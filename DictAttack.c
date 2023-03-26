#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"md5.h"

#define ROCKYOU "rockyou1m.txt"

int main(int argc , char* argv[])
{
    if(argc <2)
    {
        fprintf(stderr,"Usage %s hash to crack", argv[0]);
        exit(1);
    }
    // hash must be the second argument to this program to run
    char* target = argv[1];

    // opening the the rockyou file that counatin the most frequent used passwords
    FILE *dict = fopen(ROCKYOU,"r");

    if(!dict)
    {
        char err[100];
        sprintf(err,"file %s can not be opened",ROCKYOU);
        perror(err);
        exit(1);
    }

    char word[100];
    while(fgets(word,100,dict) != NULL)
    {
        char *nl =strchr(word, '\n');
        if (nl) *nl = '\0';


        char *hash = md5(word,strlen(word));
        if(strcmp(hash,target)==0)
        {
            printf("\nFOUND!:%s is the hash of:  %s \n",hash,word);
            fclose(dict);
            exit(0);
        }
    }
    printf("password not found :( \n");
}