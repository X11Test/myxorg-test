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

Copyright (c) Applied Testing and Technology, Inc. 1993, 1994, 1995
Copyright (c) 88open Consortium, Ltd. 1990, 1991, 1992, 1993
All Rights Reserved.

>># 
>># Project: VSW5
>># 
>># File: xts/Xt12/XtGetKeysymTable.m
>># 
>># Description:
>>#	Tests for XtGetKeysymTable()
>># 
>># Modifications:
>># $Log: tgtkytbl.m,v $
>># Revision 1.1  2005-02-12 14:37:56  anderson
>># Initial revision
>>#
>># Revision 8.0  1998/12/23 23:38:00  mar
>># Branch point for Release 5.0.2
>>#
>># Revision 7.0  1998/10/30 23:00:59  mar
>># Branch point for Release 5.0.2b1
>>#
>># Revision 6.0  1998/03/02 05:29:03  tbr
>># Branch point for Release 5.0.1
>>#
>># Revision 5.0  1998/01/26 03:25:36  tbr
>># Branch point for Release 5.0.1b1
>>#
>># Revision 4.0  1995/12/15 09:21:09  tbr
>># Branch point for Release 5.0.0
>>#
>># Revision 3.1  1995/12/15  02:16:49  andy
>># Prepare for GA Release
>>#
>>EXTERN
#include <X11/IntrinsicP.h>
#include <X11/ConstrainP.h>
#include <X11/CoreP.h>

XtAppContext app_ctext;
Widget topLevel, panedw, boxw1, boxw2;
Widget labelw, rowcolw, click_quit;
>>TITLE XtGetKeysymTable Xt12
KeySym
*XtGetKeysymTable(display, min_keycode_return, keysyms_per_keycode_return)
>>ASSERTION Good A
A successful call to
KeySym *XtGetKeysymTable(display, min_keycode_return, keysyms_per_keycode_return)
shall return a pointer to the KeySym-to-KeyCode mapping 
table for the display
.A display.
>>CODE
Display *display;
KeyCode min_keycode_return;
KeySym *keysym_return, *keysym_good;
int keysyms_per_keycode_return;
int keysyms_per_keycode_good;
int min_keycode, max_keycode;
int i , key_count;
pid_t pid2;

	FORK(pid2);
	avs_xt_hier("Tgtkytbl1", "XtGetKeysymTable");
	tet_infoline("PREP: Get display");
	display = XtDisplay(topLevel);
	tet_infoline("PREP: Create windows for widgets and map them");
	XtRealizeWidget(topLevel);
	tet_infoline("PREP: Get range of legal keycode for a server");
	XDisplayKeycodes(display, &min_keycode, &max_keycode);
	tet_infoline("PREP: Get KeySym table");
	keysym_return = XtGetKeysymTable(display, &min_keycode_return,
			 &keysyms_per_keycode_return);
	tet_infoline("PREP: Get keyboard mapping");
	key_count = max_keycode - min_keycode - 2;
	keysym_good = XGetKeyboardMapping(display, min_keycode,
			 key_count,
			 (int *)&keysyms_per_keycode_good);
	tet_infoline("TEST: Keysym values");
	for (i = min_keycode; i <= max_keycode; i++ )
		check_dec(keysym_good[i], keysym_return[i], "keysym");
	LKROF(pid2, AVSXTTIMEOUT-2);
	tet_result(TET_PASS);
>>ASSERTION Good A
A successful call to
KeySym *XtGetKeysymTable(display, min_keycode_return, 
keysyms_per_keycode_return)
shall return the minimum KeyCode valid for the specified display
in 
.A min_keycode_return.
>>CODE
Display *display;
KeyCode min_keycode_return;
KeySym *keysym_return, *keysym_good;
int keysyms_per_keycode_return;
int keysyms_per_keycode_good;
int min_keycode, max_keycode;
int i , key_count;
pid_t pid2;

	FORK(pid2);
	avs_xt_hier("Tgtkytbl1", "XtGetKeysymTable");
	tet_infoline("PREP: Get display");
	display = XtDisplay(topLevel);
	tet_infoline("PREP: Create windows for widgets and map them");
	XtRealizeWidget(topLevel);
	tet_infoline("PREP: Get range of legal keycode for a server");
	XDisplayKeycodes(display, &min_keycode, &max_keycode);
	tet_infoline("PREP: Get KeySym table");
	keysym_return = XtGetKeysymTable(display, &min_keycode_return,
			 &keysyms_per_keycode_return);
	tet_infoline("TEST: min_keycode_return");
	check_dec(min_keycode, min_keycode_return, "min_keycode_return");
	LKROF(pid2, AVSXTTIMEOUT-2);
	tet_result(TET_PASS);
>>ASSERTION Good A
A successful call to
KeySym *XtGetKeysymTable(display, min_keycode_return, 
keysyms_per_keycode_return)
shall return the number of KeySyms stored for each KeyCode in the 
KeySym-to-KeyCode table for the specified display in 
.A keysyms_per_keycode_return.
>>CODE
Display *display;
KeyCode min_keycode_return;
KeySym *keysym_return, *keysym_good;
int keysyms_per_keycode_return;
int keysyms_per_keycode_good;
int min_keycode, max_keycode;
int i , key_count;
pid_t pid2;

	FORK(pid2);
	avs_xt_hier("Tgtkytbl1", "XtGetKeysymTable");
	tet_infoline("PREP: Get display");
	display = XtDisplay(topLevel);
	tet_infoline("PREP: Create windows for widgets and map them");
	XtRealizeWidget(topLevel);
	tet_infoline("PREP: Get range of legal keycode for a server");
	XDisplayKeycodes(display, &min_keycode, &max_keycode);
	tet_infoline("PREP: Get KeySym table");
	keysym_return = XtGetKeysymTable(display, &min_keycode_return,
			 &keysyms_per_keycode_return);
	tet_infoline("PREP: Get keyboard mapping");
	key_count = max_keycode - min_keycode - 2;
	keysym_good = XGetKeyboardMapping(display, min_keycode,
			 key_count,
			 (int *)&keysyms_per_keycode_good);
	tet_infoline("TEST: keysyms_per_keycode_return");
	check_dec(keysyms_per_keycode_good, keysyms_per_keycode_return,
			"keysyms_per_keycode_return");
	LKROF(pid2, AVSXTTIMEOUT-2);
	tet_result(TET_PASS);
>>ASSERTION Good A
On a call to
KeySym *XtGetKeysymTable(display, min_keycode_return, keysyms_per_keycode_return)
the KeySym-to-KeyCode table returned shall contain the value
.S NoSymbol
for those KeyCodes that have no associated KeySyms.
>>CODE
Display *display;
KeyCode min_keycode_return;
KeySym *keysym_return, *keysym_good;
int keysyms_per_keycode_return;
int keysyms_per_keycode_good;
int min_keycode, max_keycode;
int i , key_count;
pid_t pid2;

/*we can't control the table so the best that can be done is to compare what
Xlib returns to what Xt returns*/
	FORK(pid2);
	avs_xt_hier("Tgtkytbl1", "XtGetKeysymTable");
	tet_infoline("PREP: Get display");
	display = XtDisplay(topLevel);
	tet_infoline("PREP: Create windows for widgets and map them");
	XtRealizeWidget(topLevel);
	tet_infoline("PREP: Get range of legal keycode for a server");
	XDisplayKeycodes(display, &min_keycode, &max_keycode);
	tet_infoline("PREP: Get KeySym table");
	keysym_return = XtGetKeysymTable(display, &min_keycode_return,
			 &keysyms_per_keycode_return);
	tet_infoline("PREP: Get keyboard mapping");
	key_count = max_keycode - min_keycode - 2;
	keysym_good = XGetKeyboardMapping(display, min_keycode,
			 key_count,
			 (int *)&keysyms_per_keycode_good);
	tet_infoline("TEST: Values set to NoSymbol where no associated keysym");
	for (i = min_keycode; i <= max_keycode; i++ ) {
		if (keysym_good[i] == NoSymbol) {
			if (keysym_return[i] != NoSymbol) {
				sprintf(ebuf, "ERROR: min_keycode + %d should be NoSymbol, is %ld", i, (long)keysym_return[i]);
				tet_infoline(ebuf);
				tet_result(TET_FAIL);
			}
		}
	}
	LKROF(pid2, AVSXTTIMEOUT-2);
	tet_result(TET_PASS);
