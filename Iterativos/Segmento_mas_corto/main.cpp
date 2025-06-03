// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct seg_t
{
    int inicio;
    unsigned int longitud;
};

// función que resuelve el problema
int resolver(int k, const vector<bool> &v)
{
    seg_t aux = {0, 0};
    seg_t min = {0, v.size() + 1};
    int valores_encontrados = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i])
        {
            valores_encontrados++;
            if (valores_encontrados == 1)
            {
                aux.inicio = i;
            }
            if (valores_encontrados == k)
            {
                aux.longitud = i - aux.inicio + 1;
                if (min.longitud > aux.longitud)
                {
                    min.longitud = aux.longitud;
                    min.inicio = aux.inicio;
                }
                int j = aux.inicio + 1;
                while(j < v.size(), !v[j])j++;
                aux.inicio = j;
                aux.longitud = 0;
                valores_encontrados = k - 1;
            }
        }
    }
    return min.longitud;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada

    int n, k;
    cin >> n;

    if (n == -1)
        return false;

    vector<bool> v;
    for (int i = 0; i < n; i++)
    {
        bool a;
        cin >> a;
        v.push_back(a);
    }

    cin >> k;
    int sol = resolver(k, v);

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
