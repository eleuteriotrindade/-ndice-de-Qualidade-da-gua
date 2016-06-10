#include <stdio.h>
#include <math.h>

#define e 2.718281828459045235360287
#define pi 3.14159265358979323846

//parametros: Oxigenio dissolvido(OD), Coliformes Fecais(CF), Potencial Hidrogenionico(pH), Demanda Bioquimica de Oxigenio(DBO), Nitratos(NO), Fosfatos(PO), Temperatura(C), Turbidez(UNT), Residuos Totais(RT)
//ordem dos pesos: OD CF pH DBO NO PO C UNT RT
double peso[9]={0.17,0.15,0.12,0.10,0.10,0.10,0.10,0.08,0.08} 
double parametro[9],qualidade[9]

double produtorio(double iqa[9])
{
	k=0;
	for(i=1,i<=9,++i)
	{
		iqa[k]=pow(qualidade[k],peso[k]);
		k++;
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------

double coliformesfecais(double qualidade[1])
{
	if (parametro[1] <= 100000){
		
		qualidade[1] = 98.24034 - 34.7145 * (log(parametro[1])) + 2.614267 * pow((log(parametro[1])), 2) + 0.107821 * pow((log(parametro[1])), 3); 
	
	}else{
	
		qualidade[1] = 3.0;
	
	}
}	

//--------------------------------------------------------------------------------------------------------------------------------------
	
double ph(double qualidade[2])
{
	
if (parametro[2] <= 2){

	qualidade[2] =  2.0;
}

if (parametro[2] > 2 && parametro[2] <= 6.9){

	qualidade[2] = -37.1085 + 41.91277 * parametro[2] - 15.7043 * (pow(parametro[2], 2)) + 2.417486 * (pow(parametro[2], 3)) - 0.091252 * (pow(parametro[2], 4)); 

}

if (parametro[2] > 6.9 && parametro[2] <= 7.1){

	qualidade[2] = -4.69365 - 21.4593 * parametro[2] - 68.4561 * (pow(parametro[2], 2)) + 21.638886 * (pow(parametro[2], 3)) - 1.59165 * (pow(parametro[2], 4));

}

if (parametro[2] > 7.1 && parametro[2] <= 12){

	qualidade[2] = 7698.19 + 3262.031 * parametro[2] - 499.494 * (pow(parametro[2], 2)) + 33.1551 * (pow(parametro[2], 3)) - 0.810613 * (pow(parametro[2], 4));

}

if(parametro[2] >= 12){

	qualidade[2] = 3.0; 

}
}	
}

//--------------------------------------------------------------------------------------------------------------------------------------


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
