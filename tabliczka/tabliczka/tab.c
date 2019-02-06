#pragma warning(disable:4996)
# include <stdio.h>
//# include <stdlib.h>

int main(void) {
	int **tab ,n,i,j;
	scanf(" %d", &n);
	tab = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		tab[i]=(int*)malloc((i+1) * sizeof(int));
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < i + 1; j++) {
			tab[i][j] = (i + 1)*(j + 1);
		}
	}
	scanf(" %d %d", &i, &j);
	if (i > j) 
		printf("%d", tab[i - 1][j - 1]);
	else
		printf("%d", tab[j - 1][i - 1]);
	for (i = 0; i < n; i++)
		free(tab[i]);
	free(tab);
	getchar();
	getchar();
	return 0;
}