#include <stdio.h>
#include <math.h>

#define e 2.718281828459045235360287
#define pi 3.14159265358979323846

//parametros: Oxigenio dissolvido(OD), Coliformes Fecais(CF), Potencial Hidrogenionico(pH), Demanda Bioquimica de Oxigenio(DBO), Nitratos(NO), Fosfatos(PO), Temperatura(C), Turbidez(UNT), Residuos Totais(RT)
//ordem dos pesos: OD CF pH DBO NO PO C UNT RT
double peso[9]={0.17,0.15,0.12,0.10,0.10,0.10,0.10,0.08,0.08};
double parametro[9];
double qualidade[9];
double ox;
double co;
double p;
double db;
double ni;
double fo;
double te;
double tu;
double re;

//----------Somatório-------------------------------------------------------------------------------------------------------------------
double somatorio()
{
	double x=0;
	x = ox * co * p * db * ni * fo * te * tu * re;
	
	printf("\n\nSeu IQA é %.10f\nA qualidade da água é:",x);
	
	if (x<=19)
	printf("Péssima\n");
	else if (x > 19 && x <= 36)
	printf("Ruim\n");
	else if (x > 36 && x <= 50)
	printf("Aceitável\n");
	else if (x > 50 && x <= 79)
	printf("Boa\n");
	else
	printf("Ótima\n");
}
//----------Oxigenio Dissolvido---------------------------------------------------------------------------------------------------------
double oxigenio()
{
	printf("Oxigenio Dissolvido: ");
	scanf("%lf", &parametro[0]);
	
	double cs, odx;
	//cs:concentracao de saturacao
	cs=(14.2*pow(e,-0.0212*parametro[6])-(0.0016*9.09*pow(e,-0.0264*parametro[6])))*(0.994-(0.0001042*860));

	odx=(parametro[0]/cs)*100;

	if(odx<=100)
	{
		double y1,y2,y3,y4,y5;
		y1=0.01396*odx+0.0873;
		y2=(pi/56.0)*(odx-27.0);
		y3=(pi/85.0)-(odx-15.0);
		y4=(odx-65.0)/10.0;
		y5=(65.0-odx)/10.0;

		qualidade[0]=100*pow(sin(y1),2)-(2.5*sin(y2))-0.018*odx+6.86*sin(y3)+(12/pow(e,y4)+pow(e,y5));
	}
	else if(odx>100 && odx<=140)
	{
		qualidade[0]= -0.00777142857142832*pow(odx,2)+(1.27854285714278*odx)+(49.8817148572);
	}
	else
	{
		qualidade[0]=47.0;
	}
	//printf("%f\n",qualidade[0]);
	ox = pow(qualidade[0],peso[0]);
}

//-------Coliformes Fecais--------------------------------------------------------------------------------------------------------------

double coliformesfecais()
{
	printf("\nColiformes Fecais: ");
	scanf("%lf", &parametro[1]);
	
	if (parametro[1] <= 100000)
	{
		qualidade[1] = 98.24034 - 34.7145 * (log10(parametro[1])) + 2.614267 * pow(log10(parametro[1]), 2) + 0.107821 * pow(log10(parametro[1]), 3); 
	}
	else
	{
		qualidade[1] = 3.0;
	}
	//printf("%f\n",qualidade[1]);
	co = pow(qualidade[1], peso[1]);
}	

//-------pH-----------------------------------------------------------------------------------------------------------------------------
	
double ph()
{
	printf("\nPotencial Hidrogenionico(pH): ");
	scanf("%lf", &parametro[2]);
	
	if (parametro[2] <= 2)
	{
		qualidade[2] =  2.0;
	}

	else if (parametro[2] > 2 && parametro[2] <= 6.9)
	{
		qualidade[2] = -37.1085 + 41.91277 * parametro[2] - 15.7043 * (pow(parametro[2], 2)) + 2.417486 * (pow(parametro[2], 3)) - 0.091252 * (pow(parametro[2], 4)); 
	}

	else if (parametro[2] > 6.9 && parametro[2] <= 7.1)
	{
		qualidade[2] = -4.69365 - 21.4593 * parametro[2] - 68.4561 * (pow(parametro[2], 2)) + 21.638886 * (pow(parametro[2], 3)) - 1.59165 * (pow(parametro[2], 4));
	}

	else if (parametro[2] > 7.1 && parametro[2] <= 12)
	{
		qualidade[2] = -7698.19 + 3262.031 * parametro[2] - 499.494 * (pow(parametro[2], 2)) + 33.1551 * (pow(parametro[2], 3)) - 0.810613 * (pow(parametro[2], 4));
	}

	else
	{
		qualidade[2] = 3.0; 
	}
	//printf("%f\n",qualidade[2]);
	p = pow(qualidade[2],peso[2]);
}	


//--------Demanda Bioquímica de Oxigênio------------------------------------------------------------------------------------------------

double dbo()
{
	printf("\nDemanda Bioquimica de Oxigenio: ");
	scanf("%lf", &parametro[3]);
	
	if (parametro[3] <= 30)
	{
		qualidade[3] =  100.9571 - 10.7121 * parametro[3] + 0.49544 * (pow(parametro[3], 2)) - 0.011167 * (pow(parametro[3], 3)) + 0.0001 * (pow(parametro[3], 4));
	}

	else
	{
		qualidade[3] = 2.0; 
	}
	//printf("%f\n",qualidade[3]);
	db = pow(qualidade[3],peso[3]);
}	

//--------Nitratos----------------------------------------------------------------------------------------------------------------------
double totalnitrato()
{
	printf("\nNitratos: ");
	scanf("%lf", &parametro[4]);
	
	if (parametro[4] <= 10)
	{
		qualidade[4] = -5.1 * parametro[4] + 100.17;
	}
	
	else if (parametro[4] > 10 && parametro[4] <= 60)
	{
		qualidade[4] = -22.853 * (log(parametro[4])) + 101.18;
	}
	
	else if (parametro[4] > 60 && parametro[4] <=90)
	{
		qualidade[4] = 10000000000 * (pow(parametro[4], -5.1161));
	}
	
	else if (parametro[4] > 90)
	{
		qualidade[4] = 1.0;
	}
	//printf("%f\n",qualidade[4]);
	ni = pow(qualidade[4],peso[4]);
}


//--------Fosfatos----------------------------------------------------------------------------------------------------------------------
double totalfosfato()
{
	printf("\nFosfatos: ");
	scanf("%lf", &parametro[5]);
	
	if (parametro[5] <= 10)
	{
		qualidade[5] = 79.7 * (pow((parametro[5] + 0.821), -1.15));
	}
	
	else if (parametro[5] > 10)
	{
		qualidade[5] = 5.0;
	}
	//printf("%f\n",qualidade[5]);
	fo = pow(qualidade[5],peso[5]);
}

//--------Variacao de Temperatura-------------------------------------------------------------------------------------------------------

double temperatura()
{
	printf("\nTemperatura(ºC): ");
	scanf("%lf", &parametro[6]);
	
	if(parametro[6] < 800000)
	{
		qualidade[6] = 93.0;
	}
	//printf("%f\n",qualidade[6]);
	te = pow(qualidade[6],peso[6]);
}
//--------Turbidez----------------------------------------------------------------------------------------------------------------------
double turbidez()
{
	printf("\nTurbidez: ");
	scanf("%lf", &parametro[7]);
	
	if(parametro[7] <= 100)
	{
		qualidade[7] = (90.37*pow(e,-0.0169*parametro[7])) - 15*cos(0.0571*(parametro[7] - 30))+10.22*pow(e,-0.231*parametro[7])-0.8;
	}
	else
	{
		qualidade[7] = 5.0;
	}
	//printf("%f\n",qualidade[7]);
	tu = pow(qualidade[7],peso[7]);
}

//--------Resíduos totais---------------------------------------------------------------------------------------------------------------
double residuostotais()
{
	printf("\nResiduos Totais: ");
	scanf("%lf", &parametro[8]);
	
	if(parametro[8]<=500)
	{
		qualidade[8] = 133.17*pow(e,-0.0027*parametro[8])-53.17*pow(e,-0.0141*parametro[8])+(-6.2*pow(e,-0.00462*parametro[8]))*sin(0.0146*parametro[8]);
	}
	else
	{
		qualidade[8] = 30.0;
	}
	//printf("%f\n",qualidade[8]);
	re = pow(qualidade[8],peso[8]);
}

//--------Corpo do programa-------------------------------------------------------------------------------------------------------------

int main(){

	printf("Entre com os parâmetros\n\n");
	
	oxigenio();
	
	coliformesfecais();
	
	ph();
	
	dbo();
	
	totalnitrato();
	
	totalfosfato();
	
	temperatura();
	
	turbidez();
	
	residuostotais();

	somatorio();
	
	return 0;
}
