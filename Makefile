FLAGS = -O3 -std=c++11 -Wall -Wuninitialized -pedantic

.PHONY: build
build:
	ano build -m mega --cpu atmega2560 --cxxflags="$(FLAGS)"

debug_lidar:
	ano build -m mega --cpu atmega2560 --cxxflags="$(FLAGS)"

.PHONY: upload
upload: build
	ano upload -m mega --cpu atmega2560

.PHONY: b
b: build

.PHONY: u
u: upload

.PHONY: s
s: upload
	ano serial

.PHONY: p
p:
	ano build -m mega --cpu atmega2560 --cxxflags="$(FLAGS)" --arduino-dist="/opt/arduino-1.6.6"

.PHONY: pu
pu: p upload

.PHONY: pus
pus: p upload
	ano serial

.PHONY: clean
clean:
	ano clean
