#include <iostream>
#include "Cancha.h"
#include "Reserva.h"
using namespace std;

void calculateReservePrice(Reserva &reserva, Cancha c);
Reserva createReserve(int id);
void printReserve(Reserva r);
void printField(Cancha cancha);

void menu(int *opc);

int minPc = 1;
int maxPc = 16;

Cancha canchas[]{
    Cancha(0, "sintetica", 60, 5),
    Cancha(1, "sintetica", 84, 7),
    Cancha(2, "sintetica", 100, 8),

    Cancha(3, "natural", 80, 5),
    Cancha(4, "natural", 100, 7),
    Cancha(5, "natural", 120, 8),

};

Reserva reservas[6];
int rc = 0;

int main()
{
    int maxReserves = 6;
    Reserva reserva;
    int t, d, pc, opc, id;
    bool h, natural;
    string cn;
    double ganancias = 0;

    do
    {
        menu(&opc);
        switch (opc)
        {
        case 1:
            if (rc >= maxReserves)
            {
                cout << "Lo sentimos no hay canchas disponibles para";
                break;
            }
            reserva = createReserve(rc);
            if (reserva.getId() == -1)
            {
                cout << "Hubo un error creando su reserva. Intentelo mas tarde" << endl;
                cout << reserva.getClientName();
                cout << endl;
                reserva = Reserva();
                break;
            }
            reservas[rc] = reserva;
            ganancias += reserva.getPrice();
            rc++;

            printReserve(reservas[rc - 1]);

            reserva = Reserva();
            break;
        case 2:
            for (int i = 0; i < rc; i++)
            {
                printReserve(reservas[i]);
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
                    ganancias -= reservas[i].getPrice();
                    reserva = createReserve(reservas[i].getId());

                    if (reserva.getId() == -1)
                    {
                        cout << "Hubo un error modificando la reserva. Por favor intentelo mas tarde" << endl;
                        ganancias += reservas[i].getPrice();
                        break;
                    }

                    reservas[i] = reserva;
                    ganancias += reserva.getPrice();
                    printReserve(reservas[i]);
                }
            }
            break;
        case 4:
            ganancias = 0;
            for (int i = 0; i < rc; i++)
            {
                ganancias += reservas[i].getPrice();
            }
            cout << "Se han generado: " << ganancias << "$ en ganancias" << endl;
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
    cout << "4.Ver Ganancias del dia" << endl;
    cout << "0.Salir" << endl;
    cout << "> ";
    cin >> *opc;
}

Reserva createReserve(int id)
{

    int t, d, pc, s, idCancha;
    bool h, natural;
    string cn;
    Reserva reserva;

    Cancha canchasDisponibles[size(canchas)];
    for (int i = 0; i < size(canchas); i++)
    {
        canchasDisponibles[i] = canchas[i];
    }
    int canchasDisponiblesContador = size(canchas);

    cout << "INGRESE SU NOMBRE: ";
    cin >> cn;
    reserva.setClientName(cn);

    cout << "INGRESE LA HORA DE RESERVA: ";
    cin >> t;
    if (t > 23 || t < 0)
    {
        return Reserva(-1, "EC: La hora de reserva debe ser valida(0-23)\n");
    }
    reserva.setTime(t);

    cout << "INGRESE LA CANTIDAD DE TIEMPO QUE RESERVA: ";
    cin >> d;
    cout << endl;
    if (d > 8)
    {
        return Reserva(-1, "EC: No es posible reservar canchas por mas de 8 horas\n");
    }
    reserva.setDuration(d);

    for (int i = 0; i < size(canchas); i++)
    {
        for (int j = 0; j < rc; j++)
        {
            bool sameField = reservas[j].getCancha().getId() == canchas[i].getId();

            bool startsEarlier = t <= reservas[j].getTime();
            bool endsLater = t + d > reservas[j].getTime();

            bool startsBeforeEnd = t < reservas[j].getTime() + reservas[j].getDuration();
            bool keepsGoing = t + d > reservas[j].getTime() + reservas[j].getDuration();

            bool endsBefore = t +d < reservas[j].getTime() + reservas[j].getDuration();

            bool sameTime = (startsEarlier) || (startsBeforeEnd && keepsGoing) || (startsBeforeEnd && endsBefore);
            if (reservas[j].getClientName() != "") {
                printReserve(reservas[j]);
            }
            if (sameField && sameTime)
            {
                canchasDisponibles[i] = Cancha(-1);
                canchasDisponiblesContador--;
            }
        }
    }

    if (canchasDisponiblesContador == 0)
    {
        reserva = Reserva();
        return Reserva(-1, "EC: No hay canchas disponibles en ese espacio.\n");
    }
    cout << "CANCHAS DISPONIBLES: " << endl;
    for (int i = 0; i < size(canchas); i++)
    {
        printField(canchasDisponibles[i]);
    }

    cout << "INGRESE EL ID DE LA CANCHA QUE DESEA RESERVAR: ";
    cin >> idCancha;
    reserva.setCancha(canchas[idCancha]);

    cout << "DESEA INCLUIR HIDRATACION?(0.NO 1.SI): ";
    cin >> h;
    if (h > 1 || h < 0)
    {
        return Reserva(-1, "EC: Ingrese un valor valido\n");
    }
    reserva.setIncludeHydration(h);

    int price = reserva.getCancha().getPricing() * reserva.getDuration();
    int waterTax = (reserva.getIncludeHydration() ? 20 : 0);
    reserva.setPrice(waterTax + price);

    reserva.setId(id);
    return reserva;
};

void printReserve(Reserva r)
{
    cout << "ID DE LA RESERVA: " << r.getId() << endl;
    cout << "ID DE CANCHA: " << r.getCancha().getId() << endl;
    cout << "TIPO DE CANCHA: " << r.getCancha().getGroundType() << endl;
    cout << "NOMBRE CLIENTE: " << r.getClientName() << endl;
    cout << "HORA DE LA RESERVA: " << r.getTime() << ":00" << endl;
    cout << "TIEMPO RESERVADO: " << r.getDuration() << endl;
    cout << "INCLUYE HIDRATACION: " << (r.getIncludeHydration() ? "SI" : "NO") << endl;
    cout << " ---------------------------------------" << endl;
    cout << "PRECIO DE LA CANCHA: " << r.getCancha().getPricing() << "$ ";
    cout << "* " << r.getDuration() << " horas: " << (r.getCancha().getPricing() * r.getDuration()) << "$" << endl;
    cout << "VALOR HIDRATACION: " << (r.getIncludeHydration() ? 20 : 0) << "$ " << endl;
    cout << "PRECIO DE LA RESERVA: " << r.getPrice() << endl;
    cout << " ---------------------------------------" << endl;
    cout << endl;
};

void printField(Cancha cancha)
{
    if (cancha.getId() == -1)
    {
        cout << "";
        return;
    }
    cout << "ID DE CANCHA: " << cancha.getId() << endl;
    cout << "TIPO DE CANCHA: " << cancha.getGroundType() << endl;
    cout << "CAPACIDAD DE LA CANCHA: " << cancha.getCapacity() << endl;
    cout << "PRECIO DE CANCHA: " << cancha.getPricing() << endl;
    cout << endl;
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
