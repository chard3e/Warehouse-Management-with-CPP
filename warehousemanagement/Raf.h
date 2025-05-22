#pragma once

#include <string>
#include <vector>
using namespace std;

struct Kutu {
	int genislik;
	int uzunluk;
	string ad;
};

struct Raf {
	string ad;
	int genislik;
	int uzunluk;
	int kalanGenislik;
};

class Dolap {
public:
	Dolap(int kutuSayi);

	void kutulariBaslat();
	void raflariBaslat();
	void raflariKalanGenisligeGoreSirala();
	bool rafaSiganKutu(const Kutu& kutu, const Raf& raf);
	void kutuyuRafaYerlestir(Kutu& kutu, Raf& raf);
	void yerlestirmeAlgoritmasiCalis();
	void kalanAlanlariGoster();

private:
	vector<Kutu> kutular;
	vector<Raf> raflar;
};
