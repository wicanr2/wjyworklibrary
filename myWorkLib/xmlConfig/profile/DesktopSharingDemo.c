
#include <stdio.h>
#include <glib.h>
#include <xmlConfig/xmlConfig.h>

/*
 * XmlNodeType.Element Field = 1
 * XmlNodeType.EndElement Field = 15
 * XmlNodeType.DocumentType  = 10  <!DOCTYPE
 * XmlNodeType.SignificantWhitespace  = 14
 * */
#define PROFILE_NAME "DesktopSharingDemoProfile"

struct _DesktopSharingDemoProfile {
	//master
	gboolean runDemo;
	char clientIP[255];
	char desktopSharingForwardPort[255];
	char cameraForwardPort[255];
	char cameraReceivePort[255];
	
	//client
	char desktopSharingReceivePort[255];
	
};
static struct _DesktopSharingDemoProfile __DesktopSharingDemoProfile;

static TypePool __DesktopSharingDemoTypePool[] = {
	{ "Master", "ClientIP"   				,"none", CSTR	, __DesktopSharingDemoProfile.clientIP    				},
	{ "Master", "DesktopSharingForwardPort" ,"none", CSTR	, __DesktopSharingDemoProfile.desktopSharingForwardPort },
	{ "Master", "RunDemo"      				,"none", G_BOOL	, &__DesktopSharingDemoProfile.runDemo     				},
	{ "Client", "DesktopSharingReceivePort" ,"none", CSTR	, __DesktopSharingDemoProfile.desktopSharingReceivePort },
	{ 0, 0, 0, LAST, 0 }
};

int DesktopSharingDemoProfile_Init()
{
	__XMLRegister( PROFILE_NAME, "config//desktopSharingDemo//demo.xml", __DesktopSharingDemoTypePool);
	return 0;
}

