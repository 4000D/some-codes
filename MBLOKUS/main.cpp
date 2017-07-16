#include <algorithm>
#include <iostream>
#include <vector>

#define EPS 1e-03
#define MAX 30

struct Block {
  std::vector<int> pts;
};

struct Spot {
  int x, y;
  bool blocked;
  bool possible;
  Spot(){}
  Spot(int _x, int _y, bool b) : x(_x), y(_y), blocked(b) {}
};

Spot d[MAX][MAX];
int N, M;

int main(int argc, char const *argv[]) {
  int c;
  char ch;

  std::cin >> c;

  while (c--) {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        std::cin >> ch;
        d[i][j].blocked = ch == '.' ? false : true;
        d[i][j].possible = !d[i][j].blocked;
      }
    }

  }

  return 0;
}
