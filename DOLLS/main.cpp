#include <algorithm>
#include <cstdlib> // atoi, ...
#include <cstring>
#include <iostream>
#include <queue>
#include <utility> // std::pair
#include <vector>

using namespace std;

typedef pair<int, int> ii;

#define fn(n) for (int i = 0; i < n; i++)
#define fni(n) for (int i = 0; i < n; i++)
#define fnj(n) for (int j = 0; j < n; j++)

#define MAXN 100000

int n, m;
int d[MAXN];
int a[MAXN];

int main(int argc, char const *argv[]) {
  int T;

  std::cin >> T;
  while (T--) {

    std::cin >> n >> m;
    fni(n) {
      std::cin >> d[i];
      a[i] = 0;
    }

    int i = 0;
    while (m--) {
      if (d[i] > 0) {
        d[i]--, a[i]++;
      } else {
        m++;
      }
      i = (i + 1) % n;
    }

    fni(n) printf("%d ", a[i]);
    printf("\n");
  }
}
