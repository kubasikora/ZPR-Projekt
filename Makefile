ifeq ($(OS), Windows_NT)
	PWD = %CD%
	OBJ = .obj
	RM = del
	RMR =del /S /Q
	SO=pyd
	SCADA_TEST_EXE = scada_test.exe
	RUN_CPP_TEST = cd $(PWD)/server/scada/__tests__ && start $(SCADA_TEST_EXE)
else
	PWD = `pwd`
	OBJ = .o
	RM = rm
	RMR = rm -rf
	SO=so
	SCADA_TEST_EXE = scada_test
	RUN_CPP_TEST = ./server/scada/__tests__/scada_test
endif


.PHONY: all


## building

all: 
	cd $(PWD)/server/scada && scons

scada:
	cd $(PWD)/server/scada && scons

clean:
	$(RMR) ./server/scada/build
	cd $(PWD)/server/scada/src && $(RMR) *$(OBJ)
	cd $(PWD)/server/scada && $(RM) libscada.$(SO)
	cd $(PWD)/server/scada/__tests__ && $(RMR) *$(OBJ) 
	cd $(PWD)/server/scada/__tests__ && $(RM) $(SCADA_TEST_EXE)

## testing 

python_test:
	pytest --ignore=server/scada

rest_test:
	newman run ZPR.postman_collection.json

client_test:
	cd $(PWD)/client && npm test

cpp_test:
	$(RUN_CPP_TEST)

selenium_test:
	selenium-side-runner -c "browserName=chrome chromeOptions.args=[headless]" ZPR-Projekt.side

test:
	$(RUN_CPP_TEST)
	pytest --ignore=server/scada
	newman run ZPR.postman_collection.json 
	cd $(PWD)/client && npm test 
	selenium-side-runner -c "browserName=chrome chromeOptions.args=[headless]" ZPR-Projekt.side


## misc

lint:
	astyle --project "server/scada/src/*.cpp" "server/scada/include/*.hpp"

documentation:
	doxygen
	cd $(PWD)/docs/doxygen/latex && make
