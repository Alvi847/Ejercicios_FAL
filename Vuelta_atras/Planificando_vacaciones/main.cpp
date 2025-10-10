// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


struct datos_t{
    int ciudades;
    vector<vector<int>> precios;
};

struct sol_t{
    vector<int> sol;
    vector<int> solMejor;
    int precioMin;
    int precioAct;
};

// función que resuelve el problema
void resolver(const datos_t& d, sol_t& s, int k, vector<bool>& visitadas, const vector<int>& acum) {
    for(int i = 1; i < d.ciudades; i++){
        s.sol[k] = i;
        if(!visitadas[i] && s.precioAct < s.precioMin){
            visitadas[i] = true;
            s.precioAct += d.precios[s.sol[k - 1]][i];
            if(k == d.ciudades - 1){
                s.precioAct += d.precios[i][0]; //Sumar el precio de volver a la ciudad de origen
                if(s.precioAct < s.precioMin){
                    s.precioMin = s.precioAct;
                    s.solMejor = s.sol; 
                }
                s.precioAct -= d.precios[i][0];
            }
            else{
                if(acum[k] + s.precioAct < s.precioMin)
                    resolver(d, s, k + 1, visitadas, acum);
            }
            s.precioAct -= d.precios[s.sol[k - 1]][i];
            visitadas[i] = false;
        }
    }
    
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    datos_t datos;
    cin >> datos.ciudades;

    if (datos.ciudades == 0)
        return false;
    
    datos.precios = vector<vector<int>>(datos.ciudades, vector<int>(datos.ciudades));

    for(int i = 0; i < datos.ciudades; i++){
        for(int j = 0; j < datos.ciudades; j++){
            cin >> datos.precios[i][j];
        }
    }

    //Vector para ayudar con la estimacion
    vector<int> acum(datos.ciudades);
    for(int i = 0; i < datos.ciudades; i++){
        int min = 501; // Ningun viaje cuesta mas de 500
        for(int j = 0; j < datos.ciudades; j++){
            if(datos.precios[i][j] < min)
            min = datos.precios[i][j];
        }
        acum[i] = min;
    }

    for(int i = acum.size() - 1; i > 0; i--){
        acum[i - 1] += acum[i];
    }

    sol_t solucion;
    solucion.solMejor = vector<int>(datos.ciudades);
    solucion.precioMin = 0;
    for(int i = 1; i < datos.ciudades; i++){
        solucion.precioMin += datos.precios[i-1][i];
        solucion.solMejor[i] = i;
    }

    solucion.precioMin += datos.precios[datos.ciudades - 1][0];

    solucion.precioAct = 0;
    solucion.sol = vector<int>(datos.ciudades);

    vector<bool> visitadas(datos.ciudades, false);

    resolver(datos, solucion, 1, visitadas, acum);

    cout << solucion.precioMin << endl;
    
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
