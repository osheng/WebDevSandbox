FLAGS = -g -Wall -std=gnu99

all: server 

server: server.o helper.o
	gcc ${FLAGS} -o $@ $^

%.o: %.c helper.h
	gcc ${FLAGS} -c $<

clean:
	rm -f *.o server
