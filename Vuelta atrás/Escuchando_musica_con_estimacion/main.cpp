    // Nombre del alumno Álvaro Cepeda
    // Usuario del Juez FAL-J03

    #include <iostream>
    #include <iomanip>
    #include <fstream>
    #include <vector>

    using namespace std;

    struct t_cancion
    {
        int duracion;
        int satisfaccion;
    };

    struct t_datos
    {
        int canciones;
        int ida;
        int vuelta;
        vector<t_cancion> vCanciones;
    };

    struct t_sol
    {
        int satisfaccion;
        int maxSatis;
        vector<int> solMejor;
        int ida;
        int vuelta;
        vector<int> sol; // Vector que indica si tomamos la cancion k en la ida (sol[k] = 1), en la vuelta (sol[k] = 2) o si no la tomamos (sol[k] = 0)
        bool posible;
    };

    bool esSolucion(int k, const t_datos &d, const t_sol &s)
    {
        return s.ida == d.ida && s.vuelta == d.vuelta && k == d.canciones - 1;
    }

    /**
     * El árbol de exploración tiene de altura el número de canciones, al igual que la longitud del vector de soluciones
     * Cada nodo del árbol tiene tres hijos (escucho la canción en la ida, escucho la canción en la vuelta, no la escucho)
     *
     * Al final tenemos 3^n nodos del árbol, siendo n el número de canciones de entrada 
     */
    // función que resuelve el problema
    void resolver(int k, const t_datos &d, t_sol &s, const vector<int>& acum)
    {
        // Escucho la canción k en el viaje de ida

        s.sol[k] = 1;
        s.ida += d.vCanciones[k].duracion;
        if (s.ida <= d.ida)
        {
            s.satisfaccion += d.vCanciones[k].satisfaccion;
            if (esSolucion(k, d, s))
            {
                s.posible = true;
                if (s.satisfaccion > s.maxSatis)
                {
                    s.solMejor = s.sol;
                    s.maxSatis = s.satisfaccion;
                }
            }
            else if (k < d.canciones - 1)
            {
                if(s.satisfaccion + acum[k] > s.maxSatis)
                    resolver(k + 1, d, s, acum);
            }
            s.satisfaccion -= d.vCanciones[k].satisfaccion;
        }

        // Escucho la canción k en el viaje de vuelta
        s.ida -= d.vCanciones[k].duracion;
        s.sol[k] = 2;
        s.vuelta += d.vCanciones[k].duracion;
        if (s.vuelta <= d.vuelta)
        {
            s.satisfaccion += d.vCanciones[k].satisfaccion;
            if (esSolucion(k, d, s))
            {
                s.posible = true;
                if (s.satisfaccion > s.maxSatis)
                {
                    s.solMejor = s.sol;
                    s.maxSatis = s.satisfaccion;
                }
            }
            else if (k < d.canciones - 1)
            {
                if(s.satisfaccion + acum[k] > s.maxSatis)
                    resolver(k + 1, d, s, acum);
            }
            s.satisfaccion -= d.vCanciones[k].satisfaccion;
        }

        // No escucho la canción k

        s.vuelta -= d.vCanciones[k].duracion;
        s.sol[k] = 0;
        if (esSolucion(k, d, s))
        {
            s.posible = true;
            if (s.satisfaccion > s.maxSatis)
            {
                s.solMejor = s.sol;
                s.maxSatis = s.satisfaccion;
            }
        }
        else if (k < d.canciones - 1)
        {
            if(s.satisfaccion + acum[k] > s.maxSatis)
                resolver(k + 1, d, s, acum);
        }
    }

    // Resuelve un caso de prueba, leyendo de la entrada la
    // configuración, y escribiendo la respuesta
    bool resuelveCaso()
    {
        // leer los datos de la entrada
        t_datos datos;

        cin >> datos.canciones;
        cin >> datos.ida >> datos.vuelta;

        if (datos.canciones == 0 && datos.ida == 0 && datos.vuelta == 0)
            return false;


        datos.vCanciones = vector<t_cancion>(datos.canciones, {0, 0});

        for (int i = 0; i < datos.canciones; i++)
        {
            cin >> datos.vCanciones[i].duracion >> datos.vCanciones[i].satisfaccion;
        }

        vector<int> acum;

        for(auto a : datos.vCanciones){
            acum.push_back(a.satisfaccion);
        }

        for(int i = acum.size() - 1; i > 0; i--){
            acum[i - 1] = acum[i] + acum[i - 1];
        }

        t_sol s;
        s.ida = 0;
        s.vuelta = 0;
        s.satisfaccion = 0;
        s.posible = false;
        s.maxSatis = 0;
        s.sol = vector<int>(datos.canciones, 0);
        resolver(0, datos, s, acum);

        if (!s.posible)
            cout << "Imposible\n";
        else
            cout << s.maxSatis << endl;

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
