#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
void check(int*,int*,int);
void main()
{
int x[30],k,y[30],pre_n=3,post_n=3,food_x=0,food_y=0,pause=0;
char key='d',post,pre='d';
for(k=0;k<3;k++)
{
x[k]=k+2;
y[k]=2;
}
while( (food_x<=1) || (food_y<=1) )
{
food_x=rand()%80;
food_y=rand()%26;
}
clrscr();
textcolor(GREEN);
printf("press p to exit......");
delay(100);
clrscr();
while(1)
{
clrscr();
for(k=0;k<post_n;k++)
{
gotoxy(x[k],y[k]);
printf("\02");
}
check(&x[0],&y[0],post_n);
gotoxy(food_x,food_y);
printf("*\b");
delay(150) ;
if(kbhit())
{
post=getch();
pre=key;
if((post=='a'&&pre!='d')||(post=='s'&&pre!='w')||(post=='d'&&pre!='a')||(post=='w'&&pre!='s'))
{
key=post;
}
else if(post=='p')
pause=1;
}
if(pause==1)
{
gotoxy(25,10);
textcolor(RED);
printf("do want to resume(y/n): \b");
textcolor(GREEN);
if(getch()=='y'||getch()=='y')
{
pause=0;
}
else
exit(0);
}
else if(key=='w')
{
if(pre_n==post_n)
{
for(k=0;k<post_n-1;k++)
{
y[k]=y[k+1];
x[k]=x[k+1];
}
y[k]=(y[k]>1)?(y[k]-1):(25);
}
else
{
y[post_n-1]=(y[pre_n-1]>1)?(y[pre_n-1]-1):(25);
x[post_n-1]=x[pre_n-1];
pre_n=post_n;
}
}
else if(key=='s')
{
if(pre_n==post_n)
{
for(k=0;k<post_n-1;k++)
{
y[k]=y[k+1];
x[k]=x[k+1];
}
y[k]=(y[k]<25)?(y[k]+1):(1);
}
else
{
y[post_n-1]=(y[pre_n-1]<25)?(y[pre_n-1]+1):(1);
x[post_n-1]=x[pre_n-1];
pre_n=post_n;
}
}
else if(key=='a')
{
if(pre_n==post_n)
{
for(k=0;k<post_n-1;k++)
{
y[k]=y[k+1];
x[k]=x[k+1];
}
x[k]=(x[k]>2)?(x[k]-1):(79);
}
else
{
x[post_n-1]=(x[pre_n-1]>2)?(x[pre_n-1]-1):(75);
y[post_n-1]=y[pre_n-1];
pre_n=post_n;
}
}
else if(key=='d')
{
if(pre_n==post_n)
{
for(k=0;k<post_n-1;k++)
{
y[k]=y[k+1];
x[k]=x[k+1];
}
x[k]=(x[k-1]<79)?(x[k-1]+1):(2);
}
else
{
x[post_n-1]=(x[pre_n-1]<79)?(x[pre_n-1]+1):(2);
y[post_n-1]=y[pre_n-1];
}
}
if( (food_x==x[post_n-1])&& (food_y==y[post_n-1]) )
{
post_n++;
food_x=rand()%80;
food_y=rand()%26;
while( (food_x<=1) || (food_y<=1) )
{
food_x=rand()%80;
food_y=rand()%26;
}
}
}
}
void check(int*x,int*y,int n)
{
int i;
for(i=0;i<n-3;i++)
{
if( *(x+n-1)== *(x+i) && *(y+n-1)== *(y+i) )
{
gotoxy(25,10);
textcolor(RED);
printf("game over");
getch();
exit(0);
}
}
}