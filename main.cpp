#include <iostream>
using namespace std;

class Passeggero{
    private:
    string  name, cogn;
    int     eta;
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