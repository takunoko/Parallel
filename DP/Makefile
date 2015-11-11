
# macの場合はbrewで入れた最新版のgccを使うとopenmpが使える
# 標準のgccでは-fopenmpをつけても使えない
#
# CC=/usr/local/bin/gcc-5
# OMP_OPTION=-fopenmp
# VEC_REPO=-ftree-vectorizer-verbose=2 
#
CC=icc
OMP_OPTION=-openmp
# VEC_REPO=-no-vec -qopt-report
VEC_REPO=-qopt-report
# PHI_OPTION=-mmic
# PHI_L_OPTION=-Xlinker -rpath -Xlinker /usr/jlocal/mic/lib
#
ALL=Xeon_dp Xeon_dp_100_v0 Xeon_dp_100_v1 Xeon_dp_100_v2 test_dp vec_test
DPFILES=dragonPole.o
DPFILES_2=dragonPole_2.o

OPT_OPTION=-O3
LOPTION=
DEBUG_OPTION=
SFMT_OPTION=-I SFMT -DSFMT_MEXP=19937 -O3 -msse2

C_OPTION=${OMP_OPTION} ${OPT_OPTION} ${PHI_OPTION} ${LOPTION} ${DEBUG_OPTION}
O_OPTION=${LOPTION} ${PHI_L_OPTION} ${PHI_OPTION} ${OMP_OPTION} ${DEBUG_OPTION}

all: ${ALL}

Xeon_dp: Xeon_dp.o ${DPFILES}
	${CC} ${O_OPTION} -o $@ $^

Xeon_dp_100_v0: Xeon_dp_100_v0.o ${DPFILES}
	${CC} ${O_OPTION} -o $@ $^

Xeon_dp_100_v1: Xeon_dp_100_v1.o ${DPFILES} SFMT.o
	${CC} ${O_OPTION} -o $@ $^

Xeon_dp_100_v2: Xeon_dp_100_v2.o ${DPFILES_2} SFMT.o
	${CC} ${O_OPTION} -o $@ $^

test_dp: test_dp.o ${DPFILES}
	${CC} ${O_OPTION} -o $@ $^

dragonPole.o : dragonPole.c
	${CC} -c ${C_OPTION} $^

dragonPole_2.o : dragonPole_2.c
	${CC} -c ${C_OPTION} ${VEC_REPO} $^

SFMT.o: SFMT.c
	${CC} -c ${SFMT_OPTION} $^

vec_test: vec_test.c
	 ${CC} -o vec_test ${VEC_REPO} ${C_OPTION} ${O_OPTION} vec_test.c

.c.o:
	${CC} ${C_OPTION} -c $^

clean:
	rm -f *.o
	rm -f ${ALL}
