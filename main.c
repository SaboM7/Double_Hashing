#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void popuna_tabele (int tabela[],int vel_tabele, int vrednost){
    for(int i=0;i<vel_tabele; i++){
        tabela[i]=vrednost;
    }
}

void obavestenje_o_proveri (int puna_tabela){
        if (puna_tabela == 1){
            printf("\nTabela je puna!\n");
            return;
            }
        else {
            printf("\nHes funkcija je usla u beskonacnu petlju!\nMolim Vas promenite hes funkcije.\n");
            return;
            }
}

int provera_tabele (int tabela[],int vel_tabele){ //provera da li je tabela puna
    for(int i=0;i<vel_tabele; i++){
        if (tabela[i]==-1){
            return 0;
        }
    }
    return 1;
}

int prihvati_unos(char* tekst){ //prihvatanje unosa i provera da li je broj
    char unos[20];
    int duzina,i,jeste_broj;
    while(1){
        jeste_broj=1;
        printf(" ");
        printf(tekst);
        scanf("%s", unos);
        duzina = strlen (unos);
        for (i=0;i<duzina; i++){
            if (!isdigit(unos[i])){
                printf ("Unesena je pogresna vrednost.\nMolim Vas unesite ponovo.\n");
                i=0;
                jeste_broj=0;
                break;
            }
        }
        if(jeste_broj==1){
            i=0;
            return atoi(unos);
        }
    }
}

void hesiraj (int Np,int As, int Ns, int tabela[],int vel_tabele){   //hesiranje vrednosti
    int index=-1,vrednost=-1,vrednost_sekund_h_f=0;
    int kontrola = 0;

    vrednost = prihvati_unos("\nUpisite vrednost za unos u tabelu: ");
    int pom = provera_vrednosti_u_tabeli(tabela,vel_tabele,vrednost);  //provera da li u tabeli postoji vrednost
    if (pom >= 0){
        printf("\nVrednost %d se nalazi na indeksu %d u tabeli.\n",vrednost,pom);
        return;
        }
    else{
        int pom1 = provera_tabele(tabela,vel_tabele);                   //provera da li je tabela puna
        if (pom1==1){
            printf("\nTabela je puna!\n");
            return;
        }else {
        int detekcija_besk_petlje[vel_tabele];                          //tabela za skladistenje indeksa pokusaja upisivanja
        popuna_tabele(detekcija_besk_petlje,vel_tabele,0);

        vrednost_sekund_h_f = sekundarna_hes_funk(As,Ns, vrednost);
        index =  primarna_hes_funk(Np, As, Ns, vrednost,vrednost_sekund_h_f, tabela, kontrola, vel_tabele, detekcija_besk_petlje);
        if (index==-1){
            printf("Vrednost %d nije upisana u tabelu.\n", vrednost);
        }
        else{
            tabela[index]= vrednost;
            printf("\nUnesena je vrednost %d u polje sa indeksom %d.\n\n", vrednost, index);
            }
        }
    }
    ispisi_tabelu(tabela, vel_tabele);
    return;
}

int primarna_hes_funk( int Np,int As, int Ns, int vrednost,int vrednost_sek_h_f, int tabela[], int kontrola,int vel_tabele, int detekcija_besk_petlje[]){
    int vrednost_posle_hesiranja;
    if (kontrola == 0){ //koristi se da proveri da li se prvi put poziva funkcija primarnog hesiranja
        vrednost_posle_hesiranja= vrednost%Np ;
    } else{
        vrednost_posle_hesiranja= (vrednost+ vrednost_sek_h_f)%Np ;
    }
    printf("\nHes vrednost je: %d\n", vrednost_posle_hesiranja);
    printf("\nVrednost sekundarne hes funkcije je: %d\n", vrednost_sek_h_f);
    if (tabela[vrednost_posle_hesiranja] != -1){ //provera da li je prazno polje i poziv ponovnog hesiranja sa sekundarnom funkcijom
        if (detekcija_besk_petlje[vrednost_posle_hesiranja]==1){ //provera da li je vec funkcija dala vrednost tog indeksa
            printf("Funkcije su usle u beskonacnu petlju!\nIzbor hes funkcija nije dobar.\n\n");
            return -1;
        }else {
            detekcija_besk_petlje[vrednost_posle_hesiranja]=1;
            //ispisi_tabelu(detekcija_besk_petlje,vel_tabele);
        }
        kontrola++;
        return primarna_hes_funk(Np, As, Ns, vrednost_posle_hesiranja ,vrednost_sek_h_f,tabela, kontrola, vel_tabele, detekcija_besk_petlje);
    }else{ //vracanje vrednosti indeksa
        return vrednost_posle_hesiranja;
    }
}

int provera_vrednosti_u_tabeli(int tabela[],int vel_tabele,int vrednost){
    for(int i;i<vel_tabele;i++){
        if (tabela[i]==vrednost){
            return i;
        }
    }
    return -1;
}

void ispis_provere_vr_u_tabeli(int tabela[],int vel_tabele){
    int vrednost= prihvati_unos("\nUnesite vrednost za proveru: ");
    int pom = provera_vrednosti_u_tabeli(tabela,vel_tabele,vrednost);
    if (pom < 0){
        printf("\nNema vrednosti %d u tabeli.\n",vrednost);
    }
    else{
        printf("\nVrednost %d se nalazi na indeksu %d u tabeli.\n",vrednost,pom);
    }
    return;
}

void izbrisi_vr_iz_tabele(int tabela[],int vel_tabele){
    int vrednost= prihvati_unos("\nUnesite vrednost za brisanje: ");
    int pom = provera_vrednosti_u_tabeli(tabela,vel_tabele,vrednost);
    if (pom < 0){
        printf("\nNema vrednosti %d u tabeli.\n",vrednost);
    }
    else{
        tabela[pom]=-1;
        printf("\nVrednost %d je izbrisana sa indeksa %d u tabeli.\n",vrednost,pom);
        ispisi_tabelu(tabela,vel_tabele);
    }
   return;
}

int sekundarna_hes_funk(int As, int Ns, int vrednost){
    int vrednost_posle_sek_funk = As + (vrednost%Ns);
    return vrednost_posle_sek_funk;
}

void ispisi_tabelu(int tabela[],int vel_tabele){
    for(int i=0;i<vel_tabele; i++){
        printf("%d\t%d \n",i, tabela[i]);
    }
    return;
}

void ispisi_hes_f(int Np, int As, int Ns){
    printf("\nPrimarna hes funkcija je oblika h(K)= K mod %d .\n", Np);
    printf("\nSekundarna hes funkcija je oblika g(K)= %d + K mod %d\n", As,Ns);
}

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
