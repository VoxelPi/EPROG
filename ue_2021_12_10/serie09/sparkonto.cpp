/**
 * Aufgabe 9.2
 */

#include <cassert>
#include <iostream>

class SparKonto {
private:
    int kontonummer;
    double guthaben;
    double zinssatz;

public:
    int getKontonummer();
    double getZinssatz();

    void setKontonummer(int kontonummer);
    void setZinssatz(double zinssatz);

    void abheben(double betrag);
    void einzahlen(double betrag);

    double berechneGuthaben();
};

int SparKonto::getKontonummer() {
    return kontonummer;
}

double SparKonto::getZinssatz() {
    return zinssatz;
}

void SparKonto::setKontonummer(int kontonummer) {
    assert(kontonummer >= 0);
    this->kontonummer = kontonummer;
}

void SparKonto::setZinssatz(double zinssatz) {
    assert(zinssatz >= 0);
    this->zinssatz = zinssatz;
}

void SparKonto::abheben(double betrag) {
    assert(guthaben >= betrag);
    guthaben -= betrag;
}

void SparKonto::einzahlen(double betrag) {
    guthaben += betrag;
}

double SparKonto::berechneGuthaben() {
    return guthaben * (1 + zinssatz);
}


int main() {
    SparKonto sparkonto;
    sparkonto.setKontonummer(42);
    sparkonto.setZinssatz(1.0);

    assert(sparkonto.getKontonummer() == 42);
    std::cout << "Kontonummer: " << sparkonto.getKontonummer() << std::endl;

    assert(sparkonto.getZinssatz() == 1.0);
    std::cout << "Zinssatz: " << sparkonto.getZinssatz() << std::endl;

    sparkonto.einzahlen(100.0);
    sparkonto.abheben(50.0);

    std::cout << "Guthaben: " << sparkonto.berechneGuthaben() << std::endl;

    return 0;
}