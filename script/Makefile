ifeq ($(OS), Windows_NT)
	EXECUTABLE=LO21.exe
else
	EXECUTABLE=LO21
endif

FLAGS=-lm -W -Wall -Wextra -O3
SRC_DIR=../src/
INCLUDE_DIR=../include/
BUILD_DIR=../build/

$(EXECUTABLE): $(SRC_DIR)*.c $(INCLUDE_DIR)*.h
	gcc $(SRC_DIR)*.c -o $(BUILD_DIR)$(EXECUTABLE) $(FLAGS)

run: $(EXECUTABLE)
	$(BUILD_DIR)$(EXECUTABLE)

create_build: clean
	mkdir -p $(BUILD_DIR)

clean:
	rm -r $(BUILD_DIR)