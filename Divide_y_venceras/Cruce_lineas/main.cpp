// Nombre del alumno Álvaro Cepeda Ramos
// Usuario del Juez FAL-J03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct sol_t
{
    bool cortan;
    pair<int, int> punto;
};

/**
 * Recurrencia: T(n) = c0 si n <= 1; T(n/2) + c1 si n > 1;
 *
 * Despliegue: T(n) = T(n/2) + c1 = (T(n/2^2) + c1) + c1 = (T(n/2^3) + c1) + 2 * c1 = (T(n/2^4) + c1) + 3 * c1 = T(n/2^5) + 5 * c1
 * 
 * Tras el despliegue (tras k pasos) T(k) = T(n/2^k) + k * c1
 *
 * Complejidad O(log n)
 */

// función que resuelve el problema
sol_t resolver(const vector<int> &v1, const vector<int> &v2, int ini, int fin)
{
    // Casos base
    if (ini == fin)
        return {false, {0, 0}};
    if (ini + 1 == fin)
    {
        if (v2[ini] == v1[ini])
            return {true, {ini, ini}};
        else
        {
            if (v1[ini] < v2[ini])
                return {false, {ini, ini + 1}};
            else
                return {false, {ini - 1, ini}};
        }
    }

    // Recursión
    else
    {
        int medio = (ini + fin - 1) / 2;
        // cout << "ini " << ini << ", fin " << fin << endl;
        if (v1[medio] < v2[medio])
            return resolver(v1, v2, medio + 1, fin);
        else
            return resolver(v1, v2, ini, medio + 1);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada

    int n;
    cin >> n;

    if (n == 0)
        return false;

    vector<int> prim_serie(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        prim_serie[i] = a;
    }

    vector<int> seg_serie(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        seg_serie[i] = a;
    }

    sol_t sol = resolver(prim_serie, seg_serie, 0, n);

    if (sol.cortan)
        cout << "SI " << sol.punto.first << endl;
    else
        cout << "NO " << sol.punto.first << " " << sol.punto.second << endl;

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
