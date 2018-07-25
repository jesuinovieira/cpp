#include "../header/IA.hpp"

//_________________________________________________________________________________________________________________________________

IA::IA() :	Jogador::Jogador() 
{
	setNome("Computador");
}
//_________________________________________________________________________________________________________________________________


//_________________________________________________________________________________________________________________________________

IA::~IA()
{
	//
}
//_________________________________________________________________________________________________________________________________


//_________________________________________________________________________________________________________________________________

void IA::getTiros(int* x, int* y, bool _IA)
{
	if(!_IA || lTirosVazia())	tiroAleatorio(x, y, _IA);
	
	else
	{
		int xx = 0, yy = 0;
		Coordenadas tmp;

		tmp = _lTiros.front();			// Pega o primeiro elemento da lista
		tmp.getXY(&xx, &yy);			// Pega as coordenadas
		_lTiros.pop_front();			// Remove o primeiro elemento da lista
	
		*x = xx;
		*y = yy;
	}
}
//_________________________________________________________________________________________________________________________________


//_________________________________________________________________________________________________________________________________

void IA::tiroAleatorio(int* xx, int* yy, bool _IA)
{
    std::random_device gerador;

    std::uniform_int_distribution<std::size_t> x(0, 14); 	// Coordenada x
	std::uniform_int_distribution<std::size_t> y(0, 14);	// Coordenada y

	*xx = x(gerador);
	*yy = y(gerador);

	// Caso negue a paridade e IA esteja ativada, chama novamente esta função
	if(_IA)
		if(!confereParidade(*xx, *yy))
			tiroAleatorio(xx, yy, _IA);
}
//_________________________________________________________________________________________________________________________________


//_________________________________________________________________________________________________________________________________

bool IA::confereParidade(int x, int y)
{
	/* Se os dois são pares, ou se os dois são ímpares, retorna true. */
	if(x % 2 == 0 && y % 2 == 0) return true;
	if(x % 2 != 0 && y % 2 != 0) return true;

	return false;
}
//_________________________________________________________________________________________________________________________________


//_________________________________________________________________________________________________________________________________

void IA::insereTiro(int x, int y)	// Recebe a coordenada PRONTA para a inserção.
{
	Coordenadas tmp(x, y);

	// Se o tiro não esta na lista, insere
	if( !tiroRepetido(x, y) )
		_lTiros.push_back(tmp);
}
//_________________________________________________________________________________________________________________________________


//_________________________________________________________________________________________________________________________________

bool IA::tiroRepetido(int xx, int yy)
{
	/* Percorrendo a lista e verifica se esse tiro já foi inserido */
	int x = 0, y = 0;
	for(std::list<Coordenadas>::iterator it = _lTiros.begin(); it != _lTiros.end(); ++it)
	{
		Coordenadas tmp = *it;
		tmp.getXY(&x, &y);

		if(x == xx && y == yy)	return true;	// Retorna true, o tiro é repetido
	}
								return false;	// Retorna false, o tiro não é repetido
}
//_________________________________________________________________________________________________________________________________


//_________________________________________________________________________________________________________________________________

bool IA::getInteligencia() const
{
	return _inteligencia;
}
//_________________________________________________________________________________________________________________________________


//_________________________________________________________________________________________________________________________________

bool IA::lTirosVazia() const
{
	return _lTiros.size() == 0;
}
//_________________________________________________________________________________________________________________________________


//_________________________________________________________________________________________________________________________________

void IA::esvaziarlTiros()
{
	_lTiros.clear();
}
//_________________________________________________________________________________________________________________________________