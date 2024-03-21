#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>
using namespace std;

#define MAX 100 // Bu ifade, hash tablosunun maksimum boyutunu belirlemek için kullanılır.

// Dugum yapısı, veri ve bir sonraki düğümü işaret eden bir işaretçi içerir.
struct Dugum {
    int veri;
    Dugum* ileri;
    Dugum(int vr, Dugum* ilr = NULL) {
        veri = vr;
        ileri = ilr;
    }
};

// Hash sınıfı, bir karma tablosunu temsil eder.
class Hash {
private:
    Dugum* Dizi[MAX]; // Bir dizi işaretçi, her biri bir bağlı listeyi işaret eder.
public:
    Hash(); // Kurucu fonksiyon
    int HashCode(int); // Karma fonksiyonu
    void Ekle(int); // Bir eleman ekler
    bool Cikar(int); // Bir elemanı çıkarır
    void Temizle(); // Tüm tabloyu temizler
    bool Bul(int); // Bir elemanın olup olmadığını kontrol eder
    bool Bosmu() const; // Tablonun boş olup olmadığını kontrol eder
    void Yaz() const; // Tabloyu yazdırır
    ~Hash(); // Yıkıcı fonksiyon
};

#endif
