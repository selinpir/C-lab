#include<stdio.h>

void floyd(int n)
{
	int i = 1;
	int j ;
	int a=1;

	while (i <= n)
	{
		j = 1;
		while (j <= i)
		{
			printf("%4d", a);
			a++;
			j++;
		}

		printf("\n");
		i++;
	}
}

int main()
{
	int satir;
	printf("floyd ucgeni icin satir sayisini giriniz: ");
	scanf_s("%d", &satir);
	floyd(satir);

}