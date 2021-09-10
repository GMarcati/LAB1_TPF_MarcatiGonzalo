////#############################################################################
// ARCHIVO : juego.h
// AUTOR : Gonzalo Marcati
// VERSION: 1.0 RTM.
// FECHA DE CREACION : 14/10/2018.
// ULTIMA ACTUALIZACION: 16/11/2018.
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE : Code::Blocks - 8.02 / 10.05
// COMPILADOR : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
// Funciones del juego batalla naval
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

using namespace std;

struct tCasilla
{
    char visible=' ';
    int barco;
    int fila;
    int columna;
    int direccion;
    bool tocado=false;
};

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : char validarOpcion(char*mensaje, char*mensajeError)
// ACCION : validar opcion ingresada.
// PARAMETROS: mensaje, mensaje error.
// DEVUELVE : true/false.
//-----------------------------------------------------------------------------
char validarOpcion(char*mensaje, char*mensajeError)
{

    char result;
    char ingreso[3];
    bool ingresoValido=false;

    do
    {

        cout << mensaje;
        sys::getline(ingreso,3);
        if(strlen(ingreso)==1)
        {
            ingresoValido=true;
        }
        else
        {
            sys::cls();
            cout << mensajeError;
            cin.get();

        }

    }
    while(!ingresoValido);
    result= ingreso[0];

    return result;
}

//=============================================================================
// FUNCION : void Instrucciones()
// ACCION : muestra las intrucciones por pantalla.
// PARAMETROS: nada.
// DEVUELVE : nada.
//-----------------------------------------------------------------------------
void Instrucciones()
{
     sys::cls();
            cout << "                                INSTRUCCIONES                                  " << endl;
            cout << "                                                                               " << endl;
            cout << "   JUEGO:                                                                      " << endl;
            cout << "   - El juego consiste en hundir toda la flota contrincante, que esta distri-  " << endl;
            cout << "   buida en el tablero.                                                        " << endl;
            cout << "                                                                               " << endl;
            cout << "   - El jugador debe indicar la coordenada a la cual desea atacar: un numero   " << endl;
            cout << "    entre 1 y 10 para la fila y un numero entre 1 y 10 para la columna.        " << endl;
            cout << "                                                                               " << endl;
            cout << "   - Si en la coordenada ingresada no hay ningun barco se indicara que tocaste " << endl;
            cout << "    agua con una 'A'.                                                          " << endl;
            cout << "                                                                               " << endl;
            cout << "   - Si en la coordenada ingresada hay parte de un barco, entonces el barco fue" << endl;
            cout << "   tocado y se vera una 'T'.                                                   " << endl;
            cout << "                                                                               " << endl;
            cout << "   - Si en la coordenada ingresada hay un barco, o si tocaste un barco por com-" << endl;
            cout << "    pleto, se vera el barco hundido con una o varias 'H'.                      " << endl;
            cout << "                                                                               " << endl;
            cout << "     Conteo de disparos:                                                     " << endl;
            cout << "      - Si el disparo impacta en una nave el tiro no se descuenta.            " << endl;
            cout << "      - Si el disparo impacta en el agua ('A'), en una parte del barco que ya habia sido impactada ('T')" << endl;
            cout << "        o en una nave hundida ('H'), el disparo se descuenta.                        " << endl;
            cout << "                                                                               " << endl;
            cout << "   NIVELES:                                                                 " << endl;
            cout << "   - Hay dos niveles para elegir:.                                             " << endl;
            cout << "      - Nivel 1:                                                              " << endl;
            cout << "        50 disparos disponibles.                                              " << endl;
            cout << "      - Nivel 2:                                                              " << endl;
            cout << "        25 disparos disponibles.                                              " << endl;
            cout << "                                                                              " << endl;
            cout << "                                                                               " << endl;
            cout << "                                                                               " << endl;
            cout << "   EXTRAS:                                                                   " << endl;
            cout << "   - Para ver por unica vez la ubicacion de los barcos por cuatro segundos in-  " << endl;
            cout << "      gresa las coordenadas 11:11                                              " << endl;
            cout << "                                                                               " << endl;
            cout << "   - Para ver las instrucciones del juego ingresa las coordenadas 9:11         " << endl;
            cout << "                                                                               " << endl;
            cout << "   - Para abandonar el juego ingresa las coordenadas 0:0.                      " << endl;
            cout << "                                                                               " << endl;
            cout << "   - El juego finaliza al hundir todos los barcos o al agotar tus tiros.       " << endl;
            cout << "                                                                               " << endl;
            cout << "                 Presione enter para regresar..                                " << endl;
            cin.get();
}

//=============================================================================
// FUNCION : int strToInt(char* cadena)
// ACCION : convierte una cadena de caracteres a un numero entero.
// PARAMETROS: cadena.
// DEVUELVE : entero.
//-----------------------------------------------------------------------------
int strToInt(char* cadena)
{
    int result=0;
    int valorPos=1;
    int n;
    for(int i=strlen(cadena)-1; i>=0; i--)
    {
        n=cadena[i]-48;
        result+=n*valorPos;
        valorPos=valorPos*10;
    }
    return result;
}

//=============================================================================
// FUNCION : int validarNumero(char*mensaje, char*mensajeError)
// ACCION : validar opcion ingresada.
// PARAMETROS: mensaje, mensaje error.
// DEVUELVE : entero.
//-----------------------------------------------------------------------------
int validarNumero(char*mensaje, char*mensajeError)
{
    int result;
    char ingreso[12];
    bool ingresoValido=false;
    int cant;
    do
    {
        cout << mensaje;
        sys::getline(ingreso,12);
        cant=0;
        for(int x=0; x<strlen(ingreso); x++)
        {
            if(ingreso[x]>='0' && ingreso[x]<='9')
            {
                cant++;
            }
        }
        if(cant==strlen(ingreso))
        {
            ingresoValido=true;
        }
        else
        {

            cout <<mensajeError;
            cin.get();
        }
    }
    while(!ingresoValido);
    result=strToInt(ingreso);

    return result;
}

//=============================================================================
// FUNCION : char validarOpcion(char*mensaje, char*mensajeError)
// ACCION : verificar si la opcion ingresada es incorrecta.
// PARAMETROS: mensaje, mensajeError.
// DEVUELVE : true/false.
//-----------------------------------------------------------------------------
char validarSoN(char*mensaje, char *mensajeError)
{

    bool result;
    char ingreso[3];
    bool ingresoValido=false;
    do
    {
        sys::cls();
        cout << mensaje;
        sys::getline(ingreso,3);
        if(strlen(ingreso)==1&&(ingreso[0]=='s'||ingreso[0]=='S'||ingreso[0]=='n'||ingreso[0]=='N'))
        {
            ingresoValido=true;
        }
        else
        {
            cout <<mensajeError<< endl;
            cout <<"Presione enter..";
            cin.get();


            sys::cls();
        }
    }
    while(!ingresoValido);
    result= (ingreso[0]=='s'|| ingreso[0]=='S');
    return result;
}

//=============================================================================
// FUNCION : void initMat(tCasilla mat[12][12])
// ACCION : inicializa las matrices en 0.
// PARAMETROS: matriz.
// DEVUELVE : nada.
//-----------------------------------------------------------------------------
void initMat(tCasilla mat[12][12])
{

    for(int f=0; f<12; f++)
    {

        for(int c=0; c<12; c++)
        {
            mat[f][c].barco=0;
        }
    }
}

//=============================================================================
// FUNCION : void mostrarMat(tCasilla mat[12][12])
// ACCION : muestra la parte de la matriz con los barcos.
// PARAMETROS: matriz.
// DEVUELVE : nada.
//-----------------------------------------------------------------------------
void mostrarMat(tCasilla mat[12][12])
{
    char x=221;
    cout << "                  " << endl;
    cout << "                  " << endl;

    cout <<"                          1   2   3   4   5   6   7   8   9   10 "<< endl;
    cout <<"                          " << x << "   " << x << "   " << x << "   "<< x << "   "<< x << "   "<< x << "   "<< x << "   "<< x << "   "<< x << "   "<< x << "   "<< endl;
    cout <<"                          " << "v" << "   " << "v" << "   " << "v" << "   "<< "v" << "   "<< "v" << "   "<< "v" << "   "<< "v" << "   "<< "v" << "   "<< "v" << "   "<< "v" << "   "<< endl;
    cout <<"                        +---+---+---+---+---+---+---+---+---+---+" <<endl;
    for(int f=1; f<11; f++)
    {
        if(f==10)
        {
            cout << "                  " ;
            cout << f ;
            cout << "--> ";
            cout << "|";
        }
        else
        {


            cout << "                  " ;
            cout << f ;
            cout << " --> ";
            cout << "|";
        }
        for(int c=1; c<11; c++)
        {
            cout << " " << mat[f][c].barco;
            cout << " |" ;

        }
        cout<< endl;
        cout <<"                        +---+---+---+---+---+---+---+---+---+---+" << endl;

    }


}

//=============================================================================
// FUNCION : void mostrarMatO(tCasilla mat[12][12])
// ACCION : muestra la parte visible de la matriz.
// PARAMETROS: matriz.
// DEVUELVE : nada.
//-----------------------------------------------------------------------------
void mostrarMatO(tCasilla mat[12][12])
{
    char x=221;
    cout << "                  " << endl;
    cout << "                  " << endl;

    cout <<"                          1   2   3   4   5   6   7   8   9   10 "<< endl;
    cout <<"                          " << x << "   " << x << "   " << x << "   "<< x << "   "<< x << "   "<< x << "   "<< x << "   "<< x << "   "<< x << "   "<< x << "   "<< endl;
    cout <<"                          " << "v" << "   " << "v" << "   " << "v" << "   "<< "v" << "   "<< "v" << "   "<< "v" << "   "<< "v" << "   "<< "v" << "   "<< "v" << "   "<< "v" << "   "<< endl;
    cout <<"                        +---+---+---+---+---+---+---+---+---+---+" <<endl;
    for(int f=1; f<11; f++)
    {
        if(f==10)
        {
            cout << "                  " ;
            cout << f ;
            cout << "--> ";
            cout << "|";
        }
        else
        {


            cout << "                  " ;
            cout << f ;
            cout << " --> ";
            cout << "|";
        }
        for(int c=1; c<11; c++)
        {
            cout << " " << mat[f][c].visible;
            cout << " |" ;

        }
        cout<< endl;
        cout <<"                        +---+---+---+---+---+---+---+---+---+---+" << endl;

    }


}

//=============================================================================
// FUNCION : bool tocaPared(int f,int c,int d,int tam)
// ACCION : verifica si esta tocando la pared.
// PARAMETROS: fila, columna, direccion, tamaño.
// DEVUELVE : true/false.
//-----------------------------------------------------------------------------
bool tocaPared(int f,int c,int d,int tam)
{

    if(d==0)
    {
        for(int f1=f ; f1<tam+f ; f1++)
        {
            for(int c1=c ; c1<=tam+c ; c1++)
            {
                if(c1==11)
                {
                    return true;
                }
            }
        }
    }
    else
    {
        for(int c1=c ; c1<tam+c ; c1++)
        {
            for(int f1=f ; f1<tam+f ; f1++)
            {
                if(f1==11)
                {
                    return true;
                }

            }
        }
    }
    return false;

}

//=============================================================================
// FUNCION : bool tocaBarco(tCasilla mat[12][12], int f,int c,int d,int tam)
// ACCION : verifica si no esta tocando otro barco.
// PARAMETROS: fila, columna, direccion, tamaño.
// DEVUELVE : true/false.
//-----------------------------------------------------------------------------
bool tocaBarco(tCasilla mat[12][12], int f,int c,int d,int tam)
{

    if(d==0)
    {

        for(int f2=f-1; f2<=f+1; f2++)
        {
            for(int c2=c-1; c2<=c+tam; c2++)
            {
                if(mat[f2][c2].barco!=0)
                {
                    return true;
                }
            }
        }
    }
    else
    {
        for(int c2=c-1; c2<=c+1; c2++)
        {
            for(int f2=f-1; f2<=f+tam; f2++)
            {
                if(mat[f2][c2].barco!=0)
                {
                    return true;
                }
            }
        }
    }

    return false;

}

//=============================================================================
// FUNCION : void colocarBarco(tCasilla mat[12][12], int f,int c,int d,int tam)
// ACCION : coloca el barco en la matriz.
// PARAMETROS: matriz, fila, columna, direccion, tamaño.
// DEVUELVE : nada.
//-----------------------------------------------------------------------------
void colocarBarco(tCasilla mat[12][12], int f,int c,int d,int tam)
{

    if (d==0)
    {
        for(int x=c; x<c+tam; x++)
        {
            mat[f][x].barco=tam;
            mat[f][x].direccion=d;
        }
    }
    else
    {
        for(int x=f; x<f+tam; x++)
        {
            mat[x][c].barco=tam;
            mat[x][c].direccion=d;
        }
    }

}

//=============================================================================
// FUNCION : void cargarBarco(tCasilla mat[12][12], int tam)
// ACCION : carga los barcos obteniendo coordenadas y direcciones aleatorias.
// PARAMETROS: matriz, tamaño.
// DEVUELVE : nada.
//-----------------------------------------------------------------------------
void cargarBarco(tCasilla mat[12][12], int tam)
{
    int f,c,d;
    // Obtengo coordenadas y la direccion aleatorias
    do
    {
        f=sys::random(10)+1;
        c=sys::random(10)+1;
        d=sys::random(2);
    }
    while(tocaPared(f,c,d,tam)||tocaBarco(mat,f,c,d,tam));
    colocarBarco(mat,f,c,d,tam);

}

//=============================================================================
// FUNCION : void CargarBarcos(tCasilla mat[12][12])
// ACCION : carga los barcos.
// PARAMETROS: matriz.
// DEVUELVE : nada.
//-----------------------------------------------------------------------------
void CargarBarcos(tCasilla mat[12][12])
{
    cargarBarco(mat,4);
    cargarBarco(mat,3);
    cargarBarco(mat,3);
    cargarBarco(mat,2);
    cargarBarco(mat,2);
    cargarBarco(mat,2);
    cargarBarco(mat,1);
    cargarBarco(mat,1);
    cargarBarco(mat,1);
    cargarBarco(mat,1);
}



//=============================================================================
// FUNCION : void MenuVisual(tCasilla mat[12][12],int cont)
// ACCION : menu para jugar que ve el usuario.
// PARAMETROS: matriz, entero(tiros disponibles).
// DEVUELVE : nada.
//-----------------------------------------------------------------------------
void MenuVisual(tCasilla mat[12][12],int cont)
{
    int fila;
    int columna;
    char enie=164;
    int c4=1,c3=2,c2=3,c1=4;
    int h2=0,h3=0,h4=0;
    int ct=c1+c2+c3+c4;
    bool flash=false;
    while(cont!=0&&ct!=0)
    {

        sys::cls();
        cout << "-> Para ver los barcos durante 4 segundos (Solo se permite UNA vez) ingrese las coordenadas 11:11." << endl;
        cout << endl;
        cout << "-> Para salir ingrese las coordenadas 0:0." << endl;
        cout << endl;
        cout << "-> Para ver la ayuda en linea ingrese las coordenadas 9:11." << endl;
        cout << endl;
        cout << "Tiros disponibles: " << cont << endl;
        cout << "Cantidad de barcos tama"<< enie << "o 1: " << c1 << endl;
        cout << "Cantidad de barcos tama"<< enie << "o 2: " << c2 << endl;
        cout << "Cantidad de barcos tama"<< enie << "o 3: " << c3 << endl;
        cout << "Cantidad de barcos tama"<< enie << "o 4: " << c4 << endl;
        mostrarMatO(mat);
        fila=validarNumero("[Numero de 1 a 10 para el tablero, fuera de ese rango opciones validas son las teclas especiales] \n"
                           "Ingrese fila: "
                           ,"Fila no valida \n"
                           "Presione enter.. ");
        columna=validarNumero("[Numero de 1 a 10 para el tablero, fuera de ese rango opciones validas son las teclas especiales] \n"
                              "Ingrese columna: "
                              ,"Columna no valida \n"
                              "Presione enter.. ");
if((fila&&columna>=0)&&(fila&&columna<=11))
{

        if(!flash)
        {
            sys::cls();
            if(fila==11&&columna==11)
            {

                mostrarMat(mat);
                sys::msleep(4);

                flash=true;
            }
        }
        else if(fila==11&&columna==11)
        {
            sys::cls();
            cout << endl;
            cout << "Las coordenadas 11:11 ya fueron utilizadas.";
            sys::msleep(2);
        }


        if(mat[fila][columna].visible=='T'||mat[fila][columna].visible=='H'||mat[fila][columna].visible=='A')
        {
            cont--;
        }

        if(mat[fila][columna].barco==0)
        {
            if(fila==11&columna==11||fila==9&columna==11||fila==0&columna==0)
            {

            }
            else if(mat[fila][columna].tocado==false)
            {
                mat[fila][columna].tocado=true;
                mat[fila][columna].visible='A';
                cont--;
            }

        }

        else if(mat[fila][columna].barco==1)
        {
            if(mat[fila][columna].tocado==false)
            {
                mat[fila][columna].tocado=true;
                mat[fila][columna].visible='H';
                c1--;
                ct--;
            }
        }
        else   if(mat[fila][columna].barco==2)
        {

            if(mat[fila][columna].tocado==false&&mat[fila][columna].visible!='H'&&mat[fila][columna].visible!='T')
            {

                h2++;
                mat[fila][columna].tocado==true;
                mat[fila][columna].visible='T';
                if(h2==2)
                {

                    if(mat[fila][columna].direccion==0)
                    {
                        if(mat[fila][columna].visible=='T'&&mat[fila][columna+1].visible=='T')
                        {
                            mat[fila][columna].visible='H';
                            mat[fila][columna+1].visible='H';
                        }
                        else if(mat[fila][columna].visible=='T'&&mat[fila][columna-1].visible=='T')
                        {
                            mat[fila][columna].visible='H';
                            mat[fila][columna-1].visible='H';
                        }


                        c2--;
                    }
                    else if(mat[fila][columna].direccion==1)
                    {
                        if(mat[fila][columna].visible=='T'&&mat[fila-1][columna].visible=='T')
                        {
                            mat[fila][columna].visible='H';
                            mat[fila-1][columna].visible='H';
                        }
                        else if(mat[fila][columna].visible=='T'&&mat[fila+1][columna].visible=='T')
                        {
                            mat[fila][columna].visible='H';
                            mat[fila+1][columna].visible='H';
                        }
                        c2--;

                    }
                    ct--;
                    h2=0;
                }

            }
        }
        else  if(mat[fila][columna].barco==3)
        {

            if(mat[fila][columna].tocado==false&&mat[fila][columna].visible!='H'&&mat[fila][columna].visible!='T')
            {
                h3++;
                mat[fila][columna].tocado==true;
                mat[fila][columna].visible='T';
                if(h3==3)
                {

                    if(mat[fila][columna].direccion==0)
                    {
                        if(mat[fila][columna].visible=='T'&&mat[fila][columna+2].visible=='T')
                        {
                            mat[fila][columna].visible='H';
                            mat[fila][columna+1].visible='H';
                            mat[fila][columna+2].visible='H';
                        }
                        else if(mat[fila][columna].visible=='T'&&mat[fila][columna-2].visible=='T')
                        {
                            mat[fila][columna].visible='H';
                            mat[fila][columna-1].visible='H';
                            mat[fila][columna-2].visible='H';
                        }
                        else if(mat[fila][columna].visible=='T'&&mat[fila][columna+1].visible=='T'&&mat[fila][columna-1].visible=='T')
                        {
                            mat[fila][columna-1].visible='H';
                            mat[fila][columna].visible='H';
                            mat[fila][columna+1].visible='H';
                        }


                        c3--;
                    }
                    else if(mat[fila][columna].direccion==1)
                    {
                        if(mat[fila][columna].visible=='T'&&mat[fila-2][columna].visible=='T')
                        {
                            mat[fila][columna].visible='H';
                            mat[fila-1][columna].visible='H';
                            mat[fila-2][columna].visible='H';
                        }
                        else if(mat[fila][columna].visible=='T'&&mat[fila+2][columna].visible=='T')
                        {
                            mat[fila][columna].visible='H';
                            mat[fila+1][columna].visible='H';
                            mat[fila+2][columna].visible='H';
                        }
                        else if(mat[fila][columna].visible=='T'&&mat[fila+1][columna].visible=='T'&&mat[fila-1][columna].visible=='T')
                        {
                            mat[fila-1][columna].visible='H';
                            mat[fila][columna].visible='H';
                            mat[fila+1][columna].visible='H';
                        }
                        c3--;
                    }
                    ct--;
                    h3=0;
                }
            }

        }
        else if(mat[fila][columna].barco==4)
        {
            if(mat[fila][columna].tocado==false&&mat[fila][columna].visible!='H'&&mat[fila][columna].visible!='T')
            {
                h4++;
                mat[fila][columna].tocado==true;
                mat[fila][columna].visible='T';
                if(h4==4)
                {

                    if(mat[fila][columna].direccion==0)
                    {
                        if(mat[fila][columna].visible=='T'&&mat[fila][columna+3].visible=='T')
                        {
                            mat[fila][columna].visible='H';
                            mat[fila][columna+1].visible='H';
                            mat[fila][columna+2].visible='H';
                            mat[fila][columna+3].visible='H';
                        }
                        else if(mat[fila][columna].visible=='T'&&mat[fila][columna-3].visible=='T')
                        {
                            mat[fila][columna].visible='H';
                            mat[fila][columna-1].visible='H';
                            mat[fila][columna-2].visible='H';
                            mat[fila][columna-3].visible='H';
                        }
                        else if(mat[fila][columna].visible=='T'&&mat[fila][columna-1].visible=='T'&&mat[fila][columna+1].visible=='T'&&mat[fila][columna+2].visible=='T')
                        {
                            mat[fila][columna-1].visible='H';
                            mat[fila][columna].visible='H';
                            mat[fila][columna+1].visible='H';
                            mat[fila][columna+2].visible='H';
                        }
                        else if(mat[fila][columna].visible=='T'&&mat[fila][columna+1].visible=='T'&&mat[fila][columna-1].visible=='T'&&mat[fila][columna-2].visible=='T')
                        {
                            mat[fila][columna+1].visible='H';
                            mat[fila][columna].visible='H';
                            mat[fila][columna-1].visible='H';
                            mat[fila][columna-2].visible='H';
                        }


                        c4--;
                    }
                    else if(mat[fila][columna].direccion==1)
                    {
                        if(mat[fila][columna].visible=='T'&&mat[fila-3][columna].visible=='T')
                        {
                            mat[fila][columna].visible='H';
                            mat[fila-1][columna].visible='H';
                            mat[fila-2][columna].visible='H';
                            mat[fila-3][columna].visible='H';
                        }
                        else if(mat[fila][columna].visible=='T'&&mat[fila+3][columna].visible=='T')
                        {
                            mat[fila][columna].visible='H';
                            mat[fila+1][columna].visible='H';
                            mat[fila+2][columna].visible='H';
                            mat[fila+3][columna].visible='H';
                        }
                        else if(mat[fila][columna].visible=='T'&&mat[fila-1][columna].visible=='T'&&mat[fila+1][columna].visible=='T'&&mat[fila+2][columna].visible=='T')
                        {
                            mat[fila-1][columna].visible='H';
                            mat[fila][columna].visible='H';
                            mat[fila+1][columna].visible='H';
                            mat[fila+2][columna].visible='H';
                        }
                        else if(mat[fila][columna].visible=='T'&&mat[fila+1][columna].visible=='T'&&mat[fila-1][columna].visible=='T'&&mat[fila-2][columna].visible=='T')
                        {
                            mat[fila+1][columna].visible='H';
                            mat[fila][columna].visible='H';
                            mat[fila-1][columna].visible='H';
                            mat[fila-2][columna].visible='H';
                        }
                        c4--;
                    }
                    ct--;
                    h4=0;
                }
            }



        }

        if(fila==9&&columna==11)
        {
           Instrucciones();
        }



    }
    if(fila==0&&columna==0)
    {
        sys::cls();
        if(validarSoN("SEGURO QUE QUERES SALIR? [Ingrese S o N]: ","Elija una opcion valida, S o N. "))
            {
                sys::cls();
                cont=0;

        cout << "                                                     uuuuuuu " << endl;
        cout << "                                                 uu$$$$$$$$$$$uu "<< endl;
        cout << "                                              uu$$$$$$$$$$$$$$$$$uu "<< endl;
        cout << "                                             u$$$$$$$$$$$$$$$$$$$$$u "<< endl;
        cout << "                                            u$$$$$$$$$$$$$$$$$$$$$$$u "<< endl;
        cout << "                                           u$$$$$$$$$$$$$$$$$$$$$$$$$u "<< endl;
        cout << "                                           u$$$$$$$$$$$$$$$$$$$$$$$$$u "<< endl;
        cout << "                                           u$$$$$$'   '$$$'   '$$$$$$u "<< endl;
        cout << "                                           '$$$$'      u$u      '$$$$' "<< endl;
        cout << "                                            $$$u       u$u       u$$$ "<< endl;
        cout << "                                            $$$u      u$$$u      u$$$ "<< endl;
        cout << "                                            '$$$$uu$$$   $$$uu$$$$' "<< endl;
        cout << "                                              '$$$$$$$'   '$$$$$$$' "<< endl;
        cout << "                                                u$$$$$$$u$$$$$$$u "<< endl;
        cout << "                                                 u$'$'$'$'$'$'$u "<< endl;
        cout << "                                      uuu        $$u$ $ $ $ $u$$       uuu "<< endl;
        cout << "                                      u$$$$        $$$$$u$u$u$$$       u$$$$ "<< endl;
        cout << "                                      $$$$$uu      '$$$$$$$$$'     uu$$$$$$ "<< endl;
        cout << "                                     u$$$$$$$$$$$uu    '''''    uuuu$$$$$$$$$$ "<< endl;
        cout << "                                     $$$$'$$$$$$$$$$uuu   uu$$$$$$$$$'''$$$' "<< endl;
        cout << "                                      '''      '$$$$$$$$$$$uu ''$''' " << endl;
        cout << "                                              uuuu ''$$$$$$$$$$uuu  "<< endl;
        cout << "                                     u$$$uuu$$$$$$$$$uu ''$$$$$$$$$$$uuu$$$  "<< endl;
        cout << "                                      $$$$$$$$$$''''           ''$$$$$$$$$$$"<< endl;
        cout << "                                     '$$$$$'                      ''$$$$''  "<< endl;
        cout << "                                      $$$'                         $$$$'  "<< endl;
        cout << "                                                              " << endl;
        cout << "                                                             )___(" << endl;
        cout << "                                                     _______/__/_" << endl;
        cout << "                                            ___     /===========|   ___" << endl;
        cout << "                           ____       __   [\\\\\\]___/____________|__[///]   __" << endl;
        cout << "                           \\   \\_____[\\\\]__/___________________________\\__[//]___" << endl;
        cout << "                            \\                                                    |" << endl;
        cout << "                             \\                G A M E  O V E R                  /" << endl;
        cout << "                              \\              SALISTE DEL JUEGO..               / " << endl;
        cout << "                               \\                                              /" << endl;
        cout << "                          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        sys::msleep(3);
            } else
            {

                cout << endl;
                cout << "Volvemos a jugar!"<<endl;
                cout << "Presione enter..";
                cin.get();

            }
    }
    else if((cont==0&&ct==0)||ct==0)
    {
        sys::cls();

        cout << "                                           _____" << endl;
        cout << "                                        ,-'     '-." << endl;
        cout << "                                       / o       o \\ " << endl;
        cout << "                                      /   \\     /   \\ " << endl;
        cout << "                                     /     )-'-(     \\ " << endl;
        cout << "                                    /     ( 6 6 )     \\ " << endl;
        cout << "                                   /       \\ ' /       \\ " << endl;
        cout << "                                  /         )=(         \\ " << endl;
        cout << "                                 /   o   .--'-'--.   o   \\ " << endl;
        cout << "                                /    I  /  -   -  \\  I    \\ " << endl;
        cout << "                            .--(    (_}y/\\       /\\y{_)    )--." << endl;
        cout << "                           (    '.___l\\/__\\_____/__\\/l___,'    )" << endl;
        cout << "                           \\                                 /" << endl;
        cout << "                            '-._      o O o O o O o      _,-'" << endl;
        cout << "                                `--Y--.___________.--Y--'" << endl;
        cout << "                                   |==.___________.==| " << endl;
        cout << "                                   '==.___________.==' " << endl;
        cout << "                                                              " << endl;
        cout << "                                                             )___(" << endl;
        cout << "                                                     _______/__/_" << endl;
        cout << "                                            ___     /===========|   ___" << endl;
        cout << "                           ____       __   [\\\\\\]___/____________|__[///]   __" << endl;
        cout << "                           \\   \\_____[\\\\]__/___________________________\\__[//]___" << endl;
        cout << "                            \\                                                    |" << endl;
        cout << "                             \\                G A M E  O V E R                  /" << endl;
        cout << "                              \\         FELICITACIONES! GANASTE EL JUEGO.      / " << endl;
        cout << "                               \\        Tiros restantes: " << cont << "                   /" << endl;
        cout << "                          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "                          TABLERO:                                                      " << endl;
        mostrarMat(mat);
        sys::msleep(8);
    }
    else if (cont==0&&ct!=0)
    {
        sys::cls();




        cout << "                                                     uuuuuuu " << endl;
        cout << "                                                 uu$$$$$$$$$$$uu "<< endl;
        cout << "                                              uu$$$$$$$$$$$$$$$$$uu "<< endl;
        cout << "                                             u$$$$$$$$$$$$$$$$$$$$$u "<< endl;
        cout << "                                            u$$$$$$$$$$$$$$$$$$$$$$$u "<< endl;
        cout << "                                           u$$$$$$$$$$$$$$$$$$$$$$$$$u "<< endl;
        cout << "                                           u$$$$$$$$$$$$$$$$$$$$$$$$$u "<< endl;
        cout << "                                           u$$$$$$'   '$$$'   '$$$$$$u "<< endl;
        cout << "                                           '$$$$'      u$u      '$$$$' "<< endl;
        cout << "                                            $$$u       u$u       u$$$ "<< endl;
        cout << "                                            $$$u      u$$$u      u$$$ "<< endl;
        cout << "                                            '$$$$uu$$$   $$$uu$$$$' "<< endl;
        cout << "                                              '$$$$$$$'   '$$$$$$$' "<< endl;
        cout << "                                                u$$$$$$$u$$$$$$$u "<< endl;
        cout << "                                                 u$'$'$'$'$'$'$u "<< endl;
        cout << "                                      uuu        $$u$ $ $ $ $u$$       uuu "<< endl;
        cout << "                                      u$$$$        $$$$$u$u$u$$$       u$$$$ "<< endl;
        cout << "                                      $$$$$uu      '$$$$$$$$$'     uu$$$$$$ "<< endl;
        cout << "                                     u$$$$$$$$$$$uu    '''''    uuuu$$$$$$$$$$ "<< endl;
        cout << "                                     $$$$'$$$$$$$$$$uuu   uu$$$$$$$$$'''$$$' "<< endl;
        cout << "                                      '''      '$$$$$$$$$$$uu ''$''' " << endl;
        cout << "                                              uuuu ''$$$$$$$$$$uuu  "<< endl;
        cout << "                                     u$$$uuu$$$$$$$$$uu ''$$$$$$$$$$$uuu$$$  "<< endl;
        cout << "                                      $$$$$$$$$$''''           ''$$$$$$$$$$$"<< endl;
        cout << "                                     '$$$$$'                      ''$$$$''  "<< endl;
        cout << "                                      $$$'                         $$$$'  "<< endl;
        cout << "                                                              " << endl;
        cout << "                                                             )___(" << endl;
        cout << "                                                     _______/__/_" << endl;
        cout << "                                            ___     /===========|   ___" << endl;
        cout << "                           ____       __   [\\\\\\]___/____________|__[///]   __" << endl;
        cout << "                           \\   \\_____[\\\\]__/___________________________\\__[//]___" << endl;
        cout << "                            \\                                                    |" << endl;
        cout << "                             \\                G A M E  O V E R                  /" << endl;
        cout << "                              \\              PERDISTE EL JUEGO..               / " << endl;
        cout << "                               \\        Barcos restantes: " << ct << "                   /" << endl;
        cout << "                          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "                          TABLERO:                                                        " << endl;
        mostrarMat(mat);
        sys::msleep(8);
    }

    }
}

//=============================================================================
// FUNCION : void MenuDificultad(tCasilla mat[12][12])
// ACCION : menu para elegir las dificultades.
// PARAMETROS: matriz.
// DEVUELVE : nada.
//-----------------------------------------------------------------------------
void MenuDificultad(tCasilla mat[12][12])
{
    initMat(mat);
    CargarBarcos(mat);
    char dif;
    bool menu2=false;
    while(!menu2)
    {
        sys::cls();
        cout << "Elija un nivel de dificultad: " << endl;
        cout << "                              " << endl;
        cout << " [Ingrese A] --> Nivel 1 - para ser Grumete [50 disparos disponibles]   "  << endl;
        cout << " [Ingrese B] --> Nivel 2 - para ser Almirante [25 disparos disponibles] " << endl;
        cout << endl;
        dif=validarOpcion("  Opcion: ","Elija un nivel de dificultad: \n"
                          "                              \n"
                          " [Ingrese A] --> Nivel 1 - para ser Grumete [50 disparos disponibles]   \n"
                          " [Ingrese B] --> Nivel 2 - para ser Almirante [25 disparos disponibles] \n"
                          "  \n"
                          "  Opcion no valida.\n"
                          "  Presione enter..");
        switch(dif)
        {
        case 'a':
        case 'A':
        {
            cout << endl;
            cout << "Elegiste Grumete - 50 disparos disponibles" << endl;
            cout << "Presione enter..";
            cin.get();
            menu2=true;
            MenuVisual(mat,50);
        }
        break;
        case 'b':
        case 'B':
        {
            cout << endl;
            cout << "Elegiste Almirante - 25 disparos disponibles" << endl;
            cout << "Presione enter..";
            cin.get();
            menu2=true;
            MenuVisual(mat,25);
        }
        break;
        default:
        {
            sys::cls();
            cout << endl;
            cout << "  Opcion no valida." << endl;
            cout << "  Presione enter.. ";
            cin.get();
        }
        break;
        }

    }
}

#endif // JUEGO_H_INCLUDED
