// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void mostrar_solucion(vector<int> sol, int piezas)
{
    for (int i = 0; i < piezas; i++)
    {
        switch (sol[i])
        {
        case 0:
            cout << "azul ";
            break;
        case 1:
            cout << "rojo ";
            break;
        case 2:
            cout << "verde ";
            break;
        }
    }
    cout << endl;
}

// función que resuelve el problema
bool resolver(int piezas, int k, int totalColores, vector<int> &sol, vector<int> &piezasUsadas, const vector<int> &piezasComienzo)
{
    bool haySolucion = false;
    for (int i = 0; i < totalColores; i++)
    {
        sol[k] = i;
        piezasUsadas[i]++;
        if ((i != 2 || (i == 2 && sol[k - 1] != 2)) && (piezasUsadas[0] >= piezasUsadas[2]) && (piezasUsadas[i] <= piezasComienzo[i]))
        {
            if (k == piezas - 1)
            {
                if (piezasUsadas[1] > (piezasUsadas[0] + piezasUsadas[2]))
                {
                    haySolucion = true;
                    mostrar_solucion(sol, piezas);
                }
            }
            else if (resolver(piezas, k + 1, totalColores, sol, piezasUsadas, piezasComienzo))
                haySolucion = true;
        }
        piezasUsadas[i]--;
    }
    return haySolucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int piezas;
    cin >> piezas;

    vector<int> colores(3, 1);

    if (piezas == 0)
        return false;

    for (int i = 0; i < 3; i++)
    {
        int a;
        cin >> a;
        colores[i] = a;
    }

    if (colores[1] == 0)
        cout << "SIN SOLUCION\n\n";
    else
    {
        vector<int> sol(piezas, 1); // Inicializando a 1 ya tenemos la pieza roja de la base puesta

        vector<int> piezasUsadas(3, 0); // Piezas que tiene al comienzo del problema

        piezasUsadas[1] = 1; // Marcamos la pieza roja de la base como usada
        if (piezas > 1)
        {
            bool haySolucion = resolver(piezas, 1, 3, sol, piezasUsadas, colores); // Llamamos con k = 1, porque la primera pieza ya está colocada

            if (!haySolucion)
                cout << "SIN SOLUCION\n";
        }
        else
            cout << "rojo\n";
        cout << endl;
    }

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
