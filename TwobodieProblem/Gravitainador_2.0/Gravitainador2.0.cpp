#include<iostream>
#include<cmath>
#include<fstream>
long double Ueff(long double L, long double r, long double m, long double M, long double Mu, long double G){
return ((L*L)/(2*Mu*r*r) - (G*m*M)/(r));
}

//Definimos la función a integrar:
long double FUNcion(long double E, long double L ,long double r, long double Mu, long double m, long double M, long double G){
	return (Mu*r*r*(sqrt(E-Ueff(L,r,m,M,Mu,G)))/(L*L));
}
//definimos tambien el diferencial del angulo por medio de la otra integral
long double dr(long double E, long double L, long double r, long double Mu, long double m, long double M, int N, long double G, long double o){
	long double h2 = (o-(o-0.01))/N;
	long double suma2 = 0.0;
	long double raux;
	for(int j = 2; j<N-1; j++){
	long double rj = 1 + j*h2;
		suma2 += FUNcion(E,L,rj,Mu,m,M,G);
		raux = rj;
	}
	return h2*(0.5*FUNcion(E,L,r,Mu,m,M,G) + suma2 + 0.5*FUNcion(E,L,raux,Mu,m,M,G));
}

long double r_a(long double o, long double a, long double e){
	return (a*(1-e*e))/(a*(1+e*cos(o)));
}


int main(){
long double e = 0.0167;
long double R = 1.496*pow(10,11);
long double r = 1.521*pow(10,11);
long double M = 1.989*pow(10,30);
long double m = 5.97*pow(10,24);
long double Mu = (m*M)/(m+M);
long double v_0 = 30.3*pow(10,3);
long double L = R*m*v_0;
long double G = 6.67*pow(10,-11);
long double T = sqrt(pow(R,3)*(1/(G*Mu)));
long double E = 0.5*Mu*v_0*v_0 + (0.5*L*L)/(Mu*R*R) - (G*m*M)/R;
int N = 1000;
int Y = 36000;
long double o = 0.0;
std::ofstream file1("Resultados_numericos.dat");
for (int k = 1; k<Y; k++){
	o += o + 0.01;
	r = dr(E,L,r,Mu,m,M,N,G,o); 
	file1<<k<<"	"<<r<<"	"<<o<<"	"<<r_a(o,R,e)<<"	"<<1/r <<"	"<<std::endl;
}
file1.close();

return 0;

}
