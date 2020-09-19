PROG = replay
CC = g++
CPPFLAGS = -g -Wall -Iheader
OBJDIR = build
SRCDIR = src
HEADERDIR = header

_HEADERS = dummy.h
HEADERS = $(patsubst %, $(HEADERDIR)/%, $(_HEADERS))

_OBJS = main.o dummy.o
OBJS = $(patsubst %, $(OBJDIR)/%, $(_OBJS))

$(PROG) : clean pre-build $(OBJS)
	$(CC) -o build/$(PROG) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	$(CC) $(CPPFLAGS) -c $< -o $@ 

.PHONY : clean pre-build

pre-build:
	mkdir build

clean:
	rm -rf build
