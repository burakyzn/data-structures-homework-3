hepsi: nesneler derle calistir
nesneler:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/BST.o -c ./src/BST.cpp
	g++ -I ./include/ -o ./lib/OyunKontrol.o -c ./src/OyunKontrol.cpp
derle:	
	g++ -I ./include/ -o ./bin/Test ./lib/Dugum.o ./lib/BST.o ./lib/OyunKontrol.o ./src/Test.cpp
calistir:
	./bin/Test