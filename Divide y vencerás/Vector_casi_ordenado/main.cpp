// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct sol_t{
    bool parOrdenado;
    int min;
    int max;
};

/**
 * Recurrecia: T(n) = c1 si n <= 1; 2T(n/2) + c1 si n > 1
 * 
 * Despliegue => T(n) = 2T(n/2) + c1 = 2(2T(n/2^2) + c1) + c1 = 2^2 * T(n/2^2) + 3c1 = 2^2 * (2T(n/2^3) + c1) + 3c1 = 2^3 * T(n/2^3) + 7 * c1 = 
 *              = 2^3 * (2T(n/2^4) + c1) + 7 * c1 = 2^4 * T(n/2^4) + 15 * c1
 * Tras el despliegue (k pasos) => T(k) = 2^k * T(n/2^k) + (2^k - 1) * c1
 * 
 * En el caso base T(1) => n/2^k = 1 => k = log2 (n)
 * 
 *  T(n) = 2^log2(n) * T(n/2^log2(n)) + (2^log2(n) - 1) * c1
 *          = n * T(1) + (n - 1) * c1
 * 
 * Con esto vemos que el algoritmo tiene una complejidad lineal con respecto a n O(n), siendo n el número de elementos del vector de entrada
 *             
 * 
 */

// función que resuelve el problema
sol_t resolver(const vector<int>& v, int ini, int fin) {
    // Caso base
    if(ini == fin) return {true, 0, 0};
    if(ini + 1 == fin) return {true, v[ini], v[ini]};

    // Recursión
    else{
        int medio = (ini + fin - 1) / 2;
        
        sol_t izq = resolver(v, ini, medio + 1);
        sol_t der = resolver(v, medio + 1, fin);

        return {der.parOrdenado && izq.parOrdenado && der.max >= izq.max && izq.min <= der.min, izq.min, der.max};
    } 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;
    
    vector<int> v;

    while(n != 0){
        v.push_back(n);
        cin >> n;
    }

    sol_t sol = resolver(v, 0, v.size());

    if(sol.parOrdenado)
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
