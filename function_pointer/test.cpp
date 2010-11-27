#include <stdio.h>
#include <stdlib.h>


/*
 *  XML function_name arg1 arg2 arg3 arg4
 *
 * */
typedef int (*fp0)();
typedef int (*fp1)(void *arg1);
typedef int (*fp2)(void *arg1, void *arg2);
typedef int (*fp3)(void *arg1, void *arg2, void *arg3);
typedef int (*fp4)(void *arg1, void *arg2, void *arg3, void *arg4);

class testA {
public:
	testA() { }
	~testA() { }
	virtual int TestFP(void *arg1, void *arg2){
		printf("hello ");
		int *x = (int*) arg1;
		float *y = (float*) arg2;
		printf("%d , %f\n", *x, *y);
	   	return 0;	
	}
};
class testB:public testA
{
public:
	testB(){};
	~testB(){};
	virtual int TestFP(void *arg1, void *arg2)
	{
		int *x = (int*) arg1;
		float *y = (float*) arg2;
		float r = 0.0;
		r = *y;
		r = r * (*x);
		printf("%d x %f = %f\n", *x, *y, r);
	   	return 0;	
	}
};
typedef int (testB::*callback)(void *arg1, void *arg2);
enum FunctionPointerType {
	FPT_ARGS_0,
	FPT_ARGS_1,
	FPT_ARGS_2,
	FPT_ARGS_3

};
int Test1()
{
	printf("Test 1\n");
	return 0;
}
int Test2(void *arg1)
{
	int *i = (int*) arg1;
	if ( i != 0 )
		printf( "Test 2 %d\n", *i);
	return 0;
}
int Test3(void *arg1, void *arg2)
{
	int *i = (int*) arg1;
	if ( i != 0 )
		printf( "Test 3 %d\n", *i);
	return 0;
}
int Test4(void *arg1, void *arg2, void *arg3)
{
	int *i = (int*) arg1;
	if ( i != 0 )
		printf( "Test 4 %d\n", *i);
	return 0;
}
int main(int argc, char *argv[])
{
	void *p = (void*)Test1;
	fp0 _fp0 = (fp0)p;
	if ( _fp0 != 0 )(*_fp0)();
	p = (void*)Test2;
	fp1 _fp1 = (fp1)p;
	int x = 10;
	if ( _fp1 != 0 )(*_fp1)(&x);
	
	p = (void*)Test3;
	fp2 _fp2 = (fp2)p;
	if ( _fp2 != 0 )(*_fp2)(&x,0);

	p = (void*)Test4;
	fp3 _fp3 = (fp3)p;
	if ( _fp3 != 0 )(*_fp3)(&x,0,0);

	testB *a = new testB();

	callback cb = &testB::TestFP;
	float y=99.0;
	// the language sugar 
	//
	printf( "cb=%x\n", cb);	

	(a->*cb)((void*)&x, (void*)&y);
	return 0;
}

