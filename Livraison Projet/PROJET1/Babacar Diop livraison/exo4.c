#include "bd.h"
#include <stdio.h>

int numero_valide(char *Diop)
{
    int l =  Supp_ESpaces(Diop);
    if (Diop[0] != '7' ||
        (Diop[1] != '0' && Diop[1] != '5'&& Diop[1] != '6' && Diop[1] != '7'&& Diop[1] != '8' ))

        return 0;

    for (int i = 0; i < l; i ++)
        if (Diop[i] != ' ' && (Diop[i] < '0' || Diop[i] > '9'))

            return 0;

    return 1;
}


void copie_chaine(char *source, char *destination)
{
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i ++;
    }
    destination[i] = '\0';
}


int longueur_sans_espaces(char *Diop)
{
    int i, len;
    for (i = 0, len = 0; Diop[i] != '\0'; i ++)
        if (! est_espace(Diop[i]))
            len ++;
    return len;
}


int contient_caracteres_speciaux(char *s)
{
    int n, nca, tmp, i, j;
    char caracteres_autorises[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    " \n\t.?!,;:-()'\"°"
    "0123456789";
    nca = longueur_chaine(caracteres_autorises);

    for (i = 0, n = longueur_chaine(s); i < n; i ++)
    {
        for (j = 0, tmp = 0; j < nca; j ++)
            if (s[i] == caracteres_autorises[j])
            {
                tmp = 1;
                break;
            }
        if (! tmp)
            return 1;
    }

    return 0;
}


int ponctuation(char *s)
{
    int len = longueur_chaine(s);
    if (s[len-1] == '.' || s[len-1] == '!' || s[len-1] == '?')
        return 1;
    return 0;
}


int  Supp_ESpaces(char *Diop)
{
    int i, j, len = longueur_chaine(Diop);

    while (est_espace(Diop[0]))
        len = decaler_gauche(Diop);

    for (i = 1; i < len; i ++)
        if (est_espace(Diop[i]))
            while (est_espace(Diop[i+1]))
                len = decaler_gauche(Diop+i+1) + i + 1;

    if (est_espace(Diop[longueur_chaine(Diop)-1]))
        Diop[--len] = '\0';

    return len;
}


int est_espace(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}



int decaler_gauche(char *Diop)
{
    int i, len = longueur_chaine(Diop)-1;
    for (i = 0; i < len; i ++)
        Diop[i] = Diop[i+1];
    Diop[len] = '\0';
    return len;
}

void enonce(char *eno)
{
    printf("\n%s",eno);
}

int longueur_chaine(char *Diop)
{
    int i;
    for (i = 0; Diop[i] != '\0'; i ++);
    return i;
}




void vider (void)
{    
  while (getchar() != '\n');
}

void exo4()
{

    int i, n, l, invnr, validnr;
    char num[100], inv[100][100], valid[100][100];

    do {
        printf("\nDonner le nombre de numeros a saisir : ");
    } while (! scanf("%d", &n)|| n < 1);
    vider();

    i = 0;
    invnr = 0;
    validnr = 0;

    while (i < n)
    {
        printf("Donner le numero %d : ", i+1);
        scanf("%[^\n]", num);
        (num);
        l = longueur_sans_espaces(num);
        vider();

        if (l == 9 && numero_valide(num)) {
            copie_chaine(num, valid[validnr]);
            validnr ++;
        }
        else 
        {
            copie_chaine(num, inv[invnr]);
            invnr ++;
        }

        i ++;
    }

    printf("Numeros correct :\t\t\tNumeros incorrect :\n");
    for (i = 0; i < 1; i ++)
    {
        if (i < validnr)
            printf("%s", valid[i]);
        if (i < invnr)
            printf("\t\t\t\t%s\n", inv[i]);
    }


}



