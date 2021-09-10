//#############################################################################
// ARCHIVO             : main.cpp
// AUTOR/ES            : Gonzalo Marcati
// VERSION             : 1.0 RTM.
// FECHA DE CREACION   : 14/10/2018.
// ULTIMA ACTUALIZACION: 16/11/2018.
// LICENCIA            : GPL (General Public License) - Version 3.
//
//  **************************************************************************
//  * El software libre no es una cuestion economica sino una cuestion etica *
//  **************************************************************************
//
// Este programa es software libre;  puede redistribuirlo  o  modificarlo bajo
// los terminos de la Licencia Publica General de GNU  tal como se publica por
// la  Free Software Foundation;  ya sea la version 3 de la Licencia,  o (a su
// eleccion) cualquier version posterior.
//
// Este programa se distribuye con la esperanza  de que le sea util,  pero SIN
// NINGUNA  GARANTIA;  sin  incluso  la garantia implicita de MERCANTILIDAD  o
// IDONEIDAD PARA UN PROPOSITO PARTICULAR.
//
// Vea la Licencia Publica General GNU para mas detalles.
//
// Deberia haber recibido una copia de la Licencia Publica General de GNU junto
// con este proyecto, si no es asi, escriba a la Free Software Foundation, Inc,
// 59 Temple Place - Suite 330, Boston, MA 02111-1307, EE.UU.

//=============================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE                 : Code::Blocks - 8.02 / 10.05
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
//              Menu de batalla naval.
//
////////////////////////////////////////////////////////////////////////////////

//*****************************************************************************
//                       CONFIGURACION MULTIPLATAFORMA
//=============================================================================
// COMPILACION EN WINDOWS
//-----------------------------------------------------------------------------
// Si este programa se va a compilar en Windows, descomente las tres lineas
// siguientes, y comente las tres lineas de "COMPILACION EN LINUX".
//-----------------------------------------------------------------------------
#ifndef _WIN32
# define _WIN32
#endif

//=============================================================================
// COMPILACION EN LINUX
//-----------------------------------------------------------------------------
// Si este programa se va a compilar en Linux, descomente las tres lineas
// siguientes, y comente las tres lineas de "COMPILACION EN WINDOWS".
//-----------------------------------------------------------------------------
//#ifndef _LINUX
//  # define _LINUX
//#endif

//*****************************************************************************
//                             INCLUSIONES ESTANDAR
//=============================================================================
#include <iostream> // Libreria de flujos de  Entrada/Salida  que contiene  los
// objetos cin, cout y endl.

#include <cstdlib>  // Libreria estandar que contiene la funcion exit().

//*****************************************************************************
//                             INCLUSIONES PERSONALES
//=============================================================================
#include "CSYSTEM/csystem.h" // Libreria para multiplataforma.
#include "juego.h"
#include <cstring>
//==============================================================================
// DECLARACION DEL ESPACIO DE NOMBRES POR DEFECTO
//------------------------------------------------------------------------------
using namespace std;


//==============================================================================
// FUNCION PRINCIPAL - PUNTO DE INICIO DEL PROYECTO
//------------------------------------------------------------------------------
int main()
{
    cout << "                         |----.___" << endl;
    cout << "                                |----.___'," << endl;
    cout << "              ._________________|_______________." << endl;
    cout << "              |####|    |####|    |####|   |####|" << endl;
    cout << "              |####|    |####|    |####|    |####|       ." << endl;
    cout << "              |####|    |####|    |####|    |####|     /|_____." << endl;
    cout << " __           |####|    |####|    |####|    |####|   |  o  ..|" << endl;
    cout << "(  '.         '####|    '####|    '####|    '####|   '.  .vvv'" << endl;
    cout << " '@ |          |####.    |####.    |####.    |####|    ||" << endl;
    cout << "  | |          '####.    '####.    '####.    '####.    ||" << endl;
    cout << " /  |         /####.    /####.    /####.    /####.     |'." << endl;
    cout << "|    |       '####/    '####/    '####/    '####/      |  |" << endl;
    cout << "|     |  .  /####|____/####|____/####|____/####|      |    |" << endl;
    cout << "|      |//   .#'#. .*'*. .#'#. .*'*. .#'#. .*'*.     |      |" << endl;
    cout << " |     //-...#'#'#-*'*'*-#'#'#-*'*'*-#'#'#-*'*'*-...'        |" << endl;
    cout << "  |   //     '#'#' '*'*' '#'#' '*'*' '#'#' '*'*'             |" << endl;
    cout << "  |  //                                                      |" << endl;
    cout << "  './/            B A T A L L A  N A V A L                  .'" << endl;
    cout << "  _//'._            By Gonzalo Marcati                  __.'" << endl;
    cout << " /  /   '----------------------------------------------'" << endl;

    sys::msleep(2);
    char op;
    bool menu=false;
    tCasilla tablero[12][12];
    sys::randomize();
    while(!menu)
    {
        sys::cls();
        cout << "                _______________ " << endl;
        cout << "               | BATALLA NAVAL |" << endl;
        cout << "               |_______________|" << endl;
        cout << "               |A- Jugar       |" << endl;
        cout << "               |B- Ayuda       |" << endl;
        cout << "               |C- Salir       |" << endl;
        cout << "               |_______________|" << endl;
        op=validarOpcion("               Ingrese una opcion valida: ", "                _______________  \n"
                         "               | BATALLA NAVAL |\n"
                         "               |_______________|\n"
                         "               |A- Jugar       |\n"
                         "               |B- Ayuda       |\n"
                         "               |C- Salir       |\n"
                         "               |_______________|\n"
                         "                Opcion no valida.\n"
                         "                Presione enter..");

        switch(op)
        {
        case 'a':
        case 'A':
        {

            MenuDificultad(tablero);
            return 0;

        }
        break;
        case 'b':
        case 'B':
        {
            Instrucciones();
        }
        break;
        case 'c':
        case 'C':
        {
            if(validarSoN("SEGURO QUE QUERES SALIR? [Ingrese S o N]: ","Elija una opcion valida, S o N. "))
            {
                menu=true;
            }
            else
            {
                cout << endl;
                cout << "Volvemos al menu!"<<endl;
                cout << "Presione enter..";
                cin.get();
            }


        }
        break;
        default:
        {
            cout << "               Opcion no valida." << endl;
            cout << "               Presione enter.. ";
            cin.get();
        }
        break;
        }

    }
    sys::cls();
    cout << "                                    " << endl;
    cout << "                                   )___(" << endl;
    cout << "                           _______/__/_" << endl;
    cout << "                  ___     /===========|   ___" << endl;
    cout << " ____       __   [\\\\\\]___/____________|__[///]   __" << endl;
    cout << " \\   \\_____[\\\\]__/___________________________\\__[//]___" << endl;
    cout << "  \\                                                    |" << endl;
    cout << "   \\                G A M E  O V E R                  /" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    sys::msleep(3);



    //--------------------------------------------------------------------------
    // FIN DE LA FUNCION main() SIN ERRORES.
    //--------------------------------------------------------------------------
    return 0;
}

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

