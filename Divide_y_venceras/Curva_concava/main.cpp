// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
/**
 * Recurrencia T(n) = c0            si n <= 1 
 *                    T(n/2) + c1   si n > 1
 * 
 * Despliegue: T(k) = T(n/2) + c1 = T(n/2^2) + 2 * c1 = T(n/2^3) + 3 * c1 = T(n/2^k) + k * c1
 * 
 *              k = log2(n)
 * 
 * Orden de complejidad: O(log n)
 */
// función que resuelve el problema
int resolver(const vector<int>& v, int ini, int fin) {
    //casos base
    if(ini == fin) return v[ini]; //vector vacío
    else if (ini + 1 == fin) return v[ini]; //vector de 1 elemento

    //recursión
    else{
        int medio = (ini + fin - 1) / 2;
        if(v[medio] > v[medio + 1])
            return resolver(v, medio + 1, fin); 
        else
            return resolver(v, ini, medio + 1);
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
    
    vector<int> curva(n);

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        curva[i] = a;
    }

    int sol = resolver(curva, 0, curva.size()); //El final es el siguiente al último
    
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