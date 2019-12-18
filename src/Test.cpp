#include <iostream>
#include "OyunKontrol.h"

using namespace std;

int main() {
	OyunKontrol* oyun = new OyunKontrol("benim.txt", "rakip.txt");
	oyun->OyunuBaslat();
	delete oyun;
	system("pause");
	return 0;
}