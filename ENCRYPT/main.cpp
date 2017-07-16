#include <iostream>
#include <algorithm>
using namespace std;

#define EPS 1e-03

int main(int argc, char const *argv[]) {
  int c;
  std::string s;

  std::cin >> c;

  while (c--) {
    std::cin >> s;
    std::string r = "";

    for(int i=0; i<s.length(); i+=2) {
      r += s[i];
    }
    for(int i=1; i<s.length(); i+=2) {
      r += s[i];
    }

    std::cout << r << '\n';
  }

  return 0;
}
