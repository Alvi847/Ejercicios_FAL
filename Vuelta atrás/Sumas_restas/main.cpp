// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include <algorithm>
using namespace std;

struct datos_t
{

    int m;
    vector<int> v;
};

struct sol_t
{
    int calculo;
    vector<int> vSol;
    vector<int> sol_calc;
    bool existe;
};

/**
 * Nuestro arbol de exploración es binario, de altura el tamaño del vector de entrada. El vector solucion tambien tiene el mismo tamaño que el vector de entrada
 */
// función que resuelve el problema
void resolver(const datos_t &datos, sol_t &sol, int k, const vector<int> &acum)
{

    if (datos.v.size() == 0)
    { // Esta es una forma que tengo de manejar el caso en el que datos.v es vacio
        if (sol.calculo == datos.m)
            sol.existe = true;
        return;
    }

    if (sol.existe != true && k < datos.v.size())
    {
        // Sumamos
        sol.vSol[k] = datos.v[k];
        sol.calculo += sol.vSol[k];
        sol.sol_calc[k] = sol.calculo;
        if (sol.calculo == datos.m)
        {
            if (k = datos.v.size() - 1)
                sol.existe = true;
        }
        else if (k < datos.v.size())
        {
            if (acum[k] + sol.calculo >= datos.m && sol.calculo - acum[k] <= datos.m)
                resolver(datos, sol, k + 1, acum);
        }

        sol.calculo -= sol.vSol[k];

        // Restamos
        if (sol.existe != true)
        {

            sol.vSol[k] = datos.v[k];
            sol.calculo -= sol.vSol[k];
            sol.sol_calc[k] = sol.calculo;
            if (sol.calculo == datos.m)
            {
                if (k = datos.v.size() - 1)
                    sol.existe = true;
            }
            else if (k < datos.v.size())
            {
                if (acum[k] + sol.calculo >= datos.m && sol.calculo - acum[k] <= datos.m)
                    resolver(datos, sol, k + 1, acum);
            }

            sol.calculo += sol.vSol[k];
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    datos_t datos;
    int n;
    cin >> datos.m >> n;

    datos.v = vector<int>();

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        datos.v.push_back(a);
    }

    // std::sort(datos.v.begin(), datos.v.end(), std::greater<int>());

    vector<int> acum(n);
    for (int i = 0; i < n; i++)
    {
        acum[i] = datos.v[i];
    }

    for (int i = acum.size() - 1; i > 0; i--)
    {
        acum[i - 1] += acum[i];
    }

    sol_t sol;
    sol.existe = false;
    sol.vSol = vector<int>(n);
    sol.sol_calc = vector<int>(n);

    sol.calculo = 0;
    
    if (datos.v.size() > 0)
    {
        sol.vSol[0] = datos.v[0];
        sol.calculo = datos.v[0];
    }

    resolver(datos, sol, 1, acum);

    if (sol.existe)
        cout << "SI\n";
    else
        cout << "NO\n";
}

int main()
{
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}