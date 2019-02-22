#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <regex.h>

void trim(char * str){
    int count = 0;
    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i]; // here count is
    // incremented
    str[count] = '\0';
}

int match(const char *string, const char *pattern)
{
    regex_t re;
    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) return 0;
    int status = regexec(&re, string, 0, NULL, 0);
    regfree(&re);
    if (status != 0) return 0;
    return 1;
}


int main() {
    const char* re = "[ ]*[0-9]+[ ]*[+|-|*|/][ ]*[0-9]+[ ]*";
    char str[50];
    printf("Enter the ion string or 0 (zero) to quit:\n");
    scanf("%[^\n]s", str);
    trim(str);
    printf(str);
    if (strcmp(str, "0")==0){
        printf("Quitting, bye");
        exit(0);
    }
    else{
        if(!match(str, re)){
            printf("Please enter your expression in the following order:(Operand Operator Operand), please try again.\n");
        }
        else{
            int i = 0;
            int index =0;
            int symbol = 0;
            char calc1[50];
            char calc2[50];
            while(str[i]!='+' && str[i]!='-'&& str[i]!='/'&& str[i]!='*'){
                calc1[index]=str[i];
                index++;
                symbol++;
                i++;
                }
            index =0;
            while(str[i] != '\0'){
                calc2[index] = str[i];
                index++;
                i++;
            }
            //todo do strtol for both calc1 and calc2 and then do the thing about plus
            //minus and so forth
            //symbol should now equal exactly what the symbol is. 
        }

    }

    return 0;
}