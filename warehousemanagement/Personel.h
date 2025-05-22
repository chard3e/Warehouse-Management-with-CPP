#ifndef PERSONEL_H
#define PERSONEL_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Personel {
private:
    int id;
    string adsoyad;
    int yas;
    string nitelik;

public:
    Personel();
    Personel(int id, const string& adsoyad, int yas, const string& nitelik);

    string getAdsoyad() const;
    int getID() const;
    int getYas() const;
    string getDepartman() const;

    void setAdsoyad(const string& adsoyad);
    void setID(int id);
    void setYas(int yas);
    void setDepartman(const string& nitelik);

    friend ostream& operator<<(ostream& os, const Personel& personel);
    friend istream& operator>>(istream& is, Personel& personel);
};

#endif


