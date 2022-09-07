###########################################################################
## Makefile generated for component 'generate_orders'. 
## 
## Makefile     : generate_orders_rtw.mk
## Generated on : Mon Aug 29 14:23:17 2022
## Final product: ./generate_orders.a
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# MODELLIB                Static library target

PRODUCT_NAME              = generate_orders
MAKEFILE                  = generate_orders_rtw.mk
MATLAB_ROOT               = /home/arjun/MATLAB/R2021b
MATLAB_BIN                = /home/arjun/MATLAB/R2021b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/glnxa64
START_DIR                 = /home/arjun/Documents/MATLAB/Examples/R2021b/robotics/VerticalRobotSimulation
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = generate_orders.a

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU gcc/g++ | gmake (64-bit Linux)
# Supported Version(s):    
# ToolchainInfo Version:   2021b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS         = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX     = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS     = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC = gcc

# Linker: GNU Linker
LD = g++

# C++ Compiler: GNU C++ Compiler
CPP = g++

# C++ Linker: GNU C++ Linker
CPP_LD = g++

# Archiver: GNU Archiver
AR = ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/glnxa64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(C_STANDARD_OPTS) -fPIC \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -fPIC \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPP_LDFLAGS          =
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./generate_orders.a
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/codegen/lib/generate_orders -I$(START_DIR) -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=generate_orders

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/generate_orders/generate_orders_data.cpp $(START_DIR)/codegen/lib/generate_orders/generate_orders_initialize.cpp $(START_DIR)/codegen/lib/generate_orders/generate_orders_terminate.cpp $(START_DIR)/codegen/lib/generate_orders/generate_orders.cpp $(START_DIR)/codegen/lib/generate_orders/randn.cpp $(START_DIR)/codegen/lib/generate_orders/sum.cpp $(START_DIR)/codegen/lib/generate_orders/rand.cpp $(START_DIR)/codegen/lib/generate_orders/eml_rand_mt19937ar_stateful.cpp $(START_DIR)/codegen/lib/generate_orders/eml_rand_mt19937ar.cpp $(START_DIR)/codegen/lib/generate_orders/sort.cpp $(START_DIR)/codegen/lib/generate_orders/sortIdx.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = generate_orders_data.o generate_orders_initialize.o generate_orders_terminate.o generate_orders.o randn.o sum.o rand.o eml_rand_mt19937ar_stateful.o eml_rand_mt19937ar.o sort.o sortIdx.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  -lm -lstdc++

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) $(OBJS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/generate_orders/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/generate_orders/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


generate_orders_data.o : $(START_DIR)/codegen/lib/generate_orders/generate_orders_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


generate_orders_initialize.o : $(START_DIR)/codegen/lib/generate_orders/generate_orders_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


generate_orders_terminate.o : $(START_DIR)/codegen/lib/generate_orders/generate_orders_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


generate_orders.o : $(START_DIR)/codegen/lib/generate_orders/generate_orders.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


randn.o : $(START_DIR)/codegen/lib/generate_orders/randn.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sum.o : $(START_DIR)/codegen/lib/generate_orders/sum.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rand.o : $(START_DIR)/codegen/lib/generate_orders/rand.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


eml_rand_mt19937ar_stateful.o : $(START_DIR)/codegen/lib/generate_orders/eml_rand_mt19937ar_stateful.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


eml_rand_mt19937ar.o : $(START_DIR)/codegen/lib/generate_orders/eml_rand_mt19937ar.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sort.o : $(START_DIR)/codegen/lib/generate_orders/sort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortIdx.o : $(START_DIR)/codegen/lib/generate_orders/sortIdx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


