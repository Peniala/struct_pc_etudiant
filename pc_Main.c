#include "etudiant_pc.h"
int main(){
	int nb1=0;
	printf("Combien de PC voulez-vous enregistrer : ");
	scanf("%d",&nb1);
	getDataPc(nb1);
	transferPc();
	
	return 0;
}
