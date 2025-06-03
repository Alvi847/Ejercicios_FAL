// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct cinta_t
{

    char color;
    int longitud;

    bool operator<(const cinta_t &other) const
    {
        return longitud < other.longitud;
    }
};

// función que resuelve el problema
pair<int, int> resolver(vector<cinta_t> &v)
{
    int p = 0, k = 0, q = v.size() - 1; // p -> azules, k -> verdes, q -> rojas 
    /*con los indices, un ejemplo de cinta partida tiene esta forma:*/
    /* a a a a a a a | p | v v v v v v v | q | k | r r r r r r r r */
    /*De v[0] a v[p], son azules, de v[p] a v[q], verdes y de v[q] al final son rojos*/
    while (k <= q)
    {
        if (v[k].color == 'v')
        {
            k++;
        }
        else if(v[k].color == 'a')
        {
            swap(v[k], v[p]);
            p++;
            k++;
        }
        else
        {
            swap(v[k], v[q]);
            q--;
        }
    }
    return {p, q};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;

    vector<cinta_t> v;

    for (int i = 0; i < n; i++)
    {
        char a;
        int b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    pair<int, int> sol = resolver(v);

    // escribir sol

    sort(v.begin(), v.begin() + sol.first);
    sort(v.begin() + sol.first, v.begin() + sol.second + 1);
    sort(v.begin() + sol.second + 1, v.end());

    cout << "Azules: ";
    for (int i = 0; i < sol.first; i++)
    {
        cout << v[i].longitud << " ";
    }
    cout << "\nVerdes: ";
    for (int i = sol.first; i < sol.second + 1; i++)
    {
        cout << v[i].longitud << " ";
    }
    cout << "\nRojas: ";
    for (int i = sol.second + 1; i < v.size(); i++)
    {
        cout << v[i].longitud << " ";
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