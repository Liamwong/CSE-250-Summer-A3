#ifndef A3_HPP
#define A3_HPP

#include "Maze.hpp"
#include <vector>
#include <queue>
//using std::vector;
using std::queue;
using std::pair;
using std::make_pair;

struct node {
    int x, y, distance;
};


// implement your function distance
int distance(Maze &maze, int sx, int sy, int fx, int fy) {
    queue <node> store;
    node begin = {sx, sy, 0};
    store.push(begin);
    maze.mark(sx, sy);
    int retVal = -1;
    while (!store.empty()) {
        node current = store.front();
        if (current.x == fx && current.y == fy) {
            retVal = current.distance;
            return retVal;
        }
        if (maze.is_open(current.x + 1, current.y && !maze.is_visited(current.x + 1, current.y))) {
            maze.mark(current.x + 1, current.y);
            node n = current;
            n.x++;
            n.distance++;
            store.push(n);
        }
        if (maze.is_open(current.x - 1, current.y) && !maze.is_visited(current.x - 1, current.y)) {
            maze.mark(current.x - 1, current.y);
            node n = current;
            n.x--;
            n.distance++;
            store.push(n);
        }
        if (maze.is_open(current.x, current.y + 1) && !maze.is_visited(current.x, current.y + 1)) {
            maze.mark(current.x, current.y + 1);
            node n = current;
            n.y++;
            n.distance++;
            store.push(n);
        }
        if (maze.is_open(current.x, current.y - 1) && !maze.is_visited(current.x, current.y - 1)) {
            maze.mark(current.x, current.y - 1);
            node n = current;
            n.y--;
            n.distance++;
            store.push(n);
        }
        store.pop();
    }
    return retVal;
} // distance

#endif // A3_HPP
