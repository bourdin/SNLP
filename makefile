.DEFAULT_GOAL := all
rootdir = $(realpath .)
include snlp.make.common

target := ${LIB_DIR}/libsnlp.${LIB_SUFFIX}

.PHONY: clean cleanexamples cleanall

all:: directories $(target) allexamples

$(target): $(OBJ_FILES) gitversion
	@echo "Linking "$(target)"..."
	@${LIBLD} $(OBJ_FILES) -o $@ $(LIBS)

${OBJ_DIR}/%.$(obj-suffix): src/%.c
	${CC} ${PETSCCFLAGS} -I $(INCLUDE_DIR) -fPIC -O3 -c -o $@ $<

${EXAMPLES_DIR}/%.out: ${EXAMPLES_DIR}/%.c
	${CC} ${PETSCCFLAGS} -I $(INCLUDE_DIR) -L $(LIB_DIR) -lsnlp -fPIC -O3 -o $@ $<

gitversion:
	@python checkgit.py $(rootdir)
	@if [ -s src/gitversion.c  ]; then \
		${CC} -c src/gitversion.c -o ${OBJ_DIR}/gitversion.o ;\
	fi;

allexamples: $(EXAMPLE_EXECS) $(target)

directories: ${LIB_DIR} ${OBJ_DIR}

${LIB_DIR}:
	${MKDIR_P} ${LIB_DIR}

${OBJ_DIR}:
	${MKDIR_P} ${OBJ_DIR}

clean::
	@rm -f src/gitversion.c
	@rm -f $(OBJ_FILES)
	@rm -f $(target)

cleanexamples:
	@rm -f $(EXAMPLE_EXECS)

cleanall: clean cleanexamples