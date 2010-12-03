#include <stdio.h>
#include <peer/peerInfo.h>
#include <admissionControl/estimator/trafficMeasure.hpp>
#include <admissionControl/estimator/bandwidthStatistician.hpp>

int main( int argc, char *argv[] ) {
	trafficMeasureContainer *tmc = new trafficMeasureContainer();
	tmc->AddTrafficData( 100, 5000, 0 );
	tmc->AddTrafficData( 200, 2000, 0 );
	tmc->AddTrafficData( 400, 3000, 0 );
	tmc->AddTrafficData( 500, 1000, 0 );
	tmc->EnableDebug();
	tmc->Dump();
	delete tmc;
	return 0;
}
