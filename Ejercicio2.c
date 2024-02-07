/*
2. Escriba un programa que simule el tiro de dos datos. El programa debe utilizar
la función rand() para lanzar el primer dado y debe utlizar rand() nuevamente para
el segundo dado. Luego se debe calcular la suma de los dos valores.

Nota: Cada dado puede mostrar un valor entero de 1 a 6, de manera que la suma de
ambos puede variar de 2 a 12 donde 7 el la suma mas frecuente y 2 y 12 la menos
frecuente. En la siguiente imagen se pude observar el comportamiento posible de los
dados:

                               1   2   3   4    5    6
                           1 | 2 | 3 | 4 | 5  | 6  | 7  |
                           2 | 3 | 4 | 5 | 6  | 7  | 8  |
                           3 | 4 | 5 | 6 | 7  | 8  | 9  |
                           4 | 5 | 6 | 7 | 8  | 9  | 10 |
                           5 | 6 | 7 | 8 | 9  | 10 | 11 |
                           6 | 7 | 8 | 9 | 10 | 11 | 12 |

Su programa debe realizar 10.000 lanzamientos, utilice un vector para almacenar los
resultados, muestre los resultados en forma tabular y compruebe cual es la suma mas
frecuente.
*/

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	short dado1 = 0, dado2 = 0, sumaDeLanzamiento = 0, menorSumatoria = 0, posicionMenorSumatoria = 0, primerNumeroEncontrado = 0, tabularNumero = 0, sumaMasFrecuente = 0;
	short auxiliarEncontrarMenor = 0, resultadosLanzamientos[ 10000 ] = { 0 }, valorSumaActual = 0, valorActual = 0, frecuencia = 0, sumatoriaFrecuencia = 0, sumatoriaParcialFrecuencia = 0;
	unsigned int iterarVectorDeResultados = 0, encontrarMenor = 0, mayorFrecuenciaDeLanzamientos = 0;

	srand(1);

	for ( iterarVectorDeResultados = 0; iterarVectorDeResultados < 10000; iterarVectorDeResultados++ ) {
		dado1 = rand() % 6 + 1;

		dado2 = rand() % 6 + 1;

		resultadosLanzamientos[ iterarVectorDeResultados ] = dado1 * 10 + dado2;
	}

	iterarVectorDeResultados = 0;

	for ( sumaDeLanzamiento = 2; sumaDeLanzamiento <= 12; sumaDeLanzamiento++ ) {
		do {
			menorSumatoria = resultadosLanzamientos[ iterarVectorDeResultados ];

			posicionMenorSumatoria = iterarVectorDeResultados;

			for ( encontrarMenor = iterarVectorDeResultados + 1; encontrarMenor < 10000; encontrarMenor++ ) {
				if ( resultadosLanzamientos[ encontrarMenor ] / 10 + resultadosLanzamientos[ encontrarMenor ] % 10 == sumaDeLanzamiento && primerNumeroEncontrado == 0 ) {
					posicionMenorSumatoria = encontrarMenor;

					primerNumeroEncontrado = 1;
				}
				else if ( resultadosLanzamientos[ encontrarMenor ] / 10 + resultadosLanzamientos[ encontrarMenor ] % 10 == sumaDeLanzamiento && resultadosLanzamientos[ encontrarMenor ] < resultadosLanzamientos[ posicionMenorSumatoria ] )
					posicionMenorSumatoria = encontrarMenor;
			}

			auxiliarEncontrarMenor = resultadosLanzamientos[ iterarVectorDeResultados ];

			resultadosLanzamientos[ iterarVectorDeResultados ] = resultadosLanzamientos[ posicionMenorSumatoria ];

			resultadosLanzamientos[ posicionMenorSumatoria ] = auxiliarEncontrarMenor;

			primerNumeroEncontrado = 0;

			iterarVectorDeResultados++;
		} while ( resultadosLanzamientos[ iterarVectorDeResultados - 1 ] / 10 + resultadosLanzamientos[ iterarVectorDeResultados - 1 ] % 10 == sumaDeLanzamiento && iterarVectorDeResultados < 10000 );

		iterarVectorDeResultados--;
	}

	valorSumaActual = resultadosLanzamientos[ 0 ] / 10 + resultadosLanzamientos[ 0 ] % 10;

	valorActual = resultadosLanzamientos[ 0 ];

	for ( iterarVectorDeResultados = 0; iterarVectorDeResultados < 10000; iterarVectorDeResultados++ ) {
		if ( resultadosLanzamientos[ iterarVectorDeResultados ] / 10 + resultadosLanzamientos[ iterarVectorDeResultados ] % 10 == valorSumaActual && resultadosLanzamientos[ iterarVectorDeResultados ] == valorActual && tabularNumero == 0 ) {
			printf( "-------------------------------------------------------------------\n" );
			if ( valorSumaActual >= 2 && valorSumaActual <= 9 )
				printf( "|         Sumatoria de lanzamientos Dado 1 + Dado 2 = %d           |\n", valorSumaActual );
			else
				printf( "|         Sumatoria de lanzamientos Dado 1 + Dado 2 = %d          |\n", valorSumaActual );
			printf( "-------------------------------------------------------------------\n" );
			printf( "| Resultado del dado 1 | Resultado del dado 2 | Suma | Frecuencia |\n" );
			printf( "-------------------------------------------------------------------\n" );
			if ( valorSumaActual >= 2 && valorSumaActual <= 9 )
				printf( "|          %d           |           %d          |  %d   |     ", resultadosLanzamientos[ iterarVectorDeResultados ] / 10, resultadosLanzamientos[ iterarVectorDeResultados ] % 10, resultadosLanzamientos[ iterarVectorDeResultados ] / 10 + resultadosLanzamientos[ iterarVectorDeResultados ] % 10 );
			else
				printf( "|          %d           |           %d          |  %d  |     ", resultadosLanzamientos[ iterarVectorDeResultados ] / 10, resultadosLanzamientos[ iterarVectorDeResultados ] % 10, resultadosLanzamientos[ iterarVectorDeResultados ] / 10 + resultadosLanzamientos[ iterarVectorDeResultados ] % 10 );

			tabularNumero = 1;

			frecuencia++;

			sumatoriaParcialFrecuencia++;
		}
		else if ( resultadosLanzamientos[ iterarVectorDeResultados ] / 10 + resultadosLanzamientos[ iterarVectorDeResultados ] % 10 == valorSumaActual && resultadosLanzamientos[ iterarVectorDeResultados ] == valorActual && tabularNumero == 1 ) {
			frecuencia++;

			sumatoriaParcialFrecuencia++;
		}
		else if ( resultadosLanzamientos[ iterarVectorDeResultados ] / 10 + resultadosLanzamientos[ iterarVectorDeResultados ] % 10 == valorSumaActual && resultadosLanzamientos[ iterarVectorDeResultados ] != valorActual && tabularNumero == 1 ) {
			valorActual = resultadosLanzamientos[ iterarVectorDeResultados ];

			printf( "%d    |\n", frecuencia );
			printf( "-------------------------------------------------------------------\n" );

			sumatoriaFrecuencia += frecuencia;

			if ( valorSumaActual >= 2 && valorSumaActual <= 9 )
				printf( "|          %d           |           %d          |  %d   |     ", resultadosLanzamientos[ iterarVectorDeResultados ] / 10, resultadosLanzamientos[ iterarVectorDeResultados ] % 10, resultadosLanzamientos[ iterarVectorDeResultados ] / 10 + resultadosLanzamientos[ iterarVectorDeResultados ] % 10 );
			else
				printf( "|          %d           |           %d          |  %d  |     ", resultadosLanzamientos[ iterarVectorDeResultados ] / 10, resultadosLanzamientos[ iterarVectorDeResultados ] % 10, resultadosLanzamientos[ iterarVectorDeResultados ] / 10 + resultadosLanzamientos[ iterarVectorDeResultados ] % 10 );

			frecuencia = 0;

			frecuencia++;

			sumatoriaParcialFrecuencia++;
		}
		else if ( resultadosLanzamientos[ iterarVectorDeResultados ] / 10 + resultadosLanzamientos[ iterarVectorDeResultados ] % 10 != valorSumaActual ) {
			if ( sumatoriaParcialFrecuencia > mayorFrecuenciaDeLanzamientos ) {
				mayorFrecuenciaDeLanzamientos = sumatoriaParcialFrecuencia;

				sumaMasFrecuente = valorSumaActual; 
			}

			valorSumaActual = resultadosLanzamientos[ iterarVectorDeResultados ] / 10 + resultadosLanzamientos[ iterarVectorDeResultados ] % 10;

			valorActual = resultadosLanzamientos[ iterarVectorDeResultados ];

			printf( "%d    |\n", frecuencia );
			printf( "-------------------------------------------------------------------\n" );

			sumatoriaFrecuencia += frecuencia;

			if ( ( sumatoriaFrecuencia >= 1000 && sumatoriaFrecuencia <= 9999 ) && ( sumatoriaParcialFrecuencia >= 100 && sumatoriaParcialFrecuencia <= 999 ) )
				printf( "|         Sumatoria de frecuencias = %d            |Total = %d |\n", sumatoriaFrecuencia, sumatoriaParcialFrecuencia );
			else if ( ( sumatoriaFrecuencia >= 1000 && sumatoriaFrecuencia <= 9999 ) && ( sumatoriaParcialFrecuencia >= 1000 && sumatoriaParcialFrecuencia <= 9999 ) )
				printf( "|         Sumatoria de frecuencias = %d            |Total = %d|\n", sumatoriaFrecuencia, sumatoriaParcialFrecuencia );
			else if ( ( sumatoriaFrecuencia >= 100 && sumatoriaFrecuencia <= 999 ) && ( sumatoriaParcialFrecuencia >= 100 && sumatoriaParcialFrecuencia <= 999 ) )
				printf( "|         Sumatoria de frecuencias = %d             |Total = %d |\n", sumatoriaFrecuencia, sumatoriaParcialFrecuencia );

			frecuencia = 0;

			sumatoriaParcialFrecuencia = 0;

			tabularNumero = 0;

			iterarVectorDeResultados--;
		}
	}

	printf( "%d    |\n", frecuencia );
	printf( "-------------------------------------------------------------------\n" );

	sumatoriaFrecuencia += frecuencia;

	printf( "|          Sumatoria de frecuencias = %d          |Total = %d |\n", sumatoriaFrecuencia, sumatoriaParcialFrecuencia  );
	printf( "-------------------------------------------------------------------\n" );
	printf( "|      La suma m%cs frecuente es %d en %d lanzamientos            |\n", 160, sumaMasFrecuente, mayorFrecuenciaDeLanzamientos );
	printf( "-------------------------------------------------------------------\n" );

	return 0;
}
