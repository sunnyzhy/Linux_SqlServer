Server : sqlserver.o main.o
	g++ sqlserver.o main.o -o main -L/usr/local/freetds/lib -lsybdb -I/usr/local/freetds/inc
sqlserver.o : sqlserver.cpp
	g++ -c sqlserver.cpp -o sqlserver.o 
main.o : main.cpp
	g++ -c main.cpp -o main.o 
clean : 
	rm sqlserver.o main.o
