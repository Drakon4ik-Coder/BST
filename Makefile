all: run_test run_replace clean_obj_asm

run_test:
	cl BSTtest.cpp BST.cpp /EHsc 
	BSTtest.exe

run_replace:
	cl replace.cpp BST.cpp /EHsc
	replace.exe test1.c
	replace.exe test2.c

clean:
	del *.obj
	del *.exe
	del *.asm
	del *.o

clean_obj_asm:
	del *.obj
	del *.asm