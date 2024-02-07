#include <stdio.h>
#include <stdlib.h>

unsigned char operacion[] = "[(15-13.5)x(31.654-26)]+18.65÷(1.675+4x2.67500)";

void colocarSignoMultiplicacion ( unsigned int agrupInput, unsigned int longitudOperacion );

void aplicarLeyDeLosSignos ( unsigned int agrupadorDeInicio, unsigned int agrupadorDeCierre );

void borrarAgrupadores ( unsigned int borrarALaIzquierda, unsigned int borrarALaDerecha, unsigned int longituDeLaOperacion );

unsigned int descomponerNumero ( float numeroADescomponer, unsigned int posicionDeInicio );

float convertirNumero ( unsigned int inicioDeLaConversion );

void resultadoMultiplicacionDivsionParcial ( unsigned int posicionDelOperador, unsigned int longitudDeLaOperacion );

void sumaRestaParcial ( unsigned int posicionDelOperador, unsigned int longitudDeLaOperacion );

void iterarAgrupadores ( unsigned int agrupadorDeApertura, unsigned int agrupadorDeCierre, unsigned int longitudDeLaOperacion );

void colocarSignoMultiplicacion ( unsigned int agrupInput, unsigned int longitudOperacion )
{
	unsigned int auxAgrupInputRight = agrupInput, auxAgrupInputLeft = agrupInput;

	while ( ( auxAgrupInputLeft > 0 && ( operacion[ auxAgrupInputLeft ] == ' ' || operacion[ auxAgrupInputLeft ] == '\0' ) ) || 
	( auxAgrupInputRight < longitudOperacion && ( operacion[ auxAgrupInputRight ] == ' ' || operacion[ auxAgrupInputRight ] == '\0' ) ) ) {
		if ( auxAgrupInputLeft > 0 && ( operacion[ auxAgrupInputLeft ] == ' ' || operacion[ auxAgrupInputLeft ] == '\0' ) )
			auxAgrupInputLeft--;

		if ( auxAgrupInputRight < longitudOperacion && ( operacion[ auxAgrupInputRight ] == ' ' || operacion[ auxAgrupInputRight ] == '\0' ) )
			auxAgrupInputRight++;
	}

	if ( ( operacion[ auxAgrupInputLeft ] >= '0' && operacion[ auxAgrupInputLeft ] <= '9' ) && ( ( operacion[ auxAgrupInputRight ] >= '0' && 
	operacion[ auxAgrupInputRight ] <= '9' ) || operacion[ auxAgrupInputRight ] == '+' || operacion[ auxAgrupInputRight ] == '-' ) )
		operacion[ agrupInput ] = 'x';
}

void aplicarLeyDeLosSignos ( unsigned int agrupadorDeInicio, unsigned int agrupadorDeCierre )
{
	unsigned int iterarAgrupadores = 0, buscarSigno = 0;

	for ( iterarAgrupadores = agrupadorDeInicio; iterarAgrupadores <= agrupadorDeCierre; iterarAgrupadores++ ) {
		if ( operacion[ iterarAgrupadores ] == '+' ) {
			buscarSigno = iterarAgrupadores;

			do {
				buscarSigno++;

				if ( operacion[ buscarSigno ] == '+' ) {
					operacion[ iterarAgrupadores ] = '\0';

					operacion[ buscarSigno ] = '+';
				}
				else if ( operacion[ buscarSigno ] == '-' ) {
					operacion[ iterarAgrupadores ] = '\0';

					operacion[ buscarSigno ] = '-';
				}
			} while ( operacion[ buscarSigno ] != '+' && operacion[ buscarSigno ] != '-' && operacion[ buscarSigno ] != 'x' && operacion[ buscarSigno ] != 'X' 
			&& operacion[ buscarSigno ] != '*' && operacion[ buscarSigno ] != '/' && operacion[ buscarSigno ] != 247 && !( operacion[ buscarSigno ] >= '0' && 
			operacion[ buscarSigno ] <= '9' ) );
		}
		else if ( operacion[ iterarAgrupadores ] == '-' ) {
			buscarSigno = iterarAgrupadores;

			do {
				buscarSigno++;

				if ( operacion[ buscarSigno ] == '+' ) {
					operacion[ iterarAgrupadores ] = '\0';

					operacion[ buscarSigno ] = '-';
				}
				else if ( operacion[ buscarSigno ] == '-' ) {
					operacion[ iterarAgrupadores ] = '\0';

					operacion[ buscarSigno ] = '+';
				}
			} while ( operacion[ buscarSigno ] != '+' && operacion[ buscarSigno ] != '-' && operacion[ buscarSigno ] != 'x' && operacion[ buscarSigno ] != 'X' 
			&& operacion[ buscarSigno ] != '*' && operacion[ buscarSigno ] != '/' && operacion[ buscarSigno ] != 247 && !( operacion[ buscarSigno ] >= '0' && 
			operacion[ buscarSigno ] <= '9' ) );
		}
	}
}

void borrarAgrupadores ( unsigned int borrarALaIzquierda, unsigned int borrarALaDerecha, unsigned int longituDeLaOperacion )
{
	while ( borrarALaDerecha < longituDeLaOperacion && borrarALaIzquierda > 0 && ( operacion[ borrarALaIzquierda ] == '(' || 
	operacion[ borrarALaIzquierda ] == '{' || operacion[ borrarALaIzquierda ] == '[' ) && ( operacion[ borrarALaDerecha ] == ')' || 
	operacion[ borrarALaDerecha ] == '}' || operacion[ borrarALaDerecha ] == ']' ) ) {
		operacion[ borrarALaDerecha ] = '\0';

		operacion[ borrarALaIzquierda ] = '\0';

		borrarALaDerecha++;

		borrarALaIzquierda--;
	}

	if ( ( operacion[ borrarALaIzquierda ] == '(' || operacion[ borrarALaIzquierda ] == '{' || operacion[ borrarALaIzquierda ] == '[' ) && 
	( operacion[ borrarALaDerecha ] == ')' || operacion[ borrarALaDerecha ] == '}' || operacion[ borrarALaDerecha ] == ']' ) && 
	( borrarALaDerecha < longituDeLaOperacion || borrarALaDerecha == longituDeLaOperacion - 1 ) && borrarALaIzquierda == 0 ) {
		operacion[ borrarALaDerecha ] = '\0';

		operacion[ borrarALaIzquierda ] = '\0';
	}
}

unsigned int descomponerNumero ( float numeroADescomponer, unsigned int posicionDeInicio )
{
	unsigned int divParteEntYDec = 1, parteEntera = ( ( unsigned int ) numeroADescomponer ), parteDecimal = 0;
	float auxiliarParteDecimal = numeroADescomponer - ( ( float ) parteEntera );

	while ( divParteEntYDec <= parteEntera )
		divParteEntYDec *= 10;

	divParteEntYDec /= 10;

	if ( parteEntera == 0 ) {
		operacion[ posicionDeInicio ] = '0';

		posicionDeInicio++;
	}

	while ( divParteEntYDec != 0 ) {
		operacion[ posicionDeInicio ] = parteEntera / divParteEntYDec + 48;

		parteEntera %= divParteEntYDec;

		divParteEntYDec /= 10;

		posicionDeInicio++;
	}

	if ( auxiliarParteDecimal != ( ( float ) 0 ) ) {
		divParteEntYDec = 1000000;

		auxiliarParteDecimal *= ( ( float ) divParteEntYDec );

		parteDecimal = ( ( unsigned int ) auxiliarParteDecimal );

		divParteEntYDec /= 10;

		operacion[ posicionDeInicio ] = '.';

		posicionDeInicio++;

		while ( divParteEntYDec != 0 ) {
			if ( parteDecimal != ( ( float ) 0 ) && parteDecimal >= divParteEntYDec ) {
				operacion[ posicionDeInicio ] = parteDecimal / divParteEntYDec + 48;

				posicionDeInicio++;
			}
			else if ( parteDecimal != ( ( float ) 0 ) && parteDecimal < divParteEntYDec ) {
				operacion[ posicionDeInicio ] = '0';

				posicionDeInicio++;
			}

			parteDecimal %= divParteEntYDec;

			divParteEntYDec /= 10;
		}
	}

	return posicionDeInicio;
}

float convertirNumero ( unsigned int inicioDeLaConversion )
{
	float valorNumeroConvertido = 0.000000;
	unsigned int auxiliarInicioDeLaConversion = inicioDeLaConversion, mulDivParteEntParteDec = 1, pasosParaConvertirParteEntera = 0;

	for ( pasosParaConvertirParteEntera = 0; pasosParaConvertirParteEntera < 2; pasosParaConvertirParteEntera++ ) {
		if ( pasosParaConvertirParteEntera == 0 ) {
			auxiliarInicioDeLaConversion++;

			while ( operacion[ auxiliarInicioDeLaConversion ] >= '0' && operacion[ auxiliarInicioDeLaConversion ] <= '9' ) {
				mulDivParteEntParteDec *= 10;

				auxiliarInicioDeLaConversion++;
			}
		}
		else if ( pasosParaConvertirParteEntera == 1 ) {
			while ( mulDivParteEntParteDec != 0 ) {
				valorNumeroConvertido += ( ( ( float ) mulDivParteEntParteDec ) * ( ( float ) ( operacion[ inicioDeLaConversion ] - 48 ) ) );

				mulDivParteEntParteDec /= 10;

				inicioDeLaConversion++;
			}
		}
	}

	if ( operacion[ auxiliarInicioDeLaConversion ] == '.' ) {
		mulDivParteEntParteDec = 10;

		inicioDeLaConversion++;

		while ( operacion[ inicioDeLaConversion ] >= '0' && operacion[ inicioDeLaConversion ] <= '9' ) {
			valorNumeroConvertido += ( ( ( float ) ( operacion[ inicioDeLaConversion ] - 48 ) ) / ( ( float ) mulDivParteEntParteDec ) );

			mulDivParteEntParteDec *= 10;

			inicioDeLaConversion++;
		}
	}

	return valorNumeroConvertido;
}

void resultadoMultiplicacionDivisionParcial ( unsigned int posicionDelOperador, unsigned int longitudDeLaOperacion )
{
	unsigned int inicioDeLaOperacion = 0, finalDeLaOperacion = 0, iterarEntreInicioYFinDeLaOperacion = 0, iterarALaDerechaIzquierda = posicionDelOperador, empezarABorrar = 0;
	float resultadoMultiplicacionDivisionParcial = 0.000000;

	while ( operacion[ iterarALaDerechaIzquierda ] != '+' && operacion[ iterarALaDerechaIzquierda ] != '-' && operacion[ iterarALaDerechaIzquierda ] != '(' && operacion[ iterarALaDerechaIzquierda ] != '{' && operacion[ iterarALaDerechaIzquierda ] != '[' && iterarALaDerechaIzquierda > 0 ) {
		iterarALaDerechaIzquierda--;

		if ( ( operacion[ iterarALaDerechaIzquierda ] >= '0' && operacion[ iterarALaDerechaIzquierda ] <= '9' ) && iterarALaDerechaIzquierda > 0 && !( operacion[ iterarALaDerechaIzquierda - 1 ] >= '0' && operacion[ iterarALaDerechaIzquierda - 1 ] <= '9' ) && operacion[ iterarALaDerechaIzquierda - 1 ] != '.' ) {
			resultadoMultiplicacionDivisionParcial = convertirNumero ( iterarALaDerechaIzquierda );

			inicioDeLaOperacion = iterarALaDerechaIzquierda;
		}
		else if ( ( operacion[ iterarALaDerechaIzquierda ] >= '0' && operacion[ iterarALaDerechaIzquierda ] <= '9' ) && iterarALaDerechaIzquierda == 0 ) {
			resultadoMultiplicacionDivisionParcial = convertirNumero ( iterarALaDerechaIzquierda );

			inicioDeLaOperacion = iterarALaDerechaIzquierda;
		}
		else if ( operacion[ iterarALaDerechaIzquierda ] == '+' || ( iterarALaDerechaIzquierda == 0 && operacion[ iterarALaDerechaIzquierda ] != '(' && operacion[ iterarALaDerechaIzquierda ] != '{' && operacion[ iterarALaDerechaIzquierda ] != '[' && operacion[ iterarALaDerechaIzquierda ] != '-' ) )
			inicioDeLaOperacion = iterarALaDerechaIzquierda;
		else if ( operacion[ iterarALaDerechaIzquierda ] == '-' ) {
			resultadoMultiplicacionDivisionParcial *= ( ( float ) ( -1 ) );

			inicioDeLaOperacion = iterarALaDerechaIzquierda;
		}
		else if ( operacion[ iterarALaDerechaIzquierda ] == '(' || operacion[ iterarALaDerechaIzquierda ] == '{' || operacion[ iterarALaDerechaIzquierda ] == '[' )
			inicioDeLaOperacion = iterarALaDerechaIzquierda + 1;
	}

	iterarALaDerechaIzquierda++;

	while ( operacion[ iterarALaDerechaIzquierda ] != '+' && operacion[ iterarALaDerechaIzquierda ] != '-' && operacion[ iterarALaDerechaIzquierda ] != ')' && operacion[ iterarALaDerechaIzquierda ] != '}' && operacion[ iterarALaDerechaIzquierda ] != ']' && iterarALaDerechaIzquierda < longitudDeLaOperacion ) {
		if ( operacion[ iterarALaDerechaIzquierda ] == 'X' || operacion[ iterarALaDerechaIzquierda ] == 'x' || operacion[ iterarALaDerechaIzquierda ] == '*' ) {
			while ( !( operacion[ iterarALaDerechaIzquierda ] >= '0' && operacion[ iterarALaDerechaIzquierda ] <= '9' ) ) {
				iterarALaDerechaIzquierda++;

				if ( operacion[ iterarALaDerechaIzquierda ] >= '0' && operacion[ iterarALaDerechaIzquierda ] <= '9' )
					resultadoMultiplicacionDivisionParcial *= convertirNumero ( iterarALaDerechaIzquierda );
				else if ( operacion[ iterarALaDerechaIzquierda ] == '+' ) {
					while ( !( operacion[ iterarALaDerechaIzquierda ] >= '0' && operacion[ iterarALaDerechaIzquierda ] <= '9' ) ) {
						iterarALaDerechaIzquierda++;

						if ( operacion[ iterarALaDerechaIzquierda ] >= '0' && operacion[ iterarALaDerechaIzquierda ] <= '9' )
							resultadoMultiplicacionDivisionParcial *= convertirNumero ( iterarALaDerechaIzquierda );
					}
				}
				else if ( operacion[ iterarALaDerechaIzquierda ] == '-' ) {
					while ( !( operacion[ iterarALaDerechaIzquierda ] >= '0' && operacion[ iterarALaDerechaIzquierda ] <= '9' ) ) {
						iterarALaDerechaIzquierda++;

						if ( operacion[ iterarALaDerechaIzquierda ] >= '0' && operacion[ iterarALaDerechaIzquierda ] <= '9' )
							resultadoMultiplicacionDivisionParcial *= ( ( ( float ) ( -1 ) ) * convertirNumero ( iterarALaDerechaIzquierda ) );
					}
				}
			}
		}
		else if ( operacion[ iterarALaDerechaIzquierda ] == 247 || operacion[ iterarALaDerechaIzquierda ] == '/' ) {
			while ( !( operacion[ iterarALaDerechaIzquierda ] >= '0' && operacion[ iterarALaDerechaIzquierda ] <= '9' ) ) {
				iterarALaDerechaIzquierda++;

				if ( operacion[ iterarALaDerechaIzquierda ] >= '0' && operacion[ iterarALaDerechaIzquierda ] <= '9' )
					resultadoMultiplicacionDivisionParcial /= convertirNumero ( iterarALaDerechaIzquierda );
				else if ( operacion[ iterarALaDerechaIzquierda ] == '+' ) {
					while ( !( operacion[ iterarALaDerechaIzquierda ] >= '0' && operacion[ iterarALaDerechaIzquierda ] <= '9' ) ) {
						iterarALaDerechaIzquierda++;

						if ( operacion[ iterarALaDerechaIzquierda ] >= '0' && operacion[ iterarALaDerechaIzquierda ] <= '9' )
							resultadoMultiplicacionDivisionParcial /= convertirNumero ( iterarALaDerechaIzquierda );
					}
				}
				else if ( operacion[ iterarALaDerechaIzquierda ] == '-' ) {
					while ( !( operacion[ iterarALaDerechaIzquierda ] >= '0' && operacion[ iterarALaDerechaIzquierda ] <= '9' ) ) {
						iterarALaDerechaIzquierda++;

						if ( operacion[ iterarALaDerechaIzquierda ] >= '0' && operacion[ iterarALaDerechaIzquierda ] <= '9' )
							resultadoMultiplicacionDivisionParcial /= ( ( ( float ) ( -1 ) ) * convertirNumero ( iterarALaDerechaIzquierda ) );
					}
				}
			}
		}

		iterarALaDerechaIzquierda++;

		if ( operacion[ iterarALaDerechaIzquierda ] == '+' || operacion[ iterarALaDerechaIzquierda ] == '-' || operacion[ iterarALaDerechaIzquierda ] == ')' || operacion[ iterarALaDerechaIzquierda ] == '}' || operacion[ iterarALaDerechaIzquierda ] == ']' || iterarALaDerechaIzquierda == longitudDeLaOperacion )
			finalDeLaOperacion = iterarALaDerechaIzquierda - 1;
	}

	for ( iterarEntreInicioYFinDeLaOperacion = inicioDeLaOperacion; iterarEntreInicioYFinDeLaOperacion <= finalDeLaOperacion; iterarEntreInicioYFinDeLaOperacion++ ) {
		if ( iterarEntreInicioYFinDeLaOperacion == inicioDeLaOperacion && resultadoMultiplicacionDivisionParcial < ( ( float ) 0 ) )
			operacion[ iterarEntreInicioYFinDeLaOperacion ] = '-';
		else if ( iterarEntreInicioYFinDeLaOperacion == inicioDeLaOperacion + 1 && resultadoMultiplicacionDivisionParcial < ( ( float ) 0 ) )
			empezarABorrar = descomponerNumero ( ( ( ( float ) ( -1 ) ) * resultadoMultiplicacionDivisionParcial ), iterarEntreInicioYFinDeLaOperacion );
		else if ( iterarEntreInicioYFinDeLaOperacion == inicioDeLaOperacion && resultadoMultiplicacionDivisionParcial >= ( ( float ) 0 ) && ( operacion[ inicioDeLaOperacion ] == '+' || operacion[ inicioDeLaOperacion ] == '-' ) )
			operacion[ iterarEntreInicioYFinDeLaOperacion ] = '+';
		else if ( iterarEntreInicioYFinDeLaOperacion == inicioDeLaOperacion + 1 && resultadoMultiplicacionDivisionParcial >= ( ( float ) 0 ) && ( operacion[ inicioDeLaOperacion ] == '+' || operacion[ inicioDeLaOperacion ] == '-' ) )
			empezarABorrar = descomponerNumero ( resultadoMultiplicacionDivisionParcial, iterarEntreInicioYFinDeLaOperacion );
		else if ( iterarEntreInicioYFinDeLaOperacion == inicioDeLaOperacion && resultadoMultiplicacionDivisionParcial >= ( ( float ) 0 ) && ( operacion[ inicioDeLaOperacion ] >= '0' || operacion[ inicioDeLaOperacion ] <= '9' ) )
			empezarABorrar = descomponerNumero ( resultadoMultiplicacionDivisionParcial, iterarEntreInicioYFinDeLaOperacion );
		else if ( operacion[ iterarEntreInicioYFinDeLaOperacion ] != '\0' && iterarEntreInicioYFinDeLaOperacion >= empezarABorrar )
			operacion[ iterarEntreInicioYFinDeLaOperacion ] = '\0';
	}
}

void sumaRestaParcial ( unsigned int posicionDelOperador, unsigned int longitudDeLaOperacion ) {
	unsigned int inicioDeLaOperacion = 0, finalDeLaOperacion = 0, iterarInicioYFinOperacion = 0;
	unsigned int iterarALaDerechaIzquierda = posicionDelOperador, empezarABorrar = 0;
	float sumaRestaParcial = 0.000000;

	if ( operacion[ posicionDelOperador ] >= '0' && operacion[ posicionDelOperador ] <= '9' ) {
		sumaRestaParcial = convertirNumero ( posicionDelOperador );

		inicioDeLaOperacion = posicionDelOperador;

		while ( operacion[ inicioDeLaOperacion ] != '(' && operacion[ inicioDeLaOperacion ] != '{' 
		&& operacion[ inicioDeLaOperacion ] != '[' && inicioDeLaOperacion != 0 )
			inicioDeLaOperacion--;

		if ( operacion[ inicioDeLaOperacion ] == '(' || operacion[ inicioDeLaOperacion ] == '{' || operacion[ inicioDeLaOperacion ] == '[' )
			inicioDeLaOperacion++;
	}
	else if ( operacion[ posicionDelOperador ] == '+' ) {
		inicioDeLaOperacion = posicionDelOperador;

		while ( !( operacion[ posicionDelOperador ] >= '0' && operacion[ posicionDelOperador ] <= '9' ) ) {
			posicionDelOperador++;

			if ( operacion[ posicionDelOperador ] >= '0' && operacion[ posicionDelOperador ] <= '9' )
				sumaRestaParcial = convertirNumero ( posicionDelOperador );
		}
	}
	else if ( operacion[ posicionDelOperador ] == '-' ) {
		inicioDeLaOperacion = posicionDelOperador;

		while ( !( operacion[ posicionDelOperador ] >= '0' && operacion[ posicionDelOperador ] <= '9' ) ) {
			posicionDelOperador++;

			if ( operacion[ posicionDelOperador ] >= '0' && operacion[ posicionDelOperador ] <= '9' )
				sumaRestaParcial = ( ( ( float ) ( -1 ) ) * convertirNumero ( posicionDelOperador ) );
		}
	}

	while ( operacion[ posicionDelOperador ] != ')' && operacion[ posicionDelOperador ] != '}' 
	&& operacion[ posicionDelOperador ] != ']' && posicionDelOperador < longitudDeLaOperacion ) {
		posicionDelOperador++;

		if ( operacion[ posicionDelOperador ] == '+' ) {
			while ( !( operacion[ posicionDelOperador ] >= '0' && operacion[ posicionDelOperador ] <= '9' ) ) {
				posicionDelOperador++;

				if ( operacion[ posicionDelOperador ] >= '0' && operacion[ posicionDelOperador ] <= '9' )
					sumaRestaParcial += convertirNumero ( posicionDelOperador );
			}
		}
		else if ( operacion[ posicionDelOperador ] == '-' ) {
			while ( !( operacion[ posicionDelOperador ] >= '0' && operacion[ posicionDelOperador ] <= '9' ) ) {
				posicionDelOperador++;

				if ( operacion[ posicionDelOperador ] >= '0' && operacion[ posicionDelOperador ] <= '9' )
					sumaRestaParcial += ( ( ( float ) ( -1 ) ) * convertirNumero ( posicionDelOperador ) );
			}
		}

		if ( operacion[ posicionDelOperador ] == ')' || operacion[ posicionDelOperador ] == '}' || 
		operacion[ posicionDelOperador ] == ']' || posicionDelOperador == longitudDeLaOperacion )
			finalDeLaOperacion = posicionDelOperador - 1;
	}

	for ( iterarInicioYFinOperacion = inicioDeLaOperacion; iterarInicioYFinOperacion <= finalDeLaOperacion; iterarInicioYFinOperacion++ ) {
		if ( iterarInicioYFinOperacion == inicioDeLaOperacion && sumaRestaParcial < ( ( float ) 0 ) )
			operacion[ iterarInicioYFinOperacion ] = '-';
		else if ( iterarInicioYFinOperacion == inicioDeLaOperacion + 1 && sumaRestaParcial < ( ( float ) 0 ) )
			empezarABorrar = descomponerNumero ( ( ( ( float ) ( -1 ) ) * sumaRestaParcial ), iterarInicioYFinOperacion );
		else if ( iterarInicioYFinOperacion == inicioDeLaOperacion && sumaRestaParcial >= ( ( float ) 0 ) 
		&& ( operacion[ inicioDeLaOperacion ] == '+' || operacion[ inicioDeLaOperacion ] == '-' ) )
			operacion[ iterarInicioYFinOperacion ] = '+';
		else if ( iterarInicioYFinOperacion == inicioDeLaOperacion + 1 && sumaRestaParcial >= ( ( float ) 0 ) 
		&& ( operacion[ inicioDeLaOperacion ] == '+' || operacion[ inicioDeLaOperacion ] == '-' ) )
			empezarABorrar = descomponerNumero ( sumaRestaParcial, iterarInicioYFinOperacion );
		else if ( iterarInicioYFinOperacion == inicioDeLaOperacion && sumaRestaParcial >= ( ( float ) 0 ) 
		&& ( operacion[ inicioDeLaOperacion ] >= '0' || operacion[ inicioDeLaOperacion ] <= '9' ) )
			empezarABorrar = descomponerNumero ( sumaRestaParcial, iterarInicioYFinOperacion );
		else if ( operacion[ iterarInicioYFinOperacion ] != '\0' && iterarInicioYFinOperacion >= empezarABorrar )
			operacion[ iterarInicioYFinOperacion ] = '\0';
	}
}

void iterarAgrupadores ( unsigned int agrupadorDeApertura, unsigned int agrupadorDeCierre, unsigned int longitudDelaOperacion )
{
	short iterarOperaciones = 0;
	unsigned int iterarAgrupadores = 0, agrupadorRight = 0;

	for ( iterarOperaciones = 0;  iterarOperaciones < 2; iterarOperaciones++ ) {
		for ( iterarAgrupadores = agrupadorDeApertura; iterarAgrupadores <= agrupadorDeCierre; iterarAgrupadores++ ) {
			if ( iterarOperaciones == 0 && ( operacion[ iterarAgrupadores ] == 'X' || operacion[ iterarAgrupadores ] == 'x' 
			|| operacion[ iterarAgrupadores ] == '*' ) )
				resultadoMultiplicacionDivisionParcial ( iterarAgrupadores, longitudDelaOperacion );
			else if ( iterarOperaciones == 0 && (  operacion[ iterarAgrupadores ] == '/' || operacion[ iterarAgrupadores ] == 247 ) )
				resultadoMultiplicacionDivisionParcial ( iterarAgrupadores, longitudDelaOperacion );
			else if ( iterarOperaciones == 1 && ( operacion[ iterarAgrupadores ] == '+' || operacion[ iterarAgrupadores ] == '-' ) )
				sumaRestaParcial ( iterarAgrupadores, longitudDelaOperacion );
			else if ( iterarAgrupadores > 0 && iterarOperaciones == 1 && ( operacion[ iterarAgrupadores ] >= '0' &&  operacion[ iterarAgrupadores ] <= '9' ) 
			&& !( operacion[ iterarAgrupadores - 1 ] >= '0' &&  operacion[ iterarAgrupadores - 1 ] <= '9' ) && operacion[ iterarAgrupadores - 1 ] != '.' 
			&& operacion[ iterarAgrupadores - 1 ] != '+' && operacion[ iterarAgrupadores - 1 ] != '-' && operacion[ iterarAgrupadores - 1 ] != 'X' 
			&& operacion[ iterarAgrupadores - 1 ] != 'x' && operacion[ iterarAgrupadores - 1 ] != '*' && operacion[ iterarAgrupadores - 1 ] != '/' 
			&& operacion[ iterarAgrupadores - 1 ] != 247 ) {
				agrupadorRight = iterarAgrupadores;

				while ( operacion[ agrupadorRight ] != '(' && operacion[ agrupadorRight ] != '{' && operacion[ agrupadorRight ] != '['
				&& operacion[ agrupadorRight ] != 'X' && operacion[ agrupadorRight ] != 'x' && operacion[ agrupadorRight ] != '*' 
				&& operacion[ agrupadorRight ] != '/' && operacion[ agrupadorRight ] != 247 && operacion[ agrupadorRight ] != '+' 
				&& operacion[ agrupadorRight ] != '-' && agrupadorRight > 0 ) {
					agrupadorRight--;

					if ( operacion[ agrupadorRight ] == '(' || operacion[ agrupadorRight ] == '{' || operacion[ agrupadorRight ] == '[' || agrupadorRight == 0 )
						sumaRestaParcial ( iterarAgrupadores, longitudDelaOperacion );
				}
			}
			else if ( iterarAgrupadores == 0 && iterarOperaciones == 1 && ( operacion[ iterarAgrupadores ] >= '0' &&  operacion[ iterarAgrupadores ] <= '9' ) )
					sumaRestaParcial ( iterarAgrupadores, longitudDelaOperacion );
		}
	}
}

int main ( void )
{
	unsigned int longitudDeLaOperacion = 0, agrupadorDeApertura = 0, posicionDelAgrupadorDeCierreMasInterno = 0, iterarString = 0, contadorDePuntos = 0, contadorDelSignoMasYMenos = 0, contadorDelSignoMultiplicacionDivision = 0, pasos = 0, buscarNumeroALaIzquierdaDeMasMenos = 0;
	short numeroALaIzquierdaEncontrado = 0, verificarNumero = 0, terminarOperacion = 0;

	while ( operacion[ longitudDeLaOperacion ] != '\0' )
		longitudDeLaOperacion++;

	while ( terminarOperacion == 0 ) {
		while ( operacion[agrupadorDeApertura ] != ')' && operacion[ agrupadorDeApertura ] != '}' 
		&& operacion[ agrupadorDeApertura ] != ']' && agrupadorDeApertura < longitudDeLaOperacion )
			agrupadorDeApertura++;

		posicionDelAgrupadorDeCierreMasInterno = agrupadorDeApertura;

		while ( operacion[ agrupadorDeApertura ] != '(' && operacion[ agrupadorDeApertura ] != '{' 
		&& operacion[ agrupadorDeApertura ] != '[' && agrupadorDeApertura > 0 )
			agrupadorDeApertura--;

		aplicarLeyDeLosSignos ( agrupadorDeApertura, posicionDelAgrupadorDeCierreMasInterno );

		while ( iterarString < longitudDeLaOperacion ) {
			if ( operacion[ iterarString ] != '\0' && operacion[ iterarString ] != ' ' )
				if ( operacion[ iterarString ] == 247 )
					printf( "%c", 246 );
				else
					printf( "%c", operacion[ iterarString ] );

			iterarString++;
		}

		pasos++;

		if ( agrupadorDeApertura == 0 && posicionDelAgrupadorDeCierreMasInterno == longitudDeLaOperacion ) {
			for ( iterarString = agrupadorDeApertura; iterarString <= posicionDelAgrupadorDeCierreMasInterno; iterarString++ ) {
				if ( operacion[ iterarString ] == '.' )
					contadorDePuntos++;
				else if ( operacion[ iterarString ] == '+' || operacion[ iterarString ] == '-' ) {
					contadorDelSignoMasYMenos++;

					buscarNumeroALaIzquierdaDeMasMenos = iterarString;

					while ( !( operacion[ buscarNumeroALaIzquierdaDeMasMenos ] >= '0' && operacion[ buscarNumeroALaIzquierdaDeMasMenos ] <= '9' ) && buscarNumeroALaIzquierdaDeMasMenos != 0 ) {
						buscarNumeroALaIzquierdaDeMasMenos--;

						if ( operacion[ buscarNumeroALaIzquierdaDeMasMenos ] >= '0' && operacion[ buscarNumeroALaIzquierdaDeMasMenos ] <= '9' )
							numeroALaIzquierdaEncontrado = 1;
					}
				}
				else if ( operacion[ iterarString ] == 'x' || operacion[ iterarString ] == 'X' || operacion[ iterarString ] == '*' || operacion[ iterarString ] == '/' || operacion[ iterarString ] == 247 )
					contadorDelSignoMultiplicacionDivision++;
			}

			if ( contadorDePuntos <= 1 && contadorDelSignoMasYMenos <= 1 && contadorDelSignoMultiplicacionDivision == 0 && numeroALaIzquierdaEncontrado == 0 )
				terminarOperacion = 1;

			contadorDelSignoMasYMenos = 0;

			contadorDelSignoMultiplicacionDivision = 0;

			contadorDePuntos = 0;

			numeroALaIzquierdaEncontrado = 0;
		}

		if ( terminarOperacion == 0 ) {
			printf( " => Paso %u\n", pasos );

			iterarAgrupadores ( agrupadorDeApertura, posicionDelAgrupadorDeCierreMasInterno, longitudDeLaOperacion );

			borrarAgrupadores ( agrupadorDeApertura, posicionDelAgrupadorDeCierreMasInterno, longitudDeLaOperacion );

			if ( agrupadorDeApertura > 0 )
				colocarSignoMultiplicacion( agrupadorDeApertura, longitudDeLaOperacion );
		}
		else
			printf( " => Resultado Final\n" );

		agrupadorDeApertura = 0;

		posicionDelAgrupadorDeCierreMasInterno = 0;

		iterarString = 0;
	}

	return 0;
}
