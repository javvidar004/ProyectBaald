# Baald-Ur C++
## Por: Javier De Alba Ruiz
## Tabla de Contenido
1. [Introduccion](#introduccion)
2. [Informacion general](#Informacion-general)
3. [Estructura del codigo](#Estructura-del-codigo)
	a. [Menus](#menus)
	b. [Creacion y Cargado de Partida](#creacion-y-cargado-de-partida)
	c. [Aventura](#aventura)
	d. [Metodos Adicionales](#metodos-adicionales)
4. [Estructura de las clases de personaje](#estructura-de-las-clases-de-personaje)
5. [Conclusiones](#conclusiones)
### Introduccion
Bald-Ur C++ es un juego de tipo RPG en el cual se busca desarrollar al personaje y evolucionar de manera que se pueda ver un crecimiento en el personaje obteniendo diferentes tipos de objetos que aportan diferentes beneficios a lo largo de la aventura.
Este juego esta desarrollado y construido por medio del paradigma de programación de oreintado a objetos. Para el funcionamiento del siguiente juego se desarrollaron 7 clases distintas con sus respectivos atributos y metodos. La clase juego es la clase principal del juego y dentro de la cual se construye toda la infraestructura del juego.
La clase personaje es la clase más grande de toda la estructura del codigo. Esta clase es la clase padre de las otras 5 clases(Guerrero, Arquero, Mago, Ladron y Enemigo). Las clases hijas heredan la clase personaje, además de eso hay diversos metodos a los que se les aplica el polimorfismo y con ello se logra generar y usar los atributos especificos de cada uno de los tipos de personajes que hay.
La interactividad del juego es muy basica ya que para todos los menus y momentos donde haya que elegir algun objeto o accion siempre salen los indices o numeros de eleccion por lo que es muy facil saber que se debe introducir un numero el cual sera a partir del cual se dara seguimiento segun la eleccion dada.
Para la aventura y donde se da el crecimietno es importante considerar que en un principio lo mas importante es comprar los item para restaurar la vida y el mana ya que por la capacidad de daño del personaje y la cantidad de daño que se llega a recibir del enemigo es lo mas critico para poder tener un buen desarrollo en el juego.
Para el juego es necesario considerar que se debe tener paciencia ya que al ser un juego que no cuenta con intefaz grafica y ser puramente de consola, se puede sentir un tanto monotono el juego, sin embargo, hay grandes posibilidades para seguir adelante y lograr convertirte en el personaje mas poderoso.
***
### Informacion general
La clase juego bajo la cual se estructura todo el juego tiene tan solo dos atributos, estos dos atributos son el nombre de la partida y el apuntador a un objeto de la clase Personaje. Estos dos son suficiente para toda la estructura del juego. El nombre de partida es necesario ya que para evitar errores de escritura al momento de iniciar sesion de una partida ya existente hay un documento 'Partidas.txt' donde se guardan los nombres de las partidas. Y la partida creada se guardan los datos del personaje en el documento con el 'nombrePartida.txt' gracias a esto es que se evitan error entre la interaccion entre el usuario y el juego.
Tambien es importante considerar que como todo se desarrolla dentro de la clase Juego, el unico metodo publico es el 'MenuInicial()' ya que este se llama desde el Source y todos los demás metodos y atributos relacionados con el juego se manejan totalmente dentro de la clase juego por lo que no es necesario ningun otro metodo que sea publico.
La importancia de que sea un apuntador a un objeto de la clase personaje es que con eso se puede guardar un apuntador de la clase hija dentro de un apuntador de la clase padre. Por lo mismo, es que muchos de los metodos se definen como 'virtual' en la clase Personaje, para que existan desde la clase padre y por lo mismo se puedan llamar desde un apuntador de la clase hija, con esto se sobrecargan funciones o considerando que es programacion orientada a objetos es el polimorfismo lo que se aplica en este caso y se logra para no tener que estar usando un 'switch' a lo largo del codigo evaluando la clase del personaje ya que en automatico por ser un apuntador de la clase hija se ejecuta la definicion del metodo que esta en la clase hija. 
El juego a pesar de poder considerarse monotono, se requiere estrategia para lograr seguir subiendo de nivel ya que tiene cierta complejidad y es necesario tener una estrategia en el gasto de recursos desde los primeros para poder escalar de la forma mas eficaz los niveles.
Es importante considerar que al subir de nivel va habiendo mas enemigos por cada escenario y con mayor nivel por lo que es necesario que cada vez que uno entre a la aventura habiendo comprado los item necesarios ya que no se puede salir de un escenario hasta que no se hayan vencido todos los enemigos o hayas muerto. Adicional a ello tambien considerar que por los recursos que se pueden perder al morir se recomienda salir despues de un escenario donde ya hay pocos recursos.
***
## Estructura del codigo
#### Menus
La estructura de los menus es la misma a lo largo de todo el juego y siempre para la interaccion con el usuario ya que es necesario introducir el indice que esta a la izquierda de cada una de las opciones para que de esta forma se sepa lo que se quiere elegir.
Los menus son algo muy recurente en el juego, considerando que es  la principal manera para la toma de decisiones a lo largo de todo el juego. Incluso para las tiendas de habilidades y de equipo se recurre a la estructura de los menus para elegir el producto que se quiera comprar. Simplemente el unico cambio aqui es que no hay un validador en caso de elegir algo fuera de rango, y esta es la forma de salir de la tienda sin tener que elegir un producto forzosamente. 
```cpp
void Juego::NombreDeFuncion()
{
	int opcionMI = 0;
	while (opcionMI != UltimaEleccionDeSalida) {
			cout << "Nombre de Menu"
		<< "Opciones..."
		cin >> opcionMI;
		switch (opcionMI)
		{
		case 1:
			//Metodo a ejecutar
		case 2:
			//Si es la salida, regresas a lo anterior
		default:
			cout << "Selecciona una de las opciones validas" << endl;
			break;
		}
	}
}
```
Algo adicional a considerar de los menus es que son la base de toda navegacion a lo largo del juego.
#### Creacion y Cargado de Partida
La creacion de una nueva partida y el cargado de partida fueron un fundamento en la construccion del juego ya que implica el manejo de archivos. Para realizar cualquiera de estas dos acciones se llaman desde el menuPrincipal. 
Para crear una partida es necesario primero evaluar si exite el documento donde se guardan los nombre de las partidas existentes, de ser necesario se creara el documento donde se guardaran los nombre de las partidas.
Despues, se da la interaccion con el usuario donde el usuario a partir de diversos menus elige las caracteristicas del personaje con el cual se aventurara para convertirse en el ser mas poderoso. Tras elegir los atributos principales del personaje, se designa la clase de personaje y se regresa el apuntador de la clase elegida y a partir de ahi se llama a las funciones sobrecargadas de esa clase.
Para terminar el proceso de creacion del personaje se hace un guardado en el documento que es el proceso inverso de cargar la partida, en lugar de escribir se extraen los datos del documento.
Para el proceso que implica cargar la partida primero se lee la linea sobre la cual estan escritos todos los atributos necesarios por guardar del personaje, ya que hay algunos atributos que se obtienen a partir de otros atributos. En total se guardan 42 atributos del perosnaje en el documento para que se pueda guardar una partida en su totalidad. Esto cubre desde los datos iniciales, hasta las estadisticas, equipamiento, habilidades e items. Los atributos en de la linea que se lee es necesario separarlo en un ciclo for por comas. Los atributos al ser separados se van guardando en un vector.
Guardar partida que esta relacionado, siempre sobreescribe los atributos y datos actuales del personaje en el mismo documento.txt con el nombre de la partida.
```cpp
Personaje* CargarPersonaje(vector<string>& CargAtrib);
```
Para este metodo es donde se separan los datos de los atributos por comas y se pasa por referencia el vector es para que una vez creado la instancia de la clase del personaje, se le puedan adjudicar los demas atributos desde la funcion de cargar partida.
#### Aventura
La aventura es uno de los metodos principales ya que la mayoria de los demas metodos se usan dentro de este para realizar diferentes funciones. Lo primero que se realiza es crear e inicializar la variables necesarias que son acumuladores para actualizar las estadisticas generales del personaje al finalizar la aventura.
Se crean y se definen la cantidad de escenarios que se jugaran en la aventura. Desppues se entra a un ciclo que se delimita por la cantidad de escenarios donde te manda a la batalla.
```cpp
void Batalla(vector<Enemigo>, Estadisticas&);
vector<Enemigo> CrearEnemigos(int numEnemigos);
int CantidaddeEnemigos(int nivel);

Batalla(CrearEnemigos(CantidaddeEnemigos(miPersonaje->getNivel())), StatsJuego);
```
Debido a la necesidad de crear los enemigos y mandarlos a la batalla, que es donde se define la cantidad de enemigos contra la que se enfrentara el usuario en ese escenario y tambien se pasa por referencia las estadisticas para al final actualizarlas. La batalla finaliza cuando el vector de enemigos tiene tamaño cero o cuando la vida del personaje es 0 o menor. La cantidad de enemigos y el nivel de los mismo se hace a partir del nivel del usuario.
Dentro de la batalla hay dos opciones se usa un contador y dependiendo si es par o non se define de quien es turno. Cuando es turno del usuario, se le dan diferentes opciones sobre que podria hacer.
```cpp
void MenuPelea(vector<Enemigo>& enemigos, Estadisticas& estatsJuego);
void Atacar(vector<Enemigo>& enemigos, Estadisticas& statsJA);
void DañarEnemigos(vector<Enemigo>& enemigos, Estadisticas& statsDE, int indiceDE, int daño);
void DañoEnemigosHabilidad3(vector<Enemigo>& enemigos, Estadisticas& statsDEH);

MenuPelea(enemigos, stats);
Atacar(enemigos, estatsJuego);
DañarEnemigos(enemigos, statsJA, eleccion - 1, (CantidadDeDaño() + miPersonaje->getAgilidad() + miPersonaje->getFuerza() + miPersonaje->getIntelecto()));
DañoEnemigosHabilidad3(enemigos, estatsJuego);
```
Aqui se pasan los enemigos por referencia para que cuando el usuario utilice una habilidad que ataque o decida atacar, al reducir la vida a los enemigos se vea reflejado hasta la batalla que es la que evalua si aun hay enemigos vivos.
Para apoyar en los diversos recursos visuales que se dan en la batalla para saber los datos necesarios de los enemigos se usa el siguiente metodo:
```cpp
void DatosDePelea(vector<Enemigo>& enemigos);
DatosDePelea(enemigos);
```
En caso de tener una victoria en un escenario, se da la oportunidad de jugar otro en caso de que se haya definido de forma random o tambien enfrentar un jefe, sin embargo, y para esto se crea un jefe usando los mismo metodos de ataque, lo que cambia es que se crea de una forma distinta.
A pesar de saber que tan solo se va a guardar un objeto dentro de ese vector se recurrio a vectores para que asi se puedan usar los mismos metodos que pasan por referencia un vector con objetos de tipo Enemigo.
Cuando el usuario muere en un escenario se va al metodo:
```cpp
void muertePersonaje(Estadisticas& StatsJuego);
muertePersonaje(StatsJuego);
```
Donde se actualizan las estadisticas añadiendo una muerte al usuario y le reduce el oro a la mitad, por lo que morir implica un gran retraso en el desarrollo del personaje.
El cambio de nivel fue algo requerido que se evalua a partir del nivel de experiencia del personaje que va aumentando por los enemigos que uno va matando. Los puntos de experiencia que obtienes equivalen al nivel del enemigo al que te enfrentas.
```cpp
void Juego::CambioDeNivel()
CambioDeNivel();
```
#### Metodos Adicionales
```cpp
void LimpiarPantalla()
void pausa_con_enter()
bool StringtoBool(string atrib)
```
Estos son metodos adicionales que simplemente son de apoyo para estetica, diseño o simplificar algun proceso dentro del juego. Limpiar pantalla es un metodo meramente estetico para la navegacion del juego sin llenar la consola de texto. pausa_con_enter es un metodo de apoyo para que el usuario pueda leer ciertos mensajes emergentes sobre todo cuando elige un valor invalida y se lee que no es valido y es necesario que el usuario lo lea para que pueda seguir su navegacion. Finalmente, el ultimo se usa al cargar una partida y hay que transaformar el carater '1' o '0' a dato de tipo bool.

## Estructura de las clases de personaje
```cpp
public:
	NombreDeClase(string, string, string, string, int);
	~NombreDeClase();

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
```
Asi es como se estructuran las 4 clase de personaje(Guerrero, Arquero, Mago y Ladron), todos los metodos usados dentro de estas clases y que son definidas, son funciones sobrecargadas.
Esto se debe a que sobre todo el equipamiento y las habilidades cambian de clase a clase por lo que fue necesario que se definieran de forma distinta. Simplemente con el cambio de lo que habia que ejecutar en las habilidades era necesario definirlas de forma distinta, quizas hubo funciones que si se pudieron haber definido en la clase Personaje pero por tema de claridad persona y ver como estaba definida cada cosa es que todas se definieron dentro de la clase hija.
Los getters y setters de Equipamiento, Habilidades e Items, son importantes ya que se usan tanto en el guardado y carga de partida, como en la aventura al usar alguno de estos o al tener que quitar y desactivar alguno de los que ya se uso o reducir la cantidad que hay en inventario.
Se estructuro el activador de las habilidades y el que la elimina debido a que sus efectos necesitan durar un turno del personaje por lo que en el momento en el que el usuario usa una habilidad se necesita usar el eliminador que dependiendo del tipo y duracion de la habilidad es si se quitan sus efectos o se van reduciendo los turnos hasta que llega a cero y eliminar en su totalidad de los efectos de la habilidad.
El cambio de equipo se usa al entrar en la tienda y ya poseer un objeto se elije como si se fuera a comprar, sin embargo, al ya poseerlo simplemente se equipa y revisa que no este equipado algun otro objeto de la misma clase, pues solo se puede tener equipado un arma, una armadura, unas botas, un amuleto y un casco.
'AumDañoEquip()' y 'RedDañoEquip()' son funciones que evaluando que se tiene equipado determinan que tanto aumentan el daño propio o reducen el daño del enemigo respectivamente.
Como se habia explicado anteriormente todos estos metodos se ejecutan por medio de que se usa un apuntador de la clase Personaje donde se puede guardar un apuntados de cualquiera de estas clases hijas.
Tambien recordar que el heredar todos los getters y setters de la clase personaje, se usan mucho para modificar todos los atributos que comparten todas las clases como es la vida, mana, experiencia, oro, nivel, entre muchos otros.
## Conclusiones
Para fines del juego se puede ver que hay cierta dificultad del juego, sin embargo, esta considerado asi ya que equipando el diferente equipo y usando habilidades se puede reducir el daño del enemigo en un 90% y se puede aumentar el daño del personaje por lo que si el usuario se desarrolla y juega de manera estrategica se puede lograr obtener grandes beneficios.
Es importante aclarar que con los 4 tipos de clases que puede ser el personaje no determina si se puede alcanzar e exito, con todos se puede, simplemente algunos tienen una cierta ventaja pero esto unicamente por las habilidades que se pueden desbloquear.
Es un juego que implica estrategia y con un pensamiento critico se puede lograr llegar al nivel 30 que es el maximo.
Finalmente, se aplica todo lo visto a lo largo de la clase en el presente proyecto para desarrollar el juego y se busco hacer el juego en la menor cantidad posible de lineas de codigo. 
