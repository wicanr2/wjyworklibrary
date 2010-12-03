#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <list/fastLinkedList.hpp>

class Attributes{
private:
	
public:
	
	char name[255];
	char value[255];
	Attributes() {
		strncpy( name , "none" , 255 );
		strncpy( value , "none", 255 );
	}
	Attributes(const char* n, const char *v) {
		strncpy( name  ,  n , 255 );
		strncpy( value ,  v , 255 );
	}
	~Attributes() {
		printf("Destory\tAttributes\n");
	}
	friend std::ostream& operator<< ( std::ostream &out, 
			Attributes &rhs )
	{
		out << rhs.name <<" ("<<rhs.value<<")" ;
		return out;
	}
};
int main( int argc, char *argv[] ) {
	int recordNum = 32;
	int i = 0;
	int *tmp = 0;
	fastLinkedList<Attributes> *fllAttr = new fastLinkedList<Attributes>;
	fllAttr->EnableDebug();
	fllAttr->SetMaxPoolSize(100);
	fllAttr->AppendItem(new Attributes("e1","1"));
	fllAttr->AppendItem(new Attributes("e2","2"));
	fllAttr->AppendItem(new Attributes("e3","3"));
	fllAttr->AppendItem(new Attributes("e2","4"));
	fllAttr->AppendItem(new Attributes("e2","5"));
	fllAttr->Dump();
	
	fllAttr->RemoveAllItem();
	fllAttr->Dump();
	
	fllAttr->AppendItem(new Attributes("e6","6"));
	fllAttr->AppendItem(new Attributes("e7","7"));
	fllAttr->AppendItem(new Attributes("e8","8"));
	fllAttr->AppendItem(new Attributes("e9","9"));
	fllAttr->AppendItem(new Attributes("e10","10"));
	fllAttr->Dump();
	
	delete fllAttr;
	
	
	fastLinkedList<int> *fll = new fastLinkedList<int>;
	fll->EnableDebug();
	fll->SetMaxPoolSize(100);
	for ( i = 0 ; i < 10 ; i ++ ) {
		fll->AppendItem(new int(i));
	}
	
	fll->Dump();
	fll->RemoveTailItem();
	fll->Dump();
	
	fll->RemoveItem(5);
	fll->RemoveItem(7);
	fll->RemoveItem(11);
	fll->Dump();
	fll->DisableDebug();
	for ( i = 0 ; i < fll->GetUsedPoolSize() ; i++ ) {
		tmp=(*fll)[i];
		std::cout<<"["<<i<<"] = "<<*tmp<<std::endl;
	}
	
	delete fll;
	
	return 0;
}
