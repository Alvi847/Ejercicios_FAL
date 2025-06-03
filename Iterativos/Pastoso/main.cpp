// Nombre del alumno Álvaro Cepeda Ramos
// Usuario del Juez FAL-J03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/**
 * Precondición : {datos.size > 0}
 * resolver(vector<integer>& datos) dev boolean and integer
 * 
 * Invariante : {forAll i : 0 <= i < datos.size : suma == sum k1: i <= k1 < datos.size: datos[k1]}
 *
 * Postcondición : {ret.first == Exists i: 0 <= i < datos.size: i = sum(i, datos.size) and ret.second == i }
 *      Donde: sum(i, datos.size) = sum k1: i < k1 < datos.size
 */
// función que resuelve el problema
pair<bool, int> resolver(vector<int> datos)
{
    int i = datos.size() - 1;
    pair<bool, int> ret;
    ret.first = false;
    int suma = 0;
    while(i >= 0 && !ret.first){
        if(datos[i] == suma){
            ret.first = true;
            ret.second = i;
        }
        suma += datos[i];
        i--;
    }
    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int longitud;
    cin >> longitud;

    vector<int> datos(longitud);

    for (int i = 0; i < longitud; i++)
    {
        cin >> datos[i];
    }
    pair<bool, int> sol = resolver(datos);
    // escribir sol

    if (sol.first)
        cout << "Si " << sol.second << endl;
    else
        cout << "No\n";
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