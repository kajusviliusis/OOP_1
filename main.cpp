#include "my_lib.h"

#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

int main()
{
  std::vector<Studentas> studentai;
  int pasirinkimas;
  bool testi=true;
  srand(time(nullptr));
  std::string failoVardas;

  while(testi){
    try {
      std::cout << "Pasirinkite veiksmą įvesdami:" << std::endl;
      std::cout << "1 - Įvesti ranka" << std::endl;
      std::cout << "2 - Generuoti pažymius" << std::endl;
      std::cout << "3 - Generuoti studentus ir pažymius" << std::endl;
      std::cout << "4 - Nuskaityti duomenis iš failo" << std::endl;
      std::cout << "5 - Testuoti failu nuskaityma" << std::endl;
      std::cout << "6 - Baigti darbą" << std::endl;
      if(!(std::cin >> pasirinkimas))
      {
        std::cout << "Neteisingas pasirinkimas, bandykite dar kartą" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        continue;
      }
      switch(pasirinkimas)
      {
        case 1:
          std::cout << "Pasirinkai įvesti ranka" << std::endl;
          std::cout << "-----------------------" << std::endl;
          while(true){
            Studentas s;

            std::cout << "Įveskite studento vardą (0 - baigti)" << std::endl;
            std::cin >> s.vardas;
            if(s.vardas=="0") break;

            std::cout << "Įveskite studento pavardę" << std::endl;
            std::cin >> s.pavarde;
            while(true)
            {
              std::cout << "Įveskite egzamino rezultatą (1-10)" << std::endl;
              if(std::cin >> s.egz && s.egz >=1 && s.egz <= 10) break;

              std::cout << "Klaida, bandykite dar kartą" << std::endl;
              std::cin.clear();
              std::cin.ignore(10000,'\n');
            }
            std::cout << "Įveskite namų darbų tarpinius rezultatus (1-10), (0 - baigti)" << std::endl;
            int pazymys;
            while (true) {
              if(!(std::cin >> pazymys))
              {
                std::cout << "Klaida, bandykite dar kartą" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                continue;
              }
              if(pazymys==0) break;

              while(pazymys < 1 || pazymys>10){
                std::cout << "Įveskite dar kartą. Rezultatas turi būti tarp 1-10." << std::endl;
                std::cin >> pazymys;
              }

              s.nd.push_back(pazymys);
            }

            studentai.push_back(s);
          }
          rodytiRezultatus(studentai);
          break;

        case 2:
          std::cout << "Pasirinkai generuoti pažymius" << std::endl;
          std::cout << "-----------------------------" << std::endl;
          while(true){
            Studentas s;
            std::cout << "Įveskite studento vardą (0 - baigti)" << std::endl;
            std::cin >> s.vardas;
            if(s.vardas=="0") break;

            std::cout << "Įveskite studento pavardę" << std::endl;
            std::cin >> s.pavarde;

            generuotiPazymius(s);

            studentai.push_back(s);
          }
          rodytiRezultatus(studentai);
          break;

        case 3:
          std::cout << "Pasirinkai generuoti studentus ir jų pažymius" << std::endl;
          std::cout << "-----------------------------" << std::endl;
          generuotiStudentus(studentai);
          rodytiRezultatus(studentai);
          break;

        case 4:
          std::cout << "Pasirinkai nuskaityti duomenis iš failo" << std::endl;
          std::cout << "-----------------------------" << std::endl;
          std::cout << "Iš kokio failo nuskaityti duomenis?" << std::endl;
          std::cin >> failoVardas;
          nuskaitytiFaila(studentai, failoVardas);

          int rikPasirinkimas;
          while (true) {
            std::cout << "Pasirinkite rikiavimo buda:" << std::endl;
            std::cout << "Rikiuoti pagal Varda(1), Pavarde(2), Vidurki(3), Mediana(4)" << std::endl;

            if (!(std::cin >> rikPasirinkimas)) {
              std::cout << "Klaida, iveskite skaiciu\n";
              std::cin.clear();
              std::cin.ignore(10000,'\n');
              continue;
            }
            if (rikPasirinkimas < 1 || rikPasirinkimas > 4) {
              std::cout << "Klaida, pasirinkimas turi buti 1-4\n";
              continue;
            }
            rikiuotiStudentus(studentai, rikPasirinkimas);
            break;
          }

          rodytiRez(studentai);
          break;

        case 5:
          std::cout << "Pasirinkai testuoti failu nuskaityma" << std::endl;
          std::cout << "-----------------------------" << std::endl;

          int kartai;
          std::cout << "Kiek kartu norit nuskaityti faila?" << std::endl;
          while (!(std::cin >> kartai)) {
            std::cout << "Klaida, iveskite skaiciu" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
          }

          nuskaitytiFailaTestavimui(studentai, kartai);
          break;

        case 6:
          std::cout << "Programa baigta" << std::endl;
          testi = false;
          break;

        default:
          std::cout << "Neteisingas pasirinkimas, bandykite dar kartą" << std::endl;
      }
    }
    catch (const std::invalid_argument& e) {
      std::cerr << "Klaida (argumento): " << e.what() << std::endl;
    }
    catch (const std::runtime_error& e) {
      std::cerr << "Klaida (vykdymo): " << e.what() << std::endl;
    }
    catch (std::exception& e) {
      std::cerr << "Bendra klaida: "<< e.what() << std::endl;
    }
  }
}
