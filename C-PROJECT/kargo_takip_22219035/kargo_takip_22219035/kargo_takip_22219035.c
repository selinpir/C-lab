#include <stdio.h>
#include <string.h>

// Kargo yapisi
struct Kargo {
    int kargoID;
    char gonderici[100];
    char alici[100];
    char adres[200];
    float kg;
    float mesafe;
    float ucret;
    char durum[20];
};

// Fonksiyon prototipleri -> derleyici,fonksiyonları kullanmadan önce onların nasıl kullanılacağını bilmeli
void kargoGirisi(struct Kargo* k);
void kargoCikisi(struct Kargo* k);
void kargoTakip(struct Kargo* k);
void ucretHesaplama(struct Kargo* k);
void personelMenu();
void kullaniciMenu();
void kullaniciTipi();
void mesafeSecimi(struct Kargo* k);
void dosyayaKargoYaz(struct Kargo* k);
void dosyadanKargoSil(int id);
void dosyadanKargoOku(int id, struct Kargo* k);

// Mevcut Kargo ID'lerini dosyadan kontrol eden fonksiyon
int kargoIDMevcutMu(int id) {
    FILE* dosya;
    fopen_s(&dosya, "kargolar.txt", "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi!\n");
        return 0;
    }

    char satir[512];
    while (fgets(satir, sizeof(satir), dosya)) {
        int mevcutID;
        sscanf_s(satir, "%d", &mevcutID);
        if (mevcutID == id) {
            fclose(dosya);
            return 1;  // ID mevcut
        }
    }
    fclose(dosya);
    return 0;  // ID mevcut değil
}

// Kargo girisi fonksiyonu
void kargoGirisi(struct Kargo* k) {
    int idGiris;
    do {
        printf("Kargo ID giriniz: ");
        scanf_s("%d", &idGiris);

        // Kargo ID'sinin mevcut olup olmadığını kontrol et
        if (kargoIDMevcutMu(idGiris)) {
            printf("Bu Kargo ID'si zaten mevcut! Lutfen farkli bir ID giriniz.\n");
        }
        else {
            k->kargoID = idGiris;
            break;  // ID mevcut değilse, işlemi sonlandır
        }
    } while (1);  // ID geçerli olana kadar tekrar et

    printf("Gonderici adini giriniz: ");
    getchar();  // önceki satırdan kalan '\n' karakterini temizler
    fgets(k->gonderici, sizeof(k->gonderici), stdin);
    k->gonderici[strcspn(k->gonderici, "\n")] = 0;

    printf("Alici adini giriniz: ");
    fgets(k->alici, sizeof(k->alici), stdin);
    k->alici[strcspn(k->alici, "\n")] = 0;

    printf("Adres giriniz: ");
    fgets(k->adres, sizeof(k->adres), stdin);
    k->adres[strcspn(k->adres, "\n")] = 0;

    printf("Agirligi (kg) giriniz: ");
    scanf_s("%f", &k->kg);

    mesafeSecimi(k);

    printf("Durumu giriniz (Depoda, Yolda): ");
    getchar();
    fgets(k->durum, sizeof(k->durum), stdin);
    k->durum[strcspn(k->durum, "\n")] = 0;

    // ucreti sifirla
    k->ucret = 0;

    // Ucret hesaplamasını burada yapıyoruz
    ucretHesaplama(k);

    dosyayaKargoYaz(k);

    printf("\n\n\n\n---Kargo Bilgileri:---\n");
    printf("Kargo ID: %d\n", k->kargoID);
    printf("Gonderici: %s\n", k->gonderici);
    printf("Alici: %s\n", k->alici);
    printf("Adres: %s\n", k->adres);
    printf("Agirlik (kg): %.2f\n", k->kg);
    printf("Mesafe (km): %.2f\n", k->mesafe);
    printf("Durum: %s\n", k->durum);
    printf("Toplam Ucret: %.2f TL\n", k->ucret);
    printf("\n---------------------------\n");
}

void mesafeSecimi(struct Kargo* k) {
    int secim;
    printf("\n\nMesafeyi hesaplamak icin asagidaki sehir ciftlerinden birini secin:\n");
    printf("1. Istanbul - Ankara (450 km)\n");
    printf("2. Istanbul - Izmir (480 km)\n");
    printf("3. Ankara - Izmir (580 km)\n");
    printf("4. Ankara - Antalya (480 km)\n");
    printf("5. Izmir - Denizli (460 km)\n");
    printf("6. Istanbul - Denizli (720 km)\n");
    printf("0. Mesafeyi manuel olarak girmek istiyorum.\n");

    printf("Seciminizi yapiniz (0-6): ");
    scanf_s("%d", &secim);

    switch (secim) {
    case 1:
        k->mesafe = 450.0;
        printf("\nSecilen sehirler: Istanbul - Ankara\n");
        break;
    case 2:
        k->mesafe = 480.0;
        printf("\nSecilen sehirler: Istanbul - Izmir\n");
        break;
    case 3:
        k->mesafe = 580.0;
        printf("\nSecilen sehirler: Ankara - Izmir\n");
        break;
    case 4:
        k->mesafe = 480.0;
        printf("\nSecilen sehirler: Ankara - Antalya\n");
        break;
    case 5:
        k->mesafe = 460.0;
        printf("\nSecilen sehirler: Izmir - Antalya\n");
        break;
    case 6:
        k->mesafe = 720.0;
        printf("\nSecilen sehirler: Istanbul - Antalya\n");
        break;
    case 0:
        printf("\nMesafeyi (km) manuel olarak giriniz: ");
        scanf_s("%f", &k->mesafe);
        break;
    default:
        printf("\n\nGecersiz secim! Lutfen tekrar deneyin.\n");
        k->mesafe = 0; // Hata durumunda mesafeyi sıfırla
        break;
    }
    if (k->mesafe > 0) {
        printf("\n\nHesaplanan mesafe: %.1f km\n", k->mesafe);
    }
}

void dosyayaKargoYaz(struct Kargo* k) {
    FILE* dosya;
    fopen_s(&dosya, "kargolar.txt", "a"); //"a" (append) modu dosyanın sonuna ekleme yapmak için
    if (dosya == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }
    fprintf(dosya, "%d,%s,%s,%s,%.2f,%.2f,%.2f,%s\n", k->kargoID, k->gonderici, k->alici, k->adres, k->kg, k->mesafe, k->ucret, k->durum);
    fclose(dosya);
}

void dosyadanKargoOku(int id, struct Kargo* k) {
    FILE* dosya;
    fopen_s(&dosya, "kargolar.txt", "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }
    char satir[512]; //char satir[512];512 karakterlik bir karakter dizisi oluşturur
    while (fgets(satir, sizeof(satir), dosya)) {
        int mevcutID; //sscanf_s daha güvenli
        sscanf_s(satir, "%d,%99[^,],%99[^,],%199[^,],%f,%f,%f,%19[^\n]", &mevcutID, k->gonderici, sizeof(k->gonderici), k->alici, sizeof(k->alici), k->adres, sizeof(k->adres), &k->kg, &k->mesafe, &k->ucret, k->durum, sizeof(k->durum));
        if (mevcutID == id) {
            k->kargoID = mevcutID;
            fclose(dosya);
            return;
        }
    }
    printf("\n\nID'si %d olan bir kargo bulunamadi!\n", id);
    fclose(dosya);
}

void dosyadanKargoSil(int id) {
    FILE* dosya, * gecici;
    fopen_s(&dosya, "kargolar.txt", "r");
    fopen_s(&gecici, "gecici.txt", "w");
    if (dosya == NULL || gecici == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }

    char satir[512];
    while (fgets(satir, sizeof(satir), dosya)) {
        int mevcutID;
        sscanf_s(satir, "%d", &mevcutID);
        if (mevcutID != id) {
            fputs(satir, gecici);
        }
    }
    fclose(dosya);
    fclose(gecici);
    remove("kargolar.txt");
    rename("gecici.txt", "kargolar.txt");
    printf("Kargo ID'si %d silindi.\n", id);
}

// Kargo cikis fonksiyonu
void kargoCikisi(struct Kargo* k) {
    int id;
    printf("\n\nCikisi yapilacak kargo ID'sini giriniz: ");
    scanf_s("%d", &id);

    // Kargo ID'sinin mevcut olup olmadığını kontrol et
    if (kargoIDMevcutMu(id) == 0) {
        printf("Kargo bulunamadi! Bu kargo ID'sine sahip bir kargo bulunmuyor.\n");
        return;  // Kargo bulunamadıysa fonksiyonu sonlandır
    }

    dosyadanKargoOku(id, k);  // Kargo bilgilerini dosyadan oku

    if (k->kargoID != 0) {
        printf("Kargo ID: %d\n", k->kargoID);
        printf("Gonderici: %s\n", k->gonderici);
        printf("Alici: %s\n", k->alici);
        printf("Adres: %s\n", k->adres);
        printf("Agirlik: %.2f kg\n", k->kg);
        printf("Mesafe: %.2f km\n", k->mesafe);
        printf("Durum: %s\n", k->durum);

        printf("\n\nKargo cikisi yapiliyor...\n");
        strcpy_s(k->durum, sizeof(k->durum), "Cikmis");
        dosyayaKargoYaz(k);

        dosyadanKargoSil(id);

        printf("\n\nKargo cikisi basarili.\n");
    }
}

void kargoTakip(struct Kargo* k) {
    int id;
    printf("\nTakip etmek icin kargo ID'sini giriniz:\n ");
    scanf_s("%d", &id);

    // ID'nin mevcut olup olmadığını kontrol et
    if (kargoIDMevcutMu(id) == 0) {
        printf("Kargo bulunamadi!\n");  // Kargo bulunamadı mesajını yazdır
        return;  // Fonksiyonu sonlandır
    }

    dosyadanKargoOku(id, k);  // Kargo bilgilerini dosyadan oku

    // Kargo bilgilerini yazdır
    printf("Kargo ID: %d\n", k->kargoID);
    printf("Gonderici: %s\n", k->gonderici);
    printf("Alici: %s\n", k->alici);
    printf("Adres: %s\n", k->adres);
    printf("Agirlik: %.2f kg\n", k->kg);
    printf("Mesafe: %.2f km\n", k->mesafe);
    printf("Durum: %s\n", k->durum);
}


// Ucret hesaplama fonksiyonu
void ucretHesaplama(struct Kargo* k) {
    // Ucreti sifirdan hesapla
    k->ucret = 0;

    // Agirlikla ilgili ücret hesaplama
    if (k->kg <= 0) {
        printf("Gecersiz agirlik girdisi.\n");
        return;
    }
    if (k->kg > 0 && k->kg <= 10) {
        k->ucret += 115.00;
    }
    else if (k->kg <= 30) {
        k->ucret += 190.00;
    }
    else if (k->kg <= 50) {
        k->ucret += 310.00;
    }
    else {
        k->ucret += 460.00;
    }

    // Mesafeye gore ücret hesaplama
    if (k->mesafe < 0) {
        printf("Gecersiz mesafe girdisi.\n");
        return;
    }
    k->ucret += (k->mesafe / 100) * 10;

    // Hesaplanan ucreti yazdir
    printf("\nUcret Hesaplama:\n");
    printf("Agirlik (kg): %.2f\n", k->kg);
    printf("Mesafe (km): %.2f\n", k->mesafe);
    printf("Toplam ucret: %.2f TL\n", k->ucret);
}

// Personel menu fonksiyonu
void personelMenu() {
    int secim;
    struct Kargo kargo;
    do {
        printf("\nPersonel Menu:\n");
        printf("1. Kargo Girisi\n");
        printf("2. Kargo Cikisi\n");
        printf("0. Ana menuye don\n");

        printf("Seciminizi yapiniz: ");
        scanf_s("%d", &secim);

        switch (secim) {
        case 1:
            kargoGirisi(&kargo);
            break;
        case 2:
            kargoCikisi(&kargo);
            break;
        case 0:
            printf("Donuluyor...\n");
            break;
        default:
            printf("Gecersiz secim!\n");
        }
    } while (secim != 0);
}

// Kullanici menu fonksiyonu
void kullaniciMenu() {
    int secim;
    struct Kargo kargo;
    do {
        printf("\n---Kullanici Menu:---\n");
        printf("1. Kargo Takip\n");
        printf("0. Ana menuye don\n");

        printf("Seciminizi yapiniz: ");
        scanf_s("%d", &secim);

        switch (secim) {
        case 1:
            kargoTakip(&kargo);
            break;
        case 0:
            printf("Donuluyor...\n");
            break;
        default:
            printf("Gecersiz secim!\n");
        }
    } while (secim != 0);
}

// Kullanici tipi secimi fonksiyonu
void kullaniciTipi() {
    int secim;
    do {
        printf("\n\n\nKullanici tipi seciniz:\n");
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

int main() {
    printf("-----------------------------Leda Kargo-------------------------------------------\n");
    printf("----------------------------Hos geldiniz------------------------------------------\n");
    printf("---------------------------7/24  Dagitim------------------------------------------\n");

    kullaniciTipi();
    return 0;
}

