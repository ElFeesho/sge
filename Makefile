OBJS=engine.o entity.o renderable.o collidable.o scene.o
LIBS=
CFLAGS=
LIBRARY=libsge.a

all:$(OBJS)
	ar crf $(LIBRARY) $(OBJS)
%o:%cpp
	g++ $(CFLAGS) $< -c

clean:
	rm -f $(OBJS) $(LIBRARY)
