#include "ant_colony_algorithm.h"
#include <experimental/random>
#include <iostream>
AntColony::AntColony(const std::vector<std::vector<int>> &distanceMatrix)
    : graph(distanceMatrix), min_distance(std::numeric_limits<double>::max()) {
  pheromones.resize(graph.size(), std::vector<double>(graph.size(), 0.5));
}

void AntColony::exec() {
  srand(static_cast<unsigned>(time(0)));
  for (int it = 0; it < iterations; it++) {
    std::vector<std::vector<int>> visited_all;
    for (int i = 0; i < graph.size(); i++) {
      std::vector<int> visited(1, i);
      double distance = 0;
      int selected_city = i;
      while (1) {
        selected_city = SelectNextCity(selected_city, visited);
        if (selected_city == -1) {
          if (visited.size() != graph.size() || !graph[visited.size() - 1][i]) {
            break;
          } else {
            visited.push_back(i);
            distance +=
                graph[visited[visited.size() - 2]][visited[visited.size() - 1]];
            if (distance < min_distance) {
              min_distance = distance;
              best_decision = visited;
            }
            break;
          }
        }
        distance += graph[visited[visited.size() - 1]][selected_city];
        visited.push_back(selected_city);
      }
      visited_all.push_back(visited);
    }
    EvaporatePheromones();
    for (auto k : visited_all) {
      updatePheromones(k);
    }
  }
}

std::vector<int> AntColony::GetBestDecision() { return best_decision; }

double AntColony::GetMinDistance() { return min_distance; }

int AntColony::SelectNextCity(int current_node,
                              const std::vector<int> &visited) {
  double variate = std::experimental::randint(1, 99);
  double value = 0;
  double division = 0, divider = 0;
  std::vector<int> possible_ways = PossibleWays(graph[current_node], visited);
  for (auto i : possible_ways) {
    division += Calculation_1(current_node, i);
  }
  for (auto i : possible_ways) {
    divider = Calculation_1(current_node, i);
    value += divider * 100 / division;
    if (variate < value) {
      return i;
    }
  }
  return NO_WAY;
}

double AntColony::calculatePathLength(const std::vector<int> &path) {
  double path_length = 0;
  for (int i = 0; i < path.size() - 1; i++) {
    path_length += graph[path[i]][path[i + 1]];
  }
  return path_length;
}
void AntColony::updatePheromones(const std::vector<int> &visited) {
  double delta_tao = Q / calculatePathLength(visited);
  for (int i = 0; i < visited.size() - 1; i++) {
    pheromones[visited[i]][visited[i + 1]] += delta_tao;
  }
}

void AntColony::EvaporatePheromones() {
  for (int i = 0; i < pheromones.size(); i++) {
    for (int j = 0; j < pheromones.size(); j++) {
      pheromones[i][j] *= 1 - evaporation;
      if (pheromones[i][j] < 0.1)
        pheromones[i][j] = 0.1;
    }
  }
}
std::vector<int> AntColony::PossibleWays(std::vector<int> &node,
                                         const std::vector<int> &visited) {
  std::vector<int> result;
  for (int i = 0; i < node.size(); i++) {
    if (node[i]) {
      if (std::find(std::begin(visited), std::end(visited), i) ==
          std::end(visited))
        result.push_back(i);
    }
  }
  return result;
}

double AntColony::Calculation_1(int current_node, int i) {
  double v = 1 / (double)graph[current_node][i];
  return pow(pheromones[current_node][i], alpha) *
         pow(1 / (double)graph[current_node][i], beta);
}
