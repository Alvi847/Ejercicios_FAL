// Nombre del alumno Álvaro Cepeda Ramos
// Usuario del Juez FALJ-03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/**
 * Recurrencia T(m, n) = c0 si m == 1; T(m/2) + f(n) + c1 si m > 1
 * 
 * Coste de función descansos: f(n) = c0 + c1 * n 
 * 
 * n es el número de tramos y m, el tamaño del intervalo de soluciones => m = suma de los tiempos de cada tramo - tiempo máximo de tramo
 * 
 * Tras el despliege: T(k) = T(m/2^k) + k(f(n) + c1)
 * 
 * Con esto tenemos una complejidad de la búsqueda binaria de O(log m)
 * 
 * Como con cada búsqueda se invoca la función descansos, con una complejidad de O(n).
 * La complejidad de el algoritmo completo es de O(n log m).
 */
int descansos(const vector<int> &v, int m)
{
    int ret = 0;
    int tiempoAux = m;
    for (int i = 0; i < v.size(); i++)
    {
        if (tiempoAux < v[i])
        {
            tiempoAux = m;
            ret++;
        }
        tiempoAux -= v[i];
    }
    return ret;
}

// función que resuelve el problema
int resolver(int descansosMax, int ini, int fin, const vector<int> &v)
{
    // Casos base
    if (ini == fin) // Intervalo vacío
        return ini;
    if (ini + 1 == fin) // Intervalo con un elemento
        return ini;
    // Recursión
    else
    {
        int medio = (ini + fin - 1) / 2;
        if (descansos(v, medio) > descansosMax)
            return resolver(descansosMax, medio + 1, fin, v);
        else
            return resolver(descansosMax, ini, medio + 1, v);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int n, p;

    cin >> n >> p;

    if (n == 0 && p == 0)
        return false;

    int suma = 0; // Suma de todos los tiempos
    int max = 0;  // Tiempo máximo

    vector<int> tramos(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        tramos[i] = a;
        suma += a;
        if (max < a)
            max = a;
    }

    int sol = resolver(p, max, suma + 1, tramos); // En este caso suma + 1 es el limite del intervalo (el final se considera el siguiente al último)

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
