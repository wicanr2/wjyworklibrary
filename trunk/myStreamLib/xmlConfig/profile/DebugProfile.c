
#include <stdio.h>
#include <glib.h>
#include <xmlConfig/xmlConfig.h>

/*
 * XmlNodeType.Element Field = 1
 * XmlNodeType.EndElement Field = 15
 * XmlNodeType.DocumentType  = 10  <!DOCTYPE
 * XmlNodeType.SignificantWhitespace  = 14
 * */
#define PROFILE_NAME "DebugProfile"

struct _DebugProfile {
	int 	level;
};
static struct _DebugProfile __DebugProfile;
static TypePool __DebugTypePool[] = {
	{"Debug", "Level","none", INT, &__DebugProfile.level },
	{ 0, 0, 0, LAST, 0 }
};

int DebugProfile_Init()
{
	__XMLRegister( PROFILE_NAME, "config//debug.xml", __DebugTypePool);	
	return 0;
}
