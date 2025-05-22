#include "Urun.h"


Urun::Urun() : yollandi(false) {}

Urun::Urun(const string& barkod, const string& urunadi, const string& konum, int kolihacmi, const string& gelimtarihi)
    : barkod(barkod), urunadi(urunadi), konum(konum), kolihacmi(kolihacmi), gelimtarihi(gelimtarihi), yollandi(false) {}

string Urun::getBarkod() const {
    return barkod;
}

string Urun::getUrunadi() const {
    return urunadi;
}

string Urun::getKonum() const {
    return konum;
}

int Urun::getKolihacmi() const {
    return kolihacmi;
}

string Urun::getGelimtarihi() const {
    return gelimtarihi;
}


bool Urun::Yollandimi() const {
    return yollandi;
}

void Urun::setBarkod(const string& barkod) {
    this->barkod = barkod;
}

void Urun::setUrunadi(const string& urunadi) {
    this->urunadi = urunadi;
}

void Urun::setKonum(const string& konum) {
    this->konum = konum;
}

void Urun::setKolihacmi(int kolihacmi) {
    this->kolihacmi = kolihacmi;
}

void Urun::setGelimtarihi(const string& gelimtarihi) {
    this->gelimtarihi = gelimtarihi;
}


void Urun::setYollandi(bool yollandi) {
    this->yollandi = yollandi;
}

ostream& operator<<(ostream& os, const Urun& urun) {
    os << "Barkod: " << urun.barkod << endl;
    os << "Urun Adi: " << urun.urunadi << endl;
    os << "Konum No: " << urun.konum << endl;
    os << "Koli Hacmi: " << urun.kolihacmi << endl;
    os << "Gelim Tarihi: " << urun.gelimtarihi << endl;
    os << "Yollanmis mi?: " << (urun.yollandi ? "Evet" : "Hayir") << endl;
    return os;
}

istream& operator>>(istream& is, Urun& urun) {
    cout << "Barkod: ";
    is >> urun.barkod;
    cout << "Urun Adi: ";
    is.ignore();
    getline(is, urun.urunadi);
    cout << "Konum No: ";
    is >> urun.konum;
    cout << "Koli Hacmi: ";
    is >> urun.kolihacmi;
    cout << "Gelim Tarihi: ";
    getline(is, urun.gelimtarihi);
    return is;
}

