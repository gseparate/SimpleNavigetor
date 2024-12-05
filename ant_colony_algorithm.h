#ifndef ANT_COLONY_ALGORITHM_H
#define ANT_COLONY_ALGORITHM_H
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <random>
#define NO_WAY -1 
class AntColony {
public:
  AntColony(const std::vector<std::vector<int>> &distanceMatrix);
  void exec();
  std::vector<int> GetBestDecision();
  double GetMinDistance();
private:
  std::vector<std::vector<int>> graph;
  std::vector<std::vector<double>> pheromones;
  std::vector<int> answer;
  double min_distance;
  std::vector<int> best_decision;

  int iterations = 500;
  const double alpha = 1;
  const double beta = 2;
  const double Q = 4;
  const double evaporation = 0.04;
private:
  int SelectNextCity(int current_node, const std::vector<int> &visited);
  double calculatePathLength(const std::vector<int> &path);
  void updatePheromones(const std::vector<int>& visited);
  void EvaporatePheromones();
  std::vector<int> PossibleWays(std::vector<int> &node, const std::vector<int> &visited);
  double Calculation_1(int current_node, int i);
};
#endif // ANT_COLONY_ALGORITHM_H