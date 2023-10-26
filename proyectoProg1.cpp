// Programa hecho por Gonzalo Stickar y Lautaro Moor

#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

//Funciones
string toLower(string palabra);
void bienvenida();
void mostrarColor(int numero);
int dificultad(int nivel);
void victoriaEpica(int limite);
string jugarDeNuevo();

int main()
{
    srand(time(0));

    //Declaración de variables.
    string menu;
    bool termina = false;
    int color, puntos = 0, contador = 0, tiempo = 6000; //La variable tiempo está definida en milisegundos.
    int simonDice[1]; //Se generan 25 colores aleatorios.

    //Presentamos un cartel de bienvenida.
    bienvenida();

    while (true)
    {
        //Se generan los colores aleatorios.
        for (int i = 0; i < size(simonDice); i++)
            simonDice[i] = rand() % 4 + 1;

        system("cls");

        while (termina == false && puntos < size(simonDice))
        {
            for (int i = 0; i < puntos + 1; i++)
            {
                cout << "Color " << i + 1 << " atento!!!" << endl;
                mostrarColor(simonDice[i]);
                Sleep(tiempo);
                system("cls");
            }

            contador = 0;
            system("color 7");

            //El usuario tiene que ingresar uno a uno, los diferentes colores que le haya tocado. 
            while (contador <= puntos)
            {
                do {
                    cout << "1) Verde - 2) Rojo - 3) Amarillo - 4) Azul" << endl;
                    cout << "Ingrese el numero correspondiente al Color " << contador + 1 << ": ";
                    cin >> color;
                } while (color < 1 || color > 4);
                if (simonDice[contador] == color)
                {
                    contador++;
                    system("cls");
                }
                else
                {
                    termina = true;
                    break;
                }
            }
            if (termina == false)
                puntos++;
            system("cls");
            //Segun el puntaje aumenta la velocidad 
            tiempo = dificultad(puntos);
        }

        //Muestra el puntaje
        if (puntos == size(simonDice))
        {
            victoriaEpica(size(simonDice));
        }
        else {
            cout << "Usted llego a " << puntos << " puntos!" << endl;
        }
        Sleep(3000);
        system("cls");
        system("color 7");

        //Menu para volver a jugar
        menu = jugarDeNuevo();
        if (menu == "no") {
            cout << "Finalizo el programa. " << endl;
            break;
        }
        else {
            termina = false;
            puntos = 0;
        }
    }
    return 0;
}

string toLower(string palabra) {
    for (int i = 0; i < palabra.length(); i++)
    {
        if ((palabra[i] >= 'A') && (palabra[i] <= 'Z')) {
            palabra[i] = palabra[i] + 32;
        }
    }
    return palabra;
}

void mostrarColor(int numero) {
    switch (numero)
    {
    case 1:
        cout << "VERDE" << endl;
        system("color 2");
        break;
    case 2:
        cout << "ROJO" << endl;
        system("color 4");

        break;
    case 3:
        cout << "AMARILLO" << endl;
        system("color 6");
        break;
    default:
        cout << "AZUL" << endl;
        system("color 1");
        break;
    }
}

int dificultad(int nivel) { //Mientras avance de nivel le asignamos menos tiempo.
    if (nivel < 5)
        return 5000;
    else if (nivel < 10)
        return 4200;
    else if (nivel < 15)
        return 3800;
    else if (nivel < 20)
        return 3400;
    else
        return 3000;
}

void victoriaEpica(int limite) {
    cout << "Usted gano el juego por completo, llego a la suma de " << limite << " puntos!";
    for (int i = 0; i < 5; i++) {
        system("color 2");
        Sleep(1000);
        system("color 4");
        Sleep(1000);
        system("color 6");
        Sleep(1000);
        system("color 1");
        Sleep(1000);
    }
}

void bienvenida() { //Cartel de Bienvenida al comenzar el juego.
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
    cout << "-\tBienvenido al juego de simon dice!\t +" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
    cout << endl << "Pulse enter para empezar a jugar!";
    cin.get();
}

string jugarDeNuevo() { //Opción para poder jugar de nuevo.
    string menu;
    do {
        cout << "Desea jugar volver a jugar?(si-no): ";
        cin >> menu;
        menu = toLower(menu); //Ubicamos todas las letras ingresadas en minusculas.
        if (menu == "si" || menu == "no")
        {
            system("cls");
            break;
        }
    } while (menu != "si" || menu != "no");
    return menu;
}