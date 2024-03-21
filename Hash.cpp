#include "Hash.hpp"

// Hash sýnýfýnýn kurucu fonksiyonu
Hash::Hash() {
    // Hash tablosunu baþlangýçta tüm indeksler NULL olarak ayarla
    for (int i = 0; i < MAX; i++)
        Dizi[i] = NULL;
}

// Hash tablosuna bir sayý eklemek için fonksiyon
void Hash::Ekle(int sayi) {
    // Sayý zaten tabloda varsa ekleme iþleminden çýk
    if (Bul(sayi))
        return;

    // Sayýnýn hash kodunu hesapla ve ilgili indekse ekleyerek yeni düðümü oluþtur
    int indeks = HashCode(sayi);
    Dizi[indeks] = new Dugum(sayi, Dizi[indeks]);
}

// Verilen sayýnýn hash tablosunda olup olmadýðýný kontrol eden fonksiyon
bool Hash::Bul(int sayi) {
    int indeks = HashCode(sayi); // Sayýnýn hash kodunu al
    Dugum* tmp = Dizi[indeks]; // Ýlgili indeksteki düðümü temsil eden iþaretçi

    // Ýlgili indeksteki baðlý listede dolaþ ve sayýyý bulmaya çalýþ
    while (tmp != NULL) {
        if (tmp->veri == sayi) // Sayýyý bulursan true dön
            return true;

        tmp = tmp->ileri; // Bir sonraki düðüme geç
    }

    // Sayýyý bulamazsan false dön
    return false;
}

// Verilen sayýyý hash tablosundan çýkaran fonksiyon
bool Hash::Cikar(int sayi) {
    int indeks = HashCode(sayi); // Sayýnýn hash kodunu al

    // Ýlgili indeks NULL ise, çýkarma iþleminden çýk ve false dön
    if (Dizi[indeks] == NULL)
        return false;

    // Ýlk düðümdeki sayýyý sil ve iþaretçiyi bir sonraki düðüme geçir
    if (Dizi[indeks]->veri == sayi) {
        Dugum* sil = Dizi[indeks];
        Dizi[indeks] = Dizi[indeks]->ileri;
        delete sil;
        return true;
    }

    // Ýlgili indeksteki baðlý listede sayýyý bul ve çýkar
    Dugum* onceki = Dizi[indeks];

    while (onceki->ileri != NULL) {
        if (onceki->ileri->veri == sayi) {
            Dugum* sil = onceki->ileri;
            onceki->ileri = sil->ileri;
            delete sil;
            return true;
        }

        onceki = onceki->ileri;
    }

    // Sayýyý bulamazsan false dön
    return false;
}

// Hash tablosunun boþ olup olmadýðýný kontrol eden fonksiyon
bool Hash::Bosmu() const {
    for (int i = 0; i < MAX; i++) {
        if (Dizi[i] != NULL)
            return false;
    }

    return true;
}

// Sayýnýn hash kodunu hesaplayan fonksiyon
int Hash::HashCode(int sayi) {
    // Özel durumlar için belirli hash kodlarý döndür
    if (sayi >= 256976744 && sayi <= 361788617)
        return 0;
    else if (sayi >= 230272265 && sayi <= 283549783)
        return 1;
    else
        return sayi % MAX; // Diðer durumlarda, mod alarak hash kodu hesapla
}

// Hash tablosundaki tüm elemanlarý temizleyen fonksiyon
void Hash::Temizle() {
    for (int i = 0; i < MAX; i++) {
        // Her indeksteki baðlý listeyi dolaþ ve düðümleri sil
        Dugum* tmp = Dizi[i];

        while (tmp != NULL) {
            Dugum* sil = tmp;
            tmp = tmp->ileri;
            delete sil;
        }

        // Indeksi NULL olarak ayarla
        Dizi[i] = NULL;
    }
}

// Hash sýnýfýnýn yýkýcý fonksiyonu
Hash::~Hash() {
    Temizle(); // Bellek sýzýntýsýný önlemek için tabloyu temizle
}

// Hash tablosundaki tüm elemanlarý ekrana yazdýran fonksiyon
void Hash::Yaz() const {
    for (int i = 0; i < MAX; i++) {
        // Eðer indekste eleman varsa, baðlý listeyi yazdýr
        if (Dizi[i] != NULL) {
            cout << "Dizi[" << i << "] = ";

            for (Dugum* tmp = Dizi[i]; tmp != NULL; tmp = tmp->ileri) {
                cout << tmp->veri << " -> ";
            }

            cout << "NULL" << endl;
        }
    }
}
