#include "pathplan.hpp"
#include "map.hpp"



namespace PATH_PLANNING {
class PathPlan::Impl
{
public:
    Impl(){}
    ~Impl(){}
    void InitCarmodelParam(carmodel carparam);
    void LoadMapdata(std::string outboundaryfile, double gridsize, ...);
    void SetPathplanPoint(Point2d &startpoint, Point2d &endpoint);
    int RunPathplan(Path &outpath);

public:
    Map *m_map;
    Point2d m_sPoint2d, m_ePoint2d;

};

void PathPlan::Impl::InitCarmodelParam(carmodel carparam)
{
    //...
}

void PathPlan::Impl::LoadMapdata(std::string outboundaryfile, double gridsize, ...)
{
    //...
}

void PathPlan::Impl::SetPathplanPoint(Point2d &startpoint, Point2d &endpoint)
{
    //...
}

int PathPlan::Impl::RunPathplan(Path &outpath)
{
    //...
}



PathPlan::PathPlan()
{
    m_impl = boost::shared_ptr<PathPlan::Impl> (new PathPlan::Impl());
}

PathPlan::~PathPlan()
{
    //...
}

void PathPlan::InitCarmodelParam(carmodel carparam)
{
    m_impl->InitCarmodelParam(carparam);
}

void PathPlan::LoadMapdata(std::string outboundaryfile, double gridsize, ...)
{
    m_impl->LoadMapdata(outboundaryfile, gridsize);
}

void PathPlan::SetPathplanPoint(Point2d &startpoint, Point2d &endpoint)
{
    m_impl->SetPathplanPoint(startpoint, endpoint);
}

int PathPlan::RunPathplan(Path &outpath)
{
    return m_impl->RunPathplan(outpath);
}
}
