#include<stdio.h>

int main()
{
	//switch-case
	printf("------------------------------\n");
	printf("switch-case uygulamasi\n");
	int ayNumarasi;
	printf("Ay sayisi giriniz:\n");
	scanf_s("%d", &ayNumarasi);
	switch (ayNumarasi)
	{
	case 4:
	case 6:
	case 9:
	case 11: printf("Bu ayda 30 gun vardir.\n");
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: printf("Bu ayda 31 gun vardir.\n");
		break;
	case 2: printf("Bu ayda 28 veya 29 gun vardir.\n");
		break;
	default: printf("Boyle bir ay yok.\n");
	}

}