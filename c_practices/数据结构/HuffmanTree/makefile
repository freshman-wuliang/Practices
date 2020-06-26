all : demo clean

Object = demo.o HuffmanTree.o BitTree.o SeqList.o

demo : $(Object)
	gcc -o demo $(Object)
	
demo.o : demo.c HuffmanTree.h
	gcc -c demo.c

HuffmanTree.o : HuffmanTree.c HuffmanTree.h
	gcc -c HuffmanTree.c
	
BitTree.o : BitTree.c BitTree.h
	gcc -c BitTree.c
	
SeqList.o : SeqList.c SeqList.h
	gcc -c SeqList.c
	
.PHONY : clean

clean : 
	del $(Object)