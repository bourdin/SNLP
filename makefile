.DEFAULT_GOAL := all
rootdir = $(realpath .)
include snlp.make.common

targetC := ${LIB_DIR}/libsnlp.${LIB_SUFFIX}
targetF := ${LIB_DIR}/libsnlpF90.${LIB_SUFFIX}

.PHONY: clean cleanexamples cleanall

all:: directories $(targetC) $(targetF) allexamples

$(targetC): $(OBJ_FILES) gitversion
	@echo "Linking "$(targetC)"..."
	@${LIBLD} $(OBJ_FILES) -o $@ $(LIBS)

$(targetF): $(F_OBJ_FILES) gitversion
	@echo "Linking "$(targetF)"..."
	@${LIBLD} $(F_OBJ_FILES) -I ${OBJ_DIR} -o $@ $(LIBS)

${OBJ_DIR}/%.$(obj-suffix): ${rootdir}/src/%.c
	${CC} ${PETSCCFLAGS} -I $(INCLUDE_DIR) -fPIC -O3 -c -o $@ $<

${OBJ_DIR}/%.$(obj-suffix): ${rootdir}/src/%.F90
	cd ${OBJ_DIR} && ${FC} ${PETSCFFLAGS} -fPIC -O3 -c -o $@ $< && cd ${rootdir}

${EXAMPLES_DIR}/%.out: ${EXAMPLES_DIR}/%.c
	${CC} ${PETSCCFLAGS} -I $(INCLUDE_DIR) -L $(LIB_DIR) -lsnlp -fPIC -O3 -o $@ $<

${EXAMPLES_DIR}/%.out: ${EXAMPLES_DIR}/%.F90
	cd ${EXAMPLES_DIR}
	${FC} ${PETSCFFLAGS} -I $(OBJ_DIR) -L $(LIB_DIR) -lsnlp -lsnlpF90 -fPIC -O3 -o $@ $<
	cd ${rootdir}

gitversion:
	@python checkgit.py $(rootdir)
	@if [ -s src/gitversion.c  ]; then \
		${CC} -c src/gitversion.c -o ${OBJ_DIR}/gitversion.o ;\
	fi;

allexamples: cexamples f90examples $(targetC) $(targetF)

cexamples: $(EXAMPLE_EXECS)

f90examples: $(F_EXAMPLE_EXECS)

directories: ${LIB_DIR} ${OBJ_DIR}

${LIB_DIR}:
	${MKDIR_P} ${LIB_DIR}

${OBJ_DIR}:
	${MKDIR_P} ${OBJ_DIR}

cleanall: clean cleanexamples
	
clean::
	@rm -f src/gitversion.c
	@rm -f $(OBJ_FILES)
	@rm -f $(F_OBJ_FILES)
	@rm -f $(targetC)
	@rm -f $(targetF)
	@rm -f $(modfiles)

cleanfortran:
	@rm -f $(F_OBJ_FILES)
	@rm -f $(targetF)

cleanc:
	@rm -f src/gitversion.c
	@rm -f $(OBJ_FILES)
	@rm -f $(targetC)

cleanexamples:
	@rm -f $(EXAMPLE_EXECS)
	@rm -f $(F_EXAMPLE_EXECS)

cleanall: clean cleanexamples

debug:
	-@echo cc is ${CC}
	-@echo FC is ${FC}