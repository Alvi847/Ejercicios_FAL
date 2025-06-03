// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

using lli = long long int;

/**
 * Recurrencia T(n) = c0 si n == 1 || n == 0; T(n-1) + c1 si n > 1
 * 
 * Despliegue => T(n) = T(n-1) + c1 = T(n-2) + 2c1 = T(n-3) + 3c1
 * 
 * Tras k pasos => T(k) = T(n-k) + k*c1
 * 
 * En el caso base T(1) = n - 1 = k
 * 
 * Función de coste => T(1) + n - 1 * c1
 * 
 * El orden de complejidad es lineal O(n)
 * 
 */

// función que resuelve el problema
lli resolver(int n, int y, lli n1, lli n2) {
    // Caso base
    if (n == 0) return n2;
    if (n == 1) return n1;

    //Recursion
    else{
        return resolver(n - 1, y, (2 * y * n1) - (2 * (n - 1) * n2), n1);
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int n;
    cin >> n;
    if (n == -1)
        return false;
    
    int y;
    cin >> y;

    lli sol = resolver(n, y, 2 * y, 1);
    
    cout << sol << endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
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
