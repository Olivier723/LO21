ifeq ($(OS), Windows_NT)
	EXECUTABLE=LO21.exe
else
	EXECUTABLE=LO21
endif

$(EXECUTABLE): src/*.c include/*.h
	gcc src/*.c -o $(EXECUTABLE) -lm