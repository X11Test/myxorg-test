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
>># File: xts/Xt9/XtRemoveEventHandler.m
>># 
>># Description:
>>#	Tests for XtRemoveEventHandler()
>># 
>># Modifications:
>># $Log: trmevthdr.m,v $
>># Revision 1.1  2005-02-12 14:38:24  anderson
>># Initial revision
>>#
>># Revision 8.0  1998/12/23 23:37:12  mar
>># Branch point for Release 5.0.2
>>#
>># Revision 7.0  1998/10/30 23:00:06  mar
>># Branch point for Release 5.0.2b1
>>#
>># Revision 6.0  1998/03/02 05:28:18  tbr
>># Branch point for Release 5.0.1
>>#
>># Revision 5.0  1998/01/26 03:24:52  tbr
>># Branch point for Release 5.0.1b1
>>#
>># Revision 4.0  1995/12/15 09:18:46  tbr
>># Branch point for Release 5.0.0
>>#
>># Revision 3.1  1995/12/15  02:12:09  andy
>># Prepare for GA Release
>>#
>>EXTERN
#include <X11/IntrinsicP.h>
#include <X11/ConstrainP.h>
#include <X11/CoreP.h>

XtAppContext app_ctext;
Widget topLevel, panedw, boxw1, boxw2;
Widget labelw, rowcolw, click_quit;

extern char *event_names[];

/*
** Procedure XtEVT1_Proc
*/
void XtEVT1_Proc(w, client_data, event, continue_to_dispatch)
Widget w;
XtPointer client_data;
XEvent *event;
Boolean *continue_to_dispatch;
{
	if (event->type == ButtonPress) {
		avs_set_event(1,1);
		return;
	}
	if (event->type == KeyPress) {
		avs_set_event(2,1);
		return;
	}
	if (event->type == ButtonRelease) {
		avs_set_event(3,1);
		return;
	}
	if (event->type == KeyRelease) {
		avs_set_event(4,1);
		return;
	}

	sprintf(ebuf, "ERROR: Expected Button or Key event, Received %s", event_names[event->type]);
	tet_infoline(ebuf);
	tet_result(TET_FAIL);
	exit(0);
}
/* procedure XtTMO1_Proc to be invoked */
void XtTMO1_Proc(client_data, id)
XtPointer client_data;
XtIntervalId *id;
{
	exit(0);
}

void XtEVT3_Test(w, client_data, event, continue_to_dispatch)
Widget w;
XtPointer client_data;
XEvent *event;
Boolean *continue_to_dispatch;
{
	sprintf(ebuf, "ERROR: Event %s invoked XtEVT3_Test", event_names[event->type]);
	tet_infoline(ebuf);
	tet_result(TET_FAIL);
}
/*
** Procedure XtEVT3_Proc
*/
void XtEVT3_Proc(w, client_data, event, continue_to_dispatch)
Widget w;
XtPointer client_data;
XEvent *event;
Boolean *continue_to_dispatch;
{
	if ( event->type == ButtonPress )
	avs_set_event(1,1);
	else {
		sprintf(ebuf, "ERROR: Expected ButtonPress event Received %s", event_names[event->type]);
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	exit(0);
}

/*
** Procedure XtEVT2_Proc
*/
void XtEVT2_Proc(w, client_data, event, continue_to_dispatch)
Widget w;
XtPointer client_data;
XEvent *event;
Boolean *continue_to_dispatch;
{
	if ( event->type == ButtonPress )
	avs_set_event(1,1);
	else {
		sprintf(ebuf, "ERROR: Expected ButtonPress event Received %s", event_names[event->type]);
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	exit(0);
}
/*
** Procedure XtEVT4_Proc
*/
void XtEVT4_Proc(w, client_data, event, continue_to_dispatch)
Widget w;
XtPointer client_data;
XEvent *event;
Boolean *continue_to_dispatch;
{
	if ((event->type == ButtonPress) || (event->type == KeyPress))
		avs_set_event(1, avs_get_event(1)+1);
	else {
		sprintf(ebuf, "ERROR: Expected ButtonPress and KeyPress events, Received %s", event_names[event->type]);
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
}
/*
** Procedure XtEVT4a_Proc
*/
void XtEVT4a_Proc(w, client_data, event, continue_to_dispatch)
Widget w;
XtPointer client_data;
XEvent *event;
Boolean *continue_to_dispatch;
{
	if ((event->type == ButtonRelease) || (event->type == KeyRelease))
		avs_set_event(2, avs_get_event(2)+1);
	else {
		sprintf(ebuf, "ERROR: Expected ButtonPress and KeyPress events, Received %s", event_names[event->type]);
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
}
/* procedure XtTMO4_Proc to be invoked */
void XtTMO4_Proc(client_data, id)
XtPointer client_data;
XtIntervalId *id;
{
	exit(0);
}
/*
** Warning handler
*/
void XtWMH_Proc(str1, str2, str3, str4, str5, car)
String str1, str2, str3, str4, *str5;
Cardinal *car;
{
	avs_set_event(2,1);
}
/*
** Error handler
*/
void XtEMH_Proc(str1, str2, str3, str4, str5, car)
String str1, str2, str3, str4, *str5;
Cardinal *car;
{
	avs_set_event(3,1);
}
void XtEVT_ProcA(w, client_data, event, continue_to_dispatch)
Widget w;
XtPointer client_data;
XEvent *event;
Boolean *continue_to_dispatch;
{
	if (event->type == GraphicsExpose )
	avs_set_event(1,1);
	else {
		sprintf(ebuf, "ERROR: Expected GraphicsExpose event Received %s", event_names[event->type]);
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	exit(0);
}
>>SET tpstartup avs_alloc_sem
>>SET tpcleanup avs_free_sem
>>TITLE XtRemoveEventHandler Xt9
void
XtRemoveEventHandler(w, event_mask, nonmaskable, proc, client_data)
>>ASSERTION Good A
When 
.A proc 
and 
.A client_data 
match a handler/data pair previously registered for the widget
.A w
by a call to
XtAddEventHandler or XtInsertEventHandler a successful call to 
void XtRemoveEventHandler(w, event_mask, nonmaskable, proc, client_data) 
shall unregister the procedure for the events specified by 
.A event_mask.
>>CODE
Widget labelw_msg;
char *msg = "Event widget";
pid_t pid2;
int invoked = 0;

	FORK(pid2);
	avs_xt_hier("Trmevthdr1", "XtRemoveEventHandler");
	tet_infoline("PREP: Create a test labelw_msg widget");
	labelw_msg = (Widget) CreateLabelWidget(msg, boxw1);
	tet_infoline("PREP: Create windows for widgets and map them");
	XtRealizeWidget(topLevel);
	tet_infoline("PREP: Register XtEVT1_Proc to handle ButtonPress events to labelw_msg");
	XtAddEventHandler(labelw_msg,
		 ButtonPressMask,
		 False,
		 XtEVT1_Proc,
		 (XtPointer)NULL
		 );
	tet_infoline("PREP: Register XtEVT1_Proc to handle KeyPress events to labelw_msg");
	XtAddEventHandler(labelw_msg,
		 KeyPressMask,
		 False,
		 XtEVT1_Proc,
		 (XtPointer)NULL
		 );
	tet_infoline("PREP: Insert XtEVT1_Proc to handle ButtonRelease events to labelw_msg");
	XtInsertEventHandler(labelw_msg,
		 ButtonReleaseMask,
		 False,
		 XtEVT1_Proc,
		 (XtPointer)NULL,
		 XtListHead
		 );
	tet_infoline("PREP: Insert XtEVT1_Proc to handle KeyRelease events to labelw_msg");
	XtInsertEventHandler(labelw_msg,
		 KeyReleaseMask,
		 False,
		 XtEVT1_Proc,
		 (XtPointer)NULL,
		 XtListTail
		 );
	tet_infoline("PREP: Remove XtEVT1_Proc for ButtonPress events");
	XtRemoveEventHandler(labelw_msg,
		 ButtonPressMask,
		 False,
		 XtEVT1_Proc,
		 (XtPointer)NULL
		 );
	tet_infoline("PREP: Remove XtEVT1_Proc for KeyRelease events");
	XtRemoveEventHandler(labelw_msg,
		 KeyReleaseMask,
		 False,
		 XtEVT1_Proc,
		 (XtPointer)NULL
		 );
	tet_infoline("PREP: Send ButtonPress event");
	send_event(labelw_msg, ButtonPress, ButtonPressMask, FALSE);
	tet_infoline("PREP: Send KeyPress event");
	send_event(labelw_msg, KeyPress, KeyPressMask, FALSE);
	tet_infoline("PREP: Send ButtonRelease event");
	send_event(labelw_msg, ButtonRelease, ButtonReleaseMask, FALSE);
	tet_infoline("PREP: Send KeyRelease event");
	send_event(labelw_msg, KeyRelease, KeyReleaseMask, FALSE);
	tet_infoline("PREP: Register timeout procedure");
	XtAppAddTimeOut(app_ctext, AVSXTLOOPTIMEOUT, XtTMO1_Proc, topLevel);
	XtAppMainLoop(app_ctext);
	LKROF(pid2, AVSXTTIMEOUT-2);
	tet_infoline("TEST: Procedure XtEVT1_Proc was invoked only for KeyPress and ButtonRelease");
	if (avs_get_event(1) != 0) {
		sprintf(ebuf, "ERROR: XtEVT1_Proc was invoked for ButtonPress");
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	if (avs_get_event(2) == 0) {
		sprintf(ebuf, "ERROR: XtEVT1_Proc was not invoked for KeyPress");
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	if (avs_get_event(4) != 0) {
		sprintf(ebuf, "ERROR: XtEVT1_Proc was invoked for KeyRelease");
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	if (avs_get_event(3) == 0) {
		sprintf(ebuf, "ERROR: XtEVT1_Proc was not invoked for ButtonRelease");
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	tet_result(TET_PASS);
>>ASSERTION Good A
When 
.A proc 
and 
.A client_data 
match a handler/data pair previously registered for non-maskable
events and 
.A nonmaskable
is
.S True
a successful call to 
void XtRemoveEventHandler(w, event_mask, nonmaskable, proc, client_data) 
shall unregister the procedure for all non-maskable events.
>>CODE
Widget labelw_msg;
char *msg = "Event widget";
pid_t pid2;
int invoked = 0;

	FORK(pid2);
	avs_xt_hier("Trmevthdr1", "XtRemoveEventHandler");
	tet_infoline("PREP: Create a test labelw_msg widget");
	labelw_msg = (Widget) CreateLabelWidget(msg, boxw1);
	tet_infoline("PREP: Create windows for widgets and map them");
	XtRealizeWidget(topLevel);
	tet_infoline("PREP: Register procedure to handle non-maskable events to labelw_msg");
	XtAddEventHandler(labelw_msg,
		 0,
		 True,
		 XtEVT_ProcA,
		 (XtPointer)NULL
		 );
	tet_infoline("PREP: Remove procedure for nonmaskable events");
	XtRemoveEventHandler(labelw_msg,
		 0,
		 True,
		 XtEVT_ProcA,
		 (XtPointer)NULL
		 );
	tet_infoline("PREP: Send GraphicsExpose event");
	send_event(labelw_msg, GraphicsExpose, 0, FALSE);
	XtAppAddTimeOut(app_ctext, AVSXTLOOPTIMEOUT, XtTMO1_Proc, topLevel);
	XtAppMainLoop(app_ctext);
	LKROF(pid2, AVSXTTIMEOUT-2);
	tet_infoline("TEST: Procedure was not invoked");
	if (avs_get_event(1) != 0) {
		sprintf(ebuf, "ERROR: XtEVT1_Proc was invoked for GraphicsExpose");
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	tet_result(TET_PASS);
>>ASSERTION Good A
When 
.A client_data 
does not match the value used when the procedure
.A proc
was registered a call to
void XtRemoveEventHandler(w, event_mask, nonmaskable, proc, client_data)
shall return without performing any action.
>>CODE
Widget labelw_msg;
char *msg = "Event widget";
pid_t pid2;
int invoked = 0;

	FORK(pid2);
	avs_xt_hier("Trmevthdr2", "XtRemoveEventHandler");
	tet_infoline("PREP: Create a test labelw_msg widget");
	labelw_msg = (Widget) CreateLabelWidget(msg, boxw1);
	tet_infoline("PREP: Create windows for widgets and map them");
	XtRealizeWidget(topLevel);
	tet_infoline("PREP: Register XtEVT2_Proc to handle events to labelw_msg");
	XtAddEventHandler(labelw_msg,
		 ButtonPressMask,
		 False,
		 XtEVT2_Proc,
		 (Widget)topLevel
		 );
	tet_infoline("PREP: Set up test XtToolkitError handler");
	XtAppSetErrorMsgHandler(app_ctext, XtEMH_Proc);
	tet_infoline("PREP: Set Warning Message Handler");
	XtAppSetWarningMsgHandler(app_ctext, XtWMH_Proc);
	tet_infoline("PREP: Remove the event handler with different client_data");
	XtRemoveEventHandler(labelw_msg,
		 ButtonPressMask,
		 False,
		 XtEVT2_Proc,
		 (XtPointer)NULL
		 );
	tet_infoline("PREP: Send event for which handler was registered");
	send_event(labelw_msg, ButtonPress, ButtonPressMask, FALSE);
	XtAppMainLoop(app_ctext);
	LKROF(pid2, AVSXTTIMEOUT-2);
	tet_infoline("TEST: Error message was not emitted");
	if (invoked = avs_get_event(3) != 0) {
		sprintf(ebuf, "ERROR: Error message handler was invoked %d times", invoked);
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	if (invoked = avs_get_event(2) != 0) {
		sprintf(ebuf, "ERROR: Warning message handler was invoked %d times", invoked);
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	tet_infoline("TEST: Handler was invoked");
	invoked = avs_get_event(1);
	if (!invoked) {
		sprintf(ebuf, "ERROR: Handler was not invoked");
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	tet_result(TET_PASS);
>>ASSERTION Good A
When the procedure
.A proc 
has not been registered previously for the specified widget a call to
void XtRemoveEventHandler(w, event_mask, nonmaskable, proc, client_data)
shall return without performing any action.
>>CODE
Widget labelw_msg;
char *msg = "Event widget";
pid_t pid2;
int invoked = 0;

	FORK(pid2);
	avs_xt_hier("Trmevthdr3", "XtRemoveEventHandler");
	tet_infoline("PREP: Create a test labelw_msg widget");
	labelw_msg = (Widget) CreateLabelWidget(msg, boxw1);
	tet_infoline("PREP: Set up test XtToolkitError handler");
	XtRealizeWidget(topLevel);
	tet_infoline("PREP: Register XtEVT3_Proc to handle events to labelw_msg");
	XtAddEventHandler(labelw_msg,
		 ButtonPressMask,
		 False,
		 XtEVT3_Proc,
		 (XtPointer)NULL
		 );
	tet_infoline("PREP: Set up test XtToolkitError handler");
	XtAppSetErrorMsgHandler(app_ctext, XtEMH_Proc);
	tet_infoline("PREP: Set Warning Message Handler");
	XtAppSetWarningMsgHandler(app_ctext, XtWMH_Proc);
	tet_infoline("PREP: Remove a non-registered event handler");
	XtRemoveEventHandler(labelw_msg,
		 ButtonPressMask,
		 False,
		 XtEVT3_Test,
		 (XtPointer)NULL
		 );
	tet_infoline("PREP: Send event for which handler was registered");
	send_event(labelw_msg, ButtonPress, ButtonPressMask, FALSE);
	XtAppMainLoop(app_ctext);
	LKROF(pid2, AVSXTTIMEOUT-2);
	tet_infoline("TEST: Handler was invoked");
	invoked = avs_get_event(1);
	if (!invoked) {
		sprintf(ebuf, "ERROR: Handler was not invoked");
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	tet_infoline("TEST: Error message was not emitted");
	if (invoked = avs_get_event(3) != 0) {
		sprintf(ebuf, "ERROR: Error message handler was invoked %d times", invoked);
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	if (invoked = avs_get_event(2) != 0) {
		sprintf(ebuf, "ERROR: Warning message handler was invoked %d times", invoked);
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	tet_result(TET_PASS);
>>ASSERTION Good A
When 
.A event_mask 
is XtAllEvents and 
.A nonmaskable 
is True a successful call to
void XtRemoveEventHandler(w, event_mask, nonmaskable, proc, client_data)
shall cause the procedure
.A proc
to be not called on any event for which it was previously registered by
calls to XtAddEventHandler or XtInsertEventHandler.
>>CODE
Widget labelw_msg;
char *msg = "Event widget";
pid_t pid2;
int invoked = 0;

	FORK(pid2);
	avs_xt_hier("Trmevthdr4", "XtRemoveEventHandler");
	tet_infoline("PREP: Create a test labelw_msg widget");
	labelw_msg = (Widget) CreateLabelWidget(msg, boxw1);
	tet_infoline("PREP: Create windows for widgets and map them");
	XtRealizeWidget(topLevel);
	tet_infoline("PREP: Register XtEVT4_Proc to handle events to labelw_msg");
	XtAddEventHandler(labelw_msg,
		 ButtonPressMask|KeyPressMask,
		 False,
		 XtEVT4_Proc,
		 (XtPointer)NULL
		 );
	tet_infoline("PREP: Insert XtEVT4a_Proc to handle events to labelw_msg");
	XtInsertEventHandler(labelw_msg,
		 ButtonReleaseMask|KeyReleaseMask,
		 False,
		 XtEVT4_Proc,
		 (XtPointer)NULL,
		 XtListHead
		 );
	tet_infoline("PREP: Remove previously registered event handlers");
	XtRemoveEventHandler(labelw_msg,
		 XtAllEvents,
		 True,
		 XtEVT4a_Proc,
		 (XtPointer)NULL
		 );
	XtRemoveEventHandler(labelw_msg,
		 XtAllEvents,
		 True,
		 XtEVT4_Proc,
		 (XtPointer)NULL
		 );
	tet_infoline("PREP: Register timeout procedure");
	XtAppAddTimeOut(app_ctext, AVSXTLOOPTIMEOUT, XtTMO4_Proc, topLevel);
	tet_infoline("TEST: Send all registered events for the two handlers");
	send_event(labelw_msg, ButtonPress, ButtonPressMask, FALSE);
	send_event(labelw_msg, KeyPress, KeyPressMask, FALSE);
	send_event(labelw_msg, ButtonRelease, ButtonReleaseMask, FALSE);
	send_event(labelw_msg, KeyRelease, KeyReleaseMask, FALSE);
	XtAppMainLoop(app_ctext);
	LKROF(pid2, AVSXTTIMEOUT-2);
	tet_infoline("TEST: Handlers were not invoked");
	invoked = avs_get_event(1);
	if (invoked != 0) {
		sprintf(ebuf, "ERROR: XtEVT4_Proc was invoked %d times", invoked);
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	invoked = avs_get_event(2);
	if (invoked != 0) {
		sprintf(ebuf, "ERROR:  XtEVT4a_Proc was invoked %d times", invoked);
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	tet_result(TET_PASS);
>>ASSERTION Good A
After a successful call to
void XtRemoveEventHandler(w, event_mask, nonmaskable, proc, client_data)
when 
.A event_mask 
is XtAllEvents and 
.A nonmaskable 
is True the procedure 
.A proc 
shall continue to be called for those events for which it was previously 
registered by calls to XtAddRawEventHandler and XtInsertRawEventHandler.
>>CODE
Widget labelw_msg;
char *msg = "Event widget";
pid_t pid2;
int invoked = 0;

	FORK(pid2);
	avs_xt_hier("Trmevthdr5", "XtRemoveEventHandler");
	tet_infoline("PREP: Create a test labelw_msg widget");
	labelw_msg = (Widget) CreateLabelWidget(msg, boxw1);
	tet_infoline("PREP: Create windows for widgets and map them");
	XtRealizeWidget(topLevel);
	tet_infoline("PREP: Add XtEVT1_Proc to handle events to labelw_msg");
	XtAddEventHandler(labelw_msg,
		 ButtonPressMask,
		 False,
		 XtEVT1_Proc,
		 (XtPointer)NULL
		 );
	tet_infoline("PREP: Raw Add XtEVT1_Proc to handle events to labelw_msg");
	XtAddRawEventHandler(labelw_msg,
		 KeyReleaseMask,
		 False,
		 XtEVT1_Proc,
		 (XtPointer)NULL
		 );
	tet_infoline("PREP: Raw Insert XtEVT1_Proc to handle events to labelw_msg");
	XtInsertRawEventHandler(labelw_msg,
		 KeyPressMask,
		 False,
		 XtEVT1_Proc,
		 (XtPointer)NULL,
		 XtListHead
		 );
	tet_infoline("PREP: Unregister event handler for all events");
	XtRemoveEventHandler(labelw_msg,
		 XtAllEvents,
		 True,
		 XtEVT1_Proc,
		 (XtPointer)NULL
		 );
	tet_infoline("PREP: Register timeout procedure");
	XtAppAddTimeOut(app_ctext, AVSXTLOOPTIMEOUT, XtTMO4_Proc, topLevel);
	tet_infoline("TEST: Send all registered events to the widget");
	send_event(labelw_msg, ButtonPress, ButtonPressMask, FALSE);
	send_event(labelw_msg, KeyRelease, KeyReleaseMask, TRUE);
	send_event(labelw_msg, KeyPress, KeyPressMask, TRUE);
	XtAppMainLoop(app_ctext);
	LKROF(pid2, AVSXTTIMEOUT-2);
	tet_infoline("TEST: Handler was invoked but only for raw events");
	if (avs_get_event(1) != 0) {
		sprintf(ebuf, "ERROR: XtEVT1_Proc was invoked for ButtonPress");
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	if (avs_get_event(2) == 0) {
		sprintf(ebuf, "ERROR: XtEVT1_Proc was not invoked for KeyPress");
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	if (avs_get_event(4) == 0) {
		sprintf(ebuf, "ERROR: XtEVT1_Proc was not invoked for KeyRelease");
		tet_infoline(ebuf);
		tet_result(TET_FAIL);
	}
	tet_result(TET_PASS);
>>ASSERTION Good B 1
When the widget
.A w 
is realized a successful call to 
void XtRemoveEventHandler(w, event_mask, nonmaskable, proc, client_data)
shall modify the event_mask attribute of the widget window.
