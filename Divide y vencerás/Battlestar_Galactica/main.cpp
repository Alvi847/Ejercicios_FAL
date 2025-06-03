// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct sol_t
{
    int cont;
    vector<int> v;
};
/**
 * Recurrencia T(n) = c0 si n <= 1; 2T(n/2) + n si n > 1
 * 
 * Despliegue T(n) = 2T(n/2) + n = 2^2T(n/2^2) + 3n = 2^3 * T(n/2^3) + 7n
 * 
 * Tras k pasos = T(k) = 2^k * T(n/2^k) + k * n
 * 
 * En el caso base T(1) => k = log2(n) => T(k) = n * T(1) + n * log(n)
 * 
 * El algoritmo tiene complejidad O(n log(n)) Siendo n el tamaño del vector de entrada
 */
vector<int> mezclar(const vector<int>& izq, const vector<int>& der, int& contador)
{
    int i = 0;
    int j = 0;
    vector<int> ret;
    while(i < izq.size() && j < der.size()){
        if(izq[i] < der[j]){
            ret.push_back(izq[i]);
            i++;
        }
        else{
            ret.push_back(der[j]);
            j++;
            contador += izq.size() - i;
            
        }
    }
    while(i < izq.size()){
        ret.push_back(izq[i]);
        i++;
    }
    while(j < der.size()){
        ret.push_back(der[j]);
        j++;
    }
    return ret;
}

// función que resuelve el problema
sol_t resolver(const vector<int> &v, int ini, int fin) // Esto es un algoritmo de mergesort
{
    // Casos base
    if (ini == fin)
        return {0, vector<int>()};
    if (ini + 1 == fin)
        return {0, vector<int>(1, v[ini])};

    // Recursión
    else
    {
        int medio = (ini + fin - 1) / 2;
        sol_t der = resolver(v, medio + 1, fin);
        sol_t izq = resolver(v, ini, medio + 1);
        int contador = der.cont + izq.cont;
        vector<int> aux = mezclar(izq.v, der.v, contador); //Mezclo los dos vectores

        return {contador, aux};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entintrada
    int n;
    cin >> n;

    if (!std::cin)
        return false;

    vector<int> flota(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        flota[i] = a;
    }

    sol_t sol = resolver(flota, 0, n);

    cout << sol.cont << endl;
    
    return true;
}

int main()
{
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
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