#ifndef ETU_PC
#define ETU_PC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
static int nb_pc = 0;
static int nb_etu = 0;
*/
//////// definition de struct PC
typedef struct{
	char mac[50];
	char label[50];
	char marque[50];
}PC;
//////// definition de struct Étudiant
typedef struct{
	char nom[50];
	char prenom[50];
	int age;
	char sexe[20];
	char mail[60];
	char url[100];
}Etudiant;
/////// Prototype
void getDataPc(int nb);
void getDataEtu(int nb);
int countLinePc();
int countLineEtu();
PC* triePc(PC* p, int nb);
Etudiant* trieEtu(Etudiant* e, int nb);
void transferPc();
void transferEtu();
void displayPc(PC* p, int nb);
void displayEtu(Etudiant* e, int nb);
#endif
