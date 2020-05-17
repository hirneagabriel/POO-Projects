#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

//clasa de baza Masina

class Masina
{
protected:
    string brand, model;
public:
    Masina() {
        brand = "marca";
        model = "model";
    };
    Masina(string a, string b) : brand(a), model(b) {}
    Masina(const Masina&);
    virtual ~Masina()
    {
        brand.clear();
        model.clear();
    }
    void operator=(const Masina&);
    friend istream& operator>>(istream&, Masina&);
    virtual void print(ostream&);
    string getBrand() const;
    string getModel() const;
};

Masina::Masina(const Masina& ob)
{
    brand = ob.brand;
    model = ob.model;
}

void Masina::operator=(const Masina& ob)
{
    if (!brand.empty())
    {
        brand.clear();
    }
    if (!model.empty())
    {
        model.clear();
    }
    brand = ob.brand;
    model = ob.model;
}

istream& operator>>(istream& in, Masina& ob)
{
    in >> ob.brand >> ob.model;
    return in;
}

void Masina::print(ostream& out)
{
    string a = typeid(*this).name();
    while (a[0] >= '0' && a[0] <= 9)
    {
        a.erase(a.begin());
    }
    out << a << ": " << brand << " " << model;
}
string Masina::getBrand() const
{
    return brand;
}

string Masina::getModel() const
{
    return model;
}

///clasa Coupe

class Coupe : public Masina {
public:
    Coupe() :Masina() {}
    Coupe(string a, string b) : Masina(a, b) {}
    Coupe(const Coupe& ob) : Masina(ob.brand, ob.model) {}
    void operator=(const Coupe&);
    friend istream& operator>>(istream&, Coupe&);
    ~Coupe() {
        brand.clear();
        model.clear();
    }
    void print(ostream&);
};


void Coupe::operator=(const Coupe& ob)
{
    if (!brand.empty())
    {
        brand.clear();
    }
    if (!model.empty())
    {
        model.clear();
    }
    brand = ob.brand;
    model = ob.model;
}
istream& operator>>(istream& in, Coupe& ob) {
    Masina& ob2 = ob;
    in >> ob2;
    return in;
}

void Coupe::print(ostream& out) {
    Masina::print(out);
    
}

///clasa Supersport

class Supersport : public Masina
{
    int pret;
public:
    Supersport() :Masina()
    {
        pret = 0;
    }
    Supersport(string a, string b, int p) : Masina(a, b)
    {
        pret = p;
    }
    Supersport(const Supersport& ob) :Masina(ob.brand, ob.model)
    {
        pret = ob.pret;
    }
    ~Supersport()
    {
        brand.clear();
        model.clear();
        pret = NULL;
    }
    void operator= (const Supersport&);


    int getPret() const;
    void setPret(int);
    friend istream& operator>>(istream&, Supersport&);
    void print(ostream&);

};

void Supersport::operator=(const Supersport& ob)
{
    if (!brand.empty())
    {
        brand.clear();
    }
    if (!model.empty())
    {
        model.clear();
    }
    brand = ob.brand;
    model = ob.model;
    pret = ob.pret;
}

istream& operator>>(istream& in, Supersport& ob) {
    Masina& ob2 = ob;
    in >> ob2;
    int p;
    in >> p;
    ob.pret = p;
    return in;
}

void Supersport::print(ostream& out)
{
    Masina::print(out);
  
}
int Supersport::getPret() const
{
    return pret;
}
void Supersport::setPret(int p)
{
    pret = p;
}
///clasa Cabrio

class Cabrio : public Masina {
public:
    Cabrio() :Masina() {}
    Cabrio(string a, string b) : Masina(a, b) {}
    Cabrio(const Cabrio& ob) : Masina(ob.brand, ob.model) {}
    void operator=(const Cabrio&);
    friend istream& operator>>(istream&, Cabrio&);
    ~Cabrio() {
        brand.clear();
        model.clear();
    }
    void print(ostream&);
};
void Cabrio::operator=(const Cabrio& ob)
{
    if (!brand.empty())
    {
        brand.clear();
    }
    if (!model.empty())
    {
        model.clear();
    }
    brand = ob.brand;
    model = ob.model;
}
istream& operator>>(istream& in, Cabrio& ob) {
    Masina& ob2 = ob;
    in >> ob2;
    return in;
}

void Cabrio::print(ostream& out) {
    Masina::print(out);
  
}
///clasa hothatch
class Hothatch : public Masina {
public:
    Hothatch() :Masina() {}
    Hothatch(string a, string b) : Masina(a, b) {}
    Hothatch(const Hothatch& ob) : Masina(ob.brand, ob.model) {}
    void operator=(const Hothatch&);
    friend istream& operator>>(istream&, Hothatch&);
    ~Hothatch() {
        brand.clear();
        model.clear();
    }
    void print(ostream&);
};
void Hothatch::operator=(const Hothatch& ob)
{
    if (!brand.empty())
    {
        brand.clear();
    }
    if (!model.empty())
    {
        model.clear();
    }
    brand = ob.brand;
    model = ob.model;
}
istream& operator>>(istream& in, Hothatch& ob) {
    Masina& ob2 = ob;
    in >> ob2;
    return in;
}

void Hothatch::print(ostream& out) {
    Masina::print(out);
    
}
////Expozitie
template <class T>
class Expozitie
{
    int nr;
    vector <pair<T*, int>> masini;
public:
    Expozitie() {
        nr = 0;
    }
    Expozitie(vector<T>);
    ~Expozitie();
    void operator+=(T&);
    void print(ostream& out);

};
template <class T>
void Expozitie<T>::operator+=(T& i)
{
    masini.emplace_back(new T(i), -1);
    nr++;
}
template <class T>
Expozitie<T>::Expozitie(vector<T> v)
{
    nr = v.size();
    for (auto i : v)
        masini.push_back(new T(i));
}
template <class T>
Expozitie<T>::~Expozitie()
{
    for (auto i : masini)
        delete(i.first);
    masini.clear();
}
template <class T>
void Expozitie<T>::print(ostream& out)
{
    out << "numar de masini: " << nr << "\n";
    for (auto i : masini) {
        i.first->print(out);
        out << " " << i.second << "\n";
    }
    
}

////specializare Supersport
template <>
class Expozitie <Supersport> {
    int nrExpuse, nrVandute;
    vector <pair <Supersport*, int>>vandute, expuse;
public:
    Expozitie()
    {
        nrExpuse = 0;
        nrVandute = 0;
    }
    ~Expozitie();
    void operator += (Supersport& s);
    void operator -= (Supersport& s);
    void print(ostream&);
};
Expozitie<Supersport>::~Expozitie()
{
    for (auto i : vandute)
    {
        delete(i.first);
    }
    vandute.clear();
    for (auto i : expuse)
    {
        delete(i.first);
    }
    expuse.clear();
}

void Expozitie<Supersport>::operator += (Supersport& ob) {
    expuse.emplace_back(new Supersport(ob), -1);
    nrExpuse++;
}

void Expozitie<Supersport>::operator-= (Supersport& ob) {
    if (nrExpuse == 0)
        cout << "Nu exista masini expuse!";
    else {
        for (int i = 0; i < nrExpuse; i++)
        {
            if (expuse[i].first->getBrand() == ob.getBrand() && expuse[i].first->getModel() == ob.getModel())
            {
                if (ob.getPret() != expuse[i].first->getPret())
                {
                    cout << "Ati incercat sa achizitionati " << ob.getBrand() + " " + ob.getModel() << " cu o suma incorecta.\n";
                }
                else {
                    vandute.emplace_back(new Supersport(ob), ob.getPret());
                    nrVandute++;
                    delete(expuse[i].first);
                    if (i != nrExpuse - 1)
                        expuse[i].first = expuse[nrExpuse - 1].first;
                    expuse[nrExpuse - 1].first = nullptr;

                    expuse.pop_back();
                    nrExpuse--;
                }
                    break;
                
            }
            if (i == nrExpuse - 1)
                cout << "Achizitionare incorecta!" << "\n";
        }

    }
}

void Expozitie<Supersport>::print(ostream& out) {
    out << "numar de masini supersport ramase: " << nrExpuse << "\n";
    for (auto i : expuse)
    {
        i.first->print(out);
        out << " " << i.second << "\n";
    }
    out << " numar de masini supersport vandute: " << nrVandute << "\n";
    for (auto i : vandute)
    {
        i.first->print(out);
        out << " " << i.second << "\n";
    }
}

int main()
{
    Expozitie<Supersport> supersport;
    Expozitie<Coupe> coupe;
    Expozitie<Cabrio> cabrio;
    Expozitie<Hothatch> hothatch;
    int n;
    in >> n;
    while (n)
    {
        string clasa;
        in >> clasa;
        if (clasa == "Coupe") {
            Coupe ob;
            in >> ob;
            coupe += ob;
        }
        else if (clasa == "Cabrio")
        {
            Cabrio ob;
            in >> ob;
            cabrio += ob;
        }
        else if (clasa == "Hot-Hatch")
        {
            Hothatch ob;
            in >> ob;
            hothatch += ob;
        }
        else if (clasa == "Supersport")
        {
            Supersport ob;
            in >> ob;
            supersport += ob;
        }
        else {
            cout << "eroare de introducere" << "\n";
        }
        n--;
    }

    int vanzari;
    in >> vanzari;
    while (vanzari)
    {
        Supersport A;
        in >> A;
        supersport -= A;
        vanzari--;
    }
    coupe.print(out);
    cabrio.print(out);
    hothatch.print(out);
    supersport.print(out);

    return 0;
}
