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

    while (true) {
        std::cout << "Ar skaičiuoti pagal vidurkį ar medianą? (v arba m)\n";
        std::cin >> skaiciavimas;

        skaiciavimas = std::tolower(skaiciavimas);
        if (skaiciavimas == 'v' || skaiciavimas == 'm') break;
        std::cout << "Neteisingas pasirinkimas. Bandykite dar karta\n";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
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

void rodytiRez(const std::vector<Studentas>& studentai)
{
    std::stringstream buffer;
    buffer << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavardė" << std::setw(20)
        << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl;

    for (const Studentas& s : studentai) {
        buffer << std::left << std::setw(20) << s.vardas << std::setw(20) << s.pavarde << std::setw(20) << std::fixed << std::setprecision(2) << galutinis(s, vidurkis(s)) << std::setw(20) << std::fixed << std::setprecision(2) << galutinis(s, mediana(s)) << std::endl;
    }

    int pasirinkimas;
    while (true) {
        std::cout << "Kur norite matyti rezultatus? ekrane(1), faile(2)" << std::endl;
        if (std::cin >> pasirinkimas && (pasirinkimas == 1 || pasirinkimas == 2) ) break;

        std::cout << "Klaida, iveskite 1 arba 2.\n";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
    }
    if(pasirinkimas == 1) {
        std::cout << buffer.str();
    }
    else if(pasirinkimas == 2) {
        std::ofstream failas("Rezultatai.txt");
        if (!failas) throw std::runtime_error("Nepavyko sukurti failo");
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
            throw std::out_of_range("Pasirinkimas turi buti 1-4");
    }
}

void nuskaitytiFailaTestavimui(std::vector<Studentas>& studentai, int kartai)
{
    if (kartai <= 0) {
        throw std::invalid_argument("Kartai turi buti > 0");
    }
    std::string failoVardas;
    std::cout << "Koki faila naudoti testavimui?" << std::endl;
    std::cin >> failoVardas;

    using namespace std::chrono;
    double totalSec = 0.0;

    for (int i=0; i<kartai; i++) {
        std::ifstream failas(failoVardas);
        if(!failas)
        {
            throw std::runtime_error("Nepavyko atidaryti failo " + failoVardas);
        }

        studentai.clear();

        auto start = high_resolution_clock::now();

        std::stringstream buffer;
        buffer << failas.rdbuf();

        std::string eilute;
        std::getline(buffer, eilute);

        while (std::getline(buffer,eilute))
        {
            try {
                std::stringstream ss(eilute);

                Studentas s;
                if (!(ss >> s.vardas >> s.pavarde)) {
                    throw std::runtime_error("Blogas formatas eiluteje " + eilute);
                }

                int pazymys;
                while(ss >> pazymys)
                {
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
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        }
        auto end = high_resolution_clock::now();
        duration<double> durationSec = end - start;
        totalSec += durationSec.count();
        failas.close();
    }

    double average = totalSec / kartai;
    std::cout << "Vidutinis failo nuskaitymo laikas po " << kartai << " testu: " << average << " s" << std::endl;
}

void generuotiFaila(int studentuSk) {
    int pazymiuKiekis = 15;
    std::string failoVardas = "generuotiStud" + std::to_string(studentuSk) + ".txt";
    std::ofstream failas(failoVardas);

    failas << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavardė";
    for (int i=1; i<=pazymiuKiekis; i++) {
        failas << std::setw(20) << "ND" + std::to_string(i);
    }
    failas << std::setw(20) << "Egz" << '\n';

    for (int i=1; i<=studentuSk; i++) {
       failas << std::left << std::setw(20) << ("Vardas" + std::to_string(i)) << std::setw(20) << ("Pavarde" + std::to_string(i));

       for (int j = 0; j < pazymiuKiekis; j++) {
            failas << std::setw(20) << (rand() % 10 + 1);
        }
        failas << std::setw(20) << (rand() % 10 + 1) << '\n';
    }
    failas.close();
}

void paskirstytiStudentus(const std::vector<Studentas>& studentai, int rikiavimas, std::vector<Studentas>& vargsai,
            std::vector<Studentas>& kieti) {

    for (const Studentas& s : studentai) {
        if (s.galVid >= 5.0) {
            kieti.push_back(s);
        } else {
            vargsai.push_back(s);
        }
    }

    rikiuotiStudentus(vargsai, rikiavimas);
    rikiuotiStudentus(kieti, rikiavimas);
}

void isvestiDuFailus(const std::vector<Studentas>& vargsai, const std::vector<Studentas>& kieti) {

    std::ofstream failasVargsai("vargsai.txt");
    std::ofstream failasKieti("kieti.txt");

    failasVargsai << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavardė" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << '\n';
    for (const Studentas& s : vargsai) {
        failasVargsai << std::left << std::setw(20) << s.vardas << std::setw(20) << s.pavarde << std::setw(20) << std::fixed << std::setprecision(2) << s.galVid << std::setw(20) << std::fixed << std::setprecision(2) << s.galMed << '\n';
    }

    failasKieti << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavardė" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << '\n';
    for (const Studentas& s : kieti) {
        failasKieti << std::left << std::setw(20) << s.vardas << std::setw(20) << s.pavarde << std::setw(20) << std::fixed << std::setprecision(2) << s.galVid << std::setw(20) << std::fixed << std::setprecision(2) << s.galMed << '\n';
    }

    failasVargsai.close();
    failasKieti.close();
}

void atliktiPirmaTyrima() {
    using namespace std::chrono;
    std::vector<int> kiekiai = {1000, 10000, 100000, 1000000, 10000000};

    std::cout << "----------------------------------------------------------\n";
    std::cout << std::left << std::setw(20) << "Irasu kiekis" << "Kurimo trukme (s)\n";
    std::cout << "----------------------------------------------------------\n";

    for (int n : kiekiai) {
        auto start = high_resolution_clock::now();

        generuotiFaila(n);

        auto end = high_resolution_clock::now();
        duration<double> trukme = end - start;

        std::cout << std::left << std::setw(20) << n << std::fixed << std::setprecision(5) << trukme.count() << " s\n";
    }
    std::cout << "----------------------------------------------------------\n";
}

void atliktiAntraTyrima() {
    using namespace std::chrono;
    std::vector<int> kiekiai = {1000, 10000, 100000, 1000000, 10000000};
    int rikiavimas = 3;

    std::cout << "-----------------------------------------------------------------------------\n";
    std::cout << std::left << std::setw(10) << "Irasai"
              << std::setw(12) << "Skaitymas"
              << std::setw(12) << "Skirstymas"
              << std::setw(12) << "Irasymas"
              << "Viso\n";
    std::cout << "-----------------------------------------------------------------------------\n";

    for (int n : kiekiai) {
        std::vector<Studentas> studentai;
        std::vector<Studentas> vargsai;
        std::vector<Studentas> kieti;
        std::string failoVardas = "generuotiStud" + std::to_string(n) + ".txt";

        auto visoPradzia = high_resolution_clock::now();

        // 1 skaitymas
        auto s1 = high_resolution_clock::now();
        try {
            nuskaitytiFaila(studentai, failoVardas);
        } catch (const std::exception& e) {
            std::cerr << "Klaida: Nepavyko rasti " << failoVardas << "\n";
            continue;
        }
        auto e1 = high_resolution_clock::now();

        // 2 skirstymas ir rusiavimas
        auto s2 = high_resolution_clock::now();
        paskirstytiStudentus(studentai, rikiavimas, vargsai, kieti);
        auto e2 = high_resolution_clock::now();

        // 3 suskirstytu isvedimas i du failus
        auto s3 = high_resolution_clock::now();
        isvestiDuFailus(vargsai, kieti);
        auto e3 = high_resolution_clock::now();

        auto visoPabaiga = high_resolution_clock::now();

        double trukme1 = duration<double>(e1 - s1).count();
        double trukme2 = duration<double>(e2 - s2).count();
        double trukme3 = duration<double>(e3 - s3).count();
        double trukmeViso = duration<double>(visoPabaiga - visoPradzia).count();

        std::cout << std::left << std::setw(10) << n
                  << std::fixed << std::setprecision(4)
                  << std::setw(12) << trukme1
                  << std::setw(12) << trukme2
                  << std::setw(12) << trukme3
                  << trukmeViso << " s\n";

        studentai.clear(); studentai.shrink_to_fit();
        vargsai.clear(); vargsai.shrink_to_fit();
        kieti.clear(); kieti.shrink_to_fit();
    }
    std::cout << "-----------------------------------------------------------------------------\n";
}