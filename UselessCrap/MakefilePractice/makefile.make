# Makefiles should be named either Makefile, or makefile, as these are automatically checked by the make utility for making.
#
# ALL makefile commands are structured as:
#
# target: Prerequisites
# 	  command
# 
# target - name of file or action to carry out
#
# prerequisite - input file(s) to be compiled. Each time make is run these are checked against the object file to see if they have been updated or not, saving compiling time.
#
# command (NEEDS a tab beforehand) - action that make carries out (e.g. cc tocompile)

#At the start of your makefile, the first target should refer to the name of the excecutable file genarated. This is also the default command run when make is used on the 

include makefile.* #other makefiles can be included and referenced using the include command. The formatting of the names uses standard bash file name patterns and therefore * and shell variables can be used. This can be useful when developing multiple programs that use the same variables or c files.

#In these situations, one may want a certain target within the includes to be accessed differently. These can be overrided using the following:

graphics.o:
	frobnicate > graphics.o

%: force
	@$(MAKE) -f makefile.make$@
force: ;#force prerequisits will always be run. As the current file (makefile.make) contains force, to avoid an infinite loop, force is given no commands.


CC?=gcc #This specifies the default compiler 

totalfiles = main.o graphics.o physics.o sound.o #If you don't want to have to write everything out multiple times, use variables as so:

MakefileExample: $(totalfiles)
	cc -o MakefileExample $(totalfiles)

#Sometimes you may have a large quantity of files that only require a single prerequisit. Here, use the objects as the targets instead as so:

$(totalfiles): defs.h

main.o: main.c main.h
	cc -c main.c
.PHONY: clean #By default, the make utility will look for the file specified by the target to check if the file is up to date or not. However, in this case, the clean command doesn't have an associated file with it. If someone were to make a clean file in the same directory, make would assume that, since there are no prerequisits to check, it is up to date and not carry out the command, making it useless.
clean:
	rm MakefileExample $(objects) #removes the excecutable and all compiled files

#Makefile will automagically compile the .c file of its target's namesake if no command is specified. This can neaten things up like so:

graphics.o: graphics.h dx11.h # This will compile graphics.c into graphics.o with the default c compiler


