#include<stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
# include<stdbool.h>
# define N 100
char *globalfile=NULL;
int countWords(const char *sentence)
{
    int wordCount = 0;
    bool inWord = false;

    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '\t' || sentence[i] == '\n')
        {
            inWord = false;
        }
        else if (!inWord)
        {
            inWord = true;
            wordCount++;
        }
    }

    return wordCount;
}

void *get_last_modified(char *file) {

    time_t current_time;
    struct tm *time_info;

    time(&current_time);
    time_info = localtime(&current_time);  

    char formatted_time[64];
    strftime(formatted_time, sizeof(formatted_time), "%a %d %b %H:%M:%S PM IST %Y", time_info); 
    printf("Last modified time: %s\n", formatted_time);
    return 0;
}

void date_command(struct stat stats ){ //RFC 
    time_t current_time;
    struct tm *time_info;

    time(&current_time);
    time_info = gmtime(&current_time);  

    char formatted_time[64];
    strftime(formatted_time, sizeof(formatted_time), "%a, %d %b %Y %H:%M:%S %z", time_info);
    printf("Last modified time: %s\n", formatted_time);
    
}

int main(){
    char file[N];
    struct stat stats;
    char option[4];  
    char input[200];
    char s[100];
    int flag_exit=0;
    while(flag_exit!=1){
        pid_t pid;
        printf("C:/users/OSA2/2iii> ");
        fgets(input, sizeof(input), stdin);
        if(input[0] =='e' && input[1]=='x'&& input[2] =='i' && input[3] == 't'){
            flag_exit=1;
            printf("Program terminated\n");
            return 0;
            break;
            
        }
        pid = fork();
        if(pid>0){
            wait(NULL);
            continue;
        }
        else if(pid ==0){
            execlp(input, input, (char *) NULL);
            if(input[0]=='d' && input[1]== 'a' && input[2]=='t' && input[3]=='e' && input[4]==' '){
            if(input[5] !='-'){
            char temp[100];
            int checker = 0;
            for(int i = 5;input[i]!='\0';i++){
                if(input[i] == ' '){
                    checker= 1;
                    perror("Incorrect input format.\n");
                    break;
                }
                temp[i-5] = input[i];
            }
            if(checker == 0){
            get_last_modified(temp);
            }
        }

        else if(input[5] == '-' && input[6] == 'R' && input[7]==' '){
            char store[100];
            int check = 0;
            for(int i = 8;input[i]!='\n';i++){
                if(input[i] == ' '){
                    check = 1;
                    perror("Incorrect input format.\n");
                    break;
                }
                store[i-8] = input[i];
            }
            
            if(check == 0){
                date_command(stats);
            }

        }
        else if(input[5] == '-' && input[6] == 'd' && input[7]==' '){

            char store2[100];
            int check2 = 0;
            for(int i = 8;input[i]!='\n';i++){
                if(input[i] == ' '){
                    check2 = 1;
                    perror("Incorrect input format.\n");
                    break;
                }
                store2[i-8] = input[i];
            }
            
            if(check2 == 0){
                get_last_modified(store2);
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
    }
}
