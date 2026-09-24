#include "Temporada.h"
#include <iostream>
#include <string>

Temporada::Temporada() {
	episodios = { Episodio() };
	chaptersForSeason = 0;
}

Temporada::Temporada(int episode) {
	chaptersForSeason = episode;
	episodios = {};
}

void Temporada::defineEpisodes() {
	string name = "";
	float cal = 0.0f;

	for (int i = 0; i < chaptersForSeason; i++) {
		cout <<endl<< "Dame el nombre del episodio numero" << i + 1 << " :";
		cin >> ws;
		getline(cin, name);
		cout << endl << "Dame su calificacion:";
		cin >> cal;

		episodios.push_back(Episodio(name, cal));
	}
}

vector<Episodio> Temporada::GetChapters() const{
	return episodios;
}