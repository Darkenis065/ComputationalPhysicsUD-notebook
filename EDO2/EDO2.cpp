#include<iostream>
#include<cmath>
#include<fstream>

double Va(double v_0, double v_l, double g, double t, double t_0, double e){
return (0-v_l*(((v_0-v_l)*exp(((g*(t-t_0)/v_l))))+((v_0+v_l)*exp(((((-1)*g*(t-t_0))/v_l)))))/(((v_0-v_l)*exp(((g*(t-t_0)/v_l))))-((v_0+v_l)*exp(((((-1)*g*(t-t_0))/v_l))))));
}
double Xa(double x0, double vl, double v0, double g, double t, double t0, double e){
return (x0 - (vl*log((v0-vl)*exp((g*t)/vl)-(v0+vl)*exp((2*g*t0)/(vl) - (g*t)/(vl))))/(g) + (vl*log((v0-vl)*exp((g*t0)/vl)-(v0+vl)*exp((2*g*t0)/(vl) - (g*t0)/(vl))))/(g));
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
double X = 0.0;
double x0 = 0.0;
double h = 1;
int S;
std::string choose = "";
system("clear");
std::cout<<"::::::::::"<<"\t"<<"Bienvenido al entorno de ejecución del problema del paracaidista"<<"\t"<<"::::::::::"<<std::endl;
std::cout<<"El problema sera abordado bajo las siguientes consideraciones físicas."<<std::endl;
std::cout<<"1."<<"\t"<<"El paracaidista parte del reposo."<<std::endl;
std::cout<<"2."<<"\t"<<"El paracaidista posee una masa de 70Kg."<<std::endl;
std::cout<<"3."<<"\t"<<"El paracaidista salta de una altura despreciable respecto al nivel del mar."<<std::endl;
std::cout<<"4."<<"\t"<<"El paracaidista su posicion inicial es 0."<<std::endl;
std::cout<<"4."<<"\t"<<"El medio material en el que sucede la caida es aire."<<std::endl;
std::cout<<"5."<<"\t"<<"El paracaidas posee un area de 0.6m²."<<std::endl;
std::cout<<"Dichas consideraciones no podran ser modificadas por el usuario ¿Esta de acuerdo?.(s/n)"<<std::endl;
std::cin>>choose;
if(choose == "Si" or choose == "si" or choose == "sI" or choose == "SI" or choose == "S" or choose == "s" or choose == "siks"){
system("clear");
std::cout<<"Por favor elija el metodo de solución:"<<std::endl;
std::cout<<"1."<<"\t"<<"Series de Taylor."<<std::endl;
std::cout<<"2."<<"\t"<<"Metodo de Euler."<<std::endl;
std::cout<<"3."<<"\t"<<"Metodo de Euler Mejorado."<<std::endl;
std::cout<<"4."<<"\t"<<"Runge Kutta 4to orden."<<std::endl;

std::ofstream datos("datos.dat");
for(int t = 1; t<N; t++){
 Vtay = Taylor(Vtay,b,m,g,h);
 Veu = euler(Veu,b,m,g,h);
 VeuM = eulerM(VeuM,t,b,m,g,h,tf);
 V = (-1)*Va(v_0,v_l,g,t,t_0,e);
 X = Xa(x0,v_l,v_0,g,t,t_0,e);
datos <<t<<"	"<<V<<"	"<<Vtay<<"	"<<Veu<<"	"<<VeuM<<"	"<<(std::abs(V-Vtay)*100)/V<<"	"<<(std::abs(V-Veu)*100)/V<<"	"<<(std::abs(V-VeuM)*100)/V<<"	"<<X<<std::endl;
}
datos.close();
std::cin>>S;
switch (S){
	case 1:{
	std::ofstream gp("Graficador.gp");
	gp<<"set term png\n";
	gp<<"set xlabel 't(s)'\n";
	gp<<"set ylabel 'v(m/s)'\n";
	gp<<"set output 'GAnalitica.png'\n";
	gp<<"set title 'Velocidad contra tiempo.'\n";
	gp<<"plot 'datos.dat' u 1:2 w l t 'Analitica','datos.dat' u 1:3 w l t 'Taylor'";
	gp.close();
	std::ofstream gp2("Graficador2.gp");
	gp2<<"set term png\n";
	gp2<<"set xlabel 'Pasos'\n";
	gp2<<"set ylabel 'Error'\n";
	gp2<<"set output 'GError.png'\n";
	gp2<<"set title 'Error'\n";
	gp2<<"plot [0:50] 'datos.dat' u 1:6 w l t 'Taylor'";
	gp2.close();}
	break;
	case 2:{
	std::ofstream gp3("Graficador.gp");
	gp3<<"set term png\n";
	gp3<<"set xlabel 't(s)'\n";
	gp3<<"set ylabel 'v(m/s)'\n";
	gp3<<"set output 'GAnalitica.png'\n";
	gp3<<"set title 'Velocidad contra tiempo.'\n";
	gp3<<"plot 'datos.dat' u 1:2 w l t 'Analitica','datos.dat' u 1:4 w l t 'Euler'";
	gp3.close();
	std::ofstream gp4("Graficador2.gp");
	gp4<<"set term png\n";
	gp4<<"set xlabel 'Pasos'\n";
	gp4<<"set ylabel 'Error'\n";
	gp4<<"set output 'GError.png'\n";
	gp4<<"set title 'Error'\n";
	gp4<<"plot [0:50] 'datos.dat' u 1:7 w l t 'Euler Mejorado'";
	gp4.close();}
	break;
	case 3:{
	std::ofstream gp5("Graficador.gp");
	gp5<<"set term png\n";
	gp5<<"set xlabel 't(s)'\n";
	gp5<<"set ylabel 'v(m/s)'\n";
	gp5<<"set output 'GAnalitica.png'\n";
	gp5<<"set title 'Velocidad contra tiempo.'\n";
	gp5<<"plot 'datos.dat' u 1:2 w l t 'Analitica','datos.dat' u 1:5 w l t 'Euler Mejorado'";
	gp5.close();
	std::ofstream gp6("Graficador2.gp");
	gp6<<"set term png\n";
	gp6<<"set xlabel 'Pasos'\n";
	gp6<<"set ylabel 'Error'\n";
	gp6<<"set output 'GError.png'\n";
	gp6<<"set title 'Error'\n";
	gp6<<"plot [0:50] 'datos.dat' u 1:8 w l t 'Euler Mejorado'";
	gp6.close();}
	break;
	case 4:
	//std::ofstream gp("Graficador.gp");
	//gp<<"set term png\n";
	//gp<<"set xlabel 't(s)'\n";
	//gp<<"set ylabel 'v(m/s)'\n";
	//gp<<"set output 'GAnalitica.png'\n";
	//gp<<"set title 'Velocidad contra tiempo.'\n";
	//gp<<"plot 'datos.dat' u 1:2 w l t 'Analitica','datos.dat' u 1:3 w l t 'Taylor'";
	//gp.close();
	//std::ofstream gp2("Graficador2.gp");
	//gp2<<"set term png\n";
	//gp2<<"set xlabel 'Pasos'\n";
	//gp2<<"set ylabel 'Error'\n";
	//gp2<<"set output 'GError.png'\n";
	//gp2<<"set title 'Error'\n";
	//gp2<<"plot [0:50] 'datos.dat' u 1:6 w l t 'Taylor';
	//gp2.close();
	std::cout<<"La implementación por Runge Kutta de 4to orden se encuentra en desarrollo"<<std::endl;
	break;
	default:
	std::cout<<"El valor introducido no es una de las opciones"<<std::endl;
	break;
}



system("gnuplot Graficador.gp");
system("gnuplot Graficador2.gp");
system("clear");
std::string choose2;
std::cout<<"¿Desea un viaje en tren para finalizar?(s/n)"<<std::endl;
std::cin>> choose2;
if(choose2 == "Si" or choose2 == "si" or choose2 == "sI" or choose2 == "SI" or choose2 == "S" or choose2 == "s" or choose2 == "siks"){
system("clear");
system("sl");
}
else {
std::cout<<":("<<std::endl;
}
}
else{
std::cout<<"Al no estar deacuerdo con las condiciones impuestas el programa no será ejecutado, tenga una feliz tarde."<<std::endl;
}
return 0;
}
