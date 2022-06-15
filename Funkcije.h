void popuna_tabele (int tabela[],int vel_tabele, int vrednost);

void obavestenje_o_proveri (int puna_tabela);

int provera_tabele (int tabela[],int vel_tabele); //provera da li je tabela puna

int prihvati_unos (char* tekst); //prihvatanje unosa i provera da li je broj

void hesiraj (int Np,int As, int Ns, int tabela[],int vel_tabele);   //hesiranje vrednosti

int primarna_hes_funk( int Np,int As, int Ns, int vrednost,int vrednost_sek_h_f, int tabela[], int kontrola,int vel_tabele, int detekcija_besk_petlje[]);

int provera_vrednosti_u_tabeli(int tabela[],int vel_tabele,int vrednost);

void ispis_provere_vr_u_tabeli(int tabela[],int vel_tabele);

void izbrisi_vr_iz_tabele(int tabela[],int vel_tabele);

int sekundarna_hes_funk(int As, int Ns, int vrednost);

void ispisi_tabelu(int tabela[],int vel_tabele);

void ispisi_hes_f(int Np, int As, int Ns);
