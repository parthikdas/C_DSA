#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void* func(void* arg) {
	pthread_detach(pthread_self()); // pthread_detach() function is used to indicate to your application that storage for the thread
	// tid can be reclaimed when the thread terminates.
	printf("Inside the thread\n");
	pthread_exit(NULL);
}
void fun() {
	pthread_t ptid; // pthread_t is the data type used to uniquely identify a thread. It is returned by pthread_create()
	pthread_create(&ptid,NULL,&func,NULL);
	printf("This line may be printed before thread terminate\n");
	if(pthread_equal(ptid,pthread_self())) // pthread_self() returns current thread id
		printf("Threads are equal\n");
	else
		printf("Threads are not equal\n");
	pthread_join(ptid,NULL); // The pthread_join() function provides a simple mechanism allowing an application to wait for a thread 
	//to terminate. If you want to be sure that your thread have actually finished, you want to call pthread_join . If you don't, then terminating your program will terminate all the unfinished thread abruptly.
	printf("This line print after thread ends\n");
	pthread_exit(NULL); //  terminates the calling thread
}
int main() {
	fun();
	return 0;
}
// p thread - POSIX thread
// A thread is a single sequence stream within in a process
// Process means any program is in execution. Thread means a segment of a process.