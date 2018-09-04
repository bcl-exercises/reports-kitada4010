GCC = gcc
CFLAGS =-Wall -O2
Loadlibs=-lm
work2-2_1: work2-2_1.c
	${GCC} ${CFLAGS} -o $@ $@.c
work2-2_2: work2-2_2.c
	${GCC} ${CFLAGS} -o $@ $@.c
work3-1_1: work3-1_1.c
	${GCC} ${CFLAGS} -o $@ $@.c
work3-1_2: work3-1_2.c
	${GCC} ${CFLAGS} -o $@ $@.c
work3-2_3: work3-2_3.c
	${GCC} ${CFLAGS} -o $@ $@.c
work3-2_4: work3-2_4.c
	${GCC} ${CFLAGS} -o $@ $@.c
work3-3_1: work3-3_1.c
	${GCC} ${CFLAGS} -o $@ $@.c
work3-3_2: work3-3_2.c
	${GCC} ${CFLAGS} -o $@ $@.c
work3-4_1: work3-4_1.c
	${GCC} ${CFLAGS} -o $@ $@.c
work3-4_2: work3-4_2.c
	${GCC} ${CFLAGS} -o $@ $@.c
mylib: mylib.c
	${GCC} ${CFLAGS} -c	 $@.c
genrand: genrand.c
	${GCC} ${CFLAGS} -o $@ $@.c
getdist.o: getdist.c mylib.h
	${GCC} ${CFLAGS} -c getdist.c ${Loadlibs}
getdist: mylib.o getdist.o
	${GCC} ${CFLAGS} mylib.o $@.o -o $@ ${Loadlibs}
getdist2.o: getdist2.c mylib.h
	${GCC} ${CFLAGS} -c $@.c ${Loadlibs}
getdist2: mylib.o getdist2.o
	${GCC} ${CFLAGS} mylib.o $@.o -o $@ ${Loadlibs}
clean:
	rm -f *~ *.o
tamesi:	tamesi.c
	${GCC} ${CFLAGS} -c $@.c
work7-1_b.o: work7-1_b.c
	${GCC} ${CFLAGS} -c work7-1_b.c
work7-1_b: work7-1_b.o mylib.o
	${GCC} ${CFLAGS} mylib.o $@.o -o $@
work7-2_b.o: work7-2_b.c mylib.h
	${GCC} ${CFLAGS} -c work7-2_b.c ${Loadlibs} 
work7-2_b: work7-2_b.o mylib.o
	${GCC} ${CFLAGS} mylib.o $@.o -o $@ ${Loadlibs}
array: array.c
	${GCC} ${CFLAGS} -o $@ $@.c
array2: array2.c
	${GCC} ${CFLAGS} -o $@ $@.c
showarg: showarg.c
	${GCC} ${CFLAGS} -o $@ $@.c
sum: sum.c
	${GCC} ${CFLAGS} -o $@ $@.c

