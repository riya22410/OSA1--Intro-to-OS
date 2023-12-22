#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<dirent.h>
#include<errno.h>
#include <sys/wait.h>
#include<stdbool.h>
#include<stdlib.h>
#define N 50
//If dir already exists in the main folder and "dir<filename>" is run, it throws an error
//If "dir -r" is called, it only checks for directories created using "dir", not the existing permament directories. In case, existing 
//permanent directories have the same name as input, it creates the new directory. 

char *globalfile = NULL;
int flag=0;
void dir(char path[]){ //if dir exists, throw exists 
    if(flag==1){
    printf("Processing: Checking if directory exists\n");}
    DIR* dir = opendir(path);       
    if (dir!=NULL) {/* Directory exists. */
    printf("Error: Directory already exists!\n");
    if(flag==1){
        printf("Processed: Directory already exists and error thrown! \n");
    }}
    else if (ENOENT == errno) {
        /* Directory does not exist. */
        //chdir("..");
        mkdir(path, 0777); //Assuming directory is only to be created in the cwd
        //printf("New directory created! \n");
        chdir(path);
        //printf("%s\n", getcwd(NULL, 100));
        //printf("Path changed\n");
        if(flag==1){
        printf("Processed: New directory has been created. \n");
    }}
    else{
    /* opendir() failed for some other reason. */
    printf("Sorry, we will get back to you soon\n");
    } 
}

void dirr(char path[]){ 
    if(flag==1){
    printf("Processing: Checking if directory exists\n");}
    DIR* dir = opendir(path);       
    if (dir!=NULL) {/* Directory exists. */
    //printf("hello");
    //chdir("C_RIYA");
    rmdir(path);
    //printf("Deleted existing directory");
    mkdir(path,0777);
    if(flag==1){
        printf("Processed: Existed directory deleted and new directory created! \n");
    }}
    
    else if (ENOENT == errno) {
        /* Directory does not exist. */
        //chdir("..");
        mkdir(path, 0777); //Assuming directory is only to be created in the cwd
        //printf("New directory created! \n");
        chdir(path);
        //printf("%s\n", getcwd(NULL, 100));
        //printf("Path changed\n");
        if(flag==1){
        printf("Processed: New directory has been created. \n");
    }}
    if(flag==1){
        printf("Processed: Existing directory was removed, new directory has been added!\n");
    }
}
void dirv(){
    flag=1;
    printf("Prompt display - ON\n");
}

int main(int argc, char *argv[]){
    char input[200];
    char s[100];
    int flag_exit=0;
    while(flag_exit!=1){
        pid_t pid;
        printf("C:/users/OSA2/2ii> ");
        fgets(input, sizeof(input), stdin);
        if(input[0] =='e' && input[1]=='x'&& input[2] =='i' && input[3] == 't'){
            //printf("hi");
            //exit(1);
            flag_exit=1;
            printf("Program terminated\n");
            break;
            return 0;
        }
            
        pid = fork();
        if(pid>0){
            wait(NULL);
            continue;
        }
        else if(pid ==0){
            execlp(input, input, (char *) NULL);
            if(input[0]=='d' && input[1]== 'i' && input[2]=='r' && input[3]==' '){
        if(input[4] == '-' && input[5] == 'v'&& input[6] == '\n'){
            dirv();
        }

        else if(input[4] !='-'){
            char temp[100];
            int checker = 0;
            for(int i = 4;input[i]!='\0';i++){
                if(input[i] == ' '){
                    checker= 1;
                    perror("Incorrect input format.\n");
                    break;
                }
                temp[i-4] = input[i];
            }
            if(checker == 0){
            dir(temp);
            }
        }

        else if(input[4] == '-' && input[5] == 'r' && input[6]==' '){
            char store[100];
            int check = 0;
            for(int i = 7;input[i]!='\n';i++){
                if(input[i] == ' '){
                    check = 1;
                    perror("Incorrect input format.\n");
                    break;
                }
                store[i-7] = input[i];
            }
            
            if(check == 0){
                dirr(store);
            }
        }
        }
        else{
            printf("Incorrect input format\n");
        }
          
        }
        else{
            printf("Error in fork!\n");
        }
    }}
