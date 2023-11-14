#include "Commons.h"
#include "Player.h"

class
	Aventura {
public:
	//Menu principal
	void
		Personaje() {
		cout << "1- Iniciar juego." << endl;
		cout << "2- Cerrar juego" << endl;
		cout << endl;
		int op;
		cout << "Selecciona una opcion: ";
		cin >> op;
		switch (op) {

		case 1:
			Start();
			break;

		case 2:
			exit(0);
			break;

		default:
			cout << "Opcion no valida. " << endl;
			break;
		}
	}

	void
		Start() {
		Jugador	player;
		player.vida = 3;
		player.item = 0;
		player.item2 = 0;
		player.bomba = 1;
		player.boss = 20;
		cout << endl;
		cout << "No recuerdas quien eres..." << endl;
		cout << "No sabes como llegaste aqui..." << endl;
		cout << "Pero tu instinto te dice que debes escapar." << endl;
		cout << endl;
		cout << "1- Continuar" << endl;
		cout << endl;
		int op;
		cin >> op;
		switch (op) {
		case 1:
			Cuarto01(player);
			break;
		}
	}

	//Cuarto 01 (Inicial)
	void
		Cuarto01(Jugador& player) {
		//Stats Actuales del Jugador
		cout << endl;
		cout << "Vida:" << player.vida << endl;
		cout << "Ataque:" << player.bomba << endl;
		cout << endl;
		cout << "Despiertas en una habitacion completamente vacia" << endl;
		cout << "A excepcion de (n) puertas que ahi se encuentran." << endl;
		cout << "0- Abrir puerta Blanca." << endl;
		cout << "1- Abrir puerta Azul." << endl;
		cout << "2- Abrir puerta Amarilla." << endl;
		cout << "3- Abrir puerta Roja." << endl;
		cout << endl;
		int op;
		cin >> op;
		switch (op) {

		case 0:
			Cuarto_(player);
			break;

		case 1:
			Sala_4(player);
			break;

		case 2:
			Sala_3(player);
			break;

		case 3:
			Sala_2(player);
			break;

		default:
			cout << endl;
			cout << "Las dudas inundan tu mente... Intentalo nuevamente." << endl;
			cout << endl;
			break;
		}
	}

	//Cuarto_ (n)
	void
		Cuarto_(Jugador player) {
		//Stats Actuales del Jugador
		cout << "----------------------------------------" << endl;
		cout << "Vida:" << player.vida << endl;
		cout << "Bombas:" << player.bomba << endl;
		cout << "----------------------------------------" << endl;
		cout << "Este cuarto esta rodeado por algunas fogatas." << endl;
		cout << "Y en frente de ti hay un pedestal." << endl;
		cout << "Sin embargo este esta rodeado por unas rocas" << endl;

		cout << "Que debo hacer?" << endl;
		cout << "1- Tomar Brimstone (4 Bombas)" << endl;
		cout << "2- Volver a la sala anterior" << endl;
		int op;
		cin >> op;
		switch (op) {
		case 1:
			//Evento de Bomba: Si el jugador tiene las bombas necesarias podra acceder a las recompensas.
			if
				(player.bomba == 4) {
				cout << "----------------------------------------" << endl;
				cout << "Con las 4 bombas lograste romper las rocas." << endl;
				cout << "Tomaste El Brimstone: Destruye enemigos con un potente laser." << endl;
				cout << "Despues de ello has decidido volver a la sala anterior." << endl;
				player.bomba -= 1;
				player.item2 = 1;
				Cuarto01(player);
			}
			else if
				(player.bomba < 4) {
				cout << "Al no tener suficientes bombas decidiste volver por donde viniste." << endl;
				cout << "----------------------------------------" << endl;
				Cuarto01(player);
			}
			break;

		case 2:
			Cuarto01(player);
			break;

			//Gamer Over: Por oprimir otro boton
		default:
			cout << "----------------------------------------" << endl;
			cout << "Explotaste sin ninguna razon . . ." << endl;
			cout << "GAME OVER" << endl;
			cout << "----------------------------------------" << endl;
			break;
		}
	}

	//Cuarto 02 (Puerta Azul)
	void
		Sala_2(Jugador player) {
		//Stats Actuales del Jugador
		cout << "----------------------------------------" << endl;
		cout << "Vida:" << player.vida << endl;
		cout << "Ataque:" << player.bomba << endl;
		cout << endl;
		cout << "." << endl;
		cout << "Que debo hacer?" << endl;
		cout << "1- Pelear." << endl;
		cout << "2- Investigar." << endl;
		cout << "3- Volver a la sala anterior." << endl;
		int op;
		cin >> op;
		switch (op) {
		case 1:
			cout << "----------------------------------------" << endl;
			cout << "Sin piedad acabaste con las moscas." << endl;
			cout << "Ahora que debo hacer?" << endl;
			cout << "1- Investigar." << endl;
			cout << "2- Volver a la sala anterior." << endl;
			cin >> op;
			switch (op) {

			case 1:
				cout << "----------------------------------------" << endl;
				cout << "Investigando un poco te percatas de una grieta." << endl;
				//Evento de Bomba: Si el jugador tiene 1 bomba  podra acceder a las recompensas.
				if
					(player.bomba >= 1) {
					cout << "Al tener una bomba lograste romper la pared y entrar a la sala secreta." << endl;
					cout << "En la Sala encontraste 2 corazones de alma." << endl;
					cout << "Decidiste volver a la sala anterior." << endl;
					cout << "----------------------------------------" << endl;
					player.bomba -= 1;
					player.vida += 2;
					Cuarto01(player);
				}
				else if
					(player.bomba == 0) {
					cout << "Al no tener una bomba decidiste volver por donde viniste." << endl;
					Cuarto01(player);
				}
				break;

			case 2:
				Cuarto01(player);
				break;
			}
			break;

		case 2:
			cout << "----------------------------------------" << endl;
			cout << "Gracias a las piedras pudiste cubrirte y evadir las moscas" << endl;
			cout << "Investigando un poco te percatas de una grieta." << endl;
			//Evento de Bomba: Si el jugador tiene 1 bomba  podra acceder a las recompensas.
			if
				(player.bomba >= 1) {
				cout << "Al tener una bomba lograste romper la pared y entrar a un cuarto secreta." << endl;
				cout << "En la Sala encontraste 2 corazones de alma." << endl;
				cout << "Decidiste volver a la sala anterior." << endl;
				cout << "----------------------------------------" << endl;
				player.bomba -= 1;
				player.vida += 2;
				Cuarto01(player);
			}
			else if
				(player.bomba == 0) {
				cout << "Al no tener una bomba decidiste volver por donde viniste." << endl;
				cout << "----------------------------------------" << endl;
				Cuarto01(player);
			}
			break;

		case 3:
			Cuarto01(player);
			break;

			//Gamer Over: Por oprimir otro boton
		default:
			cout << "----------------------------------------" << endl;
			cout << "Explotaste sin ninguna razon . . ." << endl;
			cout << "GAME OVER" << endl;
			cout << "----------------------------------------" << endl;
			break;
		}
	}

	//Cuarto 03 (Puerta Amarilla)
	void
		Sala_3(Jugador player) {
		//Stats Actuales del Jugador
		cout << "----------------------------------------" << endl;
		cout << "Vida:" << player.vida << endl;
		cout << "Bombas:" << player.bomba << endl;
		cout << "----------------------------------------" << endl;
		cout << "En el cuarto solo hay algunas cacas tiradas por el suelo . . ." << endl;
		cout << "Que debo hacer?" << endl;
		cout << "1- Investigar." << endl;
		cout << "2- Volver a la sala anterior." << endl;
		cout << "----------------------------------------" << endl;
		int op;
		cin >> op;
		switch (op) {
		case 1:
			cout << "----------------------------------------" << endl;
			cout << "Investigando un poco pisaste algunas de las cacas . . ." << endl;
			cout << "Que asco . . . " << endl;
			cout << "Con suerte y por extraño que paresca." << endl;
			cout << "Encontraste una bomba." << endl;
			cout << "Al final decidiste volver por donde viniste." << endl;
			cout << "----------------------------------------" << endl;
			player.bomba += 1;
			Cuarto01(player);
			break;

		case 2:
			Cuarto01(player);
			break;

			//Gamer Over: Por oprimir otro boton
		default:
			cout << "----------------------------------------" << endl;
			cout << "Explotaste sin ninguna razon . . ." << endl;
			cout << "GAME OVER" << endl;
			cout << "----------------------------------------" << endl;
			break;
		}
	}

	//Cuarto 04 (Puerta Roja)
	void
		Sala_4(Jugador player) {
		//Stats Actuales del Jugador
		cout << "----------------------------------------" << endl;
		cout << "Vida:" << player.vida << endl;
		cout << "Bombas:" << player.bomba << endl;
		cout << "----------------------------------------" << endl;
		cout << "En el cuarto hay algunos Gapers merodado." << endl;
		cout << "Y al fondo se alcanza a ver otra puerta." << endl;
		cout << "Que debo hacer?" << endl;
		cout << "1- Pelear." << endl;
		cout << "2- Investigar." << endl;
		cout << "3- Huir." << endl;
		cout << "4- Volver a la sala anterior." << endl;
		cout << "----------------------------------------" << endl;
		int op;
		cin >> op;
		switch (op) {
		case 1:
			cout << "----------------------------------------" << endl;
			cout << "Con un poco de suerte acabaste con todos los Gapers" << endl;
			cout << "Ahora que debo hacer?" << endl;
			cout << "1- Ir por la puerta de la izquierda." << endl;
			cout << "2- Volver a la sala anterior." << endl;
			cin >> op;
			switch (op) {

			case 1:
				Sala_5(player);
				break;

			case 2:
				cout << "----------------------------------------" << endl;
				cout << "Decidiste volver por donde viniste." << endl;
				cout << "----------------------------------------" << endl;
				Cuarto01(player);
				break;

				//Gamer Over: Por oprimir otro boton
			default:
				cout << "----------------------------------------" << endl;
				cout << "Explotaste sin ninguna razon . . ." << endl;
				cout << "GAME OVER" << endl;
				cout << "----------------------------------------" << endl;
				break;
			}
			break;

		case 2:
			if (player.item == 2) {
				cout << "----------------------------------------" << endl;
				cout << "Investigaste la zona volando pero no habia nada." << endl;
				cout << "Decidiste ir al siguiente cuarto." << endl;
			}
			else {
				cout << "----------------------------------------" << endl;
				cout << "Intentaste investigar pero los Gapers te alcanzaron a morder." << endl;

				player.vida -= 1;
				if (player.vida <= 0) {
					cout << "----------------------------------------" << endl;
					cout << "Ya no tienes vida . . ." << endl;
					cout << "GAME OVER" << endl;
					cout << "----------------------------------------" << endl;
				}
				else if (player.vida > 0) {
					cout << "Tuviste que retroceder al cuarto anterior." << endl;
					cout << "----------------------------------------" << endl;
					Cuarto01(player);
				}
			}
			break;

		case 3:
			if (player.item == 2) {
				cout << "----------------------------------------" << endl;
				cout << "Pasaste por arriba de los enemigos sin problema." << endl;
				Sala_5(player);
			}
			else {
				cout << "----------------------------------------" << endl;
				cout << "Corriste hacia la puerta pero los Gapers te acorralaron." << endl;
				//Verificador de Vida: Cuando esta llega a 0 Sera Game Over
				//Si aun tiene vida este podra continuar
				player.vida -= 2;
				if (player.vida <= 0) {
					cout << "----------------------------------------" << endl;
					cout << "Ya no tienes vida . . ." << endl;
					cout << "GAME OVER" << endl;
					cout << "----------------------------------------" << endl;
				}
				else if (player.vida > 0) {
					cout << "Con dificultad llegaste a la puerta." << endl;
					Sala_5(player);
				}
			}
			break;

		case 4:
			Cuarto01(player);
			break;

			//Gamer Over: Por oprimir otro boton
		default:
			cout << "----------------------------------------" << endl;
			cout << "Explotaste sin ninguna razon . . ." << endl;
			cout << "GAME OVER" << endl;
			cout << "----------------------------------------" << endl;
			break;
		}
	}

	//Cuarto 05 (Puerta Morada)
	void
		Sala_5(Jugador player) {
		//Stats Actuales del Jugador
		cout << "----------------------------------------" << endl;
		cout << "Vida:" << player.vida << endl;
		cout << "Bombas:" << player.bomba << endl;
		cout << "----------------------------------------" << endl;
		cout << "En el cuarto hay un cofre en el centro pero esta rodeado por algunas piedras." << endl;
		cout << "Ademas se puede ver 3 puertas mas en la habitacion." << endl;
		cout << "Que debo hacer?" << endl;
		cout << "1- Investigar" << endl;
		cout << "2- Ir por la puerta de la izquierda" << endl;
		cout << "3- Ir por la puerta de arriba." << endl;
		cout << "4- Ir por la puerta de abajo." << endl;
		cout << "5- Volver a la sala anterior" << endl;
		cout << "----------------------------------------" << endl;
		int op;
		cin >> op;
		switch (op) {

		case 1:
			//Evento de Bomba: Si el jugador tiene 1 bomba  podra acceder a las recompensas.
			if
				(player.bomba >= 1) {
				cout << "Al tener una bomba lograste romper las rocas." << endl;
				cout << "Dentro del cofre habia 3 corazones de alma" << endl;
				cout << "----------------------------------------" << endl;
				player.vida += 3;
				player.bomba -= 1;
				cout << "Ahora que debo hacer?" << endl;
				cout << "1- Ir por la puerta de la izquierda." << endl;
				cout << "2- Ir por la puerta de arriba." << endl;
				cout << "3- Ir por la puerta de abajo." << endl;
				cout << "4- Volver a la sala anterior" << endl;
				cin >> op;
				switch (op) {

				case 1:
					Sala_7(player);
					break;

				case 2:
					Sala_8(player);
					break;

				case 3:
					Sala_6(player);
					break;

				case 4:
					Sala_4(player);
					break;
				}
			}
			else if
				(player.bomba == 0) {
				cout << "Pateaste la roca . . ." << endl;
				cout << "Eso dolio." << endl;
				player.vida -= 1;
				//Verificador de Vida: Cuando esta llega a 0 Sera Game Over
				//Si aun tiene vida este podra continuar
				if (player.vida <= 0) {
					cout << "----------------------------------------" << endl;
					cout << "Ya no tienes vida . . ." << endl;
					cout << "GAME OVER" << endl;
					cout << "----------------------------------------" << endl;
				}
				else if (player.vida > 0) {

					cout << "Ahora que debo hacer?" << endl;
					cout << "1- Ir por la puerta de la izquierda." << endl;
					cout << "2- Ir por la puerta de arriba." << endl;
					cout << "3- Ir por la puerta de abajo." << endl;
					cout << "4- Volver a la sala anterior." << endl;
					cin >> op;
					switch (op) {

					case 1:
						Sala_7(player);
						break;

					case 2:
						Sala_8(player);
						break;

					case 3:
						Sala_6(player);
						break;

					case 4:
						Sala_4(player);
						break;
					}
				}
			}
			break;

		case 2:
			Sala_7(player);
			break;

		case 3:
			Sala_8(player);
			break;

		case 4:
			Sala_6(player);
			break;

		case 5:
			Sala_4(player);
			break;

			//Gamer Over: Por oprimir otro boton
		default:
			cout << "----------------------------------------" << endl;
			cout << "Explotaste sin ninguna razon . . ." << endl;
			cout << "GAME OVER" << endl;
			cout << "----------------------------------------" << endl;
			break;
		}
	}

	//Cuarto 06 (Puerta Verde)
	void
		Sala_6(Jugador player) {
		//Stats Actuales del Jugador
		cout << "----------------------------------------" << endl;
		cout << "Vida:" << player.vida << endl;
		cout << "Bombas:" << player.bomba << endl;
		cout << "----------------------------------------" << endl;
		cout << "En el cuarto hay varias arañas y en el suelo hay varios picos." << endl;
		cout << "Que debo hacer?" << endl;
		cout << "1- Pelear." << endl;
		cout << "2- Investigar." << endl;
		cout << "3- Volver a la sala anterior." << endl;
		int op;
		cin >> op;
		switch (op) {

		case 1:
			if (player.item2 == 1) {
				cout << "----------------------------------------" << endl;
				cout << "El laser destruyo todo a su paso." << endl;
				cout << "Al vencer encontraste una bomba" << endl;
				cout << "Al final decides volver a la sala anterior." << endl;
				player.bomba += 1;
				Sala_5(player);
			}
			else if (player.item == 2) {
				cout << "----------------------------------------" << endl;
				cout << "Eliminaste sin problema a todos los enemigos." << endl;
				cout << "Al vencer encontraste una bomba" << endl;
				cout << "Al final decides volver a la sala anterior." << endl;
				player.bomba += 1;
				Sala_5(player);
			}
			else {
				cout << "----------------------------------------" << endl;
				cout << "La pelea fue complicada pero las arañas fueron eliminadas." << endl;
				cout << "En el combate te picaste con los picos." << endl;
				player.vida -= 1;
				if
					//Verificador de Vida: Cuando esta llega a 0 Sera Game Over
					//Si aun tiene vida este podra continuar
					(player.vida <= 0) {
					cout << "----------------------------------------" << endl;
					cout << "Ya no tienes vida . . ." << endl;
					cout << "GAME OVER" << endl;
					cout << "----------------------------------------" << endl;
				}
				else if (player.vida > 0) {
					cout << "Pero al vencer encontraste una bomba" << endl;
					cout << "Al final decides volver a la sala anterior." << endl;
					player.bomba += 1;
					Sala_5(player);
				}
			}

			break;

		case 2:
			if (player.item == 2) {
				cout << "----------------------------------------" << endl;
				cout << "Investigaste la zona volando pero no habia nada." << endl;
				cout << "Al final decides volver a la sala anterior." << endl;
				Sala_5(player);
			}
			else {
				cout << "----------------------------------------" << endl;
				cout << "Intentaste investigar pero las arañas te atacaron sin piedad." << endl;
				cout << "Ademas te te picaste con los picos al intentar huir." << endl;
				cout << "Esto te hizo regresar a la sala anterior." << endl;
				player.vida -= 2;
				if
					//Verificador de Vida: Cuando esta llega a 0 Sera Game Over
					//Si aun tiene vida este podra continuar
					(player.vida <= 0) {
					cout << "----------------------------------------" << endl;
					cout << "Ya no tienes vida . . ." << endl;
					cout << "GAME OVER" << endl;
					cout << "----------------------------------------" << endl;
				}
				else if (player.vida > 0) {
					Sala_5(player);
				}
			}
			break;

		case 3:
			Sala_5(player);
			break;

			//Gamer Over: Por oprimir otro boton
		default:
			cout << "----------------------------------------" << endl;
			cout << "Explotaste sin ninguna razon . . ." << endl;
			cout << "GAME OVER" << endl;
			cout << "----------------------------------------" << endl;
			break;
		}
	}

	//Cuarto 07 (Puerta Naranja)
	void
		Sala_7(Jugador player) {
		//Stats Actuales del Jugador
		cout << "----------------------------------------" << endl;
		cout << "Vida:" << player.vida << endl;
		cout << "Bombas:" << player.bomba << endl;
		cout << "----------------------------------------" << endl;
		cout << "Al entrar la puerta del cuarto se cierra." << endl;
		cout << "Enfrete tienes 2 botones." << endl;
		cout << "Que debo hacer?" << endl;
		cout << "1- Presionar el boton 1." << endl;
		cout << "2- Presionar el boton 2." << endl;
		int op;
		cin >> op;
		switch (op) {
		case 1:
			cout << "----------------------------------------" << endl;
			cout << "Pisaste el boton 1 . . ." << endl;
			cout << "Para tu suete la puerta se abrio." << endl;
			cout << "Rapidamente saliste del cuarto." << endl;
			Sala_5(player);
			break;

		case 2:
			cout << "----------------------------------------" << endl;
			cout << "Pisaste el boton 2 . . ." << endl;
			cout << "De la nada aparecieron 2 moscas explosivas." << endl;
			cout << "Te estallaron en la cara . . ." << endl;
			player.vida -= 2;
			if
				//Verificador de Vida: Cuando esta llega a 0 Sera Game Over
				//Si aun tiene vida este podra continuar
				(player.vida <= 0) {
				cout << "----------------------------------------" << endl;
				cout << "Ya no tienes vida . . ." << endl;
				cout << "GAME OVER" << endl;
				cout << "----------------------------------------" << endl;
			}
			else if
				(player.vida > 0) {
				cout << "Con suerte estallaron la puerta." << endl;
				cout << "Volviste a la sala anterior" << endl;
				Sala_5(player);
			}
			break;

			//Gamer Over: Por oprimir otro boton
		default:
			cout << "----------------------------------------" << endl;
			cout << "Explotaste sin ninguna razon . . ." << endl;
			cout << "GAME OVER" << endl;
			cout << "----------------------------------------" << endl;
			break;
		}
	}

	//Cuarto 08 (Puerta Gris)
	void
		Sala_8(Jugador player) {
		//Stats Actuales del Jugador
		cout << "----------------------------------------" << endl;
		cout << "Vida:" << player.vida << endl;
		cout << "Bombas:" << player.bomba << endl;
		cout << "----------------------------------------" << endl;
		cout << "Al horizonte unas moscas explosivas se hacercan rapidamente." << endl;
		cout << "Sin embargo a la distancia igualmete vez una puerta." << endl;
		cout << "Pero esta bloqueado por unos picos." << endl;
		cout << "Que debo hacer?" << endl;
		cout << "1- Pelear." << endl;
		cout << "2- Huir." << endl;
		cout << "3- Volver a la sala anterior." << endl;
		int op;
		cin >> op;
		switch (op) {
		case 1:
			cout << "----------------------------------------" << endl;
			cout << "Logras derribarlos antes que lleguen." << endl;
			cout << "Gracias a ellos los picos se han retraido." << endl;
			Sala_9(player);
			break;

		case 2:
			if (player.item == 2) {
				cout << "----------------------------------------" << endl;
				cout << "Evadiste a las moscas facilmente y pasa por los ahires los picos." << endl;
				cout << "Y asi pasaste de a gratis al siguiente cuarto." << endl;
			}
			else
			{
				cout << "----------------------------------------" << endl;
				cout << "Corriste como loco y te explotaron en la cara." << endl;
				cout << "Te valio comino los picos y pasaste sobre ellos." << endl;
				player.vida -= 3;
				if
					//Verificador de Vida: Cuando esta llega a 0 Sera Game Over
					//Si aun tiene vida este podra continuar
					(player.vida <= 0) {
					cout << "----------------------------------------" << endl;
					cout << "Ya no tienes vida . . ." << endl;
					cout << "GAME OVER" << endl;
					cout << "----------------------------------------" << endl;
				}
				else if
					(player.vida > 0) {
					cout << "Obviamente dolio pero valio la pena." << endl;
					Sala_9(player);
				}
			}

			break;

		case 3:
			Sala_5(player);
			break;

			//Gamer Over: Por oprimir otro boton
		default:
			cout << "----------------------------------------" << endl;
			cout << "Explotaste sin ninguna razon . . ." << endl;
			cout << "GAME OVER" << endl;
			cout << "----------------------------------------" << endl;
			break;
		}
	}

	//Cuarto 09 (Puerta Negra)
	void
		Sala_9(Jugador player) {
		//Stats Actuales del Jugador
		cout << "----------------------------------------" << endl;
		cout << "Vida:" << player.vida << endl;
		cout << "Bombas:" << player.bomba << endl;
		cout << "----------------------------------------" << endl;
		cout << "En el cuarto parece haber algunas rocas en las esquinas." << endl;
		cout << "A la vez una puerta con apariencia siniestra se encuentra a la derecha del cuarto." << endl;
		cout << "Que debo hacer?" << endl;
		cout << "1- Ir por la Puerta Siniestra." << endl;
		cout << "2- Investigar." << endl;
		cout << "3- Volver a la sala anterior." << endl;
		int op;
		cin >> op;
		switch (op) {

		case 1:
			Sala_10(player);
			break;

		case 2:
			cout << "----------------------------------------" << endl;
			cout << "Investigando un poco te percatas de una grieta." << endl;
			//Evento de Bomba: Si el jugador tiene 1 bomba  podra acceder a las recompensas.
			if
				(player.bomba >= 1) {
				cout << "Al tener una bomba lograste romper la pared y entrar a la sala secreta." << endl;
				cout << "En la Sala encontraste 4 corazones de alma." << endl;
				cout << "Decidiste volver a la sala anterior." << endl;
				cout << "----------------------------------------" << endl;
				player.bomba -= 1;
				player.vida += 4;
				Sala_9(player);
			}
			else if
				(player.bomba == 0) {
				cout << "Al no tener una bomba decidiste volver por donde viniste." << endl;
				cout << "----------------------------------------" << endl;
				Sala_9(player);
				break;
			}

		case 3:
			Sala_8(player);
			break;

			//Gamer Over: Por oprimir otro boton
		default:
			cout << "----------------------------------------" << endl;
			cout << "Explotaste sin ninguna razon . . ." << endl;
			cout << "GAME OVER" << endl;
			cout << "----------------------------------------" << endl;
			break;
		}
	}

	//Cuarto 10 (Puerta Blanca)
	void
		Sala_10(Jugador player) {
		//Stats Actuales del Jugador
		cout << "----------------------------------------" << endl;
		cout << "Vida:" << player.vida << endl;
		cout << "Bombas:" << player.bomba << endl;
		cout << "----------------------------------------" << endl;
		cout << "Al entrar solo puedes ver una inmesa oscuridad . . ." << endl;
		cout << "Sin embargo escuchas una voz familiar." << endl;
		cout << "-Isssaaaac" << endl;
		cout << "Mama ha aparecido" << endl;
		cout << "Que debo hacer?" << endl;
		cout << "1- Pelear Contra Mama" << endl;
		int op;
		cin >> op;
		switch (op) {
		case 1:
			Final(player);
			break;

			//Gamer Over: Por oprimir otro boton
		default:
			cout << "----------------------------------------" << endl;
			cout << "Explotaste sin ninguna razon . . ." << endl;
			cout << "GAME OVER" << endl;
			cout << "----------------------------------------" << endl;
			break;
		}
	}

	//Jefe Final: Si la salud del Jefe llega a 0 el Juego Termina.
	void
		Final(Jugador player) {
		if
			(player.boss >= 1) {
			//Stats Actuales del Jugador y del Jefe Final
			cout << "----------------------------------------" << endl;
			cout << "Vida:" << player.vida << endl;
			cout << "Bombas:" << player.bomba << endl;
			cout << "----------------------------------------" << endl;
			cout << "Vida de Mama:" << player.boss << endl;
			cout << "----------------------------------------" << endl;
			cout << "Que debo hacer?" << endl;
			cout << "1- Ir por el Pie" << endl;
			cout << "2- Usar Bomba" << endl;
			cout << "3- Esquivar" << endl;
			int op;
			cin >> op;
			switch (op) {

			case 1:
				cout << "----------------------------------------" << endl;
				cout << "Atacas con todo Mama perdio 2 de vida pero igualmete contraataca." << endl;
				player.boss -= 2;
				player.vida -= 1;
				if
					//Verificador de Vida: Cuando esta llega a 0 Sera Game Over
					//Si aun tiene vida este podra continuar
					(player.vida <= 0) {
					cout << "----------------------------------------" << endl;
					cout << "Ya no tienes vida . . ." << endl;
					cout << "GAME OVER" << endl;
					cout << "----------------------------------------" << endl;
				}
				else if (player.vida > 0) {
					Final(player);
				}
				break;

			case 2:
				if
					(player.bomba >= 1) {
					cout << "Pones 1 bomba y haces que Mama reciba mucho daño" << endl;
					cout << "----------------------------------------" << endl;
					player.bomba -= 1;
					player.boss -= 4;
					Final(player);
				}
				else if
					(player.bomba == 0) {
					cout << "Te quedaste como idiota y Mama te aplasto" << endl;
					cout << "----------------------------------------" << endl;
					player.vida -= 2;
				}
				if
					//Verificador de Vida: Cuando esta llega a 0 Sera Game Over
					//Si aun tiene vida este podra continuar
					(player.vida <= 0) {
					cout << "----------------------------------------" << endl;
					cout << "Ya no tienes vida . . ." << endl;
					cout << "GAME OVER" << endl;
					cout << "----------------------------------------" << endl;
				}
				else if (player.vida > 0) {
					Final(player);
				}
				break;

			case 3:
				cout << "Mama ataca pero lograste evadirlo ademas recogiste un corazon de alma" << endl;
				player.vida += 1;
				Final(player);
				break;

				//Gamer Over: Por oprimir otro boton
			default:
				cout << "----------------------------------------" << endl;
				cout << "Explotaste sin ninguna razon . . ." << endl;
				cout << "GAME OVER" << endl;
				cout << "----------------------------------------" << endl;
				break;
			}
		}
		//La condicion de victoria.
		else if (player.boss == 0) {
			cout << "----------------------------------------" << endl;
			cout << "Mama a sido derrotada . . ." << endl;
			cout << "GANASTE!!!!" << endl;
			cout << "----------------------------------------" << endl;
		}
	}
};
