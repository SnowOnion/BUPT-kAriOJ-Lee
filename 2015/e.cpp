#include<cstdio>
#include<cmath>

const double pi=atan(1.0)*4;

double deg2rad(double deg){
	return pi*deg/180.0;
}

int main(){

	double v,alpha,theta;

	while(-1!=scanf("%lf%lf%lf",&v,&alpha,&theta)){

	double vxx=v*cos(deg2rad(theta-alpha));
	double vyy=v*sin(deg2rad(theta-alpha));
	double axx=-10.0*sin(deg2rad(alpha));
	double ayy=-10.0*cos(deg2rad(alpha));

	double t=fabs((2.0*vyy)/ayy);
	double dis=vxx*t+0.5*axx*t*t;

	printf("%.2lf\n",dis);
	}

	return 0;
}