// Nombre del alumno Álvaro Cepeda
// Usuario del Juez FAL-J03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct objeto_t
{
    int coste;
    int superficie;
    int indice;
};

struct datos_t
{

    int numObjetos;
    vector<objeto_t> objetos;
    int presupuesto;
};

struct sol_t
{

    int coste;
    int supActual;
    vector<bool> sol;
    vector<bool> solMejor;
    int maxSup;
};

class Comparador
{
public:
    bool operator()(const objeto_t &p1, const objeto_t &p2)
    {
        return (float)p1.superficie / p1.coste > (float)p2.superficie / p2.coste;
    }
};

// función que resuelve el problema
void resolver(const datos_t &d, sol_t &s, int k)
{
    // Ponemos el objeto
    s.sol[k] = true;
    s.coste += d.objetos[k].coste;
    if (s.coste <= d.presupuesto)
    {
        s.supActual += d.objetos[k].superficie;
        if (k == d.numObjetos - 1)
        {
            if (s.supActual > s.maxSup)
            {
                s.maxSup = s.supActual;
                s.solMejor = s.sol;
            }
        }
        else
            resolver(d, s, k + 1);
        s.supActual -= d.objetos[k].superficie;
    }
    s.coste -= d.objetos[k].coste;

    // No ponemos el objeto
    s.sol[k] = false;
    if (k == d.numObjetos - 1)
    {
        if (s.supActual > s.maxSup)
        {
            s.maxSup = s.supActual;
            s.solMejor = s.sol;
        }
    }
    else
        resolver(d, s, k + 1);
}

int inicializarMejorSup(const datos_t &d, sol_t &s)
{
    int i = 0, sumSup = 0, sumCoste = 0;
    while (i < d.objetos.size() && sumCoste + d.objetos[i].coste <= d.presupuesto)
    {
        sumSup += d.objetos[i].superficie;
        sumCoste += d.objetos[i].coste;
        s.solMejor[i] = true;
        i++;
    }
    return sumSup;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada

    datos_t datos;
    cin >> datos.numObjetos >> datos.presupuesto;

    if (!std::cin)
        return false;

    datos.objetos = vector<objeto_t>(datos.numObjetos);
    for (int i = 0; i < datos.numObjetos; i++)
    {
        cin >> datos.objetos[i].coste >> datos.objetos[i].superficie;
        datos.objetos[i].indice = i;
    }

    //sort(datos.objetos.begin(), datos.objetos.end(), Comparador());

    sol_t solucion;
    solucion.sol = vector<bool>(datos.numObjetos);
    solucion.solMejor = vector<bool>(datos.numObjetos);
    //solucion.maxSup = inicializarMejorSup(datos, solucion);
    solucion.maxSup = 0;
    solucion.coste = 0;
    solucion.supActual = 0;

    resolver(datos, solucion, 0);

    cout << solucion.maxSup << endl;
    for (int i = 0; i < solucion.solMejor.size(); i++)
    {
        if (solucion.solMejor[i])
            cout << datos.objetos[i].indice << " ";
    }
    cout << endl;

    return true;
}

int main()
{
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}