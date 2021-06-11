#include <iostream>

using namespace std;
struct t_riga_scontrino;

struct t_scontrino
{
    string data;
    int codicepv;
    string cassa;

    t_riga_scontrino *head;
};


struct t_riga_scontrino
{
    int codiceProdotto;
    int qta;
    double prezzo;

    t_riga_scontrino *next;  //indirizzo della struct successiva alla riga sucessiva nullptr se sei alla fine
};

template <typename T>
void ins_testata2 (T* &head, T* nuovo){
    nuovo->next = head;
    head=nuovo;
}

void ins_testata(t_riga_scontrino* &head, t_riga_scontrino *nuovo){
    nuovo->next = head;
    head=nuovo;
}


void stampa_righe_scontrino(t_riga_scontrino *head){
    t_riga_scontrino *copia = head;

    while(copia != nullptr){
        cout << "-----------" << endl;
        cout << "Prodotto: " << copia->codiceProdotto << endl;
        cout << "Quantita: " << copia->qta << endl;
        cout << "Prezzo: " << copia->prezzo << endl;

        copia = copia->next;
    }
}
int main()
{

    t_scontrino *scontrino = new t_scontrino{"2021-06-11",123,"CASSA1", nullptr};

    for (int i=0;i<10;i++){
        t_riga_scontrino *nuovo = new t_riga_scontrino{i,i*10,100.0*i};
        ins_testata(scontrino->head,nuovo);
    }
    stampa_righe_scontrino(scontrino->head);

    return 0;
}
