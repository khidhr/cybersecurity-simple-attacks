#include<stdio.h>
#include<stdlib.h>
#include "md5.h"
#include<string.h>

// a brute force attack to compromise passwords of 5 alphabets hashed with MD5

#define target "2518907025e27330286b1981ce79855c"

int main()
{
    char word[10] = "-----";

    
        
            for (char c0 = 'a'; c0 <= 'z'; c0++)
            {
                word[0] = c0;
                for(char c1 = 'a'; c1 <= 'z';c1++)      
                {
                    word[1] = c1;
                    for(char c2 = 'a' ; c2 <= 'z';c2++)
                    {
                        word[2] = c2;
                        for(char c3 = 'a' ; c3 <= 'z' ;c3++)
                        {
                            word[3] = c3;
                            for(char c4 = 'a' ; c4 <= 'z';c4++)
                            {                               
                                word[4] = c4;

                                char* hash = md5(word,strlen(word));
                                printf("%s\n",word);
                                if(strcmp(hash,target)==0)
                                {
                                    printf("found it!,%s \n",word);
                                    exit(0);
                                }
                            }
                        }    
                    }
                }
            }
        
    
}