main: main.cpp dice.o normalDistribution.o exactDiceDistribution.o improvedDiceDistribution.o
	g++ -g -o main main.cpp dice.o normalDistribution.o exactDiceDistribution.o improvedDiceDistribution.o

dice.o: dice.cpp
	g++ -g -c -o dice.o dice.cpp

normalDistribution.o: normalDistribution.cpp
	g++ -g -c -o normalDistribution.o normalDistribution.cpp

exactDiceDistribution.o: exactDiceDistribution.cpp
	g++ -g -c -o exactDiceDistribution.o exactDiceDistribution.cpp

improvedDiceDistribution.o: improvedDiceDistribution.cpp
	g++ -g -c -o improvedDiceDistribution.o improvedDiceDistribution.cpp