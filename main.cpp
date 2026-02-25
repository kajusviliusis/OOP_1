#include "my_lib.h"

#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

int main()
{
  std::vector<Studentas> studentai;
  int pasirinkimas;
  bool testi=true;
  srand(time(nullptr));
  std::string failoVardas;

  while(testi){
    std::cout << "Pasirinkite veiksmą įvesdami:" << std::endl;
    std::cout << "1 - Įvesti ranka" << std::endl;
    std::cout << "2 - Generuoti pažymius" << std::endl;
    std::cout << "3 - Generuoti studentus ir pažymius" << std::endl;
    std::cout << "4 - Nuskaityti duomenis iš failo" << std::endl;
    std::cout << "5 - Baigti darbą" << std::endl;
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
        rodytiRez(studentai);
        break;

      case 5:
        std::cout << "Programa baigta" << std::endl;
        testi = false;
        break;

      default:
        std::cout << "Neteisingas pasirinkimas, bandykite dar kartą" << std::endl;
    }
  }
}
