#include <iostream>
using namespace std;

void menuEquipos () {
    char op;

    do
    {
        cout << "1- Equipos" << endl;
        cout << "2- Jugadores" << endl;
        cout << "3- Directores Técnicos" << endl;
        cout << "4- Partidos" << endl;
        cout << "5- Salir" << endl;

        cin >> op;

    } while ();
    
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
            
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        
        default:
            break;
        }

    } while (op != 5);
    
return 0;
}