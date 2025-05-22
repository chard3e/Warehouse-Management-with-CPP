#include "Depo.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>

int Depo::kontrolSayi = 0;
Depo::Depo() : urunler(nullptr), personeller(nullptr), urunSayi(0), personelSayi(0) {
    kontrolSayi++;
}

Depo::~Depo() {
    delete[] urunler;
    delete[] personeller;
    kontrolSayi--;
}

void Depo::urunEkle(const string& barkod, const string& urunadi, const string& konum, int kolihacmi, const string& gelimtarihi) {
    Urun yeniurun(barkod, urunadi, konum, kolihacmi, gelimtarihi);
    Urun* temp = new Urun[urunSayi + 1];
    for (int i = 0; i < urunSayi; i++) {
        temp[i] = urunler[i];
    }
    temp[urunSayi] = yeniurun;

    delete[] urunler;
    urunler = temp;
    urunSayi++;

    system("cls");
    cout << "        Urun kaydi basarili!       " << endl;
    cout << "===================================";
}

void Depo::urunSil(const string& barkod) {
    bool urunBuldu = false;
    int index = -1;
    for (int i = 0; i < urunSayi; i++) {
        if (urunler[i].getBarkod() == barkod) {
            urunBuldu = true;
            index = i;
            break;
        }
    }

    if (urunBuldu) {
        for (int i = index; i < urunSayi - 1; i++) {
            urunler[i] = urunler[i + 1];
        }

        urunSayi--;

        system("cls");
        cout << "        Urun kaydi silindi!       " << endl;
        cout << "===================================";
    }
    else {
        system("cls");
        cout << "          Urun bulunamadi.        " << endl;
        cout << "===================================";
    }
}

void Depo::urunListele() const {
    if (urunSayi == 0) {
        system("cls");
        cout << "    Kayitli urun bulunmamakta.   " << endl;
        cout << "===================================";
    }
    else {
        cout << "Kayitli urun sayisi: " << urunSayi << endl;
        cout << "=======================" << endl;
        for (int i = 0; i < urunSayi; i++) {
            cout << "Urun " << i + 1 << ":" << endl;
            cout << urunler[i] << endl;
        }
    }
}

void Depo::personelEkle(int id, const string& adsoyad, int yas, const string& nitelik) {
    Personel yeniPersonel(id, adsoyad, yas, nitelik);
    Personel* temp = new Personel[personelSayi + 1];
    for (int i = 0; i < personelSayi; i++) {
        temp[i] = personeller[i];
    }
    temp[personelSayi] = yeniPersonel;
    delete[] personeller;
    personeller = temp;
    personelSayi++;

    system("cls");
    cout << "       Personel kaydi basarili!      " << endl;
    cout << "===================================";
}

void Depo::personelSil(int id) {
    bool personelBuldu = false;
    int index = -1;
    for (int i = 0; i < personelSayi; i++) {
        if (personeller[i].getID() == id) {
            personelBuldu = true;
            index = i;
            break;
        }
    }

    if (personelBuldu) {
        for (int i = index; i < personelSayi - 1; i++) {
            personeller[i] = personeller[i + 1];
        }

        personelSayi--;

        system("cls");
        cout << "       Personel kaydi silindi!      " << endl;
        cout << "===================================";
    }
    else {
        system("cls");
        cout << "         Personel bulunamadi.      " << endl;
        cout << "===================================";

    }
}

void Depo::personelListele() const {
    if (personelSayi == 0) {
        system("cls");
        cout << "    Kayitli personel bulunmamakta.  " << endl;
        cout << "===================================";
    }
    else {
        cout << "Kayitli personel sayisi: " << personelSayi << endl;
        cout << "=======================" << endl;
        for (int i = 0; i < personelSayi; i++) {
            cout << "Personel " << i + 1 << ":" << endl;
            cout << personeller[i] << endl;
        }
    }
}

void Depo::urunuYolla(const string& barkod, int id) {
    bool urunBuldu = false;
    int urunIndex = -1;
    bool personelBuldu = false;
    int personelIndex = -1;
    for (int i = 0; i < urunSayi; i++) {
        if (urunler[i].getBarkod() == barkod) {
            urunBuldu = true;
            urunIndex = i;
            break;
        }
    }

    for (int i = 0; i < personelSayi; i++) {
        if (personeller[i].getID() == id) {
            personelBuldu = true;
            personelIndex = i;
            break;
        }
    }

    if (urunBuldu && personelBuldu) {
        if (!urunler[urunIndex].Yollandimi()) {
            urunler[urunIndex].setYollandi(true);
            system("cls");
            cout << "     Yollanma islemi basarili!     " << endl;
            cout << "===================================";
        }
        else {
            system("cls");
            cout << "       Urun coktan yollanmis.    " << endl;
            cout << "===================================";
        }
    }
    else {
        system("cls");
        cout << "   Urun ya da personel bulunamadi. " << endl;
        cout << "===================================";
    }
}

void Depo::urunIade(const string& barkod, int id) {
    bool urunBuldu = false;
    int urunIndex = -1;
    bool personelBuldu = false;
    int personelIndex = -1;
    for (int i = 0; i < urunSayi; i++) {
        if (urunler[i].getBarkod() == barkod) {
            urunBuldu = true;
            personelIndex = i;
            break;
        }
    }

    for (int i = 0; i < personelSayi; i++) {
        if (personeller[i].getID() == id) {
            personelBuldu = true;
            personelIndex = i;
            break;
        }
    }

    if (urunBuldu && personelBuldu) {
        if (urunler[urunIndex].Yollandimi()) {
            urunler[urunIndex].setYollandi(false);
            system("cls");
            cout << "       Iade islemi basarili!       " << endl;
            cout << "===================================";
        }
        else {
            system("cls");
            cout << "         Urun yollanmamis.       " << endl;
            cout << "===================================";
        }
    }
    else {
        system("cls");
        cout << "   Urun ya da personel bulunamadi. " << endl;
        cout << "===================================";
    }
}



void Depo::urunKaydet(const string& dosyaadi) const {
    ofstream dosya(dosyaadi);
    if (dosya.is_open()) {
        dosya << urunSayi << "\n";

        for (int i = 0; i < urunSayi; i++) {
            dosya << urunler[i].getBarkod() << "\n";
            dosya << urunler[i].getUrunadi() << "\n";
            dosya << urunler[i].getKonum() << "\n";
            dosya << urunler[i].getKolihacmi() << "\n";
            dosya << urunler[i].getGelimtarihi() << "\n";
            dosya << urunler[i].Yollandimi() << "\n";
        }

        dosya.close();

    }
    else {
        cout << "Dosya acilamadi." << endl;
    }
}




void Depo::urunYukle(const string& dosyaadi) {
    ifstream dosya(dosyaadi);
    if (dosya.is_open()) {
        dosya >> urunSayi;
        dosya.ignore();

        delete[] urunler;
        urunler = new Urun[urunSayi];

        for (int i = 0; i < urunSayi; i++) {
            string barkod, urunadi, gelimtarihi, konum;
            int kolihacmi;
            bool yollandi;

            dosya >> barkod;
            dosya.ignore();
            getline(dosya, urunadi);
            getline(dosya, konum);
            dosya >> kolihacmi;
            dosya.ignore();
            getline(dosya, gelimtarihi);
            dosya >> yollandi;
            dosya.ignore();

            urunler[i] = Urun(barkod, urunadi, konum, kolihacmi, gelimtarihi);

        }

        dosya.close();

    }
    else {
        cout << "Dosya acilamadi." << endl;
    }
}



void Depo::personelKaydet(const string& dosyaadi) const {
    ofstream dosya(dosyaadi);
    if (dosya.is_open()) {
        dosya << personelSayi << "\n";

        for (int i = 0; i < personelSayi; i++) {
            dosya << personeller[i].getID() << "\n";
            dosya << personeller[i].getAdsoyad() << "\n";
            dosya << personeller[i].getYas() << "\n";
            dosya << personeller[i].getDepartman() << "\n";
        }

        dosya.close();

    }
    else {
        cout << "Dosya acilamadi." << endl;
    }
}

void Depo::personelYukle(const string& dosyaadi) {
    ifstream dosya(dosyaadi);
    if (dosya.is_open()) {
        dosya >> personelSayi;
        dosya.ignore();

        delete[] personeller;
        personeller = new Personel[personelSayi];

        for (int i = 0; i < personelSayi; i++) {
            string adsoyad, nitelik;
            int yas, id;

            dosya >> id;
            dosya.ignore();
            getline(dosya, adsoyad);
            dosya >> yas;
            dosya.ignore();
            getline(dosya, nitelik);

            personeller[i] = Personel(id, adsoyad, yas, nitelik);
        }

        dosya.close();

    }
    else {
        cout << "Dosya acilamadi." << endl;
    }
}


void Depo::kontrolVeHesapla() {
    auto today = chrono::system_clock::to_time_t(chrono::system_clock::now());
    struct tm date = {};

    if (localtime_s(&date, &today) != 0) {
        cerr << "Error: localtime_s failed" << endl;
        return;
    }

    stringstream ss;
    ss << put_time(&date, "%d.%m.%Y");
    string bugununTarihi = ss.str();

    for (int i = 0; i < urunSayi; i++) {
        string gelimTarihi = urunler[i].getGelimtarihi();
        int gelimGun, gelimAy;
        sscanf_s(gelimTarihi.c_str(), "%d.%d", &gelimGun, &gelimAy);
        int gecenGunler = date.tm_mday - gelimGun + (date.tm_mon + 1 - gelimAy) * 30;
        if (gecenGunler > 25) {
            int ekstraGunSayisi = gecenGunler - 25;
            double ekstraUcret = (urunler[i].getKolihacmi() / 10.0) * ekstraGunSayisi * 12.0;
            cout << "Barkod: " << urunler[i].getBarkod() << " - Ekstra Gun: " << ekstraGunSayisi << " - Ekstra Ucret: " << ekstraUcret << endl;
        }
    }
}