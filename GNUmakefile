# This software is released under the Boost Software
# License, version 1.0.  See LICENSE_1_0.txt or
# http://www.boost.org/LICENSE_1_0.txt Copyright Ken Smith
# kgsmith at gmail dot com, 2013.

# User configurable portion.
prefix := /usr/local
cpus := 4
opt := -Os -flto
#debug := -g -DDEBUG

# Implementation
prog ?= $(notdir $(CURDIR))
MAKEFLAGS := j$(cpus)
g := g++ $(opt) $(debug)
g += -std=c++11
g += -Wall -Werror -pedantic -Wno-unused-local-typedefs
g := $(strip $(g))
c := $(g) -c -MMD -I . -I ..
l := $(g)
s := $(wildcard *.cpp)
o := $(addprefix .,$(patsubst %.cpp,%.o,$(s)))
d := $(o:o=d)
p := $(filter-out .test-%.o,$(o))
t := $(patsubst %.o,%,$(filter .test-%.o,$(o)))
x := $(filter-out -Werror,$(c))
x := $(filter-out -Wall,$(x))
x := $(filter-out -pedantic,$(x))
pd := .postdepend.sh

.PRECIOUS\
:$(t)\
 $(o)

$(prog)\
:.main.o $(addsuffix .passed,$(t)) libtestables.a docs\
;$(l) -o $@ $< -L. -ltestables

libtestables.a\
:$(filter-out .main%,$(p))\
;ar r $@ $^

.test-%.o\
:test-%.cpp $(MAKEFILE_LIST) $(pd)\
;$(x) -o $@ $<\
;export $(subst -,_,$(subst .,_,$@))=$$?\
;if [[ "$$$(subst -,_,$(subst .,_,$@))" == "0" ]]\
;then ./$(pd) $(@:o=d)\
;fi\
;exit $$$(subst -,_,$(subst .,_,$@))

.%.o\
:%.cpp $(MAKEFILE_LIST)\
;$(c) -o $@ $<\
;export $(subst -,_,$(subst .,_,$@))=$$?\
;if [[ "$$$(subst -,_,$(subst .,_,$@))" == "0" ]]\
;then ./$(pd) $(@:o=d)\
;fi\
;exit $$$(subst -,_,$(subst .,_,$@))

.test-%.passed\
:.test-%\
;./$< --random --report_level=short --show_progress\
;export $(subst -,_,$(subst .,_,$@))=$$?\
;if [[ "$$$(subst -,_,$(subst .,_,$@))" == "0" ]]\
;then touch $@\
;fi\
;exit $$$(subst -,_,$(subst .,_,$@))

.test-%\
:.test-%.o libtestables.a\
;$(l) -o $@ $< -lboost_unit_test_framework -L . -ltestables

.PHONY\
:clean\
 install\
 docs

docs\
:.doxygen.out\

.doxygen.out\
:Doxyfile $(wildcard *.md) $(wildcard *.?pp)\
;doxygen > $@ 2>&1

install\
:$(prog)\
;cp $(prog) $(prefix)/bin

clean\
:\
;rm -Rf $(prog) .test-* .*.o .*.d .*.passed html latex .postdepend.sh libtestables.a .doxygen.out

.postdepend.sh\
:$(MAKEFILE_LIST)\
;echo -e\
 "#!/bin/sh\n"\
 "\n"\
 "cp \$$1 \$$1.p\n"\
 "cat \$$1"\
 "| sed"\
 "-e 's/\#.*//'"\
 "-e 's/^[^:]*: *//'" \
 "-e 's/ *\$$//'"\
 "-e '/^\$$/ d' "\
 "-e 's/$$/ :/'"\
 ">> \$$1.p\n"\
 "mv \$$1.p \$$1"\
> $@\
;chmod +x $@

-include $(d)

# vim:tw=60:
