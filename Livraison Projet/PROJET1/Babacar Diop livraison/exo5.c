#include "bd.h"
#include <stdio.h>
#include <string.h>

void exo5()
{
     int n, i, j;
    char couleur[10], position[10];

    printf("Entrez l'ordre de la matrice carrée ;l'odre de la matrice doit etre supperieur a 5: ");
    scanf("%d", &n);
    while (n <= 5) {
        printf("L'ordre de la matrice ne doit pas etre inferieur 5.\n");
        printf("Entrez l'ordre de la matrice carrée: ");
        scanf("%d", &n);
    }

    printf("Choisissez une couleur (Bleu ou Rouge): ");
    scanf("%s", couleur);
    while (strcmp (couleur, "Bleu") != 0 && strcmp(couleur, "Rouge") != 0) 
    {
        printf("Invalide couleur.Choisissez encore une couleur\n");
        printf("Entrer une couleur (Bleu ou Rouge): ");
        scanf("%s", couleur);
    }

    printf("Choisissez une position (HAUT ou BAS):\n ");
    scanf("%s", position);
    while (strcmp(position, "HAUT") != 0 && strcmp(position, "BAS") != 0) 
    {
        printf("Invalide position.Choisissez une position (HAUT ou BAS) .\n");
        printf("Entrer une position (HAUT oU BAS): ");
        scanf("%s", position);
    }

    printf("Le couleur du matrice est: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((strcmp(position, "HAUT") == 0 && i < j) || (strcmp(position, "BAS") == 0 && i > j))
                printf("%s\t", couleur);
            else
                printf("1\t");
        }
        printf("\n");
    }
}