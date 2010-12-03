#ifndef ESTIMATOR_H
#define ESTIMATOR_H
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <pthread.h>
#include <peer/peerInfo.h>
#include <buffer/ringBuffer.hpp>
#include <debug/ac_debug.h>
class Estimator {
private:
	
	// thread wait time = 
	// 		interval ~ interval * range seconds
	int interval;
	int range;
	
	// ringbuf
	//RingBuffer<float> *ringBuf;
	RingBuffer<float> **ringBufPool;
	int recordNum;
	
	// thread
	pthread_t workThread;
	bool active;
	bool workThreadStop;
	static void *DoEstimate(void *v);
	void MeasureBW();
	float GetBWFromFile(char *file);
	
	//dump
	bool debugFlag;
public:
	Estimator(int i, int r, int rn) ;
	~Estimator() ;
	// active estimator ;
	// deactive estimator 
	// wait estimator
	int ActiveEstimator();
	int DeactiveEstimator();
	int WaitEstimator();
	
	// gather bandwidth
	// report average bandwidth
	void EnableDump();
	void DisableDump();
	
	// Set functions
	int SetInterval(int v);
	int SetRange(int v);
	int SetRecordNumber(int v);
	// Get functions
	int GetInterval();
	int GetRange();
	int GetRecordNumber();
};
#endif
