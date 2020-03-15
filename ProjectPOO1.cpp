#include <iostream>
using namespace std;

class Vector
{
    friend class Vector_de_vectori;
    int* arr;
    int dim;
public:
    Vector(int numar = 0, int dimensiune = 1);
    Vector(const Vector&);
    void operator=(const Vector&);
    friend istream& operator>>(istream&, Vector&);
    friend ostream& operator<<(ostream&, const Vector&);
    ~Vector();
};

Vector::Vector(int numar, int dimensiune)
{
    arr = new int[dimensiune];
    dim = dimensiune;
    for (int i = 0; i < dimensiune; i++)
        arr[i] = numar;
}

Vector::Vector(const Vector& ob)
{
    arr = new int[ob.dim];
    for (int i = 0; i < ob.dim; i++)
        arr[i] = ob.arr[i];
    dim = ob.dim;

}

void Vector::operator=(const Vector& ob)
{
    delete[] arr;
    arr = new int[ob.dim];
    for (int i = 0; i < ob.dim; i++)
        arr[i] = ob.arr[i];
    dim = ob.dim;
}

istream& operator>>(istream& in, Vector& ob)
{
    if (ob.dim > 0)
    {
        ob.dim = 0;
        delete[] ob.arr;
    }
    cout << "dimensiune vector:";
    in >> ob.dim;
    ob.arr = new int[ob.dim];
    for (int i = 0; i < ob.dim; i++)
    {
        in >> ob.arr[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const Vector& ob)
{
    for (int i = 0; i < ob.dim; i++)
        out << ob.arr[i] << ' ';
    out << endl;
    return out;
}

Vector::~Vector()
{
    delete[] arr;
    dim = 0;
}


class Vector_de_vectori
{
    Vector* v;
    int dimen;
public:
    Vector_de_vectori(int numar = 0, int dimensiune = 1);
    Vector_de_vectori(const Vector_de_vectori&);
    ~Vector_de_vectori();
    friend istream& operator>>(istream&, Vector_de_vectori&);
    friend ostream& operator<<(ostream&, const Vector_de_vectori&);
    int** creare_matrice(int& n, int& m);
    int** operator+(Vector_de_vectori&);
    int get_dimen();

};

Vector_de_vectori::Vector_de_vectori(int numar, int dimensiune)
{
    v = new Vector[dimensiune];
    dimen = dimensiune;
    for (int i = 0; i < dimensiune; i++)
        for (int j = 0; j < v[i].dim; j++)
            v[i].arr[j] = numar;
}

Vector_de_vectori::Vector_de_vectori(const Vector_de_vectori& ob)
{
    v = new Vector[ob.dimen];
    for (int i = 0; i < ob.dimen; i++)
        for (int j = 0; j < ob.v[i].dim; j++)
            v[i].arr[j] = ob.v[i].arr[j];
    dimen = ob.dimen;
}

Vector_de_vectori::~Vector_de_vectori()
{
    delete[] v;
    dimen = 0;
}

istream& operator>>(istream& in, Vector_de_vectori& ob)
{
    if (ob.dimen > 0)
    {
        ob.dimen = 0;
        delete[] ob.v;
    }
    cout << "dimensiune Vector de vectori:";
    in >> ob.dimen;
    ob.v = new Vector[ob.dimen];
    for (int i = 0; i < ob.dimen; i++)
    {
        cin >> ob.v[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const Vector_de_vectori& ob)
{
    cout << "dimensiune: ";
    cout << ob.dimen;
    cout << endl;
    cout << "Vectorul de vectori:";
    cout << endl;
    for (int i = 0; i < ob.dimen; i++)
        cout << ob.v[i];
    return out;
}

int** Vector_de_vectori::creare_matrice(int& nr_linii, int& nr_coloane)
{

    for (int i = 0; i < dimen; i++)
        if (nr_coloane < v[i].dim)
            nr_coloane = v[i].dim;

    if (nr_linii < dimen)
        nr_linii = dimen;

    int** matrice;
    matrice = new int* [nr_linii];
    for (int i = 0; i < nr_linii; i++)
        matrice[i] = new int[nr_coloane];

    for (int i = 0; i < nr_linii; i++)
        for (int j = 0; j < nr_coloane; j++)
            if (j < v[i].dim && i < dimen)
                matrice[i][j] = v[i].arr[j];
            else
                matrice[i][j] = 0;
    return matrice;
}

int** Vector_de_vectori::operator+(Vector_de_vectori& ob)
{
    int n = 0, m = 0, x = 0, y = 0;

    int** p1;
    int** p2;
    p1 = creare_matrice(n, m);
    p2 = ob.creare_matrice(x, y);
    if (x < n)
    {
        x = n;
        p2 = ob.creare_matrice(x, y);
    }
    if (x > n)
    {
        n = x;
        p1 = creare_matrice(n, m);
    }
    if (m < y)
    {
        m = y;
        p1 = creare_matrice(n, m);
    }
    if (m > y)
    {
        y = m;
        p2 = ob.creare_matrice(x, y);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            p1[i][j] = p1[i][j] + p2[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << p1[i][j] <<" ";
        cout << endl;
    }
    return p1;
}

int Vector_de_vectori::get_dimen()
{
    return dimen;
}

void n_obiecte()
{
    int n;
    cout << "numar obiecte:";
    cin >> n;
    Vector_de_vectori* p;
    p = new Vector_de_vectori[n];
    cout << "citire "<< n<<" obiecte: ";
    cout << endl;
    for (int i = 0; i < n; i++)
    {

        cin >> p[i];
        cout << endl;
    }
    cout << endl;
    cout << "afisare "<< n<<" obiecte:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "obiectul nr " << i + 1 << endl;
        cout << p[i] << endl;

    }

}

int main()
{

    //testare metoda A+B
    Vector_de_vectori a, b;
    cin >> a >> b;
    a + b;

    //testare metoda creare_matrice(ce e comentat mai jos)
    /*
    int** p;
    int n = 0;
    int m = 0;
    p=a.creare_matrice(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << p[i][j]<<" ";
        cout << endl;
    }

    */
    return 0;
}
