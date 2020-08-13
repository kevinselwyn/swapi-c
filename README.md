# swapi-c

API wrapper for the [Star Wars API](http://swapi.co/) written in C

## Usage

Include the header to access all the methods:

```c
#include "swapi.h"
```

## Compiling

swapi-c relies on libcurl and libjansson. Use their respective flags to compile your C code:

```bash
gcc -o demo demo.c -lcurl -ljansson
```

## Variables Directory

Each type of result has its own customized struct:

* [struct swapi_people](#swapi-people)
* [struct swapi_films](#swapi-films)
* [struct swapi_starships](#swapi-starships)
* [struct swapi_vehicles](#swapi-vehicles)
* [struct swapi_species](#swapi-species)
* [struct swapi_planets](#swapi-planets)

Multiple results also have their own structs:

* [struct swapi_people_all](#swapi-people-all)
* [struct swapi_films_all](#swapi-films-all)
* [struct swapi_starships_all](#swapi-starships-all)
* [struct swapi_vehicles_all](#swapi-vehicles-all)
* [struct swapi_species_all](#swapi-species-all)
* [struct swapi_planets_all](#swapi-planets-all)

## Variables

### <a name="swapi-people"></a>struct swapi_people

```c
struct swapi_people {
	const char *birth_year;           // Birth Year
	const char *eye_color;            // Eye Color
	const char *gender;               // Gender
	const char *hair_color;           // Hair Color
	const char *height;               // Height
	const char *homeworld;            // Home World
	const char *mass;                 // Mass
	const char *name;                 // Name
	const char *skin_color;           // Skin Color
	const char *created;              // Created
	const char *edited;               // Edited
	const char *url;                  // URL
	const char *films[ARRAY_MAX];     // Films array
	const char *species[ARRAY_MAX];   // Species array
	const char *starships[ARRAY_MAX]; // Starships array
	const char *vehicles[ARRAY_MAX];  // Vehicles array
	int films_count;                  // Films array length
	int species_count;                // Species array length
	int starships_count;              // Starships array length
	int vehicles_count;               // Vehicles array length
};
```

### <a name="swapi-films"></a>struct swapi_films

```c
struct swapi_films {
	const char *director;              // Director
	int episode_id;                    // Episode ID
	const char *opening_crawl;         // Opening Crawl
	const char *producer;              // Producer
	const char *title;                 // Title
	const char *created;               // Created
	const char *edited;                // Edited
	const char *url;                   // URL
	const char *characters[ARRAY_MAX]; // Characters array
	const char *planets[ARRAY_MAX];    // Planets array
	const char *species[ARRAY_MAX];    // Species array
	const char *starships[ARRAY_MAX];  // Starships array
	const char *vehicles[ARRAY_MAX];   // Vehicles array
	int characters_count;              // Characters array length
	int planets_count;                 // Planets array length
	int species_count;                 // Species array length
	int starships_count;               // Starships array length
	int vehicles_count;                // Vehicles array length
};
```

### <a name="swapi-starships"></a>struct swapi_starships

```c
struct swapi_starships {
	const char *cargo_capacity;         // Cargo Capacity
	const char *consumables;            // Consumables
	const char *cost_in_credits;        // Cost In Credits
	const char *crew;                   // Crew
	const char *hyperdrive_rating;      // Hyperdrive Rating
	const char *length;                 // Length
	const char *manufacturer;           // Manufacturer
	const char *max_atmosphering_speed; // Max Atmosphering Speed
	const char *MGLT;                   // Megalight
	const char *model;                  // Model
	const char *name;                   // Name
	const char *passengers;             // Passengers
	const char *starship_class;         // Starship Class
	const char *created;                // Created
	const char *edited;                 // Edited
	const char *url;                    // URL
	const char *films[ARRAY_MAX];       // Films array
	const char *pilots[ARRAY_MAX];      // Pilots array
	int films_count;                    // Films array length
	int pilots_count;                   // Pilots array length
};
```

### <a name="swapi-vehicles"></a>struct swapi_vehicles

```c
struct swapi_vehicles {
	const char *cargo_capacity;         // Cargo Capacity
	const char *consumables;            // Consumables
	const char *cost_in_credits;        // Cost In Credits
	const char *crew;                   // Crew
	const char *length;                 // Length
	const char *manufacturer;           // Manufacturer
	const char *max_atmosphering_speed; // Max Atmosphering Speed
	const char *model;                  // Model
	const char *name;                   // Name
	const char *passengers;             // Passengers
	const char *vehicle_class;          // Vehicle Class
	const char *created;                // Created
	const char *edited;                 // Edited
	const char *url;                    // URL
	const char *films[ARRAY_MAX];       // Films array
	const char *pilots[ARRAY_MAX];      // Pilots array
	int films_count;                    // Films array length
	int pilots_count;                   // Pilots array length
};
```

### <a name="swapi-species"></a>struct swapi_species

```c
struct swapi_species {
	const char *average_height;    // Average Height
	const char *average_lifespan;  // Average Lifespan
	const char *classification;    // Classification
	const char *designation;       // Designation
	const char *eye_colors;        // Eye Colors
	const char *hair_colors;       // Hair Colors
	const char *homeworld;         // Homeworld
	const char *language;          // Language
	const char *name;              // Name
	const char *skin_colors;       // Skin Colors
	const char *created;           // Created
	const char *edited;            // Edited
	const char *url;               // URL
	const char *films[ARRAY_MAX];  // Films array
	const char *people[ARRAY_MAX]; // People array
	int films_count;               // Films array length
	int people_count;              // People array length
};
```

### <a name="swapi-planets"></a>struct swapi_planets

```c
struct swapi_planets {
	const char *climate;              // Climate
	const char *diameter;             // Diameter
	const char *gravity;              // Gravity
	const char *name;                 // Name
	const char *orbital_period;       // Orbital Period
	const char *population;           // Population
	const char *rotation_period;      // Rotation Period
	const char *surface_water;        // Surface Water
	const char *terrain;              // Terrain
	const char *created;              // Created
	const char *edited;               // Edited
	const char *url;                  // URL
	const char *films[ARRAY_MAX];     // Films array
	const char *residents[ARRAY_MAX]; // Residents array
	int films_count;                  // Films array length
	int residents_count;              // Residents array length
};
```

### <a name="swapi-people-all"></a>struct swapi_people_all

```c
struct swapi_people_all {
	int count;                               // Total Results Count
	const char *next;                        // Next URL
	const char *previous;                    // Previous URL
	struct swapi_people people[RESULTS_MAX]; // People array
	int results_count;                       // People array length
};
```

### <a name="swapi-films-all"></a>struct swapi_films_all

```c
struct swapi_films_all {
	int count;                             // Total Results Count
	const char *next;                      // Next URL
	const char *previous;                  // Previous URL
	struct swapi_films films[RESULTS_MAX]; // Films array
	int results_count;                     // Films array length
};
```

### <a name="swapi-starships-all"></a>struct swapi_starships_all

```c
struct swapi_starships_all {
	int count;                                     // Total Results Count
	const char *next;                              // Next URL
	const char *previous;                          // Previous URL
	struct swapi_starships starships[RESULTS_MAX]; // Starships array
	int results_count;                             // Starships array length
};
```

### <a name="swapi-vehicles-all"></a>struct swapi_vehicles_all

```c
struct swapi_vehicles_all {
	int count;                                   // Total Results Count
	const char *next;                            // Next URL
	const char *previous;                        // Previous URL
	struct swapi_vehicles vehicles[RESULTS_MAX]; // Vehicles array
	int results_count;                           // Vehicles array length
};
```

### <a name="swapi-species-all"></a>struct swapi_species_all

```c
struct swapi_species_all {
	int count;                                 // Total Results Count
	const char *next;                          // Next URL
	const char *previous;                      // Previous URL
	struct swapi_species species[RESULTS_MAX]; // Species array
	int results_count;                         // Species array length
};
```

### <a name="swapi-planets-all"></a>struct swapi_planets_all

```c
struct swapi_planets_all {
	int count;                                 // Total Results Count
	const char *next;                          // Next URL
	const char *previous;                      // Previous URL
	struct swapi_planets planets[RESULTS_MAX]; // Planets array
	int results_count;                         // Planets array length
};
```

## Methods Directory

To get a single result for a person, film, starship, vehicle, species, or planet:

* [swapi_get_person](#swapi-get-person)
* [swapi_get_film](#swapi-get-film)
* [swapi_get_starship](#swapi-get-starship)
* [swapi_get_vehicle](#swapi-get-vehicle)
* [swapi_get_species](#swapi-get-species)
* [swapi_get_planet](#swapi-get-planet)

The above methods, appended with `_url`, accept a `char *url` instead of `int id`, allowing one to pass a URL to it instead of an ID:

* [swapi_get_person_url](#swapi-get-person-url)
* [swapi_get_film_url](#swapi-get-film-url)
* [swapi_get_starship_url](#swapi-get-starship-url)
* [swapi_get_vehicle_url](#swapi-get-vehicle-url)
* [swapi_get_species_url](#swapi-get-species-url)
* [swapi_get_planet_url](#swapi-get-planet-url)

To get multiple results for people, films, starships, vehicles, species, or planets:

* [swapi_get_people_all](#swapi-get-people-all)
* [swapi_get_films_all](#swapi-get-films-all)
* [swapi_get_starships_all](#swapi-get-starships-all)
* [swapi_get_vehicles_all](#swapi-get-vehicles-all)
* [swapi_get_species_all](#swapi-get-species-all)
* [swapi_get_planets_all](#swapi-get-planets-all)

Same as the single results, one may pass a `char *url` to the following for multiple results:

* [swapi_get_people_all_url](#swapi-get-people-all-url)
* [swapi_get_films_all_url](#swapi-get-films-all-url)
* [swapi_get_starships_all_url](#swapi-get-starships-all-url)
* [swapi_get_vehicles_all_url](#swapi-get-vehicles-all-url)
* [swapi_get_species_all_url](#swapi-get-species-all-url)
* [swapi_get_planets_all_url](#swapi-get-planets-all-url)

Single results may be dumped:

* [swapi_dump_person](#swapi-dump-person)
* [swapi_dump_film](#swapi-dump-film)
* [swapi_dump_starship](#swapi-dump-starship)
* [swapi_dump_vehicle](#swapi-dump-vehicle)
* [swapi_dump_species](#swapi-dump-species)
* [swapi_dump_planet](#swapi-dump-planet)

Multiple results may also be dumped:

* [swapi_dump_people_all](#swapi-dump-people-all)
* [swapi_dump_films_all](#swapi-dump-films-all)
* [swapi_dump_starships_all](#swapi-dump-starships-all)
* [swapi_dump_vehicles_all](#swapi-dump-vehicles-all)
* [swapi_dump_species_all](#swapi-dump-species-all)
* [swapi_dump_planets_all](#swapi-dump-planets-all)

## Methods

### <a name="swapi-get-person"></a>swapi_get_person(struct swapi_people \*person, int id)

```c
struct swapi_people person;
swapi_get_person(&person, 1);
swapi_dump_person(person);
```

Returns:

```
Name:       Luke Skywalker
Height:     172
Mass:       77
...
```

### <a name="swapi-get-film"></a>void swapi_get_film(struct swapi_films \*film, int id)

```c
struct swapi_films film;
swapi_get_film(&film, 1);
swapi_dump_film(film);
```

Returns:

```
Episode ID:    4
Opening Crawl:
It is a period of civil war.
...
```

### <a name="swapi-get-starship"></a>void swapi_get_starship(struct swapi_starships \*starship, int id)

```c
struct swapi_starships starship;
swapi_get_starship(&starship, 2);
swapi_dump_starship(starship);
```

Returns:

```
Name:                   CR90 corvette
Model:                  CR90 corvette
Manufacturer:           Corellian Engineering Corporation
...
```

### <a name="swapi-get-vehicle"></a>void swapi_get_vehicle(struct swapi_vehicles \*vehicle, int id)

```c
struct swapi_vehicles vehicle;
swapi_get_vehicle(&vehicle, 4);
swapi_dump_vehicle(vehicle);
```

Returns:

```
Name:                   Sand Crawler
Model:                  Digger Crawler
Manufacturer:           Corellia Mining Corporation
```

### <a name="swapi-get-species"></a>void swapi_get_species(struct swapi_species \*species, int id)

```c
struct swapi_species species;
swapi_get_species(&species, 1);
swapi_dump_species(species);
```

Returns:

```
Name:             Human
Classification:   mammal
Designation:      sentient
```

### <a name="swapi-get-planet"></a>void swapi_get_planet(struct swapi_planets \*planet, int id)

```c
struct swapi_planets planet;
swapi_get_planet(&planet, 1);
swapi_dump_planet(planet);
```

Returns:

```
Name:            Tatooine
Rotation Period: 23
Orbital Period:  304
```

### <a name="swapi-get-person-url"></a>swapi_get_person_url(struct swapi_people \*person, char \*url)

```c
struct swapi_people person;
swapi_get_person_url(&person, "http://swapi.co/api/people/1/");
swapi_dump_person(person);
```

Returns:

```
Name:       Luke Skywalker
Height:     172
Mass:       77
...
```

### <a name="swapi-get-film-url"></a>void swapi_get_film_url(struct swapi_films \*film, char \*url)

```c
struct swapi_films film;
swapi_get_film_url(&film, "http://swapi.co/api/film/1/");
swapi_dump_film(film);
```

Returns:

```
Episode ID:    4
Opening Crawl:
It is a period of civil war.
...
```

### <a name="swapi-get-starship-url"></a>void swapi_get_starship_url(struct swapi_starships \*starship, char \*url)

```c
struct swapi_starships starship;
swapi_get_starship_url(&starship, "http://swapi.co/api/starship/2/");
swapi_dump_starship(starship);
```

Returns:

```
Name:                   CR90 corvette
Model:                  CR90 corvette
Manufacturer:           Corellian Engineering Corporation
...
```

### <a name="swapi-get-vehicle-url"></a>void swapi_get_vehicle_url(struct swapi_vehicles \*vehicle, char \*url)

```c
struct swapi_vehicles vehicle;
swapi_get_vehicle_url(&vehicle, "http://swapi.co/api/vehicle/4/");
swapi_dump_vehicle(vehicle);
```

Returns:

```
Name:                   Sand Crawler
Model:                  Digger Crawler
Manufacturer:           Corellia Mining Corporation
```

### <a name="swapi-get-species-url"></a>void swapi_get_species_url(struct swapi_species \*species, char \*url)

```c
struct swapi_species species;
swapi_get_species_url(&species, "http://swapi.co/api/species/1/");
swapi_dump_species(species);
```

Returns:

```
Name:             Human
Classification:   mammal
Designation:      sentient
```

### <a name="swapi-get-planet-url"></a>void swapi_get_planet_url(struct swapi_planets \*planet, char \*url)

```c
struct swapi_planets planet;
swapi_get_planet_url(&planet, "http://swapi.co/api/planets/1/");
swapi_dump_planet(planet);
```

Returns:

```
Name:            Tatooine
Rotation Period: 23
Orbital Period:  304
```

### <a name="swapi-get-people-all"></a>void swapi_get_people_all(struct swapi_people_all \*people, int id)

```c
struct swapi_people_all people;
swapi_get_people_all(&people, 1);
swapi_dump_people_all(people);
```

Returns:

```
Count:    82
Next:     http://swapi.co/api/people/?page=2
Previous:
...
```

### <a name="swapi-get-films-all"></a>void swapi_get_films_all(struct swapi_films_all \*films, int id)

```c
struct swapi_films_all films;
swapi_get_films_all(&films, 1);
swapi_dump_films_all(films);
```

Returns:

```
Count:    6
Next:
Previous:
...
```

### <a name="swapi-get-starships-all"></a>void swapi_get_starships_all(struct swapi_starships_all \*starships, int id)

```c
struct swapi_starships_all starships;
swapi_get_starships_all(&starships, 1);
swapi_dump_starships_all(starships);
```

Returns:

```
Count:    36
Next:     http://swapi.co/api/starships/?page=2
Previous:
...
```

### <a name="swapi-get-vehicles-all"></a>void swapi_get_vehicles_all(struct swapi_vehicles_all \*vehicles, int id)

```c
struct swapi_vehicles_all vehicles;
swapi_get_vehicles_all(&vehicles, 1);
swapi_dump_vehicles_all(vehicles);
```

Returns:

```
Count:    39
Next:     http://swapi.co/api/vehicles/?page=2
Previous:
...
```

### <a name="swapi-get-species-all"></a>void swapi_get_species_all(struct swapi_species_all \*species, int id)

```c
struct swapi_species_all species;
swapi_get_species_all(&species, 1);
swapi_dump_species_all(species);
```

Returns:

```
Count:    37
Next:     http://swapi.co/api/species/?page=2
Previous:
...
```

### <a name="swapi-get-planets-all"></a>void swapi_get_planets_all(struct swapi_planets_all \*planets, int id)

```c
struct swapi_planets_all planets;
swapi_get_planets_all(&planets, 1);
swapi_dump_planets_all(planets);
```

Returns:

```
Count:    60
Next:     http://swapi.co/api/planets/?page=2
Previous:
...
```

### <a name="swapi-get-people-all-url"></a>void swapi_get_people_all_url(struct swapi_people_all \*people, char \*url)

```c
struct swapi_people_all people;
swapi_get_people_all_url(&people, "http://swapi.co/api/people/");
swapi_dump_people_all(people);
```

Returns:

```
Count:    82
Next:     http://swapi.co/api/people/?page=2
Previous:
...
```

### <a name="swapi-get-films-all-url"></a>void swapi_get_films_all_url(struct swapi_films_all \*films, char \*url)

```c
struct swapi_films_all films;
swapi_get_films_all_url(&films, "http://swapi.co/api/films/");
swapi_dump_films_all(films);
```

Returns:

```
Count:    6
Next:
Previous:
...
```

### <a name="swapi-get-starships-all-url"></a>void swapi_get_starships_all_url(struct swapi_starships_all \*starships, char \*url)

```c
struct swapi_starships_all starships;
swapi_get_starships_all_url(&starships, "http://swapi.co/starships/");
swapi_dump_starships_all(starships);
```

Returns:

```
Count:    36
Next:     http://swapi.co/api/starships/?page=2
Previous:
...
```

### <a name="swapi-get-vehicles-all-url"></a>void swapi_get_vehicles_all_url(struct swapi_vehicles_all \*vehicles, char \*url)

```c
struct swapi_vehicles_all vehicles;
swapi_get_vehicles_all_url(&vehicles, "http://swapi.co/api/vehicles/");
swapi_dump_vehicles_all(vehicles);
```

Returns:

```
Count:    39
Next:     http://swapi.co/api/vehicles/?page=2
Previous:
...
```

### <a name="swapi-get-species-all-url"></a>void swapi_get_species_all_url(struct swapi_species_all \*species, char \*url)

```c
struct swapi_species_all species;
swapi_get_species_all_url(&species, "http://swapi.co/api/species/");
swapi_dump_species_all(species);
```

Returns:

```
Count:    37
Next:     http://swapi.co/api/species/?page=2
Previous:
...
```

### <a name="swapi-get-planets-all-url"></a>void swapi_get_planets_all_url(struct swapi_planets_all \*planets, char \*url)

```c
struct swapi_planets_all planets;
swapi_get_planets_all_url(&planets, "http://swapi.co/api/planets/");
swapi_dump_planets_all(planets);
```

Returns:

```
Count:    60
Next:     http://swapi.co/api/planets/?page=2
Previous:
...
```

### <a name="swapi-dump-person"></a>void swapi_dump_person(struct swapi_people \*person)

### <a name="swapi-dump-film"></a>void swapi_dump_film(struct swapi_films \*film)

### <a name="swapi-dump-starship"></a>void swapi_dump_starship(struct swapi_starships \*starship)

### <a name="swapi-dump-vehicle"></a>void swapi_dump_vehicle(struct swapi_vehicles \*vehicle)

### <a name="swapi-dump-species"></a>void swapi_dump_species(struct swapi_species \*species)

### <a name="swapi-dump-planet"></a>void swapi_dump_planet(struct swapi_planets \*planet)

### <a name="swapi-dump-people-all"></a>void swapi_dump_people_all(struct swapi_people_all \*people)

### <a name="swapi-dump-films-all"></a>void swapi_dump_films_all(struct swapi_films_all \*films)

### <a name="swapi-dump-starships-all"></a>void swapi_dump_starships_all(struct swapi_starships_all \*starships)

### <a name="swapi-dump-vehicles-all"></a>void swapi_dump_vehicles_all(struct swapi_vehicles_all \*vehicles)

### <a name="swapi-dump-species-all"></a>void swapi_dump_species_all(struct swapi_species_all \*species)

### <a name="swapi-dump-planets-all"></a>void swapi_dump_planets_all(struct swapi_planets_all \*planets)
