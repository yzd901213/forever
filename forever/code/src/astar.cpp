#include "astar.hpp"

namespace PATH_PLANNING{

int AStar::runAstar(Intpoint2d &start, Intpoint2d &goal, Path &path)
{
    path.clear();
    if(!m_map.isInside(start) || !m_map.isInside(goal))
    {
        return 0;
    }

    Grid &curgrid = m_map(start);
    curgrid.cellState = InOpenList;
    m_openList.insert(OpenList::value_type(curgrid.heuristic(goal)+curgrid.g_core, start));
    bool path_found = false;
    enum move{Front, Back, Left, Right, Done};
    while(m_openList.begin() != m_openList.end())
    {
        OpenList::iterator iter = m_openList.begin();
        Grid &curgrid = m_map((Intpoint2d)iter->second);
        curgrid.cellState = InClosedList;
        m_openList.erase(iter);
        int cx = curgrid.current.x;
        int cy = curgrid.current.y;
        int nx, ny;
        move mode = Front;
        do{
            switch (mode) {
            case Front:
                nx = cx + 1;
                ny = cy;
                mode = Back;
                break;
            case Back:
                nx = cx - 1;
                ny = cy;
                mode = Left;
                break;
            case Left:
                nx = cx;
                ny = cy - 1;
                mode = Right;
                break;
            case Right:
                nx = cx;
                ny = cy + 1;
                mode = Done;
                break;
            default:
                break;
            }            
            if(!m_map.isInside(nx, ny)) continue;
            Grid &tempgrid = m_map(nx, ny);

            if(tempgrid.cellState == Occupied ||
                    tempgrid.cellState == InOpenList)

            {
                continue;
            }

            if(tempgrid.cellState != InClosedList)
            {
                tempgrid.g_core = curgrid.g_core + 1;
                tempgrid.cellState = InOpenList;
                m_openList.insert(OpenList::value_type(tempgrid.heuristic(goal)+tempgrid.g_core, tempgrid.current));
                tempgrid.parent = curgrid.current;
            }
            else
            {
                int gcore = curgrid.g_core + 1;
                if(tempgrid.g_core > gcore)
                {
                    tempgrid.g_core = gcore;
                    tempgrid.parent = curgrid.current;
                }
            }

        }while(mode != Done);

        if(m_map(goal).cellState == InOpenList)
        {
            path_found = true;
            break;
        }
    }

    if(path_found)
    {
        m_start = start;
        m_goal  = goal;
        findPath(path);
        resetAstar();
        return 1;
    }

    return 0;
}

void AStar::findPath(Path &path)
{
//    path.push_back(m_goal);
//    Intpoint2d parent = m_map(m_goal).parent;
//    while(parent.x != m_start.x || parent.y != m_start.y)
//    {
//        path.push_back(parent);
//        parent = m_map(parent).parent;
//    }
//    path.push_back(parent);
//    std::reverse(path.begin(), path.end());//需看实际使用是否进行翻转
}

void AStar::resetAstar()
{
    m_openList.erase(m_openList.begin(), m_openList.end());
    m_start = Intpoint2d();
    m_goal = Intpoint2d();
    m_map.resetGridMap();
}

}
