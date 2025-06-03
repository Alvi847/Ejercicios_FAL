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
/**
 * El arbol de exploración son todas las combinaciones de letras
 * Cada hijo de un nodo en el arbol una letra
 *
 * El vector usadas es un vector de booleanos donde un índice está asociado a una letra y el valor indica si esa letra ya ha sido colocada o no
 */
// función que resuelve el problema
void resolver(int m, int k, int n, vector<char>& sol, vector<bool>& usadas) {
    for(char i = 'a'; i < ('a' + m); i++){
        sol[k] = i;
        if(!usadas[i - 'a']){
            usadas[i - 'a'] = true;
            if(k == n - 1){
                mostrar_sol(sol);
            }
            else
                resolver(m, k + 1, n, sol, usadas);
            usadas[i - 'a'] = false;
        }
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
    vector<bool> usadas(m, false);
    resolver(m, 0, n, sol, usadas);    
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