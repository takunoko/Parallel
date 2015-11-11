
CC=mpicc
ALL=myname

all: ${ALL}

myname: myname.o
	${CC} -o $@ $^

.c.o:
	${CC} -c $<
	
clean:
	rm -f *.o
	rm -f ${ALL}
