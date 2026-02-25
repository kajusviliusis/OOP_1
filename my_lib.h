#ifndef MYLIB_H
#define MYLIB_H

#include <string>
#include <vector>

struct Studentas {
    std::string vardas;
    std::string pavarde;
    int egz;
    std::vector<int> nd;
};

double vidurkis(const Studentas& s);
double mediana(const Studentas& s);
double galutinis(const Studentas& A, double medVid);
void rodytiRezultatus(const std::vector<Studentas>& studentai);
void generuotiPazymius(Studentas& s);
void generuotiStudentus(std::vector<Studentas>& studentai);
void nuskaitytiFaila(std::vector<Studentas>& studentai, std::string failoVardas);
void rodytiRez(const std::vector<Studentas>& studentai);

#endif
