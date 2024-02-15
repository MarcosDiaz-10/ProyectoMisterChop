#include <iostream>
using namespace std;

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