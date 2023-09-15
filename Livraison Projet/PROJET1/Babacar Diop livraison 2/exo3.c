#include<stdio.h>

#define N 5
#define MIN_LEN 25

int mon_strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

int c_un_espace(int c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

void supprime_Espaces(char *str) {
    int i, j = 0;
    char prev = ' ';
    int len = mon_strlen(str);
    for (i = 0; i < len; i++) {
            if(c_un_espace(str[i]) && c_un_espace(str[i+1]) )
            {
                for (j = i+1; j < len-1; j++)
                    str[j] = str[j+1];
                str[j] = '\0';
                len --; if (i) i --;
            }
       }
}
        
char *occurence_ou_strchr(const char *s, int c) 
{
    while (*s != '\0') 
    {
        if (*s == c) 
        {
            return (char *) s;
        }
        s++;
    }
    if (c == '\0')
     {
        return (char *) s;
     }
    return NULL;
}
int car_spe(char *s)
{
    char spe[] = "#@&*";
    int i, j, n= mon_strlen(s);
    for (i = 0; i < n; i ++)
        for (j = 0; j < mon_strlen(spe); j ++)
            if (s[i] == spe[j])
                return 1;
    return 0;
}
int main() {
    int i, len;
    char phrases[N][MIN_LEN + 1];
    printf("Entrez jusqu'à %d phrases (chacune au moins %d caractères), terminées par un point (.), un point d'interrogation (?) ou un point d'exclamation (!) :\n", N, MIN_LEN);
    for (i = 0; i < 1; i++) {
        printf("Donner la phrase %d : ", i+1);
        scanf("%[^\n]", phrases[i]);
        supprime_Espaces(phrases[i]);
        printf("%s\n", phrases[i]);
        len = mon_strlen(phrases[i]);
        if (phrases[i][0] < 'A' || phrases[i][0] > 'Z')
            printf("La phrase doit debuter par une majuscule\n");
        else if (car_spe(phrases[i]))
            printf("La phrase contient des caracteres speciaux\n");
        else if (phrases[i][len-1] != '.' && phrases[i][len-1] != '!' && phrases[i][len-1] != '?')
            printf("Pas de ponctuation");

    }
    return 0;
}