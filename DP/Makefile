
# macの場合はbrewで入れた最新版のgccを使うとopenmpが使える
# 標準のgccでは-fopenmpをつけても使えない
CC=/usr/local/bin/gcc-5

# 学校環境での利用 icc
# CC=/opt/intel/bin/icc
ALL=Xeon_dp Xeon_dp_100_v0 Xeon_dp_100_v1 test_dp
DPFILES=dragonPole.o

# OMP_OPTION=-openmp
OMP_OPTION=-fopenmp
OPT_OPTION=-O3
LOPTION=
# PHI_OPTION=-mmic
# PHI_L_OPTION=-Xlinker -rpath -Xlinker /usr/jlocal/mic/lib
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

test_dp: test_dp.o ${DPFILES}
	${CC} ${O_OPTION} -o $@ $^

dragonPole.o : dragonPole.c
	${CC} -c ${C_OPTION} $^

SFMT.o: SFMT.c
	${CC} -c ${SFMT_OPTION} $^

.c.o:
	${CC} ${C_OPTION} -c $^

clean:
	rm *.o
	rm ${ALL}
