#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

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

int main()
{
  std::vector<Studentas> studentai;
  char pasirinkimas;

  while(true){
    Studentas s;

    std::cout << "Įveskite studento vardą (0 - baigti)" << std::endl;
    std::cin >> s.vardas;
    if(s.vardas=="0") break;

    std::cout << "Įveskite studento pavardę" << std::endl;
    std::cin >> s.pavarde;

    std::cout << "Įveskite egzamino rezultatą (1-10)" << std::endl;
    std::cin >> s.egz;
    while(s.egz < 1 || s.egz > 10){
      std::cout << "Įveskite dar kartą. Rezultatas turi būti tarp 1-10." << std::endl;
      std::cin >> s.egz;
    }

    std::cout << "Įveskite namų darbų tarpinius rezultatus (1-10), (0 - baigti)" << std::endl;

    int max_talpa = 10;
    int pazymys;
    int kiek = 0;
    int* laikini_pazymiai = new int[max_talpa];

    while (true) {
      std::cin >> pazymys;
      if(pazymys==0) break;

      while(pazymys < 1 || pazymys>10){
        std::cout << "Įveskite dar kartą. Rezultatas turi būti tarp 1-10." << std::endl;
        std::cin >> pazymys;
      }
      laikini_pazymiai[kiek++] = pazymys;
    }

    s.ndKiekis = kiek;
    s.nd = new int[kiek];

    for(int i=0; i<kiek; i++) s.nd[i] = laikini_pazymiai[i];

    delete [] laikini_pazymiai;

    studentai.push_back(s);
    
  }

  std::cout << "Ar skaičiuoti pagal vidurkį ar medianą? (v arba m)" << std::endl;
  std::cin >> pasirinkimas; 

  std::cout << std::left << std::setw(10) << "Vardas" << std::setw(15) << "Pavardė" << "Galutinis (" << (std::tolower(pasirinkimas) == 'm' ? "Med.)" : "Vid.)" ) << std::endl;

  std::cout << "--------------------------------------------" << std::endl;
  for(Studentas s : studentai)
  {
    double galutinisBalas;
    if(std::tolower(pasirinkimas) == 'v') galutinisBalas = galutinis(s, vidurkis(s));
    else galutinisBalas = galutinis(s, mediana(s));

    std::cout << std::setw(10) << s.vardas << std::setw(15) << s.pavarde << std::setprecision(2) << std::fixed << galutinisBalas;
    std::cout << std::endl;
  }

  for(Studentas s : studentai)
  {
    delete [] s.nd;
  }

}
