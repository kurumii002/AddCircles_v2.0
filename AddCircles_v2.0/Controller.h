#pragma once
#include "Circle.h"
#include <vector>

using namespace System::Drawing;
using namespace System;
using namespace std;

class Controller {
private:
	vector<Circle*> circles; //vector que guarda muchos circulos

public:
	Controller() { }
	~Controller() { }

	/**
	 * @brief Método para agregar círculos al vector
	 * @param posX Coordenada X
	 * @param posY Coordenada Y
	*/
	void addCircle(int posX, int posY) {
		Random^ r = gcnew Random(); //genera aleatoriamente el tamaño de los circulos

		//se agrega el circulo al vector
		circles.push_back(new Circle(posX, posY, r->Next(1, 4), r->Next(1, 4), r->Next(10, 60), r->Next(0, 6)));
	}

	/**
	 * @brief Método que mueve los círculos por el canvas
	 * @param g El canvas
	*/
	void moveCircles(Graphics^ g) {
		for each (Circle * c in circles) { //recorre cada circulo y hace la misma accion para todos
			c->move(g);
			c->draw(g);
		}
	}

	/**
	 * @brief Método que obtiene la cantidad de círculos en el canvas
	 * @return La cantidad de círculos
	*/
	int getNumberOfCircles() {
		return circles.size();
	}
};