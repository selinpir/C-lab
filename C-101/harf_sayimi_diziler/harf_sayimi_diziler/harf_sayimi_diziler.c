#include<stdio.h>
#include<stdlib.h>
void karakterSay(char x[], int y[]);
int main()
{
	//ingiliz alfabesi ile (26)
	char x[100];
	int y[26], i = 0;
	printf("Cumle Giriniz: \n");
	do
	{
		scanf_s("%c", &x[i]);
		i++;

	} while (x[i - 1] != '.'); //[i-1] Enter dahil olmasin diye kullanildi.
	karakterSay(x, y);

	for (i = 0; i < 26; i++)
	{
		printf("%c / %c: %d\n", 'A' + i, 'a' + i, y[i]); // buyuk / kucuk sayimi

	}
	return 0;
}
void karakterSay(char x[], int y[])
{
	int i, j;
	for (i = 0; i < 26; i++)
	{
		y[i] = 0;
	}
	for (i = 0; x[i] != '.'; i++)
	{
		if (x[i] >= 'A' && x[i] <= 'Z')
			y[(int)x[i] - (int)'A']++; //char integere donusturuldu 

		if (x[i] >= 'a' && x[i] <= 'z')
			y[(int)x[i] - (int)'a']++; //char integere donusturuldu 
	}
}

