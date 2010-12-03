#include <admissionControl/estimator/estimator.hpp>

Estimator::Estimator(int i, int r, int rn):
	interval(0),range(0),
	recordNum(0),
	//ringBuf(0),
	active(false),workThreadStop(false),
	ringBufPool(0),debugFlag(false)
{
	this->SetInterval(i);
	this->SetRange(r);
	this->SetRecordNumber(rn);
}

Estimator::~Estimator() {
	int i = 0;
	if ( this->active ) {
		// stop thread
		for ( i = 0 ; i < PI_GetMaxPeerNum() ; i++ ) {
			delete this->ringBufPool[i];
		}
		delete [] ringBufPool;
		//delete ringBuf;
	}
}
