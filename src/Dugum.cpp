#include "Dugum.h"
#include <iostream>

// sinifi sol ve sag dugumlerine null atayarak olusturan kurucu fonksiyon.
Dugum::Dugum(const int& vr)
{
	veri = vr;
	sol = NULL;
	sag = NULL;
	soySayisi = 0;
}

// sinifin tum degerlerine mudahale ederek olusturan kurucu fonksiyon.
Dugum::Dugum(const int& vr, Dugum* sl, Dugum* sg)
{
	veri = vr;
	sol = sl;
	sag = sg;
	soySayisi = 0;
}

// sinif disindan veriye ulasmak icin kullanilacak fonksiyon.
int Dugum::getVeri()
{
	return this->veri;
}

// sinif disindan veriyi degistirmek icin kullanilacak fonksiyon.
void Dugum::setVeri(int deger)
{
	this->veri = deger;
}

// sinif disindan soy sayisina ulasmak icin kullanilacak fonksiyon.
int Dugum::getSoySayisi()
{
	return this->soySayisi;
}

// sinif disindan soy sayisini degistirmek icin kullanilacak fonksiyon.
void Dugum::setSoySayisi(int deger)
{
	this->soySayisi = deger;
}
