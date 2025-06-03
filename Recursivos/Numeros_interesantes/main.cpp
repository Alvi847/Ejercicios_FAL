// Nombre del alumno Álvaro Cepeda Ramos
// Usuario del Juez FAL-J03


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/**
 * Mi algoritmo tiene una complejidad de orden O(log n) siendo n el número cuyos digitos se analizan para determinar si es interesante o no
 */

// función que resuelve el problema
bool resolver(int n, int& sumaIzq, int sumaDer) {
    //Casos base 
    if(n == 0){
        return false;
    }
    else if(n < 10){
        sumaIzq = n;
        return sumaDer % n == 0;
    }

    //Recusion
    else{
        int digito = n % 10;
        
        bool ret = (sumaDer == 0 || sumaDer % digito == 0) && resolver(n / 10, sumaIzq, sumaDer + digito);

        if(ret){
            ret = sumaIzq % digito == 0;
            sumaIzq += digito;
        } 
        return ret;
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    
    int sumaIzq = 0;
    int sumaDer = 0;

    bool sol = resolver(n, sumaIzq, sumaDer);
    // escribir sol

    if(sol)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
    
    
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