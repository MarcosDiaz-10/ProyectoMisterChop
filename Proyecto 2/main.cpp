#include <iostream>
#include <fstream>
using namespace std;






class Jugadores {
    string nombre;
    string apellido;
    string posicion;
    int experiencia;
    string equipo;
};

class Equipos {
    string nombre;
    Jugadores *jugadores;
};
class DirectoresTecnicos {
    string nombre;
    string apellido;
    int tiempoExperiencia;
};

class TrabajoArchivo {

    public:
    Equipos *equipos;
    Jugadores *jugadores;
    DirectoresTecnicos *directoresTecnicos;
    int numEquipos = 0;
    int numJugadores = 0;
    int numDirectoresTecnicos = 0;
    string nombreArchivo;

    void contarArchivo () {
        string line;
        ifstream archivo(nombreArchivo.c_str());
        int cont = 0;
        char info;
        if(archivo.is_open()) 
        {
            while (!archivo.eof())
            {
                string palabra;
                
                getline(archivo, line);

                if(line == "E") {
                    info = 'E';
                    continue;
                }

                if( info == 'E') {
                    numEquipos++;
                }

                if( line == "J" ) {
                    info = 'J';
                    continue;
                }

                if( info == 'J') {
                    numJugadores++;
                }
                
                if( line == "D" ) {
                    info = 'D';
                    continue;
                }
                
                if( info == 'D') {
                    numDirectoresTecnicos++;
                }

                cout << line << endl;


            }
            
        }
    }

  
    void leerEntrada(){
        string line;
        ifstream archivo(nombreArchivo.c_str());
        if(archivo.is_open()) 
        {
            while (!archivo.eof())
            {
                string palabra;
                
                getline(archivo, line);

                if(line == "E") {
                    cout << "si entra en E";
                    continue;
                }

                cout << line << endl;


            }
            
        }
    }

    TrabajoArchivo( string nombreDeArchivo ) {
        nombreArchivo = nombreDeArchivo;
    }

};

void menuEquipos () {
    char op;

    do
    {

        cout << "1- Agregar" << endl;
        cout << "2- Modificar" << endl;
        cout << "3- Eliminar" << endl;
        cout << "4- Listar Todos" << endl;
        cout << "5- Volver" << endl;

        cin >> op;

    } while ( op != '5');
    
}
void menuJugadores () {
    char op;

    do
    {
        cout << "1- Porteros" << endl;
        cout << "2- Defensas" << endl;
        cout << "3- Mediocampistas" << endl;
        cout << "4- Delanteros" << endl;
        cout << "5- Goleadores" << endl;
        cout << "6- Volver" << endl;

        cin >> op;

    } while ( op != '6');
    
}
void menuDirectorTecnico () {
    char op;

    do
    {
        cout << "1- Todos" << endl;
        cout << "2- Los más experimentados" << endl;
        cout << "3- Agregar" << endl;
        cout << "4- Modificar" << endl;
        cout << "5- Eliminar" << endl;
        cout << "6- Volver" << endl;

        cin >> op;

    } while ( op != '6');
    
}

void menuPartidos () {
    char op;

    do
    {
        cout << "1- Cargar Partidos" << endl;
        cout << "2- Volver" << endl;

        cin >> op;

    } while ( op != '2');
    
}

 
int main () {

    TrabajoArchivo entradaIn("Entrada.in.txt");

    entradaIn.contarArchivo();

    cout << entradaIn.numDirectoresTecnicos << endl;
    cout << entradaIn.numEquipos << endl;
    cout << entradaIn.numJugadores << endl;

    
    char op;
    do
    {
        cout << "1- Equipos" << endl;
        cout << "2- Jugadores" << endl;
        cout << "3- Directores Técnicos" << endl;
        cout << "4- Partidos" << endl;
        cout << "5- Salir" << endl;

        cin >> op;

        switch (op)
        {
        case '1':
            menuEquipos();
            break;
        case '2':
            menuJugadores();
            break;
        case '3':
            menuDirectorTecnico();
            break;
        case '4':
            menuPartidos();
            break;
        case '5':
            cout << "Cerrando el Programa...";
            break;
        default:
            cout << "Elija una opcion válida";
            break;
        }

    } while (op != '5');
    
return 0;
}