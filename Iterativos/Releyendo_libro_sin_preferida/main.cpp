// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& v, int l) {
    int ini = 0, fin = 0, puntuacionMax = 0, puntuacionActual, paginaSol = 0;
    while(fin < l){ // l < v.size()
        puntuacionMax += v[fin];
        fin++;
    }
    puntuacionActual = puntuacionMax;
    for(int i = fin; i < v.size(); i++){
        puntuacionActual += v[i];
        puntuacionActual -= v[ini];
        ini++;
        if(puntuacionActual >= puntuacionMax){
            puntuacionMax = puntuacionActual;
            paginaSol = ini;
        }  
    }
    
    return paginaSol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, l;
    cin >> n >> l;
    if (n == 0 && l == 0)
        return false;
    
    vector<int> v;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }


    int sol = resolver(v, l);
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
