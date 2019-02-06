#pragma warning(disable:4996)
/*#include <stdio.h>
#include <string.h>

int main() {
	char znaki[1][20];
	int i = 0, k = 0, o = 0, z, dl;
	int l[10] = { 0,0,0,0,0,0,0,0,0,0 };
	printf("Podaj znaki: ");
	fgets(znaki[0], 20, stdin);
	printf("znaki: %d\n", strlen(znaki[0]) - 1);
	dl = strlen(znaki[0]);
	
	for (i; i < dl; i++) {
		for (k; k < dl; k++)
		{
			if (znaki[0][i] == znaki[0][k]) {
				l[k] ++;
			}

		}
	}
z= l[0];
	for (i = 1; i <= dl; i++) {
		
		if (z <= l[i])
			z = l[i];
	}
	if (z == 0) {
		printf("Nie ma takiego znaku.%d", l[z]);
		getchar();
		getchar();
		return 1;
	}
	
	printf("Najwiekszy znak:%c, %d,%d", znaki[0][z],l[z],z);

	getchar();
	getchar();
	return 0;
}*/
#include <stdio.h>
#include <string.h>

/* To tylko dla ułatwienia. Wartość ta raczej nie ulegnie zmianie */


int main(void)
{
	unsigned char tab[10],c;
	int i, histogram[256],a,z,d;

	printf("Podaj znaki: ");
	scanf("%s", &tab);


	//memset(histogram, 0, 256); /* To samo co pętla zerująca, ale krótsze, szybsze itp. */
	for (i = 0; i < 256; i++)
		histogram[i] = 0;
	for (i = 0; i < strlen(tab); i++)
	{
		a = tab[i];
		histogram[a] += 1;
	}

	for (i = 0; i < 256; i++) {
		if (histogram[i] >0)
			printf("Znak %c powtorzyl sie %d razy\n", i, histogram[i]);
	}

	z = histogram[0];
	for (int i = 1; i < 256; i++) {
		
		if (z <= histogram[i]) {
			d = z;
			z = histogram[i];
			c = i;
		}
	}
	if (z == d) {
		printf("Nie ma najczesciej powtarzajacego sie znaku.");
	}
	else
	printf("Najczestszy znak to: %c", c);
	getchar();
	getchar();
	return 0;
}