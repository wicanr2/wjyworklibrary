#include <xmlConfig/xmlConfig2.hpp>
int XMLConfigurator2::AddProfile
	(char *name, char *location) 
{
	MACRO_DEBUG_CLASS_PRINT_L5("Call\tXMLConfigurator2::AddProfile()\n");
	
	MACRO_ERROR_CHECK_0_WITH_DEBUG ( this->profilePool );
	MACRO_ERROR_CHECK_0_WITH_DEBUG ( name );
	MACRO_ERROR_CHECK_0_WITH_DEBUG ( location );
	
	xmlProfile *profile = this->profilePool->GetItemByName( name );
	
	MACRO_ERROR_CHECK_NOT_EQUAL_WITH_DEBUG( 
		profile, 0, -1, "the profile %s was existed\n", name );

	profile = 0;
	this->ML.Lock();
	profile = new xmlProfile( name, location );
	int r = this->profilePool->Append(profile);
	this->ML.Unlock();
	if ( r < 0 ) { 
		delete profile;
		return -1;
	}
	return 0;
}
