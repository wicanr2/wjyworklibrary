#include <stdio.h>
#include <add.h>
#include <idtr.h>


int main(int argc, char* argv[]){
	//FILE *pfp = _popen ("dir","r");
	//char buf[255];
	//int i = 0;
	int re = 0;
	double a = 10.0f , b = 20.0f;
	//while( fgets(buf, 255, pfp ) != NULL ) {
	//		printf("[line %d] %s",i,buf);
	//		i++;
	//}
	//_pclose(pfp);
	re = addtest(10,20);
	printf("re = %d\n", re);
	printf(" c = %f\n", addF(a,b) ) ;
	return 0;	
}
