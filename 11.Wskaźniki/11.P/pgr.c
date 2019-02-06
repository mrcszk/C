# include <stdio.h>

int main(){
	int a = 1, b = 2,x;
	int *p = &a, *q = &b;

	x = *p + *q;
	printf("%d", x);

	getchar();
	getchar();
	return 0;
}