#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
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
template <class Type>
void Swap(Type &x, Type &y)
{ // Intercambiar dos variables
    Type aux = x;
    x = y;
    y = aux;
}

int RandomNumber(int range_i, int range_e)
{
    srand(time(NULL));
    int r;
    r = rand() % ((range_e + 1) - (range_i));
    return r;
}
//Iterativo
template <class t>
void SelectionSort(vector<t> &A, int p, int r);

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
void RandomquickSort(vector<t> &A, int p, int r);

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
    int k; //umbral para merge hibrido
    string NameAL1;
    string NameAL2;

public:
    //constructor
    Competencia(char Algorithmb = 'I', char Algorithma = 'B')
    { //constructor con dos argumentos
        this->Algorithm1 = Algorithmb;
        this->Algorithm2 = Algorithma;
    }

    Competencia<type> setinput(vector<type> in)
    { //cambiar la entrada
        Input = in;
        return *this;
    }

    Competencia &setalgorithm1(char al)
    {
        Algorithm1 = al;

        if (al == 'B' || al == 'b')
        {
            NameAL1 = "Bubble Sort";
        }

        if (al == 'I' || al == 'i')
        {
            NameAL1 = "Insertion Sort";
        }

        if (al == 'S' || al == 's')
        {
            NameAL1 = "Selection Sort";
        }

        if (al == 'M' || al == 'm')
        {
            NameAL1 = "Merge Sort";
        }

        if (al == 'Q' || al == 'q')
        {
            NameAL1 = "Quick Sort";
        }

        if (al == 'A' || al == 'a')
        {
            NameAL1 = "Random quick Sort";
        }

        if (al == 'H' || al == 'h')
        {
            NameAL1 = "Merge sort hibrido";
        }

        return *this;
    }

    Competencia &setalgorithm2(char al)
    {
        Algorithm2 = al;

        if (al == 'B' || al == 'b')
        {
            NameAL2 = "Bubble Sort";
        }

        if (al == 'I' || al == 'i')
        {
            NameAL2 = "Insertion Sort";
        }

        if (al == 'S' || al == 's')
        {
            NameAL2 = "Selection Sort";
        }

        if (al == 'M' || al == 'm')
        {
            NameAL2 = "Merge Sort";
        }

        if (al == 'Q' || al == 'q')
        {
            NameAL2 = "Quick Sort";
        }

        if (al == 'A' || al == 'a')
        {
            NameAL2 = "Random quick Sort";
        }

        if (al == 'H' || al == 'h')
        {
            NameAL2 = "Merge sort hibrido";
        }
        return *this;
    }

    void setK(int k)
    {
        this->k = k;
    }

    void gettime_algthm1()
    {
        if (Algorithm1 == 'B' || Algorithm1 == 'b')
        { //obtiene el tiempo de ejecucion del algoritmo 1 y asigana el valor a
            // totaltime expresado en milisegundos
            timeA.Start = chrono::system_clock::now();
            BubbleSort<type>(Input, 0, Input.size() - 1);
            timeA.End = chrono::system_clock::now();
            totaltimeA = timeA.End - timeA.Start;
        }

        if (Algorithm1 == 'I' || Algorithm1 == 'i')
        {
            timeA.Start = chrono::system_clock::now();
            InsertionSort<type>(Input, 0, Input.size() - 1);
            timeA.End = chrono::system_clock::now();
            totaltimeA = timeA.End - timeA.Start;
        }

        if (Algorithm1 == 'S' || Algorithm1 == 's')
        {
            timeA.Start = chrono::system_clock::now();
            SelectionSort<type>(Input, 0, Input.size() - 1);
            timeA.End = chrono::system_clock::now();
            totaltimeA = timeA.End - timeA.Start;
        }

        if (Algorithm1 == 'Q' || Algorithm1 == 'q')
        {
            timeA.Start = chrono::system_clock::now();
            QuickSort<type>(Input, 0, Input.size() - 1);
            timeA.End = chrono::system_clock::now();
            totaltimeA = timeA.End - timeA.Start;
        }

        if (Algorithm1 == 'A' || Algorithm1 == 'a')
        {
            timeA.Start = chrono::system_clock::now();
            RandomquickSort<type>(Input, 0, Input.size() - 1);
            timeA.End = chrono::system_clock::now();
            totaltimeA = timeA.End - timeA.Start;
        }

        if (Algorithm1 == 'H' || Algorithm1 == 'h')
        {
            timeA.Start = chrono::system_clock::now();
            MergeSortHibrido<type>(Input, 0, Input.size() - 1, k);
            timeA.End = chrono::system_clock::now();
            totaltimeA = timeA.End - timeA.Start;
        }

        if (Algorithm1 == 'M' || Algorithm1 == 'm')
        { //obtiene el tiempo de ejecucion del algoritmo 1 y asigana el valor a
            // totaltime expresado en milisegundos
            timeA.Start = chrono::system_clock::now();
            MergeSort<type>(Input, 0, Input.size() - 1);
            timeA.End = chrono::system_clock::now();
            totaltimeA = timeA.End - timeA.Start;
        }
    }

    Timer timeAl1()
    {
        Timer time;
        time.Start = timeA.Start;
        time.End = timeA.End;
        return time;
    }

    void gettime_algthm2()
    {
        if (Algorithm2 == 'B' || Algorithm2 == 'b')
        { //obtiene el tiempo de ejecucion del algoritmo 1 y asigana el valor a
            // totaltime expresado en milisegundos
            timeB.Start = chrono::system_clock::now();
            BubbleSort<type>(Input, 0, Input.size() - 1);
            timeB.End = chrono::system_clock::now();
            totaltimeB = timeB.End - timeB.Start;
        }

        if (Algorithm2 == 'I' || Algorithm2 == 'i')
        {
            timeB.Start = chrono::system_clock::now();
            InsertionSort<type>(Input, 0, Input.size() - 1);
            timeB.End = chrono::system_clock::now();
            totaltimeB = timeB.End - timeB.Start;
        }

        if (Algorithm2 == 'S' || Algorithm2 == 's')
        {
            timeB.Start = chrono::system_clock::now();
            SelectionSort<type>(Input, 0, Input.size() - 1);
            timeB.End = chrono::system_clock::now();
            totaltimeB = timeB.End - timeB.Start;
        }

        if (Algorithm2 == 'Q' || Algorithm2 == 'q')
        {
            timeB.Start = chrono::system_clock::now();
            QuickSort<type>(Input, 0, Input.size() - 1);
            timeB.End = chrono::system_clock::now();
            totaltimeB = timeB.End - timeB.Start;
        }

        if (Algorithm2 == 'A' || Algorithm2 == 'a')
        {
            timeB.Start = chrono::system_clock::now();
            RandomquickSort<type>(Input, 0, Input.size() - 1);
            timeB.End = chrono::system_clock::now();
            totaltimeB = timeB.End - timeB.Start;
        }

        if (Algorithm2 == 'H' || Algorithm2 == 'h')
        {
            timeB.Start = chrono::system_clock::now();
            MergeSortHibrido<type>(Input, 0, Input.size() - 1, k);
            timeB.End = chrono::system_clock::now();
            totaltimeB = timeB.End - timeB.Start;
        }

        if (Algorithm2 == 'M' || Algorithm2 == 'm')
        { //obtiene el tiempo de ejecucion del algoritmo 1 y asigana el valor a
            // totaltime expresado en milisegundos
            timeB.Start = chrono::system_clock::now();
            MergeSort<type>(Input, 0, Input.size() - 1);
            timeB.End = chrono::system_clock::now();
            totaltimeB = timeB.End - timeB.Start;
        }
    }

    Timer timeAl2()
    { //retorna una estructura de timepo
        Timer time;
        time.Start = timeB.Start;
        time.End = timeB.End;
        return time;
    }

    void detwinner()
    { //compara los tiempos de A y B para determinar un ganador
        if (totaltimeA < totaltimeB)
        {
            cout << "¡El ganador es " << NameAL1 << " !" << endl;
        }
        else
        {
            cout << "¡El ganador es " << NameAL2 << " !" << endl;
        }
    }

    void printtime1()
    {
        cout << totaltimeA.count() << "Ms" << endl;
    }

    void printtime2()
    {
        cout << totaltimeB.count() << "Ms" << endl;
    }

    string getnameal1()
    {
        return NameAL1;
    }

    string getnameal2()
    {
        return NameAL2;
    }

    void restart()
    {
        Algorithm1 = ' ';
        Algorithm1 = ' ';
        totaltimeA.zero();
        totaltimeB.zero();
    }

    ~Competencia();
};

template <class t>

Competencia<t>::~Competencia()
{
}

int main(int argc, char const *argv[])
{
    ifstream Fil3In;
    string Arg1;
    Timer time;
    int num;
    vector<int> A; //entrada
    vector<int> C;
    Competencia<int> CM;
    char Al1, Al2;
    int k;
    char rep;
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

    //Competencia
    do
    {
        C = A; //copia del arreglo A
        cout << "COMPETENCIA DE ALGORITMOS" << endl;
        cout << "Seleccione los algoritmos que van a competir: " << endl;
        cout << "Bubble sort       B" << endl;
        cout << "Insertion sort    I" << endl;
        cout << "Selection sort    S" << endl;
        cout << "Quick sort        Q" << endl;
        cout << "Merge sort        M" << endl;
        cout << "Quick sort al.    A" << endl;
        cout << "Merge hibrido     H" << endl;
        cin >> Al1 >> Al2; // para ingresar los algoritmos(ejemplo: B A)
        if ((Al1 == 'h' || Al1 == 'H') || (Al2 == 'h' || Al2 == 'H'))
        { //pregunta en que tamaño los problemas se resuelven por insercion
            cout << "Ingresa el valor de k" << endl;
            cin >> k;
            CM.setK(k);
        }
        CM.setalgorithm1(Al1).setalgorithm2(Al2).setinput(C);
        CM.gettime_algthm1();
        CM.gettime_algthm2();
        CM.detwinner();
        cout << "Tiempo de ejecucion de  " << CM.getnameal1() << endl;
        CM.printtime1();
        cout << "Tiempo de ejecucion de  " << CM.getnameal2() << endl;
        CM.printtime2();
        cout << "Repetir la competencia? (S/N) " << endl;
        cin >> rep;
        CM.restart();
    } while (rep == 'S' || rep == 's');
    Fil3In.close();

    return 0;
}

//selection sort
template <class t>
void SelectionSort(vector<t> &A, int p, int r)
{
    int min;
    for (int i = p; i < r - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < r; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        Swap<t>(A[i], A[min]);
    }
}

//*Insertion Sort
template <class t>
void InsertionSort(vector<t> &A, int p, int r)
{
    t key;
    int i, j;
    for (j = p + 1; i < r; i++)
    {
        key = A[j];
        i = j--;
        while (i >= p && A[i] > key)
        {
            A[i++] = A[i];
            i--;
        }
        A[i++] = key;
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

template <class t>
void MergeSortHibrido(vector<t> &A, int p, int r, int k)
{
    int q;
    if (k < r - p)
    {
        q = (p + r) >> 1; //recorrido de bits
        MergeSortHibrido(A, p, q, k);
        MergeSortHibrido(A, q + 1, r, k);
        Merge(A, p, q, r);
    }
    else
    {
        InsertionSort<t>(A, p, r);
    }
}
//*Quick Sort
template <class t>
int Reacomodo(vector<t> &A, int p, int r)
{
    t piv = A[p];
    int i = p;
    int j = r;
    while (i < j)
    {
        do
        {
            i++;
        } while (A[i] <= piv);

        do
        {
            j--;
        } while (A[j] > piv);

        if (i < j)
        {
            Swap<t>(A[i], A[j]);
        }
    }
    Swap<t>(A[p], A[j]);
    return j;
}

template <class t>
void QuickSort(vector<t> &A, int p, int r)
{
    int q;
    if (p < r)
    {
        q = Reacomodo<t>(A, p, r);
        QuickSort(A, p, q);
        QuickSort(A, q + 1, r);
    }
}

template <class t>
void RandomquickSort(vector<t> &A, int p, int r)
{
    int al;
    int q;
    if (p < r)
    {
        al = RandomNumber(p, r);
        Swap<t>(A[p], A[al]);
        q = Reacomodo<t>(A, p, r);
        RandomquickSort(A, p, q);
        RandomquickSort(A, q + 1, r);
    }
}