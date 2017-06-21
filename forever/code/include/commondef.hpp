#ifndef COMMONDEF_HPP
#define COMMONDEF_HPP

#include<vector>
#include<math.h>


namespace PATH_PLANNING{
struct carmodel{
    double w; //小车最大宽度
    double b; //驱动轮轮距
    double l; //小车长度
    double l_1; //小车车头到小车中心距离
    double l_2; //小车驱动轮轮距中心到小车中心的距离
};

template<typename T>
struct point2d{
    inline point2d():x(0),y(0){}
    inline point2d(T x_, T y_):x(x_),y(y_){}

    inline point2d(const point2d &point)
    {
        x = point.x;
        y = point.y;
    }

    inline point2d& operator = (const point2d &point)
    {
        x = point.x;
        y = point.y;
        return *this;
    }
    T x, y;
};
typedef point2d<int> Intpoint2d;
typedef point2d<double> Point2d;

enum AccessState{Space, Occupied, InOpenList, InClosedList}; //单元栅格访问
struct Grid{
    Grid():cellState(Space), g_core(0), h_core(0), parent(0, 0){}
    Grid& operator = (const Grid &grid)
    {
        cellState = grid.cellState;
        current   = grid.current;
        parent    = grid.parent;
        g_core    = grid.g_core;
        h_core    = grid.h_core;
        return *this;
    }

    int heuristic(Intpoint2d &goal)
    {
        h_core = fabs(current.x - goal.x) + fabs(current.y - goal.y);
        return h_core;
    }

    AccessState cellState;
    Intpoint2d current;
    Intpoint2d parent;
    int g_core;
    int h_core;
};

typedef std::vector<Intpoint2d> IntPath;
typedef std::vector<Point2d> Path;

}
#endif // COMMONDEF_HPP
