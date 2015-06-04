all: src/libsnlp.dylib allexamples

.c.o:
	${CC} -c ${CFLAGS} -o $@ $<
	
src/libsnlp.dylib:
	-@make -C src

allexamples:
	-@make -C examples

clean:
	-@make -C src clean
	-@make -C examples clean