#ifndef SWAPI_H
#define SWAPI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <jansson.h>

#define ARRAY_MAX 16
#define RESULTS_MAX 10

static char *swapi_root = "http://swapi.dev/api";

struct swapi_memory {
	char *memory;
	size_t size;
};

struct swapi_people {
	const char *birth_year, *eye_color, *gender, *hair_color, *height;
	const char *homeworld, *mass, *name, *skin_color, *created, *edited, *url;
	const char *films[ARRAY_MAX], *species[ARRAY_MAX], *starships[ARRAY_MAX];
	const char *vehicles[ARRAY_MAX];
	int films_count, species_count, starships_count, vehicles_count;
};

struct swapi_people_all {
	int count;
	const char *next, *previous;
	struct swapi_people people[RESULTS_MAX];
	int results_count;
};

void swapi_dump_person(struct swapi_people person) {
	int i = 0, l = 0;

	printf("Name:       %s\n", person.name);
	printf("Height:     %s\n", person.height);
	printf("Mass:       %s\n", person.mass);
	printf("Hair Color: %s\n", person.hair_color);
	printf("Skin Color: %s\n", person.skin_color);
	printf("Eye Color:  %s\n", person.eye_color);
	printf("Birth Year: %s\n", person.birth_year);
	printf("Gender:     %s\n", person.gender);
	printf("Homeworld:  %s\n", person.homeworld);

	printf("Films:\n");
	for (i = 0, l = person.films_count; i < l; i++) {
		printf("  %s\n", person.films[i]);
	}

	printf("Species:\n");
	for (i = 0, l = person.species_count; i < l; i++) {
		printf("  %s\n", person.species[i]);
	}

	printf("Vehicles:\n");
	for (i = 0, l = person.vehicles_count; i < l; i++) {
		printf("  %s\n", person.vehicles[i]);
	}

	printf("Starships:\n");
	for (i = 0, l = person.starships_count; i < l; i++) {
		printf("  %s\n", person.starships[i]);
	}

	printf("Created:    %s\n", person.created);
	printf("Edited:     %s\n", person.edited);
	printf("URL:        %s\n", person.url);
}

void swapi_dump_people_all(struct swapi_people_all people) {
	int i = 0, l = 0;

	printf("Count:    %d\n", people.count);
	printf("Next:     %s\n", people.next);
	printf("Previous: %s\n", people.previous);

	printf("Results:\n");
	for (i = 0, l = people.results_count; i < l; i++) {
		printf("Result %d:\n\n", i);
		swapi_dump_person(people.people[i]);
	}
}

struct swapi_films {
	const char *director;
	int episode_id;
	const char *opening_crawl, *producer, *title, *created, *edited, *url;
	const char *characters[ARRAY_MAX], *planets[ARRAY_MAX];
	const char *species[ARRAY_MAX], *starships[ARRAY_MAX];
	const char *vehicles[ARRAY_MAX];
	int characters_count, planets_count, species_count, starships_count;
	int vehicles_count;
};

struct swapi_films_all {
	int count;
	const char *next, *previous;
	struct swapi_films films[RESULTS_MAX];
	int results_count;
};

void swapi_dump_film(struct swapi_films film) {
	int i = 0, l = 0;

	printf("Episode ID:    %d\n", film.episode_id);
	printf("Opening Crawl:\n%s\n", film.opening_crawl);
	printf("Director:      %s\n", film.director);
	printf("Producer:      %s\n", film.producer);

	printf("Characters:\n");
	for (i = 0, l = film.characters_count; i < l; i++) {
		printf("  %s\n", film.characters[i]);
	}

	printf("Planets:\n");
	for (i = 0, l = film.planets_count; i < l; i++) {
		printf("  %s\n", film.planets[i]);
	}

	printf("Starships:\n");
	for (i = 0, l = film.starships_count; i < l; i++) {
		printf("  %s\n", film.starships[i]);
	}

	printf("Vehicles:\n");
	for (i = 0, l = film.vehicles_count; i < l; i++) {
		printf("  %s\n", film.vehicles[i]);
	}

	printf("Species:\n");
	for (i = 0, l = film.species_count; i < l; i++) {
		printf("  %s\n", film.species[i]);
	}

	printf("Created:       %s\n", film.created);
	printf("Edited:        %s\n", film.edited);
	printf("URL:           %s\n", film.url);
}

void swapi_dump_films_all(struct swapi_films_all films) {
	int i = 0, l = 0;

	printf("Count:    %d\n", films.count);
	printf("Next:     %s\n", films.next);
	printf("Previous: %s\n", films.previous);

	printf("Results:\n");
	for (i = 0, l = films.results_count; i < l; i++) {
		printf("Result %d:\n\n", i);
		swapi_dump_film(films.films[i]);
	}
}

struct swapi_starships {
	const char *cargo_capacity, *consumables, *cost_in_credits, *crew;
	const char *hyperdrive_rating, *length, *manufacturer;
	const char *max_atmosphering_speed, *MGLT, *model, *name, *passengers;
	const char *starship_class, *created, *edited, *url;
	const char *films[ARRAY_MAX], *pilots[ARRAY_MAX];
	int films_count, pilots_count;
};

struct swapi_starships_all {
	int count;
	const char *next, *previous;
	struct swapi_starships starships[RESULTS_MAX];
	int results_count;
};

void swapi_dump_starship(struct swapi_starships starship) {
	int i = 0, l = 0;

	printf("Name:                   %s\n", starship.name);
	printf("Model:                  %s\n", starship.model);
	printf("Manufacturer:           %s\n", starship.manufacturer);
	printf("Cost In Credits:        %s\n", starship.cost_in_credits);
	printf("Length:                 %s\n", starship.length);
	printf("Max Atmosphering Speed: %s\n", starship.max_atmosphering_speed);
	printf("Crew:                   %s\n", starship.crew);
	printf("Passengers:             %s\n", starship.passengers);
	printf("Cargo Capacity:         %s\n", starship.cargo_capacity);
	printf("Consumables:            %s\n", starship.consumables);
	printf("Hyperdrive Rating:      %s\n", starship.hyperdrive_rating);
	printf("MGLT:                   %s\n", starship.MGLT);
	printf("Starship Class:         %s\n", starship.starship_class);

	printf("Pilots:\n");
	for (i = 0, l = starship.pilots_count; i < l; i++) {
		printf("  %s\n", starship.pilots[i]);
	}

	printf("Films:\n");
	for (i = 0, l = starship.films_count; i < l; i++) {
		printf("  %s\n", starship.films[i]);
	}

	printf("Created:                %s\n", starship.created);
	printf("Edited:                 %s\n", starship.edited);
	printf("URL:                    %s\n", starship.url);
}

void swapi_dump_starships_all(struct swapi_starships_all starships) {
	int i = 0, l = 0;

	printf("Count:    %d\n", starships.count);
	printf("Next:     %s\n", starships.next);
	printf("Previous: %s\n", starships.previous);

	printf("Results:\n");
	for (i = 0, l = starships.results_count; i < l; i++) {
		printf("Result %d:\n\n", i);
		swapi_dump_starship(starships.starships[i]);
	}
}

struct swapi_vehicles {
	const char *cargo_capacity, *consumables, *cost_in_credits, *crew, *length;
	const char *manufacturer, *max_atmosphering_speed, *model, *name;
	const char *passengers, *vehicle_class, *created, *edited, *url;
	const char *films[ARRAY_MAX], *pilots[ARRAY_MAX];
	int films_count, pilots_count;
};

struct swapi_vehicles_all {
	int count;
	const char *next, *previous;
	struct swapi_vehicles vehicles[RESULTS_MAX];
	int results_count;
};

void swapi_dump_vehicle(struct swapi_vehicles vehicle) {
	int i = 0, l = 0;

	printf("Name:                   %s\n", vehicle.name);
	printf("Model:                  %s\n", vehicle.model);
	printf("Manufacturer:           %s\n", vehicle.manufacturer);
	printf("Cost In Credits:        %s\n", vehicle.cost_in_credits);
	printf("Length:                 %s\n", vehicle.length);
	printf("Max Atmosphering Speed: %s\n", vehicle.max_atmosphering_speed);
	printf("Crew:                   %s\n", vehicle.crew);
	printf("Passengers:             %s\n", vehicle.passengers);
	printf("Cargo Capacity:         %s\n", vehicle.cargo_capacity);
	printf("Consumables:            %s\n", vehicle.consumables);
	printf("Vehicle Class:          %s\n", vehicle.vehicle_class);

	printf("Pilots:\n");
	for (i = 0, l = vehicle.pilots_count; i < l; i++) {
		printf("  %s\n", vehicle.pilots[i]);
	}

	printf("Films:\n");
	for (i = 0, l = vehicle.films_count; i < l; i++) {
		printf("  %s\n", vehicle.films[i]);
	}

	printf("Created:                %s\n", vehicle.created);
	printf("Edited:                 %s\n", vehicle.edited);
	printf("URL:                    %s\n", vehicle.url);
}

void swapi_dump_vehicles_all(struct swapi_vehicles_all vehicles) {
	int i = 0, l = 0;

	printf("Count:    %d\n", vehicles.count);
	printf("Next:     %s\n", vehicles.next);
	printf("Previous: %s\n", vehicles.previous);

	printf("Results:\n");
	for (i = 0, l = vehicles.results_count; i < l; i++) {
		printf("Result %d:\n\n", i);
		swapi_dump_vehicle(vehicles.vehicles[i]);
	}
}

struct swapi_species {
	const char *average_height, *average_lifespan, *classification;
	const char *designation, *eye_colors, *hair_colors, *homeworld, *language;
	const char *name, *skin_colors, *created, *edited, *url;
	const char *films[ARRAY_MAX], *people[ARRAY_MAX];
	int films_count, people_count;
};

struct swapi_species_all {
	int count;
	const char *next, *previous;
	struct swapi_species species[RESULTS_MAX];
	int results_count;
};

void swapi_dump_species(struct swapi_species species) {
	int i = 0, l = 0;

	printf("Name:             %s\n", species.name);
	printf("Classification:   %s\n", species.classification);
	printf("Designation:      %s\n", species.designation);
	printf("Average Height:   %s\n", species.average_height);
	printf("Skin Colors:      %s\n", species.skin_colors);
	printf("Hair Colors:      %s\n", species.hair_colors);
	printf("Eye Colors:       %s\n", species.eye_colors);
	printf("Average Lifespan: %s\n", species.average_lifespan);
	printf("Homeworld:        %s\n", species.homeworld);
	printf("Language:         %s\n", species.language);

	printf("People:\n");
	for (i = 0, l = species.people_count; i < l; i++) {
		printf("  %s\n", species.people[i]);
	}

	printf("Films:\n");
	for (i = 0, l = species.films_count; i < l; i++) {
		printf("  %s\n", species.films[i]);
	}

	printf("Created:          %s\n", species.created);
	printf("Edited:           %s\n", species.edited);
	printf("URL:              %s\n", species.url);
}

void swapi_dump_species_all(struct swapi_species_all species) {
	int i = 0, l = 0;

	printf("Count:    %d\n", species.count);
	printf("Next:     %s\n", species.next);
	printf("Previous: %s\n", species.previous);

	printf("Results:\n");
	for (i = 0, l = species.results_count; i < l; i++) {
		printf("Result %d:\n\n", i);
		swapi_dump_species(species.species[i]);
	}
}

struct swapi_planets {
	const char *climate, *diameter, *gravity, *name, *orbital_period;
	const char *population, *rotation_period, *surface_water, *terrain;
	const char *created, *edited, *url;
	const char *films[ARRAY_MAX], *residents[ARRAY_MAX];
	int films_count, residents_count;
};

struct swapi_planets_all {
	int count;
	const char *next, *previous;
	struct swapi_planets planets[RESULTS_MAX];
	int results_count;
};

void swapi_dump_planet(struct swapi_planets planet) {
	int i = 0, l = 0;

	printf("Name:            %s\n", planet.name);
	printf("Rotation Period: %s\n", planet.rotation_period);
	printf("Orbital Period:  %s\n", planet.orbital_period);
	printf("Diameter:        %s\n", planet.diameter);
	printf("Climate:         %s\n", planet.climate);
	printf("Gravity:         %s\n", planet.gravity);
	printf("Terrain:         %s\n", planet.terrain);
	printf("Surface Water:   %s\n", planet.surface_water);
	printf("Population:      %s\n", planet.population);

	printf("Residents:\n");
	for (i = 0, l = planet.residents_count; i < l; i++) {
		printf("  %s\n", planet.residents[i]);
	}

	printf("Films:\n");
	for (i = 0, l = planet.films_count; i < l; i++) {
		printf("  %s\n", planet.films[i]);
	}

	printf("Created:         %s\n", planet.created);
	printf("Edited:          %s\n", planet.edited);
	printf("URL:             %s\n", planet.url);
}

void swapi_dump_planets_all(struct swapi_planets_all planets) {
	int i = 0, l = 0;

	printf("Count:    %d\n", planets.count);
	printf("Next:     %s\n", planets.next);
	printf("Previous: %s\n", planets.previous);

	printf("Results:\n");
	for (i = 0, l = planets.results_count; i < l; i++) {
		printf("Result %d:\n\n", i);
		swapi_dump_planet(planets.planets[i]);
	}
}

static size_t swapi_write(void *ptr, size_t size, size_t nmemb, char *response) {
	size_t real_size = size * nmemb;
	struct swapi_memory *mem = (struct swapi_memory *)response;

	mem->memory = realloc(mem->memory, mem->size + real_size + 1);

	if (mem->memory == NULL) {
		printf("Memory error\n");

		return 0;
	}

	memcpy(&(mem->memory[mem->size]), ptr, real_size);
	mem->size += real_size;
	mem->memory[mem->size] = (char)0;

	return real_size;
}

static void swapi_get_curl(char **json, char *url) {
	struct swapi_memory response;
	CURL *curl;
	CURLcode res;

	response.memory = malloc(1);
	response.size = 0;

	curl = curl_easy_init();

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "swapi-c");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, swapi_write);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);

		res = curl_easy_perform(curl);

		if (res != CURLE_OK) {
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
			exit(EXIT_FAILURE);
		}

		*json = malloc(sizeof(char) * response.size + 1);
		strcpy(*json, response.memory);

		curl_easy_cleanup(curl);
	}

	if (response.memory) {
		free(response.memory);
	}
}

static const char *swapi_json_parse_string(char *json, char *key) {
	int rc = 0;
	const char *string_text = "";
	json_t *root, *string;
	json_error_t error;

	root = json_loads(json, 0, &error);

	if (!root) {
		fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);

		rc = 1;
		goto cleanup;
	}

	if (!json_is_object(root)) {
		fprintf(stderr, "error: root is not an object\n");

		rc = 1;
		goto cleanup;
	}

	string = json_object_get(root, key);

	if (!json_is_null(string)) {
		if (!json_is_string(string)) {
			fprintf(stderr, "error: element %s is not a string\n", key);

			rc = 1;
			goto cleanup;
		}

		string_text = json_string_value(string);
	}

cleanup:
	if (rc != 0) {
		json_decref(root);
		exit(rc);
	}

	return string_text;
}

static int swapi_json_parse_integer(char *json, char *key) {
	int rc = 0, int_val = 0;
	json_t *root, *integer;
	json_error_t error;

	root = json_loads(json, 0, &error);

	if (!root) {
		fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);

		rc = 1;
		goto cleanup;
	}

	if (!json_is_object(root)) {
		fprintf(stderr, "error: root is not an object\n");

		rc = 1;
		goto cleanup;
	}

	integer = json_object_get(root, key);

	if (!json_is_integer(integer)) {
		fprintf(stderr, "error: element %s is not an integer\n", key);

		rc = 1;
		goto cleanup;
	}

	int_val = json_integer_value(integer);

cleanup:
	if (rc != 0) {
		json_decref(root);
		exit(rc);
	}

	return int_val;
}

static int swapi_json_parse_array(const char *array_content[ARRAY_MAX], char *json, char *key) {
	int rc = 0, i = 0, l = 0;
	int array_count = 0;
	json_t *root, *array, *data;
	json_error_t error;

	root = json_loads(json, 0, &error);

	if (!root) {
		fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);

		rc = 1;
		goto cleanup;
	}

	if (!json_is_object(root)) {
		fprintf(stderr, "error: root is not an object\n");

		rc = 1;
		goto cleanup;
	}

	array = json_object_get(root, key);

	if (!json_is_array(array)) {
		fprintf(stderr, "error: element is not an array\n");

		rc = 1;
		goto cleanup;
	}

	l = json_array_size(array);

	if (l > ARRAY_MAX) {
		l = ARRAY_MAX;
	}

	for (i = 0; i < l; i++) {
		data = json_array_get(array, i);

		if (!json_is_string(data)) {
			fprintf(stderr, "error: element is not a string\n");

			rc = 1;
			goto cleanup;
		}

		array_content[array_count++] = json_string_value(data);
	}

cleanup:
	if (rc != 0) {
		json_decref(root);
	}

	return array_count;
}

static void swapi_get_x(char **json, char *format, char *resource, int variable) {
	char *url = NULL;
	size_t root_length = 0, resource_length = 0;

	if (variable <= 0) {
		variable = 1;
	}

	root_length = strlen(swapi_root);
	resource_length = strlen(resource);

	url = malloc(sizeof(char) * (root_length + resource_length + 6) + 1);
	sprintf(url, format, swapi_root, resource, variable);

	swapi_get_curl(&*json, url);

	if (url) {
		free(url);
	}
}

static void swapi_get_one(char **json, char *resource, int id) {
	char *format = "%s/%s/%d";

	swapi_get_x(&*json, format, resource, id);
}

static void swapi_get_all(char **json, char *resource, int page) {
	char *format = "%s/%s/?page=%d";

	swapi_get_x(&*json, format, resource, page);
}

static int swapi_get_variable(char *url_pattern, char *resource, char *url) {
	int variable = 1;
	size_t url_length = 0;
	char *pattern = NULL;

	url_length = strlen(url);

	pattern = malloc(sizeof(char) * url_length + 1);

	sprintf(pattern, url_pattern, swapi_root, resource);

	if (sscanf(url, pattern, &variable) == 0) {
		fprintf(stderr, "error: could not get variable\n");
	}

	if (pattern) {
		free(pattern);
	}

	return variable;
}

static int swapi_get_id(char *url, char *resource) {
	int id = swapi_get_variable("%s/%s/%%d/", resource, url);

	return id;
}

static int swapi_get_page(char *url, char *resource) {
	int page = swapi_get_variable("%s/%s/?page=%%d", resource, url);

	return page;
}

static int swapi_get_resource_all(json_t **results, char *json) {
	int rc = 0, l = 0;
	json_t *root;
	json_error_t error;

	root = json_loads(json, 0, &error);

	if (!root) {
		fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);

		rc = 1;
		goto cleanup;
	}

	if (!json_is_object(root)) {
		fprintf(stderr, "error: root is not an object\n");

		rc = 1;
		goto cleanup;
	}

	*results = json_object_get(root, "results");

	if (!json_is_array(*results)) {
		fprintf(stderr, "error: element is not an array\n");

		rc = 1;
		goto cleanup;
	}

	l = json_array_size(*results);

	if (l > RESULTS_MAX) {
		l = RESULTS_MAX;
	}

cleanup:
	if (rc != 0) {
		json_decref(root);
		exit(rc);
	}

	return l;
}

void swapi_get_person(struct swapi_people *person, int id) {
	char *json = NULL;

	swapi_get_one(&json, "people", id);

	person->birth_year = swapi_json_parse_string(json, "birth_year");
	person->eye_color = swapi_json_parse_string(json, "eye_color");
	person->gender = swapi_json_parse_string(json, "gender");
	person->hair_color = swapi_json_parse_string(json, "hair_color");
	person->height = swapi_json_parse_string(json, "height");
	person->homeworld = swapi_json_parse_string(json, "homeworld");
	person->mass = swapi_json_parse_string(json, "mass");
	person->name = swapi_json_parse_string(json, "name");
	person->skin_color = swapi_json_parse_string(json, "skin_color");
	person->created = swapi_json_parse_string(json, "created");
	person->edited = swapi_json_parse_string(json, "edited");
	person->url = swapi_json_parse_string(json, "url");

	person->films_count = swapi_json_parse_array(person->films, json, "films");
	person->species_count = swapi_json_parse_array(person->species, json, "species");
	person->starships_count = swapi_json_parse_array(person->starships, json, "starships");
	person->vehicles_count = swapi_json_parse_array(person->vehicles, json, "vehicles");

	if (json) {
		free(json);
	}
}

void swapi_get_person_url(struct swapi_people *person, char *url) {
	int id = swapi_get_id(url, "people");

	swapi_get_person(person, id);
}

void swapi_get_people_all(struct swapi_people_all *people, int page) {
	int rc = 0, i = 0, l = 0;
	int results_count = 0;
	char *json = NULL;
	const char *url_text;
	json_t *results, *data, *url;

	swapi_get_all(&json, "people", page);

	people->count = swapi_json_parse_integer(json, "count");
	people->next = swapi_json_parse_string(json, "next");
	people->previous = swapi_json_parse_string(json, "previous");

	l = swapi_get_resource_all(&results, json);

	for (i = 0; i < l; i++) {
		data = json_array_get(results, i);

		if (!json_is_object(data)) {
			fprintf(stderr, "error: element is not an object\n");

			rc = 1;
			goto cleanup;
		}

		url = json_object_get(data, "url");

		if (!json_is_string(url)) {
			fprintf(stderr, "error: element is not a string\n");

			rc = 1;
			goto cleanup;
		}

		url_text = json_string_value(url);

		swapi_get_person_url(&people->people[results_count++], (char *)url_text);
	}

	people->results_count = results_count;

cleanup:
	if (rc != 0) {
		exit(rc);
	}
}

void swapi_get_people_all_url(struct swapi_people_all *people, char *url) {
	int page = swapi_get_page(url, "people");

	swapi_get_people_all(people, page);
}

void swapi_get_film(struct swapi_films *film, int id) {
	char *json = NULL;

	swapi_get_one(&json, "films", id);

	film->created = swapi_json_parse_string(json, "created");
	film->director = swapi_json_parse_string(json, "director");
	film->edited = swapi_json_parse_string(json, "edited");
	film->episode_id = swapi_json_parse_integer(json, "episode_id");
	film->opening_crawl = swapi_json_parse_string(json, "opening_crawl");
	film->producer = swapi_json_parse_string(json, "producer");
	film->title = swapi_json_parse_string(json, "title");
	film->url = swapi_json_parse_string(json, "url");

	film->characters_count = swapi_json_parse_array(film->characters, json, "characters");
	film->planets_count = swapi_json_parse_array(film->planets, json, "planets");
	film->species_count = swapi_json_parse_array(film->species, json, "species");
	film->starships_count = swapi_json_parse_array(film->starships, json, "starships");
	film->vehicles_count = swapi_json_parse_array(film->vehicles, json, "vehicles");

	if (json) {
		free(json);
	}
}

void swapi_get_film_url(struct swapi_films *film, char *url) {
	int id = swapi_get_id(url, "films");

	swapi_get_film(film, id);
}

void swapi_get_films_all(struct swapi_films_all *films, int page) {
	int rc = 0, i = 0, l = 0;
	int results_count = 0;
	char *json = NULL;
	const char *url_text;
	json_t *results, *data, *url;

	swapi_get_all(&json, "films", page);

	films->count = swapi_json_parse_integer(json, "count");
	films->next = swapi_json_parse_string(json, "next");
	films->previous = swapi_json_parse_string(json, "previous");

	l = swapi_get_resource_all(&results, json);

	for (i = 0; i < l; i++) {
		data = json_array_get(results, i);

		if (!json_is_object(data)) {
			fprintf(stderr, "error: element is not an object\n");

			rc = 1;
			goto cleanup;
		}

		url = json_object_get(data, "url");

		if (!json_is_string(url)) {
			fprintf(stderr, "error: element is not a string\n");

			rc = 1;
			goto cleanup;
		}

		url_text = json_string_value(url);

		swapi_get_film_url(&films->films[results_count++], (char *)url_text);
	}

	films->results_count = results_count;

cleanup:
	if (rc != 0) {
		exit(rc);
	}
}

void swapi_get_films_all_url(struct swapi_films_all *films, char *url) {
	int page = swapi_get_page(url, "films");

	swapi_get_films_all(films, page);
}

void swapi_get_starship(struct swapi_starships *starship, int id) {
	char *json = NULL;

	swapi_get_one(&json, "starships", id);

	starship->MGLT = swapi_json_parse_string(json, "MGLT");
	starship->cargo_capacity = swapi_json_parse_string(json, "cargo_capacity");
	starship->consumables = swapi_json_parse_string(json, "consumables");
	starship->cost_in_credits = swapi_json_parse_string(json, "cost_in_credits");
	starship->created = swapi_json_parse_string(json, "created");
	starship->crew = swapi_json_parse_string(json, "crew");
	starship->edited = swapi_json_parse_string(json, "edited");
	starship->hyperdrive_rating = swapi_json_parse_string(json, "hyperdrive_rating");
	starship->length = swapi_json_parse_string(json, "length");
	starship->manufacturer = swapi_json_parse_string(json, "manufacturer");
	starship->max_atmosphering_speed = swapi_json_parse_string(json, "max_atmosphering_speed");
	starship->model = swapi_json_parse_string(json, "model");
	starship->name = swapi_json_parse_string(json, "name");
	starship->passengers = swapi_json_parse_string(json, "passengers");
	starship->starship_class = swapi_json_parse_string(json, "starship_class");
	starship->url = swapi_json_parse_string(json, "url");

	starship->films_count = swapi_json_parse_array(starship->films, json, "films");
	starship->pilots_count = swapi_json_parse_array(starship->pilots, json, "pilots");

	if (json) {
		free(json);
	}
}

void swapi_get_starship_url(struct swapi_starships *starship, char *url) {
	int id = swapi_get_id(url, "starships");

	swapi_get_starship(starship, id);
}

void swapi_get_starships_all(struct swapi_starships_all *starships, int page) {
	int rc = 0, i = 0, l = 0;
	int results_count = 0;
	char *json = NULL;
	const char *url_text;
	json_t *results, *data, *url;

	swapi_get_all(&json, "starships", page);

	starships->count = swapi_json_parse_integer(json, "count");
	starships->next = swapi_json_parse_string(json, "next");
	starships->previous = swapi_json_parse_string(json, "previous");

	l = swapi_get_resource_all(&results, json);

	for (i = 0; i < l; i++) {
		data = json_array_get(results, i);

		if (!json_is_object(data)) {
			fprintf(stderr, "error: element is not an object\n");

			rc = 1;
			goto cleanup;
		}

		url = json_object_get(data, "url");

		if (!json_is_string(url)) {
			fprintf(stderr, "error: element is not a string\n");

			rc = 1;
			goto cleanup;
		}

		url_text = json_string_value(url);

		swapi_get_starship_url(&starships->starships[results_count++], (char *)url_text);
	}

	starships->results_count = results_count;

cleanup:
	if (rc != 0) {
		exit(rc);
	}
}

void swapi_get_starships_all_url(struct swapi_starships_all *starships, char *url) {
	int page = swapi_get_page(url, "starships");

	swapi_get_starships_all(starships, page);
}

void swapi_get_vehicle(struct swapi_vehicles *vehicle, int id) {
	char *json = NULL;

	swapi_get_one(&json, "vehicles", id);

	vehicle->cargo_capacity = swapi_json_parse_string(json, "cargo_capacity");
	vehicle->consumables = swapi_json_parse_string(json, "consumables");
	vehicle->cost_in_credits = swapi_json_parse_string(json, "cost_in_credits");
	vehicle->created = swapi_json_parse_string(json, "created");
	vehicle->crew = swapi_json_parse_string(json, "crew");
	vehicle->edited = swapi_json_parse_string(json, "edited");
	vehicle->length = swapi_json_parse_string(json, "length");
	vehicle->manufacturer = swapi_json_parse_string(json, "manufacturer");
	vehicle->max_atmosphering_speed = swapi_json_parse_string(json, "max_atmosphering_speed");
	vehicle->model = swapi_json_parse_string(json, "model");
	vehicle->name = swapi_json_parse_string(json, "name");
	vehicle->passengers = swapi_json_parse_string(json, "passengers");
	vehicle->url = swapi_json_parse_string(json, "url");
	vehicle->vehicle_class = swapi_json_parse_string(json, "vehicle_class");

	vehicle->pilots_count = swapi_json_parse_array(vehicle->pilots, json, "pilots");
	vehicle->films_count = swapi_json_parse_array(vehicle->films, json, "films");

	if (json) {
		free(json);
	}
}

void swapi_get_vehicle_url(struct swapi_vehicles *vehicle, char *url) {
	int id = swapi_get_id(url, "vehicles");

	swapi_get_vehicle(vehicle, id);
}

void swapi_get_vehicles_all(struct swapi_vehicles_all *vehicles, int page) {
	int rc = 0, i = 0, l = 0;
	int results_count = 0;
	char *json = NULL;
	const char *url_text;
	json_t *results, *data, *url;

	swapi_get_all(&json, "vehicles", page);

	vehicles->count = swapi_json_parse_integer(json, "count");
	vehicles->next = swapi_json_parse_string(json, "next");
	vehicles->previous = swapi_json_parse_string(json, "previous");

	l = swapi_get_resource_all(&results, json);

	for (i = 0; i < l; i++) {
		data = json_array_get(results, i);

		if (!json_is_object(data)) {
			fprintf(stderr, "error: element is not an object\n");

			rc = 1;
			goto cleanup;
		}

		url = json_object_get(data, "url");

		if (!json_is_string(url)) {
			fprintf(stderr, "error: element is not a string\n");

			rc = 1;
			goto cleanup;
		}

		url_text = json_string_value(url);

		swapi_get_vehicle_url(&vehicles->vehicles[results_count++], (char *)url_text);
	}

	vehicles->results_count = results_count;

cleanup:
	if (rc != 0) {
		exit(rc);
	}
}

void swapi_get_vehicles_all_url(struct swapi_vehicles_all *vehicles, char *url) {
	int page = swapi_get_page(url, "vehicles");

	swapi_get_vehicles_all(vehicles, page);
}

void swapi_get_species(struct swapi_species *species, int id) {
	char *json = NULL;

	swapi_get_one(&json, "species", id);

	species->average_height = swapi_json_parse_string(json, "average_height");
	species->average_lifespan = swapi_json_parse_string(json, "average_lifespan");
	species->classification = swapi_json_parse_string(json, "classification");
	species->created = swapi_json_parse_string(json, "created");
	species->designation = swapi_json_parse_string(json, "designation");
	species->edited = swapi_json_parse_string(json, "edited");
	species->eye_colors = swapi_json_parse_string(json, "eye_colors");
	species->hair_colors = swapi_json_parse_string(json, "hair_colors");
	species->homeworld = swapi_json_parse_string(json, "homeworld");
	species->language = swapi_json_parse_string(json, "language");
	species->name = swapi_json_parse_string(json, "name");
	species->skin_colors = swapi_json_parse_string(json, "skin_colors");
	species->url = swapi_json_parse_string(json, "url");

	species->people_count = swapi_json_parse_array(species->people, json, "people");
	species->films_count = swapi_json_parse_array(species->films, json, "films");

	if (json) {
		free(json);
	}
}

void swapi_get_species_url(struct swapi_species *species, char *url) {
	int id = swapi_get_id(url, "species");

	swapi_get_species(species, id);
}

void swapi_get_species_all(struct swapi_species_all *species, int page) {
	int rc = 0, i = 0, l = 0;
	int results_count = 0;
	char *json = NULL;
	const char *url_text;
	json_t *results, *data, *url;

	swapi_get_all(&json, "species", page);

	species->count = swapi_json_parse_integer(json, "count");
	species->next = swapi_json_parse_string(json, "next");
	species->previous = swapi_json_parse_string(json, "previous");

	l = swapi_get_resource_all(&results, json);

	for (i = 0; i < l; i++) {
		data = json_array_get(results, i);

		if (!json_is_object(data)) {
			fprintf(stderr, "error: element is not an object\n");

			rc = 1;
			goto cleanup;
		}

		url = json_object_get(data, "url");

		if (!json_is_string(url)) {
			fprintf(stderr, "error: element is not a string\n");

			rc = 1;
			goto cleanup;
		}

		url_text = json_string_value(url);

		swapi_get_species_url(&species->species[results_count++], (char *)url_text);
	}

	species->results_count = results_count;

cleanup:
	if (rc != 0) {
		exit(rc);
	}
}

void swapi_get_species_all_url(struct swapi_species_all *species, char *url) {
	int page = swapi_get_page(url, "species");

	swapi_get_species_all(species, page);
}

void swapi_get_planet(struct swapi_planets *planet, int id) {
	char  *json = NULL;

	swapi_get_one(&json, "planets", id);

	planet->climate = swapi_json_parse_string(json, "climate");
	planet->created = swapi_json_parse_string(json, "created");
	planet->diameter = swapi_json_parse_string(json, "diameter");
	planet->edited = swapi_json_parse_string(json, "edited");
	planet->gravity = swapi_json_parse_string(json, "gravity");
	planet->name = swapi_json_parse_string(json, "name");
	planet->orbital_period = swapi_json_parse_string(json, "orbital_period");
	planet->population = swapi_json_parse_string(json, "population");
	planet->rotation_period = swapi_json_parse_string(json, "rotation_period");
	planet->surface_water = swapi_json_parse_string(json, "surface_water");
	planet->terrain = swapi_json_parse_string(json, "terrain");
	planet->url = swapi_json_parse_string(json, "url");

	planet->films_count = swapi_json_parse_array(planet->films, json, "films");
	planet->residents_count = swapi_json_parse_array(planet->residents, json, "residents");

	if (json) {
		free(json);
	}
}

void swapi_get_planet_url(struct swapi_planets *planet, char *url) {
	int id = swapi_get_id(url, "planets");

	swapi_get_planet(planet, id);
}

void swapi_get_planets_all(struct swapi_planets_all *planets, int page) {
	int rc = 0, i = 0, l = 0;
	int results_count = 0;
	char *json = NULL;
	const char *url_text;
	json_t *results, *data, *url;

	swapi_get_all(&json, "planets", page);

	planets->count = swapi_json_parse_integer(json, "count");
	planets->next = swapi_json_parse_string(json, "next");
	planets->previous = swapi_json_parse_string(json, "previous");

	l = swapi_get_resource_all(&results, json);

	for (i = 0; i < l; i++) {
		data = json_array_get(results, i);

		if (!json_is_object(data)) {
			fprintf(stderr, "error: element is not an object\n");

			rc = 1;
			goto cleanup;
		}

		url = json_object_get(data, "url");

		if (!json_is_string(url)) {
			fprintf(stderr, "error: element is not a string\n");

			rc = 1;
			goto cleanup;
		}

		url_text = json_string_value(url);

		swapi_get_planet_url(&planets->planets[results_count++], (char *)url_text);
	}

	planets->results_count = results_count;

cleanup:
	if (rc != 0) {
		exit(rc);
	}
}

void swapi_get_planets_all_url(struct swapi_planets_all *planets, char *url) {
	int page = swapi_get_page(url, "planets");

	swapi_get_planets_all(planets, page);
}

#endif // SWAPI_H
