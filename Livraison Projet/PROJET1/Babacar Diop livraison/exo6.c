#include "bd.h"
#include <stdio.h>
#define N_POSITIONS 6
#define N_COULEUR 6

const char *POSITIONS[N_POSITIONS] = 
{

    "ADDP (au-dessus de la diagonale principale)", 
    "EDDP (en dessous de la diagonale principale)", 
    "SDP  (sur la diagonale principale)", 
    "ADDS (au-dessus de la diagonale secondaire)", 
    "EDDS (en dessous de la diagonale secondaire)", 
    "SDS  (sur la diagonale secondaire)"
};

const char *COULEURS[N_COULEUR] = 
{

    "\033[31m",
    "\033[32m",
    "\033[34m",
    "\033[00m",
    "\033[33m",
    "\033[35m",

};

int exo6()
{
    int n, position, couleur;

    int i, j;

    printf("Entrer l'odre de la matrice carrée:\n ");

    scanf("%d", &n);

    if (n <= 4) 
    {
        printf("Merci de saisir un nombre supperieur a 4\n");

        return 1;
    }

    printf("\nChoissir une position:\n");

    for (i = 0; i < N_POSITIONS; i++)
    {
        printf("%d. %s\n", i + 1, POSITIONS[i]);
    }

    printf("Entrer votre choix: ");

    scanf("%d", &position);

    if (position < 1 || position > N_POSITIONS) 
    {
        printf("Merci de choisir un nombre entre 1 et 6\n");

        return 1;
    }
    position--;

    printf("\nChoisir un couleur:\n");
    printf("1.ROUGE\n");
    printf("2.VERT\n");
    printf("3.BLEU\n");
    printf("4.JAUNE\n");
    printf("5.ORANGE\n");
    printf("6.MAGENTA\n");

    printf("Entrer votre choix: ");

    scanf("%d", &couleur);

    if (couleur < 1 || couleur > N_COULEUR)
    
    {
        printf("Invalide couleur\n");

        return 1;
    }
    couleur--;

    printf("\nMatrice générée:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {

            if (position == 0 && i < j) 

            {
                printf("%s\t", COULEURS[couleur]);
            } 

            else if (position == 1 && i > j) 

            {
                printf("%s\t", COULEURS[couleur]);
            }
               
            else if (position == 2 && i == j) 
            {
                printf("%s\t", COULEURS[couleur]);
            } 
            else if (position == 3 && i + j == n - 1) 
            {
                printf("%s\t", COULEURS[couleur]);
            }
             else if (position == 4 && i + j < n - 1)
            {
                printf("%s\t", COULEURS[couleur]);
            } 
            else if (position == 5 && i + j > n - 1) 
            {
                printf("%s\t", COULEURS[couleur]);
                
            } 
            else 
            {
                
                printf("1\t");      
            }
        }
       
         printf("\n");  
        
    }
}