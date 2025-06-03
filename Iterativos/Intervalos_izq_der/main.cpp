// Nombre del alumno Álvaro Cepeda Ramos
// Usuario del Juez FAL-J03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
/**
 * Precondición : {datos.size > 0 and 0 < k <= datos.size() and k % 2 == 0}
 *
 * resolver(const vector<integer>& datos, integer k) dev integer intervalosSolucion
 *
 * Invariante 1er bucle: {forall j: 0 <= j < k/2: datos[j] and parteIzq = # s: 0 <= s <= j: datos[s] > 0}
 *
 * Postcondición 1er bucle: {parteIzq = # s: 0 <= s < k/2: datos[s] > 0}
 *
 * Invariante 2o bucle: {forall m: k/2 <= m < k: datos[m] and parteDer = # z: k/2 <= z < m: datos[z] > 0}
 * 
 * Postcondición 2o bucle: {parteDer = # z: k/2 <= z < k: datos[z] > 0}
 * 
 * Invariante 3er bucle: {forall j,m: i <= j <=  i + k/2 and i + k/2 < m < i + k: datos[m] and datos[j]: parteIzq = # s: i <= s <= j: datos[s] > 0 and parteDer = # z: i + k/2 < z < m: datos[z] > 0}
 *
 * Postcondición 3er bucle: {intervalosSolucion = #s, z: k <= s <= z < datos.size: izq(datos, s, k) >= der(datos, z, k)}
 *      donde:
 *              izq(datos, s, k) = # s: i <= s <= i + k/2: datos[s] > 0
 *              der(datos, z, k) = # z: i + k/2 < z <  i + k: datos[z] > 0
 */
// función que resuelve el problema
int resolver(const vector<int> &datos, int k)
{
    int intervalosSolucion = 0, parteIzq = 0, parteDer = 0;
    // Miramos el intervalo inicial
    for (int i = 0; i < k / 2; i++)
    {
        if (datos[i] > 0)
            parteIzq++;
    }
    for (int i = k / 2; i < k; i++)
    {
        if (datos[i] > 0)
            parteDer++;
    }

    if (parteIzq >= parteDer)
        intervalosSolucion++;

    // Empezamos a desplazar el intervalo a lo largo del vector
    for (int i = k; i < datos.size(); i++)
    {
        if (datos[i - k] > 0)
            parteIzq--; // Desplazamos el extremo izquierdo
        if (datos[i - k / 2] > 0)
        {
            parteIzq++; // Desplazamos la mitad del intervalo
            parteDer--;
        }
        if (datos[i] > 0)
            parteDer++; // Desplazamos el extremo derecho

        if (parteIzq >= parteDer)
            intervalosSolucion++; // Si el intervalo desplazado cumple los requisitos de la solución, aumentamos el número de intervalos válidos
    }

    return intervalosSolucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int n, k;
    cin >> n >> k;
    if (n == 0)
        return false;

    vector<int> datos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> datos[i];
    }

    int sol = resolver(datos, k);

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
