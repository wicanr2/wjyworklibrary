#include <stdio.h>

int addtest(int a,int b);
float addF(float a, float b);

struct IDTR {
	unsigned short limit:16;
	int base:32;
};
struct IDTR idtr;

void loadIDTR2(struct IDTR *i);
void loadIDTR(struct IDTR *i) {
	i->limit = 50;
	i->base = 5100;
}

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
	loadIDTR2( &idtr );
	printf("idtr.limit = %X\n", idtr.limit );
	printf("idtr.base  = %X\n", idtr.base);
	loadIDTR( &idtr );
	printf("idtr.limit = %d\n", idtr.limit );
	printf("idtr.base  = %d\n", idtr.base);
	printf("sizeof(unsigned short) = %d\n", sizeof(unsigned short));
	printf("sizeof(int) = %d\n", sizeof(int));
	printf("sizeof(idtr) = %d\n", sizeof(idtr));
	re = addtest(10,20);
	printf("re = %d\n", re);
	printf(" c = %f\n", addF(a,b) ) ;
	return 0;	
}
