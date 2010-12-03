#include <admissionControl/estimator/trafficMeasureUnit.hpp>

int trafficMeasureUnit::SetBandwidth(float v)
{
	this->bandwidth = v;
	return 0;
}

int trafficMeasureUnit::SetMeasureTime(time_t v) 
{
	this->measure_time = v;
	return 0;
}
int trafficMeasureUnit::SetDuration(time_t v)
{
	this->duration = v;
	return 0;
}
