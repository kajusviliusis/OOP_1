#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>

struct Studentas{
  std::string vardas;
  std::string pavarde;
  int egz;
  int* nd;
};

double vidurkis(const Studentas& A, int n)
{
  double pazSuma = 0;
  for(int i=0; i<n; i++)
  {
    pazSuma += A.nd[i];
  }
  return (n>0) ? pazSuma / double(n) : 0;
}

double mediana(const Studentas& A, int n)
{
  if(n <= 0 ) return 0.0;

  int* kopija = new int[n];
  for(int i=0; i<n; i++)
  {
    kopija[i] = A.nd[i];
  }
  std::sort(kopija, kopija + n);

  double med;
  if(n % 2 == 0)
  {
    med = (kopija[n / 2 - 1] + kopija[n / 2]) / 2.0;
  }
  else {
    med = kopija[n / 2];
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
  int n;
  int m;
  char pasirinkimas;

  std::cout << "Įveskite kiek yra studentų" << std::endl;
  std::cin >> m;

  std::cout << "Įveskite kiek yra namų darbų rezultatų" << std::endl;
  std::cin >> n;

  Studentas* A = new Studentas[m];

  for(int i=0; i<m; i++)
  {
    std::cout << "Įveskite " << i+1 << " studento vardą ir pavardę" << std::endl;
    std::cin >> A[i].vardas >> A[i].pavarde;
    std::cout << "Įveskite egzamino rezultatą (1-10)" << std::endl;
    std::cin >> A[i].egz;
    while(A[i].egz < 1 || A[i].egz > 10)
    {
      std::cout << "Įveskite dar kartą. Rezultatas turi būti tarp 1-10." << std::endl;
      std::cin >> A[i].egz;
    }
    std::cout << "Įveskite namų darbų tarpinius rezultatus (1-10)" << std::endl;
    A[i].nd = new int[n];
    for(int j=0; j<n; j++)
    {
      std::cin >> A[i].nd[j];
      while(A[i].nd[j] < 1 || A[i].nd[j] > 10)
      {
        std::cout << "Įveskite dar kartą. Rezultatas turi būti tarp 1-10." << std::endl;
        std::cin >> A[i].nd[j];
      }

    }
  }

  std::cout << "Ar skaičiuoti pagal vidurkį ar medianą? (v arba m)" << std::endl;
  std::cin >> pasirinkimas; 

  std::cout << std::left << std::setw(10) << "Vardas" << std::setw(15) << "Pavardė" << "Galutinis (" << (std::tolower(pasirinkimas) == 'm' ? "Med.)" : "Vid.)" ) << std::endl;

  std::cout << "--------------------------------------------" << std::endl;
  for(int i=0; i<m; i++)
  {
    double galutinisBalas;
    if(std::tolower(pasirinkimas) == 'v') galutinisBalas = galutinis(A[i], vidurkis(A[i], n));
    else galutinisBalas = galutinis(A[i], mediana(A[i], n));

    std::cout << std::setw(10) << A[i].vardas << std::setw(15) << A[i].pavarde << std::setprecision(2) << std::fixed << galutinisBalas;
    std::cout << std::endl;
  }

  for(int i=0; i<m; i++)
  {
    delete [] A[i].nd;
  }

  delete [] A;
}
