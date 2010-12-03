#ifndef BANDWIDTH_STATISTICIAN_HPP 
#define BANDWIDTH_STATISTICIAN_HPP 
#include <admissionControl/estimator/trafficMeasure.hpp>
#include <list/fastLinkedList.hpp>
#include <utils/staticMutexLocker.hpp>
#include <utils/mutexLocker.hpp>
#include <utils/debugClass.hpp>
class bandwidthStatistician:public debugClass {
private:
	fastLinkedList<trafficMeasureContainer> *list;
	
public:
};
#endif
