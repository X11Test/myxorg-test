/*
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
*/
/*
*
* Copyright (c) Applied Testing and Technology, Inc. 1995
* All Rights Reserved.
*
* Project: VSW5
*
* File: src/bin/mc/mcproto.h
*
* Description:
*       Function signatures for mc utilities
*
* Modifications:
* $Log: mcproto.h,v $
* Revision 1.1  2005-02-12 14:37:14  anderson
* Initial revision
*
* Revision 8.0  1998/12/23 23:24:16  mar
* Branch point for Release 5.0.2
*
* Revision 7.0  1998/10/30 22:42:26  mar
* Branch point for Release 5.0.2b1
*
* Revision 6.0  1998/03/02 05:16:42  tbr
* Branch point for Release 5.0.1
*
* Revision 5.0  1998/01/26 03:13:15  tbr
* Branch point for Release 5.0.1b1
*
* Revision 4.0  1995/12/15 08:41:25  tbr
* Branch point for Release 5.0.0
*
* Revision 3.2  1995/12/15  00:38:14  andy
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
*/


void mcstart(char *buf);
void mcend(char *buf);
void mccopyright(FILE *fp, char *buf);
void mcheader(FILE *fp, char *buf);
int defargnames(void);
void mcassertion(FILE *fp, char *buf);
int assertfill(FILE *fp, char *buf, FILE *outfp, char *prefix);
int joinpunct(int  c);
void mcstrategy(FILE *fp, char *buf);
void mccode(FILE *fp, register char *buf);
void mcexterncode(FILE *fp, char *buf);
int funcstart(void);
int funcend(void);
int doxcall(FILE *fp, char *buf);
void mcdefassertion(FILE *fp, char *buf);
void mcincstart(char *buf);
void mcincend(char *buf);
int hashcmd(char *buf);
int doif(char *buf);
int doelse(void);
int doendif(void);
void defargtype(char *name, int  num);
int errtext(char *buf);
int valerror(char *buf);
int valerrdefs(void);
int erralternates(char *out);
int errcode(char *bp);
void mepcopyright(FILE *fp, char *buf);
void mepecho(FILE *fp, char *buf);
void mepstart(char *buf);
void mepend(char *buf);
void mepset(char *buf);
void mepcomment(char *buf);
FILE *nextfile(struct mclist *sources);
void outcopy(char *file);
FILE *cretmpfile(char *file, char **crefile);
void outfile(FILE *fp);
int remfiles(void);
int includefile(char *file, char *bp);
void filetemp(char *name);
char *mcpath(char *file);
int gccomps(FILE *fp, char *buf);
void macopyright(FILE *fp, char *buf);
void maheader(FILE *fp, char *buf);
void maassertion(FILE *fp, char *buf);
void madefassertion(FILE *fp, char *buf);
void mastart(char *buf);
void maend(char *buf);
void macomment(char *buf);
int main(int  argc, char **argv);
char *newline(FILE *fp, char *buf);
int putbackline(char *line);
void expandxname(char *line);
int err(char *mess);
int errexit(void);
char *mcstrdup(char *s);
char *strinstr(char *s1, char *s2);
int isassertwanted(int  a);
void mmstart(char *buf);
void mmend(char *buf);
void mmcopyright(FILE *fp, char *buf);
void mmheader(FILE *fp, char *buf);
void mmmake(FILE *fp, char *buf);
void mmcfiles(FILE *fp, char *buf);
void mmincstart(char *name);
struct	mclist *createmclist(void);
struct	mclist *addmclist(struct mclist *list, char *string);
char *getmclistitem(struct mclist *list, int  n);
void mascopyright(FILE *fp, char *buf);
void masheader(FILE *fp, char *buf);
void masassertion(FILE *fp, char *buf);
void masstrategy(FILE *fp, char *buf);
void masdefassertion(FILE *fp, char *buf);
void masstart(char *buf);
void masend(char *buf);
int dosections(FILE *fp, char *buf);
int assertion(FILE *fp, char *buf);
void do1sec(FILE *fp, char *buf, int  sec);
int dohook(char *buf, int  hook);
void skip(FILE *fp, char *buf);
void echo(FILE *fp, char *buf, FILE *fpout);
void echon(FILE *fp, char *buf, FILE *fpout);
void dodefaults(char *buf);
int setcmd(char *bp);
char	*name12(char *inname);
char *name12lc(char *name);
char *name10(char *name);
char *name10lc(char *name);
int main(int  argc, char **argv);
char *strinstr(char *s1, char *s2);


