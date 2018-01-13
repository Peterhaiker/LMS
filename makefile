source=*.c
all:$(source) library.h
	gcc $(source) -o library -lmysqlclient
