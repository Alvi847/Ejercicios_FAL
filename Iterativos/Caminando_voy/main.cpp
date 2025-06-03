// Nombre del alumno Álvaro Cepeda Ramos
// Usuario del Juez FAL-J03


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


/**
 * 
 *  Precondición : { datos.size > 0 }
 *  resolver(vector<integer>& datos, integer limite) dev boolean ret
 * 
 *  Invariante : {forAll i: 0 < i < datos.size and forAll k1: 0 < k1 < i: datos[i - 1] - datos[cotaInf] > limite }
 * 
 *  Postcondición : {ret = !(Exists k1: 0 < k1 < datos.size: datos[k1] - datos[cotaInf] > limite)}
 */
// función que resuelve el problema
bool resolver(vector<int>& datos, int limite) {
    int i = 1, cotaInf = 0;
    bool ret = true;
    while(i < datos.size() && ret){
        if(datos[i] <= datos[i - 1]){
            ret = (datos[i - 1] - datos[cotaInf]) <= limite;
            cotaInf = i; 
        }
        else if (i == datos.size() - 1){
            ret = (datos[i] - datos[cotaInf]) <= limite;
            cotaInf = i; 
        }
        i++;
    }
    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int limite, cuestas;

    cin >> limite >> cuestas;

    if (! std::cin)
        return false;

    vector<int> datos(cuestas);

    for(int i = 0; i < cuestas; i++){
        cin >> datos[i];
    }
    
    bool sol = resolver(datos, limite);
    
    // escribir sol
    
    if(sol)
        cout << "APTA\n";
    else
        cout << "NO APTA\n";
    
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