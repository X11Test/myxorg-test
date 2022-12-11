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
* File:	xts5/src/libproto/delete.c
*
* Description:
*	Protocol test support routines
*
* Modifications:
* $Log: delete.c,v $
* Revision 1.2  2005-11-03 08:42:02  jmichael
* clean up all vsw5 paths to use xts5 instead.
*
* Revision 1.1.1.2  2005/04/15 14:05:12  anderson
* Reimport of the base with the legal name in the copyright fixed.
*
* Revision 8.0  1998/12/23 23:25:17  mar
* Branch point for Release 5.0.2
*
* Revision 7.0  1998/10/30 22:43:31  mar
* Branch point for Release 5.0.2b1
*
* Revision 6.0  1998/03/02 05:17:39  tbr
* Branch point for Release 5.0.1
*
* Revision 5.0  1998/01/26 03:14:11  tbr
* Branch point for Release 5.0.1b1
*
* Revision 4.2  1998/01/12 22:58:54  andy
* Corrected testing for ANSI mode
*
* Revision 4.1  1996/01/25 01:58:33  andy
* Portability improvements from DEPLOY tools
*
* Revision 4.0  1995/12/15  08:44:25  tbr
* Branch point for Release 5.0.0
*
* Revision 3.1  1995/12/15  00:42:08  andy
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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include	"stdio.h"
#include	"xtest.h"
#include	"tet_api.h"
#include	"X11/Xlib.h"
#include	"X11/Xutil.h"
#include	"xtestlib.h"
#include	"pixval.h"
#include	"XstlibInt.h"

#include <stdarg.h>

#define	LINELEN	1024

/*
 * Routines to control deleting of tests.
 *
 * xproto lib version to avoid pulling in Xlib functions like XSync or
 * the connection opening stuff along with references to Dsp etc.
 * (refer to libxtest versions of same to see what's happening)
 * Use Xst_delete_count instead of a static boolean.
 */

extern	int 	tet_thistest;

/*
 * Call this routine to delete the current test.  If there is a message
 * it is output using report().  If not then a generic message is output
 * as a fail safe measure.
 */
/*VARARGS1*/

void
delete(char *mess, ... )
{
char	buf[LINELEN];
va_list args;

	va_start(args, mess);

	Xst_delete_count++;

	if (mess && *mess) {
		vsprintf(buf, mess, args);
		report(buf);
	} else
		report("Test deleted");

	/*
	 * Can not call tet_result from within a startup routine.
	 */
	if (tet_thistest)
		tet_result(TET_UNRESOLVED);
}

/*
 * Return True if deleted, False if not.
 */
int
isdeleted()
{
	return(Xst_delete_count > 0);
}

/*
 * Reset the delete count back to 0.
 */
void
resetdelete()
{
	Xst_delete_count = 0;
}

/*
 * Cancel all remaining tests in this test case.  They will
 * not be initiated by the TCM.  The current test is not affected,
 * that should be marked as deleted with delete() if that is desired.
 * Can also be called from startup routines - none of the tests will be
 * run.
 */
void
cancelrest(reason)
char	*reason;
{
extern	int 	ntests;
int 	i;

	for (i = tet_thistest+1; i <= ntests; i++)
		tet_delete(i, reason);
}
