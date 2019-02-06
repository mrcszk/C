# include <stdio.h>
int ten[30];
int a, b;

void miesiac() {
	int month[11] = { 31,59,90,120,151,181,212,243,273,304,334 };
	int i;
	for (i = 1; i <= 31; i++) {
		ten[i] = i;
	}
	switch (a) {
	case 1:
		printf("Jest to %d dzien roku.", ten[b]);
		break;
	case 2:
		printf("Jest to %d dzien roku.", month[0] + ten[b]);
		break;
	case 3:
		printf("Jest to %d dzien roku.", month[1] + ten[b]);
		break;
	case 4:
		printf("Jest to %d dzien roku.", month[2] + ten[b]);
		break;
	case 5:
		printf("Jest to %d dzien roku.", month[3] + ten[b]);
		break;
	case 6:
		printf("Jest to %d dzien roku.", month[4] + ten[b]);
		break;
	case 7:
		printf("Jest to %d dzien roku.", month[5] + ten[b]);
		break;
	case 8:
		printf("Jest to %d dzien roku.", month[6] + ten[b]);
		break;
	case 9:
		printf("Jest to %d dzien roku.", month[7] + ten[b]);
		break;
	case 10:
		printf("Jest to %d dzien roku.", month[8] + ten[b]);
		break;
	case 11:
		printf("Jest to %d dzien roku.", month[9] + ten[b]);
		break;
	case 12:
		printf("Jest to %d dzien roku.", month[10] + ten[b]);
		break;
	default:
		printf("Taki miesiac nie istnieje.");
		break;
	}
}

int main(void) {
	printf("Podaj numer miesiaca: ");
	scanf_s("%d", &a);
	printf("Podaj dzien miesiaca: ");
	scanf_s("%d", &b);
	if (b > 31 || (b > 29 && a == 2) || (b > 30 && (a == 4 || a == 6 || a == 9 || a == 11)))
		printf("Taki dzien tego miesiaca nie istnieje!");
	else
		miesiac();
	
	getchar();
	getchar();
	return 0;
}