#pragma once
#include "VIDEO.h"
#include <iostream>
class Movies:public VIDEO
{
private: 
public:
	Movies();
	Movies(std::string, std::string, int, float, int);
	float Average_Score() const;
	std::string Get_Data() const;
};


