#include <admissionControl/estimator/trafficMeasureUnit.hpp>

trafficMeasureUnit::trafficMeasureUnit():
	bandwidth(0.0f), capacity(0.0f),
	measure_time(0), duration(0)
{
}
trafficMeasureUnit::~trafficMeasureUnit() 
{
}
std::ostream& operator<<
	(std::ostream &out, trafficMeasureUnit& rhs)
{
	out <<"BW :" << rhs.bandwidth ;
	out <<" Mbps, ";
	out <<"C :" << rhs.capacity ;
	out <<" Mb, ";
	out <<"M :" << rhs.measure_time ;
	out <<"s, ";
	out <<"S :" << rhs.duration ;
	out <<"s";

	return out;
}
