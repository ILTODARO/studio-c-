#include <iostream>
#include <time>
using namespace std;


class Fruit{
    private:
    string name, colour,season;

    public:
    Fruit(string nm, string cl, string ss):
    name(nm),colour(cl),season(ss){}

    void    set_Name    (string sx)  {name=sx;}
    void    set_Col     (string sx)  {colour=sx;}
    void    set_Season  (string sx)  {season=ss;}
    string  get_Name    ()           {return name;}
    string  get_Col     ()           {return colour;}
    string  get_Seas    ()           {return ss;}

    virtual void stampa_info(){
        cout<<"Nome frutto: "<<name<<"\t\tColore: "<<colour<< "\t\tStagione: "<<endl;
    }
    
    virtual void get_Flavour(){
        string fl []={"Crudo","Ottimale","Maturo"};


    }
};

class Apple:public Fruit{
    private:

    public:
};

int main(){
    srand(time(0));
    
    return 0;
}