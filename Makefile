CC=g++ 
CXXFLAGS=-std=c++0x
CFLAGS=-I.
DEP=headers/editorgui.h headers/linenode.h headers/sstring.h headers/textlist.h
OBJECTS=main.o editorgui.o linenode.o sstring.o textlist.o
LIBS=

editortest: $(OBJECTS)
	$(CC) $(CXXFLAGS) $(LIBS) $(CFLAGS) $^ -o $@

%.o: %.cpp $(DEP)
	$(CC) $(CXXFLAGS) $(LIBS) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJECTS) editortest