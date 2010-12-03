
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <admissionControl/estimator/estimator.hpp>

int Estimator::GetInterval() {
	return this->interval;
}
int Estimator::GetRange() {
	return this->range;
}
int Estimator::GetRecordNumber() {
	return this->recordNum;
}
