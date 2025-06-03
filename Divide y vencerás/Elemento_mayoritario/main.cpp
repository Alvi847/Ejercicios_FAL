// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& v, int ini, int fin) {
    // Casos base
    if(ini == fin) return 0;
    if(ini + 1 == fin) return v[ini];
    
    // Recursión
    else{
        int medio = (ini + fin - 1) / 2;

        int izq = resolver(v, ini, medio + 1);
        int der = resolver(v, medio + 1, fin);

        int vecesIzq = 0;
        int vecesDer = 0;
        // Recorrer el segmento actual y contar cuantas veces aparece el mayoritario de cada lado, después devolver el que más veces aparezca
        for(int i = ini; i < fin; i++){
            if(v[i] == izq) vecesIzq++;
            else if(v[i] == der) vecesDer++;
        }
        int ret = 0;
        int requisito = (fin - ini) / 2; // El requisito de que el elemento aparezca más de m/2 veces en el segmento, siendo m la longitud de este

        if(vecesDer > requisito) ret = der;
        else if(vecesIzq > requisito) ret = izq;
        
        return ret;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> v;
    int i;
    cin >> i;
    int n = 0;
    while(i != 0){
        n++;
        v.push_back(i);
        cin >> i;
    }

    int sol = resolver(v, 0, v.size());
    // escribir sol
    
    if(sol > 0)
        cout << sol;
    else
        cout << "NO";
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