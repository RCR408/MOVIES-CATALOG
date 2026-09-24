#include "Movies.h"
#include <iostream>
#include <string>
using namespace std;

Movies::Movies():VIDEO() {}

Movies::Movies(string na, string I, int tim, float cal, int indexG) :VIDEO(na, I, tim, cal, indexG) {}

float Movies::Average_Score() const {
	vector<float> temp = Get_Cal();

	float sum = 0;

	for (int i = 0; i < temp.size(); i++) {
		sum += temp[i];
	}

	sum /= temp.size();

	return sum;
}

string Movies::Get_Data() const {
	return "Pelicula: " + GetName() + ", Tiempo: " + to_string(GetTime()) + ", ID:" + GetID() + ", Genero:" + GetGender()+", Calificaciones: " + to_string(Average_Score());
}


