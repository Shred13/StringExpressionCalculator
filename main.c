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
    //regex function that checks to see if a string matches the regex pattern
}


int main() {
    const char* re = "[0-9]+[+|*|/|-][0-9]+";
    // regex string to check if it is in the same format
    char str[100]="";

    printf("Enter the expression string or 0 (zero) to quit:\n");
    gets(str);
    //input, understood that it is insecure but it works fine
    trim(str);
    if (strcmp(str, "0")==0){
        printf("Quitting, bye");
        exit(0);
        //if the input string is 0, it will exit the program
    }
    else{
        if(!match(str, re)){
            printf("Please enter your expression in the following order:(Operand Operator Operand), please try again.\n");
            // if the input string does not match the regex expression, then it will loop back and go to main (to re-query the question)
            main();
        }
        else{
            int i = 0;
            int index =0;
            char calc1[101];
            char calc2[101];
            // the following two while loops split the original string into two parts, calc1 which holds the first part of the equation and calc2 which holds the second part
            //it is split up by the operator
            while(str[i]!='+' && str[i]!='-'&& str[i]!='/'&& str[i]!='*'){
                calc1[index]=str[i];
                index++;
                i++;
                }
            index =0;
            calc1[100] = (char) "\0";
            //the end of the first equation has an end terminal automatically appended to it to ensure that it remains as a string for later use and does not get skewed in the process
            char symbol = str[i];
            // the position at where the while loop above ended is saved in the symbol variable
            i++;
            while(str[i] != '\0'){
                calc2[index] = str[i];
                index++;
                i++;
            }

            int equation1 = atoi(calc1);
            int equation2 = atoi(calc2);
            // cause both calc1 and calc2 to go from string to ints
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
            // the above if statement does the actual calculation and the answer is then printed below
            printf("%i", answer);
            printf("\n");

            main();
            //once everything has run, it loops again for further querying
        }

    }

    return 0;
}