#ifndef CONFERENCE_CONSTANT_HPP
#define CONFERENCE_CONSTANT_HPP

// role
#define ROLE_TRANSMITTER		"Transmitter"
#define ROLE_RECEIVER			"Receiver"
#define ROLE_NULL				"Role_Null"

#define NULL_STREAM  					  "null"
// transmitter stream name 
#define CAPTURE_MJPEG_STREAM 			  "CaptureMJPEGStream"
#define CAPTURE_AUDIO_RAW_STREAM 		  "CaptureAudioRawStream"

#define TRANSCODE_MJPEG_TO_H264_STREAM 	  "TranscodeMJPEGToH264Stream"
#define TRANSCODE_RAW_AUDIO_TO_GSM_STREAM "TranscodeAudioRawToGSMStream"

#define TRANSMITTER_RELAY_STREAM		  "TransmitterRelayStream"
#define TRANSMITTER_VIDEO_RELAY_STREAM	  "TransmitterVideoRelayStream"
#define TRANSMITTER_AUDIO_RELAY_STREAM	  "TransmitterAudioRelayStream"
#define NULL_RELAY_STREAM				  "NullRelayStream"

// receiver stream name
// receiver video relay stream
#define RECEIVER_VIDEO_RELAY_STREAM       "ReceiverVideoRelayStream" 
#define RECEPTION_VIDEO_H264_STREAM       "ReceptionH264Stream" 

// receiver audio relay stream
#define RECEIVER_AUDIO_RELAY_STREAM       "ReceiverAudioRelayStream"
#define RECEPTION_AUDIO_GSM_STREAM        "ReceptionGSMStream" 

// parameter constant
#define MAX_PARAMETER_POOL_SIZE 1000

#define PARAMETER_NULL_NAME 	       "None"
#define PARA_MJPEG_ENC 			       "MJPEGEncParameter"
#define PARA_V4L2_SRC  			       "V4L2SrcParameter"
#define PARA_VIDEORATE_FILTER 	       "VideoRateParameter"
#define PARA_VIDEOSCALE_FILTER         "VideoScaleParameter"
#define PARA_X264_ENC			       "X264EncParameter"
#define PARA_UDP_SRC			       "UDPSrcParameter"
#define PARA_UDP_SINK			       "UDPSinkParameter"
#define PARA_MULTIUDP_SINK		       "MultiUDPSinkParameter"
#define PARA_PULSE_SRC                 "PulseSrcParameter"
#define PARA_AUDIORESAMPLE_FILTER      "AudioResamplecParameter"
#define PARA_AUDIOCONVERT_FILTER       "AudioConvertParameter"

#define PARA_GSTRTPJITTERBUFFER_FILTER "GSTRtpJitterBufferParameter"
#define PARA_PULSE_SINK                "PulseSinkParameter"
#define PARA_AUDIOAMPLIFY_FILTER       "AudioAmplifyParameter"

#define PARA_XVIMAGE_SINK              "XVImageSinkParameter"


// default port
#define CAPTURE_MJPEG_STREAM_FORWARD_HOST "127.0.0.1"
#define CAPTURE_MJPEG_STREAM_FORWARD_PORT 51000
#define TRANSCODE_MJPEG_TO_H264_STREAM_FORWARD_HOST "127.0.0.1"
#define TRANSCODE_MJPEG_TO_H264_STREAM_FORWARD_PORT 51010

#define CAPTURE_AUDIO_RAW_STREAM_FORWARD_HOST "127.0.0.1"
#define CAPTURE_AUDIO_RAW_STREAM_FORWARD_PORT 52000

#define TRANSCODE_RAW_AUDIO_TO_GSM_STREAM_FORWARD_HOST  "127.0.0.1"
#define TRANSCODE_RAW_AUDIO_TO_GSM_STREAM_FORWARD_PORT  52010

#define TRANSMITTER_VIDEO_RELAY_STREAM_INTERNAL_DEFAULT_LOCATION "127.0.0.1:5555"
#define TRANSMITTER_AUDIO_RELAY_STREAM_INTERNAL_DEFAULT_LOCATION "127.0.0.1:8888"

// receiver video reception port base
// recv port for video streaming 
#define RECEIVER_VIDEO_RELAY_STREAM_PORT_BASE 9000
// internal video streaming forward port
#define RECEIVER_VIDEO_RELAY_STREAM_FORWARD_HOST "127.0.0.1"
#define RECEIVER_VIDEO_RELAY_STREAM_FORWARD_PORT_BASE 10000

// recv port for audio streaming 
#define RECEIVER_AUDIO_RELAY_STREAM_PORT_BASE 11000
// internal audio streaming forward port
#define RECEIVER_AUDIO_RELAY_STREAM_FORWARD_HOST "127.0.0.1"
#define RECEIVER_AUDIO_RELAY_STREAM_FORWARD_PORT_BASE 12000

#define NULL_HOST "0.0.0.0"
// max peerRelayStr size
#define MAX_PEER_RELAY_STRING_SIZE 4096
// for GST Capability
// media type
#define MEDIA_TYPE_VIDEO_YUV 	 "video/x-raw-yuv"
#define MEDIA_TYPE_AUDIO_INT 	 "audio/x-raw-int"
#define MEDIA_TYPE_GST_X_RTP	 "application/x-rtp"
#define MEDIA_TYPE_NULL			 "media/null"

#define __GST_MEDIA_VIDEO		 "video"
#define __GST_MEDIA_AUDIO		 "audio"
#define __GST_MEDIA_NULL		 "null"
#define __GST_CLOCKRATE_90000	 90000
#define __GST_CLOCKRATE_44100	 44100
#define __GST_CLOCKRATE_8000	 8000
#define __GST_ENCODING_NAME_H264 "H264"
#define __GST_ENCODING_NAME_L16  "L16"
#define __GST_ENCODING_NAME_JPEG "JPEG"
#define __GST_ENCODING_NAME_GSM  "GSM"
#define __GST_ENCODING_NAME_NULL "null"
#define __GST_PAYLOAD_DYNAMIC_96 96
#define __GST_PAYLOAD_96		 96
#define __GST_PAYLOAD_3		     3
#define __GST_RATE_44100		 44100
#define __GST_RATE_8000			 8000
#define __GST_CHANNELS_1		 1
#define __GST_WIDTH_16			 16 
#define __GST_DEPTH_16			 16
#define __GST_ENDIANNESS_1234	 1234
#define __GST_SIGNED_TRUE		 TRUE
// for different resolution
#define __GST_WIDTH_640			 640
#define __GST_HEIGHT_480		 480
#define __GST_WIDTH_320			 320
#define __GST_HEIGHT_240  		 240
#define __GST_WIDTH_176			 176
#define __GST_HEIGHT_144	     144
// framerate
#define __GST_FRAMERATE_15		 15
#define __GST_FRAMERATE_BASE_1	 1

#endif
