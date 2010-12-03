#include <stdio.h>
#include <time.h>
#include <buffer/ringBuffer.hpp>
class TrafficMeasureUnit {
private:
	float bandwidth;
	float capacity;
	time_t measure_time;
	time_t during_time; 
public:
	TrafficMeasureUnit() :
		bandwidth(0.0f), capacity(0.0f),
		measure_time(0.0f), during_time(0.0f)
	{
	} 
	friend std::ostream& operator<< 
		(std::ostream &out, TrafficMeasureUnit& rhs) 
	{
		out << "BW :" << rhs.bandwidth ;
		out <<", ";
		out << "C :" << rhs.capacity ;
		out <<", ";
		out << "M :" << rhs.measure_time ;
		out <<", ";
		out << "S :" << rhs.during_time ;

		return out;
	}
};
int main( int argc, char *argv[] ) {
		
	RingBuffer<TrafficMeasureUnit> *rbTM = 
		new	RingBuffer<TrafficMeasureUnit>;

	rbTM->SetMaxItemSize(10);
	for ( int i = 0 ; i < 10000000 ; i++ ) {
		rbTM->AddNextItem( new TrafficMeasureUnit() );
	}
	rbTM->AddNextItem( new TrafficMeasureUnit() );
	rbTM->AddNextItem( new TrafficMeasureUnit() );
	rbTM->AddNextItem( new TrafficMeasureUnit() );
	rbTM->EnableDebug();
	rbTM->Dump();
	delete rbTM;

	void *_rb = 0;
	_rb= (void*)new RingBuffer<float>;
	
	RingBuffer<float> *rb = (RingBuffer<float>*)_rb;
	rb->SetMaxItemSize(10);
	float tmp = 0.0;
	rb->AddNextItem( new float(3213.3f) );
	rb->AddNextItem( new float(2.3f) );
	rb->AddNextItem( new float(4.3f) );
	rb->AddNextItem( new float(6.3f) );
	rb->AddNextItem( new float(22.3f) );
	rb->AddNextItem( new float(75.3f) );
	rb->AddNextItem( new float(75.3f) );
	rb->AddNextItem( new float(75.3f) );
	rb->AddNextItem( new float(75.3f) );
	rb->AddNextItem( new float(75.3f) );
	rb->AddNextItem( new float(75.3f) );
	rb->EnableDebug();
	rb->Dump();
	
	rb->RemovePrevItem();
	rb->RemovePrevItem();
	rb->RemovePrevItem();
	rb->RemovePrevItem();
	rb->RemovePrevItem();
	rb->RemovePrevItem();
	rb->RemovePrevItem();
	rb->Dump();
	rb->RemoveAllItem();
	rb->Dump();	
	return 0;
}
