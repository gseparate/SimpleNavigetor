#include "help_func.h"

bool ValueIn(const std::vector<int> &v, int val) {
  for (auto i : v)
    if (val == i)
      return true;
  return false;
}
int MinValueIndex(const std::vector<int> &v) {
  int index = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] < v[index])
      index = i;
  }
  return index;
}
bool VectorHasSign(std::vector<int> v) {
  for (auto i : v)
    if (i < 0)
      return true;
  return false;
}
int min(int x, int y) { return (x < y) ? x : y; }
std::vector<int> min_v(std::vector<int> v) {
  std::vector<int> res = {0, std::numeric_limits<int>::max()};
  for (int i = 0; i < v.size(); i++) {
    if (v[i] < res[1]) {
      res = {i, v[i]};
    }
  }
  return res;
}
// bool ValueInTop(const team::stack<int>& s, int val) {
//   if (s.empty())
//     return false;
//     if(s.top() == val){
//         return true;
//     }else{
//         return false;
//     }
// }
