#include "s21_console_ui.h"
ConsoleUi::ConsoleUi(/* args */) {}

ConsoleUi::~ConsoleUi() {}
void ConsoleUi::Greeting() {
  std::cout << "###########################################\n";
  std::cout << "Welcome to graph algorithms decider\n";
  std::cout << "Load the file in adjacency matrix format\n";
  std::cout << "###########################################\n\n";
}

void ConsoleUi::ChooseOption() {
  std::cout << "Select 1 to load new graph from file\n";
  std::cout << "Select 2 to export to file\n";
  std::cout << "Select 3 to choose \"Depth First Search\" algorithm\n";
  std::cout << "Select 4 to choose \"Breadth First Search\" algorithm\n";
  std::cout << "Select 5 to choose \"Dijkstra's algorithm "
               "(GetShortestPathBetweenVertices)\"\n";
  std::cout << "Select 6 to choose \"Floyd-Warshall algorithm "
               "(GetShortestPathsBetweenAllVertices)\"\n";
  std::cout
      << "Select 7 to choose \"Prim's algorithm (GetLeastSpanningTree)\"\n";
  std::cout << "Select 8 to choose \"ant colony algorithm. "
               "(SolveTravelingSalesmanProblem)\"\n";
  std::cout << "Select 9 to choose exit from app\n";
}

void ConsoleUi::LoadFile() {
  std::cout << "enter file's name: ";
  std::cin >> filename_;
  graph_.LoadGraphFromFile(filename_);
  std::cout << "file loaded\n\n";
}

void ConsoleUi::ExportFile() {
  std::cout << "enter file's name: ";
  std::cin >> filename_;
  graph_.ExportGraphToDot(filename_);
  std::cout << "file loaded\n\n";
}

void ConsoleUi::DepthSearch() {
  std::vector<int> v;
  std::string x;
  std::cout << "Select start node: ";
  std::cin >> x;
  bool valid_val = isCorrectValue(x);
  if (valid_val == true)
    v = algorithms_.DepthFirstSearch(graph_, std::stoi(x));
  if (!v.empty()) {
    std::cout << "depth: ";
    for (auto i : v) {
      std::cout << i << ' ';
    }
  } else {
    std::cout << "can't be executed\n";
  }
  std::cout << "\n\n";
}

void ConsoleUi::BreadSearch() {
  bool invalid_val = false;
  std::vector<int> v;
  std::string x;
  std::cout << "Select start node: ";
  std::cin >> x;
  bool valid_val = isCorrectValue(x);
  if (valid_val == true)
    v = algorithms_.BreadthFirstSearch(graph_, std::stoi(x));
  if (!v.empty()) {
    std::cout << "bread: ";
    for (auto i : v) {
      std::cout << i << ' ';
    }
  } else {
    std::cout << "can't be executed\n";
  }
  std::cout << "\n\n";
}

void ConsoleUi::GetShortestPathBetweenVertices() {
  int result = -1;
  std::string x, y;
  std::cout << "Select start node: ";
  std::cin >> x;
  std::cout << "Select finish node: ";
  std::cin >> y;
  bool valid_x = isCorrectValue(x);
  bool valid_y = isCorrectValue(y);
  if (valid_x && valid_y)
    result = algorithms_.GetShortestPathBetweenVertices(graph_, std::stoi(x),
                                                        std::stoi(y));
  if (result == -1) {
    std::cout << "can't be executed\n";
  } else {
    std::cout << "Shortest path: " << result << "\n\n";
  }
}

void ConsoleUi::GetShortestPathBetweenAllVertices() {
  std::vector<std::vector<int>> z =
      algorithms_.GetShortestPathsBetweenAllVertices(graph_);
  std::cout << "Shortest path between all vertices: \n";
  for (auto i : z) {
    for (auto j : i) {
      std::cout << j << ' ';
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void ConsoleUi::GetLeastSpanningTree() {
  std::vector<std::vector<int>> z = algorithms_.GetLeastSpanningTree(graph_);
  std::cout << "Least Spanning Tree: \n";
  for (auto i : z) {
    for (auto j : i) {
      std::cout << j << ' ';
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void ConsoleUi::SolveTravelingSalesmanProblem() {
  TsmResult result = algorithms_.SolveTravelingSalesmanProblem(graph_);
  std::cout << "distance: " << result.distance << '\n';
  for (auto i : result.path) {
    std::cout << i << ' ';
  }
  std::cout << "\n\n";
}

bool ConsoleUi::isCorrectValue(const std::string &str) {
  for (auto i : str) {
    if (!isdigit(i)) {
      return false;
    }
  }
  return true;
}

void ConsoleUi::ClearConsole() {
  if (system("CLS"))
    system("clear");
}

void ConsoleUi::GoodbyeFunc() {
  std::cout << "goodbye!\n";
  sleep(1);
}

void ConsoleUi::Continue() {
      std::cout << "Enter to continue:";
    char r = getchar();
}

void ConsoleUi::exec() {
  ClearConsole();
  char ch = 1;
  Greeting();
  LoadFile();
  ChooseOption();
  while (getchar()) {
    ClearConsole();
    ChooseOption();
    std::cout << "enter number: ";
    std::cin >> ch;
    if (ch == '1') {
      LoadFile();
    } else if (ch == '2') {
      ExportFile();
    } else if (ch == '3') {
      DepthSearch();
    } else if (ch == '4') {
      BreadSearch();
    } else if (ch == '5') {
      GetShortestPathBetweenVertices();
    } else if (ch == '6') {
      GetShortestPathBetweenAllVertices();
    } else if (ch == '7') {
      GetLeastSpanningTree();
    } else if (ch == '8') {
      SolveTravelingSalesmanProblem();
    } else if (ch == '9') {
      GoodbyeFunc();
      break;
    }
    Continue();
  }
  ClearConsole();
}
