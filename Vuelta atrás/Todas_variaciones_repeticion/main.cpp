// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector> 

using namespace std;


void mostrar_sol(vector<char> sol){
    for(char a : sol){
        cout << a;
    }
    cout << endl;
}

// función que resuelve el problema
void resolver(int m, int k, int n, vector<char>& sol) {
    for(char i = 'a'; i < ('a' + m); i++){
        sol[k] = i;
        if(k == n - 1){
            mostrar_sol(sol);
        }
        else
            resolver(m, k + 1, n, sol);
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    cin >> m >> n;
    if (! std::cin)
        return false;
    vector<char> sol(n);
    resolver(m, 0, n, sol);    
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