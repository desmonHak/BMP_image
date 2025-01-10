CC 			  = gcc
ARR			  = ar

VESRION_C     = 99

GLOBAL_CFLAGS = -std=c$(VESRION_C) $(INCLUDE_FLAGS) -masm=intel \
				-D_ExceptionHandler -fdiagnostics-color=always 

PATH_EXAMPLES = ./examples
PATH_OUT      = ./out

INCLUDE_FLAGS = -I.
CFLAGS 		  =  $(GLOBAL_CFLAGS) -O3 -Wno-unused-parameter \
				-Wno-implicit-fallthrough -Wno-type-limits  \
				-Wno-unused-variable -Wno-pointer-sign
CFLAGS_DEBUG  =  $(GLOBAL_CFLAGS) -ggdb -fno-asynchronous-unwind-tables  	      \
				-Wall -Wextra 		 -pipe -O0 -D DEBUG_ENABLE      	          \
				-fstack-protector-strong -Wpedantic -fno-omit-frame-pointer       \
				-fno-inline -fno-optimize-sibling-calls -fdiagnostics-show-option
ARR_FLAGS     = -rc

OBJECTS = 	BMP_image.o