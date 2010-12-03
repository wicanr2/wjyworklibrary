#include <xmlConfig/xmlConfig.h>

struct _X264Profile {
	guint threads; // 0 - 4
	gint  pass; 
	/*
	(0): cbr              - Constant Bitrate Encoding
    (4): quant            - Constant Quantizer
    (5): qual             - Constant Quality
    (17): pass1            - VBR Encoding - Pass 1
    (18): pass2            - VBR Encoding - Pass 2
    (19): pass3            - VBR Encoding - Pass 3
	*/
	guint quantizer; //Constant quantizer or quality to apply Range 1-50 default 21
	gboolean byteStream; //Generate byte stream format of NALU Range: TRUE/FALSE
	guint bitrate; // Bitrate in kbit/sec  Range: 1 - 102400 Default: 2048
	guint vbvBufCapacity; //Size of the VBV buffer in milliseconds Range: 300 - 10000 Default: 600 Current: 600
	gint me;  
	/*
		Integer pixel motion estimation method
		(0): dia              - diamond search, radius 1 (fast)
        (1): hex              - hexagonal search, radius 2
        (2): umh              - uneven multi-hexagon search
        (3): esa              - exhaustive search (slow)
		Default: 1, "hex"
	*/
	guint subme;
	/*
		Subpixel motion estimation and partition decision quality: 1=fast, 6=best
		Range: 1 - 6 Default: 1
	*/
	gboolean dct8x8; //Adaptive spatial transform size Range: TRUE/FALSE  Default: false 
	guint ref; //Number of reference frames Range: 1 - 12 Default: 1
	guint bframes; //Number of B-frames between I and P Range: 0 - 4 Default: 0
	gboolean bAdapt; //Automatically decide how many B-frames to use Range: TRUE/FALSE Default: true
	gboolean bPyramid; //Keep some B-frames as references Range: TRUE/FALSE Default: false
	gboolean weightb; //Weighted prediction for B-frames Range: TRUE/FALSE Default: false
	guint spsId; //SPS and PPS ID number Range: 0 - 31 Default: 0
	gboolean trellis; //Enable trellis searched quantization Range: TRUE/FALSE Default: true
	guint keyIntMax; //Maximal distance between two key-frames (0 for automatic) Integer. Range: 0 - 2147483647 Default: 0
	gboolean cabac; //Enable CABAC entropy coding Range: TRUE/FALSE  Default: true
	guint qpMin; //Minimum quantizer Range: 1 - 51 Default: 10
	guint qpMax; //Maximum quantizer Range: 1 - 51 Default: 51
	guint qpStep; //Maximum quantizer difference between frames Range: 1 - 50 Default: 4 
	gfloat ipFactor; //Quantizer factor between I- and P-frames Range: 0.0 - 2.0 Default: 1.4
	gfloat pbFactor; //Quantizer factor between P- and B-frames Range: 0.0 - 2.0 Default: 1.3
	guint noiseReduction; // Noise reduction strength Range: 0 - 100000 Default: 0
	gboolean interlaced; //Interlaced material Range: TRUE/FALSE Default: false
};
static struct _X264Profile __x264Profile;
static TypePool __x264TypePool[] = {
	{"X264", "threads","threads", G_INT , &__x264Profile.threads },
	{"X264", "pass","pass", G_INT , &__x264Profile.pass },
	{"X264", "quantizer","quantizer", G_UINT , &__x264Profile.quantizer },
	{"X264", "byteStream","byte-stream", G_BOOL , &__x264Profile.byteStream },
	{"X264", "bitrate","bitrate", G_UINT , &__x264Profile.bitrate },
	{"X264", "vbvBufCapacity","vbv-buf-capacity", G_UINT , &__x264Profile.vbvBufCapacity },
	{"X264", "me","me", G_INT , &__x264Profile.me },
	{"X264", "subme","subme", G_UINT, &__x264Profile.subme },
	{"X264", "dct8x8","dct8x8", G_BOOL, &__x264Profile.dct8x8 },
	{"X264", "ref","ref", G_UINT, &__x264Profile.ref },
	{"X264", "bframes","bframes", G_UINT, &__x264Profile.bframes },
	{"X264", "bAdapt","b-adapt", G_BOOL, &__x264Profile.bAdapt },
	{"X264", "bPyramid","b-pyramid", G_BOOL, &__x264Profile.bPyramid },
	{"X264", "weightb","weightb", G_BOOL, &__x264Profile.weightb },
	{"X264", "spsId","sps-id", G_UINT, &__x264Profile.spsId },
	{"X264", "trellis","trellis", G_BOOL, &__x264Profile.trellis },
	{"X264", "keyIntMax","key-int-max", G_UINT, &__x264Profile.keyIntMax },
	{"X264", "cabac","cabac", G_BOOL, &__x264Profile.cabac },
	{"X264", "qpMin","qp-min", G_UINT, &__x264Profile.qpMin },
	{"X264", "qpMax","qp-max", G_UINT, &__x264Profile.qpMax },
	{"X264", "qpStep","qp-step", G_UINT, &__x264Profile.qpStep },
	{"X264", "ipFactor","ip-factor", G_FLOAT, &__x264Profile.ipFactor },
	{"X264", "pbFactor","pb-factor", G_FLOAT, &__x264Profile.pbFactor },
	{"X264", "noiseReduction","noise-reduction", G_UINT, &__x264Profile.noiseReduction },
	{"X264", "interlaced","interlaced", G_BOOL, &__x264Profile.interlaced },
	{ 0, 0, 0, LAST, 0 }
};

int X264Profile_Init()
{
	__XMLRegister("x264Profile", "config//x264.xml", __x264TypePool);	
	return 0;
}
