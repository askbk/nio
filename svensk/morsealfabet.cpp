#include <iostream>
#include <map>
#include <array>
#include <string>
#include <algorithm>

int main() {
  //std::map<std::string, std::string> alf; //alfabetet
  std::string alf[26];    //alfabetet
  std::string signs[26];  //morsetegn
  std::string trans[26];
  //std::map<std::string, int> legend;

  std::string S1;
  std::string S2;
  int S;  //antall 1-tall som utgjør en strek
  int P;  //antall 1-tall som utgjør en prikk
  int T;  //antall null som skiller prikk og strek
  int B;  //antall null som signaliserer ny bokstav
  int M;  //antall null som betyr mellomrom
  int N;  //antall 1 og 0 i beskjeden
  std::string morse;  //beskjed i morse
  std::string out;  //dekodet tekst

  for (size_t i = 0; i < 26; ++i) {
    std::cin >> S1 >> S2;
    alf[i]=S1;  //alfabetet
    signs[i]=S2;  //tegnene
  }

  std::cin >> S >> P >> T >> B >> M >> N >> morse;

  const std::string dots(P, '1'); //konstruerer koden til alle tegnene
  const std::string lines(S, '1');
  const std::string spaces(M, '0');
  const std::string signSpace(T, '0');
  const std::string letterSpace(B, '0');

  for (size_t i = 0; i < 26; ++i) {
    int signLength = signs[i].size();         //antall tegn i bokstaven
    for (size_t j = 0; j < signLength; ++j) { //legger til riktig antall 1-tall i oversettelsen + pause dersom det ikke er siste tegn i bokstaven
      if (signs[i].front() == '.') {
        trans[i].append(dots);
      } else {
        trans[i].append(lines);
      }
      signs[i].erase(0,1);  //fjerner første tegn fra bokstaven
      if (j+1 != signLength) {
        trans[i].append(signSpace);
      }
    }
  }
  return 0;
}
