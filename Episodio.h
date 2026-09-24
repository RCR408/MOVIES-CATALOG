#pragma once
#include <iostream>
class Episodio
{
private:
	std::string tituloCap;
	float calificacion;
public:
	Episodio();
	Episodio(std::string, float);
	std::string GetTitulo();
	float GetCalf();
};

