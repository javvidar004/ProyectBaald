#include "Juego.h"

enum clasePersonaje {
	GuerreroEn = 1,
	ArqueroEn,
	MagoEn,
	LadronEn
};

enum Orientacion {
	Bueno = 1,
	Neutro,
	Malo
};

enum DañoPorNivel {
	N1 = 3,
	N2 = 6,
	N3 = 9,
	N4 = 12,
	N5 = 15,
	N6 = 18,
	N7 = 21,
	N8 = 24,
	N9 = 27,
	N10 = 30,
	N11 = 33,
	N12 = 36,
	N13 = 39,
	N14 = 42,
	N15 = 45,
	N16 = 48,
	N17 = 51,
	N18 = 54,
	N19 = 57,
	N20 = 60,
	N21 = 63,
	N22 = 66,
	N23 = 69,
	N24 = 72,
	N25 = 75,
	N26 = 78,
	N27 = 81,
	N28 = 84,
	N29 = 87,
	N30 = 90
};

enum TablaDeNiveles {
	Nivel1 = 0,
	Nivel2 = 7,
	Nivel3 = 23,
	Nivel4 = 47,
	Nivel5 = 110,
	Nivel6 = 220,
	Nivel7 = 450,
	Nivel8 = 800,
	Nivel9 = 1300,
	Nivel10 = 2000,
	Nivel11 = 2900,
	Nivel12 = 4000,
	Nivel13 = 5500,
	Nivel14 = 7500,
	Nivel15 = 10000,
	Nivel16 = 13000,
	Nivel17 = 17000,
	Nivel18 = 21000,
	Nivel19 = 25000,
	Nivel20 = 29000,
	Nivel21 = 33000,
	Nivel22 = 37000,
	Nivel23 = 41000,
	Nivel24 = 45000,
	Nivel25 = 49000,
	Nivel26	= 53000,
	Nivel27	= 57000,
	Nivel28	= 61000,
	Nivel29	= 65000,
	Nivel30	= 70000
};

/// <summary>
/// Constructor de la clase Juego.
/// Inicializa el nombre de la partida como una cadena vacía y el puntero al personaje como nullptr.
/// </summary>
Juego::Juego()
{
	nombrePartida = "";
	miPersonaje = nullptr;
}

/// <summary>
/// Destructor de la clase Juego.
/// Libera la memoria asignada al objeto apuntado por miPersonaje.
/// </summary>
Juego::~Juego()
{
	delete miPersonaje;
}

/// <summary>
/// Muestra el menú inicial del juego y permite al usuario seleccionar entre diferentes opciones.
/// </summary>
void Juego::MenuInicial()
{
	// Limpia la pantalla antes de mostrar el menú
	LimpiarPantalla();
	// Variable para almacenar la opción seleccionada por el usuario
	int opcionMI = 0;
	// Bucle que se ejecuta hasta que el usuario elige salir del juego
	while (opcionMI != 2) {
		// Muestra las opciones del menú y solicita la entrada del usuario
		cout << "Menu de Inicio: " << endl
			<< "1. Iniciar Juego" << endl
			<< "2. Salir del juego" << endl
			<< "Opcion: ";
		cin >> opcionMI;
		// Realiza acciones basadas en la opción seleccionada por el usuario
		switch (opcionMI)
		{
		case 1:
			// Llama al método MenuPrincipal() para mostrar el menú principal del juego
			MenuPrincipal();
			break;
		case 2:
			LimpiarPantalla();
			// Muestra un mensaje de despedida y termina el juego
			cout << "Gracias por jugar" << endl;
			pausa_con_enter();
			break;
		default:
			// En caso de que el usuario seleccione una opción no válida, muestra un mensaje de error 
			// y espera a que el usuario presione Enter
			LimpiarPantalla();
			cout << "Selecciona una de las opciones validas" << endl;
			pausa_con_enter();
			break;
		}
		// Limpia la pantalla antes de mostrar el menú nuevamente
		LimpiarPantalla();
	}
}

/// <summary>
/// Muestra el menú principal del juego y permite al usuario Crear una nueva partida, Cargar una 
/// partida ya existente o salir del juego.
/// </summary>
void Juego::MenuPrincipal()
{
	// Limpia la pantalla antes de mostrar el menú
	LimpiarPantalla();
	// Variable para almacenar la opción seleccionada por el usuario
	int opcionMP = 0;
	// Bucle que se ejecuta hasta que el usuario elige salir del menú principal
	while (opcionMP != 3) {
		// Muestra las opciones del menú y solicita la entrada del usuario
		cout << "Menu Principal: " << endl
			<< "1. Comenzar partida" << endl
			<< "2. Cargar partida" << endl
			<< "3. Salir" << endl
			<< "Opcion: ";
		cin >> opcionMP;
		// Realiza acciones basadas en la opción seleccionada por el usuario
		switch (opcionMP)
		{
		case 1:
			// Llama al método CrearPartida() para iniciar una nueva partida
			// Luego, muestra el menú de juego
			CrearPartida();
			MenuDeJuego();
			break;
		case 2:
			// Llama al método CargarPartida() para cargar una partida guardada
			// Luego, muestra el menú de juego
			CargarPartida();
			MenuDeJuego();
			break;
		case 3:
			//Este case se agrego para que no salga el mensaje de opcion no valida antes de salir del juego
			break;
		default:
			// En caso de que el usuario seleccione una opción no válida, muestra un mensaje de error
			// y espera a que el usuario presione Enter
			LimpiarPantalla();
			cout << "Selecciona una de las opciones validas" << endl;
			pausa_con_enter();
			break;
		}
	}
}

/// <summary>
/// Crea una nueva partida en el juego.
/// </summary>
void Juego::CrearPartida()
{
	// Ruta del archivo que contiene las partidas guardadas
	string rutaPartidas = "./Scr/Partidas.txt";
	// Busca el documento a partir de la ruta anterior
	ifstream archivoLeido(rutaPartidas.c_str());
	ofstream archivo;
	// Si el archivo de partidas no existe, lo crea
	if (!archivoLeido) {
		archivo.open(rutaPartidas.c_str(), fstream::out);
		archivo << "";
		archivo.close();
	}
	// Solicita al usuario que introduzca el nombre de la partida
	cout << "Introduce el nombre de usuario: ";
	cin >> nombrePartida;
	// Ruta del archivo de la nueva partida
	string rutaArchivo = "./Scr/"+nombrePartida+".txt";
	// Crea el archivo de la nueva partida
	archivo.open(rutaArchivo.c_str(), fstream::out);
	archivo << "";
	archivo.close();
	// Agrega el nombre de la partida al archivo de partidas
	archivo.open(rutaPartidas.c_str(), fstream::app);
	archivo << nombrePartida << endl;
	archivo.close();
	// Crea un nuevo personaje para la partida
	miPersonaje = CrearPersonaje();
	// Guarda la partida recién creada
	GuardarPartida();
}

/// <summary>
/// Carga una partida previamente guardada por el usuario, a partir del documento con todos los datos guardados.
/// </summary>
void Juego::CargarPartida()
{
	// Ruta del archivo que contiene las partidas guardadas
	string rutaPartidas = "./Scr/Partidas.txt";
	// Abre el archivo de partidas
	ifstream archivoLeido(rutaPartidas.c_str());
	// Si el archivo de partidas no existe, indica al usuario que no hay partidas existentes y crea una nueva partida
	if (!archivoLeido) {
		cout << "Aun no hay ninguna partida existente" << endl;
		cout << "Se creara una nueva partida" << endl;
		CrearPartida();
	}
	else 
	{
		// Si existen partidas guardadas, permite al usuario seleccionar una
		cout << "Selecciona una de las partidas creadas: " << endl;
		string linea;
		int counter = 1;
		// Muestra las partidas disponibles al usuario
		while (getline(archivoLeido, linea)) {
			cout << counter << " : " << linea << endl;
			counter++;
		}
		// Solicita al usuario que seleccione una partida
		int SeleccionarPartida = 0;
		//Se valida que se introduzca un valor valido entre las posibles partidas que existen
		while (SeleccionarPartida < 1 || SeleccionarPartida >= counter)
		{
			cout << "Eleccion (1-" << counter - 1 << "): ";
			cin >> SeleccionarPartida;
		}

		cin.ignore();
		// Reinicia el contador y vuelve al principio del archivo
		counter = 1;
		archivoLeido.clear();
		archivoLeido.seekg(0, ios::beg);
		// Encuentra la partida seleccionada por el usuario en el archivo de partidas
		while (getline(archivoLeido, linea)) {
			if (counter == SeleccionarPartida) {
				nombrePartida = linea;
				break;
			}
			counter++;
		}
		// Carga los atributos del personaje desde el archivo y los asigna al objeto de personaje, 
		// logrando tener los mismos datos de la ultima vez que se guardo la partida
		vector<string> atributos;
		miPersonaje =  CargarPersonaje(atributos);
		miPersonaje->setVida(stoi(atributos[5]));
		miPersonaje->setMana(stoi(atributos[6]));
		miPersonaje->setExp(stoi(atributos[7]));
		miPersonaje->setOro(stod(atributos[8]));
		miPersonaje->setNivel(stoi(atributos[9]));
		miPersonaje->setPuntosDeHabilidad(stoi(atributos[10]));
		miPersonaje->setEstadisticas(stoi(atributos[11]), stoi(atributos[12]), stoi(atributos[13]), stoi(atributos[14]), stoi(atributos[15]));
		for (int i = 0; i < 9; i++) {
			miPersonaje->setEquipamiento(i, StringtoBool(atributos[((i + 8) * 2)]), StringtoBool(atributos[((i + 8) * 2) + 1]));
		}
		for (int i = 0; i < 3; i++) {
			miPersonaje->setHabilidades(i, StringtoBool(atributos[((i + 17) * 2)]), stoi(atributos[((i + 17) * 2) + 1]));
		}
		for (int i = 0; i < 2; i++) {
			miPersonaje->setItems(i, stoi(atributos[i + 40]));
		}
		miPersonaje->aumentarAgilidad();
		miPersonaje->aumentarFuerza();
		miPersonaje->aumentarIntelecto();
	}
}

/// <summary>
/// Guarda los datos de la partida actual en el archivo de texto con el mismo nombre de la partida.
/// </summary>
void Juego::GuardarPartida()
{
	// Abre el archivo de texto para escribir los datos de la partida
	ofstream archivo;
	string rutaArchivo = "./Scr/" + nombrePartida + ".txt";
	archivo.open(rutaArchivo.c_str(), fstream::out);
	// Escribe los datos del personaje en el archivo
	archivo << miPersonaje->getClase() << ",";
	archivo << miPersonaje->getGenero() << ",";
	archivo << miPersonaje->getNombre() << ",";
	archivo << miPersonaje->getRaza() << ",";
	archivo << miPersonaje->getOrientacion() << ",";
	archivo << miPersonaje->getVida() << ",";
	archivo << miPersonaje->getMana() << ",";
	archivo << miPersonaje->getExp() << ",";
	archivo << miPersonaje->getOro() << ",";
	archivo << miPersonaje->getNivel() << ",";
	archivo << miPersonaje->getPuntosDeHabilidad() << ",";
	// Obtiene las estadísticas del personaje y las escribe en el archivo
	Estadisticas estats = miPersonaje->getEstadisticas();
	archivo << estats.victorias << ",";
	archivo << estats.muertes << ",";
	archivo << estats.EnemigosEliminados << ",";
	archivo << estats.DañoCausado << ",";
	archivo << estats.DañoRecibido << ",";
	// Obtiene el equipamiento del personaje y lo escribe en el archivo
	for (int i = 0; i < 9; i++) {
		Equipamiento guardado = miPersonaje->getEquipo(i);
		archivo << guardado.desbloqueado << ",";
		archivo << guardado.enUso << ",";
	}
	// Obtiene las habilidades del personaje y las escribe en el archivo
	for (int i = 0; i < 3; i++) {
		Habilidades guardado = miPersonaje->getHabilidades(i);
		archivo << guardado.disponible << ",";
		archivo << guardado.turnosRestantes << ",";
	}
	// Obtiene los items del personaje y los escribe en el archivo
	for (int i = 0; i < 2; i++) {
		Items guardado = miPersonaje->getItems(i);
		archivo << guardado.cantidad << ",";
	}
	// Cierra el archivo después de escribir los datos
	archivo.close();
}

/// <summary>
/// Muestra el menú de juego y permite al usuario seleccionar entre diferentes opciones
/// del juego que son Ver Estadisticas, Comprar Equipo, Gastar Puntos de Habilidad, Ir a la aventura
/// Guardar Partida y Salir del juego.
/// </summary>
void Juego::MenuDeJuego()
{
	// Limpia la pantalla antes de mostrar el menú
	LimpiarPantalla();
	// Variable para almacenar la opción seleccionada por el usuario
	int opcionMDJ = 0;
	// Bucle que se ejecuta hasta que el usuario elige salir del menú de juego
	while (opcionMDJ != 6) {
		// Muestra las opciones del menú y solicita la entrada del usuario
		cout << "Menu Principal: " << endl
			<< "1. Ver estadisticas" << endl
			<< "2. Comprar Equipo" << endl
			<< "3. Gastar puntos de habilidad" << endl
			<< "4. Ir a una aventura" << endl
			<< "5. Guardar partida" << endl
			<< "6. Salir" << endl
			<< "Opcion: ";
		cin >> opcionMDJ;
		// Realiza acciones basadas en la opción seleccionada por el usuario
		switch (opcionMDJ)
		{
		case 1:
			// Muestra las estadísticas del personaje y pausa el juego
			LimpiarPantalla();
			miPersonaje->VerEstadisticas();
			pausa_con_enter();
			break;
		case 2:
			// Permite al usuario comprar equipo para el personaje, guarda la partida y pausa el juego
			LimpiarPantalla();
			miPersonaje->CompraEquipo();
			pausa_con_enter();
			GuardarPartida();
			break;
		case 3:
			// Permite al usuario gastar puntos de habilidad, guarda la partida y pausa el juego
			LimpiarPantalla();
			miPersonaje->GastarPuntosDeHabilidad();
			pausa_con_enter();
			GuardarPartida();
			break;
		case 4:
			// Permite al usuario ir a una aventura, guarda la partida y pausa el juego
			LimpiarPantalla();
			IrAventura();
			GuardarPartida();
			break;
		case 5:
			// Guarda la partida y continua el juego
			GuardarPartida();
			break;
		case 6:
			//Este case se agrego para que no salga el mensaje de opcion no valida antes de salir del juego
			break;
		default:
			// En caso de que el usuario seleccione una opción no válida, muestra un mensaje de error
			// y espera a que el usuario presione Enter
			LimpiarPantalla();
			cout << "Selecciona una de las opciones validas" << endl;
			pausa_con_enter();
			break;
		}
		// Limpia la pantalla antes de mostrar el menú nuevamente
		LimpiarPantalla();
	}
}

/// <summary>
/// Inicia una aventura en el juego, donde el personaje se enfrenta a una serie de escenarios.
/// </summary>
void Juego::IrAventura()
{
	//Se actualizan las variables de que cambian el daño del personaje y de los enemigos
	miPersonaje->AumDañoEquip();
	miPersonaje->RedDañoEquip();
	// Estadísticas de la aventura actual que se utilizaran para actualizar las estadisticas generales del personaje
	Estadisticas StatsJuego;
	StatsJuego.DañoCausado = 0, StatsJuego.DañoRecibido = 0, StatsJuego.EnemigosEliminados = 0, StatsJuego.muertes = 0, StatsJuego.victorias = 0;
	int oroGanado = 0, expGanada = 0;
	// Determina la cantidad de escenarios basados en el nivel del personaje
	int escenarios = CantidaddeEnemigos(miPersonaje->getNivel());
	if (escenarios > 10) {
		escenarios = 10;
	}
	// Itera a través de cada escenario de la aventura
	for (int i = 0; i < escenarios; i++) {
		// Inicia una batalla con los enemigos del escenario actual
		Batalla(CrearEnemigos(CantidaddeEnemigos(miPersonaje->getNivel())), StatsJuego);
		// Verifica si el personaje ha muerto durante la batalla
		int opcion = 0;
		if (miPersonaje->getVida() <= 0) {
			muertePersonaje(StatsJuego);
			break;
		}
		StatsJuego.victorias += 1;
		// Verifica si se han completado todos los escenarios
		if (escenarios - 1 == i) {
			LimpiarPantalla();
			cout << "Felicidades acabaste los escenarios" << endl;
			// Decide si se debe enfrentar al jefe final
			if ((rand() % (2)) == 1) {
				int eleccion = 0;
				while (eleccion != 1 && eleccion != 2)
				{
					cout << "Vida restante " << miPersonaje->getVida() << endl;
					cout << "Deseas enfrentar al Jefe:\n1. Si\n2. No\n"<< endl <<"Eleccion: ";
					cin >> eleccion;
				}
				if (eleccion == 1)
				{
					//Se crea el Jefe y se pelea contra el
					Batalla(crearJefe(miPersonaje->getNivel()), StatsJuego);
					//Se actualizan las estadisticas principales del personaje
					miPersonaje->ActualizarEstadisticas(StatsJuego);
					if (miPersonaje->getVida() <= 0) {
						muertePersonaje(StatsJuego);
						
						break;
					}
					else {
						cout << "Felicidades venciste al Jefe" << endl;
						pausa_con_enter();
					}
					CambioDeNivel();
				}
			}
			else {
				miPersonaje->ActualizarEstadisticas(StatsJuego);
				CambioDeNivel();
				pausa_con_enter();
			}
		}
		else {
			// Pregunta al usuario si desea continuar a los siguientes escenarios
			while (opcion != 1 && opcion != 2)
			{
				cout << "Escenarios restantes: " << escenarios - 1 - i << endl;
				cout << "Deseas continuar: \n1. Si\n2. No\n Eleccion: ";
				cin >> opcion;
			}
		}
		// Si el usuario decide no continuar, sale de la aventura
		if (opcion == 2)
		{
			//Se actualizan las estadisticas generales del personaje
			miPersonaje->ActualizarEstadisticas(StatsJuego);
			CambioDeNivel();
			break;
		}
	}
}

/// <summary>
/// Simula una batalla entre el personaje del jugador y una serie de enemigos.
/// </summary>
/// <param name="enemigos">Vector que contiene los enemigos que participan en la batalla</param>
/// <param name="stats">Referencia a las estadísticas de la batalla</param>
void Juego::Batalla(vector<Enemigo> enemigos, Estadisticas& stats) {
	// Contador para controlar el turno de los participantes en la batalla
	int contador = 1;
	// Bucle que se ejecuta hasta que no hay más enemigos o el personaje del jugador muere
	while (!enemigos.empty() && miPersonaje->getVida() >= 0) {
		// Si es el turno del jugador, muestra el menú de pelea
		if (contador % 2 == 1) {
			MenuPelea(enemigos, stats);
		}
		// Si es el turno de los enemigos, realiza su ataque y actualiza la vida del personaje
		else 
		{
			// Calcula el daño causado por los enemigos y actualiza la vida del personaje
			int daño =  AtaqueEnemigos(enemigos) * miPersonaje->getReduccionDaño();
			miPersonaje->setVida(miPersonaje->getVida() - daño);
			// Actualiza las estadísticas de daño recibido
			if ((miPersonaje->getVida() - daño) <= 0)
			{
				stats.DañoRecibido += (daño - miPersonaje->getVida());
			}
			else {
				stats.DañoRecibido += daño;
			}
			
		}
		// Incrementa el contador de turno
		contador += 1 + miPersonaje->getSaltarTurno();
		eliminarHabilidades();
	}
}

/// <summary>
/// Muestra el menú de opciones durante una pelea y permite al jugador seleccionar una acción.
/// </summary>
/// <param name="enemigos">Vector que contiene los enemigos participantes en la pelea.</param>
/// <param name="estatsJuego">Estadísticas del juego.</param>
void Juego::MenuPelea(vector<Enemigo>& enemigos, Estadisticas& estatsJuego)
{
	// Declaración de variable para la elección del jugador
	int eleccion = 0;
	// Bucle principal del menú de pelea
	while (eleccion != 1)
	{
		// Limpiar la pantalla antes de mostrar el menú
		LimpiarPantalla();
		// Mostrar información de la pelea
		DatosDePelea(enemigos);
		// Menú de opciones
		cout << "Pelea: " << endl
				<< "1. Atacar" << endl
				<< "2. Usar Habilidad" << endl
				<< "3. Usar Item" << endl
				<< "Opcion: ";
		cin >> eleccion;
		switch (eleccion)
		{
		case 1:
			// Función para atacar a los enemigos
			Atacar(enemigos, estatsJuego);
			break;
		case 2:
			// Función para mostrar las habilidades disponibles
			UsarHabilidades();
			// Función específica para la habilidad 3
			DañoEnemigosHabilidad3(enemigos, estatsJuego);
			// Verificar si la habilidad 3 termina el juego (condiciones para cada clase)
			if ((miPersonaje->getHabilidades(2).turnosRestantes == 5 && miPersonaje->getClase() == 2) 
				|| (miPersonaje->getHabilidades(2).turnosRestantes == 7 && miPersonaje->getClase() == 3)
				|| (miPersonaje->getHabilidades(2).turnosRestantes == 1 && miPersonaje->getClase() == 4))
			{
				//Sale del turno del jugador y pasa al turno de los enemigos
				return;
			}
			break;
		case 3:
			// Función para mostrar y usar items
			UsarItems();
			break;
		}
	}
}

/// <summary>
/// Calcula la cantidad de daño generado por los enemigo en total.
/// </summary>
/// <param name="enemigos">Vector que contiene los enemigos participantes en la batalla</param>
/// <param name="ind">Índice del enemigo para el cual se calcula el daño</param>
/// <returns>La cantidad de daño generado por el enemigo</returns>
int Juego::CantidadDeDaño(vector<Enemigo> enemigos, int ind)
{
	// Obtiene el nivel del enemigo para determinar el rango de daño
	int nivel_enemigo = enemigos[ind].getNivel();
	// Calcula el daño mínimo y máximo basado en el nivel del enemigo
	int daño_minimo = (nivel_enemigo * 2) - 1;
	int daño_maximo = (nivel_enemigo * 3) + 1;
	// Genera un valor aleatorio dentro del rango de daño
	int daño_generado = rand() % (daño_maximo - daño_minimo + 3) + daño_minimo;
	// Devuelve la cantidad de daño generada por el enemigo
	return daño_generado;
}

/// <summary>
/// Calcula la cantidad de daño infligido por el personaje del jugador, basado en su nivel.
/// </summary>
/// <returns>La cantidad de daño infligido por el personaje del jugador</returns>
int Juego::CantidadDeDaño()
{
	int dañoCDD = 0;
	// Obtiene el nivel del personaje del jugador para determinar la cantidad de daño
	switch (miPersonaje->getNivel())
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		// Niveles del 1 al 5: Daño = Nivel * 3 * 5
		dañoCDD = rand() % (miPersonaje->getNivel() * 3 * 5) + 5;
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		// Niveles del 6 al 10: Daño = Nivel * 5
		dañoCDD = rand() % (miPersonaje->getNivel() * 5) + 5;
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		// Niveles del 11 al 15: Daño = Nivel * 4
		dañoCDD = rand() % (miPersonaje->getNivel() * 4) + 5;
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
		// Niveles del 16 al 20: Daño = Nivel * 3
		dañoCDD = rand() % (miPersonaje->getNivel() * 3) + 5;
	case 21:
	case 22:
	case 23:
	case 24:
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
	case 30:
		// Niveles del 21 al 30: Daño = Nivel * 2
		dañoCDD = rand() % (miPersonaje->getNivel() * 2) + 5;
	}
	return dañoCDD * miPersonaje->getAumentoDaño();
}

/// <summary>
/// Permite al jugador atacar a un enemigo seleccionado en la batalla.
/// </summary>
/// <param name="enemigos">Vector que contiene los enemigos participantes en la batalla</param>
void Juego::Atacar(vector<Enemigo>& enemigos, Estadisticas& statsJA) 
{
	// Variable para almacenar la elección del jugador sobre qué enemigo atacar
	int eleccion = -1;
	// Bucle que se ejecuta hasta que se selecciona un enemigo válido
	while (eleccion < 1 || eleccion > (enemigos.size()))
	{
		LimpiarPantalla();
		// Solicita al jugador que seleccione un enemigo para atacar
		cout << "A que enemigo deseas atacar?" << endl;
		for (int i = 0; i < enemigos.size(); i++) {
			cout << (i + 1) << ". " << enemigos[i].getNombre() << endl;
		}
		cout << "Enemigo seleccionado: ";
		cin >> eleccion;
	}
	DañarEnemigos(enemigos, statsJA, eleccion - 1, (CantidadDeDaño() + miPersonaje->getAgilidad() + miPersonaje->getFuerza() + miPersonaje->getIntelecto()));
}

/// <summary>
/// Reduce la vida del enemigo seleccionado según el daño infligido.
/// Si la vida del enemigo llega a 0 o menos, elimina al enemigo del vector de enemigos,
/// aumenta la experiencia del personaje por el nivel del enemigo que mató,
/// otorga oro al personaje por haber eliminado al enemigo, y registra el daño causado.
/// </summary>
/// <param name="enemigos">Vector que contiene a los enemigos.</param>
/// <param name="statsDE">Referencia a las estadísticas del personaje.</param>
/// <param name="indiceDE">Índice del enemigo seleccionado.</param>
/// <param name="daño">Cantidad de daño infligido al enemigo.</param>
void Juego::DañarEnemigos(vector<Enemigo>& enemigos, Estadisticas& statsDE, int indiceDE, int daño)
{
	// Reduce la vida del enemigo seleccionado según el daño infligido
	enemigos[indiceDE].setVida(enemigos[indiceDE].getVida() - daño);
	// Si la vida del enemigo llega a 0 o menos, lo elimina del vector de enemigos
	if (enemigos[indiceDE].getVida() <= 0) {
		//Aumenta la experiencia del personaje por el nivel del enemigo que mato
		miPersonaje->setExp(miPersonaje->getExp() + enemigos[indiceDE].getNivel());
		//Da el oro que se gana por haber matado al enemigo
		miPersonaje->setOro(miPersonaje->getOro() + enemigos[indiceDE].getNivel());
		//Calcula el daño para no contar los puntos de daño si es que se paso de la vida 
		statsDE.DañoCausado += daño + enemigos[indiceDE].getVida();
		//Se elimina al enemigo que ya se le ha acabado la vida
		enemigos.erase(enemigos.begin() + indiceDE);
		statsDE.EnemigosEliminados += 1;
	}
	else {
		statsDE.DañoCausado += daño;
	}
}

/// <summary>
/// Permite al jugador usar habilidades durante la batalla, consumiendo mana según la habilidad seleccionada.
/// </summary>
void Juego::UsarHabilidades()
{
	// Muestra la cantidad actual de mana del personaje
	cout << "Mana: " << miPersonaje->getMana() << endl;
	cout << "Selecciona uno de los siguientes Items:" << endl;
	// Itera sobre las habilidades disponibles del personaje y las muestra al jugador
	for (int i = 0; i < 3; i++)
	{
		Habilidades aux = miPersonaje->getHabilidades(i);
		cout << (i + 1) << ". " << aux.nombre << "(" << aux.disponible << ")" << endl;
	}
	cout << "Eleccion: ";
	int opcion;
	cin >> opcion;
	switch (opcion)
	{
	case 1:
	{
		// Verifica si la primera habilidad está disponible y si el personaje tiene suficiente mana para usarla
		Habilidades aux = miPersonaje->getHabilidades(0);
		if (miPersonaje->getMana() >= 25 && aux.disponible) {
			// Ejecuta la primera habilidad y reduce el mana del personaje
			miPersonaje->habilidad1();
			miPersonaje->setMana(miPersonaje->getMana() - 25);
		}
		else {
			cout << "La habilidad aun no ha sido desbloqueda o no tiene suficiente mana" << endl;
		}
		break;
	}	
	case 2:
	{
		// Verifica si la segunda habilidad está disponible y si el personaje tiene suficiente mana para usarla
		Habilidades aux = miPersonaje->getHabilidades(1);
		if (miPersonaje->getMana() >= 50  && aux.disponible) {
			// Ejecuta la segunda habilidad y reduce el mana del personaje
			miPersonaje->habilidad2();
			miPersonaje->setMana(miPersonaje->getMana() - 50);
		}
		else {
			cout << "La habilidad aun no ha sido desbloqueda o no tiene suficiente mana" << endl;
		}
		break;
	}	
	case 3:
	{
		// Verifica si la tercera habilidad está disponible y si el personaje tiene suficiente mana para usarla
		Habilidades aux = miPersonaje->getHabilidades(2);
		if (miPersonaje->getMana() >= 75 && aux.disponible) {
			// Ejecuta la tercera habilidad y reduce el mana del personaje
			miPersonaje->habilidad3();
			miPersonaje->setMana(miPersonaje->getMana() - 75);
		}
		else {
			cout << "La habilidad aun no ha sido desbloqueda o no tiene suficiente mana" << endl;
		}
		break;
	}
	default:
		break;
	}
}

/// <summary>
/// Aplica el daño de la habilidad especial 3 del personaje a los enemigos en la batalla, según la clase del personaje y los efectos de la habilidad.
/// </summary>
/// <param name="enemigos">Vector que contiene los enemigos participantes en la batalla</param>
/// <param name="statsDEH">Estadísticas del daño infligido a los enemigos</param>
void Juego::DañoEnemigosHabilidad3(vector<Enemigo>& enemigos, Estadisticas& statsDEH)
{
	switch (miPersonaje->getClase())
	{
	case GuerreroEn:
		// Si la habilidad está activa, inflige 5 de daño a todos los enemigos
		if (miPersonaje->getHabilidades(2).turnosRestantes > 0)
		{
			for (int i = 0; enemigos.size(); i++) {
				DañarEnemigos(enemigos, statsDEH, i, 5);
			}
		}
		break;
	case ArqueroEn:
		// Si la habilidad está en su primer turno, inflige 10 de daño a todos los enemigos
		if (miPersonaje->getHabilidades(2).turnosRestantes == 5)
		{
			for (int i = 0; enemigos.size(); i++) {
				DañarEnemigos(enemigos, statsDEH, i, 10);
			}
		} 
		else if (miPersonaje->getHabilidades(2).turnosRestantes > 0)
		{
			for (int i = 0; enemigos.size(); i++) {
				DañarEnemigos(enemigos, statsDEH, i, 5);
			}
		}
		break;
	case MagoEn:
		// Si la habilidad está en su primer turno, inflige 10 de daño a todos los enemigos
		if (miPersonaje->getHabilidades(2).turnosRestantes == 7)
		{
			for (int i = 0; enemigos.size(); i++) {
				DañarEnemigos(enemigos, statsDEH, i, 10);
			}
		}
		// Si la habilidad está activa pero no en su primer turno, inflige 5 de daño a todos los enemigos
		else if (miPersonaje->getHabilidades(2).turnosRestantes > 0)
		{
			for (int i = 0; enemigos.size(); i++) {
				DañarEnemigos(enemigos, statsDEH, i, 5);
			}
		}
		break;
	case LadronEn:
		int eleccion = 0;
		// Solicita al jugador que seleccione un enemigo para atacar
		while (eleccion < 1 || eleccion >(enemigos.size()))
		{
			LimpiarPantalla();
			// Solicita al jugador que seleccione un enemigo para atacar
			cout << "A que enemigo deseas atacar?" << endl;
			for (int i = 0; i < enemigos.size(); i++) {
				cout << (i + 1) << ". " << enemigos[i].getNombre() << endl;
			}
			cout << "Enemigo seleccionado: ";
			cin >> eleccion;
		}
		// Realiza el daño específico para la habilidad especial del ladrón
		DañarEnemigos(enemigos, statsDEH, eleccion - 1, 90);
		break;
	}
}

/// <summary>
/// Permite al jugador usar uno de los dos ítems disponibles.
/// </summary>
void Juego::UsarItems()
{
	cout << "Selecciona uno de los siguientes Items:" << endl;
	for (int i = 0; i < 2; i++)
	{
		// Muestra los nombres y la cantidad disponible de los ítems
		Items aux = miPersonaje->getItems(i);
		cout << (i + 1) << ". " << aux.nombre << "(" << aux.cantidad << ")" << endl;
	}
	cout << "Eleccion: ";
	int opcion;
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		// Si el jugador elige el primer ítem, lo usa
		miPersonaje->UsarItem1();
		break;
	case 2:
		// Si el jugador elige el segundo ítem, lo usa
		miPersonaje->UsarItem2();
		break;
	default:
		break;
	}
}

/// <summary>
/// Muestra los datos relevantes de la pelea, incluyendo la vida y el mana del personaje del jugador y los enemigos.
/// </summary>
/// <param name="enemigos">Vector que contiene los enemigos participantes en la batalla</param>
void Juego::DatosDePelea(vector<Enemigo>& enemigos)
{
	// Muestra los datos del personaje del jugador y el primer enemigo
	cout << "Enemigos: " << "\t\t" << miPersonaje->getNombre() << endl
		<< enemigos[0].getNombre() << "\t\t" << "Vida : " << miPersonaje->getVida() << endl
		<< "Vida: " << enemigos[0].getVida() << "\t\t" << "Mana: " << miPersonaje->getMana() << endl
		<< "Nivel: " << enemigos[0].getNivel() << endl;
	// Muestra los datos de los enemigos restantes (si los hay)
	for (int i = 1; i < enemigos.size(); i++)
	{
		cout << enemigos[i].getNombre() << ":" << endl
			<< "Vida: " << enemigos[i].getVida() << endl
			<< "Nivel: " << enemigos[i].getNivel() << endl;
	}

}	

/// <summary>
/// Simula el ataque de los enemigos al personaje del jugador y calcula el daño total infligido.
/// </summary>
/// <param name="enemigos">Vector que contiene los enemigos participantes en la batalla</param>
/// <returns>El total de daño infligido por los enemigos</returns>
int Juego::AtaqueEnemigos(vector<Enemigo>& enemigos)
{
	// Variable para almacenar el total de daño generado por los enemigos
	int dañoGenerado = 0;
	// Itera a través de cada enemigo en el vector
	for (int i = 0; i < enemigos.size(); i++)
	{
		// Calcula el daño generado por el enemigo actual
		int daño;
		int dañoPorPersonaje = CantidadDeDaño(enemigos, i);
		// Ajusta el cálculo del daño para tener en cuenta la fuerza del enemigo
		if ((dañoPorPersonaje - (enemigos[i].getNivel() * 3)) == 0)
		{
			daño = miPersonaje->getReduccionDaño() * ((rand() % (1 + dañoPorPersonaje - (enemigos[i].getNivel() * 3))) + enemigos[i].getNivel());
		}
		else {
			daño = miPersonaje->getReduccionDaño() * ((rand() % (dañoPorPersonaje - (enemigos[i].getNivel() * 3))) + enemigos[i].getNivel());
		}
		// Agrega el daño generado por el enemigo al total de daño
		dañoGenerado += daño;
		if (enemigos[i].getClase() == 10) {
			return daño * 2;
		}
	}
	// Devuelve la mitad del total de daño infligido por los enemigos
	return dañoGenerado;
}

/// <summary>
/// Crea y devuelve un vector de enemigos con el número especificado.
/// </summary>
/// <param name="numEnemigos">Número de enemigos que se crearán</param>
/// <returns>Un vector que contiene los enemigos creados</returns>
vector<Enemigo> Juego::CrearEnemigos(int numEnemigos)
{
	// Vector auxiliar para almacenar los enemigos creados
	vector<Enemigo> aux;
	// Bucle para crear el número especificado de enemigos
	for (int i = 0; i < numEnemigos; i++) {
		// Genera un nombre para el enemigo
		string nombreEnemigo = "Enemigo" + to_string(i + 1);
		// Crea un nuevo enemigo con el nombre generado y otros valores predeterminados
		aux.push_back(Enemigo(nombreEnemigo, "", "", "", 0));
		// Establece el nivel del enemigo basado en el nivel del personaje del jugador
		aux[i].setNivel(nivelEnemigos(miPersonaje->getNivel()));
	}
	// Devuelve el vector que contiene los enemigos creados
	return aux;
}

/// <summary>
/// Crea un jefe enemigo con un nombre aleatorio y un nivel específico.
/// </summary>
/// <param name="nivel">Nivel del jefe enemigo</param>
/// <returns>Un vector que contiene al jefe enemigo creado</returns>
vector<Enemigo> Juego::crearJefe(int nivel)
{
	// Array de nombres de jefes enemigos
	string nombres[] = { "Shrek", "Voldemort", "Thanos", "Darth Vader", "Joker", "Saruman", "Depredador", "Chucky", "Freddy Krueger", "Gollum", "Depredador", "Jason", "Alien", "Keyser Soze", "Pennywise", "Terminator", "Tiburon", "El gato con botas" };
	// Genera un número aleatorio para seleccionar un nombre del array
	int numNombre = (rand() % (18));
	// Crea un nuevo enemigo jefe con el nombre seleccionado y un nivel específico
	Enemigo aux = Enemigo(nombres[numNombre], "", "", "", 10);
	// Crea un vector que contendrá al jefe enemigo
	vector<Enemigo> Jefe;
	Jefe.push_back(aux);
	// Devuelve el vector que contiene al jefe enemigo creado
	return Jefe;
}

/// <summary>
/// Genera aleatoriamente el nivel de los enemigos, basado en el nivel del personaje del jugador.
/// </summary>
/// <param name="nivel">Nivel del personaje del jugador</param>
/// <returns>El nivel generado para los enemigos</returns>
int Juego::nivelEnemigos(int nivel)
{
	// Establece los límites máximo y mínimo para el nivel de los enemigos
	int max = nivel, min = 1;
	// Genera aleatoriamente un valor dentro del rango especificado
	int valor = (rand() % (max - min + 1)) + min;
	// Devuelve el nivel generado para los enemigos
	return valor;
}

/// <summary>
/// Calcula aleatoriamente la cantidad de enemigos que aparecerán en función del nivel del jugador.
/// </summary>
/// <param name="nivel">Nivel del jugador</param>
/// <returns>La cantidad de enemigos generada</returns>
int Juego::CantidaddeEnemigos(int nivel)
{
	// Variables para almacenar los valores mínimos y máximos de la cantidad de enemigos
	int min, max;
	// Determina la cantidad de enemigos basada en el nivel del jugador
	switch (nivel)
	{
	case 0:
	case 1:
		return 1;
	case 2:
	case 3:
	case 4:
	case 5:
		min = 1;
		max = nivel;
		break;
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		min = 2;
		max = (nivel / 2) + 3;
		break;
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
		min = 3;
		max = nivel / 2;
		break;
	case 21:
	case 22:
	case 23:
	case 24:
	case 25:
		min = 5;
		max = (nivel / 2) + 3;
		break;
	case 26:
	case 27:
	case 28:
	case 29:
	case 30:
		min = 8;
		max = 20;
		break;

	default:
		break;
	}
	// Genera aleatoriamente la cantidad de enemigos dentro del rango especificado
	return (rand() % (max - min + 1)) + min;
}

/// <summary>
/// Procesa la muerte del personaje, actualizando estadísticas y recursos del jugador.
/// </summary>
/// <param name="StatsJuego">Estadísticas del juego</param>
void Juego::muertePersonaje(Estadisticas& StatsJuego)
{
	// Informa al jugador sobre su muerte y las consecuencias
	cout << "Has muerto" << endl;
	cout << "Has perdido la mitad de tu dinero" << endl
		<< "Has perdido los recursos ganados anteriormente" << endl;
	// Restaura la vida del personaje al máximo
	miPersonaje->setVida(miPersonaje->getVidaMax());
	// Incrementa el contador de muertes en las estadísticas del juego
	StatsJuego.muertes += 1;
	// Reduce a la mitad el oro del personaje
	miPersonaje->setOro(miPersonaje->getOro() / 2);
	// Actualiza las estadísticas del personaje con las estadísticas actuales del juego
	miPersonaje->ActualizarEstadisticas(StatsJuego);
	// Realiza el cambio de nivel, si es necesario
	CambioDeNivel();
	// Pausa el juego hasta que el jugador presione Enter
	pausa_con_enter();
}

/// <summary>
/// Elimina las habilidades activas del personaje.
/// </summary>
void Juego::eliminarHabilidades()
{
	// Elimina cada una de las habilidades activas del personaje
	miPersonaje->eliminarHabilidad1();
	miPersonaje->eliminarHabilidad2();
	miPersonaje->eliminarHabilidad3();
}

/// <summary>
/// Crea un nuevo personaje basado en la entrada del usuario para nombre, género, raza, orientación y clase.
/// </summary>
/// <returns>Un puntero al personaje creado</returns>
Personaje* Juego::CrearPersonaje()
{
	string nombre, genero, raza, orientacion;
	// Solicita al usuario que introduzca el nombre del personaje
	cout << "Introduce el nombre de tu personaje: ";
	cin >> nombre;
	// Solicita al usuario que introduzca el género del personaje
	int generoNum = 0;
	while (generoNum < 1 || generoNum > 3) {
		cout << "Introduce el genero de tu personaje: " << endl
			<< "1. Hombre" << endl
			<< "2. Mujer" << endl
			<< "3. Otro" << endl
			<< "Seleccion(1-3): ";
		cin >> generoNum;
		switch (generoNum)
		{
		case 1:
			genero = "Hombre";
			break;
		case 2:
			genero = "Mujer";
			break;
		case 3:
			genero = "Otro";
			break;
		default:
			break;
		}
	}
	// Solicita al usuario que introduzca la raza del personaje
	int razaNum = 0;
	while (razaNum < 1 || razaNum > 4)
	{
		cout << "Introduce la raza de tu personaje: " << endl
			<< "1. Humano" << endl
			<< "2. Elfo" << endl
			<< "3. Enano" << endl
			<< "4. Orco" << endl
			<< "Seleccion(1-4): ";
		cin >> razaNum;
		switch (razaNum)
		{
		case 1:
			raza = "Humano";
			break;
		case 2:
			raza = "Elfo";
			break;
		case 3:
			raza = "Enano";
			break;
		case 4:
			raza = "Orco";
			break;
		default:
			break;
		}
	}
	// Solicita al usuario que introduzca la orientación del personaje
	int orientacionNum = 0;
	while (orientacionNum < 1 || orientacionNum > 3)
	{
		cout << "Introduce la orientacion de tu personaje: " << endl
			<< "1. Bueno" << endl
			<< "2. Neutro" << endl
			<< "3. Malo" << endl
			<< "Seleccion: ";
		cin >> orientacionNum;
		switch (orientacionNum)
		{
		case Bueno:
			orientacion = "Bueno";
			break;
		case Neutro:
			orientacion = "Neutro";
			break;
		case Malo:
			orientacion = "Malo";
			break;
		}
	}
	// Solicita al usuario que seleccione la clase del personaje
	int clase = 0;
	while (clase < 1 || clase > 4)
	{
		cout << "Selecciona la clase de tu personaje:" << endl
			<< "1. Guerrero" << endl
			<< "2. Arquero" << endl
			<< "3. Mago" << endl
			<< "4. Ladron" << endl
			<< "Seleccion: ";
		cin >> clase;
		switch (clase)
		{
		case GuerreroEn:
		{
			Guerrero* miGuerrero = new Guerrero(nombre, genero, raza, orientacion, clase);
			return miGuerrero;
			break;
		}
		case ArqueroEn:
		{
			Arquero* miArquero = new Arquero(nombre, genero, raza, orientacion, clase);
			return miArquero;
			break;
		}
			break;
		case MagoEn:
		{
			Mago* miMago = new Mago(nombre, genero, raza, orientacion, clase);
			return miMago;
			break;
		}
			break;
		case LadronEn:
		{
			Ladron* miLadron = new Ladron(nombre, genero, raza, orientacion, clase);
			return miLadron;
			break;
		}
		}
	}
}

/// <summary>
/// Carga un personaje desde un archivo de texto y lo crea en función de los datos obtenidos.
/// </summary>
/// <param name="CargAtrib">Vector de cadenas que contendrá los atributos cargados del archivo</param>
/// <returns>Un puntero al personaje creado</returns>
Personaje* Juego::CargarPersonaje(vector<string>& CargAtrib)
{
	string nombre, genero, raza, orientacion;
	int clase;
	// Se crea la ruta del archivo basada en el nombre de la partida
	string rutaArchivo = "./Scr/" + nombrePartida + ".txt";
	ifstream archivoLeido(rutaArchivo.c_str());
	string linea, dato;
	// Se lee la línea del archivo y se obtienen los datos separados por comas
	while (getline(archivoLeido, linea))
	{
		for (int i = 0; i < linea.size(); i++)
		{
			if (linea[i] == ',')
			{
				CargAtrib.push_back(dato);
				dato = "";
			}
			else
			{
				dato += linea[i];
			}
		}
	}
	// Se extraen los atributos necesarios para crear el personaje
	clase = stoi(CargAtrib[0]);
	genero = CargAtrib[1];
	nombre = CargAtrib[2];
	raza = CargAtrib[3];
	orientacion = CargAtrib[4];
	// Se crea el personaje según la clase obtenida
	switch (clase)
	{
	case GuerreroEn:
	{
		Guerrero* miGuerrero = new Guerrero(nombre, genero, raza, orientacion, clase);
		return miGuerrero;
		break;
	}
	case ArqueroEn:
	{
		Arquero* miArquero = new Arquero(nombre, genero, raza, orientacion, clase);
		return miArquero;
		break;
	}
	break;
	case MagoEn:
	{
		Mago* miMago = new Mago(nombre, genero, raza, orientacion, clase);
		return miMago;
		break;
	}
	break;
	case LadronEn:
	{
		Ladron* miLadron = new Ladron(nombre, genero, raza, orientacion, clase);
		return miLadron;
		break;
	}
	}
}

/// <summary>
/// Actualiza el nivel del personaje segun la experiencia que tiene el personaje.
/// </summary>
void Juego::CambioDeNivel()
{
	int nivel;
	if (miPersonaje->getExp() < Nivel2) {
		nivel = 1;
	}
	else if (miPersonaje->getExp() < Nivel3) {
		nivel = 2;
	}
	else if(miPersonaje->getExp() < Nivel4){
		nivel = 3;
	}
	else if(miPersonaje->getExp() < Nivel5){
		nivel = 4;
	}
	else if(miPersonaje->getExp() < Nivel6){
		nivel = 5;
	}
	else if(miPersonaje->getExp() < Nivel7){
		nivel = 6;
	}
	else if(miPersonaje->getExp() < Nivel8){
		nivel = 7;
	}
	else if(miPersonaje->getExp() < Nivel9){
		nivel = 8;
	}
	else if(miPersonaje->getExp() < Nivel10){
		nivel = 9;
	}
	else if(miPersonaje->getExp() < Nivel11){
		nivel = 10;
	}
	else if(miPersonaje->getExp() < Nivel12){
		nivel = 11;
	}
	else if(miPersonaje->getExp() < Nivel13){
		nivel = 12;
	}
	else if(miPersonaje->getExp() < Nivel14){
		nivel = 13;
	}
	else if(miPersonaje->getExp() < Nivel15){
		nivel = 14;
	}
	else if(miPersonaje->getExp() < Nivel16){
		nivel = 15;
	}
	else if(miPersonaje->getExp() < Nivel17){
		nivel = 16;
	}
	else if(miPersonaje->getExp() < Nivel18){
		nivel = 17;
	}
	else if(miPersonaje->getExp() < Nivel19){
		nivel = 18;
	}
	else if(miPersonaje->getExp() < Nivel20){
		nivel = 19;
	}
	else if(miPersonaje->getExp() < Nivel21){
		nivel = 20;
	}
	else if(miPersonaje->getExp() < Nivel22){
		nivel = 21;
	}
	else if(miPersonaje->getExp() < Nivel23){
		nivel = 22;
	}
	else if(miPersonaje->getExp() < Nivel24){
		nivel = 23;
	}
	else if(miPersonaje->getExp() < Nivel25){
		nivel = 24;
	}
	else if(miPersonaje->getExp() < Nivel26){
		nivel = 25;
	}
	else if(miPersonaje->getExp() < Nivel27){
		nivel = 26;
	}
	else if(miPersonaje->getExp() < Nivel28){
		nivel = 27;
	}
	else if(miPersonaje->getExp() < Nivel29){
		nivel = 28;
	}
	else if(miPersonaje->getExp() < Nivel30){
		nivel = 29;
	}
	else {
		nivel = 30;
	}
	if (nivel > miPersonaje->getNivel()) {
		miPersonaje->setNivel(nivel);
		miPersonaje->setPuntosDeHabilidad(miPersonaje->getPuntosDeHabilidad() + 1);
		miPersonaje->ReSetVida();

	}
	miPersonaje->aumentarAgilidad();
	miPersonaje->aumentarFuerza();
	miPersonaje->aumentarIntelecto();
}

/// <summary>
/// Limpia la pantalla de la consola en sistemas Windows.
/// </summary>
void Juego::LimpiarPantalla()
{
	system("cls");
}

/// <summary>
/// Pausa la ejecución del programa y espera a que el usuario presione la tecla Enter para continuar.
/// </summary>
void Juego::pausa_con_enter()
{
	// Espera a que el usuario presione Enter para continuar
	cout << "Presiona Enter para continuar...";
	cin.ignore();
	cin.get();
}

/// <summary>
/// Convierte una cadena que representa un valor booleano ("1" o "0") en un tipo bool.
/// </summary>
/// <param name="atrib">Cadena que representa el valor booleano</param>
/// <returns>Valor booleano correspondiente a la cadena</returns>
bool Juego::StringtoBool(string atrib)
{
	// Si la cadena es "1", devuelve true
	if (atrib == "1") {
		return true;
	}
	// En cualquier otro caso, devuelve false
	return false;
}
