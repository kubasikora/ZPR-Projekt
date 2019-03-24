.PHONY: all

all: 
	cd `pwd`/scada && scons

scada:
	cd `pwd`/scada && scons

lint:
	astyle --project scada/src/*.cpp
	find . -name '*.orig' -delete
