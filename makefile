OBJS = mainA1.o 
CC = g++
CFLAGS = -Wall -g
EXEC = output

output: $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

mainA1.o: mainA1.cpp
	g++ -c mainA1.cpp
	
clean: 
	rm -f $(EXEC) *.o