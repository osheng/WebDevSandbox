all: server.c
	gcc -g -Wall -std=gnu99 -o server server.c
