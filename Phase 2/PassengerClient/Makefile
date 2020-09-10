all: PassengerClient

PassengerClient: main.cpp client_socket.o tools.o Functions.o
	g++ main.cpp client_socket.o tools.o Functions.o -o PassengerClient
	
client_socket.o: client_socket.cpp client_socket.h tools.h network_exception.h
	g++ -c client_socket.cpp
	
tools.o: tools.cpp tools.h
	g++ -c tools.cpp
	
Functions.o: Functions.cpp Functions.h
	g++ -c Functions.cpp

clean:
	rm *.o PassengerClient
