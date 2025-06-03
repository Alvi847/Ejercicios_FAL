// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
long resolver(long n) {
    // Caso Base
    if(n < 10) {
        if(n == 0)
            return 1;
        return (n);
    }

    // Recursión
    else
        if(((n / 10) % 10) != 1)
            return resolver(n / 10) * 9 - (9 - (n % 10));
        else
            return resolver(n / 10) * 9;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long n;
    cin >> n;

    if (! std::cin)
        return false;
    
    long sol = resolver(n);
    
    // escribir sol
    
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