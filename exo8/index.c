#include<stdio.h>
#include"index.h"





int menu(){
    int choix = 0;

    printf("============MENU==============\n");
    printf("1-AJOUTER UN ETUDIANT\n"); 
    printf("2-AFFICHER ETUDIANT\n"); 
    printf("3-MODIFIER ETUDIANT\n"); 
    printf("4-RECHERCHER\n"); 
    printf("5-Trier\n");
    printf("6-Afficher Pagination\n"); 
    printf("7-Quitter\n");

    printf("veillez faire un choix"); 
    scanf("%d", &choix); 
    
    return choix;
}
Etudiant saisieEtudiant()
{

    Etudiant etudiant;
    VIDER;
    printf("Entrer le prenom l'etudiant\n");
    scanf("%[^\n]",etudiant.prenom);
    printf("Entrer le nom de l'etudiant\n");
    scanf("%s",etudiant.nom);
    
    do
    {
    VIDER;
    printf("Entrer le numéro de telephone\n");
    scanf("%[^\n]",etudiant.telephone);
    
    } while (!isTelephone(etudiant.telephone));
    
    printf("Entrer la classe de l'etudiant\n");
    scanf("%s",etudiant.classe);
    do{
        printf("Entrer la note de devoir\n");
        scanf("%s",etudiant.devoir);

    }while(!isNote(etudiant.devoir));
    do{
         printf("Entrer la note de projet\n");
         scanf("%s",etudiant.projet);

    }while (!isNote(etudiant.projet));

    do{
    printf("Entrer la note d'examen\n");
    scanf("%s",etudiant.examen);

    }while(!isNote(etudiant.examen));
    
    
   
    
    return etudiant;

}
void afficheEtudiant(Etudiant etudiant)
{
     printf("PRENOM :%s\n",etudiant.prenom);
     printf("NOM :%s\n",etudiant.nom);
     printf("TELEPHONE :%s\n",etudiant.telephone);
     printf("CLASSE :%s\n",etudiant.classe);
     printf("DEVOIR :%s\n",etudiant.devoir);
     printf("PROJET :%s\n",etudiant.projet);
     printf("EXAM : %s\n",etudiant.examen);
}  
void vider()
{
    char c;
    scanf("%c",&c);
}


Booleen isChiffre(char numero)
{
    return numero >= '0' && numero <= '9';
}
int tailleChaine(char chaine[100])
{
    int i ;
    for(i=0; chaine[i]!= '\0' ; i++);
    return i ;

}

Booleen isTelephone(char tel[])
{
    int len = tailleChaine(tel);
    int i;
    if (len!= 9 && len != 12) return FALSE;
    if (tel[0]!= '7') return FALSE;
    if (tel[1]!= '5' && tel[1]!= '6' && tel[1]!= '7' && tel[1]!= '8' && tel[1]!= '0') return FALSE; 
    if (len == 12 && tel[2] != ' '&& tel[6] != ' '&&tel[9] != ' ') return FALSE;
    int cpt =0;
    
    for ( i = 0; i < len; i++) cpt += isChiffre(tel[i]);

    return cpt == 9;
}
Booleen isNote(char nombre[]){
  int  len=tailleChaine (nombre);
  int poseSep=findChar(nombre,SEPARATEUR_REEL);
  for (int i = 0; i <len ; i++)
  {
    if (poseSep!=i && !isChiffre(nombre[i]) )
    {
    return FALSE;
    }
    
  }
  if(poseSep!=-1 && poseSep!=1 && poseSep!=2 || len-3!=poseSep ) return FALSE;
  if(poseSep==1) return TRUE;
  if(nombre[0]>'2' ||(nombre[0]=='2'&& nombre[1]!='0')) return FALSE;
  return TRUE;
}



/*int findChar(char chaine[],char car){
    int len=tailleChaine(chaine);
    for ( int i = 0; i < len; i++)
    {
    if (chaine[i]==car)
    return i;
    
}
return -1;
}*/
int findChar(char chaine[],char car){
int i;
for( i=0;chaine[i]!=car && chaine[i]!='\0';i++); return chaine[i]=='\0'? -1:i ;

}
