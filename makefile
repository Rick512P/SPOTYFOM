index:
	clear
	gcc -o executavel Files_C/*.c
	clear
	./executavel

testes:
	clear
	gcc -o Testes -g Files_C/*.c
	gdb ./Testes

clear:
	@if [ -f executavel ]; then \
		rm executavel; \
	fi
	@if [ -f Testes ]; then \
		rm Testes; \
	fi
	clear
