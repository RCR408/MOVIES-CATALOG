#pragma once
#include <iostream>
#include "Episodio.h"
#include <vector>

using namespace std;

class Temporada
{
private:
	vector<Episodio> episodios;
	int chaptersForSeason;
public:
	Temporada();
	Temporada(int);
	void defineEpisodes();
	vector<Episodio> GetChapters() const;
};

