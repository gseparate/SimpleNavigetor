#ifndef S21_GRAPH_ALGORITHMS
#define S21_GRAPH_ALGORITHMS
#include "ant_colony_algorithm.h"
#include "graph.h"
#include "help_func.h"
#include "lib/queue/team_queue.h"
#include "lib/stack/team_stack.h"
#define INF std::numeric_limits<int>::max()
#define INF_D std::numeric_limits<double>::max()
#define INVALID_VAL -1
typedef struct TsmResult {
  std::vector<int> path;
  double distance = INF;
} TsmResult;

class GraphAlgorithms {
public:
  GraphAlgorithms();
  ~GraphAlgorithms();

public:
  std::vector<int> DepthFirstSearch(Graph &graph, int start_vertex);
  std::vector<int> BreadthFirstSearch(Graph &graph, int start_vertex);
  int GetShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
  std::vector<std::vector<int>>
  GetShortestPathsBetweenAllVertices(Graph &graph);
  std::vector<std::vector<int>> GetLeastSpanningTree(Graph &graph);
  TsmResult SolveTravelingSalesmanProblem(Graph &graph);

private:
  bool isBothInVector(std::vector<int> v, int val_i, int val_j);
  std::pair<int, int> FindMinCell(std::vector<std::vector<int>> src,
                                  std::vector<int> inMst);
  std::vector<std::vector<int>> InitAntsMatrix(int size, int val);

private:
  std::vector<int> possible_ways(std::vector<int> &node);
};
#endif // S21_GRAPH_ALGORITHMS