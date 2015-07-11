/*prerequisite is the program should be correct*/
#include<stdio.h>
#include<conio.h>
int multiline=0;
void remove_comment_and_print(char *s);
void main()      //main start
{
 FILE *fp = fopen("rcomment.c","r");
 char c[500];                              int flag;  clrscr();
 while(NULL!=fgets(c,80,fp))
 {remove_comment_and_print(c) ; }
 getch();
}
void remove_comment_and_print(char *s)   /*test */
{
int len; int i=0;
for(len=0;s[len]!='\0';len++);
while(s[i]!='\0')
{
if(s[i]=='/')
{   if(s[i+1]=='/')
      break;
    else if(s[i+1]=='*')
      multiline=1;
    else
      if(!multiline)
	printf("%c",s[i]);
}
else if(s[i]=='*')
{   if(s[i+1]=='/')
     {multiline=0;i++;}
     else
       if(!multiline)
	 printf("%c",s[i]);
 }                                 /*first */
else       /* this is multine comment */
{ if(!multiline)    /*this is test */
  printf("%c",s[i]);                 /*again */
}
 i++;
}
}