# MAKEFLAGS += --silent

COMPILER := g++

SRC := src
DEPS := -l glfw -I include -l dl -I $(SRC)
OBJECTS := $(shell find $(SRC)/ -type f -iname *.cpp -o -iname *.c)
HEADERS := $(shell find $(SRC)/ -type f -iname *.h)

OUT_FOLDER := out
OUT_PROGRAM := $(OUT_FOLDER)/a.out

all: $(OUT_PROGRAM)

$(OUT_PROGRAM): $(OUT_FOLDER) $(OBJECTS) $(HEADERS)
	$(COMPILER) $(DEPS) $(OBJECTS) -o $(OUT_FOLDER)/a.out

$(OUT_FOLDER):
	mkdir -p $@

run: $(OUT_PROGRAM)
	./$(OUT_PROGRAM)

clean:
	rm -rf $(OUT_FOLDER)

.PHONY: all clean run