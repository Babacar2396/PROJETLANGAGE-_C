#include <stdio.h>
#include "fonctions.h"

int main(char *argv, int argc)
{
    struct etudiant ets[E_MAX];
    int n, choix, r, i, res[E_MAX];
    char donnees[L_MAX][L_MAX], en_tete[][L_MAX] = {
        "Prenom", "Nom", "Telephone", "Classe",
        "Dev", "Proj", "Exam", "Moyenne"
    }, continuer[4] = "oui";

    int indice;
    char param[L_MAX], val[L_MAX], num[L_MAX];

    do {
        effacer();
        choix = menu8();

        switch(choix)
        {
            case 1 :
                effacer();
                n = n_saisies(ets);
                for ( i = 0; i < n; i ++ )
                    ajouter_etd_fichier(ets[i]);
                printf("Les valeurs saisies ont ete enregistrees avec succes!\n");
                break;
            case 2:
                effacer();
                if (! fetd())
                    printf("Le fichier etudiant est vide!\n");
                else
                {
                    n = lire_etd(ets);
                    etd_en_chaine(ets, donnees, n);
                    tab_etd(donnees, en_tete, n, NULL, 0);
                }
                break;
            case 3 :
                effacer();
                if (! fetd())
                    printf("Le fichier etudiant est vide!\n");
                else
                {
                    n = lire_etd(ets);
                    trier_etd(ets, n);
                    etd_en_chaine(ets, donnees, n);
                    tab_etd(donnees, en_tete, n, NULL, 0);
                }
                break;
            case 4 :
                effacer();
                if (! fetd())
                    printf("Le fichier etudiant est vide!\n");
                else
                {
                    n = lire_etd(ets);
                    printf("\t NOM\n\t PRENOM\n\t CLASSE\n\t NUMERO_TEL\n\
Donnez le critere de recherche : ");
                    do {
                        scanf("%[^\n]", param);
                        vider();
                        minuscule(param);
                        del_spaces(param);
                    } while( !comparer(param, "nom") &&
                    !comparer(param, "prenom") &&
                    !comparer(param, "classe") &&
                    !comparer(param, "numero_tel") &&
                    printf("Invalide!\n Reesayez : "));

                    printf("Donnez le motif a rechercher : ");
                    scanf("%s", val);
                    vider();
                    if (comparer("numero_tel", param))
                        enlever_spc(val);
                    else
                        del_spaces(val);

                    indice = chercher_etd(ets, n, param, val, res);
                    if ( ! indice)
                        printf(" Aucun resultat trouve!\n");
                    else
                    {
                        effacer();
                        etd_en_chaine(ets, donnees, n);
                        printf("%d resultats trouves!\n", indice);
                        tab_etd(donnees, en_tete, n, res, indice);
                    }
                }
                break;
            case 5 :
                effacer();
                if (! fetd())
                    printf("Le fichier etudiant est vide!\n");
                else
                {
                    n = lire_etd(ets);
                    printf("Donner le numero de l'etudiant a modifier\n ");
                    do {
                        scanf("%[^\n]", num);
                        vider();
                        minuscule(num);
                        enlever_spc(num);
                        if (! numero_valide(num))
                        {
                            printf("Ce numero n'est pas valide!\n ");
                            continue;
                        }
                        if (! num_existe(num))
                        {
                            printf("Aucun etudiant ne possede ce numero!\n Reesayez : ");
                            continue;
                        }
                        break;
                    } while (1);

                    printf("Donner la note a modifier\n\
\t NOTE_DEVOIR\n\t NOTE_EXAM\n\t NOTE_PROJET\n ");
                    do {
                        scanf("%[^\n]", param);
                        vider();
                        del_spaces(param);
                        minuscule(param);
                        if (! comparer(param, "note_devoir") &&
                            ! comparer(param, "note_exam") &&
                            ! comparer(param, "note_projet"))
                        {
                            printf("Invalide!\n Reesayez : ");
                            continue;
                        }
                        break;
                    } while (1);

                    printf("Donnez la nouvelle valeur : ");
                    scanf("%[^\n]", val);
                    vider();
                    del_spaces(val);

                    indice = modifier_etd(num, param, val);
                    if ( ! indice)
                        printf("\n La modification ne s'est pas passe correctement,\
 car le numero donne\nne correspond a aucun etudiant dans le fichier!\n\n");
                    else
                        printf("\n Modification effectuee avec succes!\n\n");
                }
                break;
            case 6 :
                goto fin;
                break;
        }

        do {
            printf("\nSouhaitez-vous reafficher le menu (oui ou non) : ");
            scanf("%s", continuer);
            minuscule(continuer);
            vider();
        } while ( (! comparer("oui", continuer) && ! comparer("non", continuer))
        && printf(" Invalide!\n"));
    } while (comparer("oui", continuer));
fin:
    printf("\n Au revoir a bientot!\n\n");

    return 0;
}
