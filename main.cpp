#include <iostream>
#include "Cancha.h"
#include "Reserva.h"
using namespace std;

void calculateReservePrice(Reserva &reserva, Cancha c);
Reserva createReserve(int id);
void printReserve(Reserva r);

void menu(int *opc);

int minPc = 5;
int maxPc = 8;

Cancha canchas[]{
    // Cancha(),
    // Cancha("sintetica", 84, 7),
    Cancha("sintetica", 100, 8,false),

    // Cancha("natural", 80, 5),
    // Cancha("natural", 100, 7),
    // Cancha("natural", 120, 8),

};

Reserva reservas[6];

int main()
{
    Reserva reserva;
    int t, d, pc, opc, id;
    int rc = 0;
    bool h, natural;
    string cn;
    int ganancias = 0;

    do
    {
        menu(&opc);
        switch (opc)
        {
        case 1:
            if (rc > 5)
            {
                cout << "Lo sentimos no hay canchas disponibles para";
                break;
            }
            reserva = createReserve(rc);
            if (reserva.getClientName()[0] == 'E')
            {
                cout << "Hubo un error creando su reserva. Intentelo mas tarde" << endl;
                cout << reserva.getClientName();
                break;
            }
            reservas[rc] = reserva;
            ganancias += reserva.getPrice();
            rc++;

            printReserve(reservas[rc - 1]);

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
                    if (reserva.getClientName() == "ERROR CODE")
                    {
                        cout << "Hubo un error modificando la reserva. Por favor intentelo mas tarde" << endl;
                        break;
                    }

                    ganancias += reserva.getPrice();
                    reservas[i] = reserva;
                    printReserve(reservas[i]);
                }
            }
            break;
        case 4:
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
    cout << "4.Ver Ganacias del dia" << endl;
    cout << "0.Salir" << endl;
    cout << "> ";
    cin >> *opc;
}

Reserva createReserve(int id)
{

    int t, d, pc;
    bool h, natural;
    string cn;
    Reserva reserva;

    cout << "INGRESE SU NOMBRE: ";
    cin >> cn;

    cout << "INGRESE SU LA CANTIDAD DE JUGADORES: ";
    cin >> pc;
    if (pc > maxPc || pc < minPc)
    {
        return Reserva(-1, "EC: Ingrese una cantidad de jugadores valida. (5-8)");
    }

    cout << "CANCHA NATURAL?(0.NO, 1.SI): ";
    cin >> natural;
    if (natural > 1 || natural < 0)
    {
        return Reserva(-1, "EC: Ingrese un valor valido");
    }

    cout << "INGRESE LA HORA DE RESERVA: ";
    cin >> t;
    if (t > 23 || t < 0)
    {
        return Reserva(-1, "EC: La hora de reserva debe ser valida(0-23)");
    }

    cout << "INGRESE LA CANTIDAD DE TIEMPO DE RESERVA: ";
    cin >> d;
    if (d > 8)
    {
        return Reserva(-1, "EC: No es posible reservar canchas por mas de 8 horas");
    }

    cout << "DESEA INCLUIR HIDRATACION?(0.NO 1.SI): ";
    cin >> h;
    if (h > 1 || h < 0)
    {
        return Reserva(-1, "EC: Ingrese un valor valido");
    }
    cout << endl;

    for (int i = 0; i < size(canchas); i++)
    {
        Cancha cancha = canchas[i];
        if (cancha.getIsAvailable() == false) {
            return Reserva(-1, "EC: No hay canchas disponibles en este momento");
        };
        if (cancha.getCapacity() >= pc && cancha.getGroundType() == (natural ? "natural" : "sintetica"))
        {
            cancha.setIsAvailable(false);
            reserva.setCancha(cancha);
        }
    }
    reserva.setId(id);
    reserva.setClientName(cn);
    reserva.setTime(t);
    reserva.setDuration(d);
    reserva.setPlayerCount(pc);
    reserva.setIncludeHydration(h);
    reserva.setPrice((reserva.getIncludeHydration() ? 20 : 0) + (reserva.getCancha().getPricing() * reserva.getDuration()));
    return reserva;
};

void printReserve(Reserva r)
{
    cout << "ID DE LA RESERVA: " << r.getId() << endl;
    cout << "TIPO DE CANCHA: " << r.getCancha().getGroundType() << endl;
    cout << "NOMBRE CLIENTE: " << r.getClientName() << endl;
    cout << "HORA DE LA RESERVA: " << r.getTime() << ":00" << endl;
    cout << "TIEMPO RESERVADO: " << r.getDuration() << endl;
    cout << "INCLUYE HIDRATACION: " << (r.getIncludeHydration() ? "SI" : "NO") << endl;
    cout << "CANTIDAD DE JUGADORES: " << r.getPlayerCount() << endl;
    cout << " ---------------------------------------" << endl;
    cout << "PRECIO DE LA CANCHA: " << r.getCancha().getPricing() << "$ ";
    cout << "* " << r.getDuration() << " horas " << (r.getCancha().getPricing() * r.getDuration()) << "" << endl;
    cout << "VALOR HIDRATACION: " << (r.getIncludeHydration() ? 20 : 0) << "$ " << endl;
    cout << "PRECIO DE LA RESERVA: " << r.getPrice() << endl;
    cout << " ---------------------------------------" << endl;
    cout << "" << endl;
    cout << endl;
};

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
