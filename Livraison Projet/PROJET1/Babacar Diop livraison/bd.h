#ifndef bd
#define bd
    void vider();
    void enonce(char* eno);
    int numero_valide(char *num);
    void copie_chaine(char *source, char *destination);
    int longueur_sans_espaces(char *s);
    int contient_caracteres_speciaux(char *s);
    int ponctuation(char *Diop);
    int Supp_ESpaces(char *Diop);
    int est_espace(char c);
    int decaler_gauche(char *Diop);
    int longueur_chaine(char *Diop);
    void demanderInformationEtudiant(char *nom, char *prenom, char *telephone, char *classe, float *noteDevoir, float *noteProjet, float *noteExamen);
    float calculerMoyenne(float noteDevoir, float noteProjet, float noteExamen);
    void afficherTableau(char *nom, char *prenom, char *telephone, char *classe, float moyenne);
    void exo4();
    void exo5();
    int exo6();
    int exo7();
    int exo8();
    int exo9();
#endif
    