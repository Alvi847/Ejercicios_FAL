// Nombre del alumno Álvaro Cepeda Ramos
// Usuario del Juez FAL-J03


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/**
 * Recurrencia T(m, n) = c0 si m == 1; T(m/2) + f(n) + c1 si m > 1
 * 
 * Coste de función viajes: f(n) = c0 + c1 * n 
 * 
 * n es el número de obras y m, el tamaño del intervalo de soluciones => m = suma de las obras - máximo de las obras
 * 
 * Tras el despliege: T(k) = T(m/2^k) + k(f(n) + c1)
 * 
 * Con esto tenemos una complejidad de la búsqueda binaria de O(log m)
 * 
 * Como con cada búsqueda se invoca la función viajes, con una complejidad de O(n).
 * La complejidad de el algoritmo completo es de O(n log m).
 */
int viajes(const vector<int>& v, int p){
    int ret = 0;
    int pesoAux = p;
    for(int i = 0; i < v.size(); i++){
        if(pesoAux < v[i]){
            pesoAux = p;
            ret++;
        }
        pesoAux -= v[i];
    }
    return ret;
     
}

// función que resuelve el problema
int resolver(int n, int ini, int fin, const vector<int>& v) {
    // Caso base
    if(ini == fin) return ini; // Sólo hay un elemento
    // Recursión
    else{
        int medio = (ini + fin - 1) / 2;
        if(viajes(v, medio) < n)
            return resolver(n, ini, medio, v);
        else
            return resolver(n, medio + 1, fin, v);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, viajes;

    cin >> n >> viajes;

    vector<int> obras(n);

    // Estas dos variables son el límite inferior y superior del espacio de soluciones
    int max = 0;        // Peso máximo
    int suma = 0;       // Suma de todos los pesos

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a > max)
            max = a;
        obras[i] = a;
        suma += a;
    }

    if (n ==  0 && viajes == 0)
        return false;
    
    int sol = resolver(viajes, max, suma, obras); //En este caso el final del intervalo es el último elemento
    
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
