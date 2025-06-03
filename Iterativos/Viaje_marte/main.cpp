// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct viajero_t{

    string nombre;
    int altura;

    bool operator<(viajero_t other) const{
        return nombre < other.nombre;
    }
};

// función que resuelve el problema
int resolver(vector<viajero_t> &v, int u)
{
    int p = 0, q = v.size() - 1;
    while (p <= q)
    {
        if (v[p].altura <= u)
        {
            p++;
        }
        else if (v[q].altura > u)
        {
            q--;
        }
        else
        {
            swap(v[p], v[q]);
            p++;
            q--;
        }
    }
    return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int n, umbral;
    cin >> n >> umbral;
    if (!std::cin)
        return false;

    vector<viajero_t> v;

    for (int i = 0; i < n; i++)
    {
        string a;
        int b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    int sol = resolver(v, umbral);

    // escribir sol

    sort(v.begin(), v.begin() + sol);
    sort(v.begin() + sol, v.end());

    cout << "Bajos: ";
    for (int i = 0; i < sol; i++)
    {
        cout << v[i].nombre << " ";
    }
    cout << "\nAltos: ";
    for (int i = sol; i < v.size(); i++)
    {
        cout << v[i].nombre << " ";
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