#include <admissionControl/estimator/trafficMeasure.hpp>
float  trafficMeasureContainer::GetAverageBandwidth()
{
	if ( this->rb == 0 ) return 0.0f;
	float  totalCapacity = 0.0f;
	time_t totalTime     = 0;
	float  avgBw		 = 0.0f; 	
	totalCapacity = this->GetTotalCapacity(); 
	totalTime     = this->GetTotalMeasureTime();

	if ( totalTime <=0 ) return 0.0f;
	
	avgBw = totalCapacity / (float) ( totalTime );
	return avgBw;
}
float  trafficMeasureContainer::GetTotalCapacity()
{
	if ( this->rb == 0 ) return 0.0f;
	float total = 0.0f;
	trafficMeasureUnit *tmu = 0;
	for ( int i = 0 ; i < this->rb->Size(); i++ )
	{
		tmu = this->rb->GetItem(i);
		if ( tmu != 0 )
			total += tmu->GetCapacity();
	}
	return total;
}
time_t trafficMeasureContainer::GetTotalMeasureTime()
{
	if ( this->rb == 0 ) return 0;
	time_t total = 0.0f;
	trafficMeasureUnit *tmu = 0;
	for ( int i = 0 ; i < this->rb->Size(); i++ )
	{
		tmu = this->rb->GetItem(i);
		if ( tmu != 0 )
			total += tmu->GetMeasureTime();
	}
	return total;
}
time_t trafficMeasureContainer::GetTotalDuration()
{
	if ( this->rb == 0 ) return 0;
	time_t total = 0.0f;
	trafficMeasureUnit *tmu = 0;
	for ( int i = 0 ; i < this->rb->Size(); i++ )
	{
		tmu = this->rb->GetItem(i);
		if ( tmu != 0 )
			total += tmu->GetDuration();
	}
	return total;
}
peerInfo* trafficMeasureContainer::GetPeerPtr() 
{
	return this->ptr;
}
