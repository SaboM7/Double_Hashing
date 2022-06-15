#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funkcije.h"

void main(){
    printf("\n**********DVOSTRUKO HESIRANJE**********\n");
    int vel_tabele=0;
    int Np=0;
    int As=0;
    int Ns=0;
    int izbor=0;

    //inicijalizacija i popuna tabele
    vel_tabele = prihvati_unos("\nUpisite velicinu tabele: ");
    int tabela[vel_tabele];
    popuna_tabele(tabela, vel_tabele,-1);

    //inicijalizacije primarne funkcije
    printf("\nPrimarna hes funkcija je oblika h(K)= K mod Np . \nNp je velicina tabele.\n");
    Np= vel_tabele;

    //inicijalizacije sekundarne funkcije
    printf("\nSekundarna hes funkcija je oblika g(K)= As + K mod Ns .\n");
    As = prihvati_unos("Upisite vrednost konstante As: ");
    Ns = prihvati_unos("Upisite vrednost konstante Ns: ");

    do{
	printf("\n**********MENI**********\n0: Izlaz \n1: Hesiraj \n2: Ispisi tabelu \n3: Proveri da li vec postoji vrednost u tabeli \n4: Izbrisi vrednost iz tabele \n5: Prikazi hes funkcije\n");
	izbor = prihvati_unos("Upisite Vas izbor funkcije: ");
	switch(izbor){
		case 1:hesiraj(Np,As,Ns,tabela,vel_tabele);break;
		case 2:ispisi_tabelu(tabela,vel_tabele);break;
		case 3:ispis_provere_vr_u_tabeli(tabela,vel_tabele);break;
		case 4:izbrisi_vr_iz_tabele(tabela,vel_tabele);break;
		case 5:ispisi_hes_f(Np,As,Ns);break;
        }
    }while(izbor!=0);
    exit(0);
}
