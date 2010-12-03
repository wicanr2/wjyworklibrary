
#include <stdio.h>
#include <glib.h>
#include <xmlConfig/xmlConfig.h>

/*
 * XmlNodeType.Element Field = 1
 * XmlNodeType.EndElement Field = 15
 * XmlNodeType.DocumentType  = 10  <!DOCTYPE
 * XmlNodeType.SignificantWhitespace  = 14
 * */


struct _PulseAudioProfile {
	gboolean removeStreamVolumeDB;
	gboolean removeDeviceVolumeDB;
	gboolean removeDefaultSourceDB;
	gboolean removeDefaultSinkDB;
	gboolean updateSourceStreamVolumeDB;
	gboolean updateSinkStreamVolumeDB;
};
static struct _PulseAudioProfile __PAProfile;
static TypePool __PATypePool[] = {
	{"PulseAudioProfile", "removeStreamVolumeDB"      ,"none", G_BOOL, &__PAProfile.removeStreamVolumeDB       },
	{"PulseAudioProfile", "removeDeviceVolumeDB"      ,"none", G_BOOL, &__PAProfile.removeDeviceVolumeDB       },
	{"PulseAudioProfile", "removeDefaultSourceDB"     ,"none", G_BOOL, &__PAProfile.removeDefaultSourceDB      },
	{"PulseAudioProfile", "removeDefaultSinkDB"       ,"none", G_BOOL, &__PAProfile.removeDefaultSinkDB        },
	{"PulseAudioProfile", "updateSourceStreamVolumeDB","none", G_BOOL, &__PAProfile.updateSourceStreamVolumeDB },
	{"PulseAudioProfile", "updateSinkStreamVolumeDB"  ,"none", G_BOOL, &__PAProfile.updateSinkStreamVolumeDB   },
	{ 0, 0, 0, LAST, 0 }
};

int PAProfile_Init()
{
	__XMLRegister("PulseAudioProfile", "config//PA.xml", __PATypePool);
	return 0;
}
