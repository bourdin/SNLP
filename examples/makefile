all: example1 example2 example2ctx

.c.o:
	${CC} -c ${CFLAGS} -I ../src -o $@ $<
	

example1: example1.o ../src/libsnlp.dylib
	-${CC} ${CFLAGS} -o example1 -I ../src -L ../src -lsnlp example1.o

example2: example2.o ../src/libsnlp.dylib
	-${CC} ${CFLAGS} -o example2 -I ../src -L ../src -lsnlp example2.o

example2ctx: example2ctx.o ../src/libsnlp.dylib
	-${CC} ${CFLAGS} -o example2ctx -I ../src -L ../src -lsnlp example2ctx.o

clean: 
	-@rm -f *.o
	-@rm example1 example2 example2ctx