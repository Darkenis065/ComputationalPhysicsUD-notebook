#include<iostream>			
#include<cmath>
#include<fstream>

//Definimos la función a integrar:
double FUNcion(double E, double l, double R,double Mu, double m, double M,double G){
	return (1/sqrt(2*E-(l*l)/(Mu*R*R)+(G*m*M)/(R)));
}
//definimos tambien el diferencial del angulo por medio de la otra integral
double doT(double E, double l, double R,double r,double Mu, double m, double M, int N, double G){
	double h2 = (R-r)/N;
	double suma2 = 0.0;
	for(int j = 2; j<N-1; j++){
		double rj = r + j*h2;
		suma2 += ((l*l)*FUNcion(E,l,rj,Mu,m,M,G))/(R*R*Mu);
	
	}
	return h2*(0.5*(l*l)*FUNcion(E,l,r,Mu,m,M,G)/(R*R*Mu) + suma2 + 0.5*(l*l)*FUNcion(E,l,R,Mu,m,M,G)/(R*R*Mu));
}
double doS(double E, double l, double R,double r,double Mu, double m, double M, int N, double G){
	double h = (R-r)/N;
	double suma = 0.0;
	double suma1 = 0.0;
	for(int i = 1; i<N;i++){
	double ri = r +i*h;
	suma += ((l*l)*FUNcion(E,l,ri,Mu,m,M,G))/(R*R*Mu);
	}
	for(int i = 2; i<N;i++){
	double bi = r +i*h;
	suma1 += ((l*l)*FUNcion(E,l,bi,Mu,m,M,G))/(R*R*Mu);
	}
	return h*0.166667*((l*l)*FUNcion(E,l,r,Mu,m,M,G)/(R*R*Mu) + 4*suma + 2*suma1 + (l*l)*FUNcion(E,l,R,Mu,m,M,G)/(R*R*Mu));
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
double l = r*m*v_0;
double G = 6.67*pow(10,-11);
double T = sqrt(pow(R,3)*(1/(G*Mu)));
double E = 0.5*Mu*v_0*v_0 + (0.5*l*l)/(Mu*r*r) - (G*m*M)/r;
int N = 100;
int Y = 2500;
double oT = 0.0;
double oS = 0.0;
double oA = 0.0;
//double oG = 0.0;
std::ofstream file1("Resultados_numericos.dat");
for (int k = 1; k<Y; k++){
	oT = doT(E,l,R,r,Mu,m,M,N,G);
	oS = doS(E,l,R,r,Mu,m,M,N,G);
	//oG = doG(E,l,R,r,Mu,m,M,N,G);
	r +=1000000;
	oA += 0.1;
	file1<<k<<"	"<<r<<"	"<<oS<<"	"<<oT<<"	"<<r_a(oA,R,e)<<"	"<<oA<<std::endl;
}
file1.close();
std::ofstream gp("GraficadorNum.gp");
gp<<"set term png\n";
gp<<"set output 'GraficaNum.png'\n";
gp<<"set xlabel 'x (m)'\n";
gp<<"set ylabel 'y (m)'\n";
gp<<"x(r,o) = (r)*cos(o)\n";
gp<<"y(r,o) = (r)*sin(o)\n";
gp<<"set title 'Elipse trapecios'\n";
gp<<"plot 'Resultados_numericos.dat' u (x($2,$4)):(y($2,$4))";
gp.close();

std::ofstream gp2("GraficadorNum2.gp");
gp2<<"set term png\n";
gp2<<"set output 'GraficaNum2.png'\n";
gp2<<"set xlabel 'x (m)'\n";
gp2<<"set ylabel 'y (m)'\n";
gp2<<"x(r,o) = (r)*cos(o)\n";
gp2<<"y(r,o) = (r)*sin(o)\n";
gp2<<"set title 'Elipse simpson'\n";
gp2<<"plot 'Resultados_numericos.dat' u (x($2,$3)):(y($2,$3))";
gp2.close();

std::ofstream gp3("GraficadorA.gp");
gp3<<"set term png\n";
gp3<<"set output 'GraficaA.png'\n";
gp3<<"set xlabel 'x (UA)'\n";
gp3<<"set ylabel 'y (UA)'\n";
gp3<<"x(r,o) = (r)*cos(o)\n";
gp3<<"y(r,o) = (r)*sin(o)\n";
gp3<<"set title 'Elipse Analitica'\n";
gp3<<"plot 'Resultados_numericos.dat' u (x($5,$6)):(y($5,$6))";
gp3.close();

system("gnuplot GraficadorA.gp");
system("gnuplot GraficadorNum.gp");
system("gnuplot GraficadorNum2.gp");

return 0;

}
