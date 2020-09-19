CC = g++
CPPFLAGS = -g -Wall -Iheader -std=c++17
OBJDIR = build
SRCDIR = src/main
TESTDIR = src/test
HEADERDIR = header

PROG = replay
TEST = test

_HEADERS = csvreader.h displayer.h
HEADERS = $(patsubst %, $(HEADERDIR)/%, $(_HEADERS))

_OBJS = csvreader.o
OBJS = $(patsubst %, $(OBJDIR)/%, $(_OBJS))

_MAIN_OBJS = main.o
MAIN_OBJS = $(patsubst %, $(OBJDIR)/%, $(_MAIN_OBJS))

_TEST_OBJS = test.o
TEST_OBJS = $(patsubst %, $(OBJDIR)/%, $(_TEST_OBJS))

$(PROG) : pre-build $(OBJS) $(MAIN_OBJS)
	$(CC) -o build/$(PROG) $(OBJS) $(MAIN_OBJS)

test : pre-build $(OBJS) $(TEST_OBJS)
	$(CC) -o build/$(TEST) $(OBJS) $(TEST_OBJS)
	build/$(TEST)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	$(CC) $(CPPFLAGS) -c $< -o $@ 


$(OBJDIR)/%.o: $(TESTDIR)/%.cpp $(HEADERS)
	$(CC) $(CPPFLAGS) -c $< -o $@ 

.PHONY : clean pre-build

pre-build:
	mkdir -p build

clean:
	rm -rf build
