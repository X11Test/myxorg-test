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
* $Header: /cvs/xtest/xtest/xts5/src/lib/XTestExt.c,v 1.2 2005-11-03 08:42:01 jmichael Exp $
*
* Copyright Applied Testing and Technology Inc. 1995
* All rights reserved
*
* Project: VSW5
*
* File:	xts5/src/lib/XTestExt.c
*
* Description:
*	Extension test support routines
*
* Modifications:
* $Log: XTestExt.c,v $
* Revision 1.2  2005-11-03 08:42:01  jmichael
* clean up all vsw5 paths to use xts5 instead.
*
* Revision 1.1.1.2  2005/04/15 14:05:09  anderson
* Reimport of the base with the legal name in the copyright fixed.
*
* Revision 8.0  1998/12/23 23:24:21  mar
* Branch point for Release 5.0.2
*
* Revision 7.0  1998/10/30 22:42:32  mar
* Branch point for Release 5.0.2b1
*
* Revision 6.0  1998/03/02 05:16:47  tbr
* Branch point for Release 5.0.1
*
* Revision 5.0  1998/01/26 03:13:20  tbr
* Branch point for Release 5.0.1b1
*
* Revision 4.1  1996/01/25 01:57:14  andy
* Portability improvements from DEPLOY tools
*
* Revision 4.0  1995/12/15  08:41:40  tbr
* Branch point for Release 5.0.0
*
* Revision 3.1  1995/12/15  00:38:43  andy
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

#ifdef GENERATE_PIXMAPS
/* in this case we never want to do anything like real buffer stuffing or
 * I/O on our "display" as it isn't real enough for that.
 */
#undef XTESTEXTENSION
#endif /* GENERATE_PIXMAPS */


#define NULL	0
#include	"X11/Xlib.h"
#include	"X11/Xlibint.h"

#ifdef INPUTEXTENSION
#include	<X11/extensions/XInput.h>
#endif

Status
SimulateKeyPressEvent(dpy, keycode)
Display	*dpy;
KeyCode	keycode;
{
#ifdef XTESTEXTENSION
	XTestFakeKeyEvent(dpy, keycode, 1, 0);
	return(True);
#else       
	return(False);
#endif /* XTESTEXTENSION */
}


#ifdef INPUTEXTENSION
Status
SimulateDeviceKeyPressEvent(dpy, dev, keycode)
Display	*dpy;
XDevice *dev;
KeyCode	keycode;
{
#ifdef XTESTEXTENSION
	XTestFakeDeviceKeyEvent(dpy, dev, keycode, 1, NULL, 0, 0);
	return(True);
#else       
	return(False);
#endif /* XTESTEXTENSION */
}
#endif

Status
SimulateKeyReleaseEvent(dpy, keycode)
Display	*dpy;
KeyCode	keycode;
{
#ifdef XTESTEXTENSION
	XTestFakeKeyEvent(dpy, keycode, 0, 0);
	return(True);
#else
	return(False);
#endif /* XTESTEXTENSION */
}

#ifdef INPUTEXTENSION
Status
SimulateDeviceKeyReleaseEvent(dpy, dev, keycode)
Display	*dpy;
XDevice *dev;
KeyCode	keycode;
{
#ifdef XTESTEXTENSION
	XTestFakeDeviceKeyEvent(dpy, dev, keycode, 0, NULL, 0, 0);
	return(True);
#else
	return(False);
#endif /* XTESTEXTENSION */
}
#endif

Status
SimulateButtonPressEvent(dpy, button)
Display		*dpy;
unsigned int	button;
{
#ifdef XTESTEXTENSION
	XTestFakeButtonEvent(dpy, button, 1, 0);
	return(True);
#else
	return(False);
#endif /* XTESTEXTENSION */
}

#ifdef INPUTEXTENSION
Status
SimulateDeviceButtonPressEvent(dpy, dev, button)
Display		*dpy;
XDevice *dev;
unsigned int	button;
{
#ifdef XTESTEXTENSION
	XTestFakeDeviceButtonEvent(dpy, dev, button, 1, NULL, 0, 0);
	return(True);
#else
	return(False);
#endif /* XTESTEXTENSION */
}
#endif

Status
SimulateButtonReleaseEvent(dpy, button)
Display		*dpy;
unsigned int	button;
{
#ifdef XTESTEXTENSION
	XTestFakeButtonEvent(dpy, button, 0, 0);
	return(True);
#else
	return(False);
#endif /* XTESTEXTENSION */
}

#ifdef INPUTEXTENSION
Status
SimulateDeviceButtonReleaseEvent(dpy, dev, button)
Display		*dpy;
XDevice *dev;
unsigned int	button;
{
#ifdef XTESTEXTENSION
	XTestFakeDeviceButtonEvent(dpy, dev, button, 0, NULL, 0, 0);
	return(True);
#else
	return(False);
#endif /* XTESTEXTENSION */
}
#endif

Status
CompareCursorWithWindow(dpy, window, cursor)
Display	*dpy;
Window	window;
Cursor	cursor;
{
#ifdef XTESTEXTENSION
	return XTestCompareCursorWithWindow(dpy, window, cursor);
#else
	return(False);
#endif /* XTESTEXTENSION */
}

Status
CompareCurrentWithWindow(dpy, window)
Display	*dpy;
Window	window;
{
#ifdef XTESTEXTENSION
	return XTestCompareCurrentCursorWithWindow(dpy, window);
#else
	return(False);
#endif /* XTESTEXTENSION */
}

Status
SimulateMotionEvent(dpy, screen, x, y)
Display	*dpy;
int	screen;
int	x;
int	y;
{
#ifdef XTESTEXTENSION
	XTestFakeMotionEvent(dpy, screen, x, y, 0);
	return(True);
#else
	return(False);
#endif /* XTESTEXTENSION */
}

#ifdef INPUTEXTENSION
Status
SimulateDeviceMotionEvent(dpy, dev, is_relative, n_axes, axes, first)
Display	*dpy;
XDevice *dev;
Bool	is_relative;
int	n_axes;
int	*axes;
int	first;
{
#ifdef XTESTEXTENSION
	XTestFakeDeviceMotionEvent(dpy, dev, is_relative, first, axes, n_axes, 0);
	return(True);
#else
	return(False);
#endif /* XTESTEXTENSION */
}
#endif

#ifndef XTESTEXTENSION

 /* No server extension, but we can still test some client-side functionality, can't we. */

/*
 * Discard current requests in buffer. Returns True if somthing was
 * discarded, False otherwise. 
 * The XTEST extension library includes this function.
 */

static xReq _dummy_request = {
	0, 0, 0
};

Status
XTestDiscard(dpy)
    Display *dpy;
{
    Bool something;
    register char *ptr;

    LockDisplay(dpy);
    if (something = (dpy->bufptr != dpy->buffer)) {
	for (ptr = dpy->buffer;
	     ptr < dpy->bufptr;
	     ptr += (((xReq *)ptr)->length << 2))
	    dpy->request--;
	dpy->bufptr = dpy->buffer;
	dpy->last_req = (char *)&_dummy_request;
    }
    UnlockDisplay(dpy);
    SyncHandle();
    return something;
}


/*
 * Change the GContext held within a GC structure. Now it messes with an
 * opaque data structure. The XTEST extension library includes this function.
 */
void
XTestSetGContextOfGC(gc, gid)
	GC gc;
	GContext gid;
{
	gc->gid = gid;
}

/*
 * Change the Visual ID held within a Visual structure. Now it messes with an
 * opaque data structure. The XTEST extension library includes this function.
 */
void
XTestSetVisualIDOfVisual(v, vid)
	Visual *v;
	VisualID vid;
{
	v->visualid = vid;
}

#endif /* XTESTEXTENSION */
