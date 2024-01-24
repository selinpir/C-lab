#include<stdio.h>
int main()
{
	//----------------------------------------------------------------------------------------------
	// dizideki(array) eleman sayisini bulma   
	printf("dizideki eleman sayisini bulma\n");

	printf("uyg-1\n");
	int sayi[] = { 1,2,3,4,5,6,7,8,9 };
	printf("%d\n", sizeof(sayi)); //9*4=36 gelir kapladigi alan
	printf("%d\n", sizeof(sayi[0])); // 4 byte
	printf("%d\n", sizeof(sayi) / sizeof(sayi[0]));//tum alanı tek alana bolersek kaç eleman oldugunu buluruz.

	printf("uyg-2\n");
	int sayi2[] = { 1,2,3,4,5,6,7,8,9,35,345,56,67,578,78,1234,345,1234,34,456,567,789,0,989,24,67,80,23,567,80,234,35,7879,3,42,34,35,65,7,68,7,9,7,9,6,3,423 };
	printf("%d\n", sizeof(sayi2) / sizeof(sayi2[0]));
	//----------------------------------------------------------------------------------------------

	//COK BOYUTLU DIZILER***
	printf("COK BOYUTLU DIZILER***\n");
	int matrix[2][3] = { {2,7,19},
						{3,8,12}
	};
	printf("gosterim-1\n");
	printf("%d ", matrix[0][0]);
	printf("%d ", matrix[0][1]);
	printf("%d\n", matrix[0][2]);
	printf("%d ", matrix[0][0]);
	printf("%d ", matrix[1][1]);
	printf("%d\n", matrix[1][2]);

	printf("gosterim-2\n");
	int i, j;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%3d", matrix[i][j]);
		}
		printf("\n\n");
	}
	//---------------------------------------------------------------------------------------------- 



	return 0;
}