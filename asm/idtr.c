#include <idtr.h>
void loadIDTR(struct IDTR *i) {
	i->limit = 50;
	i->base = 5100;
}
void loadIDTRTest(){
	struct IDTR idtr;
	loadIDTR2( &idtr );
	printf("idtr.limit = %X\n", idtr.limit );
	printf("idtr.base  = %X\n", idtr.base);
	loadIDTR( &idtr );
	printf("idtr.limit = %d\n", idtr.limit );
	printf("idtr.base  = %d\n", idtr.base);
	printf("sizeof(unsigned short) = %d\n", sizeof(unsigned short));
	printf("sizeof(int) = %d\n", sizeof(int));
	printf("sizeof(idtr) = %d\n", sizeof(idtr));
}
