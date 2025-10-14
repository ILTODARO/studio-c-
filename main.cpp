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



class Passeggero{
    
    bool    condizione;

    public:
    Passeggero(string nm, string cgn, int et, bool cond=false) :
            name(nm), cogn(cgn), eta(et), condizione(cond){}
    
            void set_Name       (string nam)    { name= nam;        }
            void set_Cogn       (string cogno)  { cogn=cogno;       }
            void set_Eta        (int x)         { eta=x;            }
            void set_cond       (bool x)        { condizione=x;     }

            string get_Name     ()              { return name;      }
            string get_Cognome  ()              { return cogn;      }
            int    get_Eta      ()              { return eta;       }
            bool get_Condizione ()              { return condizione;}

};


template <class T>
class Node_Pass{
    private:

    public:

};

int main(){
    return 0;
}