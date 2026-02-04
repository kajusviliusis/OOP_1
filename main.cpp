#include <iostream>
#include <string>
#include <vector>

struct Studentas{
  std::string vardas;
  std::string pavarde;
  int egz_rez;
  std::vector<int> tarp_rez;
};

double galutinis(Studentas A)
{
  double pazSuma = 0;
  for(auto pazymys : A.tarp_rez)
  {
    pazSuma += pazymys;
  }
  double vidurkis = pazSuma / A.tarp_rez.size();

  return 0,4 * vidurkis + 0,6 * A.egz_rez;
}

int main()
{
  Studentas A;
  std::cout << "iveskite varda, pavarde" << std::endl;
  std::cin >> A.vardas >> A.pavarde;
  std::cout << "iveskite egzamino rezultata" << std::endl;
  std::cin >> A.egz_rez;
  std::cout << "iveskite namu darbu tarpnius rezultatus" << std::endl;
}
