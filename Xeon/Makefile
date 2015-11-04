# CC=gcc
# CC=/opt/intel/bin/icc
CC=icc
ALL=test1 test2 test3 test4 my_test1 test_loop test_s_loop

OMP_OPTION=-openmp
OPT_OPTION=-O3
LOPTION=
PHI_OPTION=-mmic
PHI_L_OPTION=-Xlinker -rpath -Xlinker /usr/jlocal/mic/lib
DEBUG_OPTION=
# PHI_OPTION=

C_OPTION=${OMP_OPTION} ${OPT_OPTION} ${PHI_OPTION} ${LOPTION} ${DEBUG_OPTION}
O_OPTION=${LOPTION} ${PHI_L_OPTION} ${PHI_OPTION} ${OMP_OPTION} ${DEBUG_OPTION}

all: ${ALL}

test1: test1.o
	${CC} ${O_OPTION} -o $@ $^

test2: test2.o
	${CC} ${O_OPTION} -o $@ $^
	
test3: test3.o
	${CC} ${O_OPTION} -o $@ $^

test4: test4.o
	${CC} ${O_OPTION} -o $@ $^

my_test1: my_test1.o
	${CC} ${O_OPTION} -o $@ $^

test_loop: test_loop.o test_loop.h
	${CC} ${O_OPTION} -o $@ $<

test_s_loop: test_s_loop.o test_loop.h
	${CC} ${O_OPTION} -o $@ $<

.c.o:
	${CC} -c ${C_OPTION} $^
	
clean:
	rm *.o
	rm ${ALL}
