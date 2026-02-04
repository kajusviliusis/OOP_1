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

double vidurkis(Studentas A, int n)
{
  double pazSuma = 0;
  for(int i=0; i<n; i++)
  {
    pazSuma += A.nd[i];
  }
  double vidurkis = (n>0) ? pazSuma / double(n) : 0;

  return vidurkis;
}

double mediana(Studentas A, int n)
{
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

double galutinis(Studentas A, double medVid)
{
  return 0.4*medVid + 0.6*A.egz;
}

int main()
{
  int n;
  int m;
  char pasirinkimas;

  std::cout << "iveskite kiek yra studentu" << std::endl;
  std::cin >> m;

  std::cout << "iveskite kiek yra namu darbu rezultatu" << std::endl;
  std::cin >> n;

  Studentas* A = new Studentas[m];

  for(int i=0; i<m; i++)
  {
    std::cout << "iveskite " << i+1 << " studento varda ir pavarde" << std::endl;
    std::cin >> A[i].vardas >> A[i].pavarde;
    std::cout << "iveskite egzamino rezultata" << std::endl;
    std::cin >> A[i].egz;
    std::cout << "iveskite namu darbu tarpinius rezultatus" << std::endl;
    A[i].nd = new int[n];
    for(int j=0; j<n; j++)
    {
      std::cin >> A[i].nd[j];
    }
  }

  std::cout << "ar skaiciuoti pagal vidurki ar mediana? (v arba m)" << std::endl;
  std::cin >> pasirinkimas; 

  std::cout << std::left << std::setw(10) << "Vardas" << std::setw(15) << "Pavarde" << "Galutinis (" << (pasirinkimas == 'm' ? "Med.)" : "Vid.)" ) << std::endl;

  std::cout << "--------------------------------------------" << std::endl;
  for(int i=0; i<m; i++)
  {
    double galutinisBalas;
    if(pasirinkimas == 'v') galutinisBalas = galutinis(A[i], vidurkis(A[i], n));
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
