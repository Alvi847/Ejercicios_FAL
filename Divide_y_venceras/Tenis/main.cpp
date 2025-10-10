// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct sol_t
{
    int partidos;
    int ronda;
    bool hayJugadores;
};
/**
 * Recurrencia T(n) = c0 si n <= 2; 2T(n/2) + c1 si n >= 4
 * 
 * Tras el despliegue => T(k) = 2^k * T(n/2^k) + (2^k - 1) * c1
 * 
 * En el caso base T(1) k = log2(n) => T(1) = n * T(1) + (n - 1) * c1
 * 
 * Orden O(n) Siendo n el número de jugadores del torneo, contando los no presentados
 */
// función que resuelve el problema
sol_t resolver(const vector<bool> &v, int ini, int fin, int ronda)
{
    // Casos base
    if (ini == fin)
        return {0, 1, false};
    if (ini + 1 == fin)
        return {0, 1, true};
    if (ini + 2 == fin)
    {
        if (v[ini] && v[ini + 1])
        {
            return {1, 1, true};
        }
        else
            return {0, 1, v[ini] || v[ini + 1]};
    }

    // Recursión
    else
    {
        int medio = (ini + fin - 1) / 2;

        sol_t der = resolver(v, medio + 1, fin, ronda);
        sol_t izq = resolver(v, ini, medio + 1, ronda);
        int partidos = der.partidos + izq.partidos;
        if (der.ronda < ronda)
        {
            if (der.hayJugadores && izq.hayJugadores)
                partidos++;
        }
        return {partidos, der.ronda + 1, der.hayJugadores || izq.hayJugadores};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int n, ronda;
    cin >> n >> ronda;

    if (!std::cin)
        return false;

    vector<bool> torneo(n);
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        if (a == "NP") // Como el jugador en sí no importa he hecho esto, lo veía más claro así
            torneo[i] = false; // Jugador no presentado
        else
            torneo[i] = true; // Jugador presentado
    }

    sol_t sol = resolver(torneo, 0, n, ronda); // El final es el siguiente al último

    cout << sol.partidos << endl;

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