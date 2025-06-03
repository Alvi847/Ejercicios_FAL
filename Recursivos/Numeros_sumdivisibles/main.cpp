// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct sol_t{
    bool sumdivisible;
    int digitos;
    int suma;
};

/**
 * El orden de este algoritmo
 */

// función que resuelve el problema
 sol_t resolver(int n) {
    if (n < 10){
        return {true, 1, n};
    }
    sol_t aux = resolver(n / 10);
    aux.suma += n % 10;
    aux.digitos++;
    if(!(aux.sumdivisible && 
    aux.suma % aux.digitos == 0))
        aux.sumdivisible = false;
    return aux;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;
    
   sol_t sol = resolver(n);
    
    // escribir sol
    if (sol.sumdivisible)
        cout << "SI\n";
    else
        cout << "NO\n";
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
