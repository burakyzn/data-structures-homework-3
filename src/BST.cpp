#include "BST.h"
#include <iostream>
using namespace std;

// eklenecek olan dugum icin en uygun yeri bulup daha sonra ekleme islemini baslatan fonksiyon.
void BST::araveEkle(Dugum*& altDugum, const int& yeni)
{
	if (altDugum == NULL) altDugum = new Dugum(yeni);
	else if (yeni < altDugum->getVeri()) {
		altDugum->setSoySayisi(altDugum->getSoySayisi() + 1);
		return araveEkle(altDugum->sol, yeni);
	}
	else if (yeni > altDugum->getVeri()) {
		altDugum->setSoySayisi(altDugum->getSoySayisi() + 1);
		return araveEkle(altDugum->sag, yeni);
	}
	else if (yeni == altDugum->getVeri()) {
		altDugum->setSoySayisi(altDugum->getSoySayisi() + 1);
		return araveEkle(altDugum->sol, yeni);
	}
	else return;
}

// silinecek olan dugumu bulup silme islemini baslatan fonksiyon.
bool BST::araveSil(Dugum*& altDugum, const int eleman)
{
	if (altDugum == NULL) return false;
	if (altDugum->getVeri() == eleman) {
		altDugum->setSoySayisi(altDugum->getSoySayisi() - 1);
		return dugumSil(altDugum);
	}
	else if (eleman < altDugum->getVeri()) {
		altDugum->setSoySayisi(altDugum->getSoySayisi() - 1);
		return araveSil(altDugum->sol, eleman);
	}
	else {
		altDugum->setSoySayisi(altDugum->getSoySayisi() - 1);
		return araveSil(altDugum->sag, eleman);
	}
}

// agaci postorder yontemiyle dolasan fonksiyon.
void BST::postOrder(Dugum* altDugum)
{
	if (altDugum != NULL) {
		postOrder(altDugum->sol);
		postOrder(altDugum->sag);
		cout << "<" << altDugum->getVeri() << "," << altDugum->getSoySayisi() << ">" << " ";
		agactakiSoySayisi += altDugum->getSoySayisi();
	}
}

// BST sinifindan nesne olusturuldugunda calisacak olan kurucu fonksiyon.
BST::BST()
{
	kok = NULL;
	agactakiSoySayisi = 0;
}

// disaridan cagrildiginda kok dugumu donduran fonksiyon.
Dugum* BST::getKokDugum()
{
	return kok;
}

// disaridan cagrildiginda agactaki soy sayisini donduran fonksiyon.
int BST::getAgactakiSoySayisi()
{
	return this->agactakiSoySayisi;
}

// disaridan cagrildiginda agactaki soy sayisini sifirlayan fonksiyon.
void BST::agacToplamSoySifirla()
{
	agactakiSoySayisi = 0;
	return;
}

// agactaki minimum degeri bulan fonksiyon.
int BST::minimumDeger()
{
	Dugum* tmp = kok;
	while (tmp->sol != NULL) {
		tmp = tmp->sol;
	}
	return tmp->getVeri();
}

// agactaki maximum degeri bulan fonksiyon.
int BST::maximumDeger()
{
	Dugum* tmp = kok;
	while (tmp->sag != NULL) {
		tmp = tmp->sag;
	}
	return tmp->getVeri();
}

// agacin bos olup olmadigini kontrol eden fonksiyon.
bool BST::bosMu() const
{
	return kok == NULL;
}

// disaridan gelen eleman ekleme isteklerini karsilayacak olan fonksiyon.
void BST::ekle(const int& yeni)
{
	araveEkle(kok, yeni);
}

// disaridan gelen postorder siralama islemlerini karsilayacak olan fonksiyon.
void BST::postOrder()
{
	postOrder(kok);
}

// disaridan silme isteklerini karsilamak icin yazilmis olan fonksiyon.
void BST::sil(int deger)
{
	araveSil(kok, deger);
}

// agactan istenilen dugumu silen fonksiyon.
bool BST::dugumSil(Dugum*& altDugum)
{
	Dugum* silinecekDugum = altDugum;
	if (altDugum->sag == NULL) altDugum = altDugum->sol;
	else if (altDugum->sol == NULL) altDugum = altDugum->sag;
	else {
		silinecekDugum = altDugum->sol;
		Dugum* ebeveynDugum = altDugum;
		while (silinecekDugum->sag != NULL) {
			silinecekDugum->setSoySayisi(silinecekDugum->getSoySayisi() - 1);
			ebeveynDugum = silinecekDugum;
			silinecekDugum = silinecekDugum->sag;
		}
		altDugum->setVeri(silinecekDugum->getVeri());
		if (ebeveynDugum == altDugum) {
			altDugum->sol = silinecekDugum->sol;
		}
		else {
			ebeveynDugum->sag = silinecekDugum->sol;
		}
	}
	delete silinecekDugum;
	return true;
}

// agactaki dugumleri silen ve hafizadan temizleyen fonksiyon.
void BST::temizle()
{
	while (!bosMu()) dugumSil(kok);
}

// BST sinifinin nesnesi silindiginde heap bolgesinde cop birakmamak icin yazilmis yikici fonksiyon
BST::~BST()
{
	temizle();
}
