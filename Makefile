all:
	mingw32/bin/g++ -I"include" -I"SFML-2.6.1/include" -L"SFML-2.6.1/lib" src/*.cpp -o bin/main -lsfml-graphics -lsfml-system -lsfml-window