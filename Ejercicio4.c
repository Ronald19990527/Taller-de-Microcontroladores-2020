/*
4. A usted se le ha contratado para romper la seguridad de una cuenta de Facebook,
el usuario que perdió la contraseña solo recuerda que era una contraseña de 6
caracteres alfabéticos en minúsculas (a-z).

Este tipo de contraseñas es posible encontrarlas con un ataque de fuerza bruta (ir
probando combinaciones hasta encontrar la coincidencia). La contraseña estará
almacenada en un vector ej: pass[] = “axzptd”.

Al finalizar el programa debe mostrar la contraseña encontrada y cuantos intentos
realizó.
*/

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	unsigned int delay = 0, intentos = 0, longitudContrasenia = 0, incializarArregloAuxiliar = 0, iterarArregloAuxiliar = 0, posicionActualIteracion = 0, imprimirArregloAuxiliar = 0, terminarPrograma = 0;
	short romperCiclo = 0;
	unsigned char iterarCaracteres = 'a', *auxPass, pass[] = "zab";

	while ( pass[ longitudContrasenia ] != '\0' )
		longitudContrasenia++;

	auxPass = ( unsigned char * ) calloc( longitudContrasenia, sizeof( unsigned char ) );

	for ( incializarArregloAuxiliar = 0; incializarArregloAuxiliar < longitudContrasenia; incializarArregloAuxiliar++ )
		auxPass[ incializarArregloAuxiliar ] = 'a';

	while ( iterarArregloAuxiliar < longitudContrasenia && terminarPrograma != longitudContrasenia ) {
		intentos++;

		terminarPrograma = 0;

		auxPass[ posicionActualIteracion ] = iterarCaracteres++;

		if ( iterarCaracteres > 'z' )
			iterarCaracteres = 'a';

		for ( imprimirArregloAuxiliar = 0; imprimirArregloAuxiliar < longitudContrasenia; imprimirArregloAuxiliar++ )
			printf( "%c", auxPass[ imprimirArregloAuxiliar ] );

		for ( delay = 0; delay <= 100000000; delay++ )
			if ( delay < longitudContrasenia && auxPass[ delay ] == pass[ delay ] )
				terminarPrograma++;

		if ( terminarPrograma == longitudContrasenia )
			printf( " => Contrase%ca Encontrada en %u intentos\n", 164, intentos );
		else
			printf( " => Combinaci%cn\n", 162 );

		if ( iterarCaracteres == 'a' && terminarPrograma != longitudContrasenia ) {
			while ( romperCiclo == 0 && posicionActualIteracion < longitudContrasenia && auxPass[ posicionActualIteracion ] == 'z' ) {
				posicionActualIteracion++;

				if ( posicionActualIteracion < longitudContrasenia )
					if ( auxPass[ posicionActualIteracion ] < 'z' ) {
						auxPass[ posicionActualIteracion ]++;

						romperCiclo = 1;
					}
			}

			romperCiclo = 0;

			if ( posicionActualIteracion > iterarArregloAuxiliar )
				iterarArregloAuxiliar = posicionActualIteracion;

			while ( posicionActualIteracion > 0 ) {
				posicionActualIteracion--;

				auxPass[ posicionActualIteracion ] = 'a';
			}
		}
	}

	free( auxPass );

	return 0;
}
