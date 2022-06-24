#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include<stdio.h>
#include <errno.h>

int main() 
{ 
	// Fork returns process id 
	// in parent process 
	pid_t child_pid = fork(); 

	// Parent process 
	if (child_pid > 0){
		sleep(10);
        printf("Process Id of the process which has terminated but still in the table %d\n", child_pid);
        if (errno == EAGAIN) {
            
        }
    }
	// Child process 
	else{
		exit(0); 
    }
	return 0; 
}
