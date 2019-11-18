#ifndef DIJKSTRA
#define DIJKSTRA

#include <queue>
#include <tuple>
#include <climits>
#include "../board/board.hpp"
#include "../cells/cell.hpp"

class Dijkstra{
  public:
    /* Return the next hop calculated with dijkstra between source and destination */
    static pair<int, int> dijkstra(Board* b, pair<int, int> s, pair<int, int> dest);
};

#endif
