#include "../header/Coordenadas.hpp"

//_________________________________________________________________________________________________________________________________

Coordenadas::Coordenadas()
{

}
//_________________________________________________________________________________________________________________________________


//_________________________________________________________________________________________________________________________________

Coordenadas::Coordenadas(int x, int y) : _x(x), _y(y)
{

}
//_________________________________________________________________________________________________________________________________


//_________________________________________________________________________________________________________________________________

Coordenadas::~Coordenadas()
{

}
//_________________________________________________________________________________________________________________________________



//_________________________________________________________________________________________________________________________________

int Coordenadas::getX() const
{
	return _x;
}
//_________________________________________________________________________________________________________________________________


//_________________________________________________________________________________________________________________________________

int Coordenadas::getY() const
{
	return _y;
}
//_________________________________________________________________________________________________________________________________


//_________________________________________________________________________________________________________________________________

void Coordenadas::getXY(int* x, int* y) const
{
	*x = _x;
	*y = _y;
}
//_________________________________________________________________________________________________________________________________


//_________________________________________________________________________________________________________________________________

void Coordenadas::setX(int x)
{
	_x = x;
}
//_________________________________________________________________________________________________________________________________


//_________________________________________________________________________________________________________________________________

void Coordenadas::setY(int y)
{
	_y = y;
}
//_________________________________________________________________________________________________________________________________


//_________________________________________________________________________________________________________________________________

void Coordenadas::setXY(int x, int y)
{
	_x = x;
	_y = y;
}
//_________________________________________________________________________________________________________________________________