#include <algorithm>
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <unistd.h>
#include <unordered_set>
#include <vector>

using namespace std;

// #define fn(n) for (int i = 0; i < n; i++)

#define MOD 20130728
#define MAXK 10

typedef std::map<std::string, int> Map;
typedef std::unordered_set<int> Set;

template <typename T> std::string vec2str(std::vector<T> vec) {
  std::ostringstream oss;

  if (!vec.empty()) {
    std::copy(vec.begin(), vec.end() - 1, std::ostream_iterator<T>(oss, ","));
    oss << vec.back();
  }

  return oss.str();
}

//////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//
// process_mem_usage(double &, double &) - takes two doubles by reference,
// attempts to read the system-dependent data for a process' virtual memory
// size and resident set size, and return the results in KB.
//
// On failure, returns 0.0, 0.0

void process_mem_usage() {
  double vm_usage, resident_set;

  using std::ios_base;
  using std::ifstream;
  using std::string;

  vm_usage = 0.0;
  resident_set = 0.0;

  // 'file' stat seems to give the most reliable results
  //
  ifstream stat_stream("/proc/self/stat", ios_base::in);

  // dummy vars for leading entries in stat that we don't care about
  //
  string pid, comm, state, ppid, pgrp, session, tty_nr;
  string tpgid, flags, minflt, cminflt, majflt, cmajflt;
  string utime, stime, cutime, cstime, priority, nice;
  string O, itrealvalue, starttime;

  // the two fields we want
  //
  unsigned long vsize;
  long rss;

  stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr >>
      tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt >> utime >>
      stime >> cutime >> cstime >> priority >> nice >> O >> itrealvalue >>
      starttime >> vsize >> rss; // don't care about the rest

  stat_stream.close();

  long page_size_kb = sysconf(_SC_PAGE_SIZE) /
                      1024; // in case x86-64 is configured to use 2MB pages
  vm_usage = vsize / 1024.0;
  resident_set = rss * page_size_kb;

  cout << "VM: " << vm_usage << "; RSS: " << resident_set << endl;
}

//////////////////////////////////////////////////

int d[MAXK];
Map m;

int chances(std::vector<int> &v) {
  Set set;
  set.insert(0);

  for (std::vector<int>::iterator val = v.begin(); val != v.end(); val++) {
    Set t;

    for (Set::const_iterator pre = set.begin(); pre != set.end(); pre++) {
      t.insert((*pre) + (*val));
      t.insert((*pre) - (*val));
    }

    set = t;
  }

  return set.size();
}

// k start with 1
// xs, ys start with {0}
void solve(int k, std::vector<int> &xs, std::vector<int> &ys) {
  // if (k > MAXK) return;
  if (k > MAXK)
    return;
  process_mem_usage();

  std::string keyX = vec2str(xs), keyY = vec2str(ys);
  // std::cout << "k" << k << '\t';
  // std::cout << "keyX" << keyX << '\t';
  // std::cout << "keyY" << keyY << '\n';

  if (m.find(keyX) == m.end()) {
    m.insert(Map::value_type(keyX, chances(xs)));
  }

  if (m.find(keyY) == m.end()) {
    m.insert(Map::value_type(keyY, chances(ys)));
  }

  d[k - 1] += m.at(keyX) * m.at(keyY);
  d[k - 1] %= MOD;

  xs.push_back(k);
  solve(k + 1, xs, ys);

  xs.pop_back();
  ys.push_back(k);
  solve(k + 1, xs, ys);
  ys.pop_back();
}

int main(int argc, char const *argv[]) {
  // memset(d, 0, MAXK);

  // https://stackoverflow.com/a/2236225
  std::vector<int> xs;
  std::vector<int> ys;

  solve(1, xs, ys);

  int T, K;
  std::cin >> T;
  while (T--) {
    std::cin >> K;

    std::cout << d[K] << '\n';
  }
  return 0;
}
