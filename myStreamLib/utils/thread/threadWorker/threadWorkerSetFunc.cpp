#include <utils/thread/threadWorker.hpp>
int threadWorker::SetActive(bool v)
{
	ML.Lock();
	this->bActive = v;
	ML.Unlock();
	return 0;
}
int threadWorker::SetInterrupt(bool v)
{
	//ML.Lock();
	this->bInterrupt = v;
	//ML.Unlock();
	return 0;
}
int threadWorker::SetDetachable(bool v)
{
	ML.Lock();
	this->bDetachable = v;
	ML.Unlock();
	return 0;
}
