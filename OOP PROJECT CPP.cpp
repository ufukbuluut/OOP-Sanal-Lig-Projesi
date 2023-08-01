#include <iostream>

#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<stdlib.h>
using namespace std;


#pragma region players
class players
{

public:
	players();
	~players();
	void setoyuncuIsim();
	string getoyuncuisim() { return oyuncuisim; }
	void setoyuncuSoyisim();
	string getoyuncuSoyisim() { return oyuncusoyisim; }
	void setoyuncuBolgesi(string position);
	void setoyuncuYas();
	void setoyuncuForma();
	void setoyuncuPerformans();
	void performansDuzenle(int overall);
	void oyuncuOlustur();
	void displayOyuncu();
	int oyuncuyas, oyuncuperformans;
	string oyuncuisim, oyuncusoyisim, oyuncubolgesi;
private:

	int  oyuncuforma;

};

class Kaleci : public players //Oyuncuların mevkisi player sınıfından miras alınarak oluşturulmuştur
{
public:
	Kaleci();
	void displayOyuncu();
};

class Defans : public players
{
public:
	Defans();
	void displayOyuncu();
};

class Ortasaha : public players
{
public:
	Ortasaha();
	void displayOyuncu();
};
class Forvet : public players
{
public:
	Forvet();
	void displayOyuncu();
};
players::~players()
{

}
players::players()
{

	setoyuncuIsim();
	setoyuncuSoyisim();
	setoyuncuYas();
	setoyuncuForma();
	setoyuncuPerformans();


}
void players::displayOyuncu()
{
	cout << oyuncuisim << " " << oyuncusoyisim << endl;
	cout << "AGE:" << oyuncuyas << endl;
	cout << "UNIFORM NUMBER:" << oyuncuforma << endl;
	cout << "OVERALL:" << oyuncuperformans << endl;

}

void players::setoyuncuIsim()
{
	string line;
	vector<string>Ad;
	//srand(time(NULL));
	ifstream isimOkuma;
	isimOkuma.open("C:\\Users\\ufukb\\Desktop\\OOP Project2\\Ad.txt");

	int totalline = 0;
	while (getline(isimOkuma, line))
	{
		totalline++;
		Ad.push_back(line);
	}
	int random_number = rand() % totalline;
	oyuncuisim = Ad[random_number];
	isimOkuma.close();
}
void players::setoyuncuSoyisim()
{
	string line;
	vector<string>Soyad;
	//srand(time(NULL));
	ifstream soyisimOkuma;
	soyisimOkuma.open("C:\\Users\\ufukb\\Desktop\\OOP Project2\\Soyad.txt");

	int totalline = 0;
	while (getline(soyisimOkuma, line))
	{
		totalline++;
		Soyad.push_back(line);
	}
	int random_number = rand() % totalline;
	oyuncusoyisim = Soyad[random_number];
	soyisimOkuma.close();
}

void players::setoyuncuYas()
{
	int enFazla = 36, enAz = 18;
	oyuncuyas = rand() % (enFazla - enAz + 1) + enAz;
}
void players::setoyuncuForma()
{
	int enFazla = 99, enAz = 1;
	oyuncuforma = rand() % (enFazla - enAz + 1) + enAz;
}
void players::setoyuncuPerformans()
{
	int enFazla = 100, enAz = 30;
	oyuncuperformans = rand() % (enFazla - enAz + 1) + enAz;
}
void players::performansDuzenle(int overall)
{
	oyuncuperformans = overall;
}
Kaleci::Kaleci() :players()
{

}

void Kaleci::displayOyuncu()
{
	players::displayOyuncu();
	cout << "POSITION:GOALKEEPER" << endl;
	cout << "-------------------------" << endl;
}

Defans::Defans() :players()
{

}

void Defans::displayOyuncu()
{
	players::displayOyuncu();
	cout << "POSITION:DEFANCE" << endl;
	cout << "-------------------------" << endl;
}

Ortasaha::Ortasaha() :players()
{

}

void Ortasaha::displayOyuncu()
{
	players::displayOyuncu();
	cout << "POSITION:MIDFIELDER" << endl;
	cout << "-------------------------" << endl;
}

Forvet::Forvet() :players()
{

}
void Forvet::displayOyuncu()
{
	players::displayOyuncu();
	cout << "POSITION:FORWARD" << endl;
	cout << "-------------------------" << endl;
}
#pragma endregion

#pragma region Teams
class Teams
{
public:
	Teams();
	~Teams();
	void display11();
	void setKadro(int d = 4, int o = 4, int f = 2);
	void yasKontrol();
	void performansKontrol();
	void setteamYasOrt();
	void setteamPerOrt();
	string teamName;
	string teamTD;

	int teamPerOrt, teamYasOrt;
	std::vector<Kaleci>Kalecilerim;
	std::vector<Defans> Defanslarim;
	std::vector<Ortasaha> Ortasahalarim;
	std::vector<Forvet> Forvetlerim;
	void yaslandir();
	void genclestir();
	void performplus();
	int d = 4; int o = 4; int f = 2;
	int kaleciPerOrt, defansPerOrt, ortasPerOrt, forvetPerOrt;
	int Score;
	int DPO=0, OSPO=0, FPO=0;
	int galibiyetSayisi = 0, beraberlikSayisi = 0, maglubiyetSayisi = 0;
	int puan=0;
	int atilangol=0, yenilengol=0;
protected:

private:
	//int takimOrtalamaYas,takimOrtalamaPerf;
	int  kaleciYasOrt, defansYasOrt, ortasYasOrt, forvetYasOrt;

};
Teams::Teams()
{
	setKadro();


	//yasKontrol();


}

Teams::~Teams()
{
}

void Teams::display11()
{
	for (int i = 0; i < 4; i++)
	{
		Defanslarim[i].displayOyuncu();
	}
	for (int i = 0; i < 4; i++)
	{
		Ortasahalarim[i].displayOyuncu();
	}
	for (int i = 0; i < 2; i++)
	{
		Forvetlerim[i].displayOyuncu();
	}
}

void Teams::setKadro(int d, int o, int f)
{

	for (int i = 0; i < 1; i++)
	{

		Kaleci kaleobj;
		Kalecilerim.push_back(kaleobj);
		kaleciYasOrt = Kalecilerim[i].oyuncuyas;
		kaleciPerOrt = kaleciPerOrt + Kalecilerim[i].oyuncuperformans;
	}
	for (int i = 0; i < d; i++)
	{

		Defans defobj;
		Defanslarim.push_back(defobj);
		defansYasOrt = Defanslarim[i].oyuncuyas;
		defansPerOrt = (defansPerOrt + Defanslarim[i].oyuncuperformans);
	}
	for (int i = 0; i < o; i++)
	{
		Ortasaha ortobj;
		Ortasahalarim.push_back(ortobj);
		ortasYasOrt = Ortasahalarim[i].oyuncuyas;
		ortasPerOrt = (ortasPerOrt + Ortasahalarim[i].oyuncuperformans);
	}
	for (int i = 0; i < f; i++)
	{
		Forvet forobj;
		Forvetlerim.push_back(forobj);
		forvetYasOrt = Forvetlerim[i].oyuncuyas;
		forvetPerOrt = (forvetPerOrt + Forvetlerim[i].oyuncuperformans);
	}
	setteamYasOrt();
	if (teamYasOrt < 25 || teamYasOrt>32)
	{
		yasKontrol();

	}
	setteamPerOrt();
	if (teamPerOrt < 60)
	{
		performansKontrol();
	}


}

void Teams::yasKontrol()
{
	if (!(teamYasOrt > 25))
	{
		yaslandir();

	}
	else if (!(teamYasOrt < 32))
	{
		genclestir();
		//setteamYasOrt();
	}

	setteamYasOrt();

}

void Teams::performansKontrol()
{
	if (!(teamPerOrt > 60))
	{
		performplus();
	}
	//setteamPerOrt();
}

void Teams::setteamYasOrt() //Takım set edilirken yas kontrolü gerçekleştiriyor.
{
	teamYasOrt = (kaleciYasOrt + defansYasOrt + ortasYasOrt + forvetYasOrt) / 4;
}

void Teams::setteamPerOrt()
{
	teamPerOrt = (kaleciPerOrt + defansPerOrt + ortasPerOrt + forvetPerOrt) / 11;
}

void Teams::yaslandir()
{
	forvetYasOrt += 10;
	defansYasOrt += 9;
	kaleciYasOrt += 5;
}

void Teams::genclestir()
{
	forvetYasOrt -= 10;
	defansYasOrt -= 9;
	kaleciYasOrt -= 5;
}

void Teams::performplus()
{
	for (int i = 0; i < f; i++)
	{
		Forvetlerim[i].oyuncuperformans = Forvetlerim[i].oyuncuperformans + 15;
	}
	for (int i = 0; i < o; i++)
	{
		Ortasahalarim[i].oyuncuperformans = Ortasahalarim[i].oyuncuperformans + 15;
	}
	for (int i = 0; i < d; i++)
	{
		Defanslarim[i].oyuncuperformans = Defanslarim[i].oyuncuperformans + 15;
	}
	Kalecilerim[0].oyuncuperformans = Kalecilerim[0].oyuncuperformans + 15;
	teamPerOrt += 15;


}

#pragma endregion

#pragma region Match
class Match
{
public:
public:
	Match(int ID);
	~Match();
	std::vector<Teams>MacTakimlari;
	int macID;
	string macName;
	string macName1;
	string macName2;
	string takimOzellik1;
	string takimOzellik2;
	void randskorUret();
	void setDPO();
	void setOSPO();
	void setFPO();


};
Match::Match(int ID)
{
	macID = ID;
}

Match::~Match()
{
}

void Match::setDPO()
{
	MacTakimlari[0].DPO = MacTakimlari[0].defansPerOrt / 4;
	MacTakimlari[1].DPO = MacTakimlari[1].defansPerOrt / 4;


}

void Match::setOSPO()
{
	MacTakimlari[0].OSPO = MacTakimlari[0].ortasPerOrt / 4;
	MacTakimlari[1].OSPO = MacTakimlari[1].ortasPerOrt / 4;
}

void Match::setFPO()
{
	MacTakimlari[0].FPO = MacTakimlari[0].forvetPerOrt / 4;
	MacTakimlari[1].FPO = MacTakimlari[1].forvetPerOrt / 4;
}

void Match::randskorUret()
{
	int enFazla = 6, enAz = 0;
	MacTakimlari[0].Score = rand() % (enFazla - enAz + 1) + enAz;
	MacTakimlari[1].Score = rand() % (enFazla - enAz + 1) + enAz;

}



#pragma endregion

#pragma region Lig
class Lig
{
public:
	Lig();
	~Lig();
	std::vector< Teams >Takimlar;
	std::vector<Match>Maclar;
	void printTeams();
	void displayTeamfeatures(int takimkodu);

	void fiksturGoruntule();
	void takimfiksturuGoruntule(int takimkodu);
	void takimlariKarsilastir(int ID);


	void tumTakimlarinSkorlariniGoster();
	void birTakiminSkorlariniGoster(int takimkodu);
	void sanalLigPuanDurumu();

private:
	void macOynat();
	void fiksturBelirle();
	void mevkiOrtalamahesapla();
	void GBMhesapla(int takimkodu); //galibiyet beraberlik mağlubiyet sayısını belirler
};


Lig::Lig()
{
	cout << "LIG OLUSTURLUYOR..." << endl;
	int temp = 0;
	string teknik_adi;
	string takim_adi;
	ifstream takimOkuma;
	string line;
	char delimiter = '-';
	char delimiter2 = '\n';
	takimOkuma.open("C:\\Users\\ufukb\\Desktop\\OOP Project2\\Takimlar.txt");
	for (int i = 0; i < 20; i++)
	{

		getline(takimOkuma, line, delimiter);
		takim_adi = line;
		getline(takimOkuma, line, delimiter2);
		teknik_adi = line;


		Teams teamsobj;
		teamsobj.teamName = takim_adi;
		teamsobj.teamTD = teknik_adi;
		/*teamsobj.teamNameKısa1 = takim_adi[0];
		teamsobj.teamNameKısa1 = takim_adi[1];
		teamsobj.teamNameKısa1 = takim_adi[2];*/
		Takimlar.push_back(teamsobj);




		temp++;

	}
	takimOkuma.close();
	fiksturBelirle();
	macOynat();


}

Lig::~Lig()
{
	cout << "Lig dest worked" << endl;
}

void Lig::printTeams()
{
	for (int i = 0; i < 20; i++)
	{
		cout << (i + 1) << "-" << Takimlar[i].teamName << endl;

	}

}



void Lig::displayTeamfeatures(int takimkodu)
{
	cout << "TAKIM ADI:" << Takimlar[takimkodu].teamName << endl;
	cout << "TEKNIK DIREKTOR ADI:" << Takimlar[takimkodu].teamTD << endl;
	cout << "TAKIM YAS ORTALAMASI:" << Takimlar[takimkodu].teamYasOrt << endl;
	cout << "TAKIM PERFORMANS ORTALAMASI:" << Takimlar[takimkodu].teamPerOrt << endl;
	for (int i = 0; i < 1; i++)
	{
		Takimlar[takimkodu].Kalecilerim[i].displayOyuncu();
	}
	for (int i = 0; i < 4; i++)
	{
		Takimlar[takimkodu].Defanslarim[i].displayOyuncu();
	}
	for (int i = 0; i < 4; i++)
	{
		Takimlar[takimkodu].Ortasahalarim[i].displayOyuncu();
	}
	for (int i = 0; i < 2; i++)
	{
		Takimlar[takimkodu].Forvetlerim[i].displayOyuncu();
	}

}




void Lig::fiksturBelirle()
{
	int macno = 1;
	for (int j = 0; j < Takimlar.size(); j++)
	{

		for (int i = (j + 1); i < Takimlar.size(); i++)
		{


			Match macobj(macno);

			macobj.macName1 = Takimlar[j].teamName;
			macobj.macName2 = Takimlar[i].teamName;
			macobj.MacTakimlari.push_back(Takimlar[i]);
			macobj.MacTakimlari.push_back(Takimlar[j]);
			Maclar.push_back(macobj);
			macno++;

		}


	}


}

void Lig::fiksturGoruntule() //Bütün Fikstürü görüntülemek için bu fonksiyonu kullanınız
{
	for (int i = 0; i < Maclar.size(); i++)
	{
		cout << "Mac ID:" << Maclar[i].macID << " " << Maclar[i].MacTakimlari[0].teamName << "--" << Maclar[2].MacTakimlari[1].teamName << endl;
	}




}

void Lig::takimfiksturuGoruntule(int takimkodu) //İstenilen bir takımın fikstürünü görmek için bu fonksiyonu Kullanınız
{
	int a = 1;
	for (int i = 0; i < Maclar.size(); i++)
	{
		if (Maclar[i].MacTakimlari[0].teamName == Takimlar[takimkodu].teamName || Maclar[i].MacTakimlari[1].teamName == Takimlar[takimkodu].teamName)
		{

			cout << Takimlar[takimkodu].teamName << a << ". HAFTA MACI" << endl;
			cout << "Mac ID:" << Maclar[i].macID << " " << Maclar[i].MacTakimlari[0].teamName << "--" << Maclar[2].MacTakimlari[1].teamName << endl;
			cout << "----------------------------------------------" << endl;
			a++;
		}
	}


}

void Lig::takimlariKarsilastir(int ID) //Ödevin 4. kısmında istenilen işlemi yapan method
{
	for (int i = 0; i < Maclar.size(); i++)
	{
		if (i == ID)
		{
			cout << "----------------------------------" << endl;
			cout << "Mac ID:" << Maclar[ID - 1].macID << " " << Maclar[ID - 1].MacTakimlari[0].teamName << "<--->" << Maclar[ID - 1].MacTakimlari[1].teamName << endl;
			cout << Maclar[ID - 1].MacTakimlari[0].teamName << ":" << "Takim Ortalama Performansı:" << Maclar[ID - 1].MacTakimlari[0].teamPerOrt << endl;
			cout << Maclar[ID - 1].MacTakimlari[1].teamName << ":" << "Takim Ortalama Performansı:" << Maclar[ID - 1].MacTakimlari[1].teamPerOrt << endl;
			float UB;
			float A;
			float B;
			A = Maclar[ID - 1].MacTakimlari[0].teamPerOrt;
			B = Maclar[ID - 1].MacTakimlari[1].teamPerOrt;
			UB = (A / (A + B)) * (100);
			cout << Maclar[ID - 1].MacTakimlari[0].teamName << " " << "Takimi Kazanma Orani:" << "%" << UB << "   " << Maclar[ID - 1].MacTakimlari[1].teamName << " " << "Takimi Kazanma Orani:" << "%" << (100 - UB) << endl;
			//Maclar[ID - 1].MacTakimlari[0].display11(); Maclar[ID - 1].MacTakimlari[1].display11();
			cout << Maclar[ID - 1].MacTakimlari[0].teamName << " KADROSU" << "\t" << Maclar[ID - 1].MacTakimlari[1].teamName << " KADROSU" << endl;
			cout << "----------------------------------" << endl;
			cout << "POSITION:GOALKEEPER" << endl;
			for (int i = 0; i < 1; i++)
			{
				cout << Maclar[ID - 1].MacTakimlari[0].Kalecilerim[i].oyuncuisim << " " << Maclar[ID - 1].MacTakimlari[0].Kalecilerim[i].oyuncusoyisim << "<-------->" << Maclar[ID - 1].MacTakimlari[1].Kalecilerim[i].oyuncuisim << " " << Maclar[ID - 1].MacTakimlari[1].Kalecilerim[i].oyuncusoyisim << endl;

			}
			cout << "----------------------------------" << endl;
			cout << "POSITION:DEFANCE" << endl;
			for (int i = 0; i < 4; i++)
			{
				cout << Maclar[ID - 1].MacTakimlari[0].Defanslarim[i].oyuncuisim << " " << Maclar[ID - 1].MacTakimlari[0].Defanslarim[i].oyuncusoyisim << "<-------->" << Maclar[ID - 1].MacTakimlari[1].Defanslarim[i].oyuncuisim << " " << Maclar[ID - 1].MacTakimlari[1].Defanslarim[i].oyuncusoyisim << endl;
			}
			cout << "----------------------------------" << endl;
			cout << "POSITION:MIDFIELDER" << endl;
			for (int i = 0; i < 4; i++)
			{
				cout << Maclar[ID - 1].MacTakimlari[0].Ortasahalarim[i].oyuncuisim << " " << Maclar[ID - 1].MacTakimlari[0].Ortasahalarim[i].oyuncusoyisim << "<-------->" << Maclar[ID - 1].MacTakimlari[1].Ortasahalarim[i].oyuncuisim << " " << Maclar[ID - 1].MacTakimlari[1].Ortasahalarim[i].oyuncusoyisim << endl;
			}
			cout << "----------------------------------" << endl;
			cout << "POSITION:FORWARD" << endl;
			for (int i = 0; i < 2; i++)
			{
				cout << Maclar[ID - 1].MacTakimlari[0].Forvetlerim[i].oyuncuisim << " " << Maclar[ID - 1].MacTakimlari[0].Forvetlerim[i].oyuncusoyisim << "<-------->" << Maclar[ID - 1].MacTakimlari[1].Forvetlerim[i].oyuncuisim << " " << Maclar[ID - 1].MacTakimlari[1].Forvetlerim[i].oyuncusoyisim << endl;
			}
			cout << "----------------------------------" << endl;


		}
	}



}

void Lig::mevkiOrtalamahesapla()
{
	for (int i = 0; i < Maclar.size(); i++)
	{
		Maclar[i].setDPO();
		cout << Maclar[i].MacTakimlari[0].teamName << "DPO:" << Maclar[i].MacTakimlari[0].DPO << Maclar[i].MacTakimlari[1].teamName << "DPO:" << Maclar[i].MacTakimlari[1].DPO << endl;
		Maclar[i].setOSPO();
		cout << Maclar[i].MacTakimlari[0].teamName << "OSPO:" << Maclar[i].MacTakimlari[0].OSPO << Maclar[i].MacTakimlari[1].teamName << "OSPO:" << Maclar[i].MacTakimlari[1].OSPO << endl;
		Maclar[i].setFPO();
		cout << Maclar[i].MacTakimlari[0].teamName << "FPO:" << Maclar[i].MacTakimlari[0].FPO << Maclar[i].MacTakimlari[1].teamName << "FPO:" << Maclar[i].MacTakimlari[1].FPO << endl;
	}

}

void Lig::macOynat()
{
	for (int i = 0; i < Maclar.size(); i++)
	{
		Maclar[i].randskorUret();

		cout << "\n" << endl;

		if (Maclar[i].MacTakimlari[0].FPO > Maclar[i].MacTakimlari[1].FPO)
		{
			Maclar[i].MacTakimlari[0].Score++;
			cout << Maclar[i].MacTakimlari[0].FPO << "--------" << endl;
		}
		if (Maclar[i].MacTakimlari[0].FPO < Maclar[i].MacTakimlari[1].FPO)
		{
			Maclar[i].MacTakimlari[1].Score++;
		}
		if (Maclar[i].MacTakimlari[0].DPO > Maclar[i].MacTakimlari[1].DPO)
		{
			Maclar[i].MacTakimlari[1].Score--;
		}
		if (Maclar[i].MacTakimlari[0].DPO < Maclar[i].MacTakimlari[1].DPO)
		{
			Maclar[i].MacTakimlari[0].Score--;
		}
		if (Maclar[i].MacTakimlari[0].OSPO > Maclar[i].MacTakimlari[1].OSPO)
		{
			Maclar[i].MacTakimlari[0].Score++;
			Maclar[i].MacTakimlari[1].Score--;

		}
		if (Maclar[i].MacTakimlari[0].OSPO < Maclar[i].MacTakimlari[1].OSPO)
		{
			Maclar[i].MacTakimlari[1].Score++;
			Maclar[i].MacTakimlari[0].Score--;

		}
		if (Maclar[i].MacTakimlari[0].teamPerOrt > Maclar[i].MacTakimlari[1].teamPerOrt)
		{
			Maclar[i].MacTakimlari[0].Score++;

		}
		if (Maclar[i].MacTakimlari[0].teamPerOrt < Maclar[i].MacTakimlari[1].teamPerOrt)
		{
			Maclar[i].MacTakimlari[1].Score++;

		}


	}
}
void Lig::tumTakimlarinSkorlariniGoster()
{
	for (int i = 0; i < Maclar.size(); i++)
	{
		cout << Maclar[i].MacTakimlari[0].teamName << ":" << Maclar[i].MacTakimlari[0].Score << "--" << Maclar[i].MacTakimlari[1].teamName << ":" << Maclar[i].MacTakimlari[1].Score << endl;
		cout << "\n" << endl;
	}
}

void Lig::birTakiminSkorlariniGoster(int takimkodu)
{
	cout << Takimlar[takimkodu].teamName << " TAKIMI MAC SKORLARI" << endl;
	cout << "-----------------------------" << endl;
	for (int i = 0; i < Maclar.size(); i++)
	{
		if (Maclar[i].MacTakimlari[0].teamName == Takimlar[takimkodu].teamName || Maclar[i].MacTakimlari[1].teamName == Takimlar[takimkodu].teamName)
		{
			cout << Maclar[i].MacTakimlari[0].teamName << ":" << Maclar[i].MacTakimlari[0].Score << "--" << Maclar[i].MacTakimlari[1].teamName << ":" << Maclar[i].MacTakimlari[1].Score << endl;
		}
	}

}

void Lig::sanalLigPuanDurumu()
{

	for (int i = 0; i < Takimlar.size(); i++)
	{
		GBMhesapla(i);
	}
	cout << "TAKIM ADI" << " " << "OYNADIGI MAC" << " " << "GALIBIYET SAYISI" << " " << "BERABERLIK SAYISI" << " " << "MAGLUBIYET SAYISI" << " " << "ATILAN GOL" << "      " << "YENILEN GOL" << "      " << "AVERAJ" << "     " << "PUAN" << endl;
	cout << "---------" << " " << "------------" << " " << "----------------" << " " << "-----------------" << " " << "-----------------" << " " << "----------" << "      " << "-----------" << "      " << "------" << "     " << "----" << endl;
	for (int i = 0; i < Takimlar.size(); i++)
	{
		cout << Takimlar[i].teamName << "\t" << Takimlar.size() - 1 << "\t\t" << Takimlar[i].galibiyetSayisi << "\t\t" << Takimlar[i].beraberlikSayisi << "\t\t" << Takimlar[i].maglubiyetSayisi << "\t\t" << Takimlar[i].atilangol << "\t\t" << Takimlar[i].yenilengol << "\t\t" << (Takimlar[i].atilangol - Takimlar[i].yenilengol) << "\t" << Takimlar[i].puan << endl;
	}
	//cout << Takimlar[i].teamName << "\t  " << Takimlar.size()-1 << "\t" << Takimlar[i].galibiyetSayısı << "\t" << Takimlar[i].beraberlikSayısı << "\t" << Takimlar[i].maglubiyetSayısı << "\t" << Takimlar[i].atilangol << "\t" << Takimlar[i].yenilengol << "\t" << (Takimlar[i].atilangol- Takimlar[i].yenilengol) << "\t" << Takimlar[i].puan << endl;
	//cout <<Takimlar[0].teamName <<Takimlar[0].galibiyetSayısı << endl;
	//cout << Takimlar[0].teamName << Takimlar[0].beraberlikSayısı << endl;
	//cout << Takimlar[0].teamName << Takimlar[0].maglubiyetSayısı << endl;
	//cout << Takimlar[0].teamName <<"puan:" << Takimlar[0].puan << endl;
	//cout << Takimlar[0].teamName << "atılan:" << Takimlar[0].atilangol << endl;
	//cout << Takimlar[0].teamName << "yenilen" << Takimlar[0].yenilengol << endl;
	//
}

void Lig::GBMhesapla(int takimkodu)
{
	for (int i = 0; i < Maclar.size(); i++)
	{
		if (Maclar[i].MacTakimlari[0].teamName == Takimlar[takimkodu].teamName)
		{
			if (Maclar[i].MacTakimlari[0].Score > Maclar[i].MacTakimlari[1].Score)
			{
				Takimlar[takimkodu].galibiyetSayisi++;
				Takimlar[takimkodu].puan = Takimlar[takimkodu].puan +3;

			}
			if (Maclar[i].MacTakimlari[0].Score < Maclar[i].MacTakimlari[1].Score)
			{
				Takimlar[takimkodu].maglubiyetSayisi++;

			}
			if (Maclar[i].MacTakimlari[0].Score == Maclar[i].MacTakimlari[1].Score)
			{
				Takimlar[takimkodu].beraberlikSayisi++;
				Takimlar[takimkodu].puan = Takimlar[takimkodu].puan +1;

			}
			Takimlar[takimkodu].atilangol += Maclar[i].MacTakimlari[0].Score;
			Takimlar[takimkodu].yenilengol += Maclar[i].MacTakimlari[1].Score;
		}
		if (Maclar[i].MacTakimlari[1].teamName == Takimlar[takimkodu].teamName)
		{
			if (Maclar[i].MacTakimlari[0].Score > Maclar[i].MacTakimlari[1].Score)
			{
				Takimlar[takimkodu].maglubiyetSayisi++;


			}
			if (Maclar[i].MacTakimlari[0].Score < Maclar[i].MacTakimlari[1].Score)
			{
				Takimlar[takimkodu].galibiyetSayisi++;
				Takimlar[takimkodu].puan = Takimlar[takimkodu].puan +3;

			}
			if (Maclar[i].MacTakimlari[0].Score == Maclar[i].MacTakimlari[1].Score)
			{
				Takimlar[takimkodu].beraberlikSayisi++;
				Takimlar[takimkodu].puan = Takimlar[takimkodu].puan +1;

			}
			Takimlar[takimkodu].atilangol += Maclar[i].MacTakimlari[1].Score;
			Takimlar[takimkodu].yenilengol += Maclar[i].MacTakimlari[0].Score;
		}
	}


}

#pragma endregion

int main()
{
	//UFUK BULUT(394811)



	//->takimkodu isteyen methodları çağırmak için takim kodu yerine Takim indisini yazınız.
	// Örneğin superlig.displayTeamfeatures(2); şeklinde çağırnız.
	//->KOD Takimlar.txt deki sıralamada 0'dan başlayarak indisleri oluşturur.
	//takimlariKarsilastir(macID); methodunu macID ile çağırınız.


	Lig superlig;
	superlig.printTeams();
	superlig.displayTeamfeatures(2);
	superlig.fiksturGoruntule();
	superlig.takimfiksturuGoruntule(2);
	superlig.tumTakimlarinSkorlariniGoster();
	superlig.takimlariKarsilastir(100);
	superlig.birTakiminSkorlariniGoster(2);
	superlig.sanalLigPuanDurumu();


}










