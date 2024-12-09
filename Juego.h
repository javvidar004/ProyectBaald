#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Guerrero.h"
#include "Arquero.h"
#include "Mago.h"
#include "Ladron.h"
#include "Enemigo.h"

using namespace std;

class Juego
{
public:
	Juego();
	~Juego();
	void MenuInicial();

private:
	string nombrePartida;
	Personaje* miPersonaje;
	void MenuPrincipal();
	void CrearPartida();
	void CargarPartida();
	void GuardarPartida();
	void MenuDeJuego();
	void IrAventura();
	void Batalla(vector<Enemigo>, Estadisticas&);
	void MenuPelea(vector<Enemigo>&, Estadisticas&);
	int CantidadDeDaño(vector<Enemigo>, int);
	int CantidadDeDaño();
	void Atacar(vector<Enemigo>&, Estadisticas&);
	void DañarEnemigos(vector<Enemigo>&, Estadisticas&, int, int);
	void UsarHabilidades();
	void DañoEnemigosHabilidad3(vector<Enemigo>&, Estadisticas&);
	void UsarItems();
	void DatosDePelea(vector<Enemigo>&);
	int AtaqueEnemigos(vector<Enemigo>&);
	vector<Enemigo> CrearEnemigos(int);
	vector<Enemigo> crearJefe(int);
	int nivelEnemigos(int);
	int CantidaddeEnemigos(int);
	void muertePersonaje(Estadisticas&);
	void eliminarHabilidades();

	Personaje* CrearPersonaje();
	Personaje* CargarPersonaje(vector<string>&);

	void CambioDeNivel();
	void LimpiarPantalla();
	void pausa_con_enter();
	bool StringtoBool(string);
};
