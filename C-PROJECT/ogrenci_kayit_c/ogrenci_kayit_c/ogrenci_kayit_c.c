#include<stdio.h>

int main()
{
	int no, ort;
	char ad[30];
	FILE* dosya;

	// Dosya yazma modu
	if ((dosya = fopen("ogrKayit.txt", "w")) == NULL)
	{
		printf("Dosya Olusturulamadi.\n");
		return 1;
	}
	else
	{
		printf("Ogrencinin no, ad ve ortalamasini giriniz:\n");
		printf("Cikis icin EOF (CTRL+Z) basiniz.\n");

		// İlk veri girişini yapıyoruz
		while (scanf("%d %s %d", &no, ad, &ort) == 3)  // scanf'in başarılı okuma sayısını kontrol ediyoruz
		{
			fprintf(dosya, "%d\t%s\t%d\n", no, ad, ort);
			printf("\nDevam etmek icin yeni veri giriniz (CTRL+Z ile cikis yapabilirsiniz): ");
		}
		fclose(dosya);
		printf("\nYazma islemi tamamlanmistir, okumaya geciliyor.\n");
	}

	// Dosya okuma modu
	if ((dosya = fopen("ogrKayit.txt", "r")) == NULL)
	{
		printf("Dosya Bulunamadi.\n");
		return 1;
	}
	else
	{
		printf("\nno\tad\tort\n");
		// fscanf'in dönüş değerini kontrol ederek okuma yapıyoruz
		while (fscanf(dosya, "%d\t%s\t%d", &no, ad, &ort) == 3) // Eğer 3 öğe (numara, ad ve ortalama) doğru bir şekilde okunursa, döngü devam eder.
		{
			printf("%d\t%s\t%d\n", no, ad, ort);
		}
		fclose(dosya);
		printf("\nOkuma islemi tamamlandi.\n");
	}

	return 0;
}
