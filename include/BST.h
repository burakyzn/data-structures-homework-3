#ifndef BST_H
#define BST_H

#include <iostream>
#include "Dugum.h"
class BST
{
private:
	Dugum* kok; // kok dugumun tutuldugu alan
	int agactakiSoySayisi; // agactaki soy sayisinin tutuldugu alan

	void araveEkle(Dugum*&, const int&); // eklenecek olan dugum icin en uygun yeri bulup daha sonra ekleme islemini baslatan fonksiyon.
	bool araveSil(Dugum*&, const int); // silinecek olan dugumu bulup silme islemini baslatan fonksiyon.
	void postOrder(Dugum*); // agaci postorder yontemiyle dolasan fonksiyon.
	bool dugumSil(Dugum*&); // agactan istenilen dugumu silen fonksiyon.

public:
	BST(); // BST sinifindan nesne olusturuldugunda calisacak olan kurucu fonksiyon.
	~BST(); // BST sinifinin nesnesi silindiginde heap bolgesinde cop birakmamak icin yazilmis yikici fonksiyon

	Dugum* getKokDugum(); // disaridan cagrilan kok dugumu donduran fonksiyon.
	int getAgactakiSoySayisi(); // disaridan cagrildiginda agactaki soy sayisini donduran fonksiyon.
	void agacToplamSoySifirla(); // disaridan cagrildiginda agactaki soy sayisini sifirlayan fonksiyon.
	int minimumDeger(); // agactaki minimum degeri bulan fonksiyon.
	int maximumDeger(); // agactaki maximum degeri bulan fonksiyon.
	bool bosMu()const; // agacin bos olup olmadigini kontrol eden fonksiyon.
	void ekle(const int&); // disaridan gelen eleman ekleme isteklerini karsilayacak olan fonksiyon.
	void postOrder(); // disaridan gelen postorder siralama islemlerini karsilayacak olan fonksiyon.
	void sil(int); // disaridan silme isteklerini karsilamak icin yazilmis olan fonksiyon.
	void temizle(); // agactaki dugumleri silen ve hafizadan temizleyen fonksiyon.
};

#endif