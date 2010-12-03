#include <admissionControl/estimator/estimator.hpp>

void Estimator::EnableDump() {
	int i = 0;
	this->debugFlag = true;
	if ( this->ringBufPool != 0 ) {
		for ( i = 0 ; i < PI_GetMaxPeerNum() ; i++ ) {
			this->ringBufPool[i]->EnableDump();
		}
	}
}
void Estimator::DisableDump() {
	int i = 0;
	this->debugFlag = false;
	if ( this->ringBufPool != 0 ) {
		for ( i = 0 ; i < PI_GetMaxPeerNum() ; i++ ) {
			this->ringBufPool[i]->DisableDump();
		}
	}
}
