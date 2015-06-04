all: libsnlp.dylib
OBJS=cholesky.o l1sqp.o lu.o nlp.o qp.o runtime.o snlp.o equations.o linfsqp.o matrix.o nlpsolve.o qr.o scqp.o vector.o

libsnlp.dylib: ${OBJS}
	-@${CC} -o libsnlp.dylib -dynamiclib ${OBJS}

clean:
	-@rm -f *.o
	-@rm -f libsnlp.dylib