#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
struct algebraiczna {
	double rzecz;
	double uroj;
};

struct wykladnicza {
	double modul;
	double arg;
};

/*typedef struct algebraiczna{
	float rzecz;
	float uroj;
}Algebr;

typedef struct wykladnicza {
	float modul;
	float arg;
}Wykl;*/
void modarg (struct algebraiczna liczba, struct wykladnicza *number) {
	number->modul = sqrt((liczba.rzecz*liczba.rzecz) + ((liczba.uroj)*(liczba.uroj)));
	number->arg = atan2((liczba.uroj),(liczba.rzecz));

}

int main(void) {
	struct algebraiczna liczba;
	struct wykladnicza number;
	printf("Podaj czesc rzeczywista liczby: ");
	scanf("%lf", &liczba.rzecz);
	printf("Podaj czesc urojona liczby: ");
	scanf("%lf", &liczba.uroj);
	modarg(liczba, &number);
	if (liczba.uroj < 0)
	printf("Postac algebraiczna %lf%lfi\n",liczba.rzecz , liczba.uroj);
	else 
	printf("Postac algebraiczna %lf+%lfi\n", liczba.rzecz, liczba.uroj);

	printf("Postac wykladnicza e^%lf*%lf", number.modul, number.arg);


	getchar();
	getchar();
	return 0;
}