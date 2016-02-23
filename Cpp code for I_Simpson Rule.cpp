// hw2.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
using namespace std;
double f_int(double x);
double I_simpson(double a, double b, int n);
int main()
{
  double a;
  double b;
  double n;
  double loop_n;
  double f;
  double prev_d;
  double diff_d=-1;
  cout << "Enter lower limit: ";
  cin >> a;
  cout << "Enter upper limit: ";
  cin >> b;
  cout << "Enter number of partitions: ";
  cin >> n;
  
  for (double i=0;i<10;i++)
  {
  loop_n=n*pow(2,i);
  double d = I_simpson(a, b,loop_n);
  if (i>0) 
  { diff_d= abs (prev_d - d); }
  else diff_d=-1;
  prev_d= d;
  std::cout << "n =" <<loop_n<<" |  d= "<< std::setprecision (12) << d <<" | tolerance = "<<diff_d << std::endl;
    }
system ("PAUSE");
  return 0;
}
double f_int(double x)
{
  double c;
 // cout << "Enter your function: ";
  //cin >> c;
   double y = (1/sqrt(2*M_PI))*exp(x*x*(-1)/2);
  //  printf (" x=%f | y=%f | \n",x,y);
    return (y);

}
double I_simpson(double a, double b, int n)
{
	double h = (b-a)/n;
	double I_simpson = 0;
	int i;
	I_simpson = (f_int(a)/6) + (f_int(b)/6);
	for ( i=1 ; i<=(n-1) ; i++)
		{
		I_simpson = I_simpson + (f_int(a + (i * h))/3);
	}
	for (i=1 ; i<=n ; i++)
		{ 
		I_simpson = I_simpson + ((2*f_int(a + (i - (1.0/2))*h))/3);
	}
	I_simpson *= h;
	return I_simpson;
}