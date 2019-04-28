ifeq ($(OS), Windows_NT)
	PWD = %CD%
	OBJ = .obj
else
	PWD = `pwd`
	OBJ = .o
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
	rm -rf scada/__tests__/*.$(OBJ) 
	rm scada/__tests__/scada_test


## testing 

python_test:
	pytest --ignore=scada

rest_test:
	newman run ZPR.postman_collection.json

client_test:
	cd $(PWD)/client && npm test

cpp_test:
	./scada/__tests__/scada_test

selenium_test:
	selenium-side-runner -c "browserName=chrome chromeOptions.args=[headless]" ZPR-Projekt.side

test:
	./scada/__tests__/scada_test
	pytest --ignore=scada
	newman run ZPR.postman_collection.json 
	cd $(PWD)/client && npm test 
	selenium-side-runner -c "browserName=chrome chromeOptions.args=[headless]" ZPR-Projekt.side


## misc

lint:
	astyle --project "scada/src/*.cpp" "scada/include/*.hpp"

documentation:
	doxygen
	cd $(PWD)/docs/doxygen/latex && make
