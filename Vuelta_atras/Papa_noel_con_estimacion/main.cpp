// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
void resolver(const int ninos, const int juguetes, int k, const vector<vector<int>>& satis, int sumaSatis, vector<int>& sol,
     vector<bool>& marcas, int& satisMejor, const vector<int>& acumulados) {
    for(int i = 0; i < juguetes; i++){
        sol[k] = i;
        if(!marcas[i]){
            marcas[i] = true;
            sumaSatis += satis[k][i];
            if(k == ninos - 1){
                if(sumaSatis > satisMejor)
                    satisMejor = sumaSatis;
            }
            else{
                if(sumaSatis + acumulados[k + 1] > satisMejor)
                    resolver(ninos, juguetes, k + 1, satis, sumaSatis, sol, marcas, satisMejor, acumulados);
            }
            marcas[i] = false;
            sumaSatis -= satis[k][i];
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int juguetes;
    cin >> juguetes;
    
    if (! std::cin)
    return false;
    
    int ninos;
    cin >> ninos;
    
    vector<vector<int>> satisfaccion(ninos, vector<int>(juguetes));
    vector<int> acumulados(ninos, 0);
    
    for(int i = 0; i < ninos; i++){
        for(int j = 0; j < juguetes; j++){
            cin >> satisfaccion[i][j];
        }
    }
    
    for(int i = 0; i < ninos; i++){
        int max = satisfaccion[i][0];
        for(int j = 0; j < juguetes; j++){  
            if(satisfaccion[i][j] > max)
                max = satisfaccion[i][j];
        }
        acumulados[i] = max;
    }

    // La satisfacción mejor se inicializa a dar el juguete i al niño i, una solución válida aunque probablemente no la mejor
    int satisMejor = 0;
    for(int i = 0; i < ninos; i++){
            satisMejor += satisfaccion[i][i];
    }

    // Vector de acumulados, se rellena desde el final porque nos sive para conocer sa satisfacción máxima que podemos conseguir a partir de la etapa del árbol en la que estemos
    for(int i = ninos - 1; i > 0; --i){
        acumulados[i - 1] += acumulados[i];
    }

    vector<bool> marcas(juguetes, false);
    vector<int> sol(ninos);
    
    resolver(ninos, juguetes, 0, satisfaccion, 0, sol, marcas, satisMejor, acumulados);
    
    // escribir sol
    
    cout << satisMejor << endl;
    
    
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