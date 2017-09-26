SHELL=/bin/bash

all: clean cmake build
.PHONY: clean cmake build

cmake:
	mkdir -p build
	cd build && cmake ../src

build:
	cd build && make -j $$(($$(grep -c ^processor /proc/cpuinfo) * 2))

clean:
	rm -Rfv build
