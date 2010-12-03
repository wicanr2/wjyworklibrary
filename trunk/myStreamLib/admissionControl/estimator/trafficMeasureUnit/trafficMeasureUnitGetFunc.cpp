#include <admissionControl/estimator/trafficMeasureUnit.hpp>

float trafficMeasureUnit::GetBandwidth()
{
	return this->bandwidth;
}
float trafficMeasureUnit::GetCapacity()
{
	this->capacity = 
		this->bandwidth * this->measure_time;
	return this->capacity;
}
time_t trafficMeasureUnit::GetMeasureTime()
{
	return this->measure_time;
}
time_t trafficMeasureUnit::GetDuration()
{
	return this->duration;
}
