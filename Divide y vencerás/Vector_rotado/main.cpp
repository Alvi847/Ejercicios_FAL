// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/**
 * Recurrencia T(n) = c0 si n <= 1; T(n/2) si n > 1
 * 
 * Tras el despliegue => T(n) = T(n/2^k) + k * c1
 * 
 * Complejidad O(log n)
 */
// función que resuelve el problema
int resolver(const vector<int>& v, int ini, int fin) {
    // Casos base
    if (ini == fin)
        return ini;
    if (ini + 1 == fin)
        return ini;
    // Recursión
    else{
        int medio = (ini + fin) / 2;
        if (v[medio] < v[ini]) 
            return resolver(v, medio, fin);
        else
            return resolver(v, ini, medio);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int n;

    cin >> n;

    if (! std::cin)
        return false;
    
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v[i] = a;
    }


    int sol = resolver(v, 0, v.size());
    
    // escribir sol
    if(sol != v.size())
        cout << v[sol] << endl;
    
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