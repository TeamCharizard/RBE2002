.PHONY: build
build:
	ano build -m mega --cpu atmega2560 --cxxflags="-std=c++11"

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
	ano build -m mega --cpu atmega2560 --cxxflags="-std=c++11" --arduino-dist="/opt/arduino-1.6.6"

.PHONY: pu
pu: p upload

.PHONY: pus
pus: p upload
	ano serial

.PHONY: clean
clean:
	ano clean
