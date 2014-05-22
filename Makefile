OBJS=engine.o entity.o renderable.o collidable.o scene.o
LIBS=
CXXFLAGS=-std=c++11 -g
LIBRARY=libsge.a

all:$(OBJS)
	ar crf $(LIBRARY) $(OBJS)

clean:
	rm -f $(OBJS) $(LIBRARY)
