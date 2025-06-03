// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>


using TipoSolucion = int;

// función que resuelve el problema
TipoSolucion mcd(const int& a, const int&b) {
    //Caso base
    if(b == 0)
        return a;
    
    TipoSolucion sol = mcd(b, a % b);

    return sol;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a, b;

    std::cin >> a >> b;
    
    if (a == 0 && b == 0)
        return false;
    
    TipoSolucion sol = mcd(a, b);
    
    // escribir sol
    
    std::cout << sol << std::endl;

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
