#include "Raf.h"
#include <iostream>
#include <algorithm>
using namespace std;

Dolap::Dolap(int kutuSayi) {
    kutular.resize(kutuSayi);
}

void Dolap::kutulariBaslat() {
    for (int i = 0; i < kutular.size(); ++i) {
        int genislik, uzunluk;
        cout << i + 1 << ". kutunun genisligini ve uzunlugunu giriniz: ";
        cin >> genislik >> uzunluk;
        kutular[i] = { genislik, uzunluk, "a" + to_string(i + 1) };
    }
}

void Dolap::raflariBaslat() {
    raflar = {
         {"a1", 5, 5, 5},
        {"a2", 5, 5, 5},
        {"a3", 5, 5, 5},
        {"a4", 5, 5, 5},
        {"a5", 5, 5, 5},
        {"a6", 5, 5, 5},
        {"a7", 5, 5, 5},
        {"a8", 5, 5, 5},
        {"a9", 5, 5, 5},
        {"a10",5, 5, 5},
        {"b1", 7, 7, 7},
        {"b2", 7, 7, 7},
        {"b3", 7, 7, 7},
        {"b4", 7, 7, 7},
        {"b5", 7, 7, 7},
        {"b6", 7, 7, 7},
        {"b7", 7, 7, 7},
        {"b8", 7, 7, 7},
        {"b9", 7, 7, 7},
        {"b10", 7, 7, 7},
        {"c1", 10, 10, 10},
        {"c2", 10, 10, 10},
        {"c3", 10, 10, 10},
        {"c4", 10, 10, 10},
        {"c5", 10, 10, 10},
        {"c6", 10, 10, 10},
        {"c7", 10, 10, 10},
        {"c8", 10, 10, 10},
        {"c9", 10, 10, 10},
        {"c10", 10, 10, 10}
    };
}

void Dolap::raflariKalanGenisligeGoreSirala() {
    sort(raflar.begin(), raflar.end(), [](const Raf& a, const Raf& b) {
        return a.kalanGenislik > b.kalanGenislik;
        });
}

bool Dolap::rafaSiganKutu(const Kutu& kutu, const Raf& raf) {
    return kutu.genislik <= raf.kalanGenislik && kutu.uzunluk <= raf.uzunluk;
}

void Dolap::kutuyuRafaYerlestir(Kutu& kutu, Raf& raf) {
    cout << kutu.genislik << "x" << kutu.uzunluk << " boyutlu " << kutu.ad << " kutusu " << raf.ad << "(" << raf.genislik << "x" << raf.uzunluk << ") rafina yerlestirilmeli. \n";
    raf.kalanGenislik -= kutu.genislik;
}

void Dolap::yerlestirmeAlgoritmasiCalis() {
    for (Kutu& kutu : kutular) {
        bool boxPlaced = false;

        for (auto& raf : raflar) {
            if (rafaSiganKutu(kutu, raf)) {
                kutuyuRafaYerlestir(kutu, raf);
                boxPlaced = true;
                break;
            }
        }

        if (!boxPlaced) {
            cout << kutu.genislik << "x" << kutu.uzunluk << " boyutlu " << kutu.ad << " kutusu icin uygun raf yok. \n";
        }
    }
}

void Dolap::kalanAlanlariGoster() {
    cout << "\nRaflarda kalan alanlarr:\n";
    for (const auto& raf : raflar) {
        cout << "Raf " << raf.ad << ": " << raf.kalanGenislik << "x" << raf.uzunluk << "\n";
    }
}
