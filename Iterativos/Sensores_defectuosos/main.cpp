// Nombre del alumno Álvaro Cepeda Ramos
// Usuario del Juez FAL-J03


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


/**
 * 
 * Precondición : {datos.size > 0}
 * 
 * resolver(vector<long long>& datos, long long valor) dev integer correctos
 * 
 * Invariante : {forall k2: 0 <= k2 < i - veces_encontrado: datos[k2] != valor }
 * 
 * Postcondición : {forall k1: 0 <= k1 < (datos.size - veces_encontrado): datos[k1] != valor }
 * 
 */
// función que resuelve el problema
int resolver(vector<long long>& datos, long long valor) {
    int veces_encontrado = 0;
    for(int i = 0; i < datos.size(); i++){
        if(datos[i] == valor)
            veces_encontrado++;
        else if(veces_encontrado > 0){
            datos[i - veces_encontrado] = datos[i];
        }
    }

    int correctos = datos.size() - veces_encontrado;

    datos.resize(correctos);

    return correctos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int medidas;
    long long erroneo;

    cin >> medidas >> erroneo;

    vector<long long> datos(medidas);

    for(int i = 0; i < medidas; i++){
        cin >> datos[i];
    }
    
    long long correctos = resolver(datos, erroneo);
    // escribir sol
    
    cout << correctos << endl;

    for(int i = 0; i < datos.size(); i++){
        cout << datos[i] << " ";
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