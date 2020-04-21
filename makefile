cc = g++
cppflags = -W -g

target = main
src = main.cpp
hedrs = Stack.h LinkedList.h
objects = main.o


$(target): $(objects) $(hedrs)
	$(cc) -o $(target) $(objects)

clean:
	rm $(target) $(objects)
