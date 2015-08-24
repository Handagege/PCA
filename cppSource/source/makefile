DEBUG = 0
CXX = g++

ifneq ($(DEBUG),1)
	CFLAGS = -Wall -W -fpic
else
	CFLAGS = -g -Wall -W -fpic
endif

LIB_ROOT_PATH = ..
LIB_OUT_PATH = $(LIB_ROOT_PATH)/lib/
INC_OUT_PATH = $(LIB_ROOT_PATH)/include/
LIB = -lFengyoungAPI
LIB += -ljson_linux-gcc-4.4.7_libmt

OBJS = uFeatTemplateParser.o
OBJS += arrayStder.o
OBJS += arrayFilter.o
OBJS += arrayFixer.o
OBJS += getStdArrayMain.o
OBJS += arrayBalancer.o

EXES = getStdArray

.PHONY: all

all: $(EXES)

getStdArray: $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^ -L$(LIB_OUT_PATH) $(LIB)

.cpp.o:
	$(CXX) $(CFLAGS) -c $< -I$(INC_OUT_PATH) -I.

.PHONY: clean

clean:
	rm $(OBJS)
	rm $(EXES)
