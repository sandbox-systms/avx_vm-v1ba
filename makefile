CC=gc
ASM=nasm
LD=ld

all: 
	$(CC)compiler/codegen.c -o compiler/codegen
	$(ASM) -f elf64 src/*.asm
	$(LD) -o main avx_vm.o

clean:	
	rm -f main avx_vm.o compiler/codegen