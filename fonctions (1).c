#include <stdio.h>
#include "fonctions.h"

void repeter_caractere(char c, int nfois)
{
    for (int i = 0; i < nfois; i ++)
        printf("%c", c);
}

double transformer(char *ch)
{
    double n;
    remplacer(ch, ';', '.');
    if (sscanf(ch, "%lf", &n))
        return n;
    return 0.;
}

int est_espace(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int decaler_gauche(char *str)
{
    int i, len = longueur_chaine(str)-1;
    for (i = 0; i < len; i ++)
        str[i] = str[i+1];
    str[len] = '\0';
    return len;
}

int del_spaces(char *str)
{
    int i, j, len = longueur_chaine(str);

    while (est_espace(str[0]))
        len = decaler_gauche(str);

    for (i = 1; i < len; i ++)
        if (est_espace(str[i]))
            while (est_espace(str[i+1]))
                len = decaler_gauche(str+i+1) + i + 1;

    if (est_espace(str[longueur_chaine(str)-1]))
        str[--len] = '\0';

    return len;
}

int longueur_sans_espaces(char *str)
{
    int i, len;
    for (i = 0, len = 0; str[i] != '\0'; i ++)
        if (! est_espace(str[i]))
            len ++;
    return len;
}

int copie_chaine(char *src, char *dest)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i ++;
    }
    dest[i] = '\0';
    return i;
}

int numero_valide(char *str)
{
    int l = del_spaces(str);
    if (str[0] != '7' ||
        (str[1] != '0' && str[1] != '5'
        && str[1] != '6' && str[1] != '7'
        && str[1] != '8' ))
        return 0;

    for (int i = 0; i < l; i ++)
        if (str[i] != ' ' && (str[i] < '0' || str[i] > '9'))
            return 0;
    
    if (longueur_sans_espaces(str) != 9)
        return 0;

    return 1;
}

void vider()
{
    while (getchar() != '\n');
    
}

int longueur_chaine(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i ++);
    return i;
}

int nom_valide(char *s)
{
    int i, l = longueur_chaine(s);
    for (i = 0; i < l; i ++)
        if ( (s[i] < 'A' || s[i] > 'Z') &&
             (s[i] < 'a' || s[i] > 'z') &&
             (s[i] < '0' || s[i] > '9') &&
             s[i] != '-' && s[i] != ' ' )
            return 0;
    return 1;
}

void etd_en_chaine(struct etudiant e[E_MAX], char chaine[][L_MAX], int n)
{
    for (int i = 0; i < n; i ++)
    {
        sprintf(chaine[i*N_CHAMPS], "%s", e[i].prenom);
        sprintf(chaine[i*N_CHAMPS+1], "%s", e[i].nom);
        sprintf(chaine[i*N_CHAMPS+2], "%s", e[i].numero_tel);
        sprintf(chaine[i*N_CHAMPS+3], "%s", e[i].classe);
        sprintf(chaine[i*N_CHAMPS+4], "%d", e[i].note_devoir);
        sprintf(chaine[i*N_CHAMPS+5], "%d", e[i].note_exam);
        sprintf(chaine[i*N_CHAMPS+6], "%d", e[i].note_projet);
        sprintf(chaine[i*N_CHAMPS+7], "%s", e[i].moyenne);
    }
}

void tab_etd(char donnees[][L_MAX], char en_tete[N_CHAMPS][L_MAX],
    int n, int *affich, int ex)
{
    int i, j, k, tw, tmp, largeur_col[N_CHAMPS];
    char l = '-', c = '|';

    tw = 3*N_CHAMPS-1;

    for (i = 0; i < N_CHAMPS; i ++)
    {
        if (! affich)
        {
            for (j = 0, tmp = longueur_chaine(en_tete[i]); j < n; j ++)
                if (tmp < longueur_chaine(donnees[j*N_CHAMPS+i]))
                    tmp = longueur_chaine(donnees[j*N_CHAMPS+i]);
            largeur_col[i] = tmp;
            tw += tmp;
        }
        else
        {
            for (j = 0, tmp = longueur_chaine(en_tete[i]); j < n; j ++)
                for (int m = 0; m < ex; m ++)
                    if (affich[m] == j)
                        if (tmp < longueur_chaine(donnees[j*N_CHAMPS+i]))
                            tmp = longueur_chaine(donnees[j*N_CHAMPS+i]);
            largeur_col[i] = tmp;
            tw += tmp;
        }
    }

    printf(" ");
    repeter_caractere(l, tw);
    printf("\n");

    for (i = -1; i < n; i++)
    {
        for (j = 0; j < N_CHAMPS; j++)
        {
            if ( i == -1 )
            {
                tmp = (largeur_col[j] - longueur_chaine(en_tete[j])) / 2;
                printf("%c", c);
                repeter_caractere(' ', tmp+1);
                printf("%s", en_tete[j]);

                if (largeur_col[j] > longueur_chaine(en_tete[j]))
                    repeter_caractere(' ',
                    largeur_col[j] - longueur_chaine(en_tete[j]) - tmp);

                printf(" ");
                continue;
            }

            for (k = 0, tmp = 0; k < ex; k ++)
                if (i == affich[k])
                {
                    tmp = 1;
                    break;
                }
            if ( ! tmp && affich )
                continue;

            tmp = (largeur_col[j] - longueur_chaine(donnees[i*N_CHAMPS+j])) / 2;
            printf("%c", c);
            repeter_caractere(' ', tmp+1);
            printf("%s", donnees[i*N_CHAMPS+j]);

            if (largeur_col[j] > longueur_chaine(donnees[i*N_CHAMPS+j]))
                repeter_caractere(' ',
                largeur_col[j] - longueur_chaine(donnees[i*N_CHAMPS+j]) - tmp);
            printf(" ");
        }
        if ( tmp || i == -1 )
            printf("%c\n", c);

        if ( i == -1 ) {
            printf(" ");
            repeter_caractere(l, tw);
            printf("\n");
        }
    }

    printf(" ");
    repeter_caractere(l, tw);
    printf("\n");
}

int comparer(char *s1, char *s2)
{
    int l1 = longueur_chaine(s1),
    l2 = longueur_chaine(s2), i;

    if (l1 != l2)
        return 0;

    for (i = 0; i < l1; i ++)
        if (s1[i] != s2[i])
            return 0;

    return 1;
}

int debute_par(char *s1, char *s2)
{
    int l = longueur_chaine(s2), i;
    for (i = 0; i < l; i ++)
        if (s1[i] != s2[i])
            return 0;
    return 1;
}

void prem_lettre(char *str)
{
    int i, l = longueur_chaine(str);
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    for (i = 1; i < l; i ++)
        if (str[i] >= 'a' && str[i] <= 'z' && est_espace(str[i-1]))
            str[i] -= 32;
}

int num_existe(char *num)
{
    struct etudiant ets[E_MAX];
    int i, n = lire_etd(ets);

    for (i = 0; i < n; i ++)
    {
        enlever_spc(num);
        enlever_spc(ets[i].numero_tel);
        if (comparer(num, ets[i].numero_tel))
            return 1;
    }

    return 0;
}

void saisir_etudiant(struct etudiant *e)
{
    int r, i;
    double d;

    do {
        printf("Donnez le prenom de l'etudiant : ");
        scanf("%[^\n]", e->prenom);
        del_spaces(e->prenom);
        prem_lettre(e->prenom);
        vider();
    } while ( ! nom_valide(e->prenom) &&
    printf("Le prenom que vous avez donne est incorrect!\n"));

    do {
        printf("Donnez le nom de l'etudiant : ");
        scanf("%[^\n]", e->nom);
        del_spaces(e->nom);
        prem_lettre(e->nom);
        vider();
    } while ( ! nom_valide(e->nom) &&
    printf("Le nom que vous avez donne est incorrect!\n"));

    do {
        printf("Donnez le numero de telephone : ");
        scanf("%[^\n]", e->numero_tel);
        vider();
        enlever_spc(e->numero_tel);

        if (num_existe(e->numero_tel))
        {
            printf(" Ce numero appartient a un autre etudiant!\n");
            continue;
        }
    } while ( ! numero_valide(e->numero_tel) &&
    printf("Le numero est incorrect!\n"));

    do {
        printf("Donnez la classe de l'etudiant : ");
        scanf("%[^\n]", e->classe);
        del_spaces(e->classe);
        vider();
    } while( ! nom_valide(e->classe) &&
    printf("Le nom de la classe est incorrect!\n"));

    do {
        printf("Donnez la note de devoir : ");
        scanf("%[^\n]", &e->note_devoir);
        vider();
        d = remplacer(e->note_devoir);
    } while ((! d || d < 0. || d > 20.) &&
    printf(" La note est invalide!\n"));

    do {
        printf("Donnez la note d'examen : ");
        scanf("%[^\n]", &e->note_exam);
        vider();
        d = remplacer(e->note_exam);
    } while ((! d || d < 0. || d > 20.) &&
    printf(" La note est invalide!\n"));

    do {
        printf("Donnez la note de projet : ");
        r = scanf("%[^\n]", &e->note_projet);
        vider();
        d = remplacer(e->note_projet);
    } while ((! d || d < 0. || d > 20.) &&
    printf(" La note est invalide!\n"));

    d = ( remplacer(e->note_devoir) +
        remplacer(e->note_exam) +
        remplacer(e->note_projet) ) / 3.;

    sprintf(e->moyenne, "%.2f", d);
    remplacer(e->moyenne, '.', ';');
}

int n_saisies(struct etudiant *ets)
{
    int i, cont = 1, r;
    for (i = 0; cont; i ++)
    {
        saisir_etudiant(&ets[i]);
        printf("La moyenne de cet etudiant est : %s", ets[i].moyenne);

        do {
            printf("\n\t1. Continuer\n\t2. Arreter\n Voulez-vous continuer : ");
            r = scanf("%d", &cont);
            vider();
        } while ( ! r || cont < 1 || cont > 2);

        cont = cont == 2 ? 0 : cont;
    }

    return i;
}

int remplacer(char *str, char c, char n)
{
    int l = longueur_chaine(str);
    for (int i = 0; i < l; i ++)
        if (str[i] == c)
        {
            str[i] = n;
            return i;
        }
    return -1;
}

int chaine_copie(char *s1, char *s2)
{
    int i, l = longueur_chaine(s2);
    for (i = 0; i < l && s2[i] != '\n'; i ++)
        s1[i] = s2[i];
    s1[i] = '\0';
    return i;
}

void ajouter_etd_fichier(struct etudiant e)
{
    FILE *fichier = fopen(NOM_FICHIER_ETD, "a");

    fprintf(fichier, "prenom:%s\n", e.prenom);
    fprintf(fichier, "nom:%s\n", e.nom);
    fprintf(fichier, "numero_tel:%s\n", e.numero_tel);
    fprintf(fichier, "classe:%s\n", e.classe);
    fprintf(fichier, "note_devoir:%d\n", e.note_devoir);
    fprintf(fichier, "note_exam:%d\n", e.note_exam);
    fprintf(fichier, "note_projet:%d\n", e.note_projet);
    fprintf(fichier, "moyenne:%s\n", e.moyenne);

    fputs("\n", fichier);
    fclose(fichier);
}

int lire_etd(struct etudiant ets[E_MAX])
{
    FILE *f = fopen(NOM_FICHIER_ETD, "r");
    char ligne[L_MAX];
    int i = 0, r = 0;

    while (fgets(ligne, L_MAX-1, f) != NULL)
    {
        if (debute_par(ligne, "prenom:")) // prenom:
        {
            chaine_copie(ets[i].prenom, ligne+7);
            r ++;
        }

        else if (debute_par(ligne, "nom:")) // nom:
        {
            chaine_copie(ets[i].nom, ligne+4);
            r ++;
        }

        else if (debute_par(ligne, "numero_tel:")) // numero_tel:
        {
            chaine_copie(ets[i].numero_tel, ligne+11);
            r ++;
        }

        else if (debute_par(ligne, "classe:")) // classe:
        {
            chaine_copie(ets[i].classe, ligne+7);
            r ++;
        }

        else if (debute_par(ligne, "note_devoir:")) // note_devoir:
        {
            sscanf(ligne+12, "%d", &ets[i].note_devoir);
            r ++;
        }

        else if (debute_par(ligne, "note_exam:")) // note_exam:
        {
            sscanf(ligne+10, "%d", &ets[i].note_exam);
            r ++;
        }

        else if (debute_par(ligne, "note_projet:")) // note_projet:
        {
            sscanf(ligne+12, "%d", &ets[i].note_projet);
            r ++;
        }

        else if (debute_par(ligne, "moyenne:")) // moyenne:
        {
            chaine_copie(ets[i].moyenne, ligne+8);
            r ++;
        }

        if (r == 8)
        {
            i ++;
            r = 0;
        }
    }

    fclose(f);
    return i;
}

void effacer()
{
    printf("\e[1;1H\e[2J");
}

int fetd()
{
    FILE * f = fopen(NOM_FICHIER_ETD, "r");
    if (f == NULL)
        return 0;
    if (getc(f) == EOF)
        return 0;

    fclose(f);
    return 1;
}

void echanger_etd(struct etudiant *e1, struct etudiant *e2)
{
    struct etudiant e;

    copie_chaine(e1->prenom, e.prenom);
    copie_chaine(e1->nom, e.nom);
    copie_chaine(e1->classe, e.classe);
    copie_chaine(e1->numero_tel, e.numero_tel);
    e.note_devoir = e1->note_devoir;
    e.note_exam = e1->note_exam;
    e.note_projet = e1->note_projet;
    copie_chaine(e1->moyenne, e.moyenne);

    copie_chaine(e2->prenom, e1->prenom);
    copie_chaine(e2->nom, e1->nom);
    copie_chaine(e2->classe, e1->classe);
    copie_chaine(e2->numero_tel, e1->numero_tel);
    e1->note_devoir = e2->note_devoir;
    e1->note_exam = e2->note_exam;
    e1->note_projet = e2->note_projet;
    copie_chaine(e2->moyenne, e1->moyenne);

    copie_chaine(e.prenom, e2->prenom);
    copie_chaine(e.nom, e2->nom);
    copie_chaine(e.classe, e2->classe);
    copie_chaine(e.numero_tel, e2->numero_tel);
    e2->note_devoir = e.note_devoir;
    e2->note_exam = e.note_exam;
    e2->note_projet = e.note_projet;
    copie_chaine(e.moyenne, e2->moyenne);
}

void trier_etd(struct etudiant *e, int n)
{
    int i, j;
    double max, t;

    for (i = 0; i < n-1; i ++)
    {
        remplacer(e[i].moyenne, ';', '.');
        sscanf(e[i].moyenne, "%lf", &max);

        for (j = i+1; j < n; j ++)
        {
            remplacer(e[j].moyenne, ';', '.');
            sscanf(e[j].moyenne, "%lf", &t);

            if (max < t)
            {
                echanger_etd(&e[i], &e[j]);
                remplacer(e[i].moyenne, ';', '.');
                sscanf(e[i].moyenne, "%lf", &max);
            }
        }
    }

    for (i = 0; i < n; i ++)
        remplacer(e[i].moyenne, '.', ';');
}

int enlever_spc(char *s)
{
    int i, l = longueur_chaine(s), n;
    del_spaces(s);

    for (i = 0, n = 0; i < l-1; i ++)
        if (est_espace(s[i]))
        {
            del_spaces(s+i);
            n ++;
        }

    return n;
}

int chercher_etd(struct etudiant *e, int n, char *param, char *val,
    int *res)
{
    int i, j = 0;
    char s[L_MAX];

    for (i = 0; i < n; i ++)
    {
        if (comparer("nom", param))
        {
            if (comparer(e[i].nom, val))
            {
                res[j] = i;
                j ++;
            }
        }
        else if (comparer("prenom", param))
        {
            if (comparer(e[i].prenom, val))
            {
                res[j] = i;
                j ++;
            }
        }
        else if (comparer("classe", param))
        {
            if (comparer(e[i].classe, val))
            {
                res[j] = i;
                j ++;
            }
        }
        else if (comparer("numero_tel", param))
        {
            if (comparer(e[i].numero_tel, val))
            {
                res[j] = i;
                j ++;
            }
        }
    }

    return j;
}

int modifier_etd(char *num, char *param, char *val)
{
    struct etudiant ets[E_MAX];
    int n = lire_etd(ets), i, r, res[E_MAX], v;
    double moy;

    FILE *f = fopen(NOM_FICHIER_ETD, "w");
    fclose(f);

    r = chercher_etd(ets, n, "numero_tel", num, res);
    if (! r) return 0;

    for (i = 0; i < n; i ++)
    {
        if (i != res[0])
            ajouter_etd_fichier(ets[i]);
        else
        {
            if (comparer(param, "prenom"))
                copie_chaine(val, ets[i].prenom);
            else if (comparer(param, "nom"))
                copie_chaine(val, ets[i].nom);
            else if (comparer(param, "classe"))
                copie_chaine(val, ets[i].classe);
            else if (comparer(param, "numero_tel"))
            {
                enlever_spc(val);
                if ( ! num_existe(val) && numero_valide(val))
                    copie_chaine(val, ets[i].numero_tel);
            }
            else if (comparer(param, "note_devoir"))
                copie_chaine(val, ets[i].note_devoir);
            else if (comparer(param, "note_exam"))
                copie_chaine(val, ets[i].note_exam);
            else if (comparer(param, "note_projet"))
                copie_chaine(val, ets[i].note_projet);

            moy = ( remplacer(ets[i].note_projet) +
                remplacer(ets[i].note_exam) +
                remplacer(ets[i].note_devoir) ) / 3.;
            
            sprintf(val, "%.2f", moy);
            remplacer(val, '.', ';');
            copie_chaine(val, ets[i].moyenne);

            ajouter_etd_fichier(ets[i]);
        }
    }

    return 1;
}

void minuscule(char *s)
{
    int i, l = longueur_chaine(s);
    for (i = 0; i < l; i ++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
}

int menu8()
{
    int choix, r;
    printf(" Que souhaitez-vous faire ?\n\n\t\
1. Saisir des etudiants\n\t\
2. Afficher tous les etudiants\n\t\
3. Trier et afficher par ordre decroissant de la moyenne\n\t\
4. Rechercher selon un critere : NOM, PRENOM, CLASSE, NUMERO_TEL\n\t\
5. Modifier les notes d'un etudiant\n\t\
6. Sortir du programme\n");

    do {
        r = scanf("%d", &choix);
        vider();
    } while ( (! r || choix < 1 || choix > 6) &&
        printf("Ce choix n'existe pas!\n Reesayez : "));

    return choix;
}
