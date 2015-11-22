all: bin/Lidar.o bin/DriveMotor.o
	g++ -g bin/DriveMotor.o bin/Lidar.o Main.cpp -l mraa -o bin/lidar

clean:
	rm bin/*.o bin/lidar

bin/DriveMotor.o: DriveMotor.cpp
	g++ -g -c DriveMotor.cpp -o bin/DriveMotor.o

bin/Lidar.o: Lidar.cpp
	g++ -g -c Lidar.cpp -o bin/Lidar.o
