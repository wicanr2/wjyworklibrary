#include <admissionControl/estimator/trafficMeasure.hpp>

int trafficMeasureContainer::
	AddTrafficData( float bw, time_t m, time_t d) 
{
	if ( this->rb == 0 ) return -1;
	trafficMeasureUnit *tm = new trafficMeasureUnit;
	if ( tm == 0 ) return -1;
	tm->SetBandwidth( bw );
	tm->SetMeasureTime( m );	
	tm->SetDuration ( d );
	rb->AddNextItem ( tm );
	return 0;
}
