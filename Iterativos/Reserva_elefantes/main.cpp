// Nombre del alumno Álvaro Cepeda Ramos
// Usuario del Juez FAL-J03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/**
 *
 *  Precondición : {datos.size > 0 and acum.size = datos.size + 1}
 *
 *  resolver(vector<long long> acum, const vector<int>&datos)
 * 
 *  Invariante : {forAll i: 0 < i < acum.size: acum[i] = acum[i - 1] + datos[i - 1];}
 * 
 *  Postcondición : {forAll i: 0 <= i < acum.size: acum[i] = sum k1: 0 <= k1 <= i}
 */
// función que resuelve el problema
void resolver(vector<long long> &acum, const vector<int>& datos)
{
    for (int i = 1; i < acum.size(); i++)
    {
        acum[i] = acum[i - 1] + datos[i - 1];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int primerAnno, ultimoAnno;

    cin >> primerAnno >> ultimoAnno;
    if (primerAnno == 0 || ultimoAnno == 0)
        return false;

    vector<int> nacimientos((ultimoAnno - primerAnno) + 1);
    for (int i = 0; i < nacimientos.size(); i++)
    {
        cin >> nacimientos[i];
    }

    vector<long long> acumulados(nacimientos.size() + 1);
    resolver(acumulados, nacimientos);

    int preguntas;

    cin >> preguntas;

    for (int i = 0; i < preguntas; i++)
    {
        int anno1, anno2;
        cin >> anno1 >> anno2;

        cout << acumulados[anno2 - primerAnno + 1] - acumulados[anno1 - primerAnno] << endl;
    }

    cout << "---\n";

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
