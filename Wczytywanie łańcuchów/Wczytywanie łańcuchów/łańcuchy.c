#pragma warning(disable:4996)
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
char* kop(char* temp ) {
	char *tab = (char*)malloc((strlen(temp) +1) * sizeof(char));
	strcpy(tab, temp);
	return tab;
}
void wczyt(char *temp) {
	scanf(" %s", temp);
}
int main() {
	char temp[50], **slowa;
	int n ,i;
	scanf("%d", &n);
	slowa = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++) {
		wczyt(temp);
		slowa[i] = kop(temp);
	}
	for (i = 0; i < n; i++) {
		printf("%s\n", slowa[i]);
	}
	for (i = 0; i < n; i++) {
		free(slowa[i]);
	}
	free(slowa);

	getchar();
	getchar();
	return 0;
}