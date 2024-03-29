.DEFAULT_GOAL := targets
rootdir = $(realpath .)
include snlp.make.common

targetC := ${LIB_DIR}/libsnlp.${LIB_SUFFIX}
targetF := ${LIB_DIR}/libsnlpF90.${LIB_SUFFIX}

.PHONY: clean

all:: directories gitversion $(targetC) $(targetF) allexamples

targets: $(targetC) $(targetF)

$(targetC): directories $(OBJ_FILES)
	@echo "Linking "$(targetC)"..."
	-@${LIBLDC} ${SNLP_CC_FLAGS} $(LIBS) ${LDFLAGS} $(OBJ_FILES) -o $@ 

$(targetF): directories $(F_OBJ_FILES)
	@echo "Linking "$(targetF)"..."
	-@${LIBLDF} ${SNLP_FC_FLAGS} ${LDFLAGS} $(F_OBJ_FILES) -I ${OBJ_DIR} -o $@ $(LIBS)

${OBJ_DIR}/%snlpF90.$(obj-suffix): ${rootdir}/src/%.c
	-@${CC} ${SNLP_CC_FLAGS} -I $(INCLUDE_DIR) -g -fPIC -c -o $@ $<

${OBJ_DIR}/%snlpF90.$(obj-suffix): ${rootdir}/src/%.F90
	-@cd ${OBJ_DIR} && ${FC} ${SNLP_FC_FLAGS} -g -fPIC -c -o $@ $< && cd ${rootdir}

${EXAMPLES_DIR}/%: $(targetC) ${EXAMPLES_DIR}/%.c
	-@${CC} ${SNLP_CC_FLAGS} -I $(INCLUDE_DIR) -L $(LIB_DIR) -lsnlp -fPIC -Wl,-rpath,${LIB_DIR} -o $@ $(word 2,$^) 

${EXAMPLES_DIR}/%: $(targetC) $(targetF) ${EXAMPLES_DIR}/%.F90
	cd ${EXAMPLES_DIR} && ${FLINKER} ${SNLP_FC_FLAGS} -I$(OBJ_DIR) -L $(LIB_DIR) -lsnlp -lsnlpF90 -fPIC -Wl,-rpath,${LIB_DIR} -o $@ $(word 3,$^) && cd ${rootdir}

gitversion:
	@python3 checkgit.py $(rootdir)
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

install:
	@echo "installing the libraries, objs, include files"
	${MKDIR_P} ${SNLP_DIR}/lib
	${MKDIR_P} ${SNLP_DIR}/include
	cp ${targetC} ${SNLP_DIR}/lib
	cp ${targetF} ${SNLP_DIR}/lib
	cp ${main_modfiles} ${SNLP_DIR}/include
	cp ${includefiles} ${SNLP_DIR}/include

testsnlpc: ${EXAMPLES_DIR}/example1
	@echo ;echo "Testing SNLP in C"
	@${EXAMPLES_DIR}/example1 > example1.out # | grep -v -e ' \#' > example1.out 2>&1;
	@if (${DIFF} -B ${EXAMPLES_DIR}/results/example1.out example1.out) then echo "Passed";\
	else echo "Possible problem. Diffs above"; fi
	-@${RM} example1.out 

testsnlpF90: ${EXAMPLES_DIR}/example1F90
	@echo ;echo "Testing SNLP in Fortran"
	@${EXAMPLES_DIR}/example1F90 > example1F90.out # | grep -v -e ' \#' > example1.out 2>&1;
	@if (${DIFF} -B ${EXAMPLES_DIR}/results/example1F90.out example1F90.out) then echo "Passed";\
	else echo "Possible problem. Diffs above"; fi
	-@${RM} example1F90.out 

debug:
	@echo CC:      ${CC}
	@echo FC:      ${FC}
	@echo CLINKER: ${CLINKER}
	@echo FLINKER: ${FLINKER}
	@echo targetC: ${targetC}
	@echo targetF: ${targetF}
	@echo LD_SHARED_C: ${LD_SHARED_C}
	@echo LD_SHARED_F: ${LD_SHARED_F}
	@echo FC_FLAGS: ${FC_FLAGS}
	@echo CC_FLAGS: ${CC_FLAGS}
	@echo SNLP_FC_FLAGS: ${SNLP_FC_FLAGS}
	@echo SNLP_CC_FLAGS: ${SNLP_CC_FLAGS}
	@echo PETSCCFLAGS: ${PETSCCFLAGS}
	@echo LIBLDC: ${LIBLDC}
