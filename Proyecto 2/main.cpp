#include <iostream>
#include <fstream>
using namespace std;






class Jugadores {
    public:
    string nombre;
    string apellido;
    string posicion;
    int experiencia;
    string equipo;
};

class Equipos {
    public:
    string nombre;
    Jugadores *jugadores;
};
class DirectoresTecnicos {
    public:
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

                if( line == "J" ) {
                    info = 'J';
                    continue;
                }
                
                if( line == "D" ) {
                    info = 'D';
                    continue;
                }
                if( info == 'E') {
                    numEquipos++;
                }
                

                if( info == 'J') {
                    numJugadores++;
                }
                
                if( info == 'D') {
                    numDirectoresTecnicos++;
                }



           }
            
        }
    }

  
    
    void leerEntrada(){
        string line;
        ifstream archivo(nombreArchivo.c_str());
        char info;
        contarArchivo();
        
        jugadores = new Jugadores[numJugadores];
        equipos = new Equipos[numEquipos];
        directoresTecnicos = new DirectoresTecnicos[numDirectoresTecnicos];
        if(archivo.is_open()) 
        {
            int equipoActual = 0;
            int jugadorActual = 0;
            int directorActual = 0;

            while (!archivo.eof())
            {
                string palabra;

                
                getline(archivo, line);

                

                if(line == "E") {
                    info = 'E';
                    continue;
                }

                if( line == "J" ) {
                    info = 'J';
                    continue;
                }
                
                if( line == "D" ) {
                    info = 'D';
                    continue;
                }
                if( info == 'E') {

                        equipos[equipoActual].nombre = line;
                        equipoActual++;
                }
                

                if( info == 'J') {
                    string caracter = "";
                    int elem = 0;
                    for (int i = line.size() - 1; i >= 0 ; i--)
                    {
                        caracter = line[i] + caracter;

                    

                        if ( i == 0 || line[ i - 1] == ' '){
                            if( elem == 0 ){
                                palabra = caracter;
                                elem++;
                                int exp = stoi(palabra);
                                jugadores[jugadorActual].experiencia = exp;
                                caracter = "";
                            }
                            else if ( elem == 1){
                                palabra = caracter;
                                elem++;
                                jugadores[jugadorActual].posicion = palabra;
                                caracter = "";
                            } 
                            else if( elem == 2){
                                palabra = caracter;
                                elem++;
                                jugadores[jugadorActual].apellido = palabra;
                                caracter="";
                            }
                            else if( elem == 3){
                                palabra = caracter;
                                elem++;
                                jugadores[jugadorActual].nombre = palabra;
                                caracter="";
                            }
                        }
                            else if( elem == 4){
                                palabra = caracter;
                                jugadores[jugadorActual].equipo = palabra;
                                caracter="";
                            }
                    }
                    jugadorActual++;
                }
                
                if( info == 'D') {
                    string caracter = "";
                    int elem = 0;
                    for (int i = line.size() - 1; i >= 0 ; i--)
                    {
                        caracter = line[i] + caracter;

                        if ( i == 0 || line[ i - 1] == ' '){
                            if( elem == 0 ){
                                palabra = caracter;
                                elem++;
                                int exp = stoi(palabra);
                                directoresTecnicos[directorActual].tiempoExperiencia = exp;
                                caracter = "";
                            }
                            else if ( elem == 1){
                                palabra = caracter;
                                elem++;
                                directoresTecnicos[directorActual].apellido = palabra;
                                caracter = "";
                            } 
                            else if( elem == 2){
                                palabra = caracter;
                                elem++;
                                directoresTecnicos[directorActual].nombre = palabra;
                                caracter="";
                            }   
                        }
                    }
                    directorActual++;
                }

          


            }
            
        }
    }

    void agregarEquipo(string nombreEquipo) {
        numEquipos++;
        Equipos aux[numEquipos];

        for(int i = 0; i < numEquipos - 1; i++) {
            aux[i] = equipos[i];
        }

        delete []equipos;

        equipos = new Equipos[numEquipos];

        for (int i = 0; i < numEquipos; i++)
        {
            equipos[i]=aux[i];
        }
        

    }

    TrabajoArchivo( string nombreDeArchivo ) {
        nombreArchivo = nombreDeArchivo;
    }

};

void menuEquipos ( TrabajoArchivo entradaIn) {
    char op;

    do
    {

        cout << "1- Agregar" << endl;
        cout << "2- Modificar" << endl;
        cout << "3- Eliminar" << endl;
        cout << "4- Listar Todos" << endl;
        cout << "5- Volver" << endl;

        cin >> op;

        switch (op)
        {
        case ('1'): {
            string n;
            cin >> n;

            entradaIn.agregarEquipo(n);
            
            break;
        }
        default:
            break;
        }

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

    entradaIn.leerEntrada();

    
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
            menuEquipos(entradaIn);
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