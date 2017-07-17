#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = 0x00FFFFFF;
struct info {
  int r;
  int c;

  info(int ri, int ci) : r(ri), c(ci) {}
};

VVI imap;
VVI mov;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int main() {
  int n, m;

  scanf("%d%d", &n, &m);
  imap = VVI(m, VI(n, 0));
  mov = VVI(m, VI(n, INF));
  for (int r = 0; r < m; r++) {
    char str[111];
    memset(str, 0x00, sizeof(str));
    scanf("%s", str);
    for (int c = 0; c < n; c++) {
      if (str[c] == '1')
        imap[r][c] = 1;
      else if (str[c] == '0')
        imap[r][c] = 0;
    }
  }

  queue<info> q;
  q.push(info(0, 0));
  mov[0][0] = 0;

  while (!q.empty()) {
    info here = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int tr = here.r + dr[i];
      int tc = here.c + dc[i];

      if (0 <= tr && tr < m && 0 <= tc && tc < n) {
        if (imap[tr][tc] == 1) { // +1
          if (mov[tr][tc] > mov[here.r][here.c] + 1) {
            mov[tr][tc] = mov[here.r][here.c] + 1;
            q.push(info(tr, tc));
          }
        } else if (imap[tr][tc] == 0) {
          if (mov[tr][tc] > mov[here.r][here.c]) {
            mov[tr][tc] = mov[here.r][here.c];
            q.push(info(tr, tc));
          }
        }
      }
    }
  }

  printf("%d", mov[m - 1][n - 1]);

  return 0;
}
