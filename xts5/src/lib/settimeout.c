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
* File:	xts5/src/lib/settimeout.c
*
* Description:
*	Timeout routines
*
* Modifications:
* $Log: settimeout.c,v $
* Revision 1.2  2005-11-03 08:42:01  jmichael
* clean up all vsw5 paths to use xts5 instead.
*
* Revision 1.1.1.2  2005/04/15 14:05:10  anderson
* Reimport of the base with the legal name in the copyright fixed.
*
* Revision 8.0  1998/12/23 23:24:51  mar
* Branch point for Release 5.0.2
*
* Revision 7.0  1998/10/30 22:43:03  mar
* Branch point for Release 5.0.2b1
*
* Revision 6.0  1998/03/02 05:17:14  tbr
* Branch point for Release 5.0.1
*
* Revision 5.0  1998/01/26 03:13:47  tbr
* Branch point for Release 5.0.1b1
*
* Revision 4.0  1995/12/15 08:43:01  tbr
* Branch point for Release 5.0.0
*
* Revision 3.1  1995/12/15  00:40:25  andy
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

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#include "xtest.h"
#include "xtestlib.h"

static int 	Alarm_set;

#ifdef OLDSIGNALS
static void	(*osig)();
#else
static struct	sigaction	oact;
#endif

static void
alrm_exit(a)
int a;
{
	exit(TIMEOUT_EXIT);
}

/*
 * Set up a timeout to cause the process to exit in to seconds.  This should
 * only be called from a child process normally.
 */
void
settimeout(to)
int 	to;
{
#ifndef OLDSIGNALS
struct	sigaction	act;
#endif

	Alarm_set = 1;

#if OLDSIGNALS
	osig = signal(SIGALRM, alrm_exit);
#else
	act.sa_handler = alrm_exit;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);

	if (sigaction(SIGALRM, &act, &oact) == -1)
		delete("Could not set signal handler in settimeout");
#endif
	alarm((unsigned long)to);
}

/*
 * Clear a previously set timeout.  Return the amount of time remaining.
 */
unsigned long
cleartimeout()
{
unsigned long	timeleft;

	if (Alarm_set == 0)
		return 0;

	timeleft = alarm(0);
#if OLDSIGNALS
	signal(SIGALRM, osig);
#else
	if (sigaction(SIGALRM, &oact, (struct sigaction *)0) == -1)
		delete("Could not reset signal handler in cleartimeout");
#endif
	return(timeleft);
}

