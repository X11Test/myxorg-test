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
* File:	xts5/src/lib/nextvinf.c
*
* Description:
*	Visuals support routines
*
* Modifications:
* $Log: nextvinf.c,v $
* Revision 1.2  2005-11-03 08:42:01  jmichael
* clean up all vsw5 paths to use xts5 instead.
*
* Revision 1.1.1.2  2005/04/15 14:05:10  anderson
* Reimport of the base with the legal name in the copyright fixed.
*
* Revision 8.0  1998/12/23 23:24:45  mar
* Branch point for Release 5.0.2
*
* Revision 7.0  1998/10/30 22:42:57  mar
* Branch point for Release 5.0.2b1
*
* Revision 6.0  1998/03/02 05:17:08  tbr
* Branch point for Release 5.0.1
*
* Revision 5.0  1998/01/26 03:13:41  tbr
* Branch point for Release 5.0.1b1
*
* Revision 4.2  1998/01/13 07:49:01  andy
* Added include of stdlib.h (SR 113).
*
* Revision 4.1  1996/01/25 01:57:14  andy
* Portability improvements from DEPLOY tools
*
* Revision 4.0  1995/12/15  08:42:44  tbr
* Branch point for Release 5.0.0
*
* Revision 3.1  1995/12/15  00:40:05  andy
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

/*
 * Functions to cycle through all the visuals that are supported
 * on the screen under test.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"xtest.h"
#include	<X11/Xlib.h>
#include	<X11/Xutil.h>
#include	"xtestlib.h"
#include	"tet_api.h"
#include	"pixval.h"

Display	*Dsp;

static	int 	Visindex;
static	int 	Nvis;
static	XVisualInfo *Vinfop;

static	int 	Depthind;
static	int 	*Depths;
static	int 	Ndepths;

int 	CurVinf;

static	void	iddebug();
static	void	uniquify();

/*
 * Start again at the beginning of the list of visual classes.
 *
 * The callee must ensure that the alternate screen is supported if
 * VI_ALT_PIX or VI_ALT_WIN are used.
 */
void
resetvinf(flags)
int 	flags;
{
XVisualInfo	vi;

	if (flags == 0)
		flags = VI_WIN_PIX;

	if (((flags & (VI_WIN_PIX|VI_ALT_WIN_PIX))  == 0 ) ||
	    (((flags & ~(VI_WIN_PIX|VI_ALT_WIN_PIX)) ) != 0)) {
		printf("Programming error detected in resetvinf\n");
		exit(1);
	}

	if (((flags & VI_WIN_PIX) != 0) && ((flags & VI_ALT_WIN_PIX) != 0)) {
		printf("Illegal flag combination detected in resetvinf\n");
		exit(1);
	}

	CurVinf = 1;

	/*
	 * Do pixmaps only.  Useful for debuging maybe.  Allows you to test
	 * some aspects of a X Terminal that is being used.
	 */
	if (config.debug_pixmap_only)
		flags &= ~(VI_WIN|VI_ALT_WIN);

	/*
	 * Do not test pixmaps.  Useful during testing maybe.
	 */
	if (config.debug_window_only)
		flags &= ~(VI_PIX|VI_ALT_PIX);

	Visindex = 0;
	if (Vinfop)
		XFree((char*)Vinfop);
	Vinfop = (XVisualInfo *)0;

	Depthind = 0;
	if (Depths)
		XFree((char*)Depths);
	Depths = (int *)0;

	Nvis = 0;
	Ndepths = 0;

	if (flags & (VI_WIN|VI_ALT_WIN)) {
		vi.screen = (flags & VI_WIN)?
				DefaultScreen(Dsp) : config.alt_screen;
		Vinfop = XGetVisualInfo(Dsp, VisualScreenMask, &vi, &Nvis);

		/*
		 * GLX creates a plethora of identical visuals. There is no
		 * need to test them all, since the core rendering code is very
		 * probably identical in each case.
		 */
		uniquify();

		/*
		 * For debuging purposes only consider a subset of the available
		 * visuals.
		 */
		if (config.debug_visual_ids)
			iddebug();

		if (Nvis == 0) {
			/*
			 * Report something to make sure that a problem is noted.
			 */
			delete("No visuals found");
		}
	}

	if (flags & (VI_PIX|VI_ALT_PIX)) {
		Depths = XListDepths(Dsp,
			(flags & VI_PIX)?
				DefaultScreen(Dsp) : config.alt_screen,
			&Ndepths);
		if (Depths == (int*)0) {
			delete("Call to XListDepths failed");
		}
		if (Ndepths < 1) {
			delete("less than 1 depth found in XListDepths");
		}
	}

	if (config.debug_default_depths) {
		if (Nvis > 1)
			Nvis = 1;
		if (Ndepths > 1)
			Ndepths = 1;
	}

}

/*
 * Get the next visual info structure.
 * This will either corespond to a visual supported by the default
 * screen, or (if visual is NULL) to a depth for which pixmaps are supported.
 * Returns False if there is one, otherwise True.
 */
int
nextvinf(visp)
XVisualInfo 	**visp;
{
static	XVisualInfo	vi;

	CurVinf++;

	/*
	 * This will cycle through the visuals first, then the pixmap depths.
	 */
	if (Vinfop) {
		if (Visindex < Nvis) {
			*visp = &Vinfop[Visindex++];
			trace("--- Running test with visual class %s, depth %d",
			    displayclassname((*visp)->class), (*visp)->depth);
			return(True);
		} else {
			XFree((char*)Vinfop);
			Vinfop = (XVisualInfo *)0;
		}
	}
	if (Depths) {
		if (Depthind < Ndepths) {
			vi.depth = Depths[Depthind++];
			vi.visual = 0;
			*visp = &vi;
			trace("--- Running test with pixmap depth %d", vi.depth);
			return(True);
		} else {
			XFree((char*)Depths);
			Depths = (int*)0;
		}
	}

	return(False);
}

/*
 * Returns the number of times that nextvinf will succeed. Only valid
 * after a call to resetvinf().
 */
int
nvinf()
{
	return(Nvis+Ndepths);
}

/*
 * Return a drawable which is either a window with a default visual
 * or a pixmap with a default depth.  This is used where it not
 * desired to loop over all types and depths.
 */
Drawable
defdraw(disp, type)
Display *disp;
int 	type;
{
XVisualInfo	*vp;
Drawable	d;
int		ret;

	resetvinf(type);
	do
		ret = nextvinf(&vp);
	while (ret && vp->visual != DefaultVisual(disp, vp->screen));

	if (!ret)
		trace("--- WARNING - nextvinf did not find default visual");

	d = makewin(disp, vp);

	return(d);
}

/*
 * Create a window with a default visual type.  This is only used
 * where it is not neccessary to loop over all types.
 */
Window
defwin(disp)
Display	*disp;
{
XVisualInfo	*vp;

	resetvinf(VI_WIN);
	nextvinf(&vp);

	return makewin(disp, vp);
}

/*
 * If we only want to consider a subset of visuals then this routine
 * is called to filter out all the irrelevent ones.
 */
static void
iddebug()
{
XVisualInfo	*viptmp;
char	*idlist;
int 	id;
int 	i;
int 	nreal = Nvis;

	/*
	 * Copy the original (this is realy only being done this way
	 * to avoid mixing free and XFree.)
	 */
	viptmp = (XVisualInfo*)malloc(nreal * sizeof(XVisualInfo));
	if (viptmp == 0)
		return;
	for (i = 0; i < nreal; i++)
		viptmp[i] = Vinfop[i];

	/*
	 * Copy back any visual that is wanted, keeping count of found ones
	 * as we go along.  Note that the list may contain visualids for
	 * different screens.
	 */
	Nvis = 0;
	idlist = config.debug_visual_ids;
	while (idlist) {
		id = atov(idlist); /* Allow hex/octal/decimal values */
		for (i = 0; i < nreal; i++) {
			if (viptmp[i].visualid == id)
				Vinfop[Nvis++] = viptmp[i];
		}

		idlist = strchr(idlist, ',');
		if (idlist)
			idlist++;
	}
	free(viptmp);
}

static void
uniquify(void)
{
XVisualInfo	*viptmp;
int 	i;
int 	nreal = Nvis;

	/*
	 * Copy the original (this is realy only being done this way
	 * to avoid mixing free and XFree.)
	 */
	viptmp = (XVisualInfo*)malloc(nreal * sizeof(XVisualInfo));
	if (viptmp == 0)
		return;
	for (i = 0; i < nreal; i++)
		viptmp[i] = Vinfop[i];

	/*
	 * Copy back any visual that is different from the previous visual,
	 * keeping count of found ones as we go along.  Note that the list may
	 * contain visualids for different screens.
	 */
	Nvis = 0;
	for (i = 0; i < nreal; i++) {
		if (!Nvis ||
			viptmp[i].screen != Vinfop[Nvis-1].screen ||
			viptmp[i].depth != Vinfop[Nvis-1].depth ||
			viptmp[i].class != Vinfop[Nvis-1].class ||
			viptmp[i].red_mask != Vinfop[Nvis-1].red_mask ||
			viptmp[i].green_mask != Vinfop[Nvis-1].green_mask ||
			viptmp[i].blue_mask != Vinfop[Nvis-1].blue_mask ||
			viptmp[i].colormap_size != Vinfop[Nvis-1].colormap_size ||
			viptmp[i].bits_per_rgb != Vinfop[Nvis-1].bits_per_rgb) {
			Vinfop[Nvis++] = viptmp[i];
		}
	}
	free(viptmp);
}
