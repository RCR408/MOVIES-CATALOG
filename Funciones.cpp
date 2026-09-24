#include "Funciones.h"
#include <string>
using namespace std;

string Funciones::VideosMismoGenero(vector<VIDEO*> v) {
	int sum = 0;
	int index = 0;
	string ret = "";
	std::cout << "Dame el index del genero los videos que quieras buscar \n1.Terror\n2.Comedia\n3.Romance\n4.Accion\n5.Infantil\n6.Fantasia\n7.Drama\n8.Basado en hechos reales\n";
	cin >> index;

	for (int i = 0; i < v.size(); i++) {
		if (v[i]->GetIndexGen() == index - 1) {
			sum += 1;
			ret += "El Index De los videos son:" + v[i]->GetID() + "\n";
		}
	}

	ret += "La cantidad de Videos de este Genero:" + to_string(sum);
	return ret;
}

string Funciones::VideosRangoDeCalif(vector<VIDEO*> v) {
	int sum = 0;
	float indexMin = 0;
	float indexMax = 1;
	string ret = "";
	std::cout << "Dame el rango minimo de la calificacion de los videos que quieras buscar:";
	cin >> indexMin;
	std::cout << "Dame el rango maximo de la calificacion de los videos que quieras buscar:";
	cin >> indexMax;

	try {
		if (indexMin > indexMax || indexMin < 0 || indexMax < 0 || indexMin>5 || indexMax>5)
			throw "Index incorrectos";
		for (int i = 0; i < v.size(); i++) {
			if (v[i]->Average_Score() >= indexMin && v[i]->Average_Score() <= indexMax) {
				sum += 1;
				ret += "El Index De los videos son:" + v[i]->GetID() + "\n";
			}
		}
		ret += "La cantidad de Videos de este rango de calificaciones:" + to_string(sum);
		return ret;
	}
	catch (const char* td) {
		cerr << td;
		return "Index incorrectos";
	}
}
