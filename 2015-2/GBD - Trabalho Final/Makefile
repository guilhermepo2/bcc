CC = clang++
LIBS = -std=c++11 -stdlib=libc++
SOURCE = teste.cpp register.cpp page.cpp heapFile.cpp dataStructure.cpp
OUTPUT = meuDB

SOURCEYDDB = databaseInterface.cpp register.cpp page.cpp heapFile.cpp dataStructure.cpp
OUTPUTYDDB = yddb

meudb: teste.cpp
	$(CC) $(LIBS) $(SOURCE) -o $(OUTPUT)

yddb: databaseInterface.cpp
	$(CC) $(LIBS) $(SOURCEYDDB) -o $(OUTPUTYDDB)
