#ifndef SMART_POINTER_HPP
#define SMART_POINTER_HPP
#include <utils/referenceCount.hpp>
#include <utils/debugClass.hpp>
#include <cstdio>
template < typename T > 
class smartPtr: public debugClass{
private:
	T* pData;
	referenceCount* rc; // reference count

public:
	smartPtr():
		pData(0), rc(0) 
	{
		rc = new referenceCount();
		rc->AddRef();
	}
	smartPtr(T* pValue): 
		pData(pValue), rc(0) 
	{
		rc = new referenceCount();
		rc->AddRef();
	}
	smartPtr(smartPtr<T> *sp): 
		pData(sp->pData), rc(sp->rc) 
	{
		this->SetDebugFlag( sp->GetDebugFlag() );
		rc->AddRef();
	}
	~smartPtr() {
		MACRO_DEBUG_CLASS_PRINT_L6("Destory\tSmart Pointer\n");
		
		if ( rc->Release() == 0 ) {
			MACRO_DEBUG_CLASS_PRINT_L6("reference count == 0\n");
			if ( pData );
				delete pData;
			delete rc;
		}
	}
	T* GetValue() {
		return pData;
	}	
	T* operator* () {
		return pData;
	}
	T* operator-> () {
		return pData;
	}
	smartPtr<T>& operator= ( smartPtr<T>& sp ) 
	{
		if ( this != &sp ) {
			if ( rc->Release() != 0 ) {
				delete pData;
				delete rc;
			}		
			pData = sp.pData;
			rc = sp.rc;
			this->SetDebugFlag(sp.GetDebugFlag());
			rc->AddRef();
		}
		return *this;
	}
	
};
#endif
