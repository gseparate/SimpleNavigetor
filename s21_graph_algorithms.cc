
#include "s21_graph_algorithms.h"
#include <algorithm>
#include <limits>
#include <utility>
GraphAlgorithms::GraphAlgorithms() {}

GraphAlgorithms::~GraphAlgorithms() {}

std::vector<int> GraphAlgorithms::DepthFirstSearch(Graph &graph,
                                                   int start_vertex) {
  if (start_vertex < 0 || start_vertex >= graph.size()) {
    return {};
  }
  std::vector<std::vector<int>> graph_copy = graph.getGraph();
  std::vector<int> result;
  team::stack<int> s;
  std::vector<int> visited;
  s.push(start_vertex);
  visited.push_back(s.top());
  while (!s.empty()) {
    result.push_back(s.top());
    s.pop();
    for (int j = graph_copy.size() - 1; j >= 0; j--) {
      if (graph_copy[result.back()][j] && !ValueIn(visited, j)) {
        s.push(j);
        visited.push_back(j);
      }
    }
  }
  return result;
}

std::vector<int> GraphAlgorithms::BreadthFirstSearch(Graph &graph,
                                                     int start_vertex) {
  if (start_vertex < 0 || start_vertex >= graph.size()) {
    return {};
  }
  std::vector<std::vector<int>> graph_copy = graph.getGraph();
  std::vector<int> visited;
  team::queue<int> q;
  q.push(start_vertex);
  visited.push_back(q.back());
  std::vector<int> result;
  while (!q.empty()) {
    result.push_back(q.back());
    q.pop();
    for (int j = 0; j < graph_copy.size(); j++) {
      if (graph_copy[result.back()][j] && !ValueIn(visited, j)) {
        visited.push_back(j);
        q.push(j);
      }
    }
  }
  return result;
}

int GraphAlgorithms::GetShortestPathBetweenVertices(Graph &graph, int vertex1,
                                                    int vertex2) {
  if (vertex1 == vertex2)
    return 0;
  else if (vertex1 < 0 || vertex2 < 0 || vertex1 >= graph.size() ||
           vertex2 >= graph.size()) {
    return INVALID_VAL;
  }
  std::vector<std::vector<int>> graph_copy = graph.getGraph();
  std::vector<int> dist(graph_copy.size(), INF);
  dist[vertex1] = 0;
  team::queue<std::pair<int, int>> q = {};
  q.push({vertex1, dist[vertex1]});
  while (!q.empty()) {
    for (int j = 0; j < graph_copy.size(); j++) {
      if (graph_copy[q.back().first][j] < 0)
        throw std::invalid_argument("negative number\n");
      if (graph_copy[q.back().first][j]) {
        if (q.back().second + graph_copy[q.back().first][j] < dist[j]) {
          dist[j] = q.back().second + graph_copy[q.back().first][j];
          q.push({j, dist[j]});
        }
      }
    }
    q.pop();
  }
  return dist[vertex2];
}

std::vector<std::vector<int>>
GraphAlgorithms::GetShortestPathsBetweenAllVertices(Graph &graph) {
  int x1, x2;
  std::vector<std::vector<int>> dist = graph.getGraph();
  for (int i = 0; i < dist.size(); i++) {
    for (int j = 0; j < dist.size(); j++) {
      if (dist[i][j] == 0 && i != j)
        dist[i][j] = INF;
    }
  }
  for (int k = 0; k < dist.size(); k++) {
    for (int i = 0; i < dist.size(); i++) {
      for (int j = 0; j < dist.size(); j++) {
        if (dist[i][j] && dist[i][k] != INF && dist[k][j] != INF) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }
  return dist;
}

std::vector<std::vector<int>>
GraphAlgorithms::GetLeastSpanningTree(Graph &graph) {
  if (graph.isDirected())
    throw std::logic_error("prim alghorithm can't be used in directed graph\n");
  std::vector<std::vector<int>> src = graph.getGraph();
  std::vector<std::vector<int>> mst(src.size(),
                                    std::vector<int>(src.size(), 0));
  std::vector<int> inMst;
  inMst.push_back(0);
  std::pair<int, int> min_cell = {0, 0};
  while (inMst.size() != src.size()) {
    min_cell = FindMinCell(src, inMst);
    mst[min_cell.first][min_cell.second] = src[min_cell.first][min_cell.second];
    mst[min_cell.second][min_cell.first] = src[min_cell.first][min_cell.second];
    inMst.push_back(min_cell.second);
  }
  return mst;
}

bool GraphAlgorithms::isBothInVector(std::vector<int> v, int val_i, int val_j) {
  if (std::find(std::begin(v), std::end(v), val_i) != std::end(v) &&
      std::find(std::begin(v), std::end(v), val_j) != std::end(v))
    return true;
  return false;
}

std::pair<int, int>
GraphAlgorithms::FindMinCell(std::vector<std::vector<int>> src,
                             std::vector<int> inMst) {
  std::pair<int, int> min_cell = {0, 0};
  for (auto i : inMst) {
    for (int j = 0; j < src.size(); j++) {
      if (src[i][j] && !(isBothInVector(inMst, i, j)) &&
          (min_cell.first == min_cell.second ||
           src[min_cell.first][min_cell.second] > src[i][j])) {
        min_cell.first = i, min_cell.second = j;
      }
    }
  }
  return min_cell;
}

std::vector<std::vector<int>> GraphAlgorithms::InitAntsMatrix(int size,
                                                              int val) {
  return std::vector<std::vector<int>>(size, std::vector<int>(size, val));
}

std::vector<int> GraphAlgorithms::possible_ways(std::vector<int> &node) {
  std::vector<int> result;
  for (int i = 0; i < node.size(); i++) {
    if (node[i]) {
      result.push_back(i);
    }
  }
  return result;
}

TsmResult GraphAlgorithms::SolveTravelingSalesmanProblem(Graph &graph) {
  TsmResult result;
  AntColony x(graph.getGraph());
  x.exec();
  result.distance = x.GetMinDistance();
  result.path = x.GetBestDecision();
  return result;
}