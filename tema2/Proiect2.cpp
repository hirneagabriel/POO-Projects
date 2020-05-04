#include <iostream>
#include <cstring>

using namespace std;

class Nod
{
protected:
    char* info;
    Nod* next;
public:
    Nod();
    Nod(char* , Nod*);
    Nod(const Nod&);
    void operator=(const Nod&);
    friend istream& operator>>(istream&, Nod&);
    friend ostream& operator<<(ostream&, const Nod&);
    virtual ~Nod();

};

Nod::Nod()
{
    info = new char[strlen("necunoscut")+1];
    strcpy(info, "necunoscut");
    next = NULL;
}

Nod::Nod(char* sir, Nod* legatura)
{
    info = new char[strlen(sir)+1];
    strcpy(info, sir);
    next = legatura;
}

Nod::Nod(const Nod& ob)
{
    info = new char[strlen(ob.info)+1];
    strcpy(info, ob.info);
    next = ob.next;
}

void Nod::operator=(const Nod& ob)
{
    if (info)
    {
        delete[] info;
    }
    info = new char[strlen(ob.info)+1];
    strcpy(info, ob.info);
    next = ob.next;
}

istream& operator>>(istream& in, Nod& ob)
{
    char c[255];
    cout << "introduceti informatia: ";
    in >> c;
    ob.info = new char[strlen(c)+1];
    strcpy(ob.info, c);
    return in;
}
ostream& operator<<(ostream& out, const Nod& ob)
{
    out << ob.info<<endl;
    return out;
}
Nod::~Nod()
{
    delete[] info;
    next = NULL;
}

class Nod_dublu : public Nod
{
protected:
    Nod* ante;
public:
    Nod_dublu();
    Nod_dublu(char*, Nod*, Nod*);
    Nod_dublu(const Nod_dublu&);
    void operator=(const Nod_dublu&);
    virtual ~Nod_dublu();
};

Nod_dublu::Nod_dublu():Nod()
{
    ante = NULL;

}

Nod_dublu::Nod_dublu(char* c, Nod* next, Nod* anterior) : Nod(c, next)
{
    ante = anterior;
}

Nod_dublu::Nod_dublu(const Nod_dublu& ob):Nod(ob) {
    ante = ob.ante;
}

void Nod_dublu::operator=(const Nod_dublu& ob)
{
    if (info)
    {
        delete[] info;
    }
    info = new char[strlen(ob.info) + 1];
    strcpy(info, ob.info);
    next = ob.next;
    ante = ob.ante;
}

Nod_dublu::~Nod_dublu()
{
    delete ante;
}

class Nod_prioritate :public Nod_dublu
{
protected:
    int prio;
public:
    Nod_prioritate();
    Nod_prioritate(char*, Nod*, Nod*, int);
    Nod_prioritate(const Nod_prioritate&);
    void operator=(const Nod_prioritate&);
    ~Nod_prioritate();
    friend istream& operator>>(istream&, Nod_prioritate&);
    friend ostream& operator<<(ostream&, const Nod_prioritate&);
    char* get_info();
    void set_info(const char* );
    int get_prio();
    void set_prio(int);
    Nod* get_next();
    void set_next(Nod_prioritate*);
    void set_next(Nod*);
    Nod* get_ante();
    void set_ante(Nod_prioritate*);

};
char* Nod_prioritate::get_info()
{
    return info;
}
void Nod_prioritate::set_info(const char* c)
{
    info = new char[strlen(c) + 1];
    strcpy(info, c);

}

int Nod_prioritate::get_prio()
{
        return prio;
}

Nod* Nod_prioritate:: get_next()
{
    return next;
}

void Nod_prioritate::set_next(Nod_prioritate* c)
{
    next = c;
}
void Nod_prioritate::set_next(Nod* c)
{
    next = c;
}

Nod* Nod_prioritate::get_ante()
{
    return ante;
}

void Nod_prioritate::set_ante(Nod_prioritate* c)
{
    ante = c;
}


void Nod_prioritate::set_prio(int p)
{
    prio = p;
}

Nod_prioritate::Nod_prioritate()
{
    prio = 0;

}

Nod_prioritate::Nod_prioritate(char* c, Nod* next, Nod* anterior, int prioritate) :Nod_dublu(c, next, anterior)
{
    prio = prioritate;
}

Nod_prioritate::Nod_prioritate(const Nod_prioritate& ob) : Nod_dublu(ob)
{
    prio = ob.prio;
}

void Nod_prioritate::operator=(const Nod_prioritate& ob)
{
    if (info)
    {
        delete[] info;
    }
    info = new char[strlen(ob.info) + 1];
    strcpy(info, ob.info);
    next = ob.next;
    ante = ob.ante;
    prio = ob.prio;
}

Nod_prioritate::~Nod_prioritate()
{
    prio = 0;
}

istream& operator>>(istream& in, Nod_prioritate& ob)
{
    char c[255];
    cout << "introduceti informatia: ";
    in >> c;
    ob.info = new char[strlen(c) + 1];
    strcpy(ob.info, c);
    cout << "introduceti prioritate: ";
    in >> ob.prio;
    return in;
}

ostream& operator<<(ostream& out,const Nod_prioritate& ob)
{
    out << ob.info;
    out << endl;
    out << ob.prio;
    return out;
}


class Coada_prioritati
{
    Nod_prioritate* primul;
public:
    Coada_prioritati();
    ~Coada_prioritati();
    void insert(const char* i, int p);
    void print();
    void top();
    void pop();
    void empty();
};
Coada_prioritati::Coada_prioritati()
{
    primul = NULL;
}
Coada_prioritati::~Coada_prioritati()
{
    delete primul;
}

void Coada_prioritati::top()
{
    cout << "elementul cu prioritatea cea mai mare este:" << endl;
    cout << primul->get_info()<<" ";
    cout <<"cu prioritatea: "<< primul->get_prio()<<endl;
    cout << endl;

}
void Coada_prioritati::insert(const char* i, int p)
{
    Nod_prioritate* tmp, * q;
    tmp = new Nod_prioritate;
    tmp->set_info(i);
    tmp->set_prio(p);
    if (primul == NULL||p > primul->get_prio())
    {
        tmp->set_next(primul);
        primul = tmp;
    }
    else
    {
        q = primul;
        Nod_prioritate* d = dynamic_cast<Nod_prioritate*>(q->get_next());
        while (q->get_next() != NULL && d->get_prio() >= p)

            q = dynamic_cast<Nod_prioritate*>(q->get_next());
        tmp->set_next(q->get_next());
        q->set_next(tmp);
    }

}

void Coada_prioritati::pop()
{
    Nod_prioritate* tmp;
    if (primul == NULL)
        cout << "Coada goala\n";
    else
    {
        tmp = primul;
        cout << "Elementul sters este:  " << tmp->get_info() << endl;
        primul = dynamic_cast<Nod_prioritate*>(primul->get_next());
    }
}

void Coada_prioritati::empty()
{
    primul = NULL;
}
void Coada_prioritati::print()
{
    Nod_prioritate* ptr;
    ptr = primul;
    if (primul == NULL)
        cout << "Coada goala\n";
    else
    {
        cout << "Coada este:\n";
        cout << "Prioritate     Element\n";
        while (ptr != NULL)
        {
            cout << ptr->get_prio() << "              " << ptr->get_info() << endl;
            ptr = dynamic_cast<Nod_prioritate*>(ptr->get_next());
        }
    }
    cout << endl;
}

void Afisare_n_ememente()
{
    Coada_prioritati A;
    Nod_prioritate B;
    int n,i;
    cout<<"introduceti nr valori: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> B;
        A.insert(B.get_info(), B.get_prio());
    }
    A.print();
}





int main()
{
    Coada_prioritati A;
    A.insert("A", 2);
    A.insert("C", 1);
    A.insert("D", 3);
    A.print();
    A.top();
    A.insert("B", 5);
    A.insert("ana", 4);
    A.print();
    A.pop();
    A.print();
    A.empty();
    A.print();
    //Afisare_n_ememente();

    return 0;
}


