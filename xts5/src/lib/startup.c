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
* File:	xts5/src/lib/startup.c
*
* Description:
*	Primary xlib test startup routine
*
* Modifications:
* $Log: startup.c,v $
* Revision 1.2  2005-11-03 08:42:01  jmichael
* clean up all vsw5 paths to use xts5 instead.
*
* Revision 1.1.1.2  2005/04/15 14:05:10  anderson
* Reimport of the base with the legal name in the copyright fixed.
*
* Revision 8.0  1998/12/23 23:24:53  mar
* Branch point for Release 5.0.2
*
* Revision 7.0  1998/10/30 22:43:05  mar
* Branch point for Release 5.0.2b1
*
* Revision 6.1  1998/07/30 22:02:30  andy
* Added stdlib.h include.
*
* Revision 6.0  1998/03/02 05:17:16  tbr
* Branch point for Release 5.0.1
*
* Revision 5.0  1998/01/26 03:13:48  tbr
* Branch point for Release 5.0.1b1
*
* Revision 4.2  1998/01/12 23:00:02  andy
* Corrected checking for ANSI mode
*
* Revision 4.1  1996/01/25 01:57:14  andy
* Portability improvements from DEPLOY tools
*
* Revision 4.0  1995/12/15  08:43:04  tbr
* Branch point for Release 5.0.0
*
* Revision 3.1  1995/12/15  00:40:30  andy
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

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"
#include "tet_api.h"
#include "xtest.h"
#include "X11/Xlib.h"
#include "X11/Xutil.h"
#ifdef INPUTEXTENSION
#include "X11/extensions/XInput.h"
#endif
#include "xtestlib.h"
#include "pixval.h"

/*
 * Generic startup routine for tests.  All tests in general call
 * this routine unless there is a good reason not to.
 * 
 */

#define LINELEN 1024
char    buf[LINELEN];

#ifdef INPUTEXTENSION
extern  struct valname S_XIerror[];
extern  struct valname XI_event[];
#endif
extern	int 	ntests;
#ifdef INPUTEXTENSION
extern	int 	NXI_event;
#endif
int XInputMajorOpcode;
int XInputFirstError;
int XInputFirstEvent;
int baddevice;

Display	*Dsp;
Window	Win;

static	Window	ofocus;
static	int	revert_to;
static	char	**odir_array;
static	int	odirs;

Window	ErrdefWindow;
Drawable ErrdefDrawable;
GC		ErrdefGC;
Colormap ErrdefColormap;

/* NOT DONE YET */
Pixmap	ErrdefPixmap;
Atom	ErrdefAtom;
Cursor	ErrdefCursor;
Font	ErrdefFont;

void	aborttest();

void
startup()
{
int 	i;
char	*disp;
char	*cp;
/* APTETS extern	char	*TestName; */
extern	struct	tet_testlist	tet_testlist[];
extern	int 	unexp_err(Display *d, XErrorEvent *ev);
extern	int 	io_err(Display *d);

	/*
	 * Set the debug level first (it is used in initconfig).
	 */
	if ((cp = tet_getvar("XT_DEBUG")) != NULL) {
		setdblev(atov(cp));
	} else {
		setdblev(0);
	}

	/*
	 * Obtain and check all configuration parameters.
	 */
	initconfig();

	/*
	 * Put out the NAME info line for the report generator.
	 */
/*APTEST
	sprintf(buf, "TRACE:NAME: %s", TestName);
	tet_infoline(buf);
*/

	/*
	 * Pause a while in case the X server is resetting.
	 */
	reset_delay();

	/*
	 * Get the display to use and open it.
	 */
	disp = getenv("DISPLAY");

	if (disp == (char*)0) {
/*
		report("DISPLAY was not set.  Can not continue.");
*/
		for (i = 0; i < ntests; i++)
			tet_testlist[i].testfunc = aborttest;
		return;
	}

#ifdef XTEST_THREADS
	XInitThreads();
#endif
	Dsp = XOpenDisplay(disp);

	if (Dsp == (Display *)0) {
/*
		report("Could not open display.  Can not continue.");
*/
		for (i = 0; i < ntests; i++)
			tet_testlist[i].testfunc = aborttest;
		return;
	}

#ifdef notyet
	/* Get a window for general use */
	Win = makewin(Dsp);
#endif

	/* Make sure that screen saver hasn't cut in */
	XResetScreenSaver(Dsp);

	/*
	 * Set up the error handlers.
	 */
	XSetErrorHandler(unexp_err);
	XSetIOErrorHandler(io_err);

	/*
	 * Initialize the errors for the input device extension.
	 */

#ifdef INPUTEXTENSION
	 init_xinput(Dsp);
#endif

	/*
	 * Set up the default resources for error tests. At present
	 * just use the root window (could create a window specially)
	 */
	ErrdefWindow = DefaultRootWindow(Dsp);
	ErrdefDrawable = DefaultRootWindow(Dsp);
	ErrdefGC = DefaultGC(Dsp, DefaultScreen(Dsp));
	ErrdefColormap = DefaultColormap(Dsp, DefaultScreen(Dsp));
	ErrdefPixmap = maketile(Dsp, DefaultRootWindow(Dsp));
	ErrdefAtom = XInternAtom(Dsp, "XT_ERRDEFATOM", False);
	/* ErrdefCursor; */
	/* ErrdefFont; */

	/*
	 * Sync and clear out queue.
	 */
	XSync(Dsp, True);

}

/*
 * Cleanup functions called at the end of the test purposes.
 */
void
cleanup()
{
	if (Dsp) {
#ifndef GENERATE_PIXMAPS
		/* At present this causes needless problems... */
		XCloseDisplay(Dsp);
#endif
	}
}

/*
 * Startup functions called at the end of the test purposes.
 * Version to set fontpath.
 */
void
fontstartup()
{
	startup();
	if (Dsp == (Display *)0) 
		return;

	setxtfontpath();
}

void
setxtfontpath()
{
char	*fpathlist;
char	*fpathtmp;
char	*ndir_array[MAX_DIRS];
int 	ndirs;
int 	i;

	/*
	 * Save font path. (Only the first time).
	 */
	if (!odir_array)
		odir_array = XGetFontPath(Dsp, &odirs);

	/*
	 * Set font path to that containing the test fonts.
	 */
	fpathlist = config.fontpath;
	if (fpathlist == NULL || *fpathlist == '\0') {
		for (i = 1; i <= ntests; i++)
			tet_delete(i, "XT_FONTPATH not set");
		return;
	}
	fpathtmp = (char *)calloc(strlen(fpathlist)+1, sizeof(char));
	strcpy(fpathtmp, fpathlist);

	for (i = 0; i < MAX_DIRS; i++) {
		ndir_array[i] = strtok((i==0)? fpathtmp: (char*)0, SEP);
		if (ndir_array[i] == NULL)
			break;
		debug(1, "ndir_array entry %d - '%s'", i, ndir_array[i]);
	}
	ndirs = i;

	if (ndirs <= 0) {
		for (i = 1; i <= ntests; i++)
			tet_delete(i, "XT_FONTPATH contains no components");
		return;
	}

	XSetFontPath(Dsp, ndir_array, ndirs);

	/*
	 * Sync and clear out queue.
	 */
	XSync(Dsp, True);
}

/*
 * Cleanup functions called at the end of the test purposes.
 * Version to reset fontpath.
 */
void
fontcleanup()
{
	if (Dsp) {
		XSetFontPath(Dsp, odir_array, odirs);
		XFreeFontPath(odir_array);
	}

	cleanup();
}

/*
 * Startup functions called at the end of the test purposes.
 * Version to set input focus.
 */
void
focusstartup()
{
	startup();
	if (Dsp == (Display *)0) 
		return;

	/*
	 * Set focus to known state.
	 */
	XGetInputFocus(Dsp, &ofocus, &revert_to);
	XSetInputFocus(Dsp, DefaultRootWindow(Dsp), RevertToPointerRoot, CurrentTime);

	/*
	 * Sync and clear out queue.
	 */
	XSync(Dsp, True);
}

/*
 * Cleanup functions called at the end of the test purposes.
 * Version to reset input focus.
 */
void
focuscleanup()
{
	if (Dsp)
		XSetInputFocus(Dsp, ofocus, revert_to, CurrentTime);

	cleanup();
}

/*
 * Startup functions called at the end of the test purposes.
 * Version to set input focus and fontpath.
 */
void
fontfocusstartup()
{
	fontstartup();
	if (Dsp == (Display *)0) 
		return;

	/*
	 * Set focus to known state.
	 */
	XGetInputFocus(Dsp, &ofocus, &revert_to);
	XSetInputFocus(Dsp, PointerRoot, RevertToPointerRoot, CurrentTime);

	/*
	 * Sync and clear out queue.
	 */
	XSync(Dsp, True);
}

/*
 * Cleanup functions called at the end of the test purposes.
 * Version to reset input focus and fontpath.
 */
void
fontfocuscleanup()
{
	if (Dsp)
		XSetInputFocus(Dsp, ofocus, revert_to, CurrentTime);

	fontcleanup();
}

/*
 * Startup functions called at the end of the test purposes.
 * Version to initialise the resource manager.
 */
void
rmstartup()
{
	startup();
	XrmInitialize();
}

/*
 * This is used to replace all test cases when the display can not be
 * opened.  It issues a result code that should abort the current test
 * case and the tcc.
 */
void
aborttest()
{
	tccabort("Could not open display %s",
		(config.display)? config.display: "<not set>");
}

/*
 * This is used to delay before opening the first connection to the server.
 * This is to allow the server to reset (the previous test case will most 
 * likely cause a reset, when its last connection is closed).
 */
void
reset_delay()
{
	sleep(config.reset_delay);
}

#ifdef INPUTEXTENSION
Bool
init_xinput(dpy)
Display *dpy;
{
struct valname *vp;

	if (!XQueryExtension (dpy, "XInputExtension", &XInputMajorOpcode, 
		&XInputFirstEvent, &XInputFirstError))
		return False;
	if (!XI_event[0].val)
	    for (vp = XI_event; vp < &XI_event[NXI_event]; vp++) {
		vp->val += XInputFirstEvent;
	}
	BadDevice(dpy,S_XIerror[0].val);
	BadDevice(dpy,baddevice);
	BadEvent(dpy,S_XIerror[1].val);
	BadMode(dpy,S_XIerror[2].val);
	DeviceBusy(dpy,S_XIerror[3].val);
	BadClass(dpy,S_XIerror[4].val);
	return True;
}
#endif
