#include<stdio.h>
#include<stdlib.h>
int main()
{
	//---------------------------------------------------------------------------------------------
	printf("Dairenin alani ve cevresini hesaplama uygulmasi***");
	float r, cevre, alan;
	const float PI = 3.1415; // const=sabit - PI degeri sabitlendi ve ileride degistirilmeye calisildiginda uyari verecek.

	printf("Dairenin yaricapini giriniz:\n");
	scanf_s("%f", &r);

	alan = PI * r * r;
	cevre = 2 * PI * r;

	printf("Dairenin alani: %.2f\n", alan);
	printf("Dairenin cevresi: %.2f\n", cevre);

	//---------------------------------------------------------------------------------------------
	printf("4 adet sayinin kare ve kupunu hesaplama uygulamasi\n");
	float sayi1, sayi2, sayi3,sayi4;

	printf("4 adet sayi giriniz:\n");
	scanf_s("%f %f %f %f", &sayi1, &sayi2, &sayi3, &sayi4);

	printf("Sayi: %f \t",sayi1);
	printf("kupu: %f \t",sayi1* sayi1* sayi1);
	printf("karesi: %f \t\n",sayi1* sayi1);

	printf("Sayi: %f \t", sayi2);
	printf("kupu: %f \t", sayi2 * sayi2 * sayi2);
	printf("karesi: %f \t\n", sayi2 * sayi2);

	printf("Sayi: %f \t", sayi3);
	printf("kupu: %f \t", sayi3 * sayi3 * sayi3);
	printf("karesi: %f \t\n", sayi3 * sayi3);

	printf("Sayi: %f \t", sayi4);
	printf("kupu: %f \t", sayi4 * sayi4 * sayi4);
	printf("karesi: %f \t\n", sayi4 * sayi4);
	printf("\n\n");

	//---------------------------------------------------------------------------------------------
}
