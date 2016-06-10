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
double oxigenio(double qualidade[0])
{ //#INCOMPLETO
	double cs,odx;
	//cs:concentracao de saturacao
	cs=(14.2*pow(e,-0.0212*qualidade[6])-(0.0016*4/*esse numero nao e constante, mas nao e pedido no iqa, entao considerou-se o 4*/*pow(e,-0.0264*qualidade[6])))*(0.994-(0.0001042*760/*se e considerado a altitude de sao paulo*/));

	odx=(qualidade[0]/cs)*100

	if(cs<=100)
	{
		double y1,y2,y3,y4,y5;
		y1=0.01396*odx+0.0873;
		y2=pi/56*(odx-27);
		y3=pi/85-(odx-15);
		y4=(odx-65)/10;
		y5=(65-odx)/10;

		qualidade[0]=100*pow((sin(y1)),2)-(2.5*sin(y2)-0.018*odx+6.86)*sin(y3))+12/(pow(e,y4)+pow(e,y5))
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
	if (parametro[2] <= 2)
	{
		qualidade[2] =  2.0;
	}

	if (parametro[2] > 2 && parametro[2] <= 6.9)
	{
		qualidade[2] = -37.1085 + 41.91277 * parametro[2] - 15.7043 * (pow(parametro[2], 2)) + 2.417486 * (pow(parametro[2], 3)) - 0.091252 * (pow(parametro[2], 4)); 
	}

	if (parametro[2] > 6.9 && parametro[2] <= 7.1)
	{
		qualidade[2] = -4.69365 - 21.4593 * parametro[2] - 68.4561 * (pow(parametro[2], 2)) + 21.638886 * (pow(parametro[2], 3)) - 1.59165 * (pow(parametro[2], 4));
	}

	if (parametro[2] > 7.1 && parametro[2] <= 12)
	{
		qualidade[2] = 7698.19 + 3262.031 * parametro[2] - 499.494 * (pow(parametro[2], 2)) + 33.1551 * (pow(parametro[2], 3)) - 0.810613 * (pow(parametro[2], 4));
	}

	if(parametro[2] >= 12)
	{
		qualidade[2] = 3.0; 
	}
}	


//--------------------------------------------------------------------------------------------------------------------------------------

double dbo(double qualidade[3])
{
	if (parametro[3] <= 30)
	{
		qualidade[3] =  100.9571 - 10.7121 * parametro[3] + 0.49544 * (pow(parametro[3], 2)) - 0.011167 * (pow(parametro[3], 3)) + 0.0001 * (pow(parametro[3], 4));
	}

	if (parametro[3] > 30)
	{
		qualidade[3] = 2.0; 
	}
}	

//---------------------------------------------------------------------------------------------------------------------------------------




//--------------------------------------------------------------------------------------------------------------------------------------

double temperatura(double qualidade[6])
{
	if (parametro[6] > -0.625 && parametro[6] <= 625)
	{
		qualidade[6] = 93.0;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------

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
