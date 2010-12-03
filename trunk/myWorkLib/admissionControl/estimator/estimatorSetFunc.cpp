#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <admissionControl/estimator/estimator.hpp>

int Estimator::SetInterval(int v) {
	this->interval = v;
	return 0;
}
int Estimator::SetRange(int v) {
	this->range = v;
	return 0;
}
int Estimator::SetRecordNumber(int v) {
	this->recordNum = v;
	return 0;
}
