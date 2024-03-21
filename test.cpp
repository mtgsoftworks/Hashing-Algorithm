#include "Hash.hpp"

int main() {
    Hash* hash = new Hash();// Bellekte dinamik olarak bir Hash nesnesi oluştur

    // A Grubu verilerini ekle
    hash->Ekle(280923994);
    hash->Ekle(306862745);
    hash->Ekle(300391389);
    hash->Ekle(269394714);
    hash->Ekle(274128142);
    hash->Ekle(310382513);
    hash->Ekle(276829268);
    hash->Ekle(289667896);
    hash->Ekle(298747763);
    hash->Ekle(270020533);
    hash->Ekle(280000000);
    hash->Ekle(322884012);
    hash->Ekle(256976744);
    hash->Ekle(290973871);
    hash->Ekle(361788617);
    hash->Ekle(361067503);

    // B Grubu verilerini ekle
    hash->Ekle(283549783);
    hash->Ekle(231459199);
    hash->Ekle(233341714);
    hash->Ekle(230272265);
    hash->Ekle(242318587);
    hash->Ekle(235389235);

    hash->Yaz(); // Hash tablosunu yazdır

    // Veri setindeki her bir verinin ayrı ayrı hash kodunu yazdır
    std::cout << "Hash Code 1(A): " << hash->HashCode(280923994) << std::endl;
    std::cout << "Hash Code 2(A): " << hash->HashCode(306862745) << std::endl;
    std::cout << "Hash Code 3(A): " << hash->HashCode(300391389) << std::endl;
    std::cout << "Hash Code 4(A): " << hash->HashCode(269394714) << std::endl;
    std::cout << "Hash Code 5(A): " << hash->HashCode(274128142) << std::endl;
    std::cout << "Hash Code 6(A): " << hash->HashCode(310382513) << std::endl;
    std::cout << "Hash Code 7(A): " << hash->HashCode(276829268) << std::endl;
    std::cout << "Hash Code 8(A): " << hash->HashCode(289667896) << std::endl;
    std::cout << "Hash Code 9(A): " << hash->HashCode(298747763) << std::endl;
    std::cout << "Hash Code 10(A): " << hash->HashCode(270020533) << std::endl;
    std::cout << "Hash Code 11(A): " << hash->HashCode(280000000) << std::endl;
    std::cout << "Hash Code 12(A): " << hash->HashCode(322884012) << std::endl;
    std::cout << "Hash Code 13(A): " << hash->HashCode(256976744) << std::endl;
    std::cout << "Hash Code 14(A): " << hash->HashCode(290973871) << std::endl;
    std::cout << "Hash Code 15(A): " << hash->HashCode(361788617) << std::endl;
    std::cout << "Hash Code 16(A): " << hash->HashCode(361067503) << std::endl;

    std::cout << "Hash Code 1(B): " << hash->HashCode(283549783) << std::endl;
    std::cout << "Hash Code 2(B): " << hash->HashCode(231459199) << std::endl;
    std::cout << "Hash Code 3(B): " << hash->HashCode(233341714) << std::endl;
    std::cout << "Hash Code 4(B): " << hash->HashCode(230272265) << std::endl;
    std::cout << "Hash Code 5(B): " << hash->HashCode(242318587) << std::endl;
    std::cout << "Hash Code 6(B): " << hash->HashCode(235389235) << std::endl;
    delete hash; // Belleği temizle

    return 0;
}
