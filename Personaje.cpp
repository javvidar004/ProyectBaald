#include "Personaje.h"

using namespace std;

/// <summary>
/// Constructor de la clase Personaje.
/// Inicializa las propiedades del personaje con los valores proporcionados y establece valores predeterminados para otras propiedades.
/// </summary>
/// <param name="nombre">Nombre del personaje</param>
/// <param name="genero">Género del personaje</param>
/// <param name="raza">Raza del personaje</param>
/// <param name="orientacion">Orientación del personaje</param>
/// <param name="clase">Clase del personaje</param>
Personaje::Personaje(string nombre, string genero, string raza, string orientacion, int clase)
{
	_nombre = nombre;
	_genero = genero;
	_raza = raza;
	_orientacion = orientacion;
	_clase = clase;
	_vida = 100;
	_mana = 100;
	_exp = 0;
	_oro = 500.0;
	_nivel = 1;
	_puntosDeHabilidad = 5;
	_nivelMaxVida = 100;
	AumentoDaño = 1.0;
	ReduccionDaño = 1.0;
	saltarTurno = 0;
	intelecto = 0;
	fuerza = 0;
	agilidad = 0;

	_stats.DañoCausado = 0;
	_stats.DañoRecibido = 0;
	_stats.EnemigosEliminados = 0;
	_stats.muertes = 0;
	_stats.victorias = 0;

	_items[0].nombre = "Hierbas medicinales";
	_items[0].costo = 25;
	_items[0].cantidad = 0;
	_items[1].nombre = "Elixir de las Hadas";
	_items[1].costo = 35;
	_items[1].cantidad = 0;


}

Personaje::~Personaje()
{
}

/// <summary>
/// Obtiene la clase del personaje.
/// </summary>
/// <returns>La clase del personaje</returns>
int Personaje::getClase()
{
	return _clase;
}

/// <summary>
/// Obtiene el nombre del personaje.
/// </summary>
/// <returns>El nombre del personaje</returns>
string Personaje::getNombre()
{
	return _nombre;
}

/// <summary>
/// Obtiene el género del personaje.
/// </summary>
/// <returns>El género del personaje</returns>
string Personaje::getGenero()
{
	return _genero;
}

/// <summary>
/// Obtiene la raza del personaje.
/// </summary>
/// <returns>La raza del personaje</returns>
string Personaje::getRaza()
{
	return _raza;
}

/// <summary>
/// Obtiene la orientación del personaje.
/// </summary>
/// <returns>La orientación del personaje</returns>
string Personaje::getOrientacion()
{
	return _orientacion;
}

/// <summary>
/// Obtiene la vida actual del personaje.
/// </summary>
/// <returns>La vida actual del personaje</returns>
int Personaje::getVida()
{
	return _vida;
}

/// <summary>
/// Obtiene el mana actual del personaje.
/// </summary>
/// <returns>El mana actual del personaje</returns>
int Personaje::getMana()
{
	return _mana;
}

/// <summary>
/// Obtiene la experiencia actual del personaje.
/// </summary>
/// <returns>La experiencia actual del personaje</returns>
int Personaje::getExp()
{
	return _exp;
}

/// <summary>
/// Obtiene el nivel actual del personaje.
/// </summary>
/// <returns>El nivel actual del personaje</returns>
int Personaje::getNivel()
{
	return _nivel;
}

/// <summary>
/// Obtiene la cantidad de oro actual del personaje.
/// </summary>
/// <returns>La cantidad de oro actual del personaje</returns>
double Personaje::getOro()
{
	return _oro;
}

/// <summary>
/// Obtiene los puntos de habilidad del personaje.
/// </summary>
/// <returns>Los puntos de habilidad del personaje</returns>
int Personaje::getPuntosDeHabilidad()
{
	return _puntosDeHabilidad;
}

/// <summary>
/// Obtiene el aumento de daño por el que se multiplicará el daño para aumentarlo. Es una funcion virtual.
/// </summary>
/// <returns>La cantidad por la que se multiplicará el daño</returns>
double Personaje::getAumentoDaño()
{
	return AumentoDaño;
}

/// <summary>
/// Obtiene el aumento de daño por el que se multiplicará el daño para reducirlo. Es una funcion virtual.
/// </summary>
/// <returns>La cantidad por la que se multiplicará el daño y lo reducira</returns>
double Personaje::getReduccionDaño()
{
	return ReduccionDaño;
}

/// <summary>
/// Obtiene el valor de la variable `saltarTurno` que indica si el personaje está saltando su turno.
/// </summary>
/// <returns>Valor entero que indica si el personaje está saltando su turno (1) o no (0).</returns>
int Personaje::getSaltarTurno()
{
	return saltarTurno;
}

/// <summary>
/// Obtiene el valor de la fuerza del personaje.
/// </summary>
/// <returns>Valor entero que indica la fuerza del personaje.</returns>
int Personaje::getFuerza()
{
	return fuerza;
}

/// <summary>
/// Obtiene el valor del intelecto del personaje.
/// </summary>
/// <returns>Valor entero que indica el intelecto del personaje.</returns>
int Personaje::getIntelecto()
{
	return intelecto;
}

/// <summary>
/// Obtiene el valor de la agilidad del personaje.
/// </summary>
/// <returns>Valor entero que indica la agilidad del personaje.</returns>
int Personaje::getAgilidad()
{
	return agilidad;
}

/// <summary>
/// Establece la clase del personaje.
/// </summary>
/// <param name="n">La clase del personaje a establecer</param>
void Personaje::setClase(int n)
{
	_clase = n;
}

/// <summary>
/// Establece el nombre del personaje.
/// </summary>
/// <param name="nombre">El nombre del personaje a establecer</param>
void Personaje::setNombre(string nombre)
{
	_nombre = nombre;
}

/// <summary>
/// Establece el género del personaje.
/// </summary>
/// <param name="genero">El género del personaje a establecer</param>
void Personaje::setGenero(string genero)
{
	_genero = genero;
}

/// <summary>
/// Establece la raza del personaje.
/// </summary>
/// <param name="raza">La raza del personaje a establecer</param>
void Personaje::setRaza(string raza)
{
	_raza = raza;
}

/// <summary>
/// Establece la orientación del personaje.
/// </summary>
/// <param name="orientacion">La orientación del personaje a establecer</param>
void Personaje::setOrientacion(string orientacion)
{
	_orientacion = orientacion;
}

/// <summary>
/// Establece la vida del personaje.
/// </summary>
/// <param name="vida">La vida del personaje a establecer</param>
void Personaje::setVida(int vida)
{
	_vida = vida;
}

/// <summary>
/// Establece el mana del personaje.
/// </summary>
/// <param name="mana">El mana del personaje a establecer</param>
void Personaje::setMana(int mana)
{
	_mana = mana;
}

/// <summary>
/// Establece la experiencia del personaje.
/// </summary>
/// <param name="experiencia">La experiencia del personaje a establecer</param>
void Personaje::setExp(int experiencia)
{
	_exp = experiencia;
}

/// <summary>
/// Establece el nivel del personaje.
/// </summary>
/// <param name="nivel">El nivel del personaje a establecer</param>
void Personaje::setNivel(int nivel)
{
	_nivel = nivel;
}

/// <summary>
/// Establece la cantidad de oro del personaje.
/// </summary>
/// <param name="oro">La cantidad de oro del personaje a establecer</param>
void Personaje::setOro(double oro)
{
	_oro = oro;
}

/// <summary>
/// Establece los puntos de habilidad del personaje.
/// </summary>
/// <param name="puntos">Los puntos de habilidad del personaje a establecer</param>
void Personaje::setPuntosDeHabilidad(int puntos)
{
	_puntosDeHabilidad = puntos;
}

/// <summary>
/// Establece el multiplicador de aumento de daño del personaje. Este valor se utilizará para multiplicar el daño infligido por el personaje.
/// </summary>
/// <param name="aumentoDaño">Valor del multiplicador de aumento de daño (por ejemplo, 1.5 para aumentar el daño en un 50%).</param>
void Personaje::setAumentoDaño(double)
{

}

/// <summary>
/// Establece el multiplicador de reducción de daño del personaje. Este valor se utilizará para multiplicar el daño recibido por el personaje.
/// </summary>
/// <param name="reduccionDaño">Valor del multiplicador de reducción de daño (por ejemplo, 0.5 para reducir el daño recibido en un 50%).</param>
void Personaje::setReduccionDaño(double)
{

}

/// <summary>
/// Establece si el personaje está saltando su turno.
/// </summary>
/// <param name="valor">1 si el personaje está saltando su turno, 0 en caso contrario.</param>
void Personaje::setSaltarTurno(int valor)
{
	saltarTurno = valor;
}

/// <summary>
/// Aumenta la fuerza del personaje segun cada 30 enemigos que elimine
/// </summary>
void Personaje::aumentarFuerza()
{
	fuerza = (_stats.EnemigosEliminados / 30);
}

/// <summary>
/// Aumenta el intelecto por cada 20 victorias 
/// </summary>
void Personaje::aumentarIntelecto()
{
	intelecto = (_stats.victorias / 20);
}

/// <summary>
/// Aumenta la agilidad del personaje segun cada 50000 puntos de daño generados
/// </summary>
void Personaje::aumentarAgilidad()
{
	agilidad = (_stats.DañoCausado / 50000);
}

/// <summary>
/// Establece el valor máximo de vida del personaje según su nivel.
/// </summary>
void Personaje::ReSetVida()
{
	switch (_nivel)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			_nivelMaxVida = 100;
			break;
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
			_nivelMaxVida = 300;
			break;
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			_nivelMaxVida = 500;
			break;
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
			_nivelMaxVida = 800;
			break;
		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
			_nivelMaxVida = 1000;
			break;
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
			_nivelMaxVida = 1500;
			break;
	default:
		break;
	}
}

/// <summary>
/// Obtiene el valor máximo de vida del personaje.
/// </summary>
/// <returns>El valor máximo de vida del personaje</returns>
int Personaje::getVidaMax()
{
	return _nivelMaxVida;
}

/// <summary>
/// Muestra las estadísticas del personaje.
/// </summary>
void Personaje::VerEstadisticas()
{
	cout<< "Tus estadisticas son:" << endl
		<< _nivel << " Nivel" << endl
		<< _vida << " Vida" << endl
		<< _mana << " Mana" << endl
		<< _exp << " Experiencia" << endl
		<< _stats.victorias << " Escenarios terminados" << endl
		<< _stats.muertes << " Muertes" << endl
		<< _stats.EnemigosEliminados << " Enemigos Eliminados" << endl
		<< _stats.DañoCausado << " Daño causado" << endl
		<< _stats.DañoRecibido << " Daño recibido" << endl
		<< intelecto << "Intelecto" << endl
		<< agilidad << "Agilidad" << endl
		<< fuerza << "Fuerza" << endl;
}

/// <summary>
/// Actualiza las estadísticas del personaje.
/// </summary>
/// <param name="auxiliar">Las estadísticas auxiliares para actualizar</param>
void Personaje::ActualizarEstadisticas(Estadisticas auxiliar)
{
	setEstadisticas(auxiliar.victorias, auxiliar.muertes, auxiliar.EnemigosEliminados, auxiliar.DañoCausado, auxiliar.DañoRecibido);
}

/// <summary>
/// Establece las estadísticas del personaje.
/// </summary>
/// <param name="victorias">El número de victorias</param>
/// <param name="muertes">El número de muertes</param>
/// <param name="Enemigos">El número de enemigos eliminados</param>
/// <param name="DañoC">El daño causado</param>
/// <param name="DañonR">El daño recibido</param>
void Personaje::setEstadisticas(int victorias, int muertes, int Enemigos, int DañoC, int DañonR)
{
	_stats.DañoCausado += DañoC;
	_stats.DañoRecibido += DañonR;
	_stats.EnemigosEliminados += Enemigos;
	_stats.muertes += muertes;
	_stats.victorias += victorias;
}

/// <summary>
/// Establece el equipamiento del usuario, es una funcion virtual que se usa 
/// especificamente segun la clase del personaje y por la herencia se define
///  en las clases hijas.
/// </summary>
void Personaje::setEquipamiento(int, bool, bool)
{
}

/// <summary>
/// Establece las habilidades del usuario, es una funcion virtual que se usa 
/// especificamente segun la clase del personaje y por la herencia se define
///  en las clases hijas.
/// </summary>
void Personaje::setHabilidades(int, bool, int)
{

}

/// <summary>
/// Establece los items del usuario, es una funcion virtual que se usa 
/// especificamente segun la clase del personaje y por la herencia se define
///  en las clases hijas.
/// </summary>
void Personaje::setItems(int, int)
{
}

/// <summary>
/// Utiliza el primer ítem del personaje (Hierbas medicinales).
/// </summary>
void Personaje::UsarItem1()
{
}

/// <summary>
/// Utiliza el segundo ítem del personaje (Elixir de las Hadas).
/// </summary>
void Personaje::UsarItem2()
{
}

/// <summary>
/// Ejecuta la habilidad 1 del personaje.
/// </summary>
void Personaje::habilidad1()
{
}

/// <summary>
/// Elimina la habilidad 1 del personaje.
/// </summary>
void Personaje::eliminarHabilidad1()
{
}

/// <summary>
/// Ejecuta la habilidad 2 del personaje.
/// </summary>
void Personaje::habilidad2()
{
}

/// <summary>
/// Elimina la habilidad 2 del personaje.
/// </summary>
void Personaje::eliminarHabilidad2()
{
}

/// <summary>
/// Ejecuta la habilidad 3 del personaje.
/// </summary>
void Personaje::habilidad3()
{
}

/// <summary>
/// Elimina la habilidad 3 del personaje.
/// </summary>
void Personaje::eliminarHabilidad3()
{
}

/// <summary>
/// Obtiene las estadísticas del personaje.
/// </summary>
/// <returns>Las estadísticas del personaje</returns>
Estadisticas Personaje::getEstadisticas()
{
	return _stats;
}

/// <summary>
/// Aumenta el daño del personaje por medio del equipamiento.
/// </summary>
void Personaje::AumDañoEquip()
{
}

/// <summary>
/// Reduce el daño del personaje por medio del equipamiento.
/// </summary>
void Personaje::RedDañoEquip()
{
}

/// <summary>
/// Cambia el equipo del personaje al equipo con el ID especificado.
/// </summary>
/// <param name="indice">indice del lugar donde se encuentra en el arreglo el objeto que se desea cambiar.</param>
void Personaje::CambioDeEquipo(int)
{
}

/// <summary>
/// Establece la tienda segun la la clase del personaje, es un metodo virtual
/// que se define en la herencia de cada clase hija.
/// </summary>
void Personaje::CompraEquipo()
{

}

/// <summary>
/// Establece la tienda de las habilidades segun la la clase del personaje,
///  es un metodo virtual que se define en la herencia de cada clase hija.
/// </summary>
void Personaje::GastarPuntosDeHabilidad()
{

}

/// <summary>
/// Establece la tienda segun la la clase del personaje, es un metodo virtual
/// que se define en la herencia de cada clase hija.
/// </summary>
Equipamiento Personaje::getEquipo(int n)
{
	return Equipamiento();
}

/// <summary>
/// Establece la tienda de las habilidades segun la la clase del personaje,
///  es un metodo virtual que se define en la herencia de cada clase hija.
/// </summary>
Habilidades Personaje::getHabilidades(int n)
{
	return Habilidades();
}

/// <summary>
/// Obtienes uno de los items del usuario, es una funcion virtual que se usa 
/// especificamente segun la clase del personaje y por la herencia se define
///  en las clases hijas.
/// </summary>
Items Personaje::getItems(int)
{
	return Items();
}

/// <summary>
/// Pausa la ejecución del programa y espera a que el usuario presione la tecla Enter para continuar.
/// </summary>
void Personaje::pausa_con_enter()
{
	// Espera a que el usuario presione Enter para continuar
	cout << "Presiona Enter para continuar...";
	cin.ignore();
	cin.get();
}