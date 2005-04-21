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
* $Header: /cvs/xtest/xtest/xts5/include/XtTestProto.h,v 1.2 2005-04-21 09:40:42 ajosey Exp $
*
* Copyright (c) 2004 The Open Group
* Copyright (c) Applied Testing and Technology, Inc. 1993, 1994, 1995
* Copyright (c) 88open Consortium, Ltd. 1990, 1991, 1992, 1993
* All Rights Reserved.
*
* Project: VSW5
*
* File: vsw5/include/XtTestProto.h
*
* Description:
*	Library routine prototypes for vsw5 specific to the Xt tests
*
* Modifications:
* $Log: XtTestProto.h,v $
* Revision 1.2  2005-04-21 09:40:42  ajosey
* resync to VSW5.1.5
*
* Revision 8.2  2005/01/14 11:18:10  gwc
* Updated copyright notice
*
* Revision 8.1  2004/02/12 16:33:57  gwc
* Changed return type of mem_limit() to size_t
*
* Revision 8.0  1998/12/23 23:23:31  mar
* Branch point for Release 5.0.2
*
* Revision 7.0  1998/10/30 22:41:36  mar
* Branch point for Release 5.0.2b1
*
* Revision 6.0  1998/03/02 05:16:01  tbr
* Branch point for Release 5.0.1
*
* Revision 5.0  1998/01/26 03:12:32  tbr
* Branch point for Release 5.0.1b1
*
* Revision 4.0  1995/12/15 08:38:32  tbr
* Branch point for Release 5.0.0
*
* Revision 3.2  1995/12/15  00:38:01  andy
* Prepare for GA Release
*
*/

#ifndef _XTTESTPROTO_H
#define _XTTESTPROTO_H

#ifdef MIXOLDANDNEW
/*
#if defined(FUNCPROTO) || defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
*/
int     avs_alloc_sem(void);
void    avs_free_sem(void);
int     avs_wait_event(int, int);
int     avs_post_event(int);
int     avs_get_event(int);
int     avs_set_event(int, int);
char	*err_lookup(int);
void	lsah(int);
int	wait_for(pid_t, int);
int	avs_signal(int, void (*)(int));
int	avs_set_alarm(int);
int	avs_clear_alarm(void);
int	avs_expect_alarm(void);
int	avs_ignore_alarm(void);
int	push_stdout(char*, char*);
void	pop_stdout(void);
int	push_stderr(char*, char*);
void	pop_stderr(void);
void	push_to_devnull(char*, char*);
int	restore_from_devnull(void);
char	*get_token(char*, char*);
char	*get_nth_token(char *, char *, int);
void	uwerrno(char*);
void	fwerrno(char*);
void	ferrno(char*);
void	vsw_debug(int, char *, char *);
void	vsw_debug_enter(char *, char *);
void	vsw_debug_exit(char *, char *);
Widget	avs_xt_def(char *string);
char	*title(char *);
void	PostMenu(Widget, XtPointer, XButtonEvent*);
void	ConfigureDimension(Widget, Widget);
void	DestroyTree(Widget, XtPointer, XtPointer);
size_t	mem_limit(void);
void	alloc_handler(String, String, String, String, String*, Cardinal*);
Widget	avs_xt_hier(char*, char*);
Widget	avs_xt_hier_no_warn(char*, char*);
Widget	avs_xt_hier_args(char *, char *, char **, int);
Widget	avs_xt_hier_def(char*, char*);
Widget	avs_xt_init(char*, char**, int);
Widget	avs_xt_tree(Widget);
Widget	CreateMainWidget(Widget);
Widget	CreateDrawWidget(Widget);
Widget	CreateFormWidget(Widget);
Widget	CreateScrollWidget(Widget);
Widget	CreateRowColWidget(Widget);
Widget	CreateFrameWidget(Widget);
Widget	CreatePanedWidget(Widget);
Widget	CreateBoxWidget(Widget);
Widget	CreateLabelWidget(char *, Widget);
Widget	CreatePushButtonGadget(char*, Widget);
Widget	CreateMenuShellWidget(Widget);
Widget	CreateDialogShellWidget(Widget);
Window	avs_xext_init(void);
int	avs_xext_close(void);
int	check_dec(int, int, char*);
int	check_not_dec(int, int, char*);
int	check_str(char *, char *, char *);
int	check_char(char, char, char *);
int	check_size(char *, char *, size_t, size_t);
void	x_event_name(int);
void	send_event_time(Widget, int, long, Boolean, Time);
void	send_event(Widget, int, long, Boolean);
void	send_event_mask_time(Display *, Window, unsigned long, int, KeyCode, XEvent *, Time);
void	send_event_mask(Display *, Window, unsigned long, int, KeyCode, XEvent *);
int	x_handler(Display*);
void	xt_handler(String, String, String, String, String*, Cardinal*);
int	x_unexperr(Display*, XErrorEvent*);
/*from xtest library*/
void	initconfig(void);
void	report(char *fmt, ...);
void	trace(char *fmt, ...);
void report_purpose(int);
void report_assertion(char *);
void report_strategy(char *);
#else

int     avs_alloc_sem();
void    avs_free_sem();
int     avs_wait_event();
int     avs_post_event();
int     avs_get_event();
int     avs_set_event();
char	*err_lookup();
void	lsah();
int	wait_for();
int	avs_signal();
int	avs_set_alarm();
int	avs_clear_alarm();
int	avs_expect_alarm();
int	avs_ignore_alarm();
int	push_stdout();
void	pop_stdout();
int	push_stderr();
void	pop_stderr();
void	push_to_devnull();
int	restore_from_devnull();
char	*get_token();
char	*get_nth_token();
void	uwerrno();
void	fwerrno();
void	ferrno();
void	vsw_debug();
void	vsw_debug_enter();
void	vsw_debug_exit();
Widget	avs_xt_def(char *);
char	*title();
void	PostMenu();
void	ConfigureDimension();
void	DestroyTree();
size_t	mem_limit();
void	alloc_handler();
Widget	avs_xt_hier_no_warn();
Widget	avs_xt_hier();
Widget	avs_xt_hier_args();
Widget	avs_xt_hier_def();
Widget	avs_xt_init();
Widget	avs_xt_tree();
Widget	CreateMainWidget();
Widget	CreateDrawWidget();
Widget	CreateFormWidget();
Widget	CreateScrollWidget();
Widget	CreateRowColWidget();
Widget	CreateFrameWidget();
Widget	CreatePanedWidget();
Widget	CreateBoxWidget();
Widget	CreateLabelWidget();
Widget	CreatePushButtonGadget();
Widget	CreateMenuShellWidget();
Widget	CreateDialogShellWidget();
Window	avs_xext_init();
void	avs_xext_close();
int	check_dec();
int	check_not_dec();
int 	check_str();
int 	check_char();
int	check_size();
void	x_event_name();
void	send_event_time();
void	send_event();
void	send_event_mask_time();
void	send_event_mask();
int	x_handler();
void	xt_handler();
int	x_unexperr();
/*from xtest library*/
void	initconfig();
void	report();
void	trace();
void	report_purpose();
void	report_assertion();
void	report_strategy();
#endif

#endif /* _XTTESTPROTO_H */
