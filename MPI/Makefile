# CC=gcc
# CC=/opt/intel/bin/icc
CC=mpiiscc
ALL=mpi_test.mic

# OMP_OPTION=-openmp
OPT_OPTION=-O3
LOPTION=
PHI_OPTION=-mmic
PHI_L_OPTION=-Xlinker -rpath -Xlinker /usr/jlocal/mic/lib
DEBUG_OPTION=

C_OPTION=${OPT_OPTION} ${PHI_OPTION} ${LOPTION} ${DEBUG_OPTION}
O_OPTION=${LOPTION} ${PHI_L_OPTION} ${PHI_OPTION} ${OMP_OPTION} ${DEBUG_OPTION}

all: ${ALL}

mpi_test.mic: mpi_test.o
	${CC} ${O_OPTION} -o $@ $^

.c.o:
	${CC} -c ${C_OPTION} $^
	
clean:
	rm *.o
	rm ${ALL}

# use Xeon Phi
# on nlm server
# srun -n 80 -p mic ./mpi_test.mic
# -n option less than about 80
