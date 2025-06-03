// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
void sumaDigitos(const int& n, int& suma) {
    //caso base
    if(n < 10)
        suma += n;
    else{
        suma += (n % 10);
        sumaDigitos(n / 10, suma);
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int n, numero;      //n es el numero de datos en el conjunto y numero es el numero cuya suma tienen que igualar los de el conjunto      
    
    std::cin >> n >> numero;    

    int sumaInicial = 0;
    sumaDigitos(numero, sumaInicial);           //sumaInicial indica la suma de los digitos que tienen que igualar el resto de numeros

    for(int i = 0; i < n; i++){
        int numeroConjunto;             //numero i-esimo del conjunto
        std::cin >> numeroConjunto;

        int sol = 0;
        sumaDigitos(numeroConjunto,sol);      //suma de los digitos del i-esimo numero del conjunto
        
        if(sol == sumaInicial){              //si la suma coincide con la suma de nuestro numero incial, se escribe el numero
            std::cout << numeroConjunto;
            if(i != n - 1)
                std::cout << " ";
        }
    }

    std::cout << std::endl;
    
    
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