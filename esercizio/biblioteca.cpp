#include <iostream>
#include <string>
using  namespace std;

class Item{
    private:
    int Id;
    string Title, Pub_date;

    public:
    Item(int id,string title, string pub_d):
    Id(id),Title(title),Pub_date(pub_d){}

    int     get_Id()                 {return Id;}
    void    set_Id(int x)            {Id=x;}
    //
    string  get_Title()              {return Title;}
    void    set_Title(string sx)     {Title=sx;}
    //
    string  get_Pub_D()              {return Pub_date;}
    void    set_Pub_D(string sx)     {Pub_date=sx;}
};

class Book: public Item{
    private:
    string Author;

    public:
    Book(int id,string title, string pub_d,string author):
    Item(id,title,pub_d),Author(author){}

    string get_Duration()              {return Author;}
    void   set_Duration(string sx)     {Author=sx;}

};

class DVD:  public Item{
    private:
    int Duration_min;

    public:
    DVD(int id,string title, string pub_d,int durat):
    Item(id,title,pub_d),Duration_min(durat){}

    int     get_Duration()      {return Duration_min;}
    void    set_Duration(int x) {Duration_min=x;}
};

class Persona{
    private:
    string Name,Surname;

    public:
    Persona(string name,string surname):Name(name),Surname(surname){}

    string get_Name()           {return Name;}
    string get_Surn()           {return Surname;}
    void   set_Name(string sx)  {Name=sx;}
    void   set_Surn(strign sx)  {Surname=sx;}

    virtual stampa_info() const {
        cout<<Name<<" "<<Surname<<" : "<<endl;

    }
};

template<class T>
class Node{
    private:
    T*obj;
    Node<T> * next;
    public:
    
};

template<class T>
class Queue :   public Node {
    private:
    
};

class Student   :  public Persona{
    private:
    List<

    public:
    Student(string name,string surname):
    Persona(name,surname){}

    void PrintItems(){

    }

    void stampa_info()const override{
        PrintItems();
    }

};

class Professor :   public Persona{
    public:
    P(string name,string surname):
    Persona(name,surname){}

};
class Biblioteca{};

int main(){

    return 0;
}