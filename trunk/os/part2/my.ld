MEMORY 
{
/*	rom (rx)  : ORIGIN = 0, LENGTH = 256K
  ram (!rx) : org = 0x40000000, l = 4M*/
	my_pc_start (rx) : org = 0x7c00, l = 14400K 
}
ENTRY(_start)
SECTIONS
{
	.starter : {
		hello.o(.text);
		. = 0x168000;
	}> my_pc_start  
}  

