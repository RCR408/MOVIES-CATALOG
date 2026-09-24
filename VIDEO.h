#pragma once
#include <iostream>
#include <vector>
class VIDEO
{
private:
	std::string name;
	std::string ID;
	int time;
	int genDex;
	std::string Gender;
	std::string allGenders[8] = {"Terror","Comedia","Romance","Acción","Infantil","Fantasia","Drama","Basada en hechos reales"};
	std::vector<float> calf;
public:
	VIDEO();
	VIDEO(std::string, std::string, int, float,int);
	void Set_Score(float);
	std::vector<float> Get_Cal() const;
	std::string GetGender() const;
	std::string GetID() const;
	std::string GetName() const;
	int GetTime() const;
	int GetIndexGen();
	virtual float Average_Score() const=0;
	virtual std::string Get_Data() const = 0; 
};

std::ostream& operator<<(std::ostream&, const VIDEO&);
