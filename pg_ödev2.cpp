


#include <iostream>
#include <cmath>
using namespace std;

class karmasikSayi  // Karmaþýk sayýlar sýnýfý oluþturdum.
{
public:
	double reel;
	double sanal;

	void sayiIsteme()  // Kullanýcýdan ekrana karmaþýk sayý girmesi için bir fonksiyon yazdým.
	{
		cout << "Lutfen sayinin reel kismini giriniz: ";
		cin >> reel;
		cout << "Lutfen sayinin sanal kismini giriniz: ";
		cin >> sanal;
	}

	void sayiYazdirma()  // Kullanýcýnýn girdiði karmaþýk sayýyý ekrana yazdýran fonksiyon yazdým.
	{
		if (sanal < 0)
		{
			cout << "Karmasik Sayi: " << reel << " " << sanal << "i" << endl;
		}
		else
			cout << "Karmasik Sayi: " << reel << "+" << sanal << "i" << endl;
	}

	karmasikSayi operator+(karmasikSayi ks2)  //     + overloading operatörü
	{
		karmasikSayi ks3{};
		ks3.reel = reel + ks2.reel;
		ks3.sanal = sanal + ks2.sanal;
		return ks3;
	}

	karmasikSayi operator-(karmasikSayi ks2)  //    - overloading operatörü
	{
		karmasikSayi ks3{};
		ks3.reel = reel - ks2.reel;
		ks3.sanal = sanal - ks2.sanal;
		return ks3;
	}

	karmasikSayi operator*(karmasikSayi ks2)  //    * overloading operatörü
	{
		karmasikSayi ks3{};
		ks3.reel = reel * ks2.reel - sanal * ks2.sanal;
		ks3.sanal = reel * ks2.sanal + sanal * ks2.reel;
		return ks3;
	}

	karmasikSayi operator/(karmasikSayi ks2)  //    / overloading operatörü
	{
		karmasikSayi ks3{};
		ks3.reel = (reel * ks2.reel - sanal * (-1 * ks2.sanal)) / (ks2.reel * ks2.reel) + (ks2.sanal + ks2.sanal);
		ks3.sanal = (reel * (-1 * ks2.sanal) + sanal * ks2.reel) / (ks2.reel * ks2.reel) + (ks2.sanal + ks2.sanal);
		return ks3;
	}

	karmasikSayi operator+=(karmasikSayi ks2)  //     += overloading operatörü
	{
		reel += ks2.reel;
		sanal += ks2.sanal;
		cout << reel << " " << sanal << "i" << endl;
		return *this;
	}

	karmasikSayi operator-=(karmasikSayi ks2)  //     -= overloading operatörü
	{
		reel -= ks2.reel;
		sanal -= ks2.sanal;
		return *this;
	}

	karmasikSayi operator*=(karmasikSayi ks2)  //     *= overloading operatörü
	{
		reel = ks2.reel - sanal * ks2.sanal;
		sanal = ks2.sanal + sanal * ks2.reel;
		return *this;
	}

	karmasikSayi operator/=(karmasikSayi ks2)  //       /= overloading operatörü
	{
		reel = (reel * ks2.reel - sanal * (-1 * ks2.sanal)) / (ks2.reel * ks2.reel) + (ks2.sanal * ks2.sanal);
		sanal = (reel * (-1 * ks2.sanal) + sanal * ks2.reel) / (ks2.reel * ks2.reel) + (ks2.sanal * ks2.sanal);
		return *this;
	}

	void KutupsalGosterim()  //    Kutupsal gösterim için fonksiyon yazdým
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
	karmasikSayi ks1{};  // karmasikSayi sýnýfýndan ks1 nesnesi tanýmladým.
	karmasikSayi ks2{};  // karmasikSayi sýnýfýndan ks2 nesnesi tanýmladým.

	cout << "Lutfen birinci karmasik sayiyi giriniz: " << endl;  // sýnýf içerisinde yazdýðým fonksiyonlarý mainin içinde çaðýrdým.
	cout << endl;
	ks1.sayiIsteme();
	ks1.sayiYazdirma();
	cout << endl;

	cout << "Lutfen ikinci karmasik sayiyi giriniz: " << endl;  // sýnýf içerisinde yazdýðým fonksiyonlarý mainin içinde çaðýrdým.
	cout << endl;
	ks2.sayiIsteme();
	ks2.sayiYazdirma();

	karmasikSayi toplama{}, cikarma{}, carpma{}, bolme{};  // Operatör nesnelerini tanýmladým.

	toplama = ks1 + ks2;   //  Operatörlerin yapacaðý iþlemleri nesnelerle yaptýrarak tanýmladým. 
	cikarma = ks1 - ks2;   //  Operatörlerin yapacaðý iþlemleri nesnelerle yaptýrarak tanýmladým. 
	carpma = ks1 * ks2;    //  Operatörlerin yapacaðý iþlemleri nesnelerle yaptýrarak tanýmladým. 
	bolme = ks1 / ks2;     //  Operatörlerin yapacaðý iþlemleri nesnelerle yaptýrarak tanýmladým.                                 

	cout << endl;

	int secim;
	int n;
	cout << "Kac islem yapacaksiniz? ";
	cin >> n;

	for (int i = 0; i < n; i++)  // Kullanýcýnýn yapacaðý her iþlemde menünün gözükmesi için döngü kurdum.
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