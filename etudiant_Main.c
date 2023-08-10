#include "etudiant_pc.h"
int main(){
	int nb2=0;	
	printf("\n\nCombien d' étudiants voulez-vous enregistrer : ");
	scanf("%d",&nb2);
	getDataEtu(nb2);
	transferEtu();
	
	return 0;
}

