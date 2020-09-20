all: hw_01

hw_01: obj/main.o obj/bmp.o 
	gcc obj/main.o obj/bmp.o -g -o hw_01 -I./include -Wall -Werror -Wextra


obj/main.o: src/main.c | obj
	gcc -c src/main.c -g -o obj/main.o -Wall -Werror -Wextra -I./include

obj/bmp.o: src/bmp.c | obj
	gcc -c src/bmp.c -g -o obj/bmp.o -Wall -Werror -Wextra -I./include

obj: 
	mkdir obj

clean:
	rm -fr obj main *~ hw_01
