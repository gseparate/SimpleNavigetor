#ifndef S21_CONSOLE_UI_H
#define S21_CONSOLE_UI_H
#include "graph.h"
#include "s21_graph_algorithms.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
class ConsoleUi {
private:
  Graph graph_;
  GraphAlgorithms algorithms_;
  std::string filename_;
private:
  void Greeting();
  void ChooseOption();
  void LoadFile();
  void ExportFile();
  void DepthSearch();
  void BreadSearch();
  void GetShortestPathBetweenVertices();
  void GetShortestPathBetweenAllVertices();
  void GetLeastSpanningTree();
  void SolveTravelingSalesmanProblem();
  bool isCorrectValue(const std::string& str);
  void ClearConsole();
  void GoodbyeFunc();
  void Continue();
public:
  ConsoleUi(/* args */);
  ~ConsoleUi();
  void exec();
};

#endif