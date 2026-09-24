#pragma once
#include "VIDEO.h"
#include "Temporada.h"
#include <iostream>
#include <vector>

class Serie:public VIDEO
{
private:
	int seasons;
	vector<Temporada> temp;
public:
	Serie(std::string, std::string, int, int,int);
	void DefineSerie();
	float Average_Score() const;
	std::string Get_Data() const;
};

