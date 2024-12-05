#include <list>

#include "team_list.h"
template <class Type>
bool container_comparison(std::list<Type> std_list, team::list<Type> team_list) {
  auto it_std_list = std_list.begin();
  auto it_team_list = team_list.begin();
  while (it_team_list != team_list.end()) {
    auto value = *it_team_list - *it_std_list;
    if ((value > 1e-7) || (value < -1e-7)) {
      return false;
    }
    it_team_list++;
    it_std_list++;
  }
  return true;
}

TEST(List, st_cost) {
  team::list<double> team_list;
  std::list<double> std_list;
  ASSERT_EQ(std_list.size(), team_list.size());
}

TEST(List, size) {
  team::list<double> team_list(35);
  std::list<double> std_list(35);
  ASSERT_EQ(std_list.size(), team_list.size());
  EXPECT_TRUE(container_comparison(std_list, team_list));
}

TEST(List, initializer_list) {
  team::list<int> team_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  EXPECT_TRUE(container_comparison(std_list, team_list));
}

TEST(List, copy) {
  team::list<double> team_first = {3.4, 2.5, 3.4, 2.423455};
  std::list<double> std_first = {3.4, 2.5, 3.4, 2.423455};
  team::list<double> team_second = team_first;
  std::list<double> std_second = std_first;
  EXPECT_TRUE(container_comparison(std_second, team_second));
}

TEST(List, copy2) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  team::list<double> team_second;
  std::list<double> std_first = {3.423, 2.5234, 3.4567, 2.423455};
  std::list<double> std_second;
  team_second = team_first;
  std_second = std_first;
  EXPECT_TRUE(container_comparison(std_second, team_second));
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, move) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  std::list<double> std_first = {3.423, 2.5234, 3.4567, 2.423455};
  team::list<double> team_second = std::move(team_first);
  std::list<double> std_second = std::move(std_first);
  EXPECT_TRUE(container_comparison(std_second, team_second));
}

TEST(List, move2) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  team::list<double> team_second;
  std::list<double> std_first = {3.423, 2.5234, 3.4567, 2.423455};
  std::list<double> std_second;
  team_second = std::move(team_first);
  std_second = std::move(std_first);
  EXPECT_TRUE(container_comparison(std_second, team_second));
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, front) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  std::list<double> std_first = {3.423, 2.5234, 3.4567, 2.423455};
  ASSERT_NEAR(team_first.front(), std_first.front(), 1e-7);
}

TEST(List, back) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  std::list<double> std_first = {3.423, 2.5234, 3.4567, 2.423455};
  ASSERT_DOUBLE_EQ(team_first.back(), std_first.back());
}

TEST(List, begin) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  std::list<double> std_first = {3.423, 2.5234, 3.4567, 2.423455};
  ASSERT_DOUBLE_EQ(*team_first.begin(), *std_first.begin());
}

TEST(List, empty) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  std::list<double> std_first = {3.423, 2.5234, 3.4567, 2.423455};
  team::list<double> team_second;
  std::list<double> std_second;
  EXPECT_TRUE(team_first.empty() == std_first.empty());
  EXPECT_TRUE(team_second.empty() == std_second.empty());
}

TEST(List, size2) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  std::list<double> std_first = {3.423, 2.5234, 3.4567, 2.423455};
  EXPECT_TRUE(team_first.size() == std_first.size());
}

TEST(List, clear) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  std::list<double> std_first = {3.423, 2.5234, 3.4567, 2.423455};
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, insert) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  std::list<double> std_first = {3.423, 2.5234, 3.4567, 2.423455};
  auto it_std_list = std_first.begin();
  auto it_team_list = team_first.begin();
  team_first.insert(it_team_list, 345.345634);
  std_first.insert(it_std_list, 345.345634);
  EXPECT_TRUE(container_comparison(std_first, team_first));
  ++it_std_list;
  ++it_std_list;
  ++it_team_list;
  ++it_team_list;
  team_first.insert(it_team_list, 4325.3456);
  std_first.insert(it_std_list, 4325.3456);
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, earse) {
  team::list<double> team_first = {3.423,     2.5234,       3.4567,   2.423455,
                                 42545.123, 4563456.7564, 6543.6436};
  std::list<double> std_first = {3.423,     2.5234,       3.4567,   2.423455,
                                 42545.123, 4563456.7564, 6543.6436};
  auto it_std_list = std_first.begin();
  auto it_team_list = team_first.begin();
  std_first.erase(it_std_list);
  team_first.erase(it_team_list);
  EXPECT_TRUE(container_comparison(std_first, team_first));
  it_std_list = std_first.begin();
  it_team_list = team_first.begin();
  --it_std_list;
  --it_std_list;
  it_team_list--;
  it_team_list--;
  std_first.erase(it_std_list);
  team_first.erase(it_team_list);
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, push_back) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  std::list<double> std_first = {3.423, 2.5234, 3.4567, 2.423455};
  team_first.push_back(534.532);
  team_first.push_back(0.432456);
  std_first.push_back(534.532);
  std_first.push_back(0.432456);
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, pop_back) {
  team::list<double> team_first = {3.423,     2.5234,       3.4567,   2.423455,
                                 42545.123, 4563456.7564, 6543.6436};
  std::list<double> std_first = {3.423,     2.5234,       3.4567,   2.423455,
                                 42545.123, 4563456.7564, 6543.6436};
  team_first.pop_back();
  team_first.pop_back();
  std_first.pop_back();
  std_first.pop_back();
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, push_front) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  std::list<double> std_first = {3.423, 2.5234, 3.4567, 2.423455};
  team_first.push_front(534.532);
  team_first.push_front(0.432456);
  std_first.push_front(534.532);
  std_first.push_front(0.432456);
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, pop_front) {
  team::list<double> team_first = {3.423,     2.5234,       3.4567,   2.423455,
                                 42545.123, 4563456.7564, 6543.6436};
  std::list<double> std_first = {3.423,     2.5234,       3.4567,   2.423455,
                                 42545.123, 4563456.7564, 6543.6436};
  team_first.pop_front();
  team_first.pop_front();
  std_first.pop_front();
  std_first.pop_front();
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, swap) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  team::list<double> team_second = {53.543, 234.543, 436.543, 6436.435};
  std::list<double> std_first = {3.423, 2.5234, 3.4567, 2.423455};
  std::list<double> std_second = {53.543, 234.543, 436.543, 6436.435};
  team_first.swap(team_second);
  std_first.swap(std_second);
  EXPECT_TRUE(container_comparison(std_first, team_first));
  EXPECT_TRUE(container_comparison(std_second, team_second));
}

TEST(List, reverce) {
  team::list<double> team_first = {3.423,     2.5234,       3.4567,   2.423455,
                                 42545.123, 4563456.7564, 6543.6436};
  std::list<double> std_first = {3.423,     2.5234,       3.4567,   2.423455,
                                 42545.123, 4563456.7564, 6543.6436};
  team_first.reverse();
  std_first.reverse();
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, unique) {
  team::list<double> team_first = {1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4,
                                 5, 6, 6, 6, 7, 7, 8, 8, 8, 9};
  std::list<double> std_first = {1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4,
                                 5, 6, 6, 6, 7, 7, 8, 8, 8, 9};
  team_first.unique();
  std_first.unique();
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, sort) {
  team::list<double> team_first = {3.423,     2.5234,       3.4567,   2.423455,
                                 42545.123, 4563456.7564, 6543.6436};
  std::list<double> std_first = {3.423,     2.5234,       3.4567,   2.423455,
                                 42545.123, 4563456.7564, 6543.6436};
  team_first.sort();
  std_first.sort();
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, merge) {
  team::list<double> team_first = {3.423,    2.5234,  3.4567, 2.423455,
                                 4254.123, 45.7564, 65};
  std::list<double> std_first = {3.423,    2.5234,  3.4567, 2.423455,
                                 4254.123, 45.7564, 65};
  team::list<double> team_second = {53.543, 234.543, 436.543, 6436.435};
  std::list<double> std_second = {53.543, 234.543, 436.543, 6436.435};
  team_first.merge(team_second);
  std_first.merge(std_second);
  EXPECT_TRUE(container_comparison(std_first, team_first));
  EXPECT_TRUE(container_comparison(std_second, team_second));
}

TEST(List, splice) {
  team::list<double> team_first = {3.423,     2.5234,       3.4567,   2.423455,
                                 42545.123, 4563456.7564, 6543.6436};
  std::list<double> std_first = {3.423,     2.5234,       3.4567,   2.423455,
                                 42545.123, 4563456.7564, 6543.6436};
  team::list<double> team_second = {53.543, 234.543, 436.543, 6436.435};
  std::list<double> std_second = {53.543, 234.543, 436.543, 6436.435};
  auto it_std_list = std_first.begin();
  auto it_team_list = team_first.begin();
  it_std_list++;
  it_std_list++;
  ++it_team_list;
  ++it_team_list;
  team_first.splice(it_team_list, team_second);
  std_first.splice(it_std_list, std_second);
  EXPECT_TRUE(container_comparison(std_first, team_first));
  EXPECT_TRUE(container_comparison(std_second, team_second));
}

TEST(List, splice2) {
  team::list<double> team_first = {3.423,     2.5234,       3.4567,   2.423455,
                                 42545.123, 4563456.7564, 6543.6436};
  std::list<double> std_first = {3.423,     2.5234,       3.4567,   2.423455,
                                 42545.123, 4563456.7564, 6543.6436};
  team::list<double> team_second = {53.543, 234.543, 436.543, 6436.435};
  std::list<double> std_second = {53.543, 234.543, 436.543, 6436.435};
  auto it_std_list = std_first.begin();
  auto it_team_list = team_first.begin();
  team_first.splice(it_team_list, team_second);
  std_first.splice(it_std_list, std_second);
  EXPECT_TRUE(container_comparison(std_first, team_first));
  EXPECT_TRUE(container_comparison(std_second, team_second));
}

TEST(List, max_size) {
  team::list<double> team_first;
  std::list<double> std_first;
  ASSERT_EQ(team_first.max_size(), std_first.max_size());
}

TEST(List, list_iterator) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  team::list<double>::iterator it = team_first.begin();
  team::list<double>::iterator it_second = std::move(it);
  EXPECT_TRUE(it_second == team_first.begin());
}

TEST(List, list_iterator2) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  team::list<double>::iterator it = team_first.begin();
  team::list<double>::iterator it_second = std::move(it);
  EXPECT_TRUE(it_second == team_first.begin());
}

TEST(List, list_iterator_const) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  team::list<double>::const_iterator first_it = team_first.begin();
  team::list<double>::const_iterator second_it = first_it;
  EXPECT_TRUE(second_it == team_first.begin());
}

TEST(List, list_iterator_const2) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  team::list<double>::const_iterator first_it = team_first.begin();
  team::list<double>::const_iterator second_it = std::move(first_it);
  first_it = second_it;
  EXPECT_TRUE(second_it == team_first.begin());
}

TEST(List, list_iterator_const3) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  team::list<double>::const_iterator first_it = team_first.begin();
  team::list<double>::const_iterator second_it = team_first.end();
  second_it = std::move(first_it);
  EXPECT_TRUE(second_it == team_first.begin());
}

TEST(List, list_iterator_const4) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  team::list<double>::const_iterator first_it = team_first.begin();
  team::list<double>::const_iterator second_it = team_first.begin();
  first_it++;
  second_it++;
  ++first_it;
  ++second_it;
  EXPECT_FALSE(first_it != second_it);
}

TEST(List, list_iterator_const5) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  team::list<double>::const_iterator first_it = team_first.end();
  team::list<double>::const_iterator second_it = team_first.end();
  --first_it;
  --second_it;
  first_it--;
  second_it--;
  EXPECT_TRUE(*first_it == *second_it);
}

TEST(List, list_iterator_3) {
  team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  team::list<double>::iterator first_it = team_first.begin();
  team::list<double>::iterator second_it = team_first.begin();
  first_it++;
  second_it++;
  EXPECT_FALSE(first_it != second_it);
  EXPECT_TRUE(first_it == second_it);
}

TEST(List, list_iterator_4) {
  const team::list<double> team_first = {3.423, 2.5234, 3.4567, 2.423455};
  auto first_it = team_first.begin();
  auto second_it = team_first.begin();
  first_it++;
  second_it++;
  EXPECT_FALSE(first_it != second_it);
  EXPECT_TRUE(first_it == second_it);
}

TEST(List, exeptions) {
  team::list<int> team_first = {1, 2, 3, 4, 5};
  team::list<int>::iterator iter1;
  ASSERT_THROW(*iter1, std::invalid_argument);
  ASSERT_THROW(team_first.erase(team_first.end()), std::invalid_argument);
}

TEST(List, emplace) {
  team::list<int> team_first = {2, 3, 4, 5};
  std::list<int> std_first = {2, 3, 4, 5};
  std_first.emplace(std_first.begin(), 1);
  team_first.emplace(team_first.begin(), 1);
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, emplace_many_args) {
  team::list<int> team_first = {1, 2, 8, 9, 0};
  std::list<int> std_first = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  auto first_it = ++team_first.begin();
  first_it++;
  team_first.emplace(first_it, 3, 4, 5, 6, 7);
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, emplace_front) {
  team::list<double> team_first = {2, 3, 4, 5};
  std::list<double> std_first = {2, 3, 4, 5};
  std_first.emplace_front(2.345);
  team_first.emplace_front(2.345);
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, emplace_front_many_args) {
  team::list<int> team_first = {5, 6, 7, 8, 9, 0};
  std::list<int> std_first = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  team_first.emplace_front(4, 3, 2, 1);
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, emplace_back) {
  team::list<double> team_first = {2, 3, 4, 5};
  std::list<double> std_first = {2, 3, 4, 5};
  std_first.emplace_back(543.2345);
  team_first.emplace_back(543.2345);
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(List, emplace_back_many_args) {
  team::list<int> team_first = {1, 2, 3, 4, 5};
  std::list<int> std_first = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  team_first.emplace_back(6, 7, 8, 9, 0);
  EXPECT_TRUE(container_comparison(std_first, team_first));
}

TEST(ListInsertTest, InsertAtEnd) {
  team::list<int> myList;

  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);

  auto it = myList.end();

  myList.insert(it, 4);

  EXPECT_EQ(myList.back(), 4);
  EXPECT_EQ(myList.size(), 4);
}

TEST(ListPopFrontTest, PopFrontNotEmptyNotEqual) {
  team::list<int> myList;

  myList.push_back(42);
  myList.push_back(43);
  myList.push_back(44);

  myList.pop_front();

  EXPECT_EQ(myList.front(), 43);
}

TEST(ListPopFrontTest, PopFrontOnlyOneElement) {
  team::list<int> myList;

  myList.push_back(42);

  myList.pop_front();

  EXPECT_TRUE(myList.empty());
}

TEST(ListContainerComparisonTest, WithinRange) {
  team::list<double> team_list = {1.0, 2.0, 3.0};
  std::list<double> std_list = {1.0, 2.0000001, 3.0};

  EXPECT_TRUE(container_comparison(std_list, team_list));
}

TEST(ListContainerComparisonTest, OutsideRange) {
  team::list<double> team_list = {1.0, 2.0, 3.0};
  std::list<double> std_list = {1.0, 2.1, 3.0};
  EXPECT_FALSE(container_comparison(std_list, team_list));
}