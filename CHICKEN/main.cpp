#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define fn(n) for (int i = 0; i < n; i++)

#define MAXN 30
#define MAXC 1000

template <typename T> void _2D(T **a, int r, int c) {
  a = new T *[r];
  for (size_t i = 0; i < r; i++)
    a[i] = new T[c];
}

int **d, **nextD;
int N, Q, s, e;

void solve() {
  _2D(nextD, N, N);



  if (memcmp(d, nextD, N * N) == 0)
    return;

  free(d), d = nextD;
  solve();
}

int main(int argc, char const *argv[]) {
  int r;

  std::cin >> N;
  _2D(d, N, N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> d[i][j];
    }
  }

  solve();

  std::cin >> Q;
  for (int i = 0; i < Q; i++) {
    std::cin >> s >> e;
    r = d[s][e];
    // if (r > 0)
    std::cout << r << '\n';
  }

  return 0;
}
