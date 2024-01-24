#include<stdio.h>
#include<stdlib.h>

int main() {

	printf("Elektrik Faturasi Hesaplama Uygulamasi\n");

	float odenecekFatura, eskiBirimFiyat, yeniBirimFiyat;
	float enflasyon, eskiAboneUcreti, yeniAboneUcreti;
	int yeniOkuma, eskiOkuma, toplamHarcananElektrik;

	printf("Enflasyon oranini giriniz:");
	scanf_s("%f", &enflasyon);

	printf("Onceki aya ait birim miktari giriniz:");
	scanf_s("%f", &eskiBirimFiyat);

	printf("Onceki aya ait abonelik ucretini giriniz:");
	scanf_s("%f", &eskiAboneUcreti);

	printf("Bir onceki aya ait okuma degerini giriniz:");
	scanf_s("%d", &eskiOkuma);

	printf("Bu aya ait okuma degerini giriniz:");
	scanf_s("%d", &yeniOkuma);

	toplamHarcananElektrik = yeniOkuma - eskiOkuma; //harcanan elektrigi buluruz
	yeniBirimFiyat = eskiBirimFiyat*(1+enflasyon/100);
	yeniAboneUcreti = eskiAboneUcreti * (1 + enflasyon / 100);

	odenecekFatura = toplamHarcananElektrik * yeniBirimFiyat + yeniAboneUcreti;

	printf("\nOdeyeceginiz fatura tutari: %f: \n\n", odenecekFatura);
}