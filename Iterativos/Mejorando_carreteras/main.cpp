// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> &v)
{
    // Ordenamos v
    sort(v.begin(), v.end());

    int aparicionesActuales = 0;
    int maxApariciones = 0;
    int moda = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1])
        {
            aparicionesActuales++;
        }
        else
        {
            if (aparicionesActuales > maxApariciones)
            {
                maxApariciones = aparicionesActuales;
                moda = v[i - 1];
            }
            aparicionesActuales = 0;
        }
    }
    if (aparicionesActuales > maxApariciones)
    {
        maxApariciones = aparicionesActuales;
        moda = v[v.size() - 1];
        aparicionesActuales = 0;
    }

    return moda;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == -1)
        return false;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int sol = resolver(v);

    // escribir sol

    cout << sol << endl;

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
