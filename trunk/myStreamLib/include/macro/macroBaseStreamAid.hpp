#ifndef MACRO_BASESTREAM_AID_HPP
#define MACRO_BASESTREAM_AID_HPP
#include <macro/macroErrorCheck.hpp>
#define MACRO_BASESTREAM_STRAM_HASH_MAPPING( roleName, streamName )\
	do{\
		char name[255];\
		char role[] = roleName  ;\
		snprintf( name, 255, "%s", streamName );\
		this->SetStreamName(name);\
		this->SetRole(role);\
		XCFG2_HashMappingStream ( name, (baseStream*)this );\
	}while(0)

#define MACRO_BASESTREAM_STRAM_PASSIVE_HASH_MAPPING( roleName, streamName )\
	do{\
		char name[255];\
		char role[] = roleName  ;\
		snprintf( name, 255, "%s", streamName );\
		this->SetStreamName(name);\
		this->SetRole(role);\
		this->SetPassiveStream(true);\
		XCFG2_HashMappingStream ( name, (baseStream*)this );\
	}while(0)

#define MACRO_BASESTREAM_CREATE_PIPELINE()\
	do{\
		this->pipeline = gst_pipeline_new ( this->GetStreamName() );\
		MACRO_ERROR_CHECK_0_WITH_DEBUG( this->pipeline);\
	}while(0)

// create element
#define MACRO_BASESTREAM_CREATE_GSTELEMENT( ptr, _e1, _e2 ) \
	do{ \
		char element[] = #_e1; \
		char elementName[] = #_e2; \
		ptr   = \
			this->CreateGstElement( element, elementName ); \
		if ( ptr == 0 ) \
			return -1;\
	}while(0)
// set properties
#define MACRO_BASESTREAM_SET_PARAMS_START( para_type, paraName )\
	do{ \
		char para  [] = paraName ;\
		paraBase *tmp = 0;\
		para_type *ptr = 0;\
		tmp = (paraBase*) PARAMETER_MANAGER_Query(\
			this->GetRole(), \
			this->GetStreamName() , para );\
		MACRO_ERROR_CHECK_WITH_DEBUG( \
			tmp, 0, -1, "the parameter %s is not existed\n", para );\
		ptr = dynamic_cast<para_type*>(tmp);\
		if ( ptr ) { \
			while(0) 

#define MACRO_BASESTREAM_SET_PARAMS_END()\
		}\
		if ( this->GetDebugFlagLevel5() )\
			std::cout<< *tmp << std::endl;\
	}while(0)	
//--------------------------------------------------------
#define MACRO_PARAMETER_OBJECT_SET(obj,var_name,var)\
	do {\
		g_object_set ( G_OBJECT (obj), #var_name , var  , NULL);\
	} while(0)

#define MPARA_OBJSET(obj,var_name,var)\
		MACRO_PARAMETER_OBJECT_SET(obj,var_name,var)
//--------------------------------------------------------
// stream destination display
#define MACRO_BASESTREAM_SHOW_CAPTURE_STREAM_DESTINATION(udpsink)\
	do { \
		printf("%-30s, transfer data to   %s:%d\n", \
			this->GetStreamName(), udpsink->GetHost(), udpsink->GetPort() );\
	}while(0)

#define MACRO_BASESTREAM_SHOW_TRANSCODE_STREAM_DESTINATION(multiudpsink)\
	do { \
		printf("%-30s, stream   data to   %s\n", \
			this->GetStreamName(), multiudpsink->GetClients());\
	}while(0)

#define MACRO_BASESTREAM_SHOW_RELAY_STREAM_DESTINATION(tmp)\
	do { \
		printf("%-30s, relay    data to   %s\n", \
			this->GetStreamName(), tmp);\
	}while(0)

#define MACRO_BASESTREAM_SHOW_STREAM_SOURCE(udpsrc)\
	do { \
		printf("%-30s, receive  data from %d\n", \
			this->GetStreamName(), udpsrc->GetPort());\
	}while(0)

#endif
