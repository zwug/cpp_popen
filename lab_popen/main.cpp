#include <sys/wait.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
using namespace std;

int main() {
int p[2]; //pipe
if(pipe(p) == -1)
    perror("Pipe error");
for(;;){
    char command[10], *comm, argument[20];
    cout<<"Type your command\n";
    cin>>command;
    cout<<"Type argument\n";
    cin>>argument;
    char path[] = "/bin/";
    comm = strcat(path, command);
    cout<<comm;
    switch(fork()){
    case -1:
        perror("Fork error");
    case 0:
        close(1);
        dup2(p[1], 1);
        if(strcmp(argument, "null") == 0)
            execlp(path , command, NULL, NULL);
        execlp(path , command, argument, NULL);
        perror("Execl error");
        return 0;
    default:
        char buff[512] = "";
        if(read(p[0], buff, 512)>0){
            printf("MSG=%s\n",buff);
        }
        printf("\n----------Done---------\n");
    }
}
return 0;
}
