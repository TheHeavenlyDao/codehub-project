##################################################################################################################
# Author(s):	Squidy (https://github.com/gsemac)
# Description:	Makefile for codehub-project. Comments included for educational purposes.
##################################################################################################################

# The compiler we're going to use.
CC = g++
# The flags we're going to pass to the compiler.
CFLAGS = -std=c++11 -Wall
# Our linker flags.
LNFLAGS = -Wl,-rpath=$(LIBDIR) -L $(LIBDIR) -lallegro -lallegro_image
# The include paths we want to pass to the compiler. Use the -I flag for each path.
INCLUDE = -I /usr/local/include/ -I $(INCDIR)

# The path to our library directory. 
LIBDIR = /usr/local/lib
# The path to our header files.
INCDIR = include
# The path to our source files.
SRCDIR = src
# The path to the resulting executable(s).
BINDIR = bin
# The path containing our object files. Emptied on clean.
OBJDIR = build
# The name of the output executable.
EXECUTABLE = codehub-project

# A list of all source files (automatically generated).
SOURCES = $(shell find $(SRCDIR) -name '*.cc')
# A list of all subdirectories under the source directory (automatically generated).
SRCDIRS = $(shell find $(SRCDIR) -mindepth 2 -name '*.cc' -printf '%h ' | sed 's/$(SRCDIR)\///g')
# A list of all object files (automatically generated).
OBJECTS = $(patsubst $(SRCDIR)/%.cc, $(OBJDIR)/%.o, $(SOURCES))

# This target is for compiling everything. 
# It's also the default target when we call make without specifying one.
all: $(SOURCES) $(EXECUTABLE)

# This target is for compiling the main executable.
$(EXECUTABLE): build-dirs $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(BINDIR)/$@ $(OBJECTS) $(LNFLAGS)

# This target is a generic target for creating object files from source files.
$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# This target cleans up our object files and binaries.
clean:
	rm -rf $(OBJDIR)/* $(BINDIR)/*

# Creates the directory structure for the project.
build-dirs:
	@$(call builddirs)

# Function for generating the directory structure for the project.
define builddirs
	mkdir -p $(INCDIR)
	mkdir -p $(SRCDIR)
	mkdir -p $(BINDIR)
	mkdir -p $(OBJDIR)
	for dir in $(SRCDIRS); \
	do \
		mkdir -p $(OBJDIR)/$$dir; \
	done
endef
