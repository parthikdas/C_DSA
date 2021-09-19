/*
Write a C program to store the list of files/directories present in a given directory into a file. Generate a report on the number and type of files 
present in the directory. 
Hint: Name of directory should be read from user
*/
#include <stdio.h>
#include <string.h>
#include <dirent.h>
int count = 0;//to see total number of files in that folder
void files(char *basePath, int root){
    char path[100];
    struct dirent *dp;// Pointer for directory entry
    // opendir() returns a pointer of DIR type.
    DIR *ptr = opendir(basePath);//opens a directory stream corresponding to the file path pointed by dirname
    if (ptr == NULL){// opendir returns NULL if couldn't open directory
        return;
    }
    // for readdir()
    while ((dp = readdir(ptr)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){// if we dont want .
            for(int i=0;i<root;i++){
                if(i%2==0 || i==0) printf("|");//starting and even places do |
                else printf(" ");//odd places leave a gap
            }
            count++;
            printf("|-%s", dp->d_name);
            char *s = strrchr(dp->d_name, '.');
            if(s == NULL) printf(" (Folder)\n");
            else if(strcmp(s,".txt")==0 || strcmp(s,".rtf")==0) printf(" (text file)\n");
            else if(strcmp(s,".c")==0) printf(" (c program file)\n");
            else if(strcmp(s,".java")==0) printf(" (Java program file)\n");
            else if(strcmp(s,".py")==0) printf(" (Python program file)\n");
            else if(strcmp(s,".html")==0) printf(" (Html program file)\n");
            else if(strcmp(s,".css")==0) printf(" (CSS program file)\n");
            else if(strcmp(s,".js")==0) printf(" (JavaScript program file)\n");
            else if(strcmp(s,".pdf")==0 || strcmp(s,".docx")==0 || strcmp(s,".ppt")==0) printf(" (Document)\n");
            else if(strcmp(s,".rar")==0) printf(" (Zip program file)\n");
            else if(strcmp(s,".jpg")==0 || strcmp(s,".jpeg")==0 || strcmp(s,".png")==0) printf(" (Picture)\n");
            else if(strcmp(s,".mp4")==0) printf(" (Video file)\n");
            else if(strcmp(s,".mp3")==0) printf(" (Audio file)\n");
            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            files(path, root+2);
        }
    }
    closedir(ptr);
}
int main(){
    char s[100];
    scanf("%s",s);
    files(s,0);
    printf("\nTotal number of files present is %d.\n",count);
    return 0;
}