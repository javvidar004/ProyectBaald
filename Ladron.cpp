#include "Ladron.h"

/// <summary>
/// Constructor de la clase Ladron.
/// </summary>
/// <param name="nombre">Nombre del ladr�n</param>
/// <param name="genero">G�nero del ladr�n</param>
/// <param name="raza">Raza del ladr�n</param>
/// <param name="orientacion">Orientaci�n del ladr�n</param>
/// <param name="clase">Clase del ladr�n</param>
Ladron::Ladron(string nombre, string genero, string raza, string orientacion, int clase) : Personaje(nombre, genero, raza, orientacion, clase)
{
	//A = : Armadura, B = Arma, C = Botas, D = Amuleto, E = Casco.

	// Inicializaci�n del equipamiento y habilidades del ladr�n.
	_equip[0].nombre = "Daga";
		_equip[0].costo = 0;
		_equip[0].desbloqueado = true;
		_equip[0].enUso = true;
		_equip[0].tipo = 'B';
		_equip[0].cambioDa�o = 0.0;
	_equip[1].nombre = "Dagas Gemelas";
		_equip[1].costo = 500;
		_equip[1].desbloqueado = false;
		_equip[1].enUso = false;
		_equip[1].tipo = 'B';
		_equip[1].cambioDa�o = 0.2;
	_equip[2].nombre = "Capa Sombr�a";
		_equip[2].costo = 600;
		_equip[2].desbloqueado = false;
		_equip[2].enUso = false;
		_equip[2].tipo = 'A';
		_equip[2].cambioDa�o = 0.1;
	_equip[3].nombre = "Gancho de Escalada";
		_equip[3].costo = 550;
		_equip[3].desbloqueado = false;
		_equip[3].enUso = false;
		_equip[3].tipo = 'D';
		_equip[3].cambioDa�o = 0.2;
	_equip[4].nombre = "Botas de Ladr�n";
		_equip[4].costo = 450;
		_equip[4].desbloqueado = false;
		_equip[4].enUso = false;
		_equip[4].tipo = 'C';
		_equip[4].cambioDa�o = 0.1;
	_equip[5].nombre = "Botas del Jefe";
		_equip[5].costo = 750;
		_equip[5].desbloqueado = false;
		_equip[5].enUso = false;
		_equip[5].tipo = 'C';
		_equip[5].cambioDa�o = 0.2;
	_equip[6].nombre = "T�nica de Sigilo";
		_equip[6].costo = 800;
		_equip[6].desbloqueado = false;
		_equip[6].enUso = false;
		_equip[6].tipo = 'A';
		_equip[6].cambioDa�o = 0.2;
	_equip[7].nombre = "Cimitarra";
		_equip[7].costo = 650;
		_equip[7].desbloqueado = false;
		_equip[7].enUso = false;
		_equip[7].tipo = 'B';
		_equip[7].cambioDa�o = 0.3;
	_equip[8].nombre = "M�scara de Bandido";
		_equip[8].costo = 550;
		_equip[8].desbloqueado = false;
		_equip[8].enUso = false;
		_equip[8].tipo = 'E';
		_equip[8].cambioDa�o = 0.3;

	_habil[0].nombre = "Bola de Fuego";
		_habil[0].costo = 5;
		_habil[0].disponible = false;
		_habil[0].enUso = false;
		_habil[0].turnosRestantes = 0;
	_habil[1].nombre = "Rayo de Hielo";
		_habil[1].costo = 15;
		_habil[1].disponible = false;
		_habil[1].enUso = false;
		_habil[1].turnosRestantes = 0;
	_habil[2].nombre = "Fuego Radiante";
		_habil[2].costo = 24;
		_habil[2].disponible = false;
		_habil[2].enUso = false;
		_habil[2].turnosRestantes = 0;

		_items[0].nombre = "Hierbas medicinales";
		_items[0].costo = 25;
		_items[0].cantidad = 0;
		_items[1].nombre = "Elixir de las Hadas";
		_items[1].costo = 35;
		_items[1].cantidad = 0;
}

Ladron::~Ladron()
{
}

/// <summary>
/// M�todo para que el personaje compre su equipamiento correspondiente.
/// </summary>
void Ladron::CompraEquipo()
{
	int opcion;
	cout << "Oro Disponible: " << getOro() << endl
		<< "Articulos: " << endl
		<< "1. " << _equip[1].nombre << "  (" << _equip[1].costo << "pts)" << endl
		<< "2. " << _equip[2].nombre << "  (" << _equip[2].costo << "pts)" << endl
		<< "3. " << _equip[3].nombre << "  (" << _equip[3].costo << "pts)" << endl
		<< "4. " << _equip[4].nombre << "  (" << _equip[4].costo << "pts)" << endl
		<< "5. " << _equip[5].nombre << "  (" << _equip[5].costo << "pts)" << endl
		<< "6. " << _equip[6].nombre << "  (" << _equip[6].costo << "pts)" << endl
		<< "7. " << _equip[7].nombre << "  (" << _equip[7].costo << "pts)" << endl
		<< "8. " << _equip[8].nombre << "  (" << _equip[8].costo << "pts)" << endl
		<< "Items:" << endl
		<< "9. " << _items[0].nombre << "  (" << _items[0].costo << "pts)" << endl
		<< "10. " << _items[1].nombre << "  (" << _items[1].costo << "pts)" << endl
		<< "Seleccione lo que desea comprar(1-10): ";
	cin >> opcion;
	switch (opcion)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
		if (_equip[opcion].desbloqueado == true && _equip[opcion].enUso == false) {
			CambioDeEquipo(opcion);
			return;
		}
		if (getOro() >= _equip[opcion].costo) {
			if (_equip[opcion].desbloqueado) {
				cout << "El articulo ya lo has comprado antes" << endl;
			}
			else {
				_equip[opcion].desbloqueado = true;
				setOro(getOro() - _equip[opcion].costo);
				CambioDeEquipo(opcion);
			}
		}
		else {
			cout << "Fondo insuficientes" << endl;
		}
		break;
	case 9:
	case 10:
		if (getOro() >= _items[opcion - 9].costo) {
			_items[opcion - 9].cantidad += 1;
			setOro(getOro() - _items[opcion - 9].costo);
		}
		else {
			cout << "Fondo insuficientes" << endl;
		}

		break;
	default:
		break;
	}
	pausa_con_enter();
}

/// <summary>
/// M�todo para que el personaje gaste puntos de habilidad
/// comprando de sus habilidades correspondientes.
/// </summary>
void Ladron::GastarPuntosDeHabilidad()
{
	int opcion;
	cout << "Tienda de Habilidades: " << endl
		<< "Puntos de Habilidad: " << getPuntosDeHabilidad() << endl;
	cout << "1. " << _habil[0].nombre << "  (" << _habil[0].costo << "pts)" << endl
		<< "2. " << _habil[1].nombre << "  (" << _habil[1].costo << "pts)" << endl
		<< "3. " << _habil[2].nombre << "  (" << _habil[2].costo << "pts)" << endl
		<< "Seleccione lo que desea comprar (1-3): ";
	cin >> opcion;
	if (getPuntosDeHabilidad() >= _habil[opcion - 1].costo) {
		_habil[opcion - 1].disponible = true;
		if (_habil[opcion - 1].disponible == true) {
			cout << "Esta habilidad ya ha sido adquirida" << endl;
		}
		else {
			_habil[opcion - 1].disponible = true;
			setPuntosDeHabilidad(getPuntosDeHabilidad() - _habil[opcion - 1].costo);
		}
	}
	else {
		cout << "Fondo insuficientes" << endl;
	}
	pausa_con_enter();
}

/// <summary>
/// Obtiene el equipamiento del personaje en la posici�n dada.
/// </summary>
/// <param name="n">La posici�n del equipamiento</param>
/// <returns>El equipamiento del ladr�n en la posici�n dada</returns>
Equipamiento Ladron::getEquipo(int n)
{
	Equipamiento aux;
	aux.nombre = "";
	aux.costo = 0;
	aux.desbloqueado = _equip[n].desbloqueado;
	aux.enUso = _equip[n].enUso;
	aux.tipo = 'n';
	return aux;
}

/// <summary>
/// Obtiene las habilidades del personaje en la posici�n dada.
/// </summary>
/// <param name="n">La posici�n de las habilidades</param>
/// <returns>Las habilidades del personaje en la posici�n dada</returns>
Habilidades Ladron::getHabilidades(int n)
{
	Habilidades aux;
	aux.nombre = _habil[n].nombre;
	aux.costo = 0;
	aux.disponible = _habil[n].disponible;
	aux.turnosRestantes = _habil[n].turnosRestantes;
	return aux;
}

/// <summary>
/// Obtiene los �tems del personaje en la posici�n dada.
/// </summary>
/// <param name="n">La posici�n de los �tems</param>
/// <returns>Los �tems del personaje en la posici�n dada</returns>
Items Ladron::getItems(int n )
{
	Items aux;
	aux.nombre = _items[n].nombre;
	aux.costo = 0;
	aux.cantidad = _items[n].cantidad;
	return aux;

}

/// <summary>
/// Establece el equipamiento del personaje en la posici�n dada.
/// </summary>
/// <param name="n">La posici�n del equipamiento</param>
/// <param name="desbloqueado">Indica si el equipamiento est� desbloqueado</param>
/// <param name="enUso">Indica si el equipamiento est� en uso</param>
void Ladron::setEquipamiento(int n, bool desbloqueado, bool enUso)
{
	_equip[n].desbloqueado = desbloqueado;
	_equip[n].enUso = enUso;
}

/// <summary>
/// Establece las habilidades del personaje en la posici�n dada.
/// </summary>
/// <param name="n">La posici�n de las habilidades</param>
/// <param name="disponible">Indica si la habilidad est� disponible</param>
/// <param name="turnos">El n�mero de turnos de la habilidad</param>
void Ladron::setHabilidades(int n, bool disponible, int turnos)
{
	_habil[n].disponible = disponible;
	_habil[n].turnosRestantes = turnos;
}

/// <summary>
/// Establece los �tems del personaje en la posici�n dada.
/// </summary>
/// <param name="n">La posici�n de los �tems</param>
/// <param name="cantidad">La cantidad de �tems</param>
void Ladron::setItems(int n, int cantidad)
{
	_items[n].cantidad = cantidad;
}

/// <summary>
/// Usa el item 1 del personaje para restaurar vida.
/// </summary>
void Ladron::UsarItem1()
{
	if (_items[0].cantidad > 0) {
		if ((getVida() + (getVidaMax() / 4)) > getVidaMax()) {
			setVida(getVidaMax());
		}
		else {
			setVida(getVida() + (getVidaMax() / 4));
		}
		_items[0].cantidad += -1;
	}
	else {
		cout << "No tienes ninguno de estos items en tu posesion" << endl;
	}
}

/// <summary>
/// Usa el item 2 del personaje para restaurar man�.
/// </summary>
void Ladron::UsarItem2()
{
	if (_items[1].cantidad > 0) {
		if ((getMana() + 35) > 100) {
			setMana(100);
		}
		else {
			setMana(getMana() + 35);
		}
		_items[1].cantidad += -1;
	}
	else {
		cout << "No tienes ninguno de estos items en tu posesion" << endl;
	}
}

/// <summary>
/// Aumenta el da�o del personaje en un 30%.
/// </summary>
void Ladron::habilidad1()
{
	setAumentoDa�o(getAumentoDa�o() + 0.3);
}

/// <summary>
/// Aumenta el da�o del personaje en un 30%, reduce el da�o enemigo en un 20% y activa la habilidad 2 durante 5 turnos.
/// </summary>
void Ladron::habilidad2()
{
	setReduccionDa�o(getReduccionDa�o() - 0.2);
	setAumentoDa�o(getAumentoDa�o() + 0.3);
	setHabilidades(1, true, 5);
}

/// <summary>
/// Activa la habilidad 3 durante 1 turno.
/// </summary>
void Ladron::habilidad3()
{
	setHabilidades(2, true, 1);
}

/// <summary>
/// Elimina la habilidad 1 y aumenta el da�o base si estaba activa.
/// </summary>
void Ladron::eliminarHabilidad1()
{
	Habilidades aux = getHabilidades(0);
	if (aux.disponible == true) {
		AumDa�oEquip();
	}
}

/// <summary>
/// Elimina la habilidad 2, reduce su duraci�n si estaba activa y aumenta el da�o base si termina.
/// </summary>
void Ladron::eliminarHabilidad2()
{
	Habilidades aux = getHabilidades(1);
	if (aux.disponible == true) {
		if (aux.turnosRestantes <= 1)
		{
			setHabilidades(1, true, 0);
			RedDa�oEquip();
			AumDa�oEquip();
		}
		else {
			setHabilidades(1, true, aux.turnosRestantes - 1);
		}
	}
}
/// <summary>
/// Elimina la habilidad 3.
/// </summary>
void Ladron::eliminarHabilidad3()
{
	Habilidades aux = getHabilidades(2);
		if (aux.disponible == true) {
		AumDa�oEquip();
		setHabilidades(2, true, 0);
	}
}

/// <summary>
/// Calcula y establece el aumento de da�o del personaje en base al equipamiento actual.
/// </summary>
void Ladron::AumDa�oEquip()
{
	//B y D aumentan da�o
	double acumDa�o = 0.0;
	for (int i = 0; i < 9; i++) {
		if (_equip[i].enUso && (_equip[i].tipo == 'B' || _equip[i].tipo == 'D')) {
			acumDa�o += _equip[i].cambioDa�o;
		}
	}
	setAumentoDa�o(1.0 + acumDa�o);
}

/// <summary>
/// Calcula y establece la reducci�n de da�o del personaje en base al equipamiento actual.
/// </summary>
void Ladron::RedDa�oEquip()
{
	//A, C y E reducen da�o
	double acumDa�o = 0.0;
	for (int i = 0; i < 9; i++) {
		if (_equip[i].enUso && (_equip[i].tipo == 'A' || _equip[i].tipo == 'C' || _equip[i].tipo == 'E')) {
			acumDa�o += _equip[i].cambioDa�o;
		}
	}
	setAumentoDa�o(1.0 - acumDa�o);
}

/// <summary>
/// Cambia el equipo del arquero al elemento con el �ndice especificado.
/// </summary>
/// <param name="indice">�ndice del elemento del equipo al que se desea cambiar.</param>
void Ladron::CambioDeEquipo(int indice)
{
	for (int i = 0; i < 9; i++) {
		if (indice != i)
		{
			if (_equip[i].tipo == _equip[indice].tipo) {
				_equip[i].enUso = false;
			}
		}
	}
	_equip[indice].enUso = true;
	cout << "Se equipo " << _equip[indice].nombre << endl;
}
