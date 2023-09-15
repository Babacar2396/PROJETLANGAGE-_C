#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

void remove_spaces(char *phrase) {
    
    int i, j;

    int n = strlen(phrase);

    for (i = 0, j = 0; i < n; i++) 
    {
        if (!isspace(phrase[i])) 
        {
            phrase[j] = phrase[i];

            phrase[j++];
        } 
        else if (j > 0 && !isspace(phrase[j-1])) 
        {
            phrase[j++] = ' ';
        }
    }
    phrase[j] = '\0';
}

int main() {
    char phrase[MAX_LENGTH];

    printf("Saisissez une phrase  (100 caracteres max ) : ");

    fgets(phrase, MAX_LENGTH, stdin);

    remove_spaces(phrase);

    printf("Phrase sans espaces inutiles : '%s'\n", phrase);


    return 0;
}