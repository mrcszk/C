#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {
	char maska = 0x20;
	char a[20];
	int i;
	printf("Podaj wyraz: ");
	scanf("%s", &a);
	for (i = 0; i < strlen(a); i++)
		a[i] ^= maska;
	printf("%s\n", a);
	for (i=0;i<strlen(a);i++)
	a[i] = a[i] & ~maska;
	printf("%s\n", a);
	for (i = 0; i < strlen(a); i++)
		a[i] = a[i] | maska;
	printf("%s\n", a);
	getchar();
	getchar();
	return 0;
}