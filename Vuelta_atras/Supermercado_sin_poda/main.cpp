// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct t_datos
{
    int supermercados;
    int productos;
    vector<vector<int>> precios;
};

struct t_sol
{
    vector<int> sol;
    int sumaPrecios;
};

/**
 * La altura del árbol de exploración es la cantidad de productos, y cada nodo tiene tantos hijos como supermercados haya
 * 
 * El vector solución es tan grande como la cantidad de supermercados y guardo el último producto comprado
 * 
 * No guardo necesariamente todos los productos que compro, porque no lo necesito para calcular el coste mínimo.abort
 * Sin embargo, tengo que guardar cuántos productos compro en cada supermercado. Para eso uso el vector de marcas,
 * que también tiene como tamaño el número de supermercados
 */
// función que resuelve el problema
void resolver(int k, const t_datos &d, t_sol &s, vector<int> marcas, int &costeMin)
{
    for (int i = 0; i < d.supermercados; i++)
    {
        s.sol[k] = i;
        if (marcas[i] < 3)
        {
            marcas[i]++;
            s.sumaPrecios += d.precios[i][k];
            if (k == d.productos - 1)
            {
                if (s.sumaPrecios < costeMin)
                    costeMin = s.sumaPrecios;
            }
            else
            {
               resolver(k + 1, d, s, marcas, costeMin);
            }
            marcas[i]--;
            s.sumaPrecios -= d.precios[i][k];
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    t_datos datos;
    cin >> datos.supermercados >> datos.productos;
    if (datos.supermercados > 0 && datos.productos > 0)
    {

        for (int i = 0; i < datos.supermercados; i++)
        {
            vector<int> aux(datos.productos);
            for (int j = 0; j < datos.productos; j++)
            {
                cin >> aux[j];
            }
            datos.precios.push_back(aux);
        }

        int costeMin = 0;
        for (int i = 0; i < datos.supermercados; i++)
        {
            costeMin += (datos.precios[i][i] + datos.precios[i][i + 1] + datos.precios[i][i + 2]);
        }

        t_sol s;
        s.sol.assign(datos.productos, 0);
        s.sumaPrecios = 0;
        vector<int> marcas(datos.supermercados, 0);
        resolver(0, datos, s, marcas, costeMin);
        cout << costeMin << endl;
    }
    else
        cout << "Sin solucion factible\n";
}

int main()
{
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
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