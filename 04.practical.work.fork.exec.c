#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int pid = fork();
	if(pid == 0){
		printf("Child is running:\n");
		char *args[] = {"free", "-h", NULL};
		execvp("free", args);
	}
	else{
		wait(NULL);
		printf("Parent is running:\n");
		char *args[]={"/bin/ps", "-ef", NULL};
		execvp("/bin/ps", args);	
}
	return 0; 
}
