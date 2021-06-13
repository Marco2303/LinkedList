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



void ins_coda(t_riga_scontrino* &head, t_riga_scontrino* nuovo)
{

    t_riga_scontrino *cerca_fine_lista = head;

    if (head == nullptr){
            ins_testata(head,nuovo);
    }else{
        while(cerca_fine_lista->next != nullptr){
            cerca_fine_lista = cerca_fine_lista->next;
        }
            cerca_fine_lista->next = nuovo;
            nuovo->next=nullptr;
    }

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
        //ins_testata2(scontrino->head,nuovo);  //crea una lista LIFO
        ins_coda(scontrino->head,nuovo);    //crea una lista FIFO
    }
    stampa_righe_scontrino(scontrino->head);

    return 0;
}
