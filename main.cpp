#include <iostream>
using namespace std;

class Persona {
private:
    string name, cogn;
    int eta;

public:
    // --- Costruttore ---
    // Inizializza gli attributi della classe con i valori passati come argomenti.
    Persona(string nm, string cgn, int e) {
        name = nm;
        cogn = cgn;
        eta = e;
    }

    // --- Distruttore Virtuale ---
    // Buona pratica per classi destinate a essere basi per altre classi (ereditarietà).
    virtual ~Persona() {}

    // --- Metodi SET ---
    // Permettono di modificare il valore degli attributi privati dall'esterno.
    void setName(string nm) {
        name = nm;
    }

    void setCogn(string cgn) {
        cogn = cgn;
    }

    void setEta(int e) {
        eta = e;
    }

    // --- Metodi GET ---
    // Permettono di leggere il valore degli attributi privati dall'esterno.
    // 'const' indica che questi metodi non modificano lo stato dell'oggetto.
    string getName() const {
        return name;
    }

    string getCogn() const {
        return cogn;
    }

    int getEta() const {
        return eta;
    }

    // --- Funzione Virtuale ---
    // Stampa le informazioni della persona.
    // 'virtual' permette a questa funzione di essere ridefinita (override)
    // in eventuali classi derivate.
    virtual void stampaInformazioni() const {
        cout << "Nome: " << name << endl;
        cout << "Cognome: " << cogn << endl;
        cout << "Eta: " << eta << endl;
    }
};



class Passeggero: public Persona{
    private:
    string id_ticket;
    bool    condizione;

    public:
    Passeggero(string nm, string cgn, int et, string idt,bool cond=false) :
            Persona(nm,cgn,et)id_ticket(idt),condizione(cond){}
    
            void set_Name       (string nam)    { name= nam;        }
            void set_Cogn       (string cogno)  { cogn=cogno;       }
            void set_Eta        (int x)         { eta=x;            }
            void set_Id_ticket  (string sx)     { id_ticket=sx;     }
            void set_cond       (bool x)        { condizione=x;     }

            string get_Name     ()              { return name;      }
            string get_Cognome  ()              { return cogn;      }
            int    get_Eta      ()              { return eta;       }
            string get_Id_ticket()              { return id_ticket; }
            bool get_Condizione ()              { return condizione;}

};


template <class T>
class Node{
    private:
    T*info;
    Node<T>*next;

    public:
    Node(T*inf):info(inf),next(nullptr){}
    

};

int main(){
    return 0;
}