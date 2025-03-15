.PHONY: all build run

build:
	make -C tree build
	
run:
	make -C tree run

tree.o:
	make -C tree tree.o

main.o:
	make -C tree main.o

clean:
	make -C tree clean