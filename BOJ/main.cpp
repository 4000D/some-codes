#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility> // std::pair
#include <vector>
#include <cstdlib> // atoi, ...

using namespace std;

typedef pair<int, int> ii;

#define fn(n) for (int i = 0; i < n; i++)
#define fni(n) for (int i = 0; i < n; i++)
#define fnj(n) for (int j = 0; j < n; j++)

#define MAX 300

queue<ii> q;     // queue for bfs
int d[MAX][MAX]; // map
int c[MAX][MAX]; // cost
int N, M;        // args

void visit(int x, int y, int dx, int dy) {
  int nx = x + dx;
  int ny = y + dy;

  if (nx < 0 || ny < 0 || d[nx][ny] < 0) {
    return;
  }

  int cb = c[nx][ny];
  int cn = c[x][y] + d[nx][ny];

  if (cn >= 0 && cb > cn) {
    c[nx][ny] = cn;
    q.push(make_pair(nx, ny));
  } else {
  }

  return;
}

int solve() {
  q.push(make_pair(0, 0));

  while (!q.empty()) {
    ii cur = q.front();
    int x = cur.first;
    int y = cur.second;

    // printf("(x, y): (%4d, %4d)\n", x, y);
    q.pop();

    visit(x, y, +1, 0);
    visit(x, y, 0, +1);
    visit(x, y, -1, 0);
    visit(x, y, 0, -1);
  }

  return c[N-1][M-1];
}

int main(int argc, char const *argv[]) {
  memset(d, -1, sizeof(d[0][0]) * MAX * MAX);

  std::cin >> M >> N;

  for (size_t i = 0; i < N; i++) {
    std::string ln;
    std::cin >> ln;

    for (size_t j = 0; j < M; j++) {
      d[i][j] = int(ln[j]) - int('0');
      c[i][j] = MAX;
    }
  }
  c[0][0] = 0;

  std::cout << solve() << '\n';

}
