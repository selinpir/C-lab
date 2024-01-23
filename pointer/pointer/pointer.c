#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
		//1  Karakter Dizisi Harf Yok Etme
		/*
		char dizi[100];
		char eleme;
		char* selin;

		printf("Karakter dizisi giriniz:");
		gets(dizi);
		printf("Karakter dizisinden cikarilacak karakter nedir?");
		scanf("%c", &eleme);

		for (selin = dizi; *selin; selin++)
		{
			if (*selin == eleme)
			{
				strcpy(selin, selin + 1);
			}
		}
		printf("eleme yapildiktan sonraki durum: %s", dizi);
		*/

		//2 Pointer ve Karakter Dizisi
		/*
		int dizi[15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
		int* pointer;
		int i;

		printf("Dizinin ilk hali: \n");
		for (i = 0; i < 15; i++)
		{
			printf("%4d", *(dizi + i));

		}
		printf("\nCift sayilar: \n");
		for (i=0;i<15;i+=2)
		{
			printf("%4d",*(dizi+i));
		}
	*/

		//3 Pointerla Haftanýn Günleri
		/*
		char *gün[7] = { "pazartesi","sali","carsamba","persembe","cuma","cumartesi","pazar" };
		 int i;

		 do
		 {
			 printf("1 ile 7 arasi deger giriniz : \n");
			 scanf("%d", &i);
		 }
		 while (i<=0 || i>7);

		 printf(" %d girdiginiz degere gore haftanin gunu %s", i, gün[i - 1]);

		 return 0;
		 */

		//4
		/*int a = 10, b, c;
		 int* d = &a;
		 printf("\n\nTemel pointer tanimlama :\n");

		 printf(" a, b, ve c birer int tamsayi ve a = 10");
		 // d bir pointer ve %p ile pointer adresini yazdiriyoruz
		 printf("\n\n d ise bir tam sayi pointer'i ve a'nin adresini tutuyor: %p\n", d);
		 printf("\n *d ile a'nin degerine ulasiyoruz a = %i\n", *d);
		 printf("\n &a ile a'nin pointer adresine ulasiyoruz a = %p\n", &a);
		 printf("\n &b ile b'nin pointer adresine ulasiyoruz : %p\n", &b);
		 printf("\n &c  ile c'nin pointer adresine ulasiyoruz : %p\n", &c);
		 printf("\n &d ile d'nin pointer adresine ulasiyoruz : %p\n\n", &d);*/

		//5
		/*	int* ab;
		 int m;
		 m = 17;

		 printf("\n\n Pointer kullanimi:\n");
		 printf(" ab = int pointer'i, int m = 17\n\n");

		 printf(" m'nin adresi : %p\n", &m);
		 printf(" m'nin degeri : %d\n\n", m);

		 ab = &m;

		 printf(" m'nin adresi ab'ye atandi.\n");
		 printf(" ab'nin adresi : %p\n", ab);
		 printf(" ab'nin icerigi : %d\n\n", *ab);

		 m = 35;

		 printf(" m'ye 35 degeri atandi.\n");
		 printf(" ab'nin adresi : %p\n", ab);
		 printf(" ab'nin icerigi : %d\n\n", *ab);

		 *ab = 8;

		 printf(" ab'nin isaret ettigi degiskenin degeri 8 olarak atandi.\n");
		 printf(" m'nin adresi: %p\n", &m);//ab m'nin adresini icerdigi icin
		 //m 'nin degeri 8 olarak degisti
		 printf(" m'nin degeri : %d\n\n", m);
		 return 0;*/

		//6
		/*int m = 200;
			 float fx = 200.60;
			 char cht = 'z';

			 printf("\n\n & (Adresi) ve * (adresteki deger) operatorunun kullanimi :\n");

			 int* pt1;
			 float* pt2;
			 char* pt3;
			 pt1 = &m;
			 pt2 = &fx;
			 pt3 = &cht;

			 printf(" m = %d\n", m);
			 printf(" fx = %f\n", fx);
			 printf(" cht = %c\n", cht);
			 printf("\n &(uzun adres verir) operator kullanimi :\n");
			 printf("-----------------------\n");
			 printf(" m'nin adresi= %p\n", &m);
			 printf(" fx'in adresi = %p\n", &fx);
			 printf(" cht'nin adresi = %p\n", &cht);
			 printf("\n & ve * operator kullanimi :\n");
			 printf("-----------------------------\n");
			 printf(" m'nin adresindeki deger = %d\n", *(&m));//200
			 printf(" fx'in adresindeki deger = %f\n", *(&fx));// 200.600006
			 printf(" cht'nin adresindeki deger = %c\n", *(&cht));//z
			 printf("\n Sadece pointer kullanimi(* yok) :\n");
			 printf("----------------------------------\n");
			 printf(" m'nin adresi = %p\n", pt1);
			 printf(" fx'in adresi = %p\n", pt2);
			 printf(" cht'nin adresi = %p\n", pt3);
			 printf("\n Sadece ***pointer operatorunun kullanimi :\n");
			 printf("----------------------------------\n");
			 printf(" m'nin adresindeki deger = %d\n", *pt1); //200
			 printf(" fx'in adresindeki deger = %f\n", *pt2);// 200.600006
			 printf(" cht'nin adresindeki deger = %c\n\n", *pt3); //z*/

		//7
		/*int ilksayi, ikincisayi, *ptr, *qtr, topla;

		 printf("\n\n iki sayiyi toplama :\n");
		 printf("--------------------------------\n");

		 printf(" ilk sayiyi giriniz : ");
		 scanf("%d", &ilksayi);
		 printf(" ikinci sayiyi giriniz : ");
		 scanf("%d", &ikincisayi);

		 ptr = &ilksayi;
		 qtr = &ikincisayi;

		 topla = *ptr + *qtr;

		 printf(" Girilen sayilarin toplami : %d\n\n", topla);

		 return 0;
		 */

		//8
		/*long iki_sayi_ekle(long*, long*);
				 long ilksayi, ikincisayi, toplam;

				 printf("\n\n call by reference kullanarak iki sayi toplama:\n");
				 printf("-------------------------------------------------------\n");

				 printf(" ilk sayiyi giriniz : ");
				 scanf("%ld", &ilksayi);
				 printf(" ikinci sayiyi giriniz : ");
				 scanf("%ld", &ikincisayi);
				 toplam = iki_sayi_ekle(&ilksayi, &ikincisayi);
				 printf(" %ld ve %ld sayilarinin toplami: %ld\n\n", ilksayi, ikincisayi, toplam);
				 return 0;
			 }
			 long iki_sayi_ekle(long* no1, long* no2)
			 {
				 long toplam;

				 return toplam;
					 toplam = *no1 + *no2;
			 }*/

		//9
		/*	int firstno, secondno, *ptr1 = &firstno, *ptr2 = &secondno;

	printf("\n\n iki sayidan en buyugunu bulunuz :\n");
	printf("------------------------------------------------------------\n");

	printf(" ilk sayiyi giriniz : ");
	scanf("%d", ptr1);
	printf(" ikinci sayiyi giriniz : ");
	scanf("%d", ptr2);


	if (*ptr1 > *ptr2)
	{
		printf("\n\n en buyuk sayi: %d \n\n", *ptr1);
	}
	else
	{
		printf("\n\n en buyuk sayi: %d \n\n", *ptr2);
	}*/

		//10
		/*int arr1[25], i, n;
		printf("\n\n n elemanli bir array'i doldur ve elemanlarini yazdir :\n");
		printf("------------------------------------------------------------\n");
		printf(" Doldurulacak sayi miktarini giriniz :");
		scanf("%d", &n);

		printf(" %d adet sayi giriniz \n", n);
		for (i = 0; i < n; i++)
		{
			printf(" eleman - %d : ", i);
			scanf("%d", arr1 + i);
		}
		printf(" Girilen elemanlar : \n");

		for (i = 0; i < n; i++)
		{
			printf(" eleman - %d : %d \n", i, *(arr1 + i));
		}
		return 0;*/

		//11
		/*char alph[27];
		int x;
		char* ptr;
		printf("\n\n Alfabeyi yazdir:\n");
		printf("----------------------------------------\n");
		ptr = alph;

		for (x = 0; x < 26; x++)
		{
			*ptr = x + 'A';
			ptr++;
		}
		ptr = alph;

		printf(" Harfler : \n");
		for (x = 0; x < 26; x++)
		{
			printf(" %c ", *ptr);
			ptr++;
		}
		printf("\n\n");
		return(0);*/
		
		//12 
		/*int x[5] = { 1, 2, 3, 4, 5 };
		int* ptr;

		ptr = &x[2];
		printf("*ptr = %d \n", *ptr);   // 3
		printf("*ptr+1 = %d \n", *ptr + 1); // 4
		printf("*ptr-1 = %d", *ptr - 1);  // 2
		return 0;*/

		//13






}

      





