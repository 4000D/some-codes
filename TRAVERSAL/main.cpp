#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define EPS 1e-03
#define MAX 100

int N;
vector<int> *pre;
vector<int> *in;
vector<int> *post;

void pre_in_to_post(
  int pre_idx_s, int pre_idx_e,
  int in_idx_s, int in_idx_e,
  int post_idx_s, int post_idx_e)
{
  int root_val = (*pre)[pre_idx_s];
  int root_idx;

  for (root_idx = in_idx_s; root_idx <= in_idx_e; root_idx++) {
    if ((*in)[root_idx] == root_val)
      break;
  }
  int cnt_left = root_idx - in_idx_s;
  int cnt_right = in_idx_e - root_idx;

  // root
  (*post)[post_idx_e] = root_val;
  // left children
  if (cnt_left > 0) {
    pre_in_to_post(
      pre_idx_s + 1, pre_idx_s + cnt_left,
      in_idx_s, root_idx - 1,
      post_idx_s, post_idx_s + cnt_left - 1);

  }
  // right children
  if (cnt_right) {
    pre_in_to_post(
      pre_idx_e - cnt_right + 1,
      pre_idx_e, root_idx + 1, in_idx_e,
      post_idx_e - cnt_right, post_idx_e - 1);
  }

}

int main(int argc, char const *argv[]) {
int c;
  cin >> c;

  while (c--) {
    cin >> N;

    pre = new vector<int>(N);
    in = new vector<int>(N);
    post = new vector<int>(N);

    for (int i = 0; i < N; i++)
      cin >> (*pre)[i];
    for (int i = 0; i < N; i++)
      cin >> (*in)[i];

    pre_in_to_post(0, N - 1, 0, N - 1, 0, N - 1);

    for (int i = 0; i < N; i++)
      cout << (*post)[i] << (i == N-1 ? "" : " ");
    cout << endl;
  }
  return 0;
}
