#include "Episodio.h"
#include <iostream>

using namespace std;

Episodio::Episodio() {
	tituloCap = "No title";
	calificacion = 0;
}

Episodio::Episodio(string name,float cal) {
	if (cal > 5)
		cal = 5;
	else if (cal < 0)
		cal = 0;
	calificacion = cal;

	tituloCap = name;

}

string Episodio::GetTitulo() {
	return tituloCap;
}


float Episodio::GetCalf() {
	return calificacion;
}