#include<iostream>
#include<cmath>
#include<fstream>

//Función para integrar
double funcion(double x){
    return 100*pow(x,2)*cos(20*x);
}

//Calcuilo de la integral aproximada bajo regla trapezoidal
double TrapezoideInador(double a, double b, int N){
    double h=(b-a)/N;
    double suma=0.0;
    for(int i=2;i<N-1;i++){
        double xi=a+i*h;
        suma+=funcion(xi);
    }
    return h*(0.5*funcion(a)+suma+0.5*funcion(b));
}

int main(){

std::ofstream datafile("resultados_regla_trapezoidal.dat");

for(int N=1; N<=10000; ++N){
    double integral = TrapezoideInador(0.0,1.0,N);
    double integral_exacta=4.7459;
    datafile<<N<<" "<<integral<<" "<<integral_exacta<<std::endl;
    }
datafile.close();

std::ofstream scriptFile1("grafico_integral_vs_regla_trapezoidal.gp");
scriptFile1<<"set term png\n";
scriptFile1<<"set output 'grafico_integral_vs_regla_trapezoidal.png'\n";
scriptFile1<<"set xlabel 'N'\n";
scriptFile1<<"set ylabel 'Integral'\n";
scriptFile1<<"set logscale x\n";
scriptFile1<<"plot 'resultados_regla_trapezoidal.dat' u 1:2 w l title 'Integral aproximada', '' u 1:3 w l title 'Valor exacto'\n";
scriptFile1.close();

//Generar datos para graficas y pintar los rectangulos

std::ofstream dataFile2("datos_regla_trapezoidal.dat");
int N_plot=10;
double h_plot=(1.0-0.0)/N_plot;
for(double x=0.0; x<=1.0; x+=h_plot){
    dataFile2<<x<<" "<<funcion(x)<<std::endl;
    dataFile2<<x<<" "<<0.0<<std::endl;
    dataFile2<<std::endl;
}
dataFile2.close();

std::ofstream scriptFile2("grafico_funcion_rectangulos_regla_trapezoidal.gp");
scriptFile2<<"set term png\n";
scriptFile2<<"set output 'grafico_funcion_rectangulos_regla_trapezoidal.png'\n";
scriptFile2<<"set xlabel 'x'\n";
scriptFile2<<"set ylabel 'f(x)'\n";
scriptFile2<<"set logscale x\n";
scriptFile2<<"plot 'datos_regla_trapezoidal.dat' w l title 'Funcion', '' w boxes title 'Rectangulos'\n";
scriptFile2.close();
//Ejecutar Gnuplot
system("gnuplot grafico_integral_vs_regla_trapezoidal.gp");
system("gnuplot grafico_funcion_rectangulos_regla_trapezoidal.gp");

return 0;
}
