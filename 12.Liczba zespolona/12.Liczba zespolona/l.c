#include <stdio.h>
#include <math.h>


int zespolona(double a, double b,double *c,double *d) {
	
*c = sqrt((a)*(a) + (b) * (b));

*d = atan2(b,a);

}

int main() {
	double a , b,c, d;
	printf("Podaj czesc rzeczywista liczby:");
	scanf_s("%lf", &a);
	printf("Podaj czesc urojona liczby:");
	scanf_s("%lf", &b);
	zespolona(a,b,&c,&d);
	printf("Modul liczby zespolonej wynosi %lf\n", c);
	printf("Argument liczby zespolonej wynosi %lf\n", d);

	getchar();
	getchar();
	return 0;
}