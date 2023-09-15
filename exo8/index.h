#include<stdio.h>
#define TAILLE 100
#define VIDER vider()
#define SEPARATEUR_REEL ';'
 enum Menu {AJOUT= 1, AFFICHER, MODIFIER, RECHERCHER, TRIE, AFFICHERPAGINATION, QUITTER};
typedef enum Menu Menu;

enum Booleen {FALSE, TRUE};
typedef enum Booleen Booleen ;

typedef struct
{
    char prenom[TAILLE];
    char nom[TAILLE];
    char classe[TAILLE];
    char telephone[TAILLE];
    char devoir[TAILLE];
    char projet[TAILLE];
    char examen[TAILLE];
    char moyenne[TAILLE];

}Etudiant;
//declaration de fonction
int menu(void);
Etudiant saisieEtudiant (void);
void afficheEtudiant(Etudiant);
void vider();
Booleen isTelephone(char[]);
Booleen isNote(char[]);
int tailleChaine (char []);
Booleen isChiffre (char );
int findChar(char [],char );