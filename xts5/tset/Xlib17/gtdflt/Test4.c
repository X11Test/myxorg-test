/*
Copyright (c) 2005 X.Org Foundation LLC

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
* $Header: /cvs/xtest/xtest/xts5/tset/Xlib17/gtdflt/Test4.c,v 1.1 2005-02-12 14:37:30 anderson Exp $
* 
* Copyright (c) Applied Testing and Technology, Inc. 1995
* All Rights Reserved.
* 
* Project: VSW5
* 
* File: vsw5/tset/Xlib17/gtdflt/Test4.c
* 
* Description:
* 	Tests for XGetDefault()
* 
* Modifications:
* $Log: Test4.c,v $
* Revision 1.1  2005-02-12 14:37:30  anderson
* Initial revision
*
* Revision 8.0  1998/12/23 23:34:38  mar
* Branch point for Release 5.0.2
*
* Revision 7.0  1998/10/30 22:56:58  mar
* Branch point for Release 5.0.2b1
*
* Revision 6.0  1998/03/02 05:25:56  tbr
* Branch point for Release 5.0.1
*
* Revision 5.0  1998/01/26 03:22:28  tbr
* Branch point for Release 5.0.1b1
*
* Revision 4.0  1995/12/15 09:11:01  tbr
* Branch point for Release 5.0.0
*
* Revision 3.1  1995/12/15  01:13:36  andy
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

#include	<stdlib.h>
#include	"xtest.h"
#include	"Xlib.h"
#include	"Xutil.h"
#include	"tet_api.h"
#include	"xtestlib.h"
#include	"pixval.h"
#include	"Xatom.h"

extern	Display	*Dsp;

/* 
 * Dummy declarations which are normally inserted by mc.
 * Needed to prevent linkstart.c being included.
 */
char	*TestName = "XGetDefault";
int     tet_thistest;
struct tet_testlist tet_testlist[] = {
	NULL, 0
};
int 	ntests = sizeof(tet_testlist)/sizeof(struct tet_testlist)-1;

tet_main(argc, argv, envp)
int argc;	
char *argv[];
char *envp[];
{
int		pass = 0, fail = 0;
Display		*display;
char		*prog = "XTest";
char		*opt;
char		*tres;
char		*res;
char		*pval="XTest.testval41:pVAL_1\nXTest.testval42:pVAL_2\nXTest.testval43:pVAL_3\n";
int		i;
static	char	*testval[] = { "testval41", "testval42", "testval46" };
static	char	*result[]  = { "pVAL_1",    "eVAL_5",    "eVAL_6" };

	exec_startup();
	tpstartup();
	trace("Exec'd file ./Test4 with XENVIRONMENT = \"%s\".", getenv("XENVIRONMENT"));

	if(getenv("XENVIRONMENT") == (char *) NULL) {
		delete("XENVIRONMENT environment variable not set.");
		return;
	} else
		CHECK;

	XChangeProperty (Dsp, RootWindow(Dsp, 0), XA_RESOURCE_MANAGER, XA_STRING, 8, PropModeReplace, (unsigned char *)pval, 1+strlen(pval));
	XSync(Dsp, False);

	display = opendisplay();  /* Should merge $XENVIRONMENT file with existing database. */

	for(i=0; i< NELEM(testval); i++) {

		opt  = testval[i];
		tres = result[i];
	
		startcall(display);
		res = XGetDefault(display, prog, opt);
		endcall(display);
	
		if( res == (char *) NULL) {
			report("%s() returned NULL with program = \"%s\" and option = \"%s\".", TestName, prog, opt);
			FAIL;
		} else {
			CHECK;
			if(strcmp(res, tres) != 0) {
				report("%s() with program = \"%s\" and option = \"%s\" returned \"%s\" instead of \"%s\".", TestName, prog, opt, res, tres);
				FAIL;
			} else
				CHECK;
		}

	}

      	CHECKPASS(1 + 2*NELEM(testval));
	tpcleanup();
	exec_cleanup();
}
