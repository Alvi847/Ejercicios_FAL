// Nombre del alumno Álvaro Cepeda Ramos    
// Usuario del Juez FAL-J03


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/**
 * recurrencia: T(n) = {2 si n < 10, 3 * T(n/10) si n >= 10}
 */

// función que resuelve el problema
pair<int, int> resolver(int n) {
    //caso base
    if (n < 10){
        if(n == 1)
            return {1, n};
        else
            return {0, n};
    }
    int digito = n % 10;
    pair <int, int> aux = resolver(n / 10);
    if(aux.second != digito)
        return {aux.first, (aux.second * digito) % 10};
    else
        return {aux.first + 1, (aux.second * digito) % 10};
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    
    pair<int, int> sol = resolver(n);
    // escribir sol
    cout << sol.first << endl;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
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