#include<iostream>
#include<cmath>
#include<fstream>

double Va(double v_0, double v_l, double g, double t, double t_0, double e){
return (0-v_l*(((v_0-v_l)*pow(e,((g*(t-t_0)/v_l))))+((v_0+v_l)*pow(e,((((-1)*g*(t-t_0))/v_l)))))/(((v_0-v_l)*pow(e,((g*(t-t_0)/v_l))))-((v_0+v_l)*pow(e,((((-1)*g*(t-t_0))/v_l))))));
}

int main(){
double t_0 = 0.0;
double del = 0.8;
double rho = 1.225;
double A = 0.6;
double m = 70;
double b = rho*A*del*0.5;
double g = 9.81;
double v_0 = 0.0;
double v_l = sqrt((m*g)/(b));
double e = 2.7182818284;
int N = 100;
double V = 0.0;
std::ofstream datos("datos.dat");
for(int t = 1; t<N; t++){
 V = (-1)*Va(v_0,v_l,g,t,t_0,e);
datos <<t<<"	"<<V<<std::endl;
}
datos.close();
std::ofstream gp("Graficador.gp");
gp<<"set term png\n";
gp<<"set xlabel 't(s)'\n";
gp<<"set ylabel 'v(m/s)'\n";
gp<<"set output 'GAnalitica.png'\n";
gp<<"set title 'Velocidad contra tiempo.'\n";
gp<<"plot 'datos.dat' u 1:2 w l";
gp.close();
system("gnuplot Graficador.gp");
return 0;
}
