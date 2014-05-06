#include <sys/wait.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main() {
int p[2];//pipe
int status;
char buff[512];
switch(fork()){
case -1:
    perror("Fork error");
case 0:
    if(pipe(p) == -1)
        perror("Pipe error");
    printf("Child");
            close(p[0]);
        close(p[1]);
    if(fork() == 0){
        close(p[0]);
        close(p[1]);
        execlp( "/bin/ls", "ls", "-R", NULL );
    }
    //dup(p[1]);
    printf("Hello22222222222");

    printf("Hello333333333333333");
    perror("Execl error");
default:
    wait(&status);
    printf("parernt");
    //dup2(p[0], 0);
//    if(read(p[0], buff, 256)){
        //cout<<buff;
   // }
    //return(status);
}

return 0;
}
