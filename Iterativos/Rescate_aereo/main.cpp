// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
pair<int, int> resolver(const vector<int> &v, int t)
{
    int ini = 0, longitud = 0;
    int iniMax = -1, longitudMax = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > t)
        {
            longitud++;
            if (longitudMax < longitud)
            {
                iniMax = i + 1 - longitud;
                longitudMax = longitud;
            }
        }
        else
        {
            longitud = 0;
        }
    }
    return {iniMax, longitudMax - 1 + iniMax};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int n, t;
    cin >> n >> t;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    pair<int, int> sol = resolver(v, t);
    // escribir sol

    cout << sol.first << " " << sol.second << endl;
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