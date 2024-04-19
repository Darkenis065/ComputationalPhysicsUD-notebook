#include<iostream>
#include<cmath>

double function(double x, double y){
return x*x+y;
}

double euler_m(double x0,double y0,double h, double xf){
double x = x0;
double y = y0;
while(x<xf){
double y_a = y-h*function(x,y);
double y_s = 0.5*h*(function(x,y)+function(x+h,y_a))
y = y_s;
x+ = h;
}
}
int main()
{


}


