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
* $Header: /cvs/xtest/xtest/xts5/tset/Xlib15/stwmprprts/Test1.c,v 1.2 2005-02-12 15:28:19 anderson Exp $
* 
* Copyright (c) Applied Testing and Technology, Inc. 1995
* All Rights Reserved.
* 
* Project: VSW5
* 
* File: vsw5/tset/Xlib15/stwmprprts/Test1.c
* 
* Description:
* 	Tests for XSetWMProperties()
* 
* Modifications:
* $Log: Test1.c,v $
* Revision 1.2  2005-02-12 15:28:19  anderson
* Don't expect the 3rd arg to tet_main() to be envp
*
* Revision 1.1.1.1  2005/02/12 14:37:24  anderson
* VSW5 Source under an MIT license This is version 5.0.2 as received from
* AppTest with the new license applied.
*
* Revision 8.0  1998/12/23 23:34:07  mar
* Branch point for Release 5.0.2
*
* Revision 7.0  1998/10/30 22:56:14  mar
* Branch point for Release 5.0.2b1
*
* Revision 6.0  1998/03/02 05:25:28  tbr
* Branch point for Release 5.0.1
*
* Revision 5.0  1998/01/26 03:22:00  tbr
* Branch point for Release 5.0.1b1
*
* Revision 4.0  1995/12/15 09:09:42  tbr
* Branch point for Release 5.0.0
*
* Revision 3.1  1995/12/15  01:11:49  andy
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


extern	Display	*Dsp;

/* 
 * Dummy declarations which are normally inserted by mc.
 * Needed to prevent linkstart.c being included.
 */
char	*TestName = "XSetWMProperties";
int     tet_thistest;
struct tet_testlist tet_testlist[] = {
	NULL, 0
};
int 	ntests = sizeof(tet_testlist)/sizeof(struct tet_testlist)-1;

tet_main(argc, argv)
int argc;	
char *argv[];
{
int		pass = 0, fail = 0;
char		*res_name;
Window		win;
XVisualInfo	*vp;
XClassHint	class_hints;
XClassHint	rclass_hints;

	exec_startup();
	tpstartup();

	trace("Exec'd file ./Test1.");
	resetvinf(VI_WIN);
	nextvinf(&vp);
	win = makewin(Dsp, vp);

	class_hints.res_name = NULL;
	class_hints.res_class = "XTest_Undefined.";

	if( (res_name = (char *) getenv("RESOURCE_NAME")) == NULL) {
		delete("RESOURCE_NAME environment variable is not set.");
		return;
	} else
		CHECK;

	startcall(Dsp);
	XSetWMProperties( Dsp, win, (XTextProperty *) NULL, (XTextProperty *) NULL, (char **) NULL, 0, (XSizeHints *) NULL,  (XWMHints *) NULL, &class_hints);
	endcall(Dsp);

	if (geterr() != Success) {
		report("Got %s, Expecting Success", errorname(geterr()));
		FAIL;
	} else
		CHECK;

	if( XGetClassHint(Dsp, win, &rclass_hints) == 0 ) {
		delete("XGetClassHints returned zero.");
		return;
	} else
		CHECK;

	if(rclass_hints.res_name == NULL) {
		report("The res_name component of the returned XClassHint structure was NULL.");
		FAIL;
	} else {
		CHECK;
		if( strcmp(rclass_hints.res_name, res_name) != 0 ) {
			report("The res_name component of the returned XClassHint structure was \"%s\" instead of \"%s\".", rclass_hints.res_name, res_name);
			FAIL;
		} else
			CHECK;
	}

	CHECKPASS(5);
	tpcleanup();
	exec_cleanup();
}
