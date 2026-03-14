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

template <typename Container>
void rikiuotiStudentus(Container& studentai, int pasirinkimas)
{
    if (pasirinkimas < 1 || pasirinkimas > 4) {
        throw std::out_of_range("Pasirinkimas turi buti 1-4");
    }

    if (pasirinkimas == 1) {
        // perziuri kompiliavimo metu, kad butu kompiliuojamas tik reikalingas rikiavimas, ziuredamas i template type
        if constexpr (std::is_same<Container, std::list<Studentas> >::value) studentai.sort(rikiuotiVarda);
        else std::sort(studentai.begin(), studentai.end(), rikiuotiVarda);
    } else if (pasirinkimas == 2) {
        if constexpr (std::is_same<Container, std::list<Studentas> >::value) studentai.sort(rikiuotiPavarde);
        else std::sort(studentai.begin(), studentai.end(), rikiuotiPavarde);
    } else if (pasirinkimas == 3) {
        if constexpr (std::is_same<Container, std::list<Studentas> >::value) studentai.sort(rikiuotiPagalGalutiniVid);
        else std::sort(studentai.begin(), studentai.end(), rikiuotiPagalGalutiniVid);
    } else {
        if constexpr (std::is_same<Container, std::list<Studentas> >::value) studentai.sort(rikiuotiPagalGalutiniMed);
        else std::sort(studentai.begin(), studentai.end(), rikiuotiPagalGalutiniMed);
    }
}



#endif
