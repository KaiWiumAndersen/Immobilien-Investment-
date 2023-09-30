#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <fstream>
#include <filesystem>
#include <iomanip>
using namespace std;

class InvestmentImmobilien
{
private:
	string ImmobilienArt{ "kleine Wohnung; große Wohnung; kleines Haus; großes Haus; Mehrfamilien Haus; Haushälfte" };
	string ImmobilienAdresse;
	string ImmobilienZustand;
	double ImmobilienWert;
	double ZimmerAnzahl;
	double Wohnfläche;
	double Grundstücksfläche;
	string ZimmerArt{ "Küche, Badezimmer, Schlafzimmer" };
	string Lage;
	double InvestmentGeld;
public:
	vector<ifstream>Feld1;
	void Instanz(const string&, const string&, const string&, const string&, const string&, const double&, const double&, const double&, const double&, const double&);
	void Speicherung();
	void PasswortSpeicherortFunktion();
	void Ausgabe();
	InvestmentImmobilien(const InvestmentImmobilien&);
	InvestmentImmobilien& operator = (const InvestmentImmobilien&);
};

void InvestmentImmobilien::Instanz(const string& ImmoArt, const string& ImmoAdresse, const string& ImmoZustand, const string& ZArt, const string& L, const double& ImmoWert, const double& ZAnzahl, const double& Wfläche, const double& GFläche, const double& InvestGeld) { 
	ImmobilienArt = ImmoArt; 
	ImmobilienAdresse = ImmoAdresse; 
	ImmobilienZustand = ImmoZustand;
	ZimmerArt = ZArt;
	ZimmerAnzahl = ZAnzahl;
	Lage = L;
	ImmobilienWert = ImmoWert;
	Wohnfläche = Wfläche;
	Grundstücksfläche = GFläche;
	InvestmentGeld = InvestGeld; 
}

InvestmentImmobilien::InvestmentImmobilien(const InvestmentImmobilien& II) {
	ImmobilienArt = II.ImmobilienArt;
	ImmobilienAdresse = II.ImmobilienAdresse;
	ImmobilienZustand = II.ImmobilienZustand;
	ZimmerArt = II.ZimmerArt;
	ZimmerAnzahl = II.ZimmerAnzahl;
	Lage = II.Lage;
	ImmobilienWert = II.ImmobilienWert;
	Wohnfläche = II.Wohnfläche;
	Grundstücksfläche = II.Grundstücksfläche;
	InvestmentGeld = II.InvestmentGeld;
	Feld1 = II.Feld1;
}

InvestmentImmobilien& InvestmentImmobilien::operator = (const InvestmentImmobilien& II) {
	if (this == &II) {
		return *this;
	}

	ImmobilienArt = II.ImmobilienArt;
	ImmobilienAdresse = II.ImmobilienAdresse;
	ImmobilienZustand = II.ImmobilienZustand;
	ZimmerArt = II.ZimmerArt;
	ZimmerAnzahl = II.ZimmerAnzahl;
	Lage = II.Lage;
	ImmobilienWert = II.ImmobilienWert;
	Wohnfläche = II.Wohnfläche;
	Grundstücksfläche = II.Grundstücksfläche;
	InvestmentGeld = II.InvestmentGeld;
	Feld1 = II.Feld1;


	return *this; 
}

void InvestmentImmobilien::Speicherung() {
	ofstream DateiImmobilien("DateiImmobilie.txt");
	DateiImmobilien << ImmobilienArt;
	DateiImmobilien << ImmobilienAdresse;
	DateiImmobilien << ImmobilienZustand; 
	DateiImmobilien << ZimmerArt; 
	DateiImmobilien << ZimmerAnzahl;
	DateiImmobilien << Lage;
	DateiImmobilien << ImmobilienWert;
	DateiImmobilien << Wohnfläche;
	DateiImmobilien << Grundstücksfläche;
	DateiImmobilien << InvestmentGeld;
	vector<ofstream>Feld1;
	Feld1.push_back(DateiImmobilien); 
}

void InvestmentImmobilien::PasswortSpeicherortFunktion() { 
	string Passwort;
	ofstream PasswortSpeicherort("DateiPasswort.txt");
	cout << "Bitte geben sie ihr Passwort ein um die Immobilie zu speichern" << endl;
	cout << "Passwort: "; 
	cin >> Passwort;
	string* Zeiger;
	Passwort = *Zeiger;
	PasswortSpeicherort << Passwort << ";" << *Zeiger << endl;
}

void InvestmentImmobilien::Ausgabe() {
	ifstream PasswortSpeicherort("DateiPasswort.txt");
	string IA;
	string Passwort1;
	string Passwort;
	string* Zeiger1;
	string* Zeiger2;
	string Inhalt;
	if (!PasswortSpeicherort.is_open()) {
		while (!PasswortSpeicherort) {
			PasswortSpeicherort >> Passwort >> *Zeiger1;
		}
	}
	cout << "Bitte geben sie das Passwort ein" << endl;
	cout << "Eingabe: ";
	cin >> Passwort1;
	Zeiger2 = &Passwort;

	if (Zeiger2 == Zeiger1) {
		for (ifstream& FeldAusgabe : Feld1) {
			FeldAusgabe >> ImmobilienArt;
			FeldAusgabe >> ImmobilienAdresse;
			FeldAusgabe >> ImmobilienZustand;
			FeldAusgabe >> ZimmerArt;
			FeldAusgabe >> ZimmerAnzahl;
			FeldAusgabe >> Lage;
			FeldAusgabe >> ImmobilienWert;
			FeldAusgabe >> Wohnfläche;
			FeldAusgabe >> Grundstücksfläche;
			FeldAusgabe >> InvestmentGeld;
			cout << "Immobilienart: " << setw(10) << ImmobilienArt << endl;
			cout << "Immobilienadresse: " << setw(6) << ImmobilienAdresse << endl;
			cout << "Immobilienaustand: " << setw(6) << ImmobilienZustand << endl;
			cout << "Zimmerart: " << setw(14) << ZimmerArt << endl;
			cout << "Zimmeranzahl: " << setw(15) << ZimmerAnzahl << endl;
			cout << "Lage: " << setw(19) << Lage << endl;
			cout << "Aktueller ImmobilienWert: " << setw(9) << ImmobilienWert << endl;
			cout << "Wohnfläche: " << setw(13) << Wohnfläche << endl;
			cout << "Grundstücksfläche: " << setw(6) << Grundstücksfläche << endl;
			cout << "Investiertes Geld: " << setw(6) << InvestmentGeld << endl;
		}
	}
}

int main() 
{
	InvestmentImmobilien II; 
	vector<fstream>*FeldZeiger;
	string ImmobilienArt, ImmobilienAdresse, ImmobilienZustand, ImmobilienLage, ZimmerArt, Lage;
	double ImmobilienWert, ZimmerAnzahl, Wohnfläche, Grundstücksfläche, InvestmentGeld;
	vector<ofstream>Feld1;  
	cout << "Bitte geben sie die Art der Immobilie an" << endl;
	cout << "Es stehen folgenede Arten zur verfügung" << endl;
	cout << "1) kleine Wohnung; \n2) große Wohnung; \n3) kleines Haus; \n4) großes Haus; \n5) Mehrfamilien Haus; \n6) Haushälfte" << endl;
	cout << "Eingabe: ";
	cin >> ImmobilienArt;
	cout << endl << endl;
	cout << "*************************************************************************************************" << endl << endl;
	cout << "Bitte geben sie die Adresse der Immobilie an" << endl;
	cout << "Eingabe: ";
	cin >> ImmobilienAdresse;
	cout << endl << endl;
	cout << "*************************************************************************************************" << endl << endl;
	cout << "Bitte geben sie den Zustand der Immobilie an" << endl;
	cout << "Eingabe: ";
	cin >> ImmobilienZustand;
	cout << endl << endl;
	cout << "*************************************************************************************************" << endl << endl; 
	cout << "Bitte geben sie die Immobilienlage an" << endl;
	cout << "Eingabe: ";
	cin >> ImmobilienLage;
	cout << endl << endl;
	cout << "*************************************************************************************************" << endl << endl;
	cout << "Bitte geben sie die ZimmerArt an" << endl;
	cout << "Es stehen folgende Zimmerarten zur verfügung" << endl;
	cout << "1) Küche,\n 2) Badezimmer,\n 3) Schlafzimmer" << endl;
	cout << "Eingabe: ";
	cin >> ZimmerArt;
	cout << "*************************************************************************************************" << endl << endl;
	cout << endl << endl;
	cout << "Bitte geben sie die den Immonilien Wert an" << endl;
	cout << "Eingabe: ";
	cin >> ImmobilienWert;
	cout << "*************************************************************************************************" << endl << endl;
	cout << endl << endl;
	cout << "Bitte geben sie die Zimmeranzahl an" << endl;
	cout << "Eingabe: ";
	cin >> ZimmerAnzahl;
	cout << "*************************************************************************************************" << endl << endl;
	cout << endl << endl;
	cout << "Bitte geben sie die Wohnfläche in Quadratmeter an" << endl;
	cout << "Eingabe: ";
	cin >> Wohnfläche;
	cout << "*************************************************************************************************" << endl << endl;
	cout << endl << endl;
	cout << "Bitte geben sie die Grundstücksfläche an" << endl;
	cout << "Eingabe: ";
	cin >> Grundstücksfläche;
	cout << "*************************************************************************************************" << endl << endl;
	cout << endl << endl;
	cout << "Bitte geben sie ihr das Geld ein das sie in die Immobilie investiert haben" << endl;
	cout << "Eingabe: ";
	cin >> InvestmentGeld; 
	II.PasswortSpeicherortFunktion();  
	II.Speicherung();  
	II.Ausgabe();  
}