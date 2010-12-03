#include <admissionControl/estimator/estimator.hpp>

int Estimator::ActiveEstimator() {
	int i = 0;
	/*if ( this->ringBuf == 0 ) 
		this->ringBuf = new RingBuffer<float>(this->recordNum);*/
	
	// ringbuffer pool scheme
	if ( this->ringBufPool == 0 ) {
		this->ringBufPool = new RingBuffer<float>*[PI_GetMaxPeerNum()];
		for ( i = 0 ; i < PI_GetMaxPeerNum() ; i++ ) {
			this->ringBufPool[i] = new RingBuffer<float>(this->recordNum); 
		}
	}
	if ( this->debugFlag )
		this->EnableDump();
	this->active = true;
	this->workThreadStop = false;
	pthread_create ( &this->workThread, 0, this->DoEstimate, this );
	
	return 0;
}
int Estimator::DeactiveEstimator() {
	this->workThreadStop = true;
	return 0;
}
int Estimator::WaitEstimator() {
	if ( this->active ) {
		
		pthread_join( this->workThread , 0 );
	}
	return 0;
}

void *Estimator::DoEstimate(void *v){
	Estimator *e = (Estimator*) v;
	unsigned int sleepInterval = 0;
	
	__AC_L1_PRINT_NOARG("Enter DoEstimate");
	if ( e->debugFlag )
		printf("Enter DoEstimate\n");
	
	//if ( e->ringBuf == 0 ) 
		//return 0;
	if ( e->ringBufPool == 0 ) 
		return 0;
	if ( e->interval <= 0 ) 
		return 0;
	if ( e->range <= 0 )
		return 0;
	srand( time(0) );
	while(true) {
		if ( e->workThreadStop ) 
			break;
		sleepInterval = 
			e->interval + 
			(unsigned int)( rand() % ( (e->range-1) * e->interval ) );
						
		sleep( sleepInterval );
		
		__AC_L1_PRINT("The Measurement Interval is %d Seconds", sleepInterval );
		if ( e->debugFlag )
			std::cout<<"\tThe Measurement Interval is "<<sleepInterval<<" Seconds"<<std::endl;
		
		e->MeasureBW();
		
	}
	return 0;
}
