#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <admissionControl/estimator/estimator.hpp>

void Estimator::MeasureBW() {
	
	int i = 0;
	int *pbitmap = 0;
	char tmpbuf[255] ;
	char *peerIP = 0;
	float currentBandwidth = 0.0;
	const float zeroBw = 0.0;
	float tmp = 0.0;
	
	pbitmap = PI_GetPeerBitmap();
	char file[] = "bw.txt";
	RingBuffer<float> *tmpPtrRingBuf = 0;
	
	for ( i = 0 ; i < PI_GetMaxPeerNum() ; i++ ) {
		if ( pbitmap[i] ) {
			//PI_DumpI(i);
			peerIP = PI_GetPeerIP(i);
			
			__AC_L1_PRINT("Do Measurement Bandwidth with Peer %s", peerIP );
			if ( this->debugFlag )
				printf("\tDo Measurement Bandwidth with Peer %s\n", peerIP );
			
			sprintf(tmpbuf, 
				//"./tools/ptr-client %s | grep PTR | awk '{ print $2 }' > %s" , 
				"./tools/ptr-client %s > %s" , 
				PI_GetPeerIP(i), file );
			//printf("%s\n", tmpbuf);
			system(tmpbuf);
			currentBandwidth = this->GetBWFromFile(file);
			tmpPtrRingBuf = this->ringBufPool[i];
			
			if ( currentBandwidth > 0 && tmpPtrRingBuf != 0 ) {
				tmpPtrRingBuf->AddNextItem( currentBandwidth );
				tmpPtrRingBuf->Dump();
	
				tmp = tmpPtrRingBuf->Summation();
				if ( tmpPtrRingBuf->Size() > 0 ) {
					__AC_L1_PRINT("the Average Bandwidth between Peer %s is %.3f Mpbs", 
						peerIP,
						tmp / tmpPtrRingBuf->Size());
					if ( this->debugFlag )
						printf("\tthe Average Bandwidth between Peer %s is %.3f Mpbs\n\n", 
							peerIP,
							tmp / tmpPtrRingBuf->Size());
				}
			} else {
				tmpPtrRingBuf->AddNextItem( zeroBw );
			}
			
			/*sprintf(tmpbuf, "%s" , 
				"cat bw.txt" );
			system(tmpbuf);*/
		}
	}
}

float Estimator::GetBWFromFile(char *file) {
	FILE *bwF = 0;
	char buf[255];
	//char *parseFormat = "%f";
	char parseFormat[] = "PTR:%*[ ]%f%*[ ]Mbps";
	bwF = fopen(file,"r");
	float curBw = 0.0;
	if ( bwF > 0 ) {
		do {
			fgets( buf, 255, bwF );
		} while( strstr(buf,"PTR") == 0 );
		
		__AC_L1_PRINT( "buf = %s", buf );
		if ( this->debugFlag )
			printf( "buf = %s\n", buf );
		
		sscanf( buf, parseFormat , &curBw);		
		fclose( bwF );
	} else {
		__AC_L1_PRINT("open %s falied", file);
		if ( this->debugFlag )
			printf("open %s falied\n", file);
	}
	return curBw;
}
