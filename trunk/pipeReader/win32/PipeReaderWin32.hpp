#ifndef PIPE_READER_HPP
#define PIPE_READER_HPP
class pipeReader {
private:
	char *outputPool; 
	int outputPoolSize;
	int lineSize;
	int usedSize;
public:
	pipeReader();
	~pipeReader();
	int SetLineSize(int lSize);
	int SetOutputPoolSize(int oSize);
	int RunCommand(char *cmd);
	int Dump();  
};
#endif
