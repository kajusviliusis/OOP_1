#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

struct Studentas{
  std::string vardas;
  std::string pavarde;
  int egz;
  std::vector<int> nd;
};

double vidurkis(const Studentas& s)
{
  if(s.nd.empty()) return 0;

  double pazSuma = 0;
  for(int i=0; i<s.nd.size(); i++)
  {
    pazSuma += s.nd[i];
  }
  return pazSuma / double(s.nd.size());
}

double mediana(const Studentas& s)
{
  if(s.nd.empty()) return 0;

  std::vector<int> kopija = s.nd;
  std::sort(kopija.begin(), kopija.end());

  double med;
  if(s.nd.size() % 2 == 0)
  {
    med = (kopija[s.nd.size() / 2 - 1] + kopija[s.nd.size() / 2]) / 2.0;
  }
  else {
    med = kopija[s.nd.size() / 2];
  }
  return med;
}

double galutinis(const Studentas& A, double medVid)
{
  return 0.4*medVid + 0.6*A.egz;
}

void rodytiRezultatus(const std::vector<Studentas>& studentai)
{
  char skaiciavimas;
  std::cout << "Ar skaičiuoti pagal vidurkį ar medianą? (v arba m)" << std::endl;
  std::cin >> skaiciavimas; 

  std::cout << std::left << std::setw(10) << "Vardas" << std::setw(15) << "Pavardė" << "Galutinis (" << (std::tolower(skaiciavimas) == 'm' ? "Med.)" : "Vid.)" ) << std::endl;

  std::cout << "--------------------------------------------" << std::endl;
  for(const Studentas& s : studentai)
  {
    double galutinisBalas;
    if(std::tolower(skaiciavimas) == 'v') galutinisBalas = galutinis(s, vidurkis(s));
    else galutinisBalas = galutinis(s, mediana(s));

    std::cout << std::setw(10) << s.vardas << std::setw(15) << s.pavarde << std::setprecision(2) << std::fixed << galutinisBalas;
    std::cout << std::endl;
  }
}

void generuotiPazymius(Studentas& s)
{
  int kiekis = 5;
  s.nd.clear();
  for(int i=0; i<kiekis; i++)
  {
    s.nd.push_back(rand() % 10 + 1);
  }

  s.egz = rand() % 10 + 1;
}

void generuotiStudentus(std::vector<Studentas>& studentai)
{
  std::vector<std::string> vardai = {"Jonas", "Petras", "Antanas", "Marius", "Lukas", "Mantas", "Darius", "Andrius", "Tomas", "Linas"};
  std::vector<std::string> pavardes = {"Kazlauskas", "Jankauskas", "Petrauskas", "Paukštis", "Stankevičius", "Vasiliauskas", "Žukauskas", "Butkus", "Paura", "Kairys"};

  int studentuKiekis = rand() % 7 + 1;

  for(int i=0; i<studentuKiekis; i++)
  {
    Studentas s;
    s.vardas = vardai[rand() % vardai.size()];
    s.pavarde = pavardes[rand() % pavardes.size()];

    generuotiPazymius(s);
    studentai.push_back(s);
  }

}

int main()
{
  std::vector<Studentas> studentai;
  int pasirinkimas;
  bool testi=true;
  srand(time(nullptr));

  while(testi){
    std::cout << "Pasirinkite veiksmą įvesdami:" << std::endl;
    std::cout << "1 - Įvesti ranka" << std::endl;
    std::cout << "2 - Generuoti pažymius" << std::endl;
    std::cout << "3 - Generuoti studentus ir pažymius" << std::endl;
    std::cout << "4 - Baigti darbą" << std::endl;
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
        std::cout << "Programa baigta" << std::endl;
        testi = false;
        break;

      default:
        std::cout << "Neteisingas pasirinkimas, bandykite dar kartą" << std::endl;
    }
  }
}
