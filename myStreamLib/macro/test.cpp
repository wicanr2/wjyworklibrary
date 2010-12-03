#include <stdio.h>
#include <curses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <glib.h>
#include <glib/gprintf.h>
#include<macro/macroVariableAccess.hpp>
#include<macro/macroParameterAid.hpp>
#include<macro/macroDebugClassAid.hpp>
#include<macro/macroErrorCheck.hpp>
#include <xmlConfig/constant.hpp>
#include <conference/constant.hpp>
#include <conference/parameterManager/parameterManager.hpp>
#include <conference/parameterManager/parameterManagerCAPI.h>

MACRO_VAR_DECL_FULL( gint, Dithering, dithering );
MACRO_VAR_DECL(gint ,Dithering);
MACRO_VAR_DECL(gint, NoiseShaping);
MACRO_VAR_IMPL( paraAudioConvert, gint, Dithering, dithering );
MACRO_VAR_IMPL( paraAudioConvert, gint, NoiseShaping, noise_shaping);
MACRO_PARA_SET_XML_NAME( XML_GSTRTP );
MACRO_PARA_ASSOCIATE_XML_ATTR( XML,gint,txsadsada);
MACRO_PARA_SET_XML_NAME(XML_GSTRTPJITTERBUFFER_ELEMENT_NAME);


MACRO_VAR_STR_DECL_FULL(TestStr,test_str);
MACRO_VAR_STR_IMPL(x,TestStr,test_str);

int main( int argc, char *argv[] ) {
	if ( b )  
		MACRO_DEBUG_CLASS_PRINT_L3("Set \tbaseStream::bCreated == true\n");
	else 
		MACRO_DEBUG_CLASS_PRINT_L3("Set \tbaseStream::bCreated == false\n");
	MACRO_ERROR_CHECK_WITH_DEBUG( this->profilePool, 0, -1, "the profilePool is NULL\n");
	MACRO_ERROR_CHECK_0_WITH_DEBUG(this->profilePool);
	MACRO_ERROR_CHECK_NOT_EQUAL_WITH_DEBUG( 
		profile, 0, -1, "the profile %s was existed\n", name );

	MACRO_RECEIVER_STREAM_MAKE_VIDEO_RELAY_STREAM_NAME(1);
	MACRO_RECEIVER_STREAM_MAKE_VIDEO_RELAY_STREAM_NAME(2);
	MACRO_RECEIVER_STREAM_MAKE_VIDEO_RELAY_STREAM_NAME(3);
	MACRO_RECEIVER_STREAM_MAKE_VIDEO_RELAY_STREAM_NAME(4);

	MACRO_RECEIVER_STREAM_MAKE(4);
	MACRO_RECEIVER_STREAM_MAKE(1);
	RECEIVER_VIDEO_RELAY_STREAM_0; 
	RECEIVER_VIDEO_RELAY_STREAM_1;
	RECEIVER_VIDEO_RELAY_STREAM_2;
	RECEIVER_VIDEO_RELAY_STREAM_3;
	RECEIVER_VIDEO_RELAY_STREAM_4;
	RECEIVER_VIDEO_RELAY_STREAM_5;
	RECEIVER_VIDEO_RELAY_STREAM_6;
	RECEIVER_VIDEO_RELAY_STREAM_7;
	RECEIVER_VIDEO_RELAY_STREAM_8;
	RECEIVER_VIDEO_RELAY_STREAM_9;
	MACRO_PARA_MGR_CHANGE_RESOLUTION(-1,320,240);
	return 0;
}
