# Star Wars API

A Node.js script that fetches and displays all characters from a Star Wars movie using the Star Wars API.

## Description

This script connects to the [Star Wars API](https://swapi-api.hbtn.io/) to retrieve character information for any Star Wars movie. It takes a movie ID as input and prints all character names in the same order as they appear in the movie's character list.

## Features

- Fetches movie data from the Star Wars API
- Retrieves character information for each character in the movie
- Maintains the original order of characters as specified by the API
- Handles asynchronous requests efficiently using Promises
- Provides proper error handling for network and parsing errors

## Requirements

- Node.js (version 14 or higher)
- `request` module

## Installation

1. Clone or download this repository
2. Install dependencies:
   ```bash
   npm install request
   ```

## Usage

```bash
node 0-starwars_characters.js <movie_id>
```

### Parameters

- `movie_id`: The ID of the Star Wars movie (1-7)

### Movie IDs Reference

| ID | Movie Title |
|----|-------------|
| 1  | A New Hope |
| 2  | The Empire Strikes Back |
| 3  | Return of the Jedi |
| 4  | The Phantom Menace |
| 5  | Attack of the Clones |
| 6  | Revenge of the Sith |
| 7  | The Force Awakens |

## Examples

### Get characters from "Return of the Jedi" (Movie ID 3)

```bash
node 0-starwars_characters.js 3
```

**Output:**
```
Luke Skywalker
C-3PO
R2-D2
Darth Vader
Leia Organa
Obi-Wan Kenobi
Chewbacca
Han Solo
Jabba Desilijic Tiure
Wedge Antilles
Yoda
Palpatine
Boba Fett
Lando Calrissian
Ackbar
Mon Mothma
Arvel Crynyd
Wicket Systri Warrick
Nien Nunb
Bib Fortuna
```

### Get characters from "A New Hope" (Movie ID 1)

```bash
node 0-starwars_characters.js 1
```

## API Endpoints Used

- **Movie Data**: `https://swapi-api.hbtn.io/api/films/{movie_id}`
- **Character Data**: Individual character URLs from the movie's character list

## Technical Details

- Uses ES6 modules (`import` syntax)
- Implements Promise-based request handling for proper async/await patterns
- Maintains character order using `Promise.all()` to wait for all requests
- Includes comprehensive error handling for network and JSON parsing errors

## Error Handling

The script handles various error scenarios:
- Network connection errors
- Invalid movie IDs
- JSON parsing errors
- Individual character request failures

## Dependencies

- `request`: HTTP client for making API requests
- `semistandard`: Code linting and formatting

## License

This project is part of the Holberton School curriculum.
