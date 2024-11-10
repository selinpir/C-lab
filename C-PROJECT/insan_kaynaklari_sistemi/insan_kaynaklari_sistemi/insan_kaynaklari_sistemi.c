#include<stdio.h>
#include <string.h>
#define max 20 // calisan sayisini max 20 ye sabitledik


struct calisan {
	char ad[20];
	int kod; // calisanin id
	char is[20];
	int deneyim;
	int yas;
};

struct calisan cal[20];
int sayi;

void index_sil(int i)
{
	int j;
	for (j = i; j < (sayi - 1); j++) {
		strcpy(cal[j].ad, cal[j + 1].ad);
		cal[j].kod = cal[j + 1].kod;
		strcpy(cal[j].is, cal[j + 1].is);
		cal[j].deneyim = cal[j + 1].deneyim;
		cal[j].yas = cal[j + 1].yas;
	}
	return;
}

void calisan_sil() {
	int kod, i;
	printf("Calisani silmek icin calisan id giriniz:\n");
	scanf_s("%d", &kod);
	for (i = 0; i < sayi; i++) {
		if (cal[i].kod == kod) {
			index_sil(i); // silinen elemanın yerine bi sonraki eleman gelir
			sayi--;
			printf("Bsarili bir sekilde silinmistir.");
			break;
		}
	}
	showMenu();
}

void toplam_calisan() {
	printf("Calisan sayisi: %d\n\n", sayi);
	showMenu();
}

void cal_bilgi() {
	int kod,i;
	printf("Calisan bilgilerine ulasmak icin calisan id giriniz:\n");
	scanf_s("%d",&kod);
	for(i=0;i<sayi;i++){
		if (cal[i].kod == kod) {
			printf("AD: %s\n",cal[i].ad,19);
			printf("CALISAN ID: %d\n", cal[i].kod);
			printf("IS: %s\n", cal[i].is,19);
			printf("DENEYIM: %d\n", cal[i].deneyim);
			printf("YAS: %d\n", cal[i].yas);
			break;
		}
	}
	showMenu();
}

void ekle() 
{
	if (sayi < max) {
		printf("AD:");
		scanf_s("%s", &cal[sayi].ad, 19);

		printf("CALISAN ID:");
		scanf_s("%d", &cal[sayi].kod);

		printf("IS:");
		scanf_s("%s", &cal[sayi].is, 19);

		printf("DENEYIM:");
		scanf_s("%d", &cal[sayi].deneyim);

		printf("YAS:");
		scanf_s("%d", &cal[sayi].yas);
		sayi++;
	}
	else {
		printf(" max calisan sayisini astiniz!");
	}
	showMenu();
}


void olustur() {
	int i;
	printf("-maks calisan sayisi: %d\n",max);	
	printf("-lutfen calisan sayisini giriniz:\n");
	scanf_s("%d", &sayi);
	
	if(sayi>20){
		printf("Maksimum calisan sayisini astiniz.\nMaks calisan sayisi: %d\n", max);
		sayi = max;
	}


	printf("lutfen calisan bilgilerini giriniz:\n\n");
	for (i = 0; i < sayi; i++) {
		// hata almamak için scanf_s("%s", name); -> scanf_s("%s", name,39); You will need to specify size when using %s specifier in scanf_s .
		printf("%d .inci calisan bilgilerini giriniz:\n",i+1);
		printf("AD:");
		scanf_s("%s", &cal[i].ad,19);

		printf("CALISAN ID:");
		scanf_s("%d", &cal[i].kod);

		printf("IS:\n");
		scanf_s("%s", &cal[i].is,19);

		printf("DENEYIM:");
		scanf_s("%d", &cal[i].deneyim);

		printf("YAS:");
		scanf_s("%d", &cal[i].yas);
	}
	showMenu();
}


int showMenu() {
	int secim;

	printf("| insan kaynaklari sistemi |\n\n");
	printf("islem seciniz\n");

	printf("Calisan tablosunu olusturunuz(1)\n");
	printf("Yeni calisan ekleyiniz(2)\n"); 
	printf("Calisan siliniz(3)\n");
	printf("Calisan bilgilerini getiriniz(4)\n");
	printf("Calisan sayisini gosteriniz(5)\n");
	printf("Cikis yapiniz(6)\n");
	scanf_s("%d", &secim);

	if (secim == 1) {
		olustur();
	}
	else if (secim == 2) {
		ekle();
	}
	else if (secim == 3) {
		calisan_sil();		
	}
	else if (secim == 4) {
		cal_bilgi();
	}
	else if (secim == 5) {
		toplam_calisan();
	}
	else if (secim == 6) {
		return;
	}
	else {
		printf("Yanlis bir secim yaptiniz!\n");
	}
	showMenu();
}
void main()
{
	showMenu();
	return 0;
}