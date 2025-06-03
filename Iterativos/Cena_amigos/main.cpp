// Nombre del alumno Álvaro Cepeda Ramos
// Usuario del Juez FAL-J03

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct sol_t
{
    int suma;
    int inicio;
    int longitud;
};

// función que resuelve el problema
sol_t resolver(const vector<int> &datos)
{
    sol_t aux = {0, 0, 0}; // aux.inicio no se usa
    sol_t solMax = {0, 0, 0};

    for (int j = 0; j < datos.size(); j++)
    {
        if (aux.suma + datos[j] > 0)
        {
            aux.suma += datos[j];
            aux.longitud++;
            if (aux.suma > solMax.suma)
            {
                solMax.suma = aux.suma;
                solMax.inicio = j - (aux.longitud - 1);
                solMax.longitud = aux.longitud;
            }
        }
        else
        {
            aux.suma = 0;
            aux.longitud = 0;
        }
    }

    return solMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;

    vector<int> datos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> datos[i];
    }

    sol_t sol = resolver(datos);

    cout << sol.suma << ' ' << sol.inicio << ' ' << sol.longitud << endl;

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