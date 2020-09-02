SRCS = main.cpp \
	lexer.cpp \
	syntax.cpp \
	token.cpp

OUTFILE = a.out

build:
	g++ -o ${OUTFILE} ${SRCS}