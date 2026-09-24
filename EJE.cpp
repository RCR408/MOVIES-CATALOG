
#include <iostream>
#include "VIDEO.h"
#include "Movies.h"
#include "Serie.h"
#include <string>
#include "Funciones.h"
 

int main()
{
	vector<VIDEO*> base_De_Datos;
	Funciones utilidades;
	using namespace std;

	while (true)
	{
		int indexN = 0;
		cout<<endl << "Escoge que quieres hacer\n1.Mostrar un video en especifico\n2.Mostrar Videos del mismo genero\n3.Videos con calificaciones cercanas\n4.Agregar videos\n5.Calificar Videos\n6.Salir" << endl;
		cin >> indexN;
		while (indexN < 1 || indexN>6) {
			cout << endl<<"Escoge un index valido\n1.Mostrar un video en especifico\n2.Mostrar videos del mismo genero\n3.Videos con calificaciones cercanas\n4.Agregar videos\n5.Calificar Video\n6.Salir" << endl;
			cin >> indexN;
		}
		if (indexN == 6) {
			break;
		}
		switch (indexN) {
		case 1:
			if (base_De_Datos.size() == 0) {
				cout << "No tiene datos" << endl; break;
			}
			else {
				try {
					int indexBase = 0;
					cout << endl << "Cual es el ID/Index de la pelicula:";
					cin >> indexBase;
					if (indexBase >= base_De_Datos.size()) {
						throw "Index invalido"; 
					}
					cout << endl << *base_De_Datos[abs(indexBase)] << endl; break;
				}
				catch (const char* t) {
					cerr << t;
				}
				break;
			}
		case 2:
			cout << endl << utilidades.VideosMismoGenero(base_De_Datos) << endl; break;
		case 3:
			cout << endl << utilidades.VideosRangoDeCalif(base_De_Datos); break;
		case 4: {
			int size;
			cout << "El size de tu base de datos es:";
			cin >> size;

			int sizeBaseDeDatos = base_De_Datos.size();

			for (int i = sizeBaseDeDatos; i < sizeBaseDeDatos+size; i++) {
				bool serieOpelicula = 1;
				string tempName = "";
				float tempCal = 0;
				int tempIndex = 0;
				int tim = 0;

				cout << endl << "Es una pelicula(Pon un 1) es una serie(Escribe un 0):";
				cin >> serieOpelicula;

				if (serieOpelicula) {
					cout << endl << "Dame el nombre de tu pelicula:";
					cin >> ws;
					getline(cin, tempName);
					cout << endl << "Escoge un index dependiendo del genero\n1.Terror\n2.Comedia\n3.Romance\n4.Accion\n5.Infantil\n6.Fantasia\n7.Drama\n8.Basado en hechos reales\n";
					cin >> tempIndex;

					try {
						if (tempIndex > 8 || tempIndex < 1) {
							throw "Fuera de el index";
						}
						cout << endl << "Tiempo de duracion de tu pelicula:";
						cin >> tim;
						cout << endl << "Calificacion a esta pelicula:";
						cin >> tempCal;
						Movies* temp = new Movies(tempName, to_string(i), tim, tempCal, tempIndex);
						base_De_Datos.push_back(temp);
					}
					catch (const char* td) {
						cerr << td;
					}
				}
				else {
					int tempSeasons;
					cout << endl << "Dame el nombre de tu serie:";
					cin >> ws;
					getline(cin, tempName);
					cout << endl << "Escoge un index dependiendo del genero\n1.Terror\n2.Comedia\n3.Romance\n4.Accion\n5.Infantil\n6.Fantasia\n7.Drama\n8.Basado en hechos reales\n";
					cin >> tempIndex;
					try {
						if (tempIndex > 8 || tempIndex < 1) {
							throw "Fuera de el index";
						}
						cout << endl << "Tiempo de duracion de tu serie:";
						cin >> tim;
						cout << endl << "Numero de temporadas:";
						cin >> tempSeasons;

						Serie* temp = new Serie(tempName, to_string(i), tim, tempIndex, tempSeasons);
						temp->DefineSerie();

						base_De_Datos.push_back(temp);
					}
					catch (const char* td) {
						cerr << td;
					}
				}
			}break;
		}
		case 5: {
			int indexC = 0;
			cout << endl << "Dame el index de la pelicula a calificar:";
			cin >> indexC;

			float newCal = 0;
			cout << endl << "El titulo:" << base_De_Datos[indexC]->GetName() << ", cuanta calidficacion le das:";
			cin >> newCal;
			base_De_Datos[indexC]->Set_Score(newCal); break;
		}

		case 6:
			break;
		}
		


	}
	return 0;
}



