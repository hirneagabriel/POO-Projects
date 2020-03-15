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
    cout << "dimensiune matrice:";
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
    for (int i = 0; i < ob.dimen; i++)
        cout << ob.v[i];
    return out;
}

int** Vector_de_vectori::creare_matrice(int& n, int& m)
{
    
    for (int i = 0; i < dimen; i++)
        if (m < v[i].dim)
            m = v[i].dim;

    if (n < dimen)
        n = dimen;

    int** matrice;
    matrice = new int* [n];
    for (int i = 0; i < n; i++)
        matrice[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
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
        p1 = ob.creare_matrice(n, m);
    }
    if (m < y)
    {
        m = y;
        p1 = ob.creare_matrice(n, m);
    }
    if (m > y)
    {
        y = m;
        p2 = ob.creare_matrice(x, y);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            p1[i][j] = p1[i][j] + p2[i][j];
    return p1;
}


int main()
{

    Vector_de_vectori c,d;
    cin >> c;
    cin >> d;
    int** matrice;
    int n = 0;
    int m = 0;
    matrice = c+d;
  

    return 0;
}
