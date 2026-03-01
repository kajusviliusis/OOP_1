#include "my_lib.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cctype>
#include <chrono>
#include <sstream>
#include <fstream>

double vidurkis(const Studentas& s)
{
    if (s.nd.empty()) {
        throw std::invalid_argument("Negalima skaiciuoti vidurkio, truksta namu darbu ivertinimu");
    }
    double pazSuma = 0;
    for (int i = 0; i < s.nd.size(); i++)
        pazSuma += s.nd[i];

    return pazSuma / double(s.nd.size());
}

double mediana(const Studentas& s)
{
    if (s.nd.empty()) {
        throw std::invalid_argument("Negalima skaiciuoti medianos, truksta namu darbu ivertinimu");
    }

    std::vector<int> kopija = s.nd;
    std::sort(kopija.begin(), kopija.end());

    if (kopija.size() % 2 == 0)
        return (kopija[kopija.size()/2 - 1] + kopija[kopija.size()/2]) / 2.0;
    else
        return kopija[kopija.size()/2];
}

double galutinis(const Studentas& A, double medVid)
{
    return 0.4 * medVid + 0.6 * A.egz;
}

void rodytiRezultatus(const std::vector<Studentas>& studentai)
{
    char skaiciavimas;
    std::cout << "Ar skaičiuoti pagal vidurkį ar medianą? (v arba m)\n";
    std::cin >> skaiciavimas;

    skaiciavimas = std::tolower(skaiciavimas);
    if (skaiciavimas != 'v' && skaiciavimas != 'm') {
        throw std::invalid_argument("Neteisingas pasirinkimas, galima ivesti tik 'v' arba 'm' ");
    }

    std::cout << std::left << std::setw(10) << "Vardas"
              << std::setw(15) << "Pavardė"
              << "Galutinis ("
              << (skaiciavimas == 'm' ? "Med.)" : "Vid.)")
              << "\n";

    std::cout << "--------------------------------------------\n";

    for (const Studentas& s : studentai)
    {
        double galutinisBalas;

        if (skaiciavimas == 'v')
            galutinisBalas = galutinis(s, vidurkis(s));
        else
            galutinisBalas = galutinis(s, mediana(s));

        std::cout << std::setw(10) << s.vardas
                  << std::setw(15) << s.pavarde
                  << std::fixed << std::setprecision(2)
                  << galutinisBalas << "\n";
    }
}

void generuotiPazymius(Studentas& s)
{
    int kiekis = 5;
    s.nd.clear();

    for (int i = 0; i < kiekis; i++)
        s.nd.push_back(rand() % 10 + 1);

    s.egz = rand() % 10 + 1;
}

void generuotiStudentus(std::vector<Studentas>& studentai)
{
    std::vector<std::string> vardai = {"Jonas","Petras","Antanas","Marius","Lukas","Mantas","Darius","Andrius","Tomas","Linas"};
    std::vector<std::string> pavardes = {"Kazlauskas","Jankauskas","Petrauskas","Paukštis","Stankevičius","Vasiliauskas","Žukauskas","Butkus","Paura","Kairys"};

    int studentuKiekis = rand() % 7 + 1;

    for (int i = 0; i < studentuKiekis; i++)
    {
        Studentas s;
        s.vardas = vardai[rand() % vardai.size()];
        s.pavarde = pavardes[rand() % pavardes.size()];
        generuotiPazymius(s);
        studentai.push_back(s);
    }
}

void nuskaitytiFaila(std::vector<Studentas>& studentai, const std::string& failoVardas)
{
  std::ifstream failas(failoVardas);
  if(!failas)
  {
      throw std::runtime_error("Nepavyko atidaryti failo " + failoVardas);
  }

    std::stringstream buffer;
    buffer << failas.rdbuf();

    std::string eilute;
    std::getline(buffer, eilute);

    while (std::getline(buffer,eilute))
    {
      std::stringstream ss(eilute);

      Studentas s;
      ss >> s.vardas >> s.pavarde;

      int pazymys;
      while(ss >> pazymys)
      {
        s.nd.push_back(pazymys);
      }

      s.egz = s.nd.back();
      s.nd.pop_back();

      s.galVid = galutinis(s, vidurkis(s));
      s.galMed = galutinis(s, mediana(s));

      studentai.push_back(s);
    }

    failas.close();
}

void rodytiRez(const std::vector<Studentas>& studentai)
{
    std::stringstream buffer;
    buffer << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavardė" << std::setw(20)
        << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl;

    for (const Studentas& s : studentai) {
        buffer << std::left << std::setw(20) << s.vardas << std::setw(20) << s.pavarde << std::setw(20) << std::fixed << std::setprecision(2) << galutinis(s, vidurkis(s)) << std::setw(20) << std::fixed << std::setprecision(2) << galutinis(s, mediana(s)) << std::endl;
    }

    int pasirinkimas;
    std::cout << "Kur norite matyti rezultatus? ekrane(1), faile(2)" << std::endl;
    std::cin >> pasirinkimas;
    if(pasirinkimas == 1) {
        std::cout << buffer.str();
    }
    else if(pasirinkimas == 2) {
        std::ofstream failas("Rezultatai.txt");
        failas << buffer.str();
        failas.close();
    }
}

bool rikiuotiVarda(const Studentas& A, const Studentas& B) {
    return A.vardas < B.vardas;
}
bool rikiuotiPavarde(const Studentas& A, const Studentas& B) {
    return A.pavarde < B.pavarde;
}
bool rikiuotiPagalGalutiniVid(const Studentas& A, const Studentas& B) {
    return A.galVid < B.galVid;
}
bool rikiuotiPagalGalutiniMed(const Studentas& A, const Studentas& B) {
    return A.galMed < B.galMed;
}

void rikiuotiStudentus(std::vector<Studentas>& studentai, int pasirinkimas) {
    switch (pasirinkimas) {
        case 1:
            std::sort(studentai.begin(), studentai.end(), rikiuotiVarda);
            break;
        case 2:
            std::sort(studentai.begin(), studentai.end(), rikiuotiPavarde);
            break;
        case 3:
            std::sort(studentai.begin(), studentai.end(), rikiuotiPagalGalutiniVid);
            break;
        case 4:
            std::sort(studentai.begin(), studentai.end(), rikiuotiPagalGalutiniMed);
            break;
        default:
            std::cout << "Neteisingas pasirinkimas" << std::endl;
    }
}

void nuskaitytiFailaTestavimui(std::vector<Studentas>& studentai, int kartai)
{
    std::string failoVardas;
    std::cout << "Koki faila naudoti testavimui?" << std::endl;
    std::cin >> failoVardas;

    using namespace std::chrono;
    double totalSec = 0.0;

    for (int i=0; i<kartai; i++) {
        std::ifstream failas(failoVardas);
        if(!failas)
        {
            std::cout << "Nepavyko atidaryti failo." << std::endl;
            return;
        }

        studentai.clear();

        auto start = high_resolution_clock::now();

        std::stringstream buffer;
        buffer << failas.rdbuf();

        std::string eilute;
        std::getline(buffer, eilute);

        while (std::getline(buffer,eilute))
        {
            std::stringstream ss(eilute);

            Studentas s;
            ss >> s.vardas >> s.pavarde;

            int pazymys;
            while(ss >> pazymys)
            {
                s.nd.push_back(pazymys);
            }

            s.egz = s.nd.back();
            s.nd.pop_back();

            s.galVid = galutinis(s, vidurkis(s));
            s.galMed = galutinis(s, mediana(s));

            studentai.push_back(s);
        }
        auto end = high_resolution_clock::now();
        duration<double> durationSec = end - start;
        totalSec += durationSec.count();
        failas.close();
    }

    double average = totalSec / kartai;
    std::cout << "Vidutinis failo nuskaitymo laikas po " << kartai << " testu: " << average << " s" << std::endl;
}

