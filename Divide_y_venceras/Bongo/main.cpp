// Nombre del alumno Álvaro Cepeda Ramos
// Usuario del Juez FAL-J03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/**
 * La recurrencia de mi solución es: T(n) = c0 si n = 1 || n = 0; c1 + T(n/2) si n > 1; Siendo n el tamaño del vector de entradaa
 * 
 * Tras el despliegue T(n) = T(n/2^k) + k * c1
 * 
 * Con T(1) => k = log(n) => La complejidad es O(log n)
 * 
 */

// Función que resuelve el problema
int resolver(const vector<int> &v, int ini, int fin, int valor)
{
    // Casos base
    if (ini == fin) // Vector vacío
    return ini;
    if (ini + 1 == fin) // Vector de 1 elemento
    return ini;
    // Recursión
    else
    {
        int medio = (ini + fin) / 2;
        if (valor + medio < v[medio])
            return resolver(v, ini, medio, valor);
        else
            return resolver(v, medio, fin, valor);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // Leer los datos de la entrada
    int n, cajero;
    cin >> n >> cajero;

    vector<int> numeros(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        numeros[i] = a;
    }

    int sol = resolver(numeros, 0, numeros.size(), cajero); // El final es el siguiente al último elemento
    // escribir sol
    if (sol != numeros.size() && cajero + sol == numeros[sol])
        cout << numeros[sol] << endl;
    else
        cout << "NO\n";
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