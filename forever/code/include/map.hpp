#ifndef MAP_HPP
#define MAP_HPP

#include<string>
#include<assert.h>
#include"commondef.hpp"


namespace PATH_PLANNING{

#define MAP_POINT_NUMS 5000
class Map{
public:
    Map(){}
    Map(std::string directory, double delta = 1);
    Map(Map &map);
    ~Map()
    {
        for(int i = 0; i < m_mapSizeX; i++)
        {
            if(NULL != m_gridMap[i])
            {
                delete [] m_gridMap[i];
                m_gridMap[i] = NULL;
            }
        }
        if(NULL != m_gridMap)
        {
            delete [] m_gridMap;
            m_gridMap = NULL;
        }

        if(NULL != m_pPoint2d)
        {
            delete m_pPoint2d;
            m_pPoint2d = NULL;
        }
    }

    void loadMapdata(std::string directory);
    void createGridMap();
    void resetGridMap();//重置每个栅格对应的A* param

    Intpoint2d world2map(Point2d p);
    Point2d map2world(Intpoint2d p);
    AccessState cellState(int x, int y);
    AccessState cellState(Intpoint2d p);
    Grid& operator () (int x, int y);
    Grid& operator () (Intpoint2d p);
    bool isInside(int pt_x, int pt_y);
    bool isInside(Intpoint2d &point);

private:
    Point2d *m_pPoint2d;
    int m_numsofPoint2d;
    double m_xmin, m_ymin;
    double m_xmax, m_ymax;

    Point2d m_center;
    double m_worldSizeX, m_worldSizeY;
    double m_delta;
    Grid ** m_gridMap;
    int m_mapSizeX, m_mapSizeY;
    int m_SizeX2, m_SizeY2;
};

}


#endif // MAP_HPP
