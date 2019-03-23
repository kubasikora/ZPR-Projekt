all: 
	cd scada_server
	ls
	scons
	cd ..

lint:
	astyle --project --recursive *.cpp
	find . -name '*.orig' -delete
