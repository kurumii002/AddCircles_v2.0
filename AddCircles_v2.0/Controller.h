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
	 * @brief M�todo para agregar c�rculos al vector
	 * @param posX Coordenada X
	 * @param posY Coordenada Y
	*/
	void addCircle(int posX, int posY) {
		Random^ r = gcnew Random(); //genera aleatoriamente el tama�o de los circulos

		//se agrega el circulo al vector
		circles.push_back(new Circle(posX, posY, r->Next(1, 4), r->Next(1, 4), r->Next(10, 60), r->Next(0, 6)));
	}

	/**
	 * @brief M�todo que mueve los c�rculos por el canvas
	 * @param g El canvas
	*/
	void moveCircles(Graphics^ g) {
		for each (Circle * c in circles) { //recorre cada circulo y hace la misma accion para todos
			c->move(g);
			c->draw(g);
		}
	}

	/**
	 * @brief M�todo que obtiene la cantidad de c�rculos en el canvas
	 * @return La cantidad de c�rculos
	*/
	int getNumberOfCircles() {
		return circles.size();
	}
};