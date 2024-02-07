/*
1. Dado un vector definido como: 

unsigned char palabras[] = “amor, bueno, anillo, cuatro, dado, fecha, iglesia,
jabon”

Realice un programa que organice las palabras por orden alfabético. Tenga en cuenta
que la cantidad de palabras puede cambiar, al igual que las palabras en si.
*/

#include <stdio.h> // incluir el encabezado estandar de entrada/salida. 
#include <stdlib.h> // strings y vectores.

void impimirCaracterConTildeMinuscula( unsigned char caracterConTilde );

void impimirCaracterConTildeMayuscula( unsigned char caracterConTilde );

unsigned char detectarLetraConTilde( unsigned char caracterConTilde );

unsigned char detectarEnieUconDieresis( unsigned char enieUconDieresis );

void impimirCaracterConTildeMinuscula( unsigned char caracterConTilde )
{
	switch ( caracterConTilde ) {
		case 225:
			printf( "%c", 160 );
			break;

		case 237:
			printf( "%c", 161 );
			break;

		case 243:
			printf( "%c", 162 );
			break;

		case 250:
			printf( "%c", 163 );
			break;

		case 233:
			printf( "%c", 130 );
			break;

		case 241:
			printf( "%c", 164 );
			break;

		case 252:
			printf( "%c", 129 );
	}
}

void impimirCaracterConTildeMayuscula( unsigned char caracterConTilde )
{
	switch ( caracterConTilde ) {
		case 193:
			printf( "%c", 181 );
			break;

		case 201:
			printf( "%c", 144 );
			break;

		case 205:
			printf( "%c", 214 );
			break;

		case 211:
			printf( "%c", 224 );
			break;

		case 218:
			printf( "%c", 233 );
			break;

		case 209:
			printf( "%c", 165 );
			break;

		case 220:
			printf( "%c", 154 );
	}
}

unsigned char detectarLetraConTilde( unsigned char caracterConTilde )
{
	switch ( caracterConTilde ) {
		case 225:
		case 193:
			return 97;
			break;

		case 237:
		case 205:
			return 105;
			break;

		case 243:
		case 211:
			return 111;
			break;

		case 250:
		case 218:
			return 117;
			break;

		case 233:
		case 201:
			return 101;
			break;
	}
}

unsigned char detectarEnieUcondieresis( unsigned char enieUconDieresis )
{
	switch ( enieUconDieresis ) {
		case 241:
		case 209:
			return 110;
			break;

		case 252:
		case 220:
			return 117;
			break;
	}
}

int main( void )
{
	unsigned int tamanioDelString = 0, auxiliarTamanioDelString = 0, numeroDePalabras = 1, imprimirPalabrasEnOrdenInicial = 0, posicionPalabraMenor = 0, posicionPalabra = 0;
	unsigned char palabrasEnOrdenInicial = 0, caracter = 'a', auxiliarCaracterPosicionPalabraMenor = 0, auxiliarCaracterPosicionPalabra = 0, corrimiento = 0, encontrarPalabraMenor = 0, tildePosicionPalabra = 0, tildePosicionPalabraMenor = 0, monitoPosicionPalabra = 0, monitoPosicionPalabraMenor = 0, dieresisPosicionPalabra = 0, dieresisPosicionPalabraMenor = 0, auxiliarString = 0;
	unsigned char string[] = "amor, bueno, anillo, cuatro, dado, fecha, iglesia, jabon";

	printf( "Las palabras en su orden original son las siguientes:\n\n" );

	while ( imprimirPalabrasEnOrdenInicial < numeroDePalabras ) {
		if ( ( ( string[ tamanioDelString ] == ',' || string[ tamanioDelString ] == ' ' ) || string[ tamanioDelString ] == '.' ) && palabrasEnOrdenInicial == 0 ) {
			string[ tamanioDelString ] = '\0';

			numeroDePalabras++;
		}

		tamanioDelString++;

		if ( string[ tamanioDelString ] == '\0' && palabrasEnOrdenInicial == 0 ) {
			tamanioDelString = 0;

			palabrasEnOrdenInicial = 1;
		}

		if ( ( tamanioDelString == 0 || string[ tamanioDelString - 1 ] == '\0' ) && palabrasEnOrdenInicial == 1 ) {
			if ( string[ tamanioDelString ] != '\0' && tamanioDelString != 0 )
				printf( ", " );

			while ( string[ tamanioDelString ] != '\0' ) {
				if ( ( ( string[ tamanioDelString ] == 225 || string[ tamanioDelString ]== 233 ) || ( string[ tamanioDelString ] == 237 || string[ tamanioDelString ] == 243 ) ) || ( string[ tamanioDelString ] == 250 || ( string[ tamanioDelString ] == 241 || string[ tamanioDelString ] == 252 ) ) )
					impimirCaracterConTildeMinuscula( string[ tamanioDelString ] );
				else if ( ( ( string[ tamanioDelString ] == 193 || string[ tamanioDelString ] == 201 ) || ( string[ tamanioDelString ] == 205 || string[ tamanioDelString ] == 211 ) ) || ( string[ tamanioDelString ] == 218 || ( string[ tamanioDelString ] == 209 || string[ tamanioDelString ] == 220 ) ) )
					impimirCaracterConTildeMayuscula( string[ tamanioDelString ] );
				else
					printf( "%c", string[ tamanioDelString ] );

				tamanioDelString++;
			}

			imprimirPalabrasEnOrdenInicial++;
		}
	}

	printf( "\n\n" );

	auxiliarTamanioDelString = tamanioDelString;

	tamanioDelString = 0;

	numeroDePalabras = 0;

	printf( "Las palabras en orden alfab%ctico son las siguientes:\n\n", 130 );

	while ( caracter <= 'z' ) {
		while ( tamanioDelString <= auxiliarTamanioDelString ) {
			if ( ( ( string[ tamanioDelString ] == 225 || string[ tamanioDelString ] == 233 ) || ( string[ tamanioDelString ] == 237 || string[ tamanioDelString ] == 243 ) ) || string[ tamanioDelString ] == 250 )
				auxiliarString = detectarLetraConTilde( string[ tamanioDelString ] );
			else if ( ( ( string[ tamanioDelString ] == 193 || string[ tamanioDelString ] == 205 ) || ( string[ tamanioDelString ] == 211 || string[ tamanioDelString ] == 218 ) ) || string[ tamanioDelString ] == 201 )
				auxiliarString = detectarLetraConTilde( string[ tamanioDelString ] );
			else if ( ( string[ tamanioDelString ] == 209 || string[ tamanioDelString ] == 241 ) || ( string[ tamanioDelString ] == 220 || string[ tamanioDelString ] == 252 ) )
				auxiliarString = detectarEnieUcondieresis( string[ tamanioDelString ] );

			if ( ( tamanioDelString == 0 || string[ tamanioDelString - 1 ] == '\0' ) && ( ( string[ tamanioDelString ] == caracter || string[ tamanioDelString ] == caracter - 32 ) || auxiliarString == caracter ) ) {
				numeroDePalabras++;

				if ( numeroDePalabras == 1 )
					posicionPalabraMenor = tamanioDelString;
			}

			tamanioDelString++;

			auxiliarString = 0;
		}

		if ( ( tamanioDelString > auxiliarTamanioDelString ) && numeroDePalabras > 1 ) {
			tamanioDelString = 0;

			while ( tamanioDelString <= auxiliarTamanioDelString ) {
				if ( ( ( string[ tamanioDelString ] == 225 || string[ tamanioDelString ] == 233 ) || ( string[ tamanioDelString ] == 237 || string[ tamanioDelString ] == 243 ) ) || string[ tamanioDelString ] == 250 )
					auxiliarString = detectarLetraConTilde( string[ tamanioDelString ] );
				else if ( ( ( string[ tamanioDelString ] == 193 || string[ tamanioDelString ] == 205 ) || ( string[ tamanioDelString ] == 211 || string[ tamanioDelString ] == 218 ) ) || string[ tamanioDelString ] == 201 )
					auxiliarString = detectarLetraConTilde( string[ tamanioDelString ] );
				else if ( ( string[ tamanioDelString ] == 209 || string[ tamanioDelString ] == 241 ) || ( string[ tamanioDelString ] == 220 || string[ tamanioDelString ] == 252 ) )
					auxiliarString = detectarEnieUcondieresis( string[ tamanioDelString ] );

				if ( ( tamanioDelString == 0 || string[ tamanioDelString - 1 ] == '\0' ) && ( ( ( string[ tamanioDelString ] == caracter || string[ tamanioDelString ] == caracter - 32 ) || auxiliarString == caracter ) && tamanioDelString != posicionPalabraMenor ) ) {
					posicionPalabra = tamanioDelString;

					while ( ( string[ posicionPalabraMenor + corrimiento ] != '\0' || string[ posicionPalabra + corrimiento ] != '\0' ) && encontrarPalabraMenor != 1 ) {
						if ( string[ posicionPalabraMenor + corrimiento ] >= 'A' && string[ posicionPalabraMenor + corrimiento ] <= 'Z' )
							auxiliarCaracterPosicionPalabraMenor = string[ posicionPalabraMenor + corrimiento ] + 32;
						else if ( string[ posicionPalabraMenor + corrimiento ] >= 'a' && string[ posicionPalabraMenor + corrimiento ] <= 'z' )
							auxiliarCaracterPosicionPalabraMenor = string[ posicionPalabraMenor + corrimiento ];
						else if ( string[ posicionPalabraMenor + corrimiento ] == '\0' )
							auxiliarCaracterPosicionPalabraMenor = string[ posicionPalabraMenor + corrimiento ];

						if ( string[ posicionPalabra + corrimiento ] >= 'A' && string[ posicionPalabra + corrimiento ] <= 'Z' )
							auxiliarCaracterPosicionPalabra = string[ posicionPalabra + corrimiento ] + 32;
						else if ( string[ posicionPalabra + corrimiento ] >= 'a' && string[ posicionPalabra + corrimiento ] <= 'z' )
							auxiliarCaracterPosicionPalabra = string[ posicionPalabra + corrimiento ];
						else if ( string[ posicionPalabra + corrimiento ] == '\0' )
							auxiliarCaracterPosicionPalabra = string[ posicionPalabra + corrimiento ];

						if ( ( ( string[ posicionPalabraMenor + corrimiento ] == 225 || string[ posicionPalabraMenor + corrimiento ] == 233 ) || ( string[ posicionPalabraMenor + corrimiento ] == 237 || string[ posicionPalabraMenor + corrimiento ] == 243 ) ) || string[ posicionPalabraMenor + corrimiento ] == 250 ) {
							auxiliarCaracterPosicionPalabraMenor = detectarLetraConTilde( string[ posicionPalabraMenor + corrimiento ] );

							tildePosicionPalabraMenor = 1;
						}
						else if ( ( ( string[ posicionPalabraMenor + corrimiento ] == 193 || string[ posicionPalabraMenor + corrimiento ] == 201 ) || ( string[ posicionPalabraMenor + corrimiento ] == 205 || string[ posicionPalabraMenor + corrimiento ] == 211 ) ) || string[ posicionPalabraMenor + corrimiento ] == 218 ) {
							auxiliarCaracterPosicionPalabraMenor = detectarLetraConTilde( string[ posicionPalabraMenor + corrimiento ] );

							tildePosicionPalabraMenor = 1;
						}

						if ( ( ( string[ posicionPalabra + corrimiento ] == 225 || string[ posicionPalabra + corrimiento ] == 233 ) || ( string[ posicionPalabra + corrimiento ] == 237 || string[ posicionPalabra + corrimiento ] == 243 ) ) || string[ posicionPalabra + corrimiento ] == 250 ) {
							auxiliarCaracterPosicionPalabra = detectarLetraConTilde( string[ posicionPalabra + corrimiento ] );

							tildePosicionPalabra = 1;
						}
						else if ( ( ( string[ posicionPalabra + corrimiento ] == 193 || string[ posicionPalabra + corrimiento ] == 201 ) || ( string[ posicionPalabra + corrimiento ] == 205 || string[ posicionPalabra + corrimiento ] == 211 ) ) || string[ posicionPalabra + corrimiento ] == 218 ) {
							auxiliarCaracterPosicionPalabra = detectarLetraConTilde( string[ posicionPalabra + corrimiento ] );

							tildePosicionPalabra = 1;
						}

						if ( string[ posicionPalabra + corrimiento ] == 241 || string[ posicionPalabra + corrimiento ] == 209 ) {
							auxiliarCaracterPosicionPalabra = detectarEnieUcondieresis( string[ posicionPalabra + corrimiento ] );

							monitoPosicionPalabra = 1;
						}

						if ( string[ posicionPalabraMenor + corrimiento ] == 241 || string[ posicionPalabraMenor + corrimiento ] == 209 ) {
							auxiliarCaracterPosicionPalabraMenor = detectarEnieUcondieresis( string[ posicionPalabraMenor + corrimiento ] );

							monitoPosicionPalabraMenor = 1;
						}

						if ( string[ posicionPalabra + corrimiento ] == 220 || string[ posicionPalabra + corrimiento ] == 252 ) {
							auxiliarCaracterPosicionPalabra = detectarEnieUcondieresis( string[ posicionPalabra + corrimiento ] );

							dieresisPosicionPalabra = 1;
						}

						if ( string[ posicionPalabraMenor + corrimiento ] == 220 || string[ posicionPalabraMenor + corrimiento ] == 252 ) {
							auxiliarCaracterPosicionPalabraMenor = detectarEnieUcondieresis( string[ posicionPalabraMenor + corrimiento ] );

							dieresisPosicionPalabraMenor = 1;
						}

						if ( ( ( auxiliarCaracterPosicionPalabra < auxiliarCaracterPosicionPalabraMenor ) || ( ( monitoPosicionPalabra == 0 && monitoPosicionPalabraMenor == 1 ) && ( ( auxiliarCaracterPosicionPalabra <= auxiliarCaracterPosicionPalabraMenor ) && auxiliarCaracterPosicionPalabraMenor == 110 ) ) ) || ( ( dieresisPosicionPalabra == 0 && dieresisPosicionPalabraMenor == 1 ) && ( ( auxiliarCaracterPosicionPalabra <= auxiliarCaracterPosicionPalabraMenor ) && auxiliarCaracterPosicionPalabraMenor == 117 ) ) ) {
							posicionPalabraMenor = posicionPalabra;

							encontrarPalabraMenor = 1;
						}
						else if ( ( ( auxiliarCaracterPosicionPalabraMenor < auxiliarCaracterPosicionPalabra ) || ( ( monitoPosicionPalabra == 1 && monitoPosicionPalabraMenor == 0 ) && ( ( auxiliarCaracterPosicionPalabraMenor <= auxiliarCaracterPosicionPalabra ) && auxiliarCaracterPosicionPalabra == 110 ) ) ) || ( ( dieresisPosicionPalabra == 1 && dieresisPosicionPalabraMenor == 0 ) && ( ( auxiliarCaracterPosicionPalabraMenor <= auxiliarCaracterPosicionPalabra ) && auxiliarCaracterPosicionPalabra == 117 ) ) )
							encontrarPalabraMenor = 1;

						corrimiento++;

						monitoPosicionPalabra = 0;

						monitoPosicionPalabraMenor = 0;

						dieresisPosicionPalabra = 0;

						dieresisPosicionPalabraMenor = 0;
					}

					if ( ( ( string[ posicionPalabraMenor + corrimiento ] == '\0' && string[ posicionPalabra + corrimiento ] == '\0' ) && ( tildePosicionPalabraMenor == 1 && tildePosicionPalabra == 0 ) ) && auxiliarCaracterPosicionPalabraMenor == auxiliarCaracterPosicionPalabra )
						posicionPalabraMenor = posicionPalabra;

					tildePosicionPalabra = 0;
	
					tildePosicionPalabraMenor = 0;

					corrimiento = 0;

					encontrarPalabraMenor = 0;
				}

				tamanioDelString++;

				auxiliarString = 0;
			}

			tamanioDelString = 0;

			while ( string[ posicionPalabraMenor + corrimiento ] != '\0' ) {
				if ( ( ( ( string[ posicionPalabraMenor + corrimiento ] == 225 || string[ posicionPalabraMenor + corrimiento ] == 233 ) || ( string[ posicionPalabraMenor + corrimiento ] == 237 || string[ posicionPalabraMenor + corrimiento ] == 243 ) ) || string[ posicionPalabraMenor + corrimiento ] == 250 ) || ( string[ posicionPalabraMenor + corrimiento ] == 241 || string[ posicionPalabraMenor + corrimiento ] == 252 ) )
					impimirCaracterConTildeMinuscula( string[ posicionPalabraMenor + corrimiento ] );
				else if ( ( ( ( string[ posicionPalabraMenor + corrimiento ] == 193 || string[ posicionPalabraMenor + corrimiento ] == 201 ) || ( string[ posicionPalabraMenor + corrimiento ] == 205 || string[ posicionPalabraMenor + corrimiento ] == 211 ) ) || string[ posicionPalabraMenor + corrimiento ] == 218 ) || ( string[ posicionPalabraMenor + corrimiento ] == 209 || string[ posicionPalabraMenor + corrimiento ] == 220 ) )
					impimirCaracterConTildeMayuscula( string[ posicionPalabraMenor + corrimiento ] );
				else
					printf( "%c", string[ posicionPalabraMenor + corrimiento ] );

				string[ posicionPalabraMenor + corrimiento ] = '\0';

				corrimiento++;
			}

			printf( ", " );

			corrimiento = 0;

			numeroDePalabras = 0;
		}
		else if ( ( tamanioDelString > auxiliarTamanioDelString ) && numeroDePalabras == 1 ) {
			tamanioDelString = 0;

			while ( string[ posicionPalabraMenor + corrimiento ] != '\0' ) {
				if ( ( ( ( string[ posicionPalabraMenor + corrimiento ] == 225 || string[ posicionPalabraMenor + corrimiento ] == 233 ) || ( string[ posicionPalabraMenor + corrimiento ] == 237 || string[ posicionPalabraMenor + corrimiento ] == 243 ) ) || string[ posicionPalabraMenor + corrimiento ] == 250 ) || ( string[ posicionPalabraMenor + corrimiento ] == 241 || string[ posicionPalabraMenor + corrimiento ] == 252 ) )
					impimirCaracterConTildeMinuscula( string[ posicionPalabraMenor + corrimiento ] );
				else if ( ( ( ( string[ posicionPalabraMenor + corrimiento ] == 193 || string[ posicionPalabraMenor + corrimiento ] == 201 ) || ( string[ posicionPalabraMenor + corrimiento ] == 205 || string[ posicionPalabraMenor + corrimiento ] == 211 ) ) || string[ posicionPalabraMenor + corrimiento ] == 218 ) || ( string[ posicionPalabraMenor + corrimiento ] == 209 || string[ posicionPalabraMenor + corrimiento ] == 220 ) )
					impimirCaracterConTildeMayuscula( string[ posicionPalabraMenor + corrimiento ] );
				else
					printf( "%c", string[ posicionPalabraMenor + corrimiento ] );

				string[ posicionPalabraMenor + corrimiento ] = '\0';

				corrimiento++;
			}

			printf( ", " );

			corrimiento = 0;

			numeroDePalabras = 0;
		}
		else if ( ( tamanioDelString > auxiliarTamanioDelString ) && numeroDePalabras == 0 ) {
			tamanioDelString = 0;

			caracter++;
		}
	}
}
