ifeq ($(OS), Windows_NT)
	EXECUTABLE=LO21.exe
else
	EXECUTABLE=LO21
endif

$(EXECUTABLE): ../src/*.c ../include/*.h
	gcc ../src/*.c -o ../build/$(EXECUTABLE) -lm -W -Wall -Wextra -O3

run:
	../build/LO21.exe

clean:
	rm ../build/*