#ifndef PARAMETER_X264ENC_HPP
#define PARAMETER_X264ENC_HPP
#include <baseStream/baseStream.hpp>
#include <conference/parameterManager/paraBase.hpp>
class paraX264Enc:public paraBase {
protected:
	gint 	 threads;
	gint 	 pass;
	guint 	 quantizer;
  	gboolean byteStream;
	guint	 bitrate;
	guint	 vbvBufCapacity;
	gint	 me;
	guint	 subme;
	gboolean dct8x8;
	guint	 ref;
	guint  	 bframes;
	gboolean bAdapt;
	gboolean bPyramid;
	gboolean weightb;
	guint	 spsId;
	gboolean trellis;
	guint 	 keyIntMax;
	gboolean cabac;
	guint	 qpMin;
	guint	 qpMax;
	guint	 qpStep;
	gfloat	 ipFactor;
	gfloat	 pbFactor;
	guint	 noiseReduction;
	gboolean interlaced;
	
public:
	paraX264Enc();
	~paraX264Enc();
	
	//set function
	int SetThreads(gint v);
	int SetPass(gint v);
	int SetQuantizer(guint v);
	int SetByteStream(gboolean b);
	int SetBitrate(guint v);
	int SetVBVBufCapacity(guint v);
	int SetMe(gint v);
	int SetSubme(guint v);
	int SetDCT8x8(gboolean b);
	int SetRef(guint v);
	int SetBframes(guint v);
	int SetBAdapt(gboolean b);
	int SetBPyramid(gboolean b);
	int SetWeightb(gboolean b);
	int SetSPSId(guint v);
	int SetTrellis(gboolean b);
	int SetKeyIntMax(guint v);
	int SetCabac(gboolean b);
	int SetQPMin(guint v);
	int SetQPMax(guint v);
	int SetQPStep(guint v);
	int SetIPFactor(gfloat v);
	int SetPBFactor(gfloat v);
	int SetNoiseReduction(guint v);
	int SetInterlaced(gboolean b);
	
	//get function
	gint	 GetThreads();
	gint	 GetPass();
	guint 	 GetQuantizer();
	gboolean GetByteStream();
	guint	 GetBitrate();
	guint 	 GetVBVBufCapacity();
	gint	 GetMe();
	guint	 GetSubme();
	gboolean GetDCT8X8();
	guint	 GetRef();
	guint	 GetBframes();
	gboolean GetBAdapt();
	gboolean GetBPyramid();
	gboolean GetWeightb();
	guint	 GetSPSId();
	gboolean GetTrellis();
	guint 	 GetKeyIntMax();
	gboolean GetCabac();
	guint	 GetQPMin();
	guint	 GetQPMax();
	guint 	 GetQPStep();
	gfloat 	 GetIPFactor();
	gfloat	 GetPBFactor();
	guint	 GetNoiseReduction();
	gboolean GetInterlaced();
	
	std::ostream& Dump(std::ostream& out)const;
};
#endif
