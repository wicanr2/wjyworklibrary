#ifndef TRAFFIC_MEASUREMENT_UNIT_HPP
#define TRAFFIC_MEASUREMENT_UNIT_HPP
#include <iostream>
#include <time.h>
#include <utils/debugClass.hpp>
class trafficMeasureUnit:public debugClass {
private:
	float  bandwidth;
	float  capacity;
	time_t measure_time;
	time_t duration;
public:
	trafficMeasureUnit();
	~trafficMeasureUnit();
	friend std::ostream& operator<<
		(std::ostream &out, trafficMeasureUnit& rhs);
	
	//setter
	int SetBandwidth(float v);
	int SetMeasureTime(time_t v);
	int SetDuration(time_t v);

	//getter
	float GetBandwidth();
	float GetCapacity();
	time_t GetMeasureTime();
	time_t GetDuration();
};
#endif

