#ifndef MYLIB_H
#define MYLIB_H

#include <string>
#include <vector>
#include <deque>
#include <list>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <chrono>

struct Studentas {
    std::string vardas;
    std::string pavarde;
    int egz;
    std::vector<int> nd;

    double galVid;
    double galMed;
};

double vidurkis(const Studentas& s);
double mediana(const Studentas& s);
double galutinis(const Studentas& A, double medVid);
void rodytiRezultatus(const std::vector<Studentas>& studentai);
void generuotiPazymius(Studentas& s);
void generuotiStudentus(std::vector<Studentas>& studentai);
void rodytiRez(const std::vector<Studentas>& studentai);
bool rikiuotiVarda(const Studentas& A, const Studentas& B);
bool rikiuotiPavarde(const Studentas& A, const Studentas& B);
bool rikiuotiPagalGalutiniVid(const Studentas& A, const Studentas& B);
bool rikiuotiPagalGalutiniMed(const Studentas& A, const Studentas& B);
void rikiuotiStudentus(std::vector<Studentas>& studentai, int pasirinkimas);
void nuskaitytiFailaTestavimui(std::vector<Studentas>& studentai, int kartai);
void generuotiFaila(int studentuSk);
void paskirstytiStudentus(const std::vector<Studentas>& studentai, int rikiavimas, std::vector<Studentas>& vargsai,
            std::vector<Studentas>& kieti);
void isvestiDuFailus(const std::vector<Studentas>& vargsai, const std::vector<Studentas>& kieti);
void atliktiPirmaTyrima();
void atliktiAntraTyrima();

// templates

template <typename Konteineris>
void nuskaitytiFaila(Konteineris& studentai, const std::string& failoVardas)
{
    std::ifstream failas(failoVardas);
    if (!failas) {
        throw std::runtime_error("Nepavyko atidaryti failo " + failoVardas);
    }

    std::stringstream buffer;
    buffer << failas.rdbuf();

    std::string eilute;
    std::getline(buffer, eilute);

    while (std::getline(buffer, eilute)) {
        std::stringstream ss(eilute);

        Studentas s;
        if (!(ss >> s.vardas >> s.pavarde)) {
            throw std::runtime_error("Blogas formatas eiluteje " + eilute);
        }

        int pazymys;
        while (ss >> pazymys) {
            s.nd.push_back(pazymys);
        }

        if (s.nd.empty()) {
            throw std::runtime_error("Truksta pazymiu eiluteje " + eilute);
        }

        s.egz = s.nd.back();
        s.nd.pop_back();

        s.galVid = galutinis(s, vidurkis(s));
        s.galMed = galutinis(s, mediana(s));

        studentai.push_back(s);
    }
}


#endif
