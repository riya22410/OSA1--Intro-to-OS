// if a command is entered as word -d file1.txt then counting the difference by assuming the other file to be null.
// in -d we are taking just 2 input file and if other are entered then making them null and executing . 
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define N 50
char *globalfile = NULL;
int flag=0;
int wordcommand2(int argc, char *argv[]) //word -n type
{
    FILE *file;
    char character;
    bool inWord = false;
    file = fopen(globalfile, "r"); // change file name
    int count = 0;
    int i = 0;

     if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }
    char prechar=' ';
    while ((character = fgetc(file)) != EOF) {
        // Check if the character is not a newline character 
        if (character == ' ' && prechar !='\n'){
                count++;
            }
        if (character=='\n'){
            if(prechar!=' ' && prechar!= '\n'){
                count++;
            }
        }
        prechar=character;
    }
    if(prechar==' '|| prechar =='\n'){
        count--;
    }
    fclose(file);
    printf("The number of words is %d ", count+1);
    return 0;
}

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

int wordcount(char *filename) //word <file1.txt>
{
    char ch;
    FILE *file;
    int count = 0;
    char pre_char=' ';
    char prepre_char=' ';
    file = fopen(filename, "r");

    while ((ch = fgetc(file)) != EOF)
    {
        
        if (ch == ' '){
            count++;
            //pre_char=ch;
        }
        else if(ch=='\n' && pre_char!=' '){
            count++;
        }
        prepre_char=pre_char;
        pre_char= ch;
        
    }
    // printf(" prechar - '%c' ", pre_char);
    if (pre_char == ' '){
                count--;
            }
    else if(pre_char=='\n' && prepre_char!=' '){
        count--;
    }
    if(flag==0){
        printf("Number of words present in given file: %d", count+1);
    }
    fclose(file);

    return count+1;
}

int differenceBetweeenWords(char *file1, char *file2)
{
    FILE *fptr1, *fptr2;
    fptr1 = fopen(file1, "r");
    fptr2 = fopen(file2, "r");
    char wordLine1[N];
    char wordLine2[N];
    char ch;
    int count1 = 0, count2 = 0;
    if (fptr1==NULL && fptr2==NULL){
        printf("Both files are empty");
        return 0;
    }

    else if (fptr1 == NULL)
    {
        while (fgets(wordLine2, sizeof(wordLine2), fptr2))
        {
            count2 = wordcount(file2);
        }
    }
    else if (fptr2 == NULL)
    {
        while (fgets(wordLine1, sizeof(wordLine1), fptr1))
        {
            count1 = wordcount(file1);
        }
    }
    else
    {   while(fgets(wordLine1, sizeof(wordLine1), fptr1)){
        count1 = wordcount(file1);
    }
        while(fgets(wordLine2, sizeof(wordLine2), fptr2)){
        count2 = wordcount(file2);
        }
    }
        //printf("dfs\n");
        fclose(fptr1);
        fclose(fptr2);
        return count1 - count2;
    
}

int main(int argc, char *argv[])
{
    char option[4];  // input
    char input[100]; //
    // char substring[]
    char file_name[20];
    int neededword = 0;
    // char substring[extr]
    printf("C:/users/OSA2/2i> ");
    fgets(input, sizeof(input), stdin);
    int originalword = strlen(input);
    if (originalword > 0 && input[originalword - 1] == '\n')
    {                                   // string in char arry
        input[originalword - 1] = '\0'; // Replace newline with null terminator
    }
    int words = countWords(input);
    // printf("Number of words: %d\n", words);

    if (argc < 1)
    {
        printf("Usage needed: command [option] [file_name]\n");
        return 1;
    }
    int ignoreNewline = 0;
    int differenceBetweenFilesWords = 0;
    char file1[100];
    char file2[100];
    if (words == 2)
    {
        char *word = strrchr(input, ' ') + 1;
        //printf(" dasb %s\n", word);
        globalfile = word;
        wordcount(globalfile); // space cout done  mormal input working
    }

    for (int i = 0; i < argc; i++)
    {
        char mode[3];
        if (originalword >= 8)
        { 
            if (input[5] == '-' && input[6] != ' ')
            {   
                strncpy(mode, input + 5, 2);
                mode[2] = '\0'; // Null-terminate the substring
                // printf("Mode: %s\n", mode);

                if (!strcmp(mode, "-n"))
                {
                    // printf("hi");
                    neededword = 8;
                    int extractword = originalword - neededword;
                    char substring[extractword + 1];
                    // printf("%d\n", neededword);
                    strncpy(substring, input + neededword, extractword);
                    // printf("%s\n", substring);
                    globalfile = substring;
                    // printf("Stored file name: %s\n", globalfile);
                    wordcommand2(argc, argv);
                    // printf("hi");
                    return 0;
                }
                else if (!strcmp(mode, "-d"))
                {   flag=1;
                    differenceBetweenFilesWords = 1;
                    neededword = 8;
                    int extractword = strlen(input) - neededword;
                    char substring[extractword + 10];
                    strncpy(substring, input + neededword, extractword);
                    substring[extractword] = '\0';
                    ignoreNewline = 1;
                    // printf("substing %s", substring);
                    sscanf(substring, "%s %s", file1, file2);
                    // printf("%s\n", file1);
                    // printf("%s\n", file2);

                    int difference = differenceBetweeenWords(file1, file2);

                    if (difference >= 0)
                    {
                        printf("Word count difference between %s and %s: %d\n", file1, file2, difference);
                    }
                    else {
                        difference= -1 *(difference);
                        printf("Word count difference between %s and %s: %d\n", file1, file2, difference);
                    }
                }
                else{
                    printf("Incorrect input format!\n");
                }

                return 0;
            }
        }
    }
}
