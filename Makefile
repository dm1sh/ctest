CC=gcc

CFLAGS=-Wall -pedantic -std=c11 -fPIC
LDFLAGS=
DFLAGS=-gdb3

NAMES=ctest funcs

set_values = $(addprefix $(1),$(addsuffix $(2),$(3)))

sourcefy = $(call set_values,./src/,.c,$(1))
objectify = $(call set_values,./obj/,.o,$(1))

SOURCES=$(foreach N,$(NAMES),$(call sourcefy,$(N)))
OBJECTS=$(foreach N,$(NAMES),$(call objectify,$(N)))

all: libctest

libctest: $(OBJECTS) check-env
	gcc -shared -Wl,-soname,$(addsuffix .so.$(CT_VERSION),$@) -o $(addsuffix .so.$(CT_VERSION).0,$@) $(OBJECTS)


$(OBJECTS):%.o: $($(call sourcefy $@)) objdir
	$(CC) $(CFLAGS) -c -o $@ $(call sourcefy,$(subst .o,,$(@F)))

objdir:
	mkdir -p obj

install: check-env
	cp libctest.so.$(CT_VERSION).0 /usr/local/lib/
	ln -sf /usr/local/lib/libctest.so.$(CT_VERSION).0 /usr/local/lib/libctest.so.$(CT_VERSION)
	ln -sf /usr/local/lib/libctest.so.$(CT_VERSION).0 /usr/local/lib/libctest.so
	mkdir -p /usr/local/include/ctest
	cp $(wildcard ./include/*) /usr/local/include/ctest

uninstall: check-env
	rm -f $(wildcard /usr/local/lib/libctest.so*)
	rm -rf $(wildcard /usr/local/include/ctest/*)

check-env:
ifndef CT_VERSION
	$(error CT_VERSION is undefined)
endif

.PHONY:
	clean
clean: 
	rm -rf obj
	rm $(wildcard libctest.so*)