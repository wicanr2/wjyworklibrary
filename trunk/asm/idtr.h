#ifndef IDTR_H
#define IDTR_H
struct IDTR {
	unsigned short limit:16;
	int base:32;
};
void loadIDTR2(struct IDTR *i);
void loadIDTR(struct IDTR *i);
void loadIDTRTest();
#endif

