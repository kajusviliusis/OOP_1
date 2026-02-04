#include <iostream>
#include <string>

struct Studentas{
  std::string vardas;
  std::string pavarde;
  int egz;
  int* nd;
};

double galutinis(Studentas A, int n)
{
  double pazSuma = 0;
  for(int i=0; i<n; i++)
  {
    pazSuma += A.nd[i];
  }
  double vidurkis = pazSuma / n;
  return 0,4 * vidurkis + 0,6 * A.egz;
}

int main()
{
  Studentas A;
  int n;
  std::cout << "iveskite varda, pavarde" << std::endl;
  std::cin >> A.vardas >> A.pavarde;
  std::cout << "iveskite egzamino rezultata" << std::endl;
  std::cin >> A.egz;
  std::cout << "iveskite kiek yra namu darbu rezultatu" << std::endl;
  std::cin >> n;

  A.nd = new int[n];

  std::cout << "iveskite namu darbu tarpnius rezultatus" << std::endl;
  for(int i=0; i<n; i++)
  {
    std::cin >> A.nd[i];
    std::cout << std::endl;
  }



  delete [] A.nd;

}
