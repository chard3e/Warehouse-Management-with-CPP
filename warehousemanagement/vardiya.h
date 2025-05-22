#ifndef VARDIYA_H
#define VARDIYA_H
#include <vector> 
#include <map>

using namespace std;

class Vardiya {
public:

    Vardiya(vector<int>ustaID, vector<int>isciID);


    void siradakiVardiya();     // Genetik algoritma fonksiyonu
    void sonuclariGoruntule(); // Sonuçlarý görüntüleme fonksiyonu

private:
    vector<int> ustaID;
    vector<int> isciID;
    const int MAX_JENERASYON = 100;
    const int HEDEF_PUAN = 30;

    int enIyi[2] = { -1,-1 };

    vector<map<int, int>> isciPopulasyon; // hangi çalýþan hangi vardiyada 
    vector<map<int, int>> ustaPopulasyon;
    vector<int> uygunlukDegerleri; // Her bir bireyin uygunluk deðerleri

    map<int, int> gecmisVardiya; //geçmiþ vardiyayý tutacak


    // Diðer yardýmcý fonksiyonlar
    void baslangicJenerasyonunuOlustur();
    void sonJenerasyonunUygunlukDegerleriniHesapla();
    int  uygunlukDegerleriHesapla(map<int, int> ustaGeni, map<int, int> isciGeni);
    void seleksiyonYap();
    void caprazlamaYap();
    void mutasyonYap();
    void caprazlamaVeMutasyonYap();
    void istatistikGuncelle();
    void genetikAlgoritmaCalistir();

};

#endif