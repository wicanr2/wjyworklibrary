#ifndef REFERENCE_COUNT
#define REFERENCE_COUNT
class referenceCount {
private:
	int count;
public:
	referenceCount():count(0)
	{
	} 
	~referenceCount(){
	}
	void AddRef() {
		this->count++;
	} 
	int Release() {
		return --count;
	}
	
};
#endif
