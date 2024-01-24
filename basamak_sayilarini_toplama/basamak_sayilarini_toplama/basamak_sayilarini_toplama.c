#include<stdio.h>
int main()
{

	printf("Girilen Sayinin Rakamlarini Toplayan Uygulama\n");
	int sayim, bolum, kalan, toplam;
	toplam = 0;

	printf("4 basamakli sayi giriniz\n");
	scanf_s("%d", &sayim);
	 //4. basamak bulunur
	bolum = sayim / 1000;
	toplam += bolum;
	kalan = sayim % 1000;

	//3. basamak bulunur
	bolum = kalan / 100;
	toplam += bolum;
	kalan = kalan % 100;

	//2. basamak bulunur
	bolum = kalan / 10;
	toplam += bolum;
	kalan = kalan % 10;

	//1. basamak bulunur
	toplam += kalan;
	printf("Girdiginiz sayinin rakamlar toplami : %d\n",toplam);

}
