#include <iostream>
#include <string>
#include <cstdlib> // Per srand e rand
#include <ctime>   // Per time

using namespace std;

// --- CLASSE PERSONA ---
class Persona {
protected:
    string name, cogn;
    int eta;
public:
    Persona(const string& nm, const string& cgn, int e) : name(nm), cogn(cgn), eta(e) {}
    virtual ~Persona() {} // Distruttore virtuale

    virtual void stampa_info() const {
        cout << "Nome: " << name << " | Cognome: " << cogn << " | Eta: " << eta;
    }

   
};

// --- CLASSE PASSEGGERO ---
class Passeggero : public Persona {
private:
    string id_ticket;
    bool condizione;
public:
    Passeggero(const string& nm, const string& cgn, int et, const string& idt, bool cond = false)
        : Persona(nm, cgn, et), id_ticket(idt), condizione(cond) {}

    // CORREZIONE 1: Aggiunto 'override' per chiarezza e sicurezza
    // CORREZIONE 2: Migliorata la formattazione dell'output
    void stampa_info() const override {
        cout << "  -> Passeggero: " << name << " " << cogn 
             << "\t(Eta: " << eta << ")"
             << "\tID: " << id_ticket 
             << "\tStato: " << (condizione ? "Valido" : "Non Valido");
    }
};

// --- CLASSE NODO (TEMPLATE) ---
template <class T>
class Node {
private:
    T* info;
    Node<T>* next;
public:
    Node(T* inf) : info(inf), next(nullptr) {}
   ~Node()                      { delete info; } // Gestione memoria corretta
    
    T* get_info()               { return info; }
    Node<T>* get_next()         { return next; }
    void set_next(Node<T>* nx)  { next = nx;   }

};

// --- CLASSE LISTA (TEMPLATE) ---
template <class T>
class List {
private:
    Node<T>* pt_head;
public:
    List() : pt_head(nullptr) {}
    ~List() { // Gestione memoria corretta
        Node<T>* curr = pt_head;
        while (curr != nullptr) {
            Node<T>* to_delete = curr;
            curr = curr->get_next();
            delete to_delete;
        }
    }

    void insert_node(T* dt) {
        Node<T>* new_n = new Node<T>(dt);
        if (!pt_head) {
            pt_head = new_n;
        } else {
            Node<T>* curr = pt_head;
            while (curr->get_next() != nullptr) {
                curr = curr->get_next();
            }
            curr->set_next(new_n);
        }
    }

    void print_list() const {
        Node<T>* curr = pt_head;
        if (!curr) {
            cout << "  -> Lista vuota." << endl;
        }
        while (curr != nullptr) {
            curr->get_info()->stampa_info();
            cout << endl; // Aggiunge un a capo dopo ogni elemento stampato
            curr = curr->get_next();
        }
    }
    
    int count_nodes() const {
        int count = 0;
        Node<T>* curr = pt_head;
        while (curr != nullptr) {
            count++;
            curr = curr->get_next();
        }
        return count;
    }
};

// --- CLASSE VOLO ---
class Volo {
private:
    string id_fl, ride;
    List<Passeggero> passeggeri;
    int post_tot;
public:
    Volo(const string& id_f, const string& rid, int tot)
        : id_fl(id_f), ride(rid), post_tot(tot) {}

    int get_Post_occ() const { return passeggeri.count_nodes(); }
    
    void aggiungi_passeggero(Passeggero* p) {
        if (get_Post_occ() < post_tot) {
            passeggeri.insert_node(p);
        } else {
            cout << "Volo " << id_fl << " pieno. Impossibile aggiungere passeggero." << endl;
            delete p;
        }
    }

    
    int get_Post_lib() const { return post_tot - get_Post_occ(); }
    string get_Id_fl() const { return id_fl; }

    // CORREZIONE 2: Migliorata la formattazione dell'output
    void stampa_info() const {
        cout << "✈️  Volo: " << id_fl 
             << "\t\tDestinazione: " << ride 
             << "\t\tCapienza: (" << get_Post_occ() << "/" << post_tot << ")" << endl;
        passeggeri.print_list();
    }

   
};

// --- CLASSE AEROPORTO ---
class aereoporto {
    
    private:
    string nome, cod_IATA;
    List<Volo> lista_voli;
    public:
    aereoporto(const string& nm, const string& cod) : nome(nm), cod_IATA(cod) {}

    void aggiungi_volo(Volo* v) {
        lista_voli.insert_node(v);
    }
    
    void stampa_voli_programmati() const {
        cout << "\n=== TABELLONE VOLI PER L'AEROPORTO DI " << nome << " (" << cod_IATA << ") ===" << endl;
        lista_voli.print_list();
    }
};

// --- MAIN ---
int main() {
    aereoporto fiumicino("Fiumicino - Leonardo da Vinci", "FCO");

    Volo* voloNY = new Volo("AZ608", "New York", 150);
        voloNY->aggiungi_passeggero (new Passeggero("Mario",    "Rossi",    35, "TK1122",   true));
        voloNY->aggiungi_passeggero (new Passeggero("Laura",    "Bianchi",  28, "TK3344",   false));
    
        fiumicino.aggiungi_volo     (voloNY);

    Volo* voloTK = new Volo("JL416", "Tokyo", 200);
        voloTK->aggiungi_passeggero (new Passeggero("Giuseppe", "Verdi", 52, "TK5566", true)    );
        voloTK->aggiungi_passeggero (new Passeggero("Anna", "Neri", 41, "TK7788", true     )    );
        
        fiumicino.aggiungi_volo     (voloTK);

    fiumicino.stampa_voli_programmati();

    return 0;
}