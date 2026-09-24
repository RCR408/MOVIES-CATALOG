# MOVIES CATALOG

An object-oriented video catalog system in C++ for adding, rating, and filtering movies and TV series.

## Features
- Add movies and series to a catalog, each with genre and rating data
- Rate videos and filter the catalog by genre or by a rating range
- Handles series specifically: each series holds multiple seasons, and each season holds multiple episodes
- Validates user input and handles invalid operations through exceptions instead of crashing

## Tech Stack
- **Language:** C++
- **Core concepts:** abstraction, inheritance, polymorphism, operator overloading, exception handling

## How It's Structured
- `VIDEO` is an abstract base class with pure virtual functions (`Average_Score`, `Get_Data`), so it can't be instantiated directly — it only defines the shared interface.
- `Movies` and `Serie` both inherit from `VIDEO` and implement those functions in their own way.
- `Serie` is composed of a list of `Temporada` (season) objects, each of which holds a list of `Episodio` (episode) objects.
- The `<<` operator is overloaded so any video object (movie or series) can be printed in a consistent format regardless of its actual type — a practical example of polymorphism.
- The catalog itself is stored as a dynamic collection of pointers to `VIDEO`, so movies and series can be mixed together and processed through the same interface.

## Status
Coursework project focused on object-oriented design in C++: abstract classes, inheritance, polymorphism, and exception handling.
