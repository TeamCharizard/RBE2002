all: bin/Lidar.o bin/DriveMotor.o
	g++ Main.cpp bin/DriveMotor.o bin/Lidar.o -l mraa -o /bin/main

bin/DriveMotor.o:
	g++ -c DriveMotor.cpp -o bin/DriveMotor.o

bin/Lidar.o:
	g++ -c Lidar.cpp -o bin/Lidar.o
