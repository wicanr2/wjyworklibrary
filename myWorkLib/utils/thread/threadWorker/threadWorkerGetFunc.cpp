#include <utils/thread/threadWorker.hpp>
bool threadWorker::GetActive()
{
	bool tmp;
	this->ML.Lock();
	tmp = this->bActive;
	this->ML.Unlock();
	return tmp;
}
bool threadWorker::GetInterrupt()
{
	bool tmp;
	//this->ML.Lock();
	tmp = this->bInterrupt;
	//this->ML.Unlock();
	return tmp;
}
bool threadWorker::GetDetachable()
{
	bool tmp;
	this->ML.Lock();
	tmp = this->bDetachable;
	this->ML.Unlock();
	return tmp;
}
