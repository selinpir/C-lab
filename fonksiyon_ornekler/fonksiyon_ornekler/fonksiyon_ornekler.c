#include<stdio.h>
#include<stdlib.h>
//----------------------------------
int faktoriyel(int sayi)
{
	int i;
	int sonuc = 1;

	for (i = 1; i <= sayi; i++)
	{
		sonuc = sonuc * i;
	}
	return sonuc;
}
//----------------------------------
int us(int taban, int us)
{
	int i;
	int sonuc = 1;
	for (i = 1; i <= us; i++)
	{
		sonuc = taban * sonuc;
	}
	return sonuc;
}
//----------------------------------
int mukemmel(int n)
{
	int i=1;
	int toplam=0;
	while (i < n)
	{
		if (n % i == 0)
		{
			toplam = toplam + i;
		}
		i++;
	}
	if(toplam==n)
	{
		return 1;
	}
	else {
		return 0;
	}
}

//----------------------------------
int main()
{
	//----------------------------------
	printf("\n-------------------------------------\n");
	printf("Tamsayinin faktoriyelini fonksiyon kullanarak hesaplama:\n");
	int sayi;
	printf("lutfen bir sayi giriniz:\n");
	scanf_s("%d", &sayi);
	printf("%d!= %d", sayi, faktoriyel(sayi));

	//----------------------------------
	printf("\n-------------------------------------\n");
	printf("Fonksiyon kullanarak taban ve us bulma:\n");
	printf("Taban ve us degerlerinizi giriniz:\n");
	int a, b;
	scanf_s("%d %d", &a, &b);
	printf("%d ^ %d=%d", a, b, us(a, b));

	//----------------------------------
	printf("\n-------------------------------------\n");
	printf("Fonksiyon yardimiyla mukemmel sayi bulmak:\n");
	int sayim;
	int sonuc;
	printf("lutfen bir sayi giriniz:");
	scanf_s("%d", &sayim);
	sonuc = mukemmel(sayim);
	
	if (sonuc == 1)
	{
		printf("Sayi mukemmel sayidir");
	}
	else
	{
		printf("Sayi mukemmel sayi degildir.");
	}
	printf("\n-------------------------------------\n");
	//----------------------------------
	return 0;
}