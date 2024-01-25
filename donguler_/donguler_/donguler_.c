#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	/*
	while(condition)
	{// kodlar}
	*/

	/*
	do{ 
	//kodlar }
	while(condition)
	*/

	/*
	for(durum1 ;durum2; durum3)}
	{//kodlar}
	*/
	printf("-------------------------------------");
	printf("**Carpim tablosu**\n");
	int sayi, i;
	sayi = 0;
	i = 1;
	printf("1-10 arasi bir sayi giriniz:\n");
	scanf_s("%d", &sayi);

	if (sayi < 1 || sayi>10)
	{
		printf("Duzgun deger gir!\n");
		return 0;
	}
	while (i <= 10)
	{
		printf("%d x %d= %d\n", sayi, i, sayi*i);
		i++;
	}
	printf("-------------------------------------");
	return 0;
}