// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector<int> resolver(const vector<int> &v, int l)
{
    int pivote = 0;
    int fin = 0, longitud = 0, longitudAux = 0;
    vector<int> sol;
    for (int i = fin; i < v.size(); i++)
    {
        if ((v[fin] > v[pivote]) > 1)
        {
            while (longitud > 0)
            {
                longitud--;
                if ((v[fin - longitud] > v[pivote]) > 1)
                    longitudAux++;
                else if (longitudAux == l)
                    sol.push_back(v[fin - longitud]);
            }
            pivote = fin;
        }
        else
        {
            longitud++;
            if (longitud == l)
            {
                sol.push_back(pivote);
            }
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int n, l;
    cin >> n >> l;

    if (n == 0 && l == 0)
        return false;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    vector<int> sol = resolver(v, l);

    // escribir sol

    cout << sol.size() << " ";
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
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
