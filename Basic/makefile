##############################################################################
# General Makefile for C ADT compilation
##############################################################################

# Variables
CC = gcc
CFlags = -std=c99 -Wall -g3
DEPFlags = -MM -MF $@
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
DEPS := $(subst $(SRC), $(DEPSDIR), $(SRCS))
DEPS := $(DEPS:.c=.d)

# Test program dependency
TESTDEPS := $(patsubst $(TEST)%, $(DEPSDIR)%, $(TESTS))
TESTDEPS := $(TESTDEPS:.c=.d)

##############################################################################
# Designate targets that do not correspond directly to files so that they are
# run every time they are called
##############################################################################
.PHONY: help clean %_test %_test_run %_main %_test_run_specific
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
	@echo "  %.o                  - compiles the individual data structure or"
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
	@rm -rf	$(BUILD)
	@rm -rf $(DEPSDIR)
	@rm -f *.d
	@echo "Done"

# Create temporary folders
$(DEPSDIR) $(BUILD): ; @mkdir -p $@

##############################################################################
# General Compilation Targets
##############################################################################

# Used to compile possible source codes used by the make target

# todo why get rebuilt every time?
# Since the object file does not exist in current directory but in build directory
# $(INC)/%.h: $(SRC)/%.c  | $(BUILD)
# 	@echo "Compiling object file for $@"
# 	@$(CC) -c -o $(BUILD)/$*.o -I $(INC) $(CFlags) $<
# 	@echo "Done"


# Generating dependency files for source code
$(DEPSDIR)/%.d: $(SRC)/%.c | $(DEPSDIR)
	@echo "Generating dependency into $@"
	@$(CC) -I $(INC) $(CFlags) $(DEPFlags) $<
	@echo "Done"

# Generating dependency files for test program
$(DEPSDIR)/%_test.d: $(TEST)/%_test.c | $(DEPSDIR)
	@echo "Generating test file dependency into $@"
	@$(CC) -I $(INC) $(CFlags) $(DEPFlags) $<
	@echo "Done"

%.o: | $(BUILD)
	@echo "Compiling object file for $<"
	@$(eval obj_tmp=$(patsubst %.h, %.o, $+))					# Convert the header names into the required object names
	@$(eval obj_tmp = $(notdir $(obj_tmp)))						# Remove the $(INC) dir 
	@$(eval obj_tmp = $(filter %.o, $(obj_tmp))) 				# Filter out the first source file needed
	@$(eval srcs_tmp = $(addprefix $(BUILD)/, $(obj_tmp)))	# Add build/ prefix to objects
	@$(CC) -c -o $(BUILD)/$@ -I $(INC) $(CFlags) $<		# Compile the object file for this source code
	@echo "Done"

# Link the compiled object code
%_test: %_test.o  |  $(BUILD)
	@echo $(notdir $(srcs_tmp))
	@$(MAKE) -f $(THIS_FILE) $(notdir $(srcs_tmp)) # invoke other target
	@echo "Compiling test program for $*"
	@$(CC) -o $(BUILD)/$*_test.out -I $(INC) $(CFlags) $(BUILD)/$< $(srcs_tmp)
	@echo "Done"

# Link the compiled object code
%_main: %_main.o | $(BUILD)
	@echo "Compiling $*_main.c"
	@$(CC) -o $(BUILD)/$*_main.out -I $(INC) $(CFlags) $(BUILD)/$< $(srcs_tmp)
	@echo "Done"

# todo
full_test: | $(BUILD)
	@echo "Compiling test programs for all source files in $(SRC)"
	@echo "ERROR: NOT IMPLEMENTED"
	@echo "Done"

##############################################################################
# General Test Targets
##############################################################################

# todo add checker for memory leaks
%_test_run: %_test
	@echo "Running test program for $*"
	@$(BUILD)/$*_test.out
	@echo
	@echo "Running memory check for test program"
	@echo
	@$(VALGRIND) $(VFLAGS) $(BUILD)/$*_test.out
	@echo "Done"

%_test_run_specific: %_test
	@echo "Running test program for $* with $(ARGS) as arguments"
	@$(BUILD)/$*_test.out $(ARGS)
	@echo "Done"

full_run: full_test
	@echo "Running test programs for all source files in $(SRC)"
	@echo "ERROR: NOT IMPLEMENTED"
	@echo "Done"

# Avoid include dependency file while cleaning them
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),help)
-include $(DEPS)
-include $(TESTDEPS)
endif
endif
