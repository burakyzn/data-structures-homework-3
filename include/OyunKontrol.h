#ifndef OYUNKONTROL_H
#define OYUNKONTROL_H

#include "BST.h"
class OyunKontrol
{
private:
	BST* benimAgac; // benim sayilarimin tutuldugu agac
	BST* rakipAgac; // rakibin sayilarinin tutuldugu agac
	int benimPuan; // benim puanimin tutuldugu alan
	int rakipPuan; // rakip puaninin tutuldugu alan
	void dosyalariOku(string,string); // belirtilen dosya yolundaki txt dosyalarini acip icindeki degerleri okuyan fonksiyon.
public:

	OyunKontrol(string, string); // oyunkontrol sinifindan nesne olusturuldugunda calisan kurucu fonksiyon.
	~OyunKontrol(); // oyun bittiginde sinifin kullandigi hafizayi temizlemek icin kullanilan fonksiyon.

	void OyunuBaslat(); // oyunu disaridan cagrilarak baslaticak olan fonksiyon.
};

#endif