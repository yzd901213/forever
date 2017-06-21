#ifndef ASTAR_HPP
#define ASTAR_HPP

#include "map.hpp"
#include <map>
#include <algorithm>


namespace PATH_PLANNING {
struct compareFcost{
    bool operator () (const int &a, const int &b)
    {
        return a >= b;
    }

};
typedef std::map<int, Intpoint2d, compareFcost> OpenList;

class AStar{
public:
    AStar(){}
    AStar(Map &map):m_map(map){}
    ~AStar(){}

    int runAstar(Intpoint2d &start, Intpoint2d &goal, Path &path);

private:
    void findPath(Path &path);
    void resetAstar();//清空openlist并重置map


private:
    Map m_map;
    OpenList m_openList;
    Intpoint2d m_start;
    Intpoint2d m_goal;
};
}

#endif // ASTAR_HPP
