#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void menu();
int minU(int, int);
int maxU(int, int);
int kare(int);
int kup(int);
int mutlak(int);

int main() {
	int secim = 0;
	int x, y;
	menu();
	printf("secim yapiniz:\n");
	scanf_s("%d", &secim);
	switch (secim)
	{
	case 1:
		printf("iki deger giriniz:\n");
		scanf_s("%d %d ", &x, &y);
		printf("min %d\n", minU(x, y));
		break;
	case 2:	
		printf("iki deger giriniz:\n");
		scanf_s("%d %d ", &x, &y);
		printf("max %d\n", maxU(x, y));
		break;
	case 3:
		printf("bir deger giriniz:\n");
		scanf_s("%d", &x);
		printf("Karesi %d\n", kare(x));
		break;
	case 4:
		printf("bir deger giriniz:\n");
		scanf_s("%d", &x);
		printf("kupu %d\n", kup(x));
		break;
	case 5:
		printf("bir deger giriniz:\n");
		scanf_s("%d", &x);
		printf("mutlak deger %d\n", mutlak(x));
		break;
	
	default:printf("bir deger giriniz:\n");
	}
	return 0;
}

void menu() {
	printf("\n");
	printf("*MENU*\n");
	printf("1-MINIMUM\n");
    printf("2-MAXIMUM\n");
	printf("3-KARE AL\n");
	printf("4-KUP AL\n");
	printf("5-MUTLAK DEGER HESAPLA\n");


}

int minU(int x, int y)
{
	if(x<y)	{		return x;	}
	else { return y; }
}
int maxU(int x, int y)
{
	if (x > y) { return x; }
	else { return y; }
}
int kare(int x)
{
	return x * x;
}
int kup(int x)
{
	return x*x*x;
}
int mutlak(int x)
{
	if (x < 0) { return x * (-1); }
	else { return x; }
}