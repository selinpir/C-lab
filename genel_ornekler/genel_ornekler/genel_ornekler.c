#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {

	/*	printf("--------------------1--------------------------\n");
	printf("Girilen sayi ozel sayi mi ? (ozel sayi= [abcd=(ab+cd)^2]\n");
	printf("Bir sayi giriniz: \n");
	int sayi, yenisayi, durum1, durum2;
	scanf_s("%d", &sayi);
	durum1 = sayi/100; //ab
	durum2 = sayi % 100; //cd
	yenisayi = (durum1 + durum2) * (durum1 + durum2);
	if(yenisayi==sayi)
	{
		printf("sayiniz ozel sayidir. :) \n");
	}
	else {
		printf("sayiniz ozel sayi degildir. :( \n");
	}

	printf("--------------------2--------------------------\n");
	printf("Girilen sayinin karekokunun tam sayi olup olmadigini bulma:\n");
	int sayi1, karekok;
	printf("Bir sayi giriniz: \n");
	scanf_s("%d", &sayi1);
	if (sayi1 < 0)
	{
		printf("Pozitif deger giriniz:\n");
	}

	else {
		karekok = sqrt(sayi1);
		if(karekok*karekok==sayi1)		
		{
			printf("karekoktur: %d \n", karekok);
		}

		else 
		{ 
			printf("degildir.\n"); 
		}
	}

	printf("--------------------3--------------------------\n");
	printf("GSM operatoru konusma ucreti hesaplama\n");
	float konusmaSuresi, ucret;

	printf("Konusma surenizi giriniz:\n");
	scanf_s("%f", &konusmaSuresi);
	
	if (konusmaSuresi <= 4.0)
	{
		ucret = 1;
	}
	else 
	{
		ucret = 1 + (konusmaSuresi - 4) * 0.07;
	}
	printf("Toplam odenecek ucretiniz: %.2f TL\n", ucret);*/

	/*	printf("--------------------4--------------------------\n");
	printf("Ucgen Acisiyla Turunu Bulma:\n");
	printf("Lutfen ucgenin ic acilarini giriniz:\n");
	int aciA, aciB, aciC;
	scanf_s("%d %d %d", &aciA, &aciB, &aciC);
	if (aciA + aciB + aciC != 180)
	{
		printf("Bu acilar ucgen olusturmamaktadir.\n");

	}
	else {
		if(aciA==60 && aciB==60 && aciC==60)
		{
			printf("Bu ucgen eskenar ucgendir.\n");
		}
		else if (aciA == aciB || aciA == aciC || aciB == aciC)
		{
			printf("Bu ucgen ikizkenar ucgendir.\n");
		}
		else {
			printf("Bu ucgen cesitkenar ucgendir.\n");
		}
	}*/

	

	return 0;

}