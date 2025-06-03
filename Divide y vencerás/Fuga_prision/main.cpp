// Nombre del alumno Álvaro Cepeda Ramos
// Usuario del Juez FAL-J03


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/**
 * Recurrencia: T(n) = c0 si n <= 1; T(n/2) si n > 1; siendo n el tamaño del vector de entrada
 * 
 * Tras el despliegue => T(n) = T(n/2^k) + k * c1
 * 
 * Complejidad O(log n)
 */
// función que resuelve el problema
char resolver(const vector<char>& v, int ini, int fin, int primero) {
    // Caso base, no pongo el caso del vector vacío porque no hay un pabellón sin presos 
    int medio = (ini + fin - 1) / 2;
    if(ini + 1 == fin){                 
        if (v[medio] - primero == medio)    //Si el que falta es el último preso, devolvería el último elemento del vector 
        {                                   // que es el último de los presos que SI están (el de la izquierda)
            return ini + primero + 1;       // así que para devolver el preso correcto, sumo 1
        }
        
        return ini + primero;
    }
    // Recursión
    else{
        if(v[medio] - primero != medio)
            return resolver(v, ini, medio + 1, primero);
        else
            return resolver(v, medio + 1, fin, primero);
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    char prim, ult;

    cin >> prim >> ult;

    vector<char> presos(ult-prim);

    for(int i = 0; i < ult - prim; i++){
        char a;
        cin >> a;
        presos[i] = a;
    }
    
    char sol = resolver(presos, 0, presos.size(), prim);
    // escribir sol

    cout << sol << endl; 
    
    
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