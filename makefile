rootdir = $(realpath .)
include snlp.make.common

target := ${LIB_DIR}/libsnlp.${LIB_SUFFIX}

.PHONY: clean

all:: directories $(target) allexamples

allexamples:
	-@make --directory=$(EXAMPLES_DIR) all

$(target): $(OBJ_FILES) gitversion
	@echo "Linking "$(target)"..."
	@${LIBLD} $(OBJ_FILES) -o $@ $(LIBS)

${OBJ_DIR}/%.$(obj-suffix): src/%.c
	${CC} ${PETSCCFLAGS} -I $(INCLUDE_DIR) -fPIC -O3 -c -o $@ $<

gitversion:
	@python checkgit.py $(rootdir)
	@if [ -s src/gitversion.c  ]; then \
		${CC} -c src/gitversion.c -o ${OBJ_DIR}/gitversion.o ;\
	fi;


directories: ${LIB_DIR} ${OBJ_DIR}

${LIB_DIR}:
	${MKDIR_P} ${LIB_DIR}

${OBJ_DIR}:
	${MKDIR_P} ${OBJ_DIR}

clean::
	@rm -f src/gitversion.c
	@rm -f $(OBJ_FILES)
	@rm -f $(target)
	-@make --directory=$(EXAMPLES_DIR) clean