##############################################################################
# General Makefile for C ADT compilation
##############################################################################

# Variables
CC = gcc
CFlags = -std=c99 -Wall -g3
VALGRIND = valgrind
VFLAGS = --tool=memcheck --leak-check=yes

# Directory
BUILDDIR := build
SOURCE := src
INCLUDE := inc
TEST := test


# Name of all source file
SOURCES := $(shell find $(SOURCE) -name '*.c')
# todo for loop to loop through?
# SOURCES := $(shell filename=$$(basename $(SOURCES)); echo "$${filename%.*}")
SOURCES := $(shell filename=$$(basename $(SOURCES)); echo $$filename)


##############################################################################
# Designate targets that do not correspond directly to files so that they are
# run every time they are called
##############################################################################
.PHONY: help clean
.PHONY: full_test full_run

##############################################################################
# Make the default target (the one called when no specific one is invoked) to
# output the proper usage of this makefile
##############################################################################
help:
	@echo "----------------------------------------------------------------"
	@echo "Administrative targets:"
	@echo "  help                 - print this help message"
	@echo "  clean                - removes the complied files"
	@echo
	@echo "Compilation targets:"
	@echo "  %_obj                - compiles the individual data structure or"
	@echo "                         algorithm with source file as of src/%.c"
	@echo
	@echo "  %_test               - compiles the test program (with name like"
	@echo "                         \"test/c_adt_list_test.c\") for the data structure"
	@echo "                         or algorithm with source file as of src/%.c"
	@echo "                         and test program in test/ folder"
	@echo
	@echo "  full_test            - complies all the data structure or algorithm"
	@echo "                         files under this directory"
	@echo
	@echo "  %_main               - compiles the custom main program (with name like"
	@echo "                         \"test/c_adt_list_main.c\") for the data structure"
	@echo "                         or algorithm with source file as of %.c"
	@echo "                         and main program in test/ folder"
	@echo
	@echo "                         Which is used for self testing prior to running"
	@echo "                         the overall test progam"
	@echo
	@echo "Test targets:"
	@echo "  %_test_run           - compiles and run the whole test program for the data"
	@echo "                         structure or algorithm with source file as of src/%.c"
	@echo
	@echo "  %_test_run_specific  - compiles and run the specific test program for the data"
	@echo "                         structure or algorithm with source file as of src/%.c"
	@echo "                         The specific test is specified via a \"ARGS\"" 
	@echo "                         when using the make command"
	@echo
	@echo "                         Example: \`make c_adt_list_test_run_specific ARGS=\"test1\"\`"
	@echo "                         Which the string \"test1\" will be passedd to the main function"
	@echo
	@echo "  full_run             - compiles and run the test program for all data "
	@echo "                         structure or algorithm under this directory"
	@echo "----------------------------------------------------------------"

##############################################################################
# Administrative Targets
##############################################################################
clean:
	@echo "Removing all complied files"
	@rm -rf test/*.tmp
	@rm -f	$(BUILDDIR)/*.out $(BUILDDIR)/*.a $(BUILDDIR)/*.o
	@echo "Done\n\n"

##############################################################################
# General Compilation Targets
##############################################################################

# Complie the data structure or algorithm itself only
%_obj: $(SOURCE)/%.c
	@echo "Compiling object file for $*"
	@$(CC) -c -o $(BUILDDIR)/$*.o -I $(INCLUDE) $(CFlags) $(SOURCE)/$*.c 
	@echo "Done"

%_test: $(TEST)/%_test.c $(SOURCE)/%.c
	@echo "Compiling test program for $*"
	@$(CC) -o $(BUILDDIR)/$*_test.out -I $(INCLUDE) $(CFlags) $(TEST)/$*_test.c $(SOURCE)/$*.c
	@echo "Done"

# todo
full_test:
	@echo "Compiling test programs for all source files in $(SOURCE)"
	@echo "ERROR: NOT IMPLEMENTED"
	@echo "Done"

%_main: $(TEST)/%_main.c $(SOURCE)/%.c
	@echo "Compiling $*_main.c"
	@$(CC) -o $(BUILDDIR)/$*_main.out -I $(INCLUDE) $(CFlags) $(TEST)/$*_main.c $(SOURCE)/$*.c
	@echo "Done"

##############################################################################
# General Test Targets
##############################################################################

# todo add checker for memory leaks
%_test_run: %_test
	@echo "Running test program for $*"
	@$(BUILDDIR)/$*_test.out
	@echo
	@echo "Running memory check for test program"
	@echo
	@$(VALGRIND) $(VFLAGS) $(BUILDDIR)/$*_test.out
	@echo "Done"

%_test_run_specific: %_test
	@echo "Running test program for $* with $(ARGS) as arguments"
	@$(BUILDDIR)/$*_test.out $(ARGS)
	@echo "Done"

full_run: full_test
	@echo "Running test programs for all source files in $(SOURCE)"
	@echo "ERROR: NOT IMPLEMENTED"
	@echo "Done"
