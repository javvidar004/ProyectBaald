#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Estadisticas {
	int victorias;
	int muertes;
	int EnemigosEliminados;
	int DañoCausado;
	int DañoRecibido;
};

struct Equipamiento {
	string nombre;
	int costo;
	double cambioDaño;
	bool desbloqueado;
	bool enUso;
	char tipo;
};

struct Habilidades {
	string nombre;
	int costo;
	bool disponible;
	bool enUso;
	int turnosRestantes;
};

struct Items {
	string nombre;
	int costo;
	int cantidad;
};

class Personaje
{
public:
	Personaje(string, string, string, string, int);
	virtual ~Personaje();
	int getClase();
	string getNombre();
	string getGenero();
	string getRaza();
	string getOrientacion();
	int getVida();
	int getMana();
	int getExp();
	int getNivel();
	double getOro();
	int getPuntosDeHabilidad();
	double getAumentoDaño();
	double getReduccionDaño();
	int getSaltarTurno();
	int getFuerza();
	int getIntelecto();
	int getAgilidad();

	void setClase(int);
	void setNombre(string);
	void setGenero(string);
	void setRaza(string);
	void setOrientacion(string);
	void setVida(int);
	void setMana(int);
	void setExp(int);
	void setNivel(int);
	void setOro(double);
	void setPuntosDeHabilidad(int);
	void setAumentoDaño(double);
	void setReduccionDaño(double);
	void setSaltarTurno(int);

	void aumentarFuerza();
	void aumentarIntelecto();
	void aumentarAgilidad();

	void ReSetVida();
	int getVidaMax();

	void VerEstadisticas();
	void ActualizarEstadisticas(Estadisticas);
	void setEstadisticas(int, int, int, int, int);
	virtual void setEquipamiento(int, bool, bool);
	virtual void setHabilidades(int, bool, int);
	virtual void setItems(int, int);
	virtual void UsarItem1();
	virtual void UsarItem2();
	virtual void habilidad1();
	virtual void eliminarHabilidad1();
	virtual void habilidad2();
	virtual void eliminarHabilidad2();
	virtual void habilidad3();
	virtual void eliminarHabilidad3();
	Estadisticas getEstadisticas();
	virtual void AumDañoEquip();
	virtual void RedDañoEquip();
	virtual void CambioDeEquipo(int);

	virtual void CompraEquipo();
	virtual void GastarPuntosDeHabilidad();
	virtual Equipamiento getEquipo(int);
	virtual Habilidades getHabilidades(int);
	virtual Items getItems(int);

	void pausa_con_enter();


private:
	string _nombre;
	string _genero;
	string _raza;
	string _orientacion;
	int _clase;
	int _vida;
	int _mana;
	int _exp;
	double _oro;
	int _nivel;
	int _puntosDeHabilidad;
	int _nivelMaxVida;
	int saltarTurno;
	int intelecto;
	int fuerza;
	int agilidad;
	double AumentoDaño;
	double ReduccionDaño;
	Estadisticas _stats;

protected:
	Items _items[2];
};

