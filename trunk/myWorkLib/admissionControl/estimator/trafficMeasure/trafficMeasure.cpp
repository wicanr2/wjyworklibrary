#include <admissionControl/estimator/trafficMeasure.hpp>

trafficMeasureContainer::trafficMeasureContainer() :
	ptr(0), rb(0)
{
	this->rb = new RingBuffer<trafficMeasureUnit>;
	this->rb->SetMaxItemSize(10); 
}
trafficMeasureContainer::~trafficMeasureContainer()
{
	if ( this->rb ) 
		delete rb;
}
void trafficMeasureContainer::Dump() {
	int width = 25;
	if ( this->rb )
		this->rb->Dump();
	std::cout << std::endl;
	std::cout << "\tTraffic Measurement Container" ;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Average Bandwidth   :" 
			  << std::setw(width)
			  << std::setprecision(18)
			  << this->GetAverageBandwidth();
	
	std::cout << std::endl;

	std::cout << "Total Capacity      :" 
			  << std::setw(width)
			  << this->GetTotalCapacity();
	
	std::cout << std::endl;
	
	std::cout << "Total Measure Time  :" 
			  << std::setw(width)
			  << this->GetTotalMeasureTime();

	std::cout << std::endl;

	std::cout << "Total Duration Time :" 
			  << std::setw(width)
			  << this->GetTotalDuration();

	std::cout << std::endl;
	{
		for ( int i = 0 ; i < 80 ; i++ ) {
			std::cout << "_";
		}
		std::cout <<std::endl;
	}
}
void trafficMeasureContainer::EnableDebug()
{
	if ( this->rb )
		this->rb->EnableDebug();
	debugClass::EnableDebug();
}
void trafficMeasureContainer::DisableDebug() 
{
	if ( this->rb )
		this->rb->DisableDebug();
	debugClass::DisableDebug();
}
