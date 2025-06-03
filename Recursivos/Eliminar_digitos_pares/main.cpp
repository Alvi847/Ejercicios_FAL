// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;



// función que resuelve el problema
long long resolverFinal(long long n, long long pot, long long num) {
    //Caso base
    if(n < 10){
        if(n % 2 == 0)
            return num;
        else
            return num + pot * n;
    }

    if((n % 10) % 2 == 0){
        return resolverFinal(n / 10, pot, num);
    }
    else{
        return resolverFinal(n / 10, pot * 10, num + ((n % 10) * pot));
    }
}

// función que resuelve el problema
long long resolverNoFinal(long long n) {
    //caso base
    if(n < 10){
        if(n % 2 == 0)
            return 0;
        else
            return n;
    }

    long long num = n % 10;
    if(num % 2 == 0){
        return resolverNoFinal(n / 10);
    }
    else{
        return resolverNoFinal(n / 10)*10 + num;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long n;

    cin >> n;

    if (! std::cin)
        return false;
    
    long long pot = 1;
    long long num = 0;
    long long solFinal = resolverFinal(n, pot, num);
    long long solNoFinal = resolverNoFinal(n);

    cout << solNoFinal << " " << solFinal << endl;
     
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