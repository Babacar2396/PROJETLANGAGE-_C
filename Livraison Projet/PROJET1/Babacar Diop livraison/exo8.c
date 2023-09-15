#include "bd.h"
#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define FICHIER "fichier.txt"

struct Student {
  char nom[MAX_NAME_LENGTH];
  char telephone[MAX_NAME_LENGTH];
  char classe[MAX_NAME_LENGTH];
  float Devoir;
  float project;
  float examen;
  float moyenne;
};

int exo8()
{



// Prototypes des fonctions
void AfficherEtudiant(const struct Student *student);
void AfficherEtudiants(const struct Student students[], int count);
void TrierEtudiantsParMoyenne(struct Student students[], int count);
int  RechercherEtudiant (const struct Student students[], int count, const char *criterion, const char *value);
int  ModifierEtudiant(struct Student students[], int count, const char *phone);
void SaveStudentsToFile(const struct Student students[], int count, const char *filename);


void demanderInformationEtudiant(char *nom, char *prenom, char *telephone, char *classe, float *noteDevoir, float *noteProjet, float *noteExamen) {
  printf("Entrez le Nom de l'étudiant: ");
  scanf("%s", nom);
  printf("Entrez le Prénom de l'étudiant: ");
  scanf("%s", prenom);
  printf("Entrez le Téléphone de l'étudiant: ");
  scanf("%s", telephone);
  printf("Entrez la Classe de l'étudiant: ");
  scanf("%s", classe);
  printf("Entrez la note de devoir de l'étudiant: ");
  scanf("%f", noteDevoir);
  printf("Entrez la note de Projet de l'étudiant: ");
  scanf("%f", noteProjet);
  printf("Entrez la note D'examen de l'étudiant: ");
  scanf("%f", noteExamen);
}

float calculerMoyenne(float noteDevoir, float noteProjet, float noteExamen) {
  return (noteDevoir + noteProjet + noteExamen) / 3;
}

void afficherTableau(char *nom, char *prenom, char *telephone, char *classe, float moyenne) {
  printf("+--------------+----------------+----------------+----------------+------------------------+\n");
  printf("| %-12s | %-14s | %-14s | %-14s | %-14s |\n", "Nom", "Prénom", "Téléphone", "Classe", "Moyenne");
  printf("+--------------+----------------+----------------+----------------+------------------------+\n");
  printf("| %-12s | %-14s | %-14s | %-14s | %-14.2f |\n", nom, prenom, telephone, classe, moyenne);
  printf("+--------------+----------------+----------------+----------------+------------------------+\n");
}

}
