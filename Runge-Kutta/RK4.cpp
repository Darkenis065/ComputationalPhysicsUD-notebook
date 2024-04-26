#include<iostream>
#include<fstream>
#include<cmath>

double f1(double x, double y){
return ((y+2)/(x-2)); //y(0)=1
}
double f2(double x, double y){
return (1-(y/x)); //y(-1/2)=2
}
double f3(double x, double y){
return (y-cos(((M_PI)*x/2))); //y(-1)=0
}
double f4(double x, double y){
return (0-2*x*x*x+12*x*x-20*x+8); //y(0)=1
}
double f5(double x, double y){
return (exp(3*x+2*y)); //y(0)=1
}
//Implementación RK4
double RK41(double x0, double y0, double h, double xf){
double k1,k2,k3,k4;
double y=y0;

h = xf - x0;
k1 = f1(x0,y);
k2 = f1(x0+0.5*h,y+0.5*h*k1);
k3 = f1(x0+0.5*h,y+0.5*h*k2);
k4 = f1(x0+h,y+k3);

y=y + 1.6666666667*(k1+2.0*k2+2.0*k3*k4);

return y;
}
double RK42(double x0, double y0, double h, double xf){
double k1,k2,k3,k4;
double y=y0;

h = xf - x0;
k1 = f2(x0,y);
k2 = f2(x0+0.5*h,y+0.5*h*k1);
k3 = f2(x0+0.5*h,y+0.5*h*k2);
k4 = f2(x0+h,y+k3*h);

y=y + 1.6666666667*h*(k1+2.0*k2+2.0*k3*k4);


return y;
}
double RK43(double x0, double y0, double h, double xf){
double k1,k2,k3,k4;
double y=y0;

h = xf - x0;
k1 = f3(x0,y);
k2 = f3(x0+0.5*h,y+0.5*h*k1);
k3 = f3(x0+0.5*h,y+0.5*h*k2);
k4 = f3(x0+h,y+k3*h);

y=y + 1.6666666667*h*(k1+2.0*k2+2.0*k3*k4);

return y;
}
double RK44(double x0, double y0, double h, double xf){
double k1,k2,k3,k4;
double y=y0;

h = xf - x0;
k1 = f4(x0,y);
k2 = f4(x0+0.5*h,y+0.5*h*k1);
k3 = f4(x0+0.5*h,y+0.5*h*k2);
k4 = f4(x0+h,y+k3*h);

y=y + 1.6666666667*h*(k1+2.0*k2+2.0*k3*k4);

return y;
}
double RK45(double x0, double y0, double h, double xf){
double k1,k2,k3,k4;
double y=y0;

h = xf - x0;
k1 = f5(x0,y);
k2 = f5(x0+0.5*h,y+0.5*h*k1);
k3 = f5(x0+0.5*h,y+0.5*h*k2);
k4 = f5(x0+h,y+k3*h);

y=y + 1.6666666667*h*(k1+2.0*k2+2.0*k3*k4);

return y;
}

double y_a1(double x){
return (1.0-(3.0 * x)/(2.0));
}
double y_a2(double x){
return (0.0 - (9.0/(8.0 * x)) + x/2.0);
}
double y_a3(double x){
return ((4.0*cos(M_PI*x/2.0)-2.0*M_PI*(sin(M_PI*x/2.0+exp(x+1.0))))/(4.0+M_PI*M_PI));
}
double y_a4(double x){
return (0.0-x*x*x*x/2.0+4.0*x*x*x-10.0*x*x+8.0*x+1.0);
}
double y_a5(double x){
return (-0.5*log(-2.0*exp(3.0*x)/3.0+2.0/3.0+exp(-2.0)));
}

int main(){
double x0=0, y0=1.0, x=10.0, h=0.1;

double x02=-0.5, y02=2.0;

double x03=-1.0, y03=0.0;

double x04=0.0, y04=1.0;

double x05=0.0, y05=1.0;

std::ofstream dat1("datos1.dat");
dat1<<"x"<<"\t"<<"RK4"<<"\t"<<"y_a1"<<"\t"<<"E"<<std::endl;
double xi = x0;
double yrk41 = y0;
while(xi <= x){
yrk41 = RK41(x0,yrk41,h,xi);
double y_ex1 = y_a1(xi); 
double error1 = std::abs(yrk41-y_ex1);
dat1<<xi<<"\t"<<yrk41<<"\t"<<y_ex1<<"\t"<<error1<<std::endl;
xi += h;
}
dat1.close();
std::ofstream gp1("graficador1.gp");
gp1<<"set term png\n";
gp1<<"set output 'Grafica1.png'\n";
gp1<<"set xlabel 'x'\n";
gp1<<"set ylabel 'y'\n";
gp1<<"set title 'EDO1'\n";
gp1<<"plot 'datos1.dat' u 1:2 w l t 'RK4', 'datos1.dat' u 1:3 w l t 'Analitica'";
gp1.close();

std::ofstream dat2("datos2.dat");
dat2<<"x"<<"\t"<<"RK4"<<"\t"<<"y_a1"<<"\t"<<"E"<<std::endl;
xi = x02;
double yrk42 = y02;
while(xi <= x){
yrk42 = RK42(x02,yrk42,h,xi);
double y_ex2 = y_a2(xi); 
double error2 = std::abs(yrk42-y_ex2);
dat2<<xi<<"\t"<<yrk42<<"\t"<<y_ex2<<"\t"<<error2<<std::endl;
xi += h;
}
dat2.close();
std::ofstream gp2("graficador2.gp");
gp2<<"set term png\n";
gp2<<"set output 'Grafica2.png'\n";
gp2<<"set xlabel 'x'\n";
gp2<<"set ylabel 'y'\n";
gp2<<"set title 'EDO1'\n";
gp2<<"plot 'datos2.dat' u 1:2 w l t 'RK42', 'datos2.dat' u 1:3 w l t 'Analitica'";
gp2.close();

std::ofstream dat3("datos3.dat");
dat3<<"x"<<"\t"<<"RK4"<<"\t"<<"y_a1"<<"\t"<<"E"<<std::endl;
xi = x03;
double yrk43 = y03;
while(xi <= x){
double yrk43 = RK43(x03,yrk43,h,xi);
double y_ex3 = y_a3(xi); 
double error3 = std::abs(yrk43-y_ex3);
dat3<<xi<<"\t"<<yrk43<<"\t"<<y_ex3<<"\t"<<error3<<std::endl;
xi += h;
}
dat3.close();
std::ofstream gp3("graficador3.gp");
gp3<<"set term png\n";
gp3<<"set output 'Grafica3.png'\n";
gp3<<"set xlabel 'x'\n";
gp3<<"set ylabel 'y'\n";
gp3<<"set title 'EDO3'\n";
gp3<<"plot 'datos3.dat' u 1:2 w l t 'RK4', 'datos3.dat' u 1:3 w l t 'Analitica'";
gp3.close();

std::ofstream dat4("datos4.dat");
dat4<<"x"<<"\t"<<"RK4"<<"\t"<<"y_a1"<<"\t"<<"E"<<std::endl;
xi = x04;
double yrk44 = y04;
while(xi <= x){
yrk44 = RK44(x04,yrk44,h,xi);
double y_ex4 = y_a4(xi); 
double error4 = std::abs(yrk44-y_ex4);
dat4<<xi<<"\t"<<yrk44<<"\t"<<y_ex4<<"\t"<<error4<<std::endl;
xi += h;
}
dat4.close();
std::ofstream gp4("graficador4.gp");
gp4<<"set term png\n";
gp4<<"set output 'Grafica4.png'\n";
gp4<<"set xlabel 'x'\n";
gp4<<"set ylabel 'y'\n";
gp4<<"set title 'EDO4'\n";
gp4<<"plot 'datos4.dat' u 1:2 w l t 'RK4', 'datos3.dat' u 1:3 w l t 'Analitica'";
gp4.close();

std::ofstream dat5("datos5.dat");
dat5<<"x"<<"\t"<<"RK4"<<"\t"<<"y_a1"<<"\t"<<"E"<<std::endl;
xi = x05;
double yrk45 = y05;
while(xi <= x){
yrk45 = RK45(x05,yrk45,h,xi);
double y_ex5 = y_a5(xi); 
double error5 = std::abs(yrk45-y_ex5);
dat5<<xi<<"\t"<<yrk45<<"\t"<<y_ex5<<"\t"<<error5<<std::endl;
xi += h;
}
dat5.close();
std::ofstream gp5("graficador5.gp");
gp5<<"set term png\n";
gp5<<"set output 'Grafica5.png'\n";
gp5<<"set xlabel 'x'\n";
gp5<<"set ylabel 'y'\n";
gp5<<"set title 'EDO5'\n";
gp5<<"plot 'datos5.dat' u 1:2 w l t 'RK5', 'datos5.dat' u 1:3 w l t 'Analitica'";
gp5.close();

system("gnuplot graficador1.gp");
system("gnuplot graficador2.gp");
system("gnuplot graficador3.gp");
system("gnuplot graficador4.gp");
system("gnuplot graficador5.gp");

return 0;
}
