##############################################################################
# General Makefile for C ADT compilation
##############################################################################

# Variables
CC = gcc
CFlags = -std=c99 -Wall -g3
DEPFlags = -MP -MM -MF $@ -MT '$(BUILD)/$(strip $(patsubst %.d, %.o, $(notdir $@)))'
VALGRIND = valgrind
VFLAGS = --tool=memcheck --leak-check=yes

# Directory
BUILD := build
SRC := src
INC := inc
TEST := test
THIS_FILE := $(lastword $(MAKEFILE_LIST))

# Name of all source file
SRCS := $(wildcard $(SRC)/*.c)
TESTS := $(wildcard $(TEST)/*.c)

# Dependency directory and files
DEPSDIR := .deps

# Source code dependency
DEPS := $(patsubst $(SRC)%, $(DEPSDIR)%, $(SRCS))
DEPS := $(DEPS:.c=.d)

# Test program dependency
TESTDEPS := $(patsubst $(TEST)%, $(DEPSDIR)%, $(TESTS))
TESTDEPS := $(TESTDEPS:.c=.d)

# Object file list
OBJS := $(patsubst $(SRC)%, $(BUILD)%, $(SRCS))
OBJS := $(OBJS:.c=.o)

# Designate targets that do not correspond directly to files so that they are
# run every time they are called
.PHONY: help clean %_test %_test_run %_main %_test_run_specific veryclean
.PHONY: full_test full_run

# Avoid deleting .out file due to interrupted makefile
.PRECIOUS: $(BUILD)/%.out

# Enable wildcard matching
.SECONDEXPANSION: $(DEPSDIR)/%.d

##############################################################################
# Make the default target (the one called when no specific one is invoked) to
# output the proper usage of this makefile
##############################################################################
help:
	@echo "----------------------------------------------------------------"
	@echo "Administrative targets:"
	@echo "  help                 - print this help message"
	@echo "  clean                - removes the complied files"
	@echo "  veryclean            - removes the complied files along with dependency files"
	@echo
	@echo "Compilation targets:"
	@echo "  build/%.o            - compiles the individual data structure or"
	@echo "                         algorithm with source file as of src/%.c"
	@echo "  build/%.out          - compiles and link the dependency to form executable"
	@echo "                         Exclude files are specified via a \"EXCLUDE\"" 
	@echo "                         when using the make command"
	@echo
	@echo "                         Example: \`make build/c_adt_stack_arr_test.out EXCLUDE=\"build/c_adt_stack_list.o\"\`"
	@echo "                         Which the string \"test1\" will be passedd to the main function"
	@echo
	@echo
	@echo "  %_test               - compiles the test program (with name like"
	@echo "                         \"test/c_adt_list_test.c\") for the data structure"
	@echo "                         or algorithm with source file as of src/%.c"
	@echo "                         and test program in test/ folder"
	@echo
	@echo "                         Same argument in build/%.out also applies here"
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
	@echo "----------------------------------------------------------------"
	@echo "Removing temporary test output files"
	@echo
	@rm -rf test/*.tmp
	@echo "Done"
	@echo "----------------------------------------------------------------"
	@echo "Removing all complied files and build directory"
	@echo
	@rm -rf	$(BUILD)
	@echo "Done"
	@echo "----------------------------------------------------------------"

veryclean: clean
	@echo "----------------------------------------------------------------"
	@echo "Removing all dependency files and .deps directory"
	@echo
	@rm -rf $(DEPSDIR)
	@echo "Done"
	@echo "----------------------------------------------------------------"


# Create temporary folders
$(DEPSDIR) $(BUILD): ; @mkdir -p $@

##############################################################################
# General Compilation Targets
##############################################################################

# Used to compile possible source codes used by the make target

# Generating dependency files for source code
$(DEPSDIR)/%.d: $$(wildcard $(SRC)/%.c) $$(wildcard $(TEST)/%.c) | $(DEPSDIR)
	@echo "----------------------------------------------------------------"
	@echo "Generating dependency into $@"
	@echo
	@$(CC) -I $(INC) $(CFlags) $(DEPFlags) $<
	@echo "Done"
	@echo "----------------------------------------------------------------"

# Build object files
$(BUILD)/%.o: | $(BUILD)
	@echo "----------------------------------------------------------------"
	@echo "Compiling object file for $@"
	@echo
	@$(CC) -c -o $@ -I $(INC) $(CFlags) $<
	@echo "Done"
	@echo "----------------------------------------------------------------"

# Link the compiled object code to build executable
$(BUILD)/%.out: $(BUILD)/%.o $(OBJS)| $(BUILD)
	@echo "----------------------------------------------------------------"
	@echo "Compiling test program for $*"
	@echo Exclude: $(EXCLUDE)
	@$(CC) -o $@ -I $(INC) $(CFlags) $< $(filter-out $(EXCLUDE), $(OBJS))
	@echo "Done"
	@echo "----------------------------------------------------------------"

# todo
full_test: | $(BUILD)
	@echo "----------------------------------------------------------------"
	@echo "Compiling test programs for all source files in $(SRC)"
	@echo "ERROR: NOT IMPLEMENTED"
	@echo "Done"
	@echo "----------------------------------------------------------------"

##############################################################################
# General Test Targets
##############################################################################

# Compile only target
%_test:	$(BUILD)/%_test.out ;

%_main:	$(BUILD)/%_main.out ;

%_test_run: $(BUILD)/%_test.out
	@echo "----------------------------------------------------------------"
	@echo "Running test program for $*"
	@$< $(ARGS)
	@echo
ifeq ($(ARGS), "")
	@echo "Running memory check for test program"
	@echo
	@$(VALGRIND) $(VFLAGS) $(BUILD)/$*_test.out
endif
	@echo "Done"
	@echo "----------------------------------------------------------------"

full_run: full_test
	@echo "----------------------------------------------------------------"
	@echo "Running test programs for all source files in $(SRC)"
	@echo "ERROR: NOT IMPLEMENTED"
	@echo "Done"
	@echo "----------------------------------------------------------------"

# Avoid include dependency file while cleaning them
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),help)
ifneq ($(MAKECMDGOALS),veryclean)
-include $(DEPS)
-include $(TESTDEPS)
endif
endif
endif
