#ifndef URUN_H
#define URUN_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Urun {
private:
    string barkod;
    string urunadi;
    string konum;
    int kolihacmi;
    string gelimtarihi;
    bool yollandi;

public:
    Urun();
    Urun(const string& barkod, const string& urunadi, const string& konum, int kolihacmi, const string& gelimtarihi);

    string getBarkod() const;
    string getUrunadi() const;
    string getKonum() const;
    int getKolihacmi() const;
    string getGelimtarihi() const;
    bool Yollandimi() const;
    void setBarkod(const string& barkod);
    void setUrunadi(const string& urunadi);
    void setKonum(const string& konum);
    void setKolihacmi(int kolihacmi);
    void setGelimtarihi(const string& gelimtarihi);
    void setYollandi(bool yollandi);

    friend ostream& operator<<(ostream& os, const Urun& urun);
    friend istream& operator>>(istream& is, Urun& urun);
};

#endif

