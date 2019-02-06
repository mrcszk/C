#include <stdio.h>

int main(void) {
	int godz, sek, min, x;
	printf("Podaj liczbę sekund:");
	scanf_s("%d", &sek);

	if (sek >= 0) {
		godz = sek / 3600;
		min = (sek % 3600) / 60;
		sek = (sek % 3600) % 60;

		printf("Jest to %d godzin, %d minut i %d sekund.\n", godz, min, sek);
	}
	else {
		printf("Podałeś błędne dane.\n");
	}
	getchar();
	getchar();
	return 0;
}