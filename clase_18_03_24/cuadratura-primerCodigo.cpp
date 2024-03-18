#include<iostream>
#include<cmath>
#include<fstream>

int main()
{
	std::ofstream datafile("Resultados.dat");
	for(int N = 1; N <= 10000; N++)
	{
	double integral = 0.0;
	double a = 0.0;
	double b = 1.0;
        double h = (b-a)/N;
		for(int i=0; i<N; i++ )
		{
			double xi=a+(i+0.5)*h;
			integral += 100*(std::pow(xi,2))*std::cos(20*xi);
		}
	integral*=h;
	double integral_exacta=4.7459;
	datafile<<N<<"	"<<integral<<"	"<<integral_exacta<<std::endl;
	}
	datafile.close();
	std::ofstream scriptfile1("Grafico_integral_aproximada.gp");
	scriptfile1<<"set term png\n";
	scriptfile1<<"set output 'Grafica_integral_aproximada.png'\n";
	scriptfile1<<"set xlabel 'N'\n";
	scriptfile1<<"set ylabel 'Integral'\n";
	scriptfile1<<"set logscale x\n";			
	scriptfile1<<"set title 'Integral aproximada'\n";
	scriptfile1<<"plot 'Resultados.dat' u 1:2 w l\n";
	scriptfile1.close();
	
	std::ofstream scriptfile2("Grafico_integral_exacta.gp");
	scriptfile2<<"set term png\n";
	scriptfile2<<"set output 'integral_exacta.png'\n";
	scriptfile2<<"set xlabel 'N'\n";
	scriptfile2<<"set ylabel 'Integral'\n";
	scriptfile2<<"set logscale x\n";
	scriptfile2<<"set title 'Integral exacta'\n";
	scriptfile2<<"plot 'Resultados.dat' u 1:3 w l\n";
	scriptfile2.close();
	
	system("gnuplot Grafico_integral_aproximada.gp ");
	system("gnuplot Grafico_integral_exacta.gp");
	
	return 0;
}
