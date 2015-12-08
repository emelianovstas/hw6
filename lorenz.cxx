#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void funct(double* const f, const double* p, double x, double y, double z);

int main()
{
	double tstart=0, tend=100, dt=0.0001;
	int N=(tend-tstart)/dt+1;
	double p[3];
	p[0]=10;
	p[1]=28;
	p[2]=8/3;

	double x=1,y=1,z=1;
	double k1[3],k2[3],k3[3],k4[3];


		ofstream out("output.txt");
		out<< tstart << "\t" << x << "\t" << y << "\t" << z <<endl;

for (int i=1; i<(N-1); i++)
{
	funct(k1,p,x,y,z);	
	funct(k2,p,x+dt/2*k1[0],y+dt/2*k1[1],z+dt/2*k1[2]);
	funct(k3,p,x+dt/2*k1[0],y+dt/2*k1[1],z+dt/2*k1[2]);
	funct(k4,p,x+dt*k3[0],y+dt*k3[1],z+dt*k3[2]);

		x+=dt/6*(k1[0]+2*k2[0]+2*k3[0]+k4[0]);
		y+=dt/6*(k1[1]+2*k2[1]+2*k3[1]+k4[1]);
		z+=dt/6*(k1[2]+2*k2[2]+2*k3[2]+k4[2]);

			out << tstart+i*dt << "\t" << x << "\t" << y << "\t" << z << endl;
}

out.close();
return 0;
}

void funct(double* const f, const double* p, double x, double y, double z)
{
	f[0]=p[0]*(y-x);
	f[1]=x*(p[1]-z)-y;
	f[2]=x*y-p[2]*z;
}
