PROGRAM=anasm
SOURCES=main.cc lexer.cc parser.cc driver.cc
OBJECTS=parser.o driver.o lexer.o main.o
LEX_OUT=lexer.cc
BISON_OUT=parser.cc parser.hh parser.output location.hh position.hh stack.hh

LEX=win_flex
BISON=win_bison
CXX=g++

CXXFLAGS=-std=c++11 -IC:/win_flex_bison/include
LDFLAGS=
LIBS=

.SUFFIXES: .o .hh .cc .l .yy

all: $(PROGRAM)

.cc.o:
	$(CXX) $(CXXFLAGS) -c -o $*.o $<

.l.cc:
	$(LEX) -+ -o$*.cc $<

.yy.cc:
	$(BISON) --defines=$*.hh --output-file=$*.cc $<

$(PROGRAM): $(OBJECTS)
	$(CXX) -o $(PROGRAM) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) $(LIBS)

clean:
	rm -f $(OBJECTS) $(LEX_OUT) $(BISON_OUT) $(PROGRAM)

parser.cc: parser.yy

lexer.cc: lexer.l

parser.hh: parser.yy

lexer.o: lexer.cc

parser.o: parser.cc

driver.o: driver.cc

main.o: main.cc
