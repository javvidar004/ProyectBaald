#pragma once
#include "Personaje.h"

class Ladron : public Personaje
{
public:
	Ladron(string, string, string, string, int);
	~Ladron();

	void CompraEquipo();
	void GastarPuntosDeHabilidad();
	Equipamiento getEquipo(int);
	Habilidades getHabilidades(int);
	Items getItems(int);
	void setEquipamiento(int, bool, bool);
	void setHabilidades(int, bool, int);
	void setItems(int, int);
	void UsarItem1();
	void UsarItem2();
	void habilidad1();
	void habilidad2();
	void habilidad3();
	void eliminarHabilidad1();
	void eliminarHabilidad2();
	void eliminarHabilidad3();
	void AumDañoEquip();
	void RedDañoEquip();
	void CambioDeEquipo(int);

private:
	Equipamiento _equip[9];
	Habilidades _habil[3];
};
