


#include <iostream>
#include <cmath>
using namespace std;

class karmasikSayi  // Karma��k say�lar s�n�f� olu�turdum.
{
public:
	double reel;
	double sanal;

	void sayiIsteme()  // Kullan�c�dan ekrana karma��k say� girmesi i�in bir fonksiyon yazd�m.
	{
		cout << "Lutfen sayinin reel kismini giriniz: ";
		cin >> reel;
		cout << "Lutfen sayinin sanal kismini giriniz: ";
		cin >> sanal;
	}

	void sayiYazdirma()  // Kullan�c�n�n girdi�i karma��k say�y� ekrana yazd�ran fonksiyon yazd�m.
	{
		if (sanal < 0)
		{
			cout << "Karmasik Sayi: " << reel << " " << sanal << "i" << endl;
		}
		else
			cout << "Karmasik Sayi: " << reel << "+" << sanal << "i" << endl;
	}

	karmasikSayi operator+(karmasikSayi ks2)  //     + overloading operat�r�
	{
		karmasikSayi ks3{};
		ks3.reel = reel + ks2.reel;
		ks3.sanal = sanal + ks2.sanal;
		return ks3;
	}

	karmasikSayi operator-(karmasikSayi ks2)  //    - overloading operat�r�
	{
		karmasikSayi ks3{};
		ks3.reel = reel - ks2.reel;
		ks3.sanal = sanal - ks2.sanal;
		return ks3;
	}

	karmasikSayi operator*(karmasikSayi ks2)  //    * overloading operat�r�
	{
		karmasikSayi ks3{};
		ks3.reel = reel * ks2.reel - sanal * ks2.sanal;
		ks3.sanal = reel * ks2.sanal + sanal * ks2.reel;
		return ks3;
	}

	karmasikSayi operator/(karmasikSayi ks2)  //    / overloading operat�r�
	{
		karmasikSayi ks3{};
		ks3.reel = (reel * ks2.reel - sanal * (-1 * ks2.sanal)) / (ks2.reel * ks2.reel) + (ks2.sanal + ks2.sanal);
		ks3.sanal = (reel * (-1 * ks2.sanal) + sanal * ks2.reel) / (ks2.reel * ks2.reel) + (ks2.sanal + ks2.sanal);
		return ks3;
	}

	karmasikSayi operator+=(karmasikSayi ks2)  //     += overloading operat�r�
	{
		reel += ks2.reel;
		sanal += ks2.sanal;
		cout << reel << " " << sanal << "i" << endl;
		return *this;
	}

	karmasikSayi operator-=(karmasikSayi ks2)  //     -= overloading operat�r�
	{
		reel -= ks2.reel;
		sanal -= ks2.sanal;
		return *this;
	}

	karmasikSayi operator*=(karmasikSayi ks2)  //     *= overloading operat�r�
	{
		reel = ks2.reel - sanal * ks2.sanal;
		sanal = ks2.sanal + sanal * ks2.reel;
		return *this;
	}

	karmasikSayi operator/=(karmasikSayi ks2)  //       /= overloading operat�r�
	{
		reel = (reel * ks2.reel - sanal * (-1 * ks2.sanal)) / (ks2.reel * ks2.reel) + (ks2.sanal * ks2.sanal);
		sanal = (reel * (-1 * ks2.sanal) + sanal * ks2.reel) / (ks2.reel * ks2.reel) + (ks2.sanal * ks2.sanal);
		return *this;
	}

	void KutupsalGosterim()  //    Kutupsal g�sterim i�in fonksiyon yazd�m
	{
		double derece = 180 / 3.141593;
		double yaricap = sqrt(reel * reel + sanal * sanal);
		double alfa = atan(sanal / reel) * derece;
		cout << "Yaricap = " << yaricap << endl;
		cout << "Aci = " << alfa << endl;

	}
};


int main()
{
	karmasikSayi ks1{};  // karmasikSayi s�n�f�ndan ks1 nesnesi tan�mlad�m.
	karmasikSayi ks2{};  // karmasikSayi s�n�f�ndan ks2 nesnesi tan�mlad�m.

	cout << "Lutfen birinci karmasik sayiyi giriniz: " << endl;  // s�n�f i�erisinde yazd���m fonksiyonlar� mainin i�inde �a��rd�m.
	cout << endl;
	ks1.sayiIsteme();
	ks1.sayiYazdirma();
	cout << endl;

	cout << "Lutfen ikinci karmasik sayiyi giriniz: " << endl;  // s�n�f i�erisinde yazd���m fonksiyonlar� mainin i�inde �a��rd�m.
	cout << endl;
	ks2.sayiIsteme();
	ks2.sayiYazdirma();

	karmasikSayi toplama{}, cikarma{}, carpma{}, bolme{};  // Operat�r nesnelerini tan�mlad�m.

	toplama = ks1 + ks2;   //  Operat�rlerin yapaca�� i�lemleri nesnelerle yapt�rarak tan�mlad�m. 
	cikarma = ks1 - ks2;   //  Operat�rlerin yapaca�� i�lemleri nesnelerle yapt�rarak tan�mlad�m. 
	carpma = ks1 * ks2;    //  Operat�rlerin yapaca�� i�lemleri nesnelerle yapt�rarak tan�mlad�m. 
	bolme = ks1 / ks2;     //  Operat�rlerin yapaca�� i�lemleri nesnelerle yapt�rarak tan�mlad�m.                                 

	cout << endl;

	int secim;
	int n;
	cout << "Kac islem yapacaksiniz? ";
	cin >> n;

	for (int i = 0; i < n; i++)  // Kullan�c�n�n yapaca�� her i�lemde men�n�n g�z�kmesi i�in d�ng� kurdum.
	{
		cout << "MENU: " << endl;
		cout << "TOPLAMA ISLEMI ICIN 1'E BASINIZ: " << endl;
		cout << "CIKARMA ISLEMI ICIN 2'YE BASINIZ: " << endl;
		cout << "CARPMA ISLEMI ICIN 3'E BASINIZ: " << endl;
		cout << "BOLME ISLEMI ICIN 4'E BASINIZ: " << endl;
		cout << "+= ISLEMI ICIN 5'E BASINIZ: " << endl;
		cout << "-= ISLEMI ICIN 6'YA BASINIZ:" << endl;
		cout << "*= ISLEMI ICIN 7'YE BASINIZ:" << endl;
		cout << "/= ISLEMI ICIN 8'E BASINIZ:" << endl;
		cout << "KUTUPSAL GOSTERIM ICIN 9'A BASINIZ:" << endl;
		cin >> secim;
		cout << endl;

		switch (secim)
		{
		case 1:
			cout << "TOPLAM = ";
			toplama.sayiYazdirma();
			break;

		case 2:
			cout << "FARK = ";
			cikarma.sayiYazdirma();
			break;

		case 3:
			cout << "CARPIM = ";
			carpma.sayiYazdirma();
			break;

		case 4:
			cout << "BOLUM = ";
			bolme.sayiYazdirma();
			break;

		case 5:
			ks1 += ks2;
			cout << "TOPLAYIP EKLEME ISLEMI = ";
			ks1.sayiYazdirma();
			break;

		case 6:
			ks1 -= ks2;
			cout << "CIKARIP EKLEME ISLEMI = ";
			ks1.sayiYazdirma();
			break;

		case 7:
			ks1 *= ks2;
			cout << "CARPIP EKLEME ISLEMI = ";
			ks1.sayiYazdirma();
			break;

		case 8:
			ks1 /= ks2;
			cout << "BOLUP EKLEME ISLEMI = ";
			ks1.sayiYazdirma();
			break;

		case 9:
			cout << "1. sayi icin degerler: " << endl;
		 ks1.KutupsalGosterim();
		 cout << endl;
		 cout << "2. sayi icin degerler: " << endl;
		 ks2.KutupsalGosterim();
		 cout << endl;
		 break;

		}
	}

	return 0;
}