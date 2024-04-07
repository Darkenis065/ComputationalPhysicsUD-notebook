#include<iostream>
#include<cmath>
#include<fstream>
double Ueff(double L, double r, double m, double M, double Mu, double G){
return ((L*L)/(2*Mu*r*r) - (G*m*M)/(r));
}

//Definimos la función a integrar:
double FUNcion(double E, double L ,double r, double Mu, double m, double M, double G){
	return (Mu*r*r*(sqrt(E-Ueff(L,r,m,M,Mu,G)))/(L*L));
}
//definimos tambien el diferencial del angulo por medio de la otra integral
double dr(double E, double L, double r, double Mu, double m, double M, int N, double G, double o){
	double h2 = (o-(o-0.01))/N;
	double suma2 = 0.0;
	double raux;
	for(int j = 2; j<N-1; j++){
	double rj = 1 + j*h2;
		suma2 += FUNcion(E,L,rj,Mu,m,M,G);
		raux = rj;
	}
	return h2*(0.5*FUNcion(E,L,r,Mu,m,M,G) + suma2 + 0.5*FUNcion(E,L,raux,Mu,m,M,G));

}

double r_a(double o, double a, double e){
	return (a*(1-e*e))/(a*(1+e*cos(o)));
}


int main(){
double e = 0.0167;
double r = 1.496*pow(10,11);
double R = 1.521*pow(10,11);
double M = 1.989*pow(10,30);
double m = 5.97*pow(10,24);
double Mu = (m*M)/(m+M);
double v_0 = 30.3*pow(10,3);
double L = R*m*v_0;
double G = 6.67*pow(10,-11);
double T = sqrt(pow(R,3)*(1/(G*Mu)));
double E = 0.5*Mu*v_0*v_0 + (0.5*L*L)/(Mu*R*R) - (G*m*M)/R;
int N = 50;
int Y = 1000;
double o = 0.0;
std::ofstream file1("Resultados_numericos.dat");
for (int k = 1; k<Y; k++){
	o += 0.01;
	//r = dr(E,L,r,Mu,m,M,N,G,o);
	double h=(o-(o-0.01))/N;
	file1<<k<<"	"<<r<<"	"<<o<<"	"<<r_a(o,R,e)<<"	"<< FUNcion(E,L,(1*pow(10,11)),Mu,m,M,G)<<"	"<<std::endl;
}
file1.close();

return 0;

}
