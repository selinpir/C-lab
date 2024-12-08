#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    // Yıldız Kullanarak Yarım Piramit Oluşturma
    int i, j;

    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }


    //Sayı Kullanarak Yarım Piramit Oluşturma
    int i, j;

    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }


    // Alfabe Piramidi Oluşturma
    int i, j;
    char start = 'A', input;

    printf("Lutfen yarim piramidi sonlandirmak istediginiz karakteri giriniz\n");
    scanf("%c", &input);
    printf("\n");

    for (i = 1; i <= (input - 'A' + 1); i++) {
        for (j = 1; j <= i; j++) {
            printf("%c ", start);
        }
        start++;
        printf("\n");
    }

    //  * Kullanarak Ters Yarım Piramit Oluşturma
    int i, j;

    for (i = 5; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    //Sayı Kullanarak Ters Yarım Piramit Oluşturma
    int i, j;

    for (i = 5; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    // * Kullanarak Tam Piramit Oluşturma
    int satir, i, k, bosluk;

    printf("Lutfen satir sayisini giriniz\n");
    scanf("%d", &satir);

    for (i = 1, k = 0; i <= satir; i++, k = 0) {
        for (bosluk = 1; bosluk <= satir - i; bosluk++) {
            printf("  ");
        }
        while (k != 2 * i - 1) {
            printf("* ");
            k++;
        }
        printf("\n");

    }


    //   Floyd Üçgeni Oluşturma


    int i, j, satir, sayi = 1;

    printf("Lutfen satir sayisini giriniz\n");
    scanf("%d", &satir);

    for (i = 1; i <= satir; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", sayi);
            sayi++;
        }
        printf("\n");
    }


    return 0;
}