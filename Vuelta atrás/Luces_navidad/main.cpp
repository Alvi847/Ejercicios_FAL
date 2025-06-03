// Nombre del alumno Álvaro Cepeda    
// Usuario del Juez FAL-J03


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/**
 * Cada nodo del árbol de exploración va a tener tantos hijos como colores distintos haya (n)
 * 
 * La altura del árbol es el tamaño de la tira de luces
 * 
 * El tamaño de la tira es también el tamaño del vector solución y cada componente guarda el color de la luz en ese lugar de la tira
 * 
 * Todas las combinaciones de luces que pueden caber en la tira forman el espacio de soluciones, pero sólo las que cumplen las restricciones
 * son solución del problema
 */
// función que resuelve el problema
void resolver(int l, int k, int maxConsumo, const vector<int>& consumos, vector<int>& tira, int& combinaciones, 
vector<int>& marcas, int consumoTotal) {
    for(int i = 0; i < consumos.size(); i++){
        tira[k] = i;
        marcas[i]++;
        consumoTotal += consumos[i];
        if((k < 2 || (k >= 2 && !(tira[k - 2] == tira[k - 1] && i == tira[k - 2]))) // Condición de no más de dos seguidas iguales
        && consumoTotal <= maxConsumo && (marcas[i] <= k - marcas[i] + 2))  // Condiciones del límite de consumo y de que no haya más de una luz del color i que el resto
        {
            if(k == l - 1){
                combinaciones++;
            }
            else
                resolver(l, k + 1, maxConsumo, consumos, tira, combinaciones, marcas, consumoTotal);
        }
        consumoTotal -= consumos[i];
        marcas[i]--;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int l;
    cin >> l;
    if (l == 0)
        return false;
    
    int n, c;
    cin >> n >> c;
    vector<int> consumos(n, 0); // Vector que guarda el consumo de cada color de luz

    for(int i = 0; i < n;i++){
        int a;
        cin >> a;
        consumos[i] = a;
    }

    vector<int> tira(l, 0);     // Toda la tira de luces (vector de las combinaciones quie son solución)
    vector<int> marcas(n, 0);   // Vector que cuenta cuántas luces de cada color hemos usado
    int sol = 0;

    resolver(l, 0, c, consumos, tira, sol, marcas, 0);
    
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
