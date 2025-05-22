#include "Personel.h"

Personel::Personel() {}

Personel::Personel(int id, const string& adsoyad, int yas, const string& nitelik)
	: id(id), adsoyad(adsoyad), yas(yas), nitelik(nitelik) {}

string Personel::getAdsoyad() const {
	return adsoyad;
}

int Personel::getID() const {
	return id;
}

int Personel::getYas() const {
	return yas;
}

string Personel::getDepartman()const {
	return nitelik;
}

void Personel::setAdsoyad(const string& adsoyad) {
	this->adsoyad = adsoyad;
}

void Personel::setID(int id) {
	this->id = id;
}

void Personel::setYas(int yas) {
	this->yas = yas;
}

void Personel::setDepartman(const string& nitelik) {
	this->nitelik = nitelik;
}

ostream& operator<<(ostream& os, const Personel& personel) {
	os << "ID: " << personel.id << endl;
	os << "Ad-Soyad: " << personel.adsoyad << endl;
	os << "Yas: " << personel.yas << endl;
	os << "Nitelik: " << personel.nitelik << endl;
	return os;
}

istream& operator>>(istream& is, Personel& personel) {
	cout << "ID: ";
	is.ignore();
	is >> personel.id;
	cout << "Ad-Soyad: ";
	is.ignore();
	getline(is, personel.adsoyad);
	cout << "Yas: ";
	is >> personel.yas;
	cout << "Nitelik: ";
	is.ignore();
	getline(is, personel.nitelik);
	return is;
}

