#include <stdio.h>
#include <unistd.h> // fork() and getpid()
#include <sys/types.h> // useless
#include <stdlib.h> // exit(1)

int main() {
	int pid1,pid2,pid3;
	// printf("a | ");
	pid1 = fork(); // fork() creates a new child process and returns the pid of the child. In the child, fork returns 0 which is not the pid of anything, it's just a marker that its a child or -1 (unsuccessful)
	// printf("b | ");
	if (pid1 == -1) {
		printf("Error");
		exit(1);
	}
	// printf("c\n");
	printf("%d ",pid1);
	if (pid1 != 0) {
		pid2 = getpid(); // getpid() - returns the process ID of the calling process
		printf("Parent process id: %d\n",pid2);
	} else {
		pid3 = getpid();
		printf("Child process id: %d",pid3);
	}
	return 0;
}


// Why the code is going through twice after using fork?? (if u uncomment the statements u will see they are runned twice)
/*
So, if you're implementing fork, you have to create a second process without ending the first. Then the return-twice 
behavior will happen naturally: each of the two distinct processes will continue execution, only differing in the value
they return (the child giving zero, and the parent giving the child's PID).
*/

/*
If you're the parent, fork() returns the pid of the other process, the child. And if you're the child, fork() doesn't return a pid at all. (If you're the child and you want to know the pid of your parent, that's a good, frequent, and separate question. Answer: call getppid().)

We can summarize all this as follows:

                 parent   child
                 ------   -----
pid:              25110   25111
fork returns:     25111       0
getpid returns:   25110   25111
getppid returns:  ?????   25110
*/