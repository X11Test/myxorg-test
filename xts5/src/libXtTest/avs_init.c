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
* Copyright (c) 2003 The Open Group
* Copyright (c) Applied Testing and Technology, Inc. 1993, 1994, 1995
* Copyright (c) 88open Consortium, Ltd. 1990, 1991, 1992, 1993
* All Rights Reserved.
*
* Project: VSW5
*
* File: xts5/src/lib/libXtTest/avs_init.c
*
* Description:
*	intialize the toolkit internals, creat application context, open
*	and intialize display and create initial shell instance
*	return the toplevel shell widget.
*
* Modifications:
* $Log: avs_init.c,v $
* Revision 1.3  2005-11-03 08:42:02  jmichael
* clean up all vsw5 paths to use xts5 instead.
*
* Revision 1.2  2005/04/21 09:40:42  ajosey
* resync to VSW5.1.5
*
* Revision 8.2  2005/01/20 15:58:39  gwc
* Updated copyright notice
*
* Revision 8.1  2003/12/09 17:23:42  gwc
* PR2241: allow time for server reset before trying to connect
*
* Revision 8.0  1998/12/23 23:25:35  mar
* Branch point for Release 5.0.2
*
* Revision 7.0  1998/10/30 22:43:49  mar
* Branch point for Release 5.0.2b1
*
* Revision 6.2  1998/06/22 21:23:25  andy
* Editorial
*
* Revision 6.1  1998/06/22 21:16:57  andy
* Added retry loop on opening display. SR #84.
*
* Revision 6.0  1998/03/02 05:17:54  tbr
* Branch point for Release 5.0.1
*
* Revision 5.0  1998/01/26 03:14:26  tbr
* Branch point for Release 5.0.1b1
*
* Revision 4.0  1995/12/15 08:45:10  tbr
* Branch point for Release 5.0.0
*
* Revision 3.1  1995/12/15  00:43:01  andy
* Prepare for GA Release
*
*/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <XtTest.h>
extern char ebuf[];

/* Toolkit definitions */

Widget avs_xt_init(string, argvector, argcount)
char *string;
char *argvector[];
int argcount;
{
	char app_class[4096]; 
	XtAppContext app_context;
	Display *display;
	Widget root_widget;
	int	i;

	int x_origin, y_origin;		/* x, y origin of widget */
	int width, height;		/* height and width of widget */

	int DisplayWidthInPix;		/* Number of display width pixels */
	int DisplayHeightInPix;		/* Number of display height pixels */
	int DisplayWidthInMM;		/* display width in mm */
	int PixelPerCM;			/* number of pixels in cms */

	char *	cfgdisplay;

	(void)XSetIOErrorHandler(x_handler);	/*X Handler for severe errors */
	(void)XSetErrorHandler(x_unexperr);	/* Unexpected XError handler */

	XtToolkitInitialize();

	app_context = XtCreateApplicationContext();

	/*
	** form application class name
	*/
	strcpy(app_class, string);
	/*
	** open display
	*/
	cfgdisplay = getenv("DISPLAY");
	if (cfgdisplay == 0) {
		tet_infoline("ERROR: avs_xt_init: DISPLAY not set");
		tet_result(TET_UNRESOLVED);
		exit(0);
	}
	if (strlen(cfgdisplay) == 0) {
		tet_infoline("ERROR: avs_xt_init: DISPLAY has empty value");
		tet_result(TET_UNRESOLVED);
		exit(0);
	}

	for (i = 0; i < (config.reset_delay *2)+1; i++) {
		display = XtOpenDisplay(
		 	app_context,		/* application context */
		 	(String)cfgdisplay,	/* display name */
		 	"VSW5 X Toolkit Tests",	/*application name*/
		 	app_class,		/* application class */
			NULL,/* command line options */
		 	(Cardinal)0,		/* num command line options */
		 	&argcount,
		 	argvector		/* command line args */
		 	);
		if (display != NULL)
			break;
		sleep(1);
	}

	if (!display) {
		sprintf(ebuf,"ERROR: avs_xt_init: Unable to open display %s", config.display);
		tet_infoline(ebuf);
		tet_result(TET_UNRESOLVED);
		exit(0);
	}

	XResetScreenSaver(display);

	/*
	** Get height and width of display in pixels and create a toplevel
	** shell with consistent height and width for any display.
	*/
	DisplayWidthInPix  = XDisplayWidth(display, XDefaultScreen(display));
	DisplayHeightInPix = XDisplayHeight(display, XDefaultScreen(display));
	DisplayWidthInMM = XDisplayWidthMM(display, XDefaultScreen(display));

	PixelPerCM = (DisplayWidthInPix * 10)/DisplayWidthInMM;

	x_origin =  2 * PixelPerCM;
	y_origin = 2 * PixelPerCM;
	width = DisplayWidthInPix - ( 4 * PixelPerCM );
	height = DisplayHeightInPix - ( 4 * PixelPerCM );

	root_widget = XtVaAppCreateShell(
		(String)NULL,		   	/*application name use argv[0]*/
		app_class,		  	/* application class */
		applicationShellWidgetClass, 	/* widget class */
		display,			/* display struct */
		XtNx, x_origin,		 	/* resource specifications */
		XtNy, y_origin,
		XtNwidth, width,
		XtNheight, height,
		NULL
		);

	/* return toplevel shell widget */
	return(root_widget);
}
