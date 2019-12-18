#ifndef DUGUM_H
#define DUGUM_H

#include <iostream>

using namespace std;

class Dugum
{
private:
	int veri; // dugumda verinin bulundugu alan
	int soySayisi; // dugumde soysayisini tuttugumuz alan
public:
	Dugum* sag; // dugumde sag dugumun adresini tutan alan
	Dugum* sol; // dugumde sol dugumun adresini tutan alan

	Dugum(const int&); // sinifi sol ve sag dugumlerine null atayarak olusturan kurucu fonksiyon.
	Dugum(const int&, Dugum*, Dugum*); // sinifin tum degerlerine mudahale ederek olusturan kurucu fonksiyon.

	int getVeri(); // sinif disindan veriye ulasmak icin kullanilacak fonksiyon.
	void setVeri(int); // sinif disindan veriyi degistirmek icin kullanilacak fonksiyon.
	int getSoySayisi(); // sinif disindan soy sayisina ulasmak icin kullanilacak fonksiyon.
	void setSoySayisi(int); // sinif disindan soy sayisini degistirmek icin kullanilacak fonksiyon.
};

#endif
