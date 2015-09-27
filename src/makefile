localAlignTMScore: jsoncpp.o Protein.o HitProtein.o GroundTruthRoot.o Point.o Driver.o
	g++ jsoncpp.o  Protein.o Point.o HitProtein.o GroundTruthRoot.o Driver.o -o localAlignTMScore

jsoncpp.o: jsoncpp.cpp
	g++ -c jsoncpp.cpp
	
Protein.o: Protein.cpp
	g++ -c Protein.cpp
	
Point.o: Point.cpp
	g++ -c Point.cpp

HitProtein.o: HitProtein.cpp
	g++ -c HitProtein.cpp
	
GroundTruthRoot.o: GroundTruthRoot.cpp
	g++ -c GroundTruthRoot.cpp	
	
Driver.o: Driver.cpp
	g++ -c Driver.cpp
	

clean:
	rm *.o localAlignTMScore