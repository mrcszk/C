#include <stdio.h>

void multiply(int A[][3], int B[][3], int C[][3])
{
	int i, j, k;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				C[i][j] += (A[i][k] * B[k][j]);
			}
		}
	}
}

int main()
{
	int A[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int B[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int C[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

	multiply(A, B, C);

	int i, j, k;
	for (j = 0; j <3; j++)
	{
		for (k = 0; k <3; k++)
		{
			if (k == 2)
				printf("%3d \n", C[j][k]);
			else
				printf("%3d ", C[j][k]);
		}
	}

	getchar();
	getchar();
	return 0;
}

