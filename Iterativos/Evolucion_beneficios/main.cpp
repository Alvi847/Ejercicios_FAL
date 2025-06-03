// Nombre del alumno Álvaro Cepeda Ramos
// Usuario del Juez FAL-J03


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


/**
 * El vector datos contiene las ventas y el vector sol contiene los indices de datos cuyos valores son mayores que los valores anteriores 
 * 
 * Precondición (P): {datos.size > 0 and datos.size == segundoAnno - primerAnno + 1}
 * 
 * resolver(vector<integer> datos) dev vector<integer> sol 
 * 
 * Invariante (I): {forAll k1 0 <= k1 < sol.size and 0 <= i < datos.size : maxi = max k2: 0 <= k2: datos[k2] datos[sol[k1]] <= maxi}
 * 
 * Postcondición (Q): {forAll k1: 0 <= k1 < sol.size: datos[sol[k1]] > max k2: 0 <= k2 < sol[k1]: datos[k2]}
 */
// función que resuelve el problema
vector<int> resolver(const vector<int>& datos) {
    int maxi = datos[0];
    vector<int> sol;

    for(int i = 0; i < datos.size(); i++){
        if(datos[i] > maxi){
            sol.push_back(i);
            maxi = datos[i];
        }
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int primerAnno, segundoAnno;

    cin >> primerAnno >> segundoAnno;
    
    vector<int> ventas(0);

    for(int i = 0;  i <= segundoAnno - primerAnno; i++){
        int a;
        cin >> a;
        ventas.push_back(a);
    }
    
    vector<int> sol = resolver(ventas);
        
    for(int i = 0; i < sol.size(); i++){
        cout << sol[i] + primerAnno << " ";
    }
    
    cout << endl;
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