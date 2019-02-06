#pragma warning(disable:4996)
# include <stdio.h>

int main() {
	char t[5][20];

	fgets(t[0], 20, stdin);
	fgets(t[1], 20, stdin);
	fgets(t[2], 20, stdin);
	fgets(t[3], 20, stdin);
	fgets(t[4], 20, stdin);
	printf("%s\n", t[0]);
	printf("%s\n", t[1]);
	printf("%s\n", t[2]);
	printf("%s\n", t[3]);
	printf("%s\n", t[4]);
	getchar();
	getchar();
	return 0;
}