.DEFAULT_GOAL := all
rootdir = $(realpath .)
include snlp.make.common

targetC := ${LIB_DIR}/libsnlp.${METHOD}.${LIB_SUFFIX}
targetF := ${LIB_DIR}/libsnlpF90.${METHOD}.${LIB_SUFFIX}

.PHONY: clean cleanexamples cleanall

all:: directories $(targetC) $(targetF) allexamples

$(targetC): directories $(OBJ_FILES) gitversion
	@echo "Linking "$(targetC)"..."
	@${LIBLDC} ${PETSCCFLAGS} ${LDFLAGS} $(OBJ_FILES) -o $@ $(LIBS)

$(targetF): directories $(F_OBJ_FILES) gitversion
	@echo "Linking "$(targetF)"..."
	@${LIBLDF} ${PETSCFFLAGS} ${LDFLAGS} $(F_OBJ_FILES) -I ${OBJ_DIR} -o $@ $(LIBS)

${OBJ_DIR}/%.$(METHOD).$(obj-suffix): ${rootdir}/src/%.c
	${CC} ${PETSCCFLAGS} -I $(INCLUDE_DIR) -g -fPIC -c -o $@ $<

${OBJ_DIR}/%.$(METHOD).$(obj-suffix): ${rootdir}/src/%.F90
	cd ${OBJ_DIR} && ${FC} ${PETSCFFLAGS} -g -fPIC -c -o $@ $< && cd ${rootdir}

${EXAMPLES_DIR}/%: $(targetC) ${EXAMPLES_DIR}/%.c
	@${CC} ${PETSCCFLAGS} -I $(INCLUDE_DIR) -L $(LIB_DIR) -lsnlp.${METHOD} -fPIC -o $@ $(word 2,$^)

${EXAMPLES_DIR}/%: $(targetC) $(targetF) ${EXAMPLES_DIR}/%.F90
	@cd ${EXAMPLES_DIR} && ${FLINKER} ${PETSCFFLAGS} -I$(OBJ_DIR) -L $(LIB_DIR) -lsnlp.${METHOD} -lsnlpF90.${METHOD} -fPIC -o $@ $(word 3,$^) && cd ${rootdir}

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

clean::
	@rm -f src/gitversion.c
	@rm -f $(allobj)
	@rm -f $(targetC)
	@rm -f $(targetF)
	@rm -f $(OBJ_FILES)
	@rm -f $(F_OBJ_FILES) 
	@rm -f $(EXAMPLE_EXECS)
	@rm -f $(F_EXAMPLE_EXECS)
	@rm -f $(modfiles)

testsnlp: testsnlpc testsnlpF90

testsnlpc: ${EXAMPLES_DIR}/example1
	@echo ;echo "Testing SNLP in C"
	@${EXAMPLES_DIR}/example1 > example1.${METHOD}.out # | grep -v -e ' \#' > example1.${METHOD}.out 2>&1;
	@if (${DIFF} -B ${EXAMPLES_DIR}/results/example1.out example1.${METHOD}.out) then echo "Passed";\
	else echo "Possible problem. Diffs above"; fi
	-@${RM} example1.${METHOD}.out 

testsnlpF90: ${EXAMPLES_DIR}/example1F90
	@echo ;echo "Testing SNLP in Fortran"
	@${EXAMPLES_DIR}/example1F90 > example1F90.${METHOD}.out # | grep -v -e ' \#' > example1.${METHOD}.out 2>&1;
	@if (${DIFF} -B ${EXAMPLES_DIR}/results/example1F90.out example1F90.${METHOD}.out) then echo "Passed";\
	else echo "Possible problem. Diffs above"; fi
	-@${RM} example1F90.${METHOD}.out 