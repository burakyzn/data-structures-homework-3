#include "OyunKontrol.h"
#include <fstream>
#include <string>

using namespace std;

// belirtilen dosya yolundaki txt dosyalarini acip icindeki degerleri okuyan fonksiyon.
void OyunKontrol::dosyalariOku(string benim, string rakip) // dosyalardan sayilari okuyup gerekli agaclara aktaricak fonksiyon.
{
	ifstream benimDosya(benim, ios::in); // dosya okumalarini yapmak icin ifstream sinifindan yararlandik.
	ifstream rakipDosya(rakip, ios::in);

	if (benimDosya.is_open()) { // benim agacima sayilari sirayla ekliyor.
		string sayi;
		while (benimDosya >> sayi) {
			this->benimAgac->ekle(stoi(sayi));
		}
	}

	if (rakipDosya.is_open()) { // rakip agacina sayilari sirayla ekliyor.
		string sayi;
		while (rakipDosya >> sayi) {
			this->rakipAgac->ekle(stoi(sayi));
		}
	}
}

// oyunkontrol sinifindan nesne olusturuldugunda calisan kurucu fonksiyon.
OyunKontrol::OyunKontrol(string benim, string rakip) // gelen paremetrelerle nesneyi yaratan olan kurucu fonksiyon.
{
	benimAgac = new BST();
	rakipAgac = new BST();
	benimPuan = 0;
	rakipPuan = 0;

	dosyalariOku(benim, rakip); // dosyalari okuyup icindeki degerleri almasi icin bu fonksiyonu cagiriyorum.
}

// oyunu disaridan cagrilarak baslaticak olan fonksiyon.
void OyunKontrol::OyunuBaslat() // oyunu baslatacak olan fonksiyon.
{
	bool oyunDevam = true;

	for (int turSayisi = 0; turSayisi <= 20; turSayisi++) {
		cout << "Benim Agac Postorder : " << endl;
		benimAgac->postOrder();
		cout << endl << "Benim Agac Toplam Soy Sayisi : " << benimAgac->getAgactakiSoySayisi() << endl;
		cout << "----------------------------------------------------" << endl << endl;

		cout << "Rakip Agac Postorder : " << endl;
		rakipAgac->postOrder();
		cout << endl << "Rakip Agac Toplam Soy Sayisi : " << rakipAgac->getAgactakiSoySayisi() << endl;
		cout << "----------------------------------------------------" << endl << endl;

		// benim kazanirsa yapilacaklar
		if (benimAgac->getAgactakiSoySayisi() < rakipAgac->getAgactakiSoySayisi()) {
			benimAgac->agacToplamSoySifirla();
			rakipAgac->agacToplamSoySifirla();

			benimPuan++;
			cout << "--TEBRIKLER KAZANDINIZ--" << endl;

			benimAgac->ekle(rakipAgac->maximumDeger());
			rakipAgac->sil(rakipAgac->maximumDeger());
			rakipAgac->ekle(benimAgac->getKokDugum()->getVeri());
			benimAgac->sil(benimAgac->getKokDugum()->getVeri());
		}
		// rakip kazanirsa yapilacaklar
		else if (benimAgac->getAgactakiSoySayisi() > rakipAgac->getAgactakiSoySayisi()) {
			benimAgac->agacToplamSoySifirla();
			rakipAgac->agacToplamSoySifirla();
			rakipPuan++;

			rakipAgac->ekle(benimAgac->maximumDeger());
			benimAgac->sil(benimAgac->maximumDeger());
			benimAgac->ekle(rakipAgac->getKokDugum()->getVeri());
			rakipAgac->sil(rakipAgac->getKokDugum()->getVeri());
			cout << "--RAKIP KAZANDI--" << endl;
		}
		// berabere durumunda yapilacaklar
		else {
			benimAgac->agacToplamSoySifirla();
			rakipAgac->agacToplamSoySifirla();

			benimAgac->ekle(rakipAgac->getKokDugum()->getVeri());
			rakipAgac->sil(rakipAgac->getKokDugum()->getVeri());
			rakipAgac->ekle(benimAgac->getKokDugum()->getVeri());
			benimAgac->sil(benimAgac->getKokDugum()->getVeri());
			cout << "--BERABERE--" << endl;
		}

		cout << "Benim Skor : " << benimPuan << endl;
		cout << "Rakip Skor : " << rakipPuan << endl;

		if (benimPuan >= 5) {
			oyunDevam = false;
			cout << endl << "--OYUN BITTI KAZANDINIZ--" << endl;
			break;
		}
		else if (rakipPuan >= 5) {
			oyunDevam = false;
			cout << endl << "--OYUN BITTI KAYBETTINIZ--" << endl;
			break;
		}

		system("pause");
		system("cls");
	}

	if (oyunDevam == true) {
		if (benimPuan > rakipPuan) {
			cout << endl << "--OYUN BITTI KAZANDINIZ--" << endl;
		}
		else {
			cout << endl << "--OYUN BITTI KAYBETTINIZ--" << endl;
		}
	}
}

// oyun bittiginde sinifin kullandigi hafizayi temizlemek icin kullanilan fonksiyon.
OyunKontrol::~OyunKontrol()
{
	delete benimAgac;
	delete rakipAgac;
}
