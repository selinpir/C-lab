#include<stdio.h>
#include<stdlib.h>

int main()
{
	int no, bakiye, secim;
	char ad[30];
	FILE* dosya;

	// Dosyayı okuma modunda açıyoruz
	if ((dosya = fopen("musteriler.txt", "r")) == NULL) // "r" okuma modu
	{
		printf("Dosya bulunamadi.\n");
		return 1; // Eğer dosya açılamazsa programdan çık
	}

	while (1)
	{
		printf("\nBanka Bilgileri Uygulamasi\n");
		printf("1-Hesabinda para olan musteriler\n");
		printf("2-Hesabinda para olmayan musteriler\n");
		printf("3-Borcu olan musteriler\n");
		printf("4-Cikis\n");

		printf("Seciminizi girin: ");
		scanf("%d", &secim);

		switch (secim)
		{
		case 1:
			printf("\nHesabinda para olan musteriler:\n");
			rewind(dosya); // Dosya başına dön
			while (fscanf(dosya, "%d\t%s\t%d", &no, ad, &bakiye) == 3)
			{
				if (bakiye > 0)
					printf("%d\t%s\t%d\n", no, ad, bakiye);
			}
			break;

		case 2:
			printf("\nHesabinda para olmayan musteriler:\n");
			rewind(dosya); // Dosya başına dön
			while (fscanf(dosya, "%d\t%s\t%d", &no, ad, &bakiye) == 3)
			{
				if (bakiye == 0)
					printf("%d\t%s\t%d\n", no, ad, bakiye);
			}
			break;

		case 3:
			printf("\nBorcu olan musteriler:\n");
			rewind(dosya); // Dosya başına dön
			while (fscanf(dosya, "%d\t%s\t%d", &no, ad, &bakiye) == 3)
			{
				if (bakiye < 0)
					printf("%d\t%s\t%d\n", no, ad, bakiye);
			}
			break;

		case 4:
			printf("Cikis Yaptiniz ... \n");
			fclose(dosya); // Dosyayı kapat
			return 0;

		default:
			printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
		}
	}
	return 0;
}
