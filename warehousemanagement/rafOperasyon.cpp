#include "Raf.h"
#include<iostream>
using namespace std;

void runSpecialCase() {
    int kutuSayi;
    cout << "Koli sayisini girin: ";
    cin >> kutuSayi;

    Dolap raf(kutuSayi);
    raf.kutulariBaslat();
    raf.raflariBaslat();
    raf.raflariKalanGenisligeGoreSirala();
    raf.yerlestirmeAlgoritmasiCalis();
    raf.kalanAlanlariGoster();
}
