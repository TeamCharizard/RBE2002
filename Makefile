build:
	ano build -m mega --cpu atmega2560 --cxxflags="-std=c++11"

upload: build
	ano upload -m mega --cpu atmega2560

clean:
	ano clean
