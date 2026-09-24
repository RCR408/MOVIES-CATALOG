#include "VIDEO.h"
#include "string.h"
#include <string>
using namespace std;

VIDEO::VIDEO() {
	name = "";
	ID = "";
	time = 0;
	Gender = allGenders[0];
	calf = {0};
	genDex = 0;
}

VIDEO::VIDEO(string na, string I, int tim, float cal,int indexG) {
	if (cal > 5)
		cal = 5;
	else if (cal < 0)
		cal = 0;
	name = na;
	ID = I;
	time = tim;
	genDex = indexG - 1;
	Gender = allGenders[genDex];
	calf = {abs(cal)};
}

int VIDEO::GetIndexGen() {
	return genDex;
}

vector<float> VIDEO::Get_Cal() const{
	return calf;
}

void VIDEO::Set_Score(float s) {
	if (s > 5)
		s = 5;
	else if (s < 0)
		s = 0;
	calf.push_back(abs(s));
}

string VIDEO::GetGender() const {
	return Gender;
}

string VIDEO::GetID() const{
	return ID;
}

int VIDEO::GetTime() const{
	return time;
}

string VIDEO::GetName() const{
	return name;
}

std::ostream& operator<<(std::ostream& m, const VIDEO& v) {
	m << v.Get_Data();
	return m;
}