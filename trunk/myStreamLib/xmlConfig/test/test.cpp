#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <xmlConfig/xmlProfilesPool.hpp> 
/*class Attributes{
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
};*/
int main( int argc, char *argv[] ) {
	int recordNum = 32;
	int i = 0;
	int *tmp = 0;
	xmlProfilesPool *pP = new xmlProfilesPool;
	xmlProfile *profile = 0; 
	XC_xmlElement *element = 0;
	//pP->EnableDebug();
	for( i = 0 ; i < 1 ; i++ )
	{
		char name[] = "profile1";
		char value[] = "location:../config/xml/profile/video/profile1.xml";
		profile = new xmlProfile(name,value);
		if ( profile == 0 ) return 0;
		//profile->EnableDebug();
		pP->Append(profile);
		
		
	}
	
	XC_xmlElementsPool *eP = profile->GetElementsPool();
	//eP->EnableDebug();
	for ( i = 0 ; i < 2 ; i ++ ) 	
	{
		char name[] = "element1";
		char value[] = "no value";
		element = new XC_xmlElement(name,value);
		if ( element == 0 ) return 0;
		//element->EnableDebug();
		eP->Append(element);
	}
	
	attributesPool *attrlist = element->GetAttributesPool();
	//attrlist->EnableDebug();
	for ( i = 0 ; i < 6 ; i++ )
	{
		char name[] = "e1";
		char value[] = "1";
		Attributes *tmp = new Attributes(name,value); 
		//tmp->EnableDebug();
		attrlist->Append( tmp );
	}
	{
		char name[] = "e2";
		char value[] = "2";
		Attributes *tmp = new Attributes(name,value); 
		//tmp->EnableDebug();
		attrlist->Append( tmp );
	}
	{
		char name[] = "e3";
		char value[] = "3";
		Attributes *tmp = new Attributes(name,value); 
		//tmp->EnableDebug();
		attrlist->Append( tmp );
	}
	{
		char name[] = "e4";
		char value[] = "4";
		Attributes *tmp = new Attributes(name,value); 
		//tmp->EnableDebug();
		attrlist->Append( tmp );
	}
	{
		char name[] = "e5";
		char value[] = "5";
		Attributes *tmp = new Attributes(name,value); 
		//tmp->EnableDebug();
		attrlist->Append( tmp );
	}
		
	XC_xmlElementsPool *eP2 = 0;
	{
		char name[] ="element1";
		eP2 = eP->GetItemPool(name);
		//printf("eP2 = %d\n", eP2 );
		if ( eP2 != 0 ) {
			//eP2->Dump();
			delete eP2;
		}
	}
	
	//std::cout << "Dump profile pool again "<<std::endl; 
	//pP->Dump();
	/*XC_xmlElement *xmlETmp = 0;
	attributesPool *aP = 0;
	Attributes *attrTmp = 0;
	for ( int i = 0 ; i < eP->GetSize() ;i++ ) {
		std::cout << "Get element pool item ["<<i<<"]"<<std::endl;
		xmlETmp = eP->GetItem(i);
		aP = xmlETmp->GetAttributesPool();
		for ( int j = 0 ; j < aP->GetSize() ; j++ ) {
			std::cout << "Get attributs pool item ["<<j<<"]"<<std::endl;
			attrTmp = aP->GetItem(j);
			std::cout << "Name : ";
			std::cout << attrTmp->GetName();
			std::cout << ", ";
			std::cout << "Value : ";
			std::cout << attrTmp->GetValue();
			std::cout << std::endl;
		}
	} */
	
	xmlProfilesPool *pP2 = 0;
	{
		char name[] ="pro";
		pP2 = pP->GetItemPoolContain(name);
		if ( pP2 != 0 ) {
			//pP2->Dump();
			delete pP2;
		}
	}
	pP->Dump();
	std::cout << "Delete profile pool"<<std::endl;
	
	delete pP;
    /*XC_xmlElement *element = new XC_xmlElement;	
	element->EnableDebug();
	attributesPool *attrlist = element->GetAttributesPool();
	attrlist->EnableDebug();
	attrlist->Append(new Attributes("e1","1"));
	attrlist->Append(new Attributes("e2","2"));
	attrlist->Append(new Attributes("e3","3"));
	attrlist->Append(new Attributes("e2","4"));
	attrlist->Append(new Attributes("e2","5"));
	//attrlist->Dump();
	std::cout<< *element;
	attrlist->RemoveAll();
	//attrlist->Dump();
	std::cout<< *element;
	delete element;*/
	//fastLinkedList<Attributes> *fllAttr = new fastLinkedList<Attributes>;
	/*attributesList *fllAttr = new attributesList;  
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
	
	delete fllAttr;*/
	
	
/*	fastLinkedList<int> *fll = new fastLinkedList<int>;
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
*/
	
	return 0;
}
