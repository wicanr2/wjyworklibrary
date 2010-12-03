#include <stdio.h>
#include <xmlConfig/xmlConfig.h>


#define PROFILE_NAME "AudioBindleProfile"

struct _AudioBindleProfile {
	int 	size;
	char	sink1[255];
	char	source1[255];
	char	sink2[255];
	char	source2[255];
	char 	sink3[255];
	char 	source3[255];
	char 	sink4[255];
	char	source4[255];
	char 	ringingSink[255];
	char	ringingSource[255];
};
static struct _AudioBindleProfile __AudioBindleProfile;
static TypePool __AudioBindleTypePool[] = {
	{"AudioBindle", "size","none", INT, &__AudioBindleProfile.size },
	{"Bindle1", "sink","none", CSTR, __AudioBindleProfile.sink1 },
	{"Bindle1", "source","none", CSTR, __AudioBindleProfile.source1 },
	{"Bindle2", "sink","none", CSTR, __AudioBindleProfile.sink2 },
	{"Bindle2", "source","none", CSTR, __AudioBindleProfile.source2 },
	{"Bindle3", "sink","none", CSTR, __AudioBindleProfile.sink3 },
	{"Bindle3", "source","none", CSTR, __AudioBindleProfile.source3 },
	{"Bindle4", "sink","none", CSTR, __AudioBindleProfile.sink4 },
	{"Bindle4", "source","none", CSTR, __AudioBindleProfile.source4 },
	{"Ringing", "sink","none", CSTR, __AudioBindleProfile.ringingSink },
	{"Ringing", "source","none", CSTR, __AudioBindleProfile.ringingSource },
	{ 0, 0, 0, LAST, 0 }
};

int AudioBindleProfile_Init()
{
	__XMLRegister( PROFILE_NAME, "config//audioBindle.xml", __AudioBindleTypePool);	
	return 0;
}
