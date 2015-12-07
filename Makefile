build:
	ano build -m mega --cpu atmega2560 --cxxflags="-std=c++11"

upload: build
	ano upload -m mega --cpu atmega2560

p:
	ano build -m mega --cpu atmega2560 --cxxflags="-std=c++11" --arduino-dist="/opt/arduino-1.6.6"

pu: p upload

clean:
	ano clean
