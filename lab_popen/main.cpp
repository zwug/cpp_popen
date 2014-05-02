#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main() {
	FILE *in;
	char buff[512];
	execl("/bin/ls", "ls",(char *)0);
execl("ls", "ls", 0);
	if(!(in = popen("touch 2.txt", "w"))){
		return 1;
	}

	while(fgets(buff, sizeof(buff), in)!=NULL){
		cout << buff;
	}
	pclose(in);

	return 0;
}
