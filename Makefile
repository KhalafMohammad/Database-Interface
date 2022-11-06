# -*- MakeFile -*-

#target: dependencies
#	action

all: circuits constructorResults constructorStandings constructors driverStandings drivers lapTimes pitStops qualifying races results seasons status target interface

interface: Interface.c
	gcc -Wall -Wextra -o interface Interface.c $$(mariadb_config --libs)


circuits: circuits.c
	gcc -Wall -Wextra -o circuits circuits.c $$(mariadb_config --libs)



constructorResults: constructorResults.c
	gcc -Wall -Wextra -o constructorResults constructorResults.c $$(mariadb_config --libs)



constructorStandings: constructorStandings.c
	gcc -Wall -Wextra -o constructorStandings constructorStandings.c $$(mariadb_config --libs)



constructors: constructors.c
	gcc -Wall -Wextra -o constructors constructors.c $$(mariadb_config --libs)



driverStandings: driverStandings.c
	gcc -Wall -Wextra -o driverStandings driverStandings.c $$(mariadb_config --libs)



drivers: drivers.c
	gcc -Wall -Wextra -o drivers drivers.c $$(mariadb_config --libs)


lapTimes: lapTimes.c
	gcc -Wall -Wextra -o lapTimes lapTimes.c $$(mariadb_config --libs)



pitStops: pitStops.c
	gcc -Wall -Wextra -o pitStops pitStops.c $$(mariadb_config --libs)



qualifying: qualifying.c
	gcc -Wall -Wextra -o qualifying qualifying.c $$(mariadb_config --libs)



races: races.c
	gcc -Wall -Wextra -o races races.c $$(mariadb_config --libs)



results: results.c
	gcc -Wall -Wextra -o results results.c $$(mariadb_config --libs)



seasons: seasons.c
	gcc -Wall -Wextra -o seasons seasons.c $$(mariadb_config --libs)



status: status.c
	gcc -Wall -Wextra -o status status.c $$(mariadb_config --libs)



target: target.c
	gcc -Wall -Wextra -o target target.c $$(mariadb_config --libs)


clear:
	rm circuits constructorResults constructorStandings constructors driverStandings drivers lapTimes pitStops qualifying races results seasons status target interface

