#include "etudiant_pc.h"
/////// initialiser les éléments de struct PC
void getDataPc(int nb){
	
	PC* p = malloc(nb*sizeof(PC));
	
	printf("\nRemplisser les informations sur les %d PC\n",nb);
	for (int i = 0; i <nb ; ++i){
		printf("\n[ %d ] :\n\nAdresse Mac : ",i+1);	scanf("%s",p[i].mac);
		printf("Étiquette : ");						scanf("%s",p[i].label);
		printf("Marque : ");						scanf("%s",p[i].marque);
	}

	FILE* file = fopen("pc.txt","a");
	if(file == NULL){
		fprintf(stderr,"Erreur d'accés de fichier\n");
	}
	for (int i = 0; i <nb ; ++i){
		fprintf(file,"%s;%s;%s\n",p[i].mac,p[i].label,p[i].marque);
	}
	fclose(file);
}
/////// initialiser les éléments de struct Étudiants
void getDataEtu(int nb){
	Etudiant* e = malloc(nb*sizeof(Etudiant));
	
	printf("\nRemplisser les informations sur les %d étudiant(s)\n",nb);
	for (int i = 0; i <nb ; ++i){
		getchar();
		printf("\n[ %d ] :\n\nNom : ",i+1);	scanf("%[^\n]",e[i].nom);		getchar();
		printf("Prénoms : ");				scanf("%[^\n]",e[i].prenom);	getchar();
		printf("Age : ");					scanf("%d",&e[i].age);
		printf("Sexe : ");					scanf("%s",e[i].sexe);
		printf("Mail : ");					scanf("%s",e[i].mail);
		printf("URL-GIT : ");				scanf("%s",e[i].url);
	}
	
	FILE* file = fopen("etudiant.txt","a");
	if(file == NULL){
		fprintf(stderr,"Erreur d'accés de fichier\n");
	}
	for (int i = 0; i <nb ; ++i){
		fprintf(file,"%s;%s;%d;%s;%s;%s\n",e[i].nom,e[i].prenom,e[i].age,e[i].sexe,e[i].mail,e[i].url);
	}
	fclose(file);
}
/////// compter les lignes du fichier pc.txt
int countLinePc(){
	int l=0;
	char c;
	FILE* file = fopen("pc.txt","r");
	if(file == NULL){
		fprintf(stderr,"Erreur d'accés de fichier\n");
	}
	while((c = fgetc(file)) != EOF){
		if(c == '\n'){
			l++;
		}
	}
	fclose(file);
	return l;
}
/////// compter les lignes du fichier etudiant.txt
int countLineEtu(){
	int l=0;
	char c;
	FILE* file = fopen("etudiant.txt","r");
	if(file == NULL){
		fprintf(stderr,"Erreur d'accés de fichier\n");
	}
	while((c = fgetc(file)) != EOF){
		if(c == '\n'){
			l++;
		}
	}
	return l;
}
/////// trier les PC
PC* triePc(PC* p, int nb){
	char tmp[60];
	for (int i = 0; i < nb; ++i){
		for (int j = i+1; j < nb; ++j){
			if (strcmp(p[i].label,p[j].label) > 0){
				strcpy(tmp,p[i].label);
				strcpy(p[i].label,p[j].label);
				strcpy(p[j].label,tmp);

				strcpy(tmp,p[i].mac);
				strcpy(p[i].mac,p[j].mac);
				strcpy(p[j].mac,tmp);

				strcpy(tmp,p[i].marque);
				strcpy(p[i].marque,p[j].marque);
				strcpy(p[j].marque,tmp);
			}
		}
	}
	return p;
}
/////// trier les Étudiants
Etudiant* trieEtu(Etudiant* e, int nb){
	char tmp[100];
	int a;
	for (int i = 0; i < nb; ++i){
		for (int j = i+1; j < nb; ++j){
			if (strcmp(e[i].nom,e[j].nom) > 0){
				strcpy(tmp,e[i].nom);
				strcpy(e[i].nom,e[j].nom);
				strcpy(e[j].nom,tmp);

				strcpy(tmp,e[i].prenom);
				strcpy(e[i].prenom,e[j].prenom);
				strcpy(e[j].prenom,tmp);
				
				a = e[i].age;
				e[i].age = e[j].age;
				e[j].age = a;

				strcpy(tmp,e[i].sexe);
				strcpy(e[i].sexe,e[j].sexe);
				strcpy(e[j].sexe,tmp);
				
				strcpy(tmp,e[i].mail);
				strcpy(e[i].mail,e[j].mail);
				strcpy(e[j].mail,tmp);
				
				strcpy(tmp,e[i].url);
				strcpy(e[i].url,e[j].url);
				strcpy(e[j].url,tmp);
			}
			else if (strcmp(e[i].nom,e[j].nom) == 0){
				if(strcmp(e[i].nom,e[j].nom) > 0){
					strcpy(tmp,e[i].nom);
					strcpy(e[i].nom,e[j].nom);
					strcpy(e[j].nom,tmp);

					strcpy(tmp,e[i].prenom);
					strcpy(e[i].prenom,e[j].prenom);
					strcpy(e[j].prenom,tmp);
					
					a = e[i].age;
					e[i].age = e[j].age;
					e[j].age = a;

					strcpy(tmp,e[i].sexe);
					strcpy(e[i].sexe,e[j].sexe);
					strcpy(e[j].sexe,tmp);
					
					strcpy(tmp,e[i].mail);
					strcpy(e[i].mail,e[j].mail);
					strcpy(e[j].mail,tmp);
					
					strcpy(tmp,e[i].url);
					strcpy(e[i].url,e[j].url);
					strcpy(e[j].url,tmp);
				}
			}
		}
	}
	return e;
}
/////// transferer données dans un pc.csv
void transferPc(){
	int nb=0;
	nb = countLinePc();
	
	PC* p = malloc(nb*sizeof(PC));
	
	FILE* file = fopen("pc.txt","r");
	if(file == NULL){
		fprintf(stderr,"Erreur d'accés de fichier\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0; i<nb; i++){
		fscanf(file,"%[^;];%[^;];%s\n",p[i].mac,p[i].label,p[i].marque);
	}
	fclose(file);
	
	p = triePc(p,nb);
	
	FILE* file1 = fopen("pc.csv","w");
	if(file1 == NULL){
		fprintf(stderr,"Erreur d'accés de fichier\n");
	}
	
	fprintf(file,"MAC,ETIQUETTE,MARQUE\n");
	for(int i=0; i<nb; i++){
		fprintf(file1,"%s,%s,%s\n",p[i].mac,p[i].label,p[i].marque);
	}
	fclose(file1);
}
/////// transferer données des étudiants 
void transferEtu(){
	int nb=0;
	nb = countLineEtu();
	
	Etudiant* e = malloc(nb*sizeof(Etudiant));
	
	FILE* file = fopen("etudiant.txt","r");
	if(file == NULL){
		fprintf(stderr,"Erreur d'accés de fichier\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0; i<nb; i++){
		fscanf(file,"%[^;];%[^;];%d;%[^;];%[^;];%s\n",e[i].nom,e[i].prenom,&e[i].age,e[i].sexe,e[i].mail,e[i].url);
	}
	fclose(file);
	
	e = trieEtu(e,nb);
	
	FILE* file1 = fopen("etudiant.csv","w");
	if(file1 == NULL){
		fprintf(stderr,"Erreur d'accés de fichier\n");
	}
	
	fprintf(file,"NOM,PRÉNOM,AGE,SEXE,MAIL,URL-GIT\n");
	for(int i=0; i<nb; i++){
		fprintf(file1,"%s,%s,%d,%s,%s,%s\n",e[i].nom,e[i].prenom,e[i].age,e[i].sexe,e[i].mail,e[i].url);
	}
	fclose(file1);	
}
/////// afficher les elements du struct PC
void displayPc(PC* p, int nb){
	printf("\nLes informations sur les %d PC\n",nb);
	for (int i = 0; i <nb ; ++i){
		printf("\n[ %d ] :\n\nAdresse Mac : %s\nÉtiquette : %s\nMarque : %s\n",i+1,p[i].mac,p[i].label,p[i].marque);
	}
}
/////// afficher les elements du struct Étudiant
void displayEtu(Etudiant* e, int nb){
	printf("\nLes informations sur les %d étudiant(s)\n",nb);
	for (int i = 0; i <nb ; ++i){
		printf("\n[ %d ] :\n\nNom : %s\nPrénoms : %s\nAge : %d\nSexe : %s\nMail : %s\nURL-GIT : %s\n",i+1,e[i].nom,e[i].prenom,e[i].age,e[i].sexe,e[i].mail,e[i].url);
	}
}
