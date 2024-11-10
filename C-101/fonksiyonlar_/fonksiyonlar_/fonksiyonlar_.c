#include<stdio.h>

void mesajim() 
{
	printf("fOnkSiyOnlAr xd\n");
}

void isimListesi(char isim[],int yas[]) {
	printf("merhaba %s, yasiniz :%d\n", isim,yas);
}

void tumsayilar(int sayilarim[6]) {
	for (int i=0;i<6;i++)
	{
		printf("%d\n", sayilarim[i]);
	}
}

//	printf("Recursion(ozyinelemeli) Fonksiyonlar\n");
int sayiToplam(int i);

int main()
{
	printf("-----------------------------------\n");
	printf("--void geriye return ile deger dondurmeyecegimizde kullanilir.--\n");
	mesajim();
	printf("-----------------------------------\n");
	isimListesi("selin",22);
	isimListesi("evrim",43);
	isimListesi("kivilcim",34);
	printf("-----------------------------------\n");
	int sayilarim[6] = { 10,20,30,40,50,60 };
	tumsayilar(sayilarim);

	printf("-----------------------------------\n");
	printf("Recursion(ozyinelemeli) Fonksiyonlar\n");
	int sonuc = sayiToplam(5);
	printf("%d\n", sonuc);
	return 0;
	
}
//	printf("Recursion(ozyinelemeli) Fonksiyonlar\n");
int sayiToplam(int i) {
	if (i > 0)
	{
		return i + sayiToplam(i - 1);
	}
	else {
		return 0;
	}
}