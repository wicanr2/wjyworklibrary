#ifndef XML_CONSTANT_HPP
#define XML_CONSTANT_HPP

#define XML_CONSTANT_MAX_VALUE_LENGTH 128
#define XML_CONSTANT_MAX_NAME_LENGTH 128
#define XML_CONSTANT_MAX_ATTRIBUTES_SIZE 30
#define XML_CONSTANT_MAX_ELEMENTS_SIZE 80
#define XML_CONSTANT_MAX_PROFILES_SIZE 80
#define XML_CONSTANT_MAX_TEMP_ELEMENTS_LIST_SIZE 100
#define XML_CONSTANT_MAX_ADAPTIVE_RULE_LIST_SIZE 100

// xmlboot.xml
#define XML_SUMMARY_PROFILE_NAME     "XMLBOOT"
#define XML_SUMMARY_PROFILE_LOCATION "xmlboot.xml"
#define XML_SUMMARY_PROFILE_PATH     "config/xml2"

// const value
#define XML_NO_VALUE "No Value"

// field constant
#include "xmlElementField/profile.hpp" 
#include "xmlElementField/xmlAudioConvert.hpp" 
#include "xmlElementField/xmlAudioResample.hpp" 
#include "xmlElementField/xmlGSTCaps.hpp" 
#include "xmlElementField/xmlMJPEG.hpp" 
#include "xmlElementField/xmlMultiUDPSink.hpp" 
#include "xmlElementField/xmlPulseSrc.hpp" 
#include "xmlElementField/xmlStream.hpp" 
#include "xmlElementField/xmlUDPSink.hpp" 
#include "xmlElementField/xmlUDPSrc.hpp" 
#include "xmlElementField/xmlV4L2.hpp" 
#include "xmlElementField/xmlVideoRate.hpp" 
#include "xmlElementField/xmlVideoScale.hpp" 
#include "xmlElementField/xmlX264Enc.hpp" 
#include "xmlElementField/xmlGSTRtpJitterBuffer.hpp" 
#include "xmlElementField/xmlXVImageSink.hpp" 
#include "xmlElementField/xmlPulseSink.hpp" 
#include "xmlElementField/xmlAudioAmplify.hpp" 
#include "xmlElementField/xmlAdaptiveRule.hpp" 
#endif
