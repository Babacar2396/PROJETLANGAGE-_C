#include <stdio.h>
#include "bd.h"
#include <string.h>
#define FICHIER "fichier.txt"

int main() {
  int choice,rep=1;
  while (1) {
    do{
        printf("\nMenu:\n");
        printf("1. exercice 4\n");
        printf("2. exercice 5\n");
        printf("3. exercice 6\n");
        printf("4. exercice 7\n");
        printf("5. exercice 8\n");
        printf("6. exercice 9\n");
        printf("7. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);
        getchar();
        if (!( (choice>=1) && (choice<=7)))
        {
            printf("\nNON pris en charge\n ");
        }
        else 
        {
            rep=0;
            if (choice==6)
            {
                printf("\nMerci\n");
            }
            
        }
        
        

    }while (rep);
    
    switch (choice) {
      
      case 1:
        enonce("Exercice 4 :\n Écrire un programme qui permet de remplir N numéros à\npartir d’une chaîne. Le programme ré-affiche les numéros\n\nvalides à gauche et les numéros invalides à droite de\nl'écran .Le programme affichera aussi le nombre de\nnuméros de chaque opérateur .");
        exo4();
        break;

      case 2:
        enonce("Exercice 5 :\nProposer un programme qui permet la saisie:\n De l’ordre d’une matrice carrée\n.Un Menu de choix avec comme options Bleu et Rouge\n.Un Menu de choix pour la position de la couleur Bleu avec comme valeur HAUT ou BAS.\nLorsque l’utilisateur valide , le programme devra dessiner la matrice en la coloriant suivant les couleurs et les positions choisies par l’utilisateur.");
        exo5();
        break;

      case 3 :
        enonce("Exercice 6 :\nProposer un programme qui permet la saisie \n:De l’ordre d’une matrice carrée\n.Un Menu de choix pour la position de la couleur\n.ADDP, au-dessus de la diagonale principale\n.EDDP, en dessous de la diagonale principale\n.SDP,sur la diagonale principale\n.ADDS, au-dessus de la diagonale secondaire\n.EDDS, en dessous de la diagonale secondaire\n.SDS,sur la diagonale secondaire\n.Un Menu de choix ayant comme options des couleurs\n.Lorsque l’utilisateur valide , le programme devra dessiner la matrice en la coloriant suivant les couleurs et les positions choisies par l’utilisateur.\n");
        exo6();
        break;

      case 4 :
        enonce("Exercice 7 :\nÉcrire un programme qui, à partir d’une phrase\n, affiche son équivalent codé\n.Règles de codage de la phrase\n:On considère le clavier avec les anciens téléphones avec touches\n");
        exo7();
        break;

      case 5 :
       enonce("Exercice 8 :\nDemander des informations concernant l’étudiant tant que l’utilisateur \ndésire continuer.\nVous devez demander le téléphone, nom, prénom, classe,note de devoir,\nnote de projet et note d’examen pour\nensuite calculer la moyenne et afficher le résultat sous \nforme du tableau ci- dessous lorsque l’utilisateur\nterminera sa saisie.");
       exo8();
       break;

      case 6 :
       enonce("Exercice 9 :\nSaisir une suite d’ opérateurs téléphoniques\n(Orange,Tigo,expresso,...) puis génère une matrice dont le \nnombre de lignes est égal au nombre d’opérateurs saisis.\n1.Saisir les informations d’un client (nom,prénom,numéro \ntéléphone) et le ranger dans la ligne de l'opérateur \ncorrespondant à son numéro de téléphone.\n2. Afficher les clients de la matrice par opérateurs \n3. Afficher les clients d’un opérateur \n4. Afficher les numéros téléphone d’un client\n5. Modifier ou ajouter un numero telephone pour un client\n6. Lorsque l’utilisateur quitte le programme, les données de la matrice sont enregistrées dans un fichier texte.");
       exo9();
       break;

      case 7: 
        return 0;
      default:
        break;
    }
  }
  return 0;
}
