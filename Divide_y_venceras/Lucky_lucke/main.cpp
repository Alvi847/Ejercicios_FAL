// Nombre del alumno Álvaro Cepeda Ramos
// Usuario del Juez FAL-J03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int buscarDer(const vector<int>& v, int ini, int fin, int valor)
{
    // Casos base
    if (ini == fin)
        return -1; // Vector vacío, aquí no está lo que buscamos, por cómo es el código en resuelveCaso, aquí nunca llegamos
    else if (ini + 1 == fin) // Vector con 1 elemento, como las alturas son positivas, puedo devolver -1 como indicador de que el elemento no existe
    {
        if (v[ini] == valor)
            return ini;
        else
            return -1;
    }

    // Recursión
    else
    {
        int medio = (ini + fin) / 2;
        if (v[medio] > valor)
            return buscarDer(v, ini, medio, valor);
        else
            return buscarDer(v, medio, fin, valor);
    }
}

int buscarIzq(const vector<int> v, int ini, int fin, int valor)
{
    // Casos base
    if (ini == fin)
        return -1; // Vector vacío, aquí no está lo que buscamos
    else if (ini + 1 == fin) // Vector con 1 elemento, como las alturas son positivas, puedo devolver -1 como indicador de que el elemento no existe
    {
        if (v[ini] == valor)
            return ini;
        else
            return -1;
    }

    // Recursión
    else
    {
        int medio = (ini + fin - 1) / 2;
        if (v[medio] >= valor)
            return buscarIzq(v, ini, medio + 1, valor);
        else
            return buscarIzq(v, medio + 1, fin, valor);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada

    int n, altura;

    cin >> n >> altura;

    if (!std::cin)
        return false;

    vector<int> sospechosos(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sospechosos[i] = a;
    }
    int solIzq = buscarIzq(sospechosos, 0, sospechosos.size(), altura); // El final del vector es el siguiente al último

    // escribir sol

    if (solIzq != -1)
    {
        int solDer = buscarDer(sospechosos, 0, sospechosos.size(), altura);
        if (solDer != solIzq)
            cout << solIzq << " " << solDer << endl;
        else
            cout << solIzq << endl;
    }
    else
        cout << "NO EXISTE\n";

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