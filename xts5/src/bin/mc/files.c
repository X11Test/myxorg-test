/*
Copyright (c) 2005 X.Org Foundation L.L.C.

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
/*
*
* Copyright (c) 1999,2001 The Open Group
* Copyright (c) Applied Testing and Technology, Inc. 1995
* All Rights Reserved.
*
* Project: VSW5
*
* File: src/bin/mc/files.c
*
* Description:
*       misc rountines for mc utilities
*
* Modifications:
* $Log: files.c,v $
* Revision 1.3  2005-11-03 08:42:01  jmichael
* clean up all vsw5 paths to use xts5 instead.
*
* Revision 1.2  2005/04/21 09:40:42  ajosey
* resync to VSW5.1.5
*
* Revision 8.3  2005/01/20 15:48:56  gwc
* Updated copyright notice
*
* Revision 8.2  2001/02/05 12:52:25  vsx
* rename OutFile to OutFileName, to avoid clash with outfile()
*
* Revision 8.1  1999/11/25 17:13:01  vsx
* missing stdlib.h; malloc() arg wrong type
*
* Revision 8.0  1998/12/23 23:24:12  mar
* Branch point for Release 5.0.2
*
* Revision 7.0  1998/10/30 22:42:23  mar
* Branch point for Release 5.0.2b1
*
* Revision 6.0  1998/03/02 05:16:39  tbr
* Branch point for Release 5.0.1
*
* Revision 5.0  1998/01/26 03:13:11  tbr
* Branch point for Release 5.0.1b1
*
* Revision 4.0  1995/12/15 08:41:15  tbr
* Branch point for Release 5.0.0
*
* Revision 3.1  1995/12/15  00:37:56  andy
* Prepare for GA Release
*
*/

/*
Portions of this software are based on Xlib and X Protocol Test Suite.
We have used this material under the terms of its copyright, which grants
free use, subject to the conditions below.  Note however that those
portions of this software that are based on the original Test Suite have
been significantly revised and that all such revisions are copyright (c)
1995 Applied Testing and Technology, Inc.  Insomuch as the proprietary
revisions cannot be separated from the freely copyable material, the net
result is that use of this software is governed by the ApTest copyright.
 
Copyright (c) 1990, 1991  X Consortium

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
X CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of the X Consortium shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from the X Consortium.

Copyright 1990, 1991 by UniSoft Group Limited.

Permission to use, copy, modify, distribute, and sell this software and
its documentation for any purpose is hereby granted without fee,
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in
supporting documentation, and that the name of UniSoft not be
used in advertising or publicity pertaining to distribution of the
software without specific, written prior permission.  UniSoft
makes no representations about the suitability of this software for any
purpose.  It is provided "as is" without express or implied warranty.
*/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <unistd.h>
#include "mc.h"

#define	MC_LOC		"/xts5/lib/"

extern	char	*Filename;
extern	int 	Lineno;

static	int 	Filenum;
static	char	*Filetemp[50];
static	int 	Filetind;

FILE	*opencopy();

/*
 * Open the first source file.
 */
FILE *
nextfile(sources)
struct	mclist	*sources;
{
FILE	*fp;
static	int 	firsttime = 1;

	Lineno = 0;
	if ((Filename = getmclistitem(sources, Filenum++)) == NULL) {
		if (firsttime)
			fp = stdin;
		else
			fp = NULL;
	} else {
		if ((fp = fopen(Filename, "r")) == NULL) {
			fprintf(stderr, "Could not open %s\n", Filename);
			errexit();
		}
	}

	firsttime = 0;
	return(fp);
}

/*
 * Copy the contents of the corresponding skeleton file to the output.
 * The skeleton files have a .mc suffix.
 */
void
outcopy(file)
char	*file;
{
register FILE	*fp;
char 	buf[BUFSIZ];

	/*
	 * Look for a corresponding file with name lib/mc/*.mc .
	 */
	sprintf(buf, "mc/%s", file);
	file = buf;
	if (strcmp(file+strlen(file)-3, ".mc") != 0) {
		/*
		 * For debugging only -- there is an error in the file name
		 * conventions.
		 */
		fprintf(stderr, "Internal error outcopy file does not end in .mc\n");
	}

	if ((fp = fopen(mcpath(file), "r")) != NULL) {
		outfile(fp);
		fclose(fp);
	} else {
		fprintf(stderr, "Could not open skeleton file %s\n", mcpath(file));
		errexit();
		/*NOTREACHED*/
	}
}

/*
 * Create a temporary file with the given name. Open a stream to it
 * and return the stream pointer.
 */
FILE *
cretmpfile(file, crefile)
char	*file;
char	**crefile;
{
register FILE	*fp;
char *tmpfile;

	tmpfile = malloc(PATH_MAX);
	if (!tmpfile) {
		fprintf(stderr, "Could not allocate memory for tmpfile %s\n",
			file);
		errexit();
	}

	snprintf(tmpfile, PATH_MAX, "%s.%d", file, (int)getpid());
	if ((fp = fopen(tmpfile, "w+")) == NULL) {
		fprintf(stderr, "Could not open %s\n", tmpfile);
		errexit();
	}

	if (crefile)
		*crefile = tmpfile;
	filetemp(tmpfile);

	return(fp);
}


/*
 * Combine all the files in the right order onto
 * stdout.
 */
void outfile(fp)
FILE	*fp;
{
static FILE	*fout;
static int 	olineno = 0;
static char	*ofilename;
char	buf[BUFSIZ];
register int 	n;
extern	char	*OutFileName;
extern	int 	pflag;
extern	int 	Cmdname;

	if (!fout) {
		if (OutFileName) {
			if ((fout = fopen(OutFileName, "w")) == NULL) {
				fprintf(stderr, "Could not open %s for output\n", OutFileName);
				errexit();
			}
			ofilename = OutFileName;
		} else {
			fout = stdout;
			ofilename = "stdout";
		}
	}

	/* If there was no file to write from, just return after opening
	 * the output file. */
	if (!fp)
		return;

	rewind(fp);

	if (pflag && Cmdname == CMD_MC) {
		while (fgets(buf, BUFSIZ, fp) != NULL) {
			olineno++;
			if (buf[0] == '>' && buf[1] == '>' && buf[2] == 'G')
				sprintf(buf, "#line %d \"%s\"\n", olineno+1, ofilename);
			fputs(buf, fout);
		}
	} else {
		while ((n = fread(buf, sizeof(char), BUFSIZ, fp)) > 0)
			fwrite(buf, n, 1, fout);
	}
}

remfiles()
{
int 	i;

	for (i = 0; i < Filetind; i++) {
		unlink(Filetemp[i]);
		free(Filetemp[i]);
		Filetemp[i] = NULL;
	}
	Filetind = 0;
}

includefile(file, bp)
char	*file;
char	*bp;
{
char	*name;
char	*savline;
char	*savfilename;
char	*path;
char	*strtok();
FILE	*fp;
int 	savlineno;

	savline = mcstrdup(bp);
	file = mcstrdup(file);

	name = strtok(file, " \t\n");
	if (name == (char*)0) {
		err("Missing file name on include directive\n");
		errexit();
	}

	if ((fp = fopen(name, "r")) == NULL) {
		path = mcpath(name);
		if ((fp = fopen(path, "r")) == NULL) {
			err("");
			fprintf(stderr, "Cannot open include file %s\n", name);
			errexit();
		}
	}

	savfilename = Filename;
	savlineno = Lineno;
	Filename = name;
	Lineno = 0;

	dohook(name, HOOK_INCSTART);
	dosections(fp, bp);
	fclose(fp);
	dohook(name, HOOK_INCEND);

	Filename = savfilename;
	Lineno = savlineno;

	strcpy(bp, savline);
	free(savline);
	free(file);
}

/*
 * Mark the file name for deletion at the end.
 */
void
filetemp(name)
char	*name;
{
int 	i;

	for (i = 0; i < Filetind; i++) {
		if (strcmp(Filetemp[i], name) == 0)
			return;
	}
	Filetemp[Filetind++] = name;
}

/*
 * Return path name of file in the xts5 lib directory.
 */
char *
mcpath(file)
char	*file;
{
char	*rp;
char	*path;
int 	size;

	rp = getenv("TET_ROOT");
	if (rp == NULL) {
		fprintf(stderr, "TET_ROOT not set in environment\n");
		errexit();
	}
	size = strlen(rp)+strlen(MC_LOC)+strlen(file)+1;
	path = malloc((size_t)size);
	if (path == NULL) {
		fprintf(stderr, "Out of memory\n");
		errexit();
	}
	strcpy(path, rp);
	strcat(path, MC_LOC);
	strcat(path, file);

	return(path);
}
