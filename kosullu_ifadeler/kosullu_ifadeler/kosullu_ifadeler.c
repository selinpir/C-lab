#include<stdio.h>
#include<stdlib.h>
int main()
{
	//---------------------------------------------------
	//if
	printf("---------------------------------------------------\n");
	int sayim1, sayim2;
	sayim1 = 19;
	sayim2 = 2;
	if (sayim1 > sayim2)
	{
		printf("%d daha buyuktur %d den \n", sayim1, sayim2);
	}

	//---------------------------------------------------
	printf("---------------------------------------------------\n");
	printf("Kitap Siparis Uygulamasi\n\n");
	int kitapFiyati, siparisSayisi;
	float indirimOrani, indirimsizFiyat,indirimliFiyat,toplam;

	kitapFiyati = 20; //sabit fiyat
	siparisSayisi = 0;

	printf("kac adet kitap siparis etmek istiyorsunuz ?\n");
	scanf_s("%d",&siparisSayisi);
	if (siparisSayisi>=60)
	{
		indirimOrani = 0.30;		
	}
	else {
		if (siparisSayisi >= 30 && siparisSayisi < 60)
		{
			indirimOrani = 0.20;
		}
		else if (siparisSayisi >= 10 && siparisSayisi < 30)
		{
			indirimOrani = 0.12;
		}
		else {
			indirimOrani = 0.01;
		}
	}
	indirimsizFiyat = siparisSayisi * kitapFiyati;
	printf("Kitabin indirimsiz fiyati: %.2f TL \n", indirimsizFiyat);
	indirimliFiyat = siparisSayisi * kitapFiyati * indirimOrani;
	toplam = indirimsizFiyat - indirimliFiyat;
	printf("Siparisinizin Toplam Tutari : %.2f TL \n", toplam);
	//---------------------------------------------------

	printf("---------------------------------------------------\n");
	printf("TBMM Toplanti Uygulamasi\n\n");
	int partiA, partiB, partiC, mevcutMilletvekili;
	const int toplamMilletvekili = 600;

	printf("Meclisdeki partilerin Millet Vekili sayilarini giriniz:\n");
	scanf_s("%d %d %d", &partiA, &partiB, &partiC);

	mevcutMilletvekili = partiA + partiB + partiC;
	if (mevcutMilletvekili < 200)
	{
		printf("Toplanti yeter sayisina ulasilamadigindan toplantiya ara verildi\n");
		printf("Toplanti yeter sayisi 200'dur.\n");

	}
	else
	{
		printf("Meclis Toplantiya Hazir\n");
	}

	//---------------------------------------------------
	printf("---------------------------------------------------\n");
	printf("Kullanicidan alinan sayilarin en kucugunu ve en buyugunu bulan uygulama\n\n");

	int say1, say2, say3,max,min;
	printf("Uc sayi giriniz:");
	scanf_s("%d %d %d", &say1, &say2, &say3);

	if (say1 > say2 && say1 > say3)
	{
		max = say1;
	}
	else if (say2 > say1 && say2 > say3)
	{
		max = say2;
	}
	else
	{
		max = say3;
	}
	printf("max sayi: %d\n", max);

		if (say1 < say2 && say1 < say3)
		{
			min = say1;
		}
		else if (say2 < say1 && say2 < say3)
		{
			min = say2;
		}
		else
		{
			min = say3;
		}
		printf("min sayi: %d\n", min);

	//---------------------------------------------------
	printf("---------------------------------------------------\n");
	printf("Kenar uzunluklarina gore ucgenin turunu bulma uygulamasi\n");
	
	int a, b, c; //kenarlar
	printf("kenar uzunluklarini giriniz:");
	scanf_s("%d %d %d", &a, &b, &c);
		
	int uzunKenar;
	
	if (a > b && a > c)  uzunKenar = 'a';	
	else if (b > a && b > c)	{		uzunKenar = 'b';	}
	else	{		uzunKenar = 'c';	}

	if (uzunKenar == 'a')
	{
		if (a * a == b * b + c * c) 		printf("Dik acili ucgen\n");
		else if(a*a>b*b+c*c)				printf("Genis acili ucgen\n");
		else                      printf("Girilen kenarlar ucgen olusturmaz !\n");
	}
	else if (uzunKenar == 'b')
	{
		if (b * b == a * a + c * c) 		printf("Dik acili ucgen\n");
		else if (b * b > a * a + c * c)		printf("Genis acili ucgen\n");
		else                      printf("Girilen kenarlar ucgen olusturmaz !\n");
	}
	else
	{
		if (c * c == a * a + b * b) 		printf("Dik acili ucgen\n");
		else if (c * c > a * a + b * b)		printf("Genis acili ucgen\n");
		else                      printf("Girilen kenarlar ucgen olusturmaz !\n");
	}

	return 0;

}