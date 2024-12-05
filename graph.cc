#include "graph.h"

Graph::Graph() {}

Graph::Graph(const std::string filename) { ReadFromFile(filename); }

Graph::~Graph() { file.close(); }

void Graph::ParseFile() {
  std::string str;
  file >> str;
  int size = std::stoi(str);

  for (int i = 0; i < size; i++) {
    graph.push_back({});
    for (int j = 0; j < size; j++) {
      if (!(file >> str)) {
        throw std::invalid_argument(
            "-------------\ninvalid matrix\n------------------------");
      }
      graph[i].push_back(std::stoi(str));
      if (std::stoi(str) > 1)
        graph_stats.weighted_ = 1;
    }
  }
  if (isDiagonalMatrix()) {
    graph_stats.directed_ = 1;
  }
}

void Graph::ReadFromFile(const std::string filename) {
  file.open(filename, std::ios::in);
  if (!file) {
    throw std::invalid_argument(
        "-------------\nfile doesn't exist\n------------------------");
  }
}

void Graph::WriteToFile(const std::string filename) {
  file.open(filename, std::ios::out);
  if (!file) {
    throw std::invalid_argument(
        "-------------\nfile doesn't exist\n------------------------");
  }
}

std::string Graph::ConvertVectorToString(const std::vector<int> v) {
  std::string result;
  for (auto i : v) {
    result.append(std::to_string(i));
    result.append(";\n");
  }
  return std::string();
}

bool Graph::isDiagonalMatrix() {
  for (int i = 0; i < graph.size(); i++) {
    for (int j = 0; j < graph.size(); j++) {
      if (graph[i][j] != graph[j][i])
        return true;
    }
  }
  return false;
}

bool Graph::isDirected()
{
    return graph_stats.directed_;
}

bool Graph::isWeighted()
{
    return graph_stats.weighted_;
}

void Graph::LoadGraphFromFile(const std::string filename) {
  if (file) {
    file.close();
  }
  ReadFromFile(filename);
  graph.clear();
  graph_stats.clear();
  ParseFile();
}

void Graph::ExportGraphToDot(const std::string filename) {
  std::vector<std::string> connection;
  if (file) {
    file.close();
  }
  WriteToFile(filename);
  if(graph_stats.directed_)
  file << "di";
  file << "graph graphname {\n";
  for (int i = 0; i < graph.size(); i++) {
    file << "v_" << std::to_string(i + 1) << ";\n";
    for (int j = 0; j < graph.size(); j++) {
      if (graph[i][j] && i != j) {
        if (graph_stats.directed_) {
          connection.push_back("v_" + std::to_string(i + 1) + " -> v_" +
                               std::to_string(j + 1));
        } else {
          connection.push_back("v_" + std::to_string(i + 1) + " -- v_" +
                               std::to_string(j + 1));
        }
      }
    }
  }
  for (auto i : connection) {
    file << i << ";\n";
  }
  file << "}";
}

const int Graph::size()
{
    return graph.size();
}

std::vector<std::vector<int>> Graph::getGraph()
{
    return graph;
}
