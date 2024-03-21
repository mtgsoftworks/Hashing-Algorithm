#include "Hash.hpp"

// Hash s�n�f�n�n kurucu fonksiyonu
Hash::Hash() {
    // Hash tablosunu ba�lang��ta t�m indeksler NULL olarak ayarla
    for (int i = 0; i < MAX; i++)
        Dizi[i] = NULL;
}

// Hash tablosuna bir say� eklemek i�in fonksiyon
void Hash::Ekle(int sayi) {
    // Say� zaten tabloda varsa ekleme i�leminden ��k
    if (Bul(sayi))
        return;

    // Say�n�n hash kodunu hesapla ve ilgili indekse ekleyerek yeni d���m� olu�tur
    int indeks = HashCode(sayi);
    Dizi[indeks] = new Dugum(sayi, Dizi[indeks]);
}

// Verilen say�n�n hash tablosunda olup olmad���n� kontrol eden fonksiyon
bool Hash::Bul(int sayi) {
    int indeks = HashCode(sayi); // Say�n�n hash kodunu al
    Dugum* tmp = Dizi[indeks]; // �lgili indeksteki d���m� temsil eden i�aret�i

    // �lgili indeksteki ba�l� listede dola� ve say�y� bulmaya �al��
    while (tmp != NULL) {
        if (tmp->veri == sayi) // Say�y� bulursan true d�n
            return true;

        tmp = tmp->ileri; // Bir sonraki d���me ge�
    }

    // Say�y� bulamazsan false d�n
    return false;
}

// Verilen say�y� hash tablosundan ��karan fonksiyon
bool Hash::Cikar(int sayi) {
    int indeks = HashCode(sayi); // Say�n�n hash kodunu al

    // �lgili indeks NULL ise, ��karma i�leminden ��k ve false d�n
    if (Dizi[indeks] == NULL)
        return false;

    // �lk d���mdeki say�y� sil ve i�aret�iyi bir sonraki d���me ge�ir
    if (Dizi[indeks]->veri == sayi) {
        Dugum* sil = Dizi[indeks];
        Dizi[indeks] = Dizi[indeks]->ileri;
        delete sil;
        return true;
    }

    // �lgili indeksteki ba�l� listede say�y� bul ve ��kar
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

    // Say�y� bulamazsan false d�n
    return false;
}

// Hash tablosunun bo� olup olmad���n� kontrol eden fonksiyon
bool Hash::Bosmu() const {
    for (int i = 0; i < MAX; i++) {
        if (Dizi[i] != NULL)
            return false;
    }

    return true;
}

// Say�n�n hash kodunu hesaplayan fonksiyon
int Hash::HashCode(int sayi) {
    // �zel durumlar i�in belirli hash kodlar� d�nd�r
    if (sayi >= 256976744 && sayi <= 361788617)
        return 0;
    else if (sayi >= 230272265 && sayi <= 283549783)
        return 1;
    else
        return sayi % MAX; // Di�er durumlarda, mod alarak hash kodu hesapla
}

// Hash tablosundaki t�m elemanlar� temizleyen fonksiyon
void Hash::Temizle() {
    for (int i = 0; i < MAX; i++) {
        // Her indeksteki ba�l� listeyi dola� ve d���mleri sil
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

// Hash s�n�f�n�n y�k�c� fonksiyonu
Hash::~Hash() {
    Temizle(); // Bellek s�z�nt�s�n� �nlemek i�in tabloyu temizle
}

// Hash tablosundaki t�m elemanlar� ekrana yazd�ran fonksiyon
void Hash::Yaz() const {
    for (int i = 0; i < MAX; i++) {
        // E�er indekste eleman varsa, ba�l� listeyi yazd�r
        if (Dizi[i] != NULL) {
            cout << "Dizi[" << i << "] = ";

            for (Dugum* tmp = Dizi[i]; tmp != NULL; tmp = tmp->ileri) {
                cout << tmp->veri << " -> ";
            }

            cout << "NULL" << endl;
        }
    }
}
