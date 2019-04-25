ifeq ($(OS), Windows_NT)
	PWD = %CD%
else
	PWD = `pwd`
endif


.PHONY: all


all: 
	cd $(PWD)/scada && scons

scada:
	cd $(PWD)/scada && scons

lint:
	astyle --project scada/src/*.cpp
	find . -name '*.orig' -delete

clean:
	rm -rf scada/build/*
	rm scada/libscada.so

test:
	pytest --ignore=scada
	newman run ZPR.postman_collection.json 
	cd $(PWD)/client && npm test 