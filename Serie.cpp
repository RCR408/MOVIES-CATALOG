#include "Serie.h"
#include <string>

Serie::Serie(string na, string I, int tim, int indexG,int index) :VIDEO(na, I, tim, 0, indexG) {
	seasons = index;
	temp = {};
}

void Serie::DefineSerie() {
	int num;
	for (int i = 0; i < seasons; i++) {
		cout << endl << "Cuantos episodios tiene la temporada " << i+1 << ":";
		cin >> num;
		Temporada season(num);
		season.defineEpisodes();
		temp.push_back(season);
	}
}


float Serie::Average_Score() const {
	float sum = 0;
	int evaluaciones=0;
	for (int i = 0; i < seasons;i++) {
		vector<Episodio> templa = temp[i].GetChapters();
		for (int j = 0; j < templa.size(); j++) {
			sum = sum + templa[j].GetCalf();
			evaluaciones++;
		}
	}
	
	vector<float> tempCal = Get_Cal();

	if (tempCal.size() > 1) {
		for (int i = 1; i < tempCal.size(); i++) {
			sum += tempCal[i];
			evaluaciones++;
		}
	}

	return sum/evaluaciones;
}


std::string Serie::Get_Data() const{
	std::string ret = "";
	for (int i = 0; i < seasons; i++) {
		vector<Episodio> templa = temp[i].GetChapters();
		for (int j = 0; j < templa.size(); j++) {
			ret += "Serie: " + GetName() + ", Temporada: " + to_string(i + 1) + ", Capitulo " + to_string(j + 1) + ": " + templa[j].GetTitulo() + ", Calificacion Episodio: " + to_string(templa[j].GetCalf()) + "\n";
		}
	}

	ret += "Serie: " + GetName() + ", Temporadas: " + to_string(seasons) + ", Tiempo: " + to_string(GetTime()) + ", ID: " + GetID() + ", Calificacion Promedio: " + to_string(Average_Score());
	return ret;
}