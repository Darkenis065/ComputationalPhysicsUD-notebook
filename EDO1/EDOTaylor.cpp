#include<iostream>
#include<cmath>
#include<fstream>
double solA(double x){
double y;
y=(-1)/((x)/(2)+(x*x)/(4)-1);
return y;
}
double d_f(double x, double y){
return 0.5*(1+x)*y*y;
}
double d_2f(double x, double y){
return (0.5*y*y)+(1+x)*y*d_f(x,y);
}
double d_3f(double x, double y){
return 2*y*d_f(x,y)+(1+x)*(d_f(x,y))*(d_f(x,y))+(1+x)*y*d_2f(x,y);
}
double sTaylor(double x0 , double y0 , double h){
double y_i;
y_i=y0+h*(d_f(x0,y0))+0.5*h*h*d_2f(x0,y0) + (0.166666666667)*h*h*h*d_3f(x0,y0);
return y_i;
}
int main(){
double x0,y0,h;
std::cout<<"Fleiz cumpleaños"<<std::endl;
std::cout<<"Ingrese x_0"<<std::endl;
std::cin>>x0;
std::cout<<"Ingrese y_0"<<std::endl;
std::cin>>y0;
std::cout<<"Ingrese h"<<std::endl;
std::cin>>h;
double x_i = x0;
double y_i = y0;
double y_a;
std::ofstream datafile("Resultados_EDO.dat");
for(int i = 1; i<=100; i++){
y_i = sTaylor(x_i,y_i,h);
y_a = solA(x_i);
x_i = x_i + h;
datafile<<x_i<<"	"<<y_i<<"	"<<y_a<<std::endl;
}
datafile.close();
std::ofstream Gnuplotvs("Analitica_vs_Taylor.gp");
Gnuplotvs<<"set term png\n";
Gnuplotvs<<"set xlabel 'x'\n";
Gnuplotvs<<"set ylabel 'f(x)'\n";
Gnuplotvs<<"set output 'Analitica_vs_Taylor.png'\n";
Gnuplotvs<<"plot 'Resultados_EDO.dat' u 1:2 w p pt 4 ps 2 title 'Solucion numerica', '' u 1:3 w l lw 5 title 'Solucion Analitica'\n";
Gnuplotvs.close();

std::ofstream datafile2("Datos_EDO.dat");
int N = 100;
double div = (1.0)/N;
for(double x=0.0; x<=1.0; x+=div){
datafile2<<x<<"	"<<solA(x)<<std::endl;
datafile2<<std::endl;
}
datafile2.close();
std::ofstream datosf("Datos_Funcion.gp");
datosf<<"set xlabel 'x'\n";
datosf<<"set ylabel 'f(x)'\n";
datosf<<"set term png\n";
datosf<<"set output 'Funcion.png'\n";
datosf<<"plot 'Datos_EDO.dat' u 1:2 w p pt 4 ps 2 title 'f(x)'\n";
datosf.close();
system("gnuplot Analitica_vs_Taylor.gp");
system("gnuplot Datos_Funcion.gp");
}










