#include <cctype>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

struct Studentas{
  std::string vardas;
  std::string pavarde;
  int egz;
  int* nd;
  int ndKiekis;
};

double vidurkis(const Studentas& s)
{
  double pazSuma = 0;
  for(int i=0; i<s.ndKiekis; i++)
  {
    pazSuma += s.nd[i];
  }
  return (s.ndKiekis > 0) ? pazSuma / double(s.ndKiekis) : 0;
}

double mediana(const Studentas& s)
{
  if(s.ndKiekis <= 0 ) return 0.0;

  int* kopija = new int[s.ndKiekis];
  for(int i=0; i<s.ndKiekis; i++)
  {
    kopija[i] = s.nd[i];
  }
  std::sort(kopija, kopija + s.ndKiekis);

  double med;
  if(s.ndKiekis % 2 == 0)
  {
    med = (kopija[s.ndKiekis / 2 - 1] + kopija[s.ndKiekis / 2]) / 2.0;
  }
  else {
    med = kopija[s.ndKiekis / 2];
  }
  delete [] kopija;
  return med;
}

double galutinis(const Studentas& A, double medVid)
{
  return 0.4*medVid + 0.6*A.egz;
}

void rodytiRezultatus(Studentas* studentai, int kiekis)
{
  if (kiekis == 0) return;
  char skaiciavimas;
  std::cout << "Ar skaičiuoti pagal vidurkį ar medianą? (v arba m)" << std::endl;
  std::cin >> skaiciavimas; 

  std::cout << std::left << std::setw(10) << "Vardas" << std::setw(15) << "Pavardė" << "Galutinis (" << (std::tolower(skaiciavimas) == 'm' ? "Med.)" : "Vid.)" ) << std::endl;

  std::cout << "--------------------------------------------" << std::endl;
  for(int i = 0; i < kiekis; i++)
  {
    Studentas& s = studentai[i];
    double galutinisBalas;
    if(std::tolower(skaiciavimas) == 'v') galutinisBalas = galutinis(s, vidurkis(s));
    else galutinisBalas = galutinis(s, mediana(s));

    std::cout << std::setw(10) << s.vardas << std::setw(15) << s.pavarde << std::setprecision(2) << std::fixed << galutinisBalas;
    std::cout << std::endl;
  }
}

void generuotiPazymius(Studentas& s)
{
  s.ndKiekis = rand() % 15 + 1;
  s.nd = new int[s.ndKiekis];
  for(int i=0; i<s.ndKiekis; i++)
  {
    s.nd[i] = rand() % 10 + 1;
  }

  s.egz = rand() % 10 + 1;
}

void padidintiMasyva(Studentas*& studentai, int& talpa) {
    int naujaTalpa = (talpa == 0) ? 2 : talpa * 2;
    Studentas* naujasMasyvas = new Studentas[naujaTalpa];
    for (int i = 0; i < talpa; i++) {
        naujasMasyvas[i] = studentai[i];
    }
    delete[] studentai;
    studentai = naujasMasyvas;
    talpa = naujaTalpa;
}

void generuotiStudentus(Studentas*& studentai, int& kiekis, int& talpa)
{
  std::string vardai[] = {"Jonas", "Petras", "Antanas", "Marius", "Lukas", "Mantas", "Darius", "Andrius", "Tomas", "Linas"};
  std::string pavardes[] = {"Kazlauskas", "Jankauskas", "Petrauskas", "Paukštis", "Stankevičius", "Vasiliauskas", "Žukauskas", "Butkus", "Paura", "Kairys"};

  int studentuKiekis = rand() % 7 + 1;

  for(int i=0; i<studentuKiekis; i++)
  {
    if (kiekis >= talpa) padidintiMasyva(studentai, talpa);
    
    studentai[kiekis].vardas = vardai[rand() % 10];
    studentai[kiekis].pavarde = pavardes[rand() % 10];
    generuotiPazymius(studentai[kiekis]);
    kiekis++;
  }
}

int main()
{
  int talpa = 10;
  int kiekis = 0;
  Studentas* studentai = new Studentas[talpa];
  
  int pasirinkimas;
  bool testi=true;
  srand(time(NULL));

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
          if (kiekis >= talpa) padidintiMasyva(studentai, talpa);
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

          int dabartine_nd_talpa = 2; 
          int k_nd = 0;
          int* laikini_pazymiai = new int[dabartine_nd_talpa];
          int pazymys;

          while (true) {
            if(!(std::cin >> pazymys)) {
              std::cout << "Klaida (įvesta ne skaičius), bandykite dar kartą" << std::endl;
              std::cin.clear();
              std::cin.ignore(10000, '\n');
              continue;
            }

            if(pazymys == 0) break;

            if(pazymys < 1 || pazymys > 10) {
              std::cout << "Įveskite dar kartą. Rezultatas turi būti tarp 1-10." << std::endl;
              continue;
            }

            if (k_nd >= dabartine_nd_talpa) {
              int nauja_nd_talpa = dabartine_nd_talpa * 2;
              int* naujas_nd_masyvas = new int[nauja_nd_talpa];
              for (int i = 0; i < dabartine_nd_talpa; i++) {
                naujas_nd_masyvas[i] = laikini_pazymiai[i];
              }
              delete[] laikini_pazymiai;
              laikini_pazymiai = naujas_nd_masyvas;
              dabartine_nd_talpa = nauja_nd_talpa;
            }

            laikini_pazymiai[k_nd] = pazymys;
            k_nd++;
          }

          s.ndKiekis = k_nd;
          s.nd = new int[k_nd];
          for(int i=0; i<k_nd; i++) s.nd[i] = laikini_pazymiai[i];
          
          delete [] laikini_pazymiai;

          studentai[kiekis] = s; 
          kiekis++;
        }
        rodytiRezultatus(studentai, kiekis);
        break;

      case 2:
        std::cout << "Pasirinkai generuoti pažymius" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        while(true){
          if (kiekis >= talpa) padidintiMasyva(studentai, talpa);
          Studentas s;
          std::cout << "Įveskite studento vardą (0 - baigti)" << std::endl;
          std::cin >> s.vardas;
          if(s.vardas=="0") break;

          std::cout << "Įveskite studento pavardę" << std::endl;
          std::cin >> s.pavarde;

          generuotiPazymius(s);

          studentai[kiekis] = s;
          kiekis++;
        }
        rodytiRezultatus(studentai, kiekis);
        break;
      
      case 3:
        std::cout << "Pasirinkai generuoti studentus ir jų pažymius" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        generuotiStudentus(studentai, kiekis, talpa);
        rodytiRezultatus(studentai, kiekis);
        break;

      case 4:
        std::cout << "Programa baigta" << std::endl;
        testi = false;
        break;

      default:
        std::cout << "Blogas pasirinkimas" << std::endl;
    }
  }

  for(int i = 0; i < kiekis; i++)
  {
    delete [] studentai[i].nd;
  }
  delete [] studentai;

  return 0;
}
