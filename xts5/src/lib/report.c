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
* Copyright Applied Testing and Technology Inc. 1995
* All rights reserved
*
* Project: VSW5
*
* File:	xts5/src/lib/report.c
*
* Description:
*	Reporting functions
*
* Modifications:
* $Log: report.c,v $
* Revision 1.2  2005-11-03 08:42:01  jmichael
* clean up all vsw5 paths to use xts5 instead.
*
* Revision 1.1.1.2  2005/04/15 14:05:10  anderson
* Reimport of the base with the legal name in the copyright fixed.
*
* Revision 8.0  1998/12/23 23:24:49  mar
* Branch point for Release 5.0.2
*
* Revision 7.0  1998/10/30 22:43:01  mar
* Branch point for Release 5.0.2b1
*
* Revision 6.0  1998/03/02 05:17:12  tbr
* Branch point for Release 5.0.1
*
* Revision 5.0  1998/01/26 03:13:46  tbr
* Branch point for Release 5.0.1b1
*
* Revision 4.2  1998/01/12 23:00:02  andy
* Corrected checking for ANSI mode
*
* Revision 4.1  1996/01/25 01:57:14  andy
* Portability improvements from DEPLOY tools
*
* Revision 4.0  1995/12/15  08:42:55  tbr
* Branch point for Release 5.0.0
*
* Revision 3.1  1995/12/15  00:40:19  andy
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

/*LINTLIBRARY*/
/*
 * Reporting functions these implement a higher level
 * on top of tet_infoline.
 * 
 *  REPORT -- report(char *fmt, ...)
 *    A description of something that went wrong.
 *  TRACE -- trace(char *fmt, ...)
 *    A 'I am here' or description of somthing that happened
 *    that is not an error in itself.
 *  DEBUG -- debug(char *fmt, ...)
 *    Debug lines -- Interface to be decided
 *  CHECK -- ???
 *    Path trace line.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include	<stdio.h>
#include	<string.h>
#include	"xtest.h"
#include	<X11/Xlib.h>
#include	<X11/Xutil.h>
#include	"xtestlib.h"
#include	"tet_api.h"

#include <stdarg.h>

#define	LINELEN	1024

static int 	DebugLevel = 0;

extern	struct	config	config;

extern	int	tet_thistest;

int	purpose_reported = 0;
/*VARARGS1*/

void
report(char *fmt, ...)
{
char	buf[LINELEN];
va_list	args;

	va_start(args, fmt);

	strcpy(buf, "REPORT: ");
	vsprintf(buf+strlen("REPORT: "), fmt, args);
	tet_infoline(buf);

	va_end(args);

}

/*APTEST*/
void report_purpose(int number)
{
	char	buf[LINELEN];

	sprintf(buf, "VSW5TESTSUITE PURPOSE %d", number);
	tet_infoline(buf);
	purpose_reported = number;
}

void report_assertion(char* line)
{
	tet_infoline(line);
}

void report_strategy(char* line)
{
	char	buf[LINELEN];

	sprintf(buf, "METH: %s", line);
	tet_infoline(buf);
}

/*VARARGS1*/

void
trace(char *fmt, ...)
{
char	buf[LINELEN];
va_list	args;

	if (config.option_no_trace)
		return;

	va_start(args, fmt);

	strcpy(buf, "TRACE: ");
	vsprintf(buf+strlen("TRACE: "), fmt, args);
	tet_infoline(buf);

	va_end(args);
}

/*VARARGS1*/

void
check(char *fmt, ...)
{
char	buf[LINELEN];
va_list	args;

	if (config.option_no_check)
		return;

	va_start(args, fmt);

	strcpy(buf, "CHECK: ");
	vsprintf(buf+strlen("CHECK: "), fmt, args);
	tet_infoline(buf);

	va_end(args);
}

/*VARARGS2*/

void
debug(int lev, char *fmt, ...)
{
char	buf[LINELEN];
va_list	args;

	if (lev > DebugLevel)
		return;

	va_start(args, fmt);

	strcpy(buf, "DEBUG: ");
	vsprintf(buf+strlen("DEBUG: "), fmt, args);
	tet_infoline(buf);

	va_end(args);
}

/*
 * This formats its arguments as in report().  It also issues the result
 * code MIT_TET_ABORT.  This causes the TCM to give up, and also the TCC if
 * running under it.  It should be used when something is so badly wrong
 * that there is no point continuing any more tests.
 */

/*VARARGS1*/

void
tccabort(char *fmt, ...)
{
char	buf[LINELEN];
va_list	args;

	va_start(args, fmt);

	if (purpose_reported == 0)
		report_purpose((tet_thistest  == 0) ? 1: tet_thistest);
	strcpy(buf, "REPORT: ");
	vsprintf(buf+strlen("REPORT: "), fmt, args);
	tet_infoline(buf);

	va_end(args);

	tet_result(MIT_TET_ABORT);

}

void
setdblev(n)
int 	n;
{
	DebugLevel = n;
}

int
getdblev()
{
	return DebugLevel;
}
