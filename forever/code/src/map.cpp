#include "map.hpp"

namespace PATH_PLANNING {
void Map::loadMapdata(std::string directory)
{
    //加载地图数据文件，保存置数组m_pPoint2d
    //....
    m_pPoint2d = new Point2d[MAP_POINT_NUMS];

    //边界滤波，并获取边界上下限

}

void Map::createGridMap()
{

}

void Map::resetGridMap()
{
    for(int i = 0; i < m_mapSizeX; i++)
    {
        for(int j = 0; j < m_mapSizeY; j++)
        {
            if(m_gridMap[i][j].cellState != Space ||
                    m_gridMap[i][j].cellState != Occupied)
            {
                m_gridMap[i][j].cellState = Space;
            }
            m_gridMap[i][j].current = Intpoint2d();
            m_gridMap[i][j].parent  = Intpoint2d();
            m_gridMap[i][j].g_core = 0;
            m_gridMap[i][j].h_core = 0;
        }
    }
}

Intpoint2d Map::world2map(Point2d p)
{
    //...
}

Point2d Map::map2world(Intpoint2d p)
{
    //...
}


AccessState Map::cellState(int x, int y)
{
    assert(x >= 0 && y >= 0 && x < m_mapSizeX && y < m_mapSizeY);
    return m_gridMap[x][y].cellState;
}

AccessState Map::cellState(Intpoint2d p)
{
    assert(p.x >= 0 && p.y >= 0 && p.x < m_mapSizeX && p.y < m_mapSizeY);
    return m_gridMap[p.x][p.y].cellState;
}

Grid &Map::operator ()(int x, int y)
{
    assert(x >= 0 && y >= 0 && x < m_mapSizeX && y < m_mapSizeY);
    return m_gridMap[x][y];
}

Grid &Map::operator ()(Intpoint2d p)
{
    assert(p.x >= 0 && p.y >= 0 && p.x < m_mapSizeX && p.y < m_mapSizeY);
    return m_gridMap[p.x][p.y];
}

bool Map::isInside(int pt_x, int pt_y)
{
    if(pt_x < 0 || pt_x >= m_mapSizeX ||
            pt_y < 0 || pt_y >= m_mapSizeY)
    {
        return false;
    }
    return true;
}

bool Map::isInside(Intpoint2d &point)
{
    if(point.x < 0 || point.x >= m_mapSizeX ||
            point.y < 0 || point.y >= m_mapSizeY)
    {
        return false;
    }
    return true;
}
}
