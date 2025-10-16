#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Persona {
private:
    string name, cogn;
    int eta;

public:
    // --- Costruttore ---
    Persona(const string& nm, const string& cgn, int e) {
        name = nm;
        cogn = cgn;
        eta = e;
    }

    // --- Distruttore Virtuale ---
    virtual ~Persona() {}

    // --- Metodi SET ---
    void setName(const string& nm) {
        name = nm;
    }

    void setCogn(const string& cgn) {
        cogn = cgn;
    }

    void setEta(int e) {
        eta = e;
    }

    // --- Metodi GET ---
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
    virtual void stampa_info() const {
        cout << "Nome: " << name << " Cognome: " << cogn << " Eta: " << eta << endl;
    }
};


class Passeggero: public Persona{
    private:
    string id_ticket;
    bool    condizione;

    public:
    Passeggero(const string& nm, const string& cgn, int et, const string& idt, bool cond=false) :
            Persona(nm,cgn,et), id_ticket(idt), condizione(cond){}
    
    void set_Id_ticket(const string& sx) { id_ticket=sx; }
    void set_cond(bool x) { condizione=x; }

    string get_Id_ticket() const { return id_ticket; }
    bool get_Condizione() const { return condizione;}

    void stampa_info() const override{
        Persona::stampa_info();
        cout << "ID Ticket: " << id_ticket << " Condizione: " << condizione << endl;
    }
};


template <class T>
class Node{
    private:
    T*info;
    Node<T>*next;

    public:
    Node(T*inf):info(inf),next(nullptr){}

    void set_Info(T*x){info=x;}
    T* get_info(){return info;}

    void set_next(Node<T>*nx){next=nx;}
    Node<T>* get_next(){return next;}
};

template <class T>
class List{
    private:
    Node<T>*pt_head;

    public:
    List(): pt_head(nullptr) {}
    void set_Head(Node<T>*ptx){pt_head=ptx;}
    Node<T>* get_Head(){return pt_head;}

    void insert_node(T*dt){
        Node<T>*new_n = new Node<T>(dt);
        
        if(!pt_head){
            pt_head=new_n;
        }else{
            Node<T>*curr=pt_head;
            while(curr->get_next() != nullptr){
                curr=curr->get_next();
            }
            curr->set_next(new_n);
        }
    }

    void delete_n(T*dt){
        Node<T>*curr = pt_head;
        Node<T>*prec = nullptr;
        
        if(curr){
            // Caso 1: il nodo da eliminare è la testa
            if(*(curr->get_info()) == *dt){
                pt_head = curr->get_next();
                delete curr;
                return;
            }
            
            // Caso 2: il nodo è nel mezzo o in coda
            while(curr != nullptr && *(curr->get_info()) != *dt){
                prec = curr;
                curr = curr->get_next();
            }
            
            // Se abbiamo trovato il nodo
            if(curr != nullptr){
                prec->set_next(curr->get_next());
                delete curr;
            }
        }else{
            cout << "Lista vuota" << endl;
        }
    }
    
    void print_list(){
        Node<T>*curr = pt_head;
        while(curr != nullptr){
            curr->get_info()->stampa_info();
            curr = curr->get_next();
        }
    }
};

int main(){
    srand(time(0)); // Inizializza il generatore random
    
    // Array di nomi e cognomi random
    string nomi[] = {"Mario", "Luigi", "Anna", "Sofia", "Marco", "Laura"};
    string cognomi[] = {"Rossi", "Bianchi", "Verdi", "Neri", "Gialli", "Blu"};
    
    List<Passeggero> lista;
    
    cout << "=== GENERAZIONE PASSEGGERI RANDOM ===" << endl << endl;
    
    // Genera 5 passeggeri random
    for(int i = 0; i < 5; i++){
        string nome = nomi[rand() % 6];
        string cognome = cognomi[rand() % 6];
        int eta = rand() % 60 + 18; // Età tra 18 e 77
        string ticket = "TK" + to_string(rand() % 9000 + 1000); // TK1000-TK9999
        bool condizione = rand() % 2; // true o false random
        
        Passeggero* p = new Passeggero(nome, cognome, eta, ticket, condizione);
        lista.insert_node(p);
    }
    
    cout << "Lista completa:" << endl;
    lista.print_list();
    
    return 0;
}