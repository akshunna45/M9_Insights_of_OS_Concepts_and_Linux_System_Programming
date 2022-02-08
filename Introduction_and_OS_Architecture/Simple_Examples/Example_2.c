#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
  int fd; 
  int nbytes;
  fd = open("alpha.txt", O_RDONLY);
  if (fd < 0) 
  {
    perror("open");
    exit(1);
  }
  int maxlen = 128;
  char buf[maxlen];
  nbytes = read(fd, buf, maxlen);
  if (nbytes < 0) 
  {
    perror("read");
    exit(2);
  }
  // if(nbytes==0)  printf("File is empty\n");
  // buf[nbytes]='\0';
  // printf("nbytes=%d,buf=%s\n",nbytes,buf);
  write(1, buf, nbytes);
  close(fd);
  return 0; // exit(0);
}
/*
Reading chunk by chunk
int chksize = 10;
char buf[chksize];
while(1) {
  nbytes = read(fd, buf, chksize);  
  if(nbytes==0) break;                //end of file
  if (nbytes < 0) {
      perror("read");
      exit(2);
  }
  buf[chksize]='\0';
  printf(buf);
  //write(1, buf, nbytes);
}
*/