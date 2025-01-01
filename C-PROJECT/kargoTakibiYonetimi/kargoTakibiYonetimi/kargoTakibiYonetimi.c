#include <stdio.h>
#include <string.h>
#include <stdlib.h> // exit fonksiyonu icin
#define MAX_KARGO 1000 // max kargo girisini 1000 e sabitledim 

//struct kullanimi-kargo yapisi-----------------------------------------------------------------------------------------------------------
struct Kargo {
    int kargoID;// kargonun IDsi diger islemlerde kolaylik olmasi acisindan elle giriliyor ama otomatik arttirma veya rand() kullanabilirdim
    char gonderici[100]; // leda kargo ile kargo gonderen isletme 
    char alici[100]; // isletmeden siparis veren-kullanici
    char adres[200]; // kargo teslim adresi
    float kg; //kargo agirligi
    float mesafe; //ucret hesaplanmasi icin nereden nereye
    float ucret;
    char durum[20]; //kargonun durumu
};

//Diziler ve degiskenler -----------------------------------------------------------------------------------------------------------------
struct Kargo kargolar[MAX_KARGO];
int kargoSayisi = 0;

char durumlar[][20] = { "Yolda", "Dagitima Cikarilmis" }; // durumlar dizisi

struct SehirMesafe {
    char sehirler[50];
    float mesafe;
    float ucret;
};

struct SehirMesafe mesafeUcretTablosu[] = { 
    {"Istanbul - Ankara", 450.0, 45.0},
    {"Istanbul - Izmir", 480.0, 48.0},
    {"Ankara - Izmir", 580.0, 58.0},
    {"Ankara - Antalya", 480.0, 48.0},      
    {"Izmir - Denizli", 460.0, 46.0},
    {"Istanbul - Denizli", 720.0, 72.0}
};

// Fonksiyon prototipleri-----------------------------------------------------------------------------------------------------------------
void kargoGirisi(struct Kargo kargolar[], int* kargoSayisi);
void kargoGuncelle(struct Kargo kargolar[], int kargoSayisi);
void kargoCikisi(struct Kargo kargolar[], int kargoSayisi);
void kargoTakip(struct Kargo kargolar[], int kargoSayisi);
void ucretHesaplama(struct Kargo* k);
void personelMenu();
void kullaniciMenu();
void kullaniciTipi();
void mesafeSecimi(struct Kargo* k);

// kargo girisi alt fonksiyonlari
int idKontrol(struct Kargo kargolar[], int kargoSayisi, struct Kargo* yeniKargo);
void idAl(struct Kargo kargolar[], int kargoSayisi, struct Kargo* yeniKargo);
void gondericiAdiAl(struct Kargo* yeniKargo);
void aliciAdiAl(struct Kargo* yeniKargo);
void adresAl(struct Kargo* yeniKargo);
void agirlikAl(struct Kargo* yeniKargo);

//-----ID KONTROL-------------------------------------------------------------------------------------------------------------------------
int idKontrol(struct Kargo kargolar[], int kargoSayisi, struct Kargo* yeniKargo) {
    int idMevcut = 0;
    for (int i = 0; i < kargoSayisi; i++) {// Mevcut ID kontrolu
        if (kargolar[i].kargoID == yeniKargo->kargoID) {
            idMevcut = 1;
            printf("Bu ID zaten mevcut. Lutfen farkli bir ID giriniz.\n");
            break;
        }
    }
    return idMevcut;
}
//-----ID GIRISI-------------------------------------------------------------------------------------------------------------------------
void idAl(struct Kargo kargolar[], int kargoSayisi, struct Kargo* yeniKargo) {
    do {
        printf("ID giriniz: ");
        if (scanf_s("%d", &yeniKargo->kargoID) != 1) {
            printf("Lutfen sayisal deger girerek tekrar deneyiniz.\n");
            while (getchar() != '\n');  // Hatali girisi temizler
        }
        else {
            // ID'nin gecerli ve benzersiz olup olmadigini kontrol et
            if (yeniKargo->kargoID > 0 && idKontrol(kargolar, kargoSayisi, yeniKargo) == 0) {
                break;  
            }
            else {
                printf("ID 0'dan buyuk olmali ve mevcut olmamalidir. Tekrar deneyiniz.\n");
            }
        }
    } while (1);
}
//-----GONDERİCİ ADI ALMA FONKSIYONU-----------------------------------------------------------------------------------------------------
void gondericiAdiAl(struct Kargo* yeniKargo) {
    do {
        printf("Gonderici adini giriniz: ");
        getchar();
        fgets(yeniKargo->gonderici, sizeof(yeniKargo->gonderici), stdin);
        yeniKargo->gonderici[strcspn(yeniKargo->gonderici, "\n")] = 0;
        if (strlen(yeniKargo->gonderici) == 0) {
            printf("Gonderici adi bos olamaz. Lutfen tekrar giriniz.\n");
        }
    } while (strlen(yeniKargo->gonderici) == 0);
}
//-----ALICI ADI ALMA FONKSIYONU---------------------------------------------------------------------------------------------------------
void aliciAdiAl(struct Kargo* yeniKargo) {
    do {
        printf("Alici adini giriniz: ");
        fgets(yeniKargo->alici, sizeof(yeniKargo->alici), stdin);
        yeniKargo->alici[strcspn(yeniKargo->alici, "\n")] = 0;
        if (strlen(yeniKargo->alici) == 0) {
            printf("Alici adi bos olamaz. Lutfen tekrar giriniz.\n");
        }
    } while (strlen(yeniKargo->alici) == 0);
}
//-----ADRES ALMA FONKSIYONU-------------------------------------------------------------------------------------------------------------
void adresAl(struct Kargo* yeniKargo) {
    do {
        printf("Adres giriniz: ");
        fgets(yeniKargo->adres, sizeof(yeniKargo->adres), stdin);
        yeniKargo->adres[strcspn(yeniKargo->adres, "\n")] = 0;
        if (strlen(yeniKargo->adres) == 0) { // boş değer girildiyse 
            printf("Adres bos olamaz. Lutfen tekrar giriniz.\n");
        }
    } while (strlen(yeniKargo->adres) == 0); // strlen uzunluk bulur
}
//-----AGIRLIK ALMA FONKSIYONU-----------------------------------------------------------------------------------------------------------
void agirlikAl(struct Kargo* yeniKargo) {
    do {
        printf("Agirligi (kg) giriniz: ");
        if (scanf_s("%f", &yeniKargo->kg) != 1 || yeniKargo->kg <= 0) {
            printf("Gecersiz agirlik girdisi. Lutfen tekrar deneyiniz.\n");
            while (getchar() != '\n');
            yeniKargo->kg = -1;
        }
    } while (yeniKargo->kg <= 0);
}
// Kargo girisi fonksiyonu----------------------------------------------------------------------------------------------------------------
void kargoGirisi(struct Kargo kargolar[], int* kargoSayisi) {
    if (*kargoSayisi >= MAX_KARGO) {
        printf("Maksimum kargo sayisina ulasildi. Daha fazla ekleme yapamazsiniz.\n");
        return;
    }
    struct Kargo yeniKargo;
    idAl(kargolar, *kargoSayisi, &yeniKargo); 
    gondericiAdiAl(&yeniKargo);
    aliciAdiAl(&yeniKargo);
    adresAl(&yeniKargo);
    agirlikAl(&yeniKargo);
    mesafeSecimi(&yeniKargo);

    strcpy_s(yeniKargo.durum, sizeof(yeniKargo.durum), "Depoda");// Durum

    ucretHesaplama(&yeniKargo);

    // Kargo bilgilerini kaydediyoruz
    kargolar[*kargoSayisi] = yeniKargo;
    (*kargoSayisi)++;

    // Kargo bilgilerini ekrana yazdiriyoruz
    printf("\n\n---Kargo Bilgileri:---\n");
    printf("Kargo ID: %d\n", yeniKargo.kargoID);
    printf("Gonderici: %s\n", yeniKargo.gonderici);
    printf("Alici: %s\n", yeniKargo.alici);
    printf("Adres: %s\n", yeniKargo.adres);
    printf("Agirlik (kg): %.2f\n", yeniKargo.kg);
    printf("Mesafe (km): %.2f\n", yeniKargo.mesafe);
    printf("Durum: %s\n", yeniKargo.durum);
    printf("Toplam Ucret: %.2f TL\n", yeniKargo.ucret);
    printf("\n---------------------------\n");
}
// Kargo guncelle fonksiyonu------------------------------------------------------------------------------------------------------------
void kargoGuncelle(struct Kargo kargolar[], int kargoSayisi) {
    if (kargoSayisi == 0) {
        printf("Henuz eklenmis bir kargo bulunmamaktadir.\n");
        return;
    }
    int id, bulundu = 0; 
    printf("\n\nGuncellenecek kargo ID'sini giriniz: ");
    while (getchar() != '\n'); 
    if (scanf_s("%d", &id) != 1) {
        printf("Hata: Gecerli bir sayisal ID giriniz.\n");
        while (getchar() != '\n'); 
        return;
    }
        // Kargo dizisini kontrol et
    for (int i = 0; i < kargoSayisi; i++) {
        if (kargolar[i].kargoID == id) { 
            bulundu = 1; 
            // Durum secimi
            int durumSecim;
            printf("\nKargo durumu seciniz:\n");
            printf("0: Yolda\n");
            printf("1: Dagitima cikarilmis\n");
            printf("Seciminizi yapiniz (0-1): ");
            if (scanf_s("%d", &durumSecim) != 1 || (durumSecim != 0 && durumSecim != 1)) {
                printf("Gecersiz secim. Kargo durumu 'Depoda' olarak ayarlandi.\n");
                strcpy_s(kargolar[i].durum, sizeof(kargolar[i].durum), "Depoda");
            }
            else {
                if (durumSecim == 0) { //0 = yolda
                    strcpy_s(kargolar[i].durum, sizeof(kargolar[i].durum), "Yolda");
                    printf("Kargo durumu 'Yolda' olarak guncellendi. Kargo ID: %d\n", id);
                }
                else if (durumSecim == 1) { //1 = dagıtıma cıkarildi
                    strcpy_s(kargolar[i].durum, sizeof(kargolar[i].durum), "Dagitima cikarilmis");
                    printf("Kargo durumu 'Dagitima cikarilmis' olarak guncellendi. Kargo ID: %d\n", id);
                }
            }
            return; 
        }
    }
    if (!bulundu) { 
        printf("\n\nGirdiginiz ID ile eslesen kargo bulunamadi.\n");
    }
}
//Kargo cikisi fonksiyonu----------------------------------------------------------------------------------------------------------------
void kargoCikisi(struct Kargo kargolar[], int kargoSayisi) {
    if (kargoSayisi == 0) {
        printf("Henuz eklenmis bir kargo bulunmamaktadir.\n");
        return;
    }
    int id, bulundu = 0; 

    printf("\n\nTeslim edilmis kargo ID'sini giriniz: ");
    while (getchar() != '\n'); 
    if (scanf_s("%d", &id) != 1) {
        printf("Hata: Gecerli bir sayisal ID giriniz.\n");
        while (getchar() != '\n');
        return;
    }
    for (int i = 0; i < kargoSayisi; i++) {
        if (kargolar[i].kargoID == id) { 
            bulundu = 1; 
            strcpy_s(kargolar[i].durum, sizeof(kargolar[i].durum), "Teslim Edilmis"); //hedef adres, hedef dizinin boyutu,kopyalanacak olan dize
            printf("\n\nKargo teslim edilmistir, kargo cikisi basarili. Kargo ID: %d\n", id);
            return;
        }
    }
    if (!bulundu) {
        printf("\n\nGirdiginiz ID ile eslesen kargo bulunamadi.\n");
    }
}
// Kullanici Kargo Takip Fonksiyonu------------------------------------------------------------------------------------------------------
void kargoTakip(struct Kargo kargolar[], int kargoSayisi) {
    if (kargoSayisi == 0) { 
        printf("\nHenuz kayitli bir kargo bulunmamaktadir.\n");
        return;
    }
    int id;
    printf("\nTakip etmek icin kargo ID'sini giriniz:\n ");

    if (scanf_s("%d", &id) != 1) {
        printf("Hata: Gecerli bir ID giriniz.\n");
        return;
    }
    
    for (int i = 0; i < kargoSayisi; i++) {
        if (kargolar[i].kargoID == id) {
            printf("\n--- Kargo Bilgileri ---\n");
            printf("Kargo ID: %d\n", kargolar[i].kargoID);
            printf("Durum: %s\n", kargolar[i].durum);
            printf("------------------------\n");
            return;
        }
    }
    
    printf("\nGirdiginiz ID (%d) ile eslesen kargo bulunamadi.\n", id);
}
//Mesafe secim fonksiyonu----------------------------------------------------------------------------------------------------------------
void mesafeSecimi(struct Kargo* k) {
    int secim;
    // Mesafe secim tablosu
    printf("\n\nMesafeyi hesaplamak icin asagidaki sehir ciftlerinden birini secin:\n");
    for (int i = 0; i < sizeof(mesafeUcretTablosu) / sizeof(mesafeUcretTablosu[0]); i++) { //sizeof(mesafeUcretTablosu) / sizeof(mesafeUcretTablosu[0] : dizinin eleman sayısını bulur
        printf("%d. %s (%.1f km, %.2f TL)\n", i + 1, mesafeUcretTablosu[i].sehirler, mesafeUcretTablosu[i].mesafe, mesafeUcretTablosu[i].ucret);
    }
    printf("0. Mesafeyi manuel olarak girmek istiyorum.\n");
    do {
        printf("Seciminizi yapiniz (0-%d): ", sizeof(mesafeUcretTablosu) / sizeof(mesafeUcretTablosu[0]));
        if (scanf_s("%d", &secim) != 1 || secim < 0 || secim > sizeof(mesafeUcretTablosu) / sizeof(mesafeUcretTablosu[0])) {
            printf("\n\nGecersiz secim! Lutfen tekrar deneyin.\n");
            while (getchar() != '\n'); 
            secim = -1;
        }
    } while (secim < 0 || secim > sizeof(mesafeUcretTablosu) / sizeof(mesafeUcretTablosu[0]));

    if (secim > 0) {
        k->mesafe = mesafeUcretTablosu[secim - 1].mesafe;
        printf("\nSecilen sehirler: %s\n", mesafeUcretTablosu[secim - 1].sehirler);
    }
    else if (secim == 0) {
        do {
            printf("\nMesafeyi (km) manuel olarak giriniz: ");
            if (scanf_s("%f", &k->mesafe) != 1 || k->mesafe <= 0) {
                printf("Gecersiz mesafe girdisi. Lutfen tekrar deneyiniz.\n");
                while (getchar() != '\n'); 
                k->mesafe = -1; 
            }
        } while (k->mesafe <= 0);
    }

    printf("\nHesaplanan mesafe: %.1f km\n", k->mesafe);
}
//Ucret hesaplama fonksiyonu----------------------------------------------------------------------------------------------------
void ucretHesaplama(struct Kargo* k) { // k Kargo yapısının bellek adresini tutar.
    k->ucret = 0;

    // ucret hesaplama
    if (k->kg > 0 && k->kg <= 10) { // 0-10 kg arasındaki kargolar için 115 TL
        k->ucret += 115.00;
    }
    else if (k->kg <= 30) { // 11-30 kg arasındaki kargolar için 190 TL
        k->ucret += 190.00;
    }
    else if (k->kg <= 50) { // 31-50 kg arasındaki kargolar için 310 TL
        k->ucret += 310.00;
    }
    else {  // 50 kg ve üzeri kargolar için 460 TL
        k->ucret += 460.00;
    }
    // Mesafe ücret hesaplama: Her 100 km için 10 TL
    k->ucret += (k->mesafe / 100) * 10;
    // ucret bilgisi
    printf("\nUcret Hesaplama:\n");
    printf("Agirlik (kg): %.2f\n", k->kg);
    printf("Mesafe (km): %.2f\n", k->mesafe);
    printf("Toplam ucret: %.2f TL\n", k->ucret);
}
// Personel icin menu, kargo girisi-guncellemesi-cikisi yapilabiliyor.-------------------------------------------------------------------
void personelMenu() {
    int secim;
    do {
        printf("\nPersonel Menu:\n");
        printf("1. Kargo Girisi\n");
        printf("2. Kargo Guncelle\n");
        printf("3. Kargo Cikisi\n");
        printf("0. Ana menuye don\n");

        printf("Seciminizi yapiniz: ");
        scanf_s("%d", &secim);

        switch (secim) {
        case 1:
            kargoGirisi(kargolar, &kargoSayisi); //
            break;
        case 2:
            kargoGuncelle(kargolar, kargoSayisi);
            break;
        case 3:
            kargoCikisi(kargolar, kargoSayisi);
            break;
        case 0:
            printf("Donuluyor...\n");
            break;
        default:
            printf("Gecersiz secim!\n");
        }
    } while (secim != 0);
}
//Kullanici icin menu, kargo takip ve cikis islemleri gerceklestirilebiliyor sadece.----------------------------------------------------
void kullaniciMenu() {
    int secim;
    do {
        printf("\n---Kullanici Menu:---\n");
        printf("1. Kargo Takip\n");
        printf("2. Cik\n");
        printf("0. Ana menuye don\n");

        printf("Seciminizi yapiniz: ");
        scanf_s("%d", &secim);

        switch (secim) {
        case 1:
            kargoTakip(kargolar, kargoSayisi);
            break;
        case 2:
            printf("Cikiliyor...\n");
            exit(0);
            break;
        case 0:
            printf("Donuluyor...\n");
            break;
        default:
            printf("Gecersiz secim!\n");
        }
    } while (secim != 0);
}
//kullanicinin tip secimi-----------------------------------------------------------------------------------------------------------------
void kullaniciTipi() {
    int secim;
    do {
        printf("\n---Kullanici Tipinizi Seciniz:---\n");
        printf("1. Personel\n");
        printf("2. Kullanici\n");
        printf("0. Cikis\n");

        printf("Seciminizi yapiniz: ");
        scanf_s("%d", &secim);

        switch (secim) {
        case 1:
            personelMenu();
            break;
        case 2:
            kullaniciMenu();
            break;
        case 0:
            printf("Cikis yapiliyor...\n");
            break;
        default:
            printf("Gecersiz secim!\n");
        }
    } while (secim != 0);
}
//Programin baslangic noktasi, kullanicinin tip secimi ile baslar.----------------------------------------------------------------------
int main() {
    printf("\t\t**************************************\n");
    printf("\t\t*       Leda Kargo Takip Sistemi     *\n");
    printf("\t\t*           Hosgeldiniz!             *\n");
    printf("\t\t**************************************\n\n");
    kullaniciTipi();
    return 0;
}
//--------------------------------------------------------------&SON&--------------------------------------------------------------------