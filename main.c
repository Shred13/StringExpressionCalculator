#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

void trim(char * str){
    int index, i;
    index = 0;
    while (str[index]!='\0'){
        if (str[index] == ' '){
            int temp = index +1;
            if (str[index] != '\0'){
                while (str[index] == '\0'){

                }
            }
        }
    }
}

int main() {
    char str[100];
    printf("Enter the ion string or 0 (zero) to quit:\n");
    scanf("%[^\n]s", str);
    if (strcmp(str, "0")==0){
        printf("Quitting, bye");
        exit(0);
    }
    else{

    }

    return 0;
}