#include "vardiya.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <numeric> 
#include <random>

using namespace std;

Vardiya::Vardiya(vector<int> ustaID, vector<int> isciID) : ustaID(ustaID), isciID(isciID) {
    srand(static_cast<unsigned int>(time(0)));
};

void Vardiya::siradakiVardiya()
{
    baslangicJenerasyonunuOlustur();

    for (int gen = 2; gen < MAX_JENERASYON && uygunlukDegerleri[enIyi[0]] < HEDEF_PUAN; gen++) {
        caprazlamaYap();
        mutasyonYap();
        sonJenerasyonunUygunlukDegerleriniHesapla();
        istatistikGuncelle();
    }

    gecmisVardiya = ustaPopulasyon[enIyi[0]];
    for (const auto& pair : isciPopulasyon[enIyi[0]]) {
        gecmisVardiya[pair.first] = pair.second;
    }

}

void Vardiya::baslangicJenerasyonunuOlustur()
{
    map<int, int> populasyon;
    for (int i = 0; i < 2; i++)
    {
        for (const int& usta : ustaID) {
            populasyon[usta] = rand() % 3;
        }
        ustaPopulasyon.push_back(populasyon);

        for (const int& isci : isciID) {
            populasyon[isci] = rand() % 3;
        }
        isciPopulasyon.push_back(populasyon);
        sonJenerasyonunUygunlukDegerleriniHesapla();
    }
    if (uygunlukDegerleri[0] >= uygunlukDegerleri[1]) {
        enIyi[0] = 0;
        enIyi[1] = 1;
    }
    else {
        enIyi[0] = 1;
        enIyi[1] = 0;
    }
}

void Vardiya::sonJenerasyonunUygunlukDegerleriniHesapla() {
    uygunlukDegerleri.push_back(uygunlukDegerleriHesapla(ustaPopulasyon.back(), isciPopulasyon.back()));
}

int Vardiya::uygunlukDegerleriHesapla(map<int, int> ustaGeni, map<int, int> isciGeni)
{
    /*
        KOSULLAR
        ----------------------------------------------------------------
        1-> Bir isci ayni gun icin birden fazla vardiyaya atanamaz.
        2-> Herhangi bir iscinin atanmadigi bos bir vardiya olamaz.
        3-> Ustalar vardiyalara esit dagitilmali.
        4-> Usta sayýsý fazlaysa eksik personelli vardiyaya atama.
        5-> Vardiyalar arasý iþçi sayýsý farký max 1 olmalý.
        6-> Vardiyalar arasý usta sayýsý farký max 1 olmalý.
        7-> Vardiyalarda personel(iþçi+usta) farký max 1 olmalý.
        ----------------------------------------------------------------*/
        // kosul 2
    int puan2 = 0; // max 30
    bool vardiyalarDolu[3] = { false, false, false };
    for (const auto& pair : ustaGeni) {
        vardiyalarDolu[pair.second] = true;
    }
    for (const auto& pair : isciGeni) {
        vardiyalarDolu[pair.second] = true;
    }
    for (const bool& doluluk : vardiyalarDolu) {
        puan2 += 10;
    }

    // kosul 3
    int puan3 = 0;
    int ustalarinVardiyalari[3] = { 0, 0, 0 };
    int idealUstaSayisi = ustaID.size() / 3;

    for (int i = 0; i < 3; i++) {
        int ustalarinVardiyadakiSayisi = ustalarinVardiyalari[i];
        puan3 += abs(ustalarinVardiyadakiSayisi - idealUstaSayisi);
    }
    puan3 = 30 - puan3; // Maksimum puan 30

// kosul 4 
    int puan4 = 0;

    for (int i = 0; i < 3; i++) {
        int ustalarinVardiyadakiSayisi = ustalarinVardiyalari[i];
        if (ustalarinVardiyadakiSayisi < idealUstaSayisi) {
            puan4 += 10; // Eksik personelli vardiya avantajý
        }
    }

    // kosul 5 
    int puan5 = 0;
    int isciSayilari[3] = { 0, 0, 0 };
    for (const auto& pair : isciGeni) {
        isciSayilari[pair.second]++;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            puan5 += abs(isciSayilari[i] - isciSayilari[j]);
        }
    }
    puan5 = 30 - puan5; // Maksimum puan 30 

    // kosul 6 
    int puan6 = 0;
    int ustalarinVardiyalar2[3] = { 0, 0, 0 };
    for (const auto& pair : ustaGeni) {
        ustalarinVardiyalar2[pair.second]++;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            puan6 += abs(ustalarinVardiyalar2[i] - ustalarinVardiyalar2[j]);
        }
    }
    puan6 = 30 - puan6; // Maksimum puan 30

    //kosul 7
    int puan7 = 0;
    int personelSayilari[3] = { 0, 0, 0 };
    for (const auto& pair : ustaGeni) {
        personelSayilari[pair.second]++;
    }
    for (const auto& pair : isciGeni) {
        personelSayilari[pair.second]++;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            puan7 += abs(personelSayilari[i] - personelSayilari[j]);
        }
    }
    puan7 = 30 - puan7; // Maksimum puan 30


    int puan = puan2 + puan3 + puan4 + puan5 + puan6 + puan7;
    return puan;
}

void Vardiya::caprazlamaYap()
{
    // En iyi iki jenerasyona dayalý olarak yeni bir jenerasyon üretilir. Deðiþkenlere kaydedilir.(Ýsci pop, Usta pop)
    // En iyi iki jenerasyonu al
    map<int, int> enIyiUsta = ustaPopulasyon[enIyi[0]];
    map<int, int> enIyiIsci = isciPopulasyon[enIyi[0]];

    map<int, int> ikinciEnIyiUsta = ustaPopulasyon[enIyi[1]];
    map<int, int> ikinciEnIyiIsci = isciPopulasyon[enIyi[1]];

    // Çaprazlama noktasýný belirle
    int caprazlamaNoktasi = rand() % (ustaID.size() + isciID.size());

    // Yeni çocuklarý oluþtur
    map<int, int> cocuk1Usta, cocuk1Isci, cocuk2Usta, cocuk2Isci;

    for (int i = 0; i < caprazlamaNoktasi; i++) {
        cocuk1Usta[ustaID[i]] = enIyiUsta[ustaID[i]];
        cocuk1Isci[isciID[i]] = enIyiIsci[isciID[i]];

        cocuk2Usta[ustaID[i]] = ikinciEnIyiUsta[ustaID[i]];
        cocuk2Isci[isciID[i]] = ikinciEnIyiIsci[isciID[i]];
    }

    for (int i = caprazlamaNoktasi; i < ustaID.size(); i++) {
        cocuk1Usta[ustaID[i]] = ikinciEnIyiUsta[ustaID[i]];
        cocuk1Isci[isciID[i]] = ikinciEnIyiIsci[isciID[i]];

        cocuk2Usta[ustaID[i]] = enIyiUsta[ustaID[i]];
        cocuk2Isci[isciID[i]] = enIyiIsci[isciID[i]];
    }

    // Yeni çocuklarý populasyona ekle
    ustaPopulasyon.push_back(cocuk1Usta);
    isciPopulasyon.push_back(cocuk1Isci);

    ustaPopulasyon.push_back(cocuk2Usta);
    isciPopulasyon.push_back(cocuk2Isci);

}



void Vardiya::mutasyonYap()
{
   
// En son isci ve usta popülasyonlarýný al
    map<int, int> sonIsci = isciPopulasyon.back();
    map<int, int> sonUsta = ustaPopulasyon.back();

    // Ýþçi ve ustalarýn sayýsý
    int isciSayisi = isciID.size();
    int ustaSayisi = ustaID.size();

    // Ýþçi ve ustalardan birini seç
    int secilenGrup = rand() % 2; // 0: Ýþçi, 1: Usta

    // Mutasyon indeksi
    int mutasyonIndex;

    if (secilenGrup == 0 && isciSayisi > 0) {
        // Ýþçi grubunu seç ve mutasyon indeksini belirle
        mutasyonIndex = rand() % isciSayisi;
        // Ýþçi genini deðiþtir
        sonIsci[isciID[mutasyonIndex]] = rand() % 3;
    }
    else if (ustaSayisi > 0) {
        // Usta grubunu seç ve mutasyon indeksini belirle
        mutasyonIndex = rand() % ustaSayisi;
        // Usta genini deðiþtir
        sonUsta[ustaID[mutasyonIndex]] = rand() % 3;
    }

    // Mutasyon sonrasý bireyleri populasyona ekleyin
    ustaPopulasyon.push_back(sonUsta);
    isciPopulasyon.push_back(sonIsci);
}


void Vardiya::caprazlamaVeMutasyonYap()
{
    caprazlamaYap();
    mutasyonYap();
    sonJenerasyonunUygunlukDegerleriniHesapla();
    istatistikGuncelle();
}

void Vardiya::seleksiyonYap()
{
    // Uygunluk deðerlerine göre seçim yap
    // Örneðin, turnuva seçimi kullanabilirsiniz
    int turnuvaBuyuklugu = 5; // 5 birey arasýndan en iyiyi seç
    int secilenIndex = -1;

    for (int i = 0; i < turnuvaBuyuklugu; i++) {
        int randomIndex = rand() % uygunlukDegerleri.size();
        if (secilenIndex == -1 || uygunlukDegerleri[randomIndex] > uygunlukDegerleri[secilenIndex]) {
            secilenIndex = randomIndex;
        }
    }

    // Seçilen bireyi en iyi birey olarak iþaretle
    enIyi[1] = enIyi[0];
    enIyi[0] = secilenIndex;
}

void Vardiya::genetikAlgoritmaCalistir()
{
    baslangicJenerasyonunuOlustur();

    for (int gen = 2; gen < MAX_JENERASYON && uygunlukDegerleri[enIyi[0]] < HEDEF_PUAN; gen++) {
        caprazlamaVeMutasyonYap();
        seleksiyonYap();
    }

    gecmisVardiya = ustaPopulasyon[enIyi[0]];
    for (const auto& pair : isciPopulasyon[enIyi[0]]) {
        gecmisVardiya[pair.first] = pair.second;
    }
}

void Vardiya::istatistikGuncelle()
{
    int sonJenerasyonDegeri = uygunlukDegerleri.back();
    int sonJenerasyonID = uygunlukDegerleri.size() - 1;
    int enIyiDeger = uygunlukDegerleri[enIyi[0]];
    int enIyi2Deger = uygunlukDegerleri[enIyi[1]];
    if (sonJenerasyonDegeri > enIyiDeger) {
        enIyi[1] = enIyi[0];
        enIyi[0] = sonJenerasyonID;
    }
    else if (sonJenerasyonDegeri > enIyi2Deger) {
        enIyi[1] = sonJenerasyonDegeri;
    }
}

void Vardiya::sonuclariGoruntule()
{

    for (const auto& calisan : gecmisVardiya) {
        cout << "CalisanNo: " << calisan.first << ", vardiya: " << calisan.second << "\n";
    }
    cout << "Jenerasyon: " << isciPopulasyon.size() << endl;
}

