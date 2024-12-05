#ifndef GRAPH_H
#define GRAPH_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
// #include "lib/matrix/s21_matrix_oop.h"
class Graph {
private:
  std::fstream file;
  std::vector<std::vector<int>> graph;
  typedef struct GraphStats {
    GraphStats() { directed_ = 0, weighted_ = 0; };
    void clear() { directed_ = 0, weighted_ = 0; };
    bool directed_;
    bool weighted_;
  } GraphStats;
  GraphStats graph_stats;

public: // private
  void ParseFile();
  void ReadFromFile(const std::string filename);
  void WriteToFile(const std::string filename);
  std::string ConvertVectorToString(const std::vector<int> v);
  bool isDiagonalMatrix();
  bool isDirected();
  bool isWeighted();
public:
  Graph();
  Graph(const std::string filename);
  ~Graph();
  void LoadGraphFromFile(const std::string filename);
  void ExportGraphToDot(const std::string filename);
  const int size();
  std::vector<std::vector<int>> getGraph();
};
#endif // GRAPH_H