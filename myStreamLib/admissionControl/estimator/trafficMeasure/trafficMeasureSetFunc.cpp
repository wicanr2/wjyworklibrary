#include <admissionControl/estimator/trafficMeasure.hpp>
int trafficMeasureContainer::SetAssociatePeerPtr( peerInfo *p ) 
{
	if ( p == 0 ) return -1;
	this->ptr = p;
	return 0;
}
