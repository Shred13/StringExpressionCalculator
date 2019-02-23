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
    const char* re = "[0-9]+[+|-|*|/][0-9]+";
    char str[100];
    printf("Enter the expression string or 0 (zero) to quit:\n");
    scanf("%[^\n]s", str);
    trim(str);
    if (strcmp(str, "0")==0){
        printf("Quitting, bye");
        exit(0);
    }
    //TODO TAKE A LOOK FOR A NEGATIVE SIGN AND FIND OUT ABOUT REGEX NEGATIVE
    //todo also find out why it seems to get a value in mind for recursive tings.
    else{
        if(!match(str, re)){
            printf("Please enter your expression in the following order:(Operand Operator Operand), please try again.\n");
        }
        else{
            int i = 0;
            int index =0;
            char calc1[101];
            char calc2[101];
            while(str[i]!='+' && str[i]!='-'&& str[i]!='/'&& str[i]!='*'){
                calc1[index]=str[i];
                index++;
                i++;
                }
            index =0;
            calc1[100] = (char) "\0";
            char symbol = str[i];
            i++;
            while(str[i] != '\0'){
                calc2[index] = str[i];
                index++;
                i++;
            }

            int equation1 = atoi(calc1);
            int equation2 = atoi(calc2);
            int answer = 0;
            if (symbol == '+'){
               answer = equation1+equation2;
            }
            else if (symbol == '-'){
                answer = equation1-equation2;
            }
            else if (symbol == '*'){
                answer = equation1*equation2;
            }
            else if (symbol == '/'){
                answer = equation1/equation2;
            }
            printf("%i", answer);
            printf("\n");

            main();
        }

    }

    return 0;
}