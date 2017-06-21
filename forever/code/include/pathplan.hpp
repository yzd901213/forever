#ifndef PATHPLAN_HPP
#define PATHPLAN_HPP

#include "commondef.hpp"
#include <string>
#include "boost/shared_array.hpp"

namespace PATH_PLANNING {
class PathPlan
{
public:
    PathPlan();
    ~PathPlan();
    void InitCarmodelParam(carmodel carparam);
    void LoadMapdata(std::string outboundaryfile, double gridsize, ...);
    void SetPathplanPoint(Point2d &startpoint, Point2d &endpoint);
    int RunPathplan(Path &outpath);

private:
    class Impl;
    boost::shared_ptr<Impl> m_impl;
};
}


#endif // PATHPLAN_HPP
