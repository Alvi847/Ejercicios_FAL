// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void mostrar_solucion(vector<int> sol){
    for(int i = 0; i < sol.size(); i++){
        switch(sol[i]){
            case 0:
                cout << "azul ";
                break;
            case 1:
                cout << "rojo ";
                break;
            case 2:
                cout << "verde ";
                break;
        }
    }
    cout << endl;
}

// función que resuelve el problema
void resolver(int piezas, int k, int colores, vector<int>& sol) {
    for(int i = 0; i < colores; i++){
        sol[k] = i;
        if(k == piezas - 1){
            mostrar_solucion(sol);
        }
        else
            resolver(piezas, k + 1, colores, sol);
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int piezas;
    cin >> piezas;
    if (piezas == 0)
        return false;
    
    vector<int> sol(piezas);

    resolver(piezas, 0, 3, sol);
    
    cout << endl;
    
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
