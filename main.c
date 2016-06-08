#include <stdio.h>
#include <math.h>

#define e 2.718281828459045235360287
#define pi 3.14159265358979323846

//parametros: Oxigenio dissolvido(OD), Coliformes Fecais(CF), Potencial Hidrogenionico(pH), Demanda Bioquimica de Oxigenio(DBO), Nitratos(NO), Fosfatos(PO), Temperatura(C), Turbidez(UNT), Residuos Totais(RT)
//ordem dos pesos: OD CF pH DBO NO PO C UNT RT
double peso[9]={0.17,0.15,0.12,0.10,0.10,0.10,0.10,0.08,0.08} 
double parametro[9]

double produtorio(double iqa)
{
	double n;
	iqa=1;
}

int main(){

	printf("Oxigenio Dissolvido: ");
	scanf("%lf\n", &parametro[0]);

	printf("Coliformes Fecais: ");
	scanf("%lf\n", &parametro[1]);

	printf("Potencial Hidrogenionico(pH): ");
	scanf("%lf\n", &parametro[2]);

	printf("Demanda Bioquimica de Oxigenio: ");
	scanf("%lf\n", &parametro[3]);

	printf("Nitratos: ");
	scanf("%lf\n", &parametro[4]);

	printf("Fosfatos: ");
	scanf("%lf\n", &parametro[5]);

	printf("Temperatura(ºC): ");
	scanf("%lf\n", &parametro[6]);

	printf("Turbidez: ");
	scanf("%lf\n", &parametro[7]);

	printf("Residuos Totais: ");
	scanf("%lf\n", &parametro[8]);

	return 0;
}
