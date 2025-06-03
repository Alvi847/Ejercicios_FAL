// Nombre del alumno Álvaro Cepeda Ramos
// Usuario del Juez FAL-J03


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/**
 * Recurrencia T(n) = c0 si n <= 1; 2*T(n/2) + c1 si n > 1
 * 
 * Despliegue: T(n) = 2*T(n/2) + c1 = 2 * (2*T(n/2^2) + c1) + c1 = 2^2 * T(n/2^2) + 3 * c1 = 2^2 * (2 * T(n/2^3) + c1) + 3 * c1
 *  = 2^3 * T(n/2^3) + 7 * c1
 * 
 * Tras k pasos: T(k) = 2^k * T(n/2^k) + (2^k - 1) * c1
 * 
 * T(1) => n/2^k = 1 => k = log2 n
 * 
 * T(n) = 2^log2(n) * T(1) + (2^log2(n) - 1) * c1 = n * O(1) + (n - 1) * c1 
 * 
 * Entonces, el orden de complejidad es O(n) 
 */
// función que resuelve el problema
pair<bool, int> resolver(const vector<int>& v, int ini, int fin) {
    // Casos base
    if(ini == fin) return {false, 0};
    if(ini + 1 == fin){
        if(v[ini] % 2 == 0)
            return {true, 1};
        else
            return {true, 0};
    }

    // Recursión    
    else{
        int medio = (ini + fin - 1) / 2;
        
        pair<bool, int> der = resolver(v, medio + 1, fin);
        pair<bool, int> izq = resolver(v, ini, medio + 1);

        return {der.first && izq.first && abs(der.second - izq.second) <= 2, der.second + izq.second};
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
    
    vector<int> numeros(n);

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        numeros[i] = a;
    }


    pair<bool, int> sol = resolver(numeros, 0, numeros.size());
    
    if(sol.first)
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
