#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <utils/directorySubsidiary.h>

int DirSub_MakeFullPath
	(char *out, int outSize, char *path, char *file)
{
	int re = 0;
	if ( out == 0  ) return -1;
	if ( path == 0 ) return -1;
	if ( file == 0 ) return -1;

	re = snprintf( out, outSize, "%s/%s", path, file );
	if ( re < 0 ) return -1;
	return 0;
}
