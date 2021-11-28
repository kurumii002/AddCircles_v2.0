#pragma once
using namespace System::Drawing;

class Circle {
private:
	int x, y; //coordenadas
	int dx, dy; //desplazamiento
	int color;
	int radio;

public:
	/**
	 * @brief 
	*/

	/**
	 * @brief Constructor del Círculo, inicializa sus atributos
	 * @param x Coordenada X
	 * @param y Coordenada Y
	 * @param dx Desplazamiento en X
	 * @param dy Desplazamiento en Y
	 * @param radio Radio del círclo
	 * @param color Color del círculo (0:rojo, 1:azul, 2:violeta, 3:naranja, 4:cyan, 5:verde claro)
	*/
	Circle(int x, int y, int dx, int dy, int radio, int color) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->radio = radio;
		this->color = color;
	}

	/**
	 * @brief Mueve el círculo en el canvas
	 * @param g El canvas
	*/
	void move(Graphics^ g) {
		//valida que la figura no pase de los limites del canvas
		//(limite IZQ) (limite DER)
		//(dx-  (<-) ) (dx+  (->) )
		if (x + dx < 1 || x + dx + radio > g->VisibleClipBounds.Width) {
			dx = dx * -1; //cambia la direccion de desplazamiento
		}

		//(limite SUP)  (limite INF)
		//(dy-  (^) )   (dy+  (v) )
		if (y + dy < 1 || y + dy + radio > g->VisibleClipBounds.Height) {
			dy = dy * -1;
		}

		//mueve el círculo (coordenadas + desplazamiento)
		x += dx;
		y += dy;

		//dibuja el círculo
		draw(g);
	}

	/**
	 * @brief Método que dibujar el círculo en el canvas
	 * @param g El canvas
	*/
	void draw(Graphics^ g) {
		switch (color) {
		case 0:
			g->FillEllipse(Brushes::Red, x - radio, y - radio, radio * 2, radio * 2);
			break;
		case 1:
			g->FillEllipse(Brushes::Blue, x - radio, y - radio, radio * 2, radio * 2);
			break;
		case 2:
			g->FillEllipse(Brushes::Violet, x - radio, y - radio, radio * 2, radio * 2);
			break;
		case 3:
			g->FillEllipse(Brushes::Orange, x - radio, y - radio, radio * 2, radio * 2);
			break;
		case 4:
			g->FillEllipse(Brushes::Cyan, x - radio, y - radio, radio * 2, radio * 2);
			break;
		case 5:
			g->FillEllipse(Brushes::Lime, x - radio, y - radio, radio * 2, radio * 2);
			break;
		}
	}
};