#ifndef DEPO_H
#define DEPO_H

#include <iostream>
#include <fstream>
#include <string>
#include "Urun.h"
#include "Personel.h"
#include <chrono>
#include <ctime>
#include <iomanip>

class Depo {
private:
    Urun* urunler;
    Personel* personeller;
    int urunSayi;
    int personelSayi;
    static int kontrolSayi;

public:
    Depo();
    ~Depo();
    int getKontrolsayi();
    void urunEkle(const string& barkod, const string& urunadi, const string& konum, int kolihacmi, const string& gelimtarihi);
    void urunSil(const string& barkod);
    void urunListele() const;
    void personelEkle(int id, const string& adsoyad, int yas, const string& nitelik);
    void personelSil(int id);
    void personelListele() const;
    void urunuYolla(const string& barkod, int id);
    void urunIade(const string& barkod, int id);

    void urunKaydet(const string& dosyaadi) const;

    void urunYukle(const string& dosyaadi);
    void personelKaydet(const string& dosyaadi) const;
    void personelYukle(const string& dosyaadi);
    void kontrolVeHesapla();
};

#endif
