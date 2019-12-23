CC=gcc
AR=ar
OBJECTS_MAIN1=mainsort.o
OBJECTS_MAIN2=maintxt.o
OBJECTS_LIB1=isort.o
OBJECTS_LIB2=txtfind.o
FLAGS= -Wall -g

all: libmylib1.so libmylib2.so isort txtfind 

isort: $(OBJECTS_MAIN1)
	$(CC) $(FLAGS) -o isort $(OBJECTS_MAIN1) ./libmylib1.so
libmylib1.so: $(OBJECTS_LIB1)
	$(CC) -shared -o libmylib1.so $(OBJECTS_LIB1)    
isort.o: isort.c isort.h
	$(CC) $(FLAGS) -fPIC -c isort.c
mainsort.o: mainsort.c isort.h
	$(CC) $(FLAGS) -c mainsort.c 


txtfind: $(OBJECTS_MAIN2)
	$(CC) $(FLAGS) -o txtfind $(OBJECTS_MAIN2) ./libmylib2.so
libmylib2.so: $(OBJECTS_LIB2)
	$(CC) -shared -o libmylib2.so $(OBJECTS_LIB2)
txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -fPIC -c txtfind.c
maintxt.o: maintxt.c txtfind.h 
	$(CC) $(FLAGS) -c maintxt.c



.PHONY: clean all

clean:
	rm -f *.o *.so isort txtfind