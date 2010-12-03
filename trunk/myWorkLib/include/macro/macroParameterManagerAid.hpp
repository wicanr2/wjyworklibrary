#ifndef MACRO_PARAMETER_MANAGER_AID_HPP
#define MACRO_PARAMETER_MANAGER_AID_HPP
#include <macro/macroLoggerAid.hpp>
// add parameter to pool
#define MACRO_PARA_MGR_ADD_START(roleName,streamName,para_type)\
	{\
		paraBase *pb=0;\
		para_type* ptr=0;\
		char role[]= roleName ;\
		char stream[255] ;\
		snprintf( stream, 255, "%s", streamName );\
		ptr = new para_type();

#define MACRO_PARA_MGR_ADD_END()\
		pb = dynamic_cast<paraBase*>(ptr);\
		if ( pb )\
		{\
			pb->SetRole( role );\
			pb->SetBelongStream( stream );\
			this->pool->AppendItem(pb);\
		}\
	}
// hash mapping add
#define MACRO_PARA_MGR_HASH_MAPPING(roleName,streamName)\
	do{\
		char role[]   = roleName ;\
		char stream[255];\
		snprintf( stream, 255, "%s", streamName );\
		this->QueryStreamParams( role , stream );\
		paraBase *tmp = 0;\
		if ( this->GetDebugFlagLevel2() ) {\
			MACRO_LOGGER_PRINT_DIVIDE_LINE();\
			printf("\t\t%s:%s HashMapping\n\n", role, stream);\
		}\
		for ( int i = 0 ; i < this->GetQueryStreamParamsSize() ; i++ )\
		{\
			tmp = this->QueryStreamParamsI(i);\
			if ( tmp != 0 )\
				XCFG2_HashMappingParams( tmp->GetBelongStream(), tmp );\
		}\
		if ( this->GetDebugFlagLevel2() ) {\
			MACRO_LOGGER_PRINT_DIVIDE_LINE();\
		}\
	}while(0)

#define MACRO_PARA_MGR_CHANGE_RESOLUTION(index, width, height)\
	do{\
		char role  [] = ROLE_TRANSMITTER;\
		char stream[] = TRANSCODE_MJPEG_TO_H264_STREAM;\
		char para  [] = PARA_VIDEOSCALE_FILTER;\
		gint _w = width;\
		gint _h = height;\
		paraBase *tmp = 0;\
		paraVideoScale *_ptr = 0;\
		tmp = (paraBase*) PARAMETER_MANAGER_Query(role, stream, para );\
		_ptr = dynamic_cast<paraVideoScale*>(tmp);\
		if ( _ptr ) {\
			if ( _w > 0 )  _ptr->SetWidth (_w);\
			if ( _h > 0 )  _ptr->SetHeight(_h);\
			if ( _w > 0 || _h > 0 ) {\
				printf("Change Video Transmitter Resolution to %dx%d\n",\
					_ptr->GetWidth(), _ptr->GetHeight() );\
			}\
		}\
	}while(0)

#define MACRO_PARA_MGR_CHANGE_FRAMERATE(index, fr, base)\
	do{\
		char role  [] = ROLE_TRANSMITTER;\
		char stream[] = TRANSCODE_MJPEG_TO_H264_STREAM;\
		char para  [] = PARA_VIDEORATE_FILTER;\
		gint _base = base;\
		gint _fr   = fr;\
		paraBase *tmp = 0;\
		paraVideoRate *_ptr = 0;\
		tmp = (paraBase*) PARAMETER_MANAGER_Query(role, stream, para );\
		_ptr = dynamic_cast<paraVideoRate*>(tmp);\
		if ( _ptr ) {\
			if ( _base > 0 ) _ptr->SetBase(_base);\
			if ( _fr   > 0 ) _ptr->SetFramerate( _fr);\
			if ( _base > 0 || _fr > 0 ) {\
				printf("Change Video Transmitter Rate to %d/%d\n",\
					_ptr->GetFramerate(), _ptr->GetBase() );\
			}\
		}\
	}while(0)
//--------------------------------------------------------------------
// query resolution and framerate
#define MACRO_PARA_MGR_QUERY_RESOLUTION(index, width, height)\
	do{\
		char role  [] = ROLE_TRANSMITTER;\
		char stream[] = TRANSCODE_MJPEG_TO_H264_STREAM;\
		char para  [] = PARA_VIDEOSCALE_FILTER;\
		paraBase *tmp = 0;\
		paraVideoScale *_ptr = 0;\
		tmp = (paraBase*) PARAMETER_MANAGER_Query(role, stream, para );\
		_ptr = dynamic_cast<paraVideoScale*>(tmp);\
		if ( _ptr ) {\
			*width  =  _ptr->GetWidth();\
			*height =  _ptr->GetHeight();\
		}\
	}while(0)

#define MACRO_PARA_MGR_QUERY_FRAMERATE(index, fr, base)\
	do{\
		char role  [] = ROLE_TRANSMITTER;\
		char stream[] = TRANSCODE_MJPEG_TO_H264_STREAM;\
		char para  [] = PARA_VIDEORATE_FILTER;\
		paraBase *tmp = 0;\
		paraVideoRate *_ptr = 0;\
		tmp = (paraBase*) PARAMETER_MANAGER_Query(role, stream, para );\
		_ptr = dynamic_cast<paraVideoRate*>(tmp);\
		if ( _ptr ) {\
			*fr    = _ptr->GetFramerate();\
			*base  = _ptr->GetBase();\
		}\
	}while(0)

#endif
