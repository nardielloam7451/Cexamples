pgm1: print.o sort.o date.o times.o order.o class.o main.o
	gcc -o prgm1 print.o sort.o date.o times.o order.o class.o main.o

print.o: classes.h print.c
	gcc -c -Wall print.c

sort.o: classes.h sort.c
	gcc -c -Wall sort.c

date.o: classes.h date.c
	gcc -c -Wall date.c

times.o: classes.h times.c
	gcc -c -Wall times.c

order.o: classes.h order.c
	gcc -c -Wall order.c

class.o: classes.h class.c
	gcc -c -Wall class.c

main.o: classes.h main.c
	gcc -c -Wall main.c
