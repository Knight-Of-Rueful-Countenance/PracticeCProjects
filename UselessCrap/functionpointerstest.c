#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double (*v)(double);

double GetArea(double Radius) 
{
	return pow(Radius,(double)2)*(double)(3.141529);
} 

void main(int argc, char* argv[])
{
	v = GetArea;
	if(argc ==0){return 0;}
	printf("%d\n",(*v)(atof(argv[1])));
	return 0;
}