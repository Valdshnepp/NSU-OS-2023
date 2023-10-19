#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	
	if (argc<2){
		printf("not enough args\n");
		return 0;
	}

	int status;
	pid_t ret;
	pid_t pid; 
	
	if ((pid = fork())==-1){
	perror("fork error");
	return 1;
	}

	if (pid == 0){
	if ( execvp(argv[1],&argv[1])==-1){
		perror("exec error");
		return 1;
		}
	}
	if ((ret=wait(&status))==-1){
	perror("wait error");
	return 1;
	}

	if (WIFEXITED(status)!=0){
		int exit_status = WEXITSTATUS(status);
		printf("exit status is %d\n",exit_status);
	}

	if (WIFSIGNALED(status)!=0){
		int sig_num = WTERMSIG(status);
		printf("end signal is $d\n");
	}
	return 0;
}

