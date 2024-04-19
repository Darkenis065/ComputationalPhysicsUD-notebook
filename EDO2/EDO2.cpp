#include<iostream>
#include<cmath>
#include<fstream>

double Va(double v_0, double v_l, double g, double t, double t_0, double e){
return (0-v_l*(((v_0-v_l)*pow(e,((g*(t-t_0)/v_l))))+((v_0+v_l)*pow(e,((((-1)*g*(t-t_0))/v_l)))))/(((v_0-v_l)*pow(e,((g*(t-t_0)/v_l))))-((v_0+v_l)*pow(e,((((-1)*g*(t-t_0))/v_l))))));
}
double Dv(double v, double b, double m, double g){
return (g - (b*v*v)/m);
}
double D2v(double v, double b, double m ,double g){
return (0-(2*b*v*Dv(v,b,m,g))/m);
}
double D3v(double v, double b, double m, double g){
return (0-(2*b*D2v(v,b,m,g)*Dv(v,b,m,g))/m);
}
double Taylor(double v0, double b, double m, double g, double h){
double v_i;
v_i = v0 + h*Dv(v0,b,m,g) + 0.5*h*h*D2v(v0,b,m,g) + 0.166666666667*h*h*h*D3v(v0,b,m,g);
return v_i;
}
double euler(double v0, double b, double m, double g, double h){
double v_i;
v_i = v0 + h*Dv(v0,b,m,g);
return v_i;
}
double eulerM(double v0, double t0, double b, double m, double g, double h, double tf){
double t = t0;
double v = v0;
while(t<tf){
double v_a = v0 + h*Dv(v,b,m,g);
double v_s = v0 + 0.5*h*(Dv(v,b,m,g) + Dv(v_a,b,m,g));
v = v_s;
t += h;
}
return v;
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
int N = 150;
int tf = 150;
double V = 0.0;
double Vtay = v_0;
double Veu = v_0;
double VeuM = v_0;
double h = 1;
std::ofstream datos("datos.dat");
for(int t = 1; t<N; t++){
 Vtay = Taylor(Vtay,b,m,g,h);
 Veu = euler(Veu,b,m,g,h);
 VeuM = eulerM(VeuM,t,b,m,g,h,tf);
 V = (-1)*Va(v_0,v_l,g,t,t_0,e);
datos <<t<<"	"<<V<<"	"<<Vtay<<"	"<<Veu<<"	"<<VeuM<<"	"<<std::abs(V-Vtay)<<"	"<<std::abs(V-Veu)<<"	"<<std::abs(V-VeuM)<<std::endl;
}
datos.close();
std::ofstream gp("Graficador.gp");
gp<<"set term png\n";
gp<<"set xlabel 't(s)'\n";
gp<<"set ylabel 'v(m/s)'\n";
gp<<"set output 'GAnalitica.png'\n";
gp<<"set title 'Velocidad contra tiempo.'\n";
gp<<"plot 'datos.dat' u 1:2 w l t 'Analitica','datos.dat' u 1:3 w l t 'Taylor','datos.dat' u 1:4 w l t 'Euler','datos.dat' u 1:5 w l t 'Euler mejorado' ";
gp.close();
std::ofstream gp2("Graficador2.gp");
gp2<<"set term png\n";
gp2<<"set xlabel 'Pasos'\n";
gp2<<"set ylabel 'Error'\n";
gp2<<"set output 'GError.png'\n";
gp2<<"set title 'Error'\n";
gp2<<"plot [0:50] 'datos.dat' u 1:6 w l t 'Taylor','datos.dat' u 1:7 w l t 'Euler','datos.dat' u 1:8 w l t 'Euler mejorado'";
gp2.close();
system("gnuplot Graficador.gp");
system("gnuplot Graficador2.gp");
return 0;
}
