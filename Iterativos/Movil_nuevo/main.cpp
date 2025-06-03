// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector<int> resolver(const vector<int> &a, const vector<int> &b)
{
    vector<int> mezcla;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            mezcla.push_back(a[i]);
            i++;
        }
        else if (a[i] > b[j])
        {
            mezcla.push_back(b[j]);
            j++;
        }
        else
        {
            mezcla.push_back(b[j]);
            j++;
            i++;
        }
    }

    while (i < a.size())
    {
        mezcla.push_back(a[i]);
        i++;
    }

    while (j < b.size())
    {
        mezcla.push_back(b[j]);
        j++;
    }

    return mezcla;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int n, m;
    cin >> n >> m;
    vector<int> a;
    vector<int> b;

    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        a.push_back(c);
    }
    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;
        b.push_back(c);
    }

    vector<int> sol = resolver(a, b);
    // escribir sol

    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    cout << endl;
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