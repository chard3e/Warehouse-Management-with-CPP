#include "Depo.h"
#include "Raf.h"
#include "vardiya.h"

using namespace std;
void runSpecialCase();

int main() {
    Depo depo;

    depo.urunYukle("urunler.txt");
    depo.personelYukle("personeller.txt");
    Vardiya vardiya({ 10,34,69 }, { 403,506,203 }); //  3 usta , 3iþçi
    int secim;
    string barkod, urunadi, gelimtarihi, adsoyad, nitelik, konum;
    int id, yas, kolihacmi;

    do {
        cout << "======== Beykoz Warehouse ========" << endl;
        cout << "1. Urun ekle" << endl;
        cout << "2. Urun sil" << endl;
        cout << "3. Urunleri listele" << endl;
        cout << "4. Personel ekle" << endl;
        cout << "5. Personel sil" << endl;
        cout << "6. Personelleri listele" << endl;
        cout << "7. Urun yollama" << endl;
        cout << "8. Urun iade" << endl;
        cout << "9. Raf belirleme" << endl;
        cout << "10. Ekstra ucretli urunleri gorme" << endl;
        cout << "11. Vardiya goruntuleme" << endl;
        cout << "0. Cikis" << endl;
        cout << "Yapmak istediginiz islemi giriniz: ";
        cin >> secim;
        cout << endl;

        switch (secim) {
        case 1:
            cout << "Barkod: ";
            cin >> barkod;
            cout << "Urun Adi: ";
            cin.ignore();
            getline(cin, urunadi);
            cout << "Konum No: ";
            cin.ignore();
            getline(cin, konum);
            cout << "Koli Hacmi: ";
            cin >> kolihacmi;
            cin.ignore();
            cout << "Gelim tarihi: ";
            getline(cin, gelimtarihi);
            depo.urunEkle(barkod, urunadi, konum, kolihacmi, gelimtarihi);
            depo.urunKaydet("urunler.txt");
            break;
        case 2:
            cout << "Barkod: ";
            cin >> barkod;
            depo.urunSil(barkod);
            //depo.urunKaydet("urunler.txt");
            break;
        case 3:
            system("cls");
            depo.urunListele();
            break;
        case 4:
            cout << "ID: ";
            cin >> id;
            cout << "Ad-Soyad: ";
            cin.ignore();
            getline(cin, adsoyad);
            cout << "Yas: ";
            cin >> yas;
            cout << "Nitelik: ";
            cin.ignore();
            getline(cin, nitelik);
            depo.personelEkle(id, adsoyad, yas, nitelik);
            depo.personelKaydet("personeller.txt");
            break;
        case 5:
            cout << "ID: ";
            cin >> id;
            depo.personelSil(id);
            depo.personelKaydet("personeller.txt");
            break;
        case 6:
            system("cls");
            depo.personelListele();

            break;
        case 7:
            cout << "Barkod: ";
            cin >> barkod;
            cout << "ID: ";
            cin >> id;
            depo.urunuYolla(barkod, id);
            depo.urunKaydet("urunler.txt");
            break;
        case 8:
            cout << "Barkod: ";
            cin >> barkod;
            cout << "ID: ";
            cin >> id;
            depo.urunIade(barkod, id);
            depo.urunKaydet("urunler.txt");
            break;
        case 9:
            runSpecialCase();
            break;
        case 10:
            depo.kontrolVeHesapla();
            break;
        case 11:
            vardiya.siradakiVardiya();
            vardiya.sonuclariGoruntule();
            break;
        case 0:
            cout << "Cikis yapiliyor..." << endl;
            break;
        default:
            cout << "Gecersiz secim... Tekrar deneyiniz." << endl;
            break;
        }

        cout << endl;
    } while (secim != 0);

    return 0;
}

