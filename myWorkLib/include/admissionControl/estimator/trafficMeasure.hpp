#ifndef TRAFFIC_MEASUREMENT_CONTAINER_HPP
#define TRAFFIC_MEASUREMENT_CONTAINER_HPP
#include <iostream>
#include <iomanip>
#include <time.h>
#include <utils/debugClass.hpp>
#include <admissionControl/estimator/trafficMeasureUnit.hpp>
#include <buffer/ringBuffer.hpp>
#include <peer/peer.hpp>
class trafficMeasureContainer:public debugClass {
private:
	peerInfo *ptr;
	RingBuffer<trafficMeasureUnit> *rb;
public:
	trafficMeasureContainer();
	~trafficMeasureContainer();
	
		
	int AddTrafficData( float bw, time_t m, time_t d);
	
	// setter
	int SetAssociatePeerPtr( peerInfo *p );

	// the time_t unit is seconds
	// getter
	float  GetAverageBandwidth();
	float  GetTotalCapacity();
	time_t GetTotalMeasureTime();
	time_t GetTotalDuration();
	peerInfo * GetPeerPtr();

	void Dump();
	void EnableDebug();
	void DisableDebug();
};
#endif
