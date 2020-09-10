all: SpaceTaxi

SpaceTaxi: Main.o Functions.o SpaceTaxi.o Driver.o Person.o	Passenger.o Topology.o Planet.o Galaxy.o Trip.o Date.o Rate.o SystemMoney.o Admin.o BadException.o DiscountCode.o FindingDriverHelpingClass.o SpaceShip.o CommandProcess.o
		g++ Main.o Functions.o SpaceTaxi.o Driver.o Person.o Passenger.o Topology.o Planet.o Galaxy.o Trip.o Date.o Rate.o SystemMoney.o Admin.o BadException.o DiscountCode.o FindingDriverHelpingClass.o SpaceShip.o CommandProcess.o -o SpaceTaxi

Main.o: Main.cpp SpaceTaxi.h
		g++ -c Main.cpp

Functions.o: Functions.cpp SpaceTaxi.h Functions.h
		g++ -c Functions.cpp

SpaceTaxi.o: SpaceTaxi.cpp SpaceTaxi.h
		g++ -c SpaceTaxi.cpp

CommandProcess.o: CommandProcess.cpp CommandProcess.h SpaceTaxi.h
		g++ -c CommandProcess.cpp

Driver.o: Driver.cpp SpaceTaxi.h Driver.h
		g++ -c Driver.cpp

Person.o: Person.cpp SpaceTaxi.h Person.h
		g++ -c Person.cpp

Passenger.o: Passenger.cpp SpaceTaxi.h Passenger.h
		g++ -c Passenger.cpp

Topology.o: Topology.cpp SpaceTaxi.h Topology.h
		g++ -c Topology.cpp

Planet.o: Planet.cpp SpaceTaxi.h Planet.h
		g++ -c Planet.cpp

Galaxy.o: Galaxy.cpp Galaxy.h SpaceTaxi.h
		g++ -c Galaxy.cpp

Trip.o: Trip.cpp SpaceTaxi.h Trip.h
		g++ -c Trip.cpp

Date.o: Date.cpp SpaceTaxi.h Date.h
		g++ -c Date.cpp

Rate.o: Rate.cpp SpaceTaxi.h Rate.h
		g++ -c Rate.cpp

SystemMoney.o: SystemMoney.cpp SpaceTaxi.h SystemMoney.h
		g++ -c SystemMoney.cpp

Admin.o: Admin.cpp SpaceTaxi.h Admin.h
		g++ -c Admin.cpp

BadException.o: BadException.cpp SpaceTaxi.h BadException.h
		g++ -c BadException.cpp

DiscountCode.o: DiscountCode.cpp SpaceTaxi.h DiscountCode.h
		g++ -c DiscountCode.cpp

FindingDriverHelpingClass.o: FindingDriverHelpingClass.cpp SpaceTaxi.h FindingDriverHelpingClass.h
		g++ -c FindingDriverHelpingClass.cpp

SpaceShip.o: SpaceShip.cpp SpaceTaxi.h SpaceShip.h
		g++ -c SpaceShip.cpp

clean:
	rm *.o SpaceTaxi
