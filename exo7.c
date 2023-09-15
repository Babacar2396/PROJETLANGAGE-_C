#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char phrase[100];
    int i, j, longueur;

    printf("Entrez une phrase : \n ");

    // Lire la phrase avec des espaces

    scanf("%[^\n]", phrase); 

    // Déterminer la longueur de la phrase

    longueur = strlen(phrase); 

    for (i = 0; i < longueur; i++)

    {
    // Si le caractère est un espace, afficher "00"

        if (isspace(phrase[i]))
        {
            printf("00");
        }
    // Si le caractère est une lettre  
     
        else if (isalpha(phrase[i])) 

        {

    // Convertir en majuscule

            switch (toupper(phrase[i])) 
            {
                    case 'A': printf("2"); break;
                    case 'B': printf("22"); break;
                    case 'C': printf("222"); break;
                    case 'D': printf("3"); break;
                    case 'E': printf("33"); break;
                    case 'F': printf("333"); break;
                    case 'G': printf("4"); break;
                    case 'H': printf("44"); break;
                    case 'I': printf("444"); break;
                    case 'J': printf("5"); break;
                    case 'K': printf("55"); break;
                    case 'L': printf("555"); break;
                    case 'M': printf("6"); break;
                    case 'N': printf("66"); break;
                    case 'O': printf("666"); break;
                    case 'P': printf("7"); break;
                    case 'Q': printf("77"); break;
                    case 'R': printf("777"); break;
                    case 'S': printf("7777"); break;
                    case 'T': printf("8"); break;
                    case 'U': printf("88"); break;
                    case 'V': printf("888"); break;
                    case 'W': printf("9"); break;
                    case 'X': printf("99"); break;
                    case 'Y': printf("999"); break;
                    case 'Z': printf("9999"); break;
                default:

    // Si la lettre n'est pas reconnue, ne rien faire

                    break;
            }

     // Vérifier si la prochaine lettre partage le même code
    // Si oui, ajouter un "0"
    
    // la fonction toupper permet de convertir les lettres en majuscules

            if (i < longueur - 1 && isalpha(phrase[i + 1]))
            {
                switch (toupper(phrase[i]))
                {
                    case 'A':
                        if (toupper(phrase[i + 1]) == 'A')
                            printf("0");
                        break;
                    case 'B':
                        if (toupper(phrase[i + 1]) == 'B')
                            printf("0");
                        break;
    
                    case 'C':
                        if (toupper(phrase[i + 1]) == 'C')
                            printf("0");
                        break;
                    case 'D':
                        if (toupper(phrase[i + 1]) == 'D')
                            printf("0");
                        break;
                    case 'E':
                        if (toupper(phrase[i + 1]) == 'E')
                            printf("0");
                        break;
                    case 'F':
                        if (toupper(phrase[i + 1]) == 'F')
                            printf("0");
                        break;
                    case 'G':
                        if (toupper(phrase[i + 1]) == 'G')
                            printf("0");
                        break;
                    case 'I':
                        if (toupper(phrase[i + 1]) == 'I')
                            printf("0");
                        break;
                    case 'J':
                        if (toupper(phrase[i + 1]) == 'J')
                            printf("0");
                        break;
                    case 'K':
                        if (toupper(phrase[i + 1]) == 'K')
                            printf("0");
                        break;
                    case 'L':
                        if (toupper(phrase[i + 1]) == 'L')
                            printf("0");
                        break;
                    case 'M':
                        if (toupper(phrase[i + 1]) == 'M')
                            printf("0");
                        break;
                    case 'N':
                        if (toupper(phrase[i + 1]) == 'N')
                            printf("0");
                        break;
                    case 'P':
                        if (toupper(phrase[i + 1]) == 'P')
                            printf("0");
                        break;
                    case 'Q':
                        if (toupper(phrase[i + 1]) == 'Q')
                            printf("0");
                        break;
                    case 'R':
                        if (toupper(phrase[i + 1]) == 'R')
                            printf("0");
                        break;
                    case 'S':
                        if (toupper(phrase[i + 1]) == 'S')
                            printf("0");
                        break;
                    case 'T':
                        if (toupper(phrase[i + 1]) == 'T')
                            printf("0");
                        break;
                    case 'U':
                        if (toupper(phrase[i + 1]) == 'U')
                            printf("0");
                        break;
                    case 'V':
                        if (toupper(phrase[i + 1]) == 'V')
                            printf("0");
                        break;
                    case 'W':
                        if (toupper(phrase[i + 1]) == 'W')
                            printf("0");
                        break;
                    case 'X':
                        if (toupper(phrase[i + 1]) == 'X')
                            printf("0");
                        break;
                    case 'Y':
                        if (toupper(phrase[i + 1]) == 'Y')
                            printf("0");
                        break;
                    case 'Z':
                        if (toupper(phrase[i + 1]) == 'Z')
                            printf("0");
                        break;
                    default:
                        break;
                }
            }
        }
     // Si le caractère n'est ni une lettre ni un espace

        else 
        {

   // Afficher le caractère tel quel

            printf("%c", phrase[i]);
        }
    }

    printf("\n");

    return 0;
}