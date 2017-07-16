#include <algorithm>
#include <iostream>

#define EPS 1e-03
#define MAX 202

int c, N, M;
double d[MAX];

double test(double dist) {
  int s = 0;
  for (int i = 1; i < N; i++) {
    int j = s + 1;
    for (; j < M && d[j] - d[s] < dist; j++);
    if (j == M) return false;
    s = j;
  }
  return true;
}

int main(int argc, char const *argv[]) {

  std::cin >> c;

  while (c--) {
    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
      std::cin >> d[i];
    }

    double low = 0, mid, high = d[M - 1] - d[0];
    for (int i = 0; i < 100; i++) {
      mid = (high + low) / 2;
      if (test(mid)) {
        low = mid;
      } else {
        high = mid;
      }
    }
    printf("%.2lf\n", mid);
  }

  return 0;
}
