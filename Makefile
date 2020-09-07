SRCS = main.cpp \
	lexer.cpp \
	syntax.cpp \
	token.cpp \
	node.cpp

OUTFILE = a.out

build:
	g++ -o ${OUTFILE} ${SRCS}