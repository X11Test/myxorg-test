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
* $Header: /cvs/xtest/xtest/xts5/tset/Xlib3/XDisplayString/Test1.c,v 1.5 2005-11-03 08:43:22 jmichael Exp $
* 
* Copyright (c) Applied Testing and Technology, Inc. 1995
* All Rights Reserved.
* 
* Project: VSW5
* 
* File: xts5/tset/Xlib3/XDisplayString/Test1.c
* 
* Description:
*	Tests for XDisplayString()
* 
* Modifications:
* $Log: Test1.c,v $
* Revision 1.5  2005-11-03 08:43:22  jmichael
* clean up all vsw5 paths to use xts5 instead.
*
* Revision 1.4  2005/04/21 09:40:42  ajosey
* resync to VSW5.1.5
*
* Revision 8.1  2000/02/04 15:31:35  vsx
* SR234: remove extra tet_main() argument
*
* Revision 8.0  1998/12/23 23:35:11  mar
* Branch point for Release 5.0.2
*
* Revision 7.0  1998/10/30 22:57:37  mar
* Branch point for Release 5.0.2b1
*
* Revision 6.0  1998/03/02 05:26:27  tbr
* Branch point for Release 5.0.1
*
* Revision 5.0  1998/01/26 03:23:00  tbr
* Branch point for Release 5.0.1b1
*
* Revision 4.0  1995/12/15 09:12:36  tbr
* Branch point for Release 5.0.0
*
* Revision 3.1  1995/12/15  01:15:35  andy
* Prepare for GA Release
*
*:
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
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include	<stdlib.h>
#include	"xtest.h"
#include	<X11/Xlib.h>
#include	<X11/Xutil.h>
#include	"tet_api.h"
#include	"xtestlib.h"
#include	"pixval.h"


extern	Display	*Dsp;

/* 
 * Dummy declarations which are normally inserted by mc.
 * Needed to prevent linkstart.c being included.
 */
char	*TestName = "XDisplayString";
int     tet_thistest;
struct tet_testlist tet_testlist[] = {
	NULL, 0
};
int 	ntests = sizeof(tet_testlist)/sizeof(struct tet_testlist)-1;

int
tet_main(argc, argv)
int argc;	
char *argv[];
{
int		pass = 0, fail = 0;
char		*res_name;
char		*dispstr;
char		*rdispstr;
Display		*display;

	exec_startup();
	tpstartup();
	trace("Exec'd file ./Test1.");

	if((dispstr = getenv("DISPLAY")) == (char *) NULL) {
		delete("Environment variable DISPLAY is not set.");
		return;
	} else
		CHECK;

	if((display = XOpenDisplay("")) == (Display *) NULL) {
		delete("XOpenDisplay() returned NULL.");		
		return;
	} else
		CHECK;

	startcall(display);
	rdispstr = XDisplayString(display);
	endcall(display);

	if(rdispstr == (char *) NULL) {
		report("%s() returned NULL.", TestName);
		FAIL;
	} else {
		CHECK;
		if(strcmp(rdispstr, dispstr) != 0) {
			report("%s() returned \"%s\" instead of \"%s\".", TestName, rdispstr, dispstr);
			FAIL;
		} else
			CHECK;
	}

	XCloseDisplay(display);
	CHECKPASS(4);
	tpcleanup();
	exec_cleanup();
}
