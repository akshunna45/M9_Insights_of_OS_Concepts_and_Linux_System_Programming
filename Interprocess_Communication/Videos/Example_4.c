#include<unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
int ret;
int nbytes = 0;
int fds[2];
ret=pipe(fds); //fds[0]-RD, fds[1]-WR
if(ret<0)
{
perror("pipe");
exit(1);
}
ret=fork();
if(ret==0) //child--read
{
close(fds[1]); //no write
char buf[128];
sleep(1);
//blocks if pipe is empty
nbytes=read(fds[0],buf,128);
//err handling
printf("Hi from Child, data read from pipe is: \n");
write(1,buf,nbytes);
close(fds[0]); //no read
exit(0);
}
else //parent -- write
{
close(fds[0]); //no read
//some delay
char str[]="1-Msg-1";
int len=strlen(str);
nbytes=write(fds[1],str,len);


char str1[]="2-Msg-2";
int len1=strlen(str1);
nbytes=write(fds[1],str1,len1);
//error handling
close(fds[1]); //done with writing
}
return 0;
}