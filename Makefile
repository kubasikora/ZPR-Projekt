ifeq ($(OS), Windows_NT)
	PWD = %CD%
else
	PWD = `pwd`
endif


.PHONY: all


## building

all: 
	cd $(PWD)/scada && scons

scada:
	cd $(PWD)/scada && scons

clean:
	rm -rf scada/build/*
	rm scada/libscada.so



## testing 

python_test:
	pytest --ignore=scada

rest_test:
	newman run ZPR.postman_collection.json

client_test:
	cd $(PWD)/client && npm test

test:
	pytest --ignore=scada
	newman run ZPR.postman_collection.json 
	cd $(PWD)/client && npm test 


## misc

lint:
	astyle --project "scada/src/*.cpp" "scada/include/*.hpp"

documentation:
	doxygen
	cd $(PWD)/docs/doxygen/latex && make
