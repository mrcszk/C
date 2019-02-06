#include <stdio.h>

int main(void) {
	int godz, sek;
	printf("Podaj liczbę godzin:");
	scanf_s("%d", &godz);
	sek = 3600 * godz;
	printf("Jest to %d sekund.\n", sek);
	getchar();
	getchar();
	return 0;
}