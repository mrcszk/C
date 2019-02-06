#pragma warning(disable:4996)
#include <stdio.h>
enum kolory {czerwony, pomaranczowy, zolty,zielony,niebieski,fioletowy};
struct osobowy {
	char marka[20];
	char naped[20];
	int liczba_dzwi;
	int kolor;
	int cena;
	char terminy[10][20];
};
int main(void) {
	struct osobowy avensis;
	enum kolory samochody;
	avensis.marka[0] = "toyota";
	avensis.naped[0] = "diesel";
	avensis.liczba_dzwi = 5;
	avensis.cena = 100000;
	avensis.terminy[0][0] = "10.03.2018";
	avensis.terminy[1][0] = "10.03.2018";
	avensis.terminy[2][0] = "10.03.2018";

	getchar();
	getchar();
	return 0;
}