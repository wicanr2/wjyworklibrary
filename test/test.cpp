#include "PipeReader.hpp"
#include <stdio.h>

extern "C" {
int addtest(int a, int b);
}

int main(int argc, char*argv[]){
	int a = 10, b = 20 , c = 0;
	pipeReader pr;
	pr.RunCommand("dir");
	pr.Dump();
	c = addtest(a,b);
	printf("c = %d\n", c);
	return 0;
}
