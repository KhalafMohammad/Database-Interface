# -*- MakeFile -*-

#target: dependencies
#	action

all: circuits constructorResults constructorStandings constructors driverStandings drivers lapTimes pitStops qualifying races results seasons status target interface

interface: Interface.o error.o
	gcc -Wall -Wextra -o interface error.o Interface.o $$(mariadb_config --libs)

Interface.o: Interface.c interface.h
	gcc -Wall -Wextra -c Interface.c $$(mariadb_config --libs)

error.o: error.c
	gcc -Wall -Wextra -c error.c $$(mariadb_config --libs)

circuits: circuits.o error.o
	gcc -Wall -Wextra -o circuits circuits.o error.o $$(mariadb_config --libs)

circuits.o: circuits.c interface.h
	gcc -Wall -Wextra -c circuits.c $$(mariadb_config --libs)

constructorResults: constructorResults.o error.o
	gcc -Wall -Wextra -o constructorResults constructorResults.o error.o $$(mariadb_config --libs)

constructorResults.o: constructorResults.c interface.h
	gcc -Wall -Wextra -c constructorResults.c $$(mariadb_config --libs)

constructorStandings: constructorStandings.o error.o
	gcc -Wall -Wextra -o constructorStandings constructorStandings.o error.o $$(mariadb_config --libs)

constructorStandings.o: constructorStandings.c interface.h
	gcc -Wall -Wextra -c constructorStandings.c $$(mariadb_config --libs)

constructors: constructors.o error.o
	gcc -Wall -Wextra -o constructors constructors.o error.o $$(mariadb_config --libs)

constructors.o: constructors.c interface.h
	gcc -Wall -Wextra -c constructors.c $$(mariadb_config --libs)

driverStandings: driverStandings.o error.o
	gcc -Wall -Wextra -o driverStandings driverStandings.o error.o $$(mariadb_config --libs)

driverStandings.o: driverStandings.c interface.h
	gcc -Wall -Wextra -c driverStandings.c $$(mariadb_config --libs)

driverslapTimes: driverslapTimes.o error.o
	gcc -Wall -Wextra -o driverslapTimes driverslapTimes.o error.o $$(mariadb_config --libs)

driverslapTimes.o: driverslapTimes.c interface.h
	gcc -Wall -Wextra -c driverslapTimes.c $$(mariadb_config --libs)

pitStops: pitStops.o error.o
	gcc -Wall -Wextra -o pitStops pitStops.o error.o $$(mariadb_config --libs)

pitStops.o: pitStops.c interface.h
	gcc -Wall -Wextra -c pitStops.c $$(mariadb_config --libs)

qualifying: qualifying.o error.o
	gcc -Wall -Wextra -o qualifying qualifying.o error.o $$(mariadb_config --libs)

qualifying.o: qualifying.c interface.h
	gcc -Wall -Wextra -c qualifying.c $$(mariadb_config --libs)

races: races.o error.o
	gcc -Wall -Wextra -o races races.o error.o $$(mariadb_config --libs)

races.o: races.c interface.h
	gcc -Wall -Wextra -c races.c $$(mariadb_config --libs)

results: results.o error.o
	gcc -Wall -Wextra -o results results.o error.o $$(mariadb_config --libs)

results.o: results.c interface.h
	gcc -Wall -Wextra -c results.c $$(mariadb_config --libs)

seasons: seasons.o error.o
	gcc -Wall -Wextra -o seasons seasons.o error.o $$(mariadb_config --libs)

seasons.o: seasons.c interface.h
	gcc -Wall -Wextra -c seasons.c $$(mariadb_config --libs)

status: status.o error.o
	gcc -Wall -Wextra -o status status.o error.o $$(mariadb_config --libs)

status.o: status.c interface.h
	gcc -Wall -Wextra -c status.c $$(mariadb_config --libs)

target: target.o error.o
	gcc -Wall -Wextra -o target target.o error.o $$(mariadb_config --libs)

target.o: target.c interface.h
	gcc -Wall -Wextra -c target.c $$(mariadb_config --libs)


clear:
	rm *.o  circuits constructorResults constructorStandings constructors driverStandings drivers lapTimes pitStops qualifying races results seasons status target interface

