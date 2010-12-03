#ifndef AUDIO_DEVICE_BINDLE_HPP
#define AUDIO_DEVICE_BINDLE_HPP
class __AudioDeviceBindle {
private:	
	char source[255];
	char sink[255];
public:
	__AudioDeviceBindle(const char *n1, const char *n2);
	bool CheckSink(const char *n);
	bool CheckSource(const char *n);
	const char* GetSource();
	const char* GetSink();
};
class __AudioBindle {
private:	
	__AudioDeviceBindle *Pool[4];
	int size ;
	char ringingSink[255];
	char ringingSource[255];
public:
	__AudioBindle();
	bool CheckSink(const char *n);
	bool CheckSource(const char *n);
	const char* RequestBindleSink(const char *src);
	const char* RequestBindleSource(const char *sink);
	const char* RequestRingingSink();
	const char* RequestRingingSource();
	//bindle info
	//bindle switch 
	/*
		is need bindle switch
	*/
};
#endif
