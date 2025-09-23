#include <iostream>
#include "Cancha.h"
#include "Reserva.h"
using namespace std;

void calculateReservePrice(Reserva &reserva, Cancha c);
void menu(int *opc1);

int minPc = 5;
int maxPc = 8;
Cancha canchas[]{
    Cancha(),
    Cancha("sintetica", 84, 7),
    Cancha("sintetica", 100, 8),

    Cancha("natural", 80, 5),
    Cancha("natural", 100, 7),
    Cancha("natural", 120, 8),

};
Reserva reservas[100];
int main()
{
    Reserva reserva;
    int t, d, pc, opc, id;
    int rc = 0;
    bool h, natural;
    string cn;

    do
    {
        menu(&opc);
        switch (opc)
        {
        case 1:
            cout << "INGRESE SU NOMBRE: ";
            cout << "> ";
            cin >> cn;

            cout << "INGRESE SU LA CANTIDAD DE JUGADORES: ";
            cout << "> ";
            cin >> pc;
            if (pc > maxPc || pc < minPc)
            {
                cout << "Ingrese una cantidad de jugadores valida. (5-8)" << endl;
                break;
            }

            cout << "CANCHA NATURAL?(0.NO, 1.SI): " << endl;
            cout << "> ";
            cin >> natural;
            if (natural > 1 || natural < 0)
            {
                cout << "Ingrese un valor valido" << endl;
                break;
            }

            cout << "INGRESE LA HORA DE RESERVA: ";
            cout << "> ";
            cin >> t;
            if (t > 23 || t < 0)
            {
                cout << "La hora de reserva debe ser valida(0-23)" << endl;
                break;
            }

            cout << "INGRESE LA CANTIDAD DE TIEMPO DE RESERVA: ";
            cout << "> ";
            cin >> d;
            if (d > 8)
            {
                cout << "No es posible reservar canchas por mas de 8 horas" << endl;
                break;
            }

            cout << "DESEA INCLUIR HIDRATACION?(0.NO 1.SI): ";
            cout << "> ";
            cin >> h;
            if (h > 1 || h < 0)
            {
                cout << "Ingrese un valor valido" << endl;
                break;
            }

            for (int i = 0; i < size(canchas); i++)
            {
                Cancha cancha = canchas[i];
                if (cancha.getCapacity() <= pc && cancha.getGroundType() == (natural ? "natural" : "sintetica"))
                {
                    reserva.setCancha(cancha);
                }
            }

            reserva.setClientName(cn);
            reserva.setTime(t);
            reserva.setDuration(d);
            reserva.setPlayerCount(pc);
            reserva.setIncludeHydration(h);
            reserva.setPrice(reserva.getCancha().getPricing() + (reserva.getIncludeHydration() ? 20 : 0));
            reservas[rc] = reserva;
            rc++;

            cout << "ID DE LA RESERVA: " << reservas[rc - 1].getId();
            cout << "TIPO DE CANCHA: " << reservas[rc - 1].getCancha().getGroundType() << endl;
            cout << "NOMBRE CLIENTE: " << reservas[rc - 1].getClientName() << endl;
            cout << "HORA DE LA RESERVA: " << reservas[rc - 1].getTime() << endl;
            cout << "TIEMPO RESERVADO: " << reservas[rc - 1].getDuration() << endl;
            cout << "INCLUYE HIDRATACION: " << (reservas[rc - 1].getIncludeHydration() ? "SI" : "NO") << endl;
            cout << "CANTIDAD DE JUGADORES" << reservas[rc - 1].getPlayerCount() << endl;
            cout << "PRECIO DE LA RESERVA: " << reservas[rc - 1].getPrice() << endl;
            cout << "RESERVA GENERADA EXISTOSAMENTE" << endl;
            cout << endl;

            break;
        case 2:
            for (int i = 0; i < rc; i++)
            {
                cout << "ID DE LA RESERVA: " << reservas[i].getId();
                cout << "TIPO DE CANCHA: " << reservas[i].getCancha().getGroundType() << endl;
                cout << "NOMBRE CLIENTE: " << reservas[i].getClientName() << endl;
                cout << "HORA DE LA RESERVA: " << reservas[i].getTime() << endl;
                cout << "TIEMPO RESERVADO: " << reservas[i].getDuration() << endl;
                cout << "INCLUYE HIDRATACION: " << (reservas[i].getIncludeHydration() ? "SI" : "NO") << endl;
                cout << "CANTIDAD DE JUGADORES" << reservas[i].getPlayerCount() << endl;
                cout << "PRECIO DE LA RESERVA: " << reservas[i].getPrice() << endl;
                cout << endl;
            }
            break;
        case 3:
            cout << "MODIFICAR RESERVA" << endl;
            cout << "Ingrese el id de la reserva" << endl;
            cout << "> ";
            cin >> id;
            for (int i = 0; i < rc; i++)
            {
                if (reservas[i].getId() == id)
                {
                    cout << "INGRESE SU NOMBRE: ";
                    cout << "> ";
                    cin >> cn;

                    cout << "INGRESE SU LA CANTIDAD DE JUGADORES: ";
                    cout << "> ";
                    cin >> pc;
                    if (pc > maxPc || pc < minPc)
                    {
                        cout << "Ingrese una cantidad de jugadores valida. (5-8)" << endl;
                        break;
                    }

                    cout << "CANCHA NATURAL?(0.NO, 1.SI): " << endl;
                    cout << "> ";
                    cin >> natural;
                    if (natural > 1 || natural < 0)
                    {
                        cout << "Ingrese un valor valido" << endl;
                        break;
                    }

                    cout << "INGRESE LA HORA DE RESERVA: ";
                    cout << "> ";
                    cin >> t;
                    if (t > 23 || t < 0)
                    {
                        cout << "La hora de reserva debe ser valida(0-23)" << endl;
                        break;
                    }

                    cout << "INGRESE LA CANTIDAD DE TIEMPO DE RESERVA: ";
                    cout << "> ";
                    cin >> d;
                    if (d > 8)
                    {
                        cout << "No es posible reservar canchas por mas de 8 horas" << endl;
                        break;
                    }

                    cout << "DESEA INCLUIR HIDRATACION?(0.NO 1.SI): ";
                    cout << "> ";
                    cin >> h;
                    if (h > 1 || h < 0)
                    {
                        cout << "Ingrese un valor valido" << endl;
                        break;
                    }

                    for (int i = 0; i < size(canchas); i++)
                    {
                        Cancha cancha = canchas[i];
                        if (cancha.getCapacity() <= pc && cancha.getGroundType() == (natural ? "natural" : "sintetica"))
                        {
                            reservas[i].setCancha(cancha);
                        }
                    }

                    reservas[i].setClientName(cn);
                    reservas[i].setTime(t);
                    reservas[i].setDuration(d);
                    reservas[i].setPlayerCount(pc);
                    reservas[i].setIncludeHydration(h);
                    reservas[i].setPrice(reservas[i].getCancha().getPricing() + (reservas[i].getIncludeHydration() ? 20 : 0));

                    cout << "ID DE LA RESERVA: " << reservas[i].getId();
                    cout << "TIPO DE CANCHA: " << reservas[i].getCancha().getGroundType() << endl;
                    cout << "NOMBRE CLIENTE: " << reservas[i].getClientName() << endl;
                    cout << "HORA DE LA RESERVA: " << reservas[i].getTime() << endl;
                    cout << "TIEMPO RESERVADO: " << reservas[i].getDuration() << endl;
                    cout << "INCLUYE HIDRATACION: " << (reservas[i].getIncludeHydration() ? "SI" : "NO") << endl;
                    cout << "CANTIDAD DE JUGADORES" << reservas[i].getPlayerCount() << endl;
                    cout << "PRECIO DE LA RESERVA: " << reservas[i].getPrice() << endl;
                    cout << "RESERVA MODIFICADA EXISTOSAMENTE" << endl;
                    cout << endl;
                }
            }
            break;
        default:
            break;
        }

    } while (opc != 0);
    // Reserva reserva1 = Reserva(canchas[0], 19, 1, "Omar", 5);
}

void menu(int *opc)
{
    cout << "CANCHAS METEGOL" << endl;
    cout << "1.Crear Reserva" << endl;
    cout << "2.Listar Reservas" << endl;
    cout << "3.Modificar Reserva" << endl;
    cout << "> ";
    cin >> *opc;
}

// void calculateReservePrice(Reserva &reserva, Cancha c, Cancha *canchas) {
//     int pc = reserva.getPlayerCount();
//     string fieldType = reserva.getCancha().getGroundType();
//
//     for (int i = 0; i < 6; i++) {
//         if (pc == canchas[i].getCapacity() && fieldType == canchas[i].getGroundType()) {
//             reserva.setPrice(canchas[i].getPricing());
//         }
//     }
// };
