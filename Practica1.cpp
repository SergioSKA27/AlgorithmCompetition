#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <chrono> //libreria para medir los tiempos de Ejecucion

using namespace std;
/*
    Para el facilitar el proceso y hacerlo lo mas parecido a una 
    competencia de algoritmos, he diseñado una clase competencia 
    la cual tiene como atributos los tiempos de ejecucion de cada 
    uno de los algoritmos,los algoritmos que se pondran a competir
    y finalmente la entrada que se usara para ponerlos a competir  
*/

struct Timer
{ //estructura para almacenar tiempos de ejecucion
    chrono::system_clock::time_point Start;
    chrono::system_clock::time_point End;
};

// Funciones extra
void PrintTimer(Timer Time);

void WriteListSort(string Filename, vector<int> &A);

template <class Type>
void Swap(Type &x, Type &y)
{ // Intercambiar dos variables
    Type aux = x;
    x = y;
    y = aux;
}

//Iterativo
template <class t>
void InsertionSort(vector<t> &A, int p, int r);

template <class t>
void BubbleSort(vector<t> &A, int p, int r);

//Recursivo
template <class t>
int Reacomodo(vector<t> &A, int p, int r);

template <class t>
void QuickSort(vector<t> &A, int p, int r);

template <class t>
void Merge(vector<t> &A, int p, int q, int r);

template <class t>
void MergeSort(vector<t> &A, int p, int r);

template <class t>
void MergeSortHibrido(vector<t> &A, int p, int r, int k);

// Competencia de Algoritmos
template <class type>
class Competencia
{
private:
    Timer timeA;
    chrono::duration<float, milli> totaltimeA;
    Timer timeB;
    chrono::duration<float, milli> totaltimeB;
    char Algorithm1;
    char Algorithm2;
    vector<type> Input;

public:
    //constructores(existe un bug que no permite inicializar con el constructor vacio)
    Competencia(char Algorithmb = 'I', char Algorithma = 'B')
    { //constructor con dos argumentos
        this->Algorithm1 = Algorithmb;
        this->Algorithm2 = Algorithma;
    }

    Competencia();
    /*Competencia(char Algorithm1 = 'I', char Algorithm2 = 'B', vector<type> Input = NULL)
    { //constructor completo
        this->Algorithm1 = Algorithm1;
        this->Algorithm2 = Algorithm2;
        this->Input = Input;
    }*/

    Competencia<type> &
    setinput(vector<type> in)
    { //cambiar la entrada
        Input = in;
        return *this;
    }

    Competencia &setalgorithm1(char al)
    {
        Algorithm1 = al;
        cout << al;
        return *this;
    }

    Competencia &setalgorithm2(char al)
    {
        Algorithm2 = al;
        return *this;
    }

    Competencia &gettime_algthm1()
    {
        if (Algorithm1 = 'B' || Algorithm1 = 'b')
        {
            timeA.Start = chrono::system_clock::now();
            BubbleSort<type>(Input, Input.begin(), Input.end());
            timeA.End = chrono::system_clock::now();
            totaltimeA = timeA.End - timeA.Start;
        }
        return *this;
    }

    ~Competencia();
};

template <class t>

Competencia<t>::~Competencia()
{
}

template <class t>
Competencia<t>::Competencia()
{
    Algorithm1 = 'B';
    Algorithm2 = 'I';
}

int main(int argc, char const *argv[])
{
    ifstream Fil3In;
    string Arg1;
    Timer time;
    int num;
    vector<int> A;
    Competencia<int> CM('a', 'a');
    if (argv[1] == NULL)
    {
        cout << "ERROR: INGRESE EL NOMBRE O LA RUTA DEL ARCHIVO" << endl;
        exit(-1);
    }
    else
    {
        Arg1 = argv[1];
    }
    cout << "El archivo seleccionado es: " << Arg1 << endl;
    Fil3In.open(Arg1, ios::in);
    if (Fil3In.fail())
    { //si falla al abrir el archivo
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
    }
    while (Fil3In.good())
    { // lee los datos del archivo y los almacena dentro de un vector
        Fil3In >> num;
        A.push_back(num);
    }
    CM.setalgorithm1('B');

    Fil3In.close();

    return 0;
}

void PrintTimer(Timer time)
{ //Imprime el tiempo de ejecucion, recibe como parametros el tiempo medido al inicio y el tiempo final
    chrono::duration<float, milli> TotalTime;
    TotalTime = time.End - time.Start;
    cout << TotalTime.count() << " Ms " << endl;
}

void WriteListSort(string Filename, vector<int> &A)
{ //Escribe la lista ordenada en un archivo
    ofstream Fileout;
    Fileout.open(Filename, ios::out);
    for (int i = 0; i < A.size(); i++)
    {
        Fileout << A.at(i) << endl;
    }
    Fileout.close();
}

//Insertion Sort
template <class t>

void InsertionSort(vector<t> &A, int p, int r)
{
    int j, mano;
    for (int i = p + 1; i <= r; i++)
    {
        mano = A.at(i);
        j = i - 1;
        while (j > 0 && A[j] > mano)
        {
            A[j++] = A[j];
            j--;
        }
        A[j++] = mano;
    }
}

//Bubble Sort
template <class t>
void BubbleSort(vector<t> &A, int p, int r)
{
    for (int i = p; i < r; i++)
    {
        for (int j = p; j < r - 1; j++)
        {
            if (A[j] < A[j++])
            {
                Swap<t>(A[j], A[j++]);
            }
        }
    }
}

//Merge Sort
template <class t>

void Merge(vector<t> &A, int p, int q, int r)
{
    //Crea Arreglos nuevos y copia pedazos
    vector<t> L(A.begin() + p, A.begin() + q + 1);
    vector<t> R(A.begin() + q + 1, A.begin() + r + 1);
    int i = 0; //indiza L
    int j = 0; //indiza R
    int k = p; //indiza A
    while (i < L.size() && j < R.size())
    {
        if (L[i] < R[j])
        {
            A[k++] = L[i++];
        }
        else
        {
            A[k++] = R[j++];
        }
    }
    //Toma el resto
    while (i < L.size())
    {
        A[k++] = L[i++];
    }
    while (j < R.size())
    {
        A[k++] = R[j++];
    }
}

template <class t>

void MergeSort(vector<t> &A, int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) >> 1; //recorrido de bits
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

//Quick Sort
template <class t>

int Reacomodo(vector<t> &A, int p, int r)
{
    int piv = A.at(p);
    int i = p;
    int j = r;
    while (i < j)
    {
        do
        { //Aumenta i hasta encontrar un numero mayor
            //que el pivote
            i++;
        } while (A.at(i) < piv);
        do
        { //decrementa j hasta encontrar un elemento
            //
            j--;
        } while (A.at(j) > piv);
        if (i < j)
        {
            Swap<int>(A[i], A[j]);
        }
    }
    Swap<int>(A[p], A[j]);
    return j;
}
template <class t>

void QuickSort(vector<t> &A, int p, int r)
{
    if (p < r)
    {
        int q = Reacomodo(A, p, r);
        QuickSort(A, p, q);
        QuickSort(A, q + 1, r);
    }
}
