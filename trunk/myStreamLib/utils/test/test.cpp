#include <stdio.h>
#include <iostream>
#include <peer/peerInfo.h>
#include <utils/fileCheckerCAPI.h>
#include <utils/smartPointer.hpp>
#include <utils/thread/threadWorker.hpp>
class temp {
public:
	int x, y ,z ;
	temp(int _x, int _y, int _z){
		this->x = _x;
		this->y = _y;
		this->z = _z;
	}
	~temp() {
	}
	void Dump() {
		printf(" x = %d , y = %d , z = %d \n", x,y,z);
	}
};

class work1:public threadWorker{
protected:
	void DoRealWork(){
		printf("i am work1\n");
	}  
public:
	work1(){}
	~work1(){}
};

class work2:public threadWorker{
protected:
	void DoRealWork(){
		printf("i am work2\n");
	}  
public:
	work2(){}
	~work2(){}
};

class work3:public threadWorker{
protected:
	virtual void DoRealWork(){
		printf("i am work3\n");
	}  
public:
	work3(){}
	~work3(){}
};
#define THREAD_NUM 5
int main( int argc, char *argv[] ) {
	
	threadWorker *thw[THREAD_NUM];
	{
		thw[0] = new work1;
		//thw[0]->CreateThread();
		
		thw[1] = new work2;
		//thw[1]->CreateThread();
		
		thw[2] = new work3;
		//thw[2]->CreateThread();
		for ( int i = 3  ; i < THREAD_NUM ; i ++ ) {
			thw[i] = new threadWorker;
			//thw[i]->CreateThread();
		}
		printf(" after new\n");
		for ( int i = 0 ; i < THREAD_NUM ; i ++ ) {
			//printf(" create %d\n", i);
			thw[i]->ActivateThread();
		}
		//sleep(1);	
		printf(" after creation\n");
		
	}
	{

		char ip[] = "127.0.0.1";
		char aport[] = "5000";
		char vport[] = "6000";
		PI_AddPeer    (0, ip, vport, aport );
	}
	temp *t = new temp(5566,7788,1122);
	smartPtr<temp> *tsp = 0;
	tsp = new smartPtr<temp>(t);	
	(*tsp)->Dump();
	delete tsp;
	t->Dump();

	int *x = new int(5);
	
	smartPtr<int> *sp = 0;
	sp = new smartPtr<int>(x);
	sp->EnableDebug();
	
	int *p = *(*(sp));	
	printf(" p<-*(*(sp)) = %d\n", *p );
	
	printf(" delete sp\n" );

	printf(" sp = %d\n", (int)sp );
	p = sp->GetValue();
	printf(" p<-sp->GetValue = %d\n",(int) *p );

	smartPtr<int> sp2(sp);
	delete sp;	
	p = *sp2;	
	printf(" p<-*sp2 = %d\n", *p );

	
	p = *sp2;	
	printf(" p<-*sp2 = %d\n", *p );
			
	smartPtr<int> *sp3 = new  smartPtr<int>;
	*sp3 = sp2;
	//sp3->EnableDebug();
	p = *(*sp3);	
	printf(" p<-*(*sp3) = %d\n", *p );
	printf(" delete sp3\n" );
	delete sp3;		
	p = *sp2;	
	printf(" p<-*sp2 =  %d\n", *p );
		
	p = *(*(sp));	
	printf(" p<-*(*(sp)) = %d\n", *p );
	
	FC_EnableDebug();
	{ 
		char file[] = "/usr";
		FC_CheckFileExisted(file);
	}
	{ 
		char file[] = "tttt";
		FC_CheckFileExisted(file);
	}
	FC_Destory();
	PI_Destory();
	{
		printf("sleep 10 seconds\n");
		sleep(10);
		for ( int i = 0 ; i < THREAD_NUM ; i ++ ) {
			if ( thw[i] )
				thw[i]->StopThread();
		}
		printf("Wait Thread Joining\n");
		for ( int i = 0 ; i < THREAD_NUM ; i ++ ) {
			if ( thw[i] )
				thw[i]->WaitThreadJoin();
		}
		printf("Free Thread\n");
		for ( int i = 0 ; i < THREAD_NUM  ; i++ ) {	
			if ( thw[i] )
				delete thw[i];
		}
		pthread_exit(NULL);
	}
	return 0;
}
