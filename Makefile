SRCS = main.cpp \
	lexer.cpp \
	syntax.cpp \
	token.cpp

OURFILE = a.out

build:
	g++ -o ${OURFILE} ${SRCS}