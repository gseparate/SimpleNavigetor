#ifndef HELP_FUNC_H
#define HELP_FUNC_H
#include "lib/stack/team_stack.h"
#include <vector>
// #include
bool ValueIn(const std::vector<int>& v, int val);
bool VectorHasSign(std::vector<int> v);
int min(int x, int y);
std::vector<int> min_v(std::vector<int>);
int MinValueIndex(const std::vector<int> &v);
// bool ValueInTop(const team::stack<int>& s, int val);
#endif