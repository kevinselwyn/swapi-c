#include <stdio.h>
#include "../swapi.h"

int main(int argc, char *argv[]) {
	int page = 1, page_size = 10, count = 1000, mass = 0, mass_limit = 100;
	int i = 0, l = 0;
	struct swapi_people_all people;

	if (argc >= 2) {
		mass_limit = atoi(argv[1]);
	}

	printf("Star Wars characters whose mass is less than %dkg:\n", mass_limit);

	while (page * page_size <= count) {
		swapi_get_people_all(&people, page++);

		count = people.count;

		for (i = 0, l = people.results_count; i < l; i++) {
			sscanf(people.people[i].mass, "%d", &mass);

			if (strstr(people.people[i].mass, ",")) {
				continue;
			}

			if (mass < mass_limit) {
				printf("%02dkg - %s\n", mass, people.people[i].name);
			}
		}
	}

	return 0;
}