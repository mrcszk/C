#include <stdio.h>
/*void wektor(int n, double t1[], double t2[], double t3[]) {
	printf("Wektor 3 = [");
	for (n = 0; n < 3; n++)
		t3[n] = t1[n] + t2[n];
	printf("]");
}*/

	


int main() {
	double t1[3] = {1,2,3};
	double t2[3] = { 2,3,4 };
	double t3[3];
	int n;
	printf("[");
	for (n = 0; n < 3; n++) {
		
		printf("%f ", t1[n]);
	}

	printf("] + ");
	printf("[");
	for (n = 0; n < 3; n++) {

		printf("%f ", t2[n]);
	}

	printf("] = ");
	printf("[");
	for (n = 0; n < 3; n++) {
		t3[n] = t1[n] + t2[n];
		printf("%f ",t3[n]);
	}
		
	printf("]");
	getchar();
	getchar();
	return 0;
}