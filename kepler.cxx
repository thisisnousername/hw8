/*
author: markus
date:	2015-01-10
*/

#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;
//----------------------------------------------
void step(double*, double*, const double, double&);
//----------------------------------------------
int main(){
	const double pi = acos(-1.0);
	const double ecc = 0.6;
	const double tEnd = 20.0*pi;
	const double dt = 0.0005;
	double t = 0;
	double H;
	double p[2];
	double q[2];

	// initial values
	q[0] = 1.0-ecc;
	q[1] = 0;
	p[0] = 0;
	p[1] = sqrt((1.0+ecc)/(1.0-ecc));

	H = 0.5*(p[0]*p[0]+p[1]*p[1])-1.0/(sqrt(q[0]*q[0]+q[1]*q[1]));

	ofstream out("data");

	out << 0 << "\t" << q[0] << "\t" << q[1] << "\t" << H << endl;

	while(t<tEnd){
	step(p, q, dt, H);
	out << t << "\t" << q[0] << "\t" << q[1] << "\t" << H << endl;
	t+=dt;
	}
	out.close();
	return 0;
}
//----------------------------------------------
void step(double* p, double* q, const double dt, double& H){
	double r = sqrt(q[0]*q[0]+q[1]*q[1]);
	for(int i=0; i<2; i++){
	p[i] -= dt*q[i]/(r*r*r);
	q[i] += dt*p[i];
	}
	H = 0.5*(p[0]*p[0]+p[1]*p[1])-1.0/(sqrt(q[0]*q[0]+q[1]*q[1]));
}
