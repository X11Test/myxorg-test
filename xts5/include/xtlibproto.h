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
* Copyright (c) Applied Testing and Technology, Inc. 1995
* All Rights Reserved.
*
* Project: VSW5
*
* File: xts5/include/xlibproto.h
*
* Description:
*	Defines used by the Xt tests
*
* Modifications:
* $Log: xtlibproto.h,v $
* Revision 1.2  2005-11-03 08:42:00  jmichael
* clean up all vsw5 paths to use xts5 instead.
*
* Revision 1.1.1.2  2005/04/15 14:05:07  anderson
* Reimport of the base with the legal name in the copyright fixed.
*
* Revision 8.0  1998/12/23 23:23:37  mar
* Branch point for Release 5.0.2
*
* Revision 7.0  1998/10/30 22:41:42  mar
* Branch point for Release 5.0.2b1
*
* Revision 6.0  1998/03/02 05:16:07  tbr
* Branch point for Release 5.0.1
*
* Revision 5.0  1998/01/26 03:12:39  tbr
* Branch point for Release 5.0.1b1
*
* Revision 4.2  1998/01/12 23:00:26  andy
* Corrected testing for ANSI mode
*
* Revision 4.1  1998/01/12 21:38:03  andy
* Changed STDC to defined(STDC)
*
* Revision 4.0  1995/12/15 08:38:41  tbr
* Branch point for Release 5.0.0
*
* Revision 3.2  1995/12/15  00:38:36  andy
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

 
Copyright (c) 1990, 1991, 1992  X Consortium

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

Copyright 1990, 1991, 1992 by UniSoft Group Limited.

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

#ifdef INPUTEXTENSION
#include <X11/extensions/XInput.h>
#endif

void startup(void);
void cleanup(void);
void fontstartup(void);
void setxtfontpath(void);
void fontcleanup(void);
void focusstartup(void);
void focuscleanup(void);
void fontfocusstartup(void);
void fontfocuscleanup(void);
void rmstartup(void);
void aborttest(void);
void reset_delay(void);
void exec_startup(void);
void exec_cleanup(void);
char *boolname(int  val);
char *eventmaskname(unsigned long val);
char *eventname(int  val);
char *keymaskname(unsigned long val);
char *modifiername(int  val);
char *buttonmaskname(unsigned long val);
char *buttonname(int  val);
char *notifymodename(int  val);
char *notifydetailname(int  val);
char *visibilityname(int  val);
char *grabreplyname(int  val);
char *alloweventmodename(int  val);
char *reverttoname(int  val);
char *errorname(int  val);
char *classname(int  val);
char *bitgravityname(int  val);
char *wingravityname(int  val);
char *backingstorename(int  val);
char *gcfunctionname(int  val);
char *linestylename(int  val);
char *capstylename(int  val);
char *joinstylename(int  val);
char *fillstylename(int  val);
char *displayclassname(int  val);
char *protoname(int  val);
char *atomname(int  val);
char *mapstatename(int  val);
char *visualmaskname(unsigned long val);
char *contexterrorname(int  val);
int error_status(Display *disp, XErrorEvent *errevent);
int unexp_err(Display *disp, XErrorEvent *errevent);
int io_err(Display *disp);
int geterr(void);
int getbadvalue(void);
void reseterr(void);
int getevent(Display *disp, XEvent *event);
int stackorder(Display *disp, Window win);
void report(char *fmt, ...);
void trace(char *fmt, ...);
/*APTEST*/
void report_purpose(int);
void report_assertion(char *);
void report_strategy(char *);
void check(char *fmt, ...);
void debug(int lev, char *fmt, ...);
void tccabort(char *fmt, ...);
void setdblev(int  n);
int getdblev(void);
Window iponlywin(Display *disp);
Window badwin(Display *disp);
void _startcall(Display *disp);
void startcall(Display *disp);
void _endcall(Display *disp);
void endcall(Display *disp);
Window makewin(Display *disp, XVisualInfo *vp);
void winpair(Display *disp, XVisualInfo *vp, Window *w1p, Window *w2p);
Drawable makewinpos(Display *disp, XVisualInfo *vp, int  x, int  y);
int checkevent(XEvent *good, XEvent *ev);
int initvclass(void);
void resetvclass(void);
int nextvclass(int  *vp, int  *dp);
int nvclass(void);
GC badgc(Display *disp);
Pixmap badpixm(Display *disp);
Font badfont(Display *disp);
void badvis(Visual *v);
void linkstart(void);
void linkclean(void);
int issuppvis(Display *disp, int  vis);
unsigned long visualsupported(Display *disp, unsigned long mask);
void resetsupvis(unsigned long vismask);
int nextsupvis(XVisualInfo **vi);
int nsupvis(void);
Status checkarea(Display *disp, Drawable d, register struct area *ap, unsigned long  inpix, unsigned long  outpix, int  flags);
Status checkclear(Display *disp, Drawable d);
Status checkregion(Display *disp, Drawable d, Region rgn, unsigned long inpix, unsigned long outpix, int flags);
void getsize(Display *disp, Drawable d, unsigned int  *widthp, unsigned int  *heightp);
unsigned int getdepth(Display *disp, Drawable d);
void pattern(Display *disp, Drawable d);
Status checkpattern(Display *disp, Drawable d, struct area *ap);
Window crechild(Display *disp, Window w, struct area *ap);
Window creunmapchild(Display *disp, Window w, struct area *ap);
Status checktile(Display *disp, Drawable d, struct area *ap, int  xorig, int  yorig, Pixmap pm);
Pixmap maketile(Display *disp, Drawable d);
Pixmap makepixm(Display *disp, XVisualInfo *vp);
void resetvinf(int  flags);
int nextvinf(XVisualInfo  **visp);
int nvinf(void);
Drawable defdraw(Display *disp, int  type);
Window defwin(Display *disp);
GC makegc(Display *disp, Drawable d);
void setgcfont(Font font);
void dumpimage(XImage *imp, char *name, struct area *ap);
int verifyimage(Display  *disp, Drawable d, struct area *ap, int vwarn);
void dclear(Display *disp, Drawable d);
void dset(Display *disp, Drawable d, unsigned long pix);
void delete(char *mess, ... );
int isdeleted(void);
void resetdelete(void);
void cancelrest(char *reason);
void unsupported(char *mess, ... );
void notinuse(char *mess, ... );
void untested(char *mess, ... );
XImage *savimage(Display *disp, Drawable d);
Status compsavimage(Display *disp, Drawable d, XImage *im);
Status diffsavimage(Display *disp, Drawable d, XImage *im);
int checkpixel(Display *display, Drawable drawable, int x, int y, unsigned long value);
unsigned long getpixel(Display *display, Drawable drawable, int  x, int  y);
Status checkpixels(Display *display, Drawable drawable, int x, int y, int dx, int dy, int len, unsigned long value);
int notmember(int  *list, int  len, long *ret);
int notmaskmember(unsigned long *list, int  len, unsigned long *ret);
void setwidth(Display *disp, GC  gc, unsigned int  width);
void setcapstyle(Display *disp, GC  gc, int  capstyle);
void setlinestyle(Display *disp, GC  gc, int  linestyle);
void setjoinstyle(Display *disp, GC  gc, int  joinstyle);
int checkgccomponent(Display *disp, GC gc, unsigned int valuemask, XGCValues *values);
void gcflush(Display *dpy, GC gc);
void tpstartup(void);
void tpcleanup(void);
Pixmap nondepth1pixmap( Display *disp,  Drawable d);
void setfuncpixel(Display *disp, Drawable drw, int  *xp, int  *yp);
void regid(Display *disp, union regtypes *id, int  type);
void freereg(void);
void regenable(void);
void regdisable(void);
void openfonts(Font fonts[], int  nfonts);
int checkfsp(XFontStruct *fsp, XFontStruct *good, char *str);
void txtextents(XFontStruct *fsp, unsigned char *str, int  n, int  *dir, int  *ascent, int  *descent, XCharStruct *overall);
void txtextents16(XFontStruct *fsp, XChar2b *str, int  n, int  *dir, int  *ascent, int  *descent, XCharStruct *overall);
int txtwidth(XFontStruct *fsp, unsigned char *str, int  n);
int txtwidth16(XFontStruct *fsp, XChar2b *str, int  n);
Colormap badcolormap( Display *disp,  Window  win);
Colormap makecolmap(Display *disp, Visual *visual, int alloc);
int lg( unsigned long x);
char *bitstr( unsigned long val,  char spare[]);
Cursor makecurnum(Display *disp, int inc);
Cursor makecur(Display *disp);
Cursor makecur2(Display *disp);
XImage *makeimg(Display *disp, XVisualInfo *vp, int format);
void dsetimg(XImage *ximage, unsigned long pixel);
void patternimg(XImage *ximage, unsigned long pixel);
Status checkimg(XImage *im, struct area *ap, long inpix, long outpix, int flags);
Status checkimgstruct(XImage *im, unsigned int depth, unsigned int width, unsigned int height, int format);
Display *opendisplay(void);
unsigned int bitcount( register unsigned long n);
unsigned long getpix(unsigned long m, unsigned long p);
int atov(char *str);
void initconfig(void);
Window mkwinchild(Display *disp, XVisualInfo *vp, struct area *ap, int  mapflag, Window  parent, int  border_width);
Window mkwin(Display *disp, XVisualInfo *vp, struct area *ap, int  mapflag);
Status block(Display *display, XEvent *event, Block_Info *info);
Winh *winh_adopt(Display *display, Winh *parent, unsigned long valuemask, XSetWindowAttributes *attributes, Winhg *winhg, long winhmask);
int winh_create(Display *display, Winh *winh, long winhmask);
Winh *winh_find(Winh *winh, Window window);
int winh_plant(Winh *source, XEvent *event, long event_mask, long winhmask);
int winh_pending(int expected);
int winh_harvest(Display *display, Winh *winh);
int winh_weed(Winh *winh, int event_type, long winhmask);
int winh_ignore_event(Winh *winh, int event_type, long winhmask);
int winh_selectinput(Display *display, Winh *winh, long event_mask);
int winh_changewindowattributes(Display *display, Winh *winh, unsigned long valuemask, XSetWindowAttributes *attributes);
void winh_free(Winh *winh);
int winh_walk(Winh *winh, int depthfirst, int (*procedure)());
int winh_climb(Winh *start, Winh *stop, int (*procedure)());
int winh_eventindex(int event_type);
int winh_ordercheck(int before, int after);
int winh(Display *display, int depth, long winhmask);
PointerPlace *warppointer(Display *display, Window dest_w, int dest_x, int dest_y);
Bool pointermoved(Display *display, PointerPlace *ptr);
void unwarppointer(Display *display, PointerPlace *ptr);
void pointerrootpos(Display *display, PointerPlace *ptr);
void rootcoordset(Display *display, Window src_w, Window dest_w, int src_x, int src_y, int *dest_x_return, int *dest_y_return);
void serialset(Display *display, XEvent *event);
Bool serialtest(XEvent *good, XEvent *ev);
Time gettime( Display *disp);
int maxsize( XVisualInfo *vp);
char *xt_strdup(char *str);
struct	buildtree *buildtree(Display *disp, Window parent, char **list, int  nlist);
struct	buildtree *btntobtp(struct buildtree *list, char *name);
struct	buildtree *btwtobtp(struct buildtree *list, Window w);
Window btntow(struct buildtree *list, char *name);
char *btwton(struct buildtree *list, Window w);
void setforexpose(Display *disp, Window w);
Status exposefill(Display *disp, Window w);
Status exposecheck(Display *disp, Window w);
Status expose_test_restored(Display *disp, Window w);
void settimeout(int  to);
unsigned long cleartimeout(void);
Region makeregion(void);
int samehost(XHostAddress *h1, XHostAddress *h2);
void pfcount(int  pass, int  fail);
void rptcounts(void);
Status SimulateKeyPressEvent(Display *dpy, KeyCode keycode);
Status SimulateKeyReleaseEvent(Display *dpy, KeyCode keycode);
Status SimulateButtonPressEvent(Display  *dpy, unsigned int button);
Status SimulateButtonReleaseEvent(Display  *dpy, unsigned int button);
#ifdef INPUTEXTENSION
Bool init_xinput(Display *dpy);
Status SimulateDeviceKeyPressEvent(Display *dpy, XDevice *dev, unsigned int button);
Status SimulateDeviceKeyReleaseEvent(Display *dpy, XDevice *dev, unsigned int button);
Status SimulateDeviceButtonPressEvent(Display *dpy, XDevice *dev, unsigned int button);
Status SimulateDeviceButtonReleaseEvent(Display *dpy, XDevice *dev, unsigned int button);
#endif
Status CompareCursorWithWindow(Display *dpy, Window window, Cursor cursor);
Status CompareCurrentWithWindow(Display *dpy, Window window);
Status SimulateMotionEvent(Display *dpy, int screen, int x, int y);
Status XTestDiscard(    Display *dpy);
void XTestSetGContextOfGC( GC gc,  GContext gid);
void XTestSetVisualIDOfVisual( Visual *v,  VisualID vid);
void buttonpress(Display *disp, unsigned int     button);
void buttonrel(Display *disp, unsigned int     button);
void keypress(Display *disp, int     key);
void keyrel(Display *disp, int     key);
void relbuttons(void);
void relkeys(void);
void relalldev(void);
unsigned int wantmods(Display *disp, int  want);
void modpress(Display *disp, unsigned int  mask);
void modrel(Display *disp, unsigned int  mask);
int ismodkey(unsigned int  mask, int kc);
void restoredevstate(void);
int noext(int  needbutton);
int nbuttons(void);
int getkeycode(Display *display);
Status IsExtTestAvailable(void);
int xtest_putenv(char *envstr);
int curofwin(Display *display, Cursor cursor, Window window);
int defcur(Display *display, Window window);
int spriteiswin(Display *display, Window window);
const char *outfile(const char *fn);


