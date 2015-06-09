rootdir = $(realpath ..)
include $(rootdir)/snlp.make.common

all: example1 example2 example2ctx

.c.o:
	${CC} -c ${CFLAGS} -I $(INCLUDE_DIR) -o $@ $<
	

example1: example1.o $(LIB_DIR)/libsnlp.${LIB_SUFFIX}
	-${CC} ${CFLAGS} -o example1 -I $(INCLUDE_DIR)  -L $(LIB_DIR)  -lsnlp example1.o

example2: example2.o $(LIB_DIR)/libsnlp.${LIB_SUFFIX}
	-${CC} ${CFLAGS} -o example2 -I $(INCLUDE_DIR)  -L $(LIB_DIR) -lsnlp example2.o

example2ctx: example2ctx.o $(LIB_DIR)/libsnlp.${LIB_SUFFIX}
	-${CC} ${CFLAGS} -o example2ctx -I $(INCLUDE_DIR) -L $(LIB_DIR) -lsnlp example2ctx.o

clean::
	-@rm -f *.o
	-@rm example1 example2 example2ctx