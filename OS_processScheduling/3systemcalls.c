#include <stdlib.h> // exit(1)
#include <stdio.h>
#include <dirent.h> // DIR, readdir, opendir
#include <unistd.h> // useless
int main() {
	char buff[100];
	struct dirent *dptr; // Pointer for directory entry
	DIR *dirp;
	printf("Enter Directory Name: ");
	scanf("%s",buff);
	dirp = opendir(buff); // open a directory stream
	if (dirp == NULL) {
		printf("The given directory does not exist");
		exit(1);
	}
	dptr = readdir(dirp); // send stream as param and get pointer to struct
	while (dptr) {
		printf("%s\n",dptr->d_name);
		dptr = readdir(dirp);
	}
	closedir(dirp); // ends the stream
	return 0;
} 

// 1. what is DIR?
// Ans: The DIR data type represents a directory stream.

// 2. what opendir returns
// Ans: The opendir() function shall open a directory stream and returns a pointer of DIR type.

// 3. what readdir returns?
// Ans: The readdir() function returns a pointer to a structure representing the directory entry at the current 
// position in the directory stream specified by the argument dirp, and positions the directory stream at the next
// entry. It returns a null pointer upon reaching the end of the directory stream.

// 4. . means current directory, .. means parent directory

// 5. what is dirent struct?
// Ans: It contains the character pointer d_name, which points to a string that gives the name of a file in the directory. 