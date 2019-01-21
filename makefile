output: main.o Board.o Player.o Space.o CastleSpace.o JungleSpace.o LandSpace.o FarmSpace.o
	g++ -std=c++11 main.o Board.o Player.o Space.o CastleSpace.o JungleSpace.o LandSpace.o FarmSpace.o -o output

main.o: main.cpp Board.cpp Player.cpp Space.cpp CastleSpace.cpp JungleSpace.cpp LandSpace.cpp FarmSpace.cpp
	g++ -std=c++11 -c main.cpp Board.cpp Player.cpp Space.cpp CastleSpace.cpp JungleSpace.cpp LandSpace.cpp FarmSpace.cpp

Board.o: Board.cpp Board.hpp
	g++ -std=c++11 -c Board.cpp

Player.o: Player.cpp Player.hpp
	g++ -std=c++11 -c Player.cpp

Space.o: Space.cpp Space.hpp
	g++ -std=c++11 -c Space.cpp

CastleSpace.o: CastleSpace.cpp CastleSpace.hpp
	g++ -std=c++11 -c CastleSpace.cpp

JungleSpace.o: JungleSpace.cpp JungleSpace.hpp
	g++ -std=c++11 -c JungleSpace.cpp

LandSpace.o: LandSpace.cpp LandSpace.hpp
	g++ -std=c++11 -c LandSpace.cpp

FarmSpace.o: FarmSpace.cpp FarmSpace.hpp
	g++ -std=c++11 -c FarmSpace.cpp

clean:
	rm *.o output