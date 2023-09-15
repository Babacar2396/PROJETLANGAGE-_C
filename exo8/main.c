#include"index.h"


 
int main()
{
  printf("%d",isNote("09;3760" ));
    char c;
     Menu choix;
    do
    {       
      choix = menu();
    switch (choix)
    {
    case AJOUT:
          printf("*****AJOUTER UN ETUDIANT*******\n");   
          afficheEtudiant(saisieEtudiant()) ;

        break;
    case AFFICHER:
          printf("*****AFFICHER UN ETUDIANT*******");           
        break;
    case MODIFIER:
          printf("*****MODIFIER UN ETUDIANT*******\n");           
       break;
    case RECHERCHER:
        //  printf("*****MODIFIER UN ETUDIANT*******");           
        break;
    case TRIE:
         // printf("*****MODIFIER UN ETUDIANT*******");           
        break;
    case AFFICHERPAGINATION:
          //printf("*****MODIFIER UN ETUDIANT*******");           
        break;
    case QUITTER: 
           printf("QUITTEZ");                 
    break;
    default:
           printf("erreur"); 
        break;
    }
    } while ( choix != 7);
    return 0;
}

