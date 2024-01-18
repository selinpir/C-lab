#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	// Karakter Dizisi Harf Yok Etme
	/*
	char dizi[100];
	char eleme;
	char* selin;

	printf("Karakter dizisi giriniz:");
	gets(dizi);
	printf("Karakter dizisinden cikarilacak karakter nedir?");
	scanf("%c", &eleme);

	for (selin = dizi; *selin; selin++)
	{
		if (*selin == eleme)
		{
			strcpy(selin, selin + 1);
		}
	}
	printf("eleme yapildiktan sonraki durum: %s", dizi);
	*/

	// Pointer ve Karakter Dizisi
	/*
	int dizi[15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	int* pointer;
	int i;

	printf("Dizinin ilk hali: \n");
	for (i = 0; i < 15; i++)
	{
		printf("%4d", *(dizi + i));
		
	}	
	printf("\nCift sayilar: \n");
	for (i=0;i<15;i+=2)
	{
		printf("%4d",*(dizi+i));
	}
*/

	//Pointerla Haftanýn Günleri
   /*	
   char *gün[7] = { "pazartesi","sali","carsamba","persembe","cuma","cumartesi","pazar" };
	int i;

	do
	{
		printf("1 ile 7 arasi deger giriniz : \n");
		scanf("%d", &i);
	} 
	while (i<=0 || i>7);

	printf(" %d girdiginiz degere gore haftanin gunu %s", i, gün[i - 1]);

	return 0;
	*/
}