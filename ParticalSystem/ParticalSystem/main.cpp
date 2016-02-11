#include<iostream>
#include"ParticalSystem.h"
#include"Explode.h"
#include"Shoot.h"
#include"Snow.h"
#include"PSManager.h"

using namespace std;

RenderWindow* MainWindow;

//bool flag = false;

float explodeLife = 3;
float shootLife = 2;

void set_some_PS()
{
	PSManager::Instance()->AddRepeller();

	ParticleSystem* ps = new Snow(2000, Points, explodeLife, Vector2f(100,100));
	PSManager::Instance()->AddPS(ps);
}

float keyCD = 0.1;
float currentCD = 0;

int currentNum = 0;
float fps = 0;

void ProcessInput(Time elapsed)
{
	currentCD -= elapsed.asSeconds();
	if (currentCD <= 0)
	{
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			currentNum = PSManager::Instance()->m_ParticalSystems[1]->AddNumber();

			currentCD = keyCD;
		}
	}
	if (currentCD <= 0)
	{
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			currentNum = PSManager::Instance()->m_ParticalSystems[1]->SubNumber();

			currentCD = keyCD;
		}
	}
	if (currentCD <= 0)
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			PSManager::Instance()->m_ParticalSystems[3]->setup();

			currentCD = keyCD;
		}
		if (Keyboard::isKeyPressed(Keyboard::Q))
		{
			sf::Vector2i mouse = sf::Mouse::getPosition(*MainWindow);
			Vector2f pos = MainWindow->mapPixelToCoords(mouse);
			ParticleSystem* ps = new Explode(100, Quads, explodeLife, pos);
			PSManager::Instance()->AddPS(ps);
			//particles4.setEmitter(Vector2f(100, 200));
			Texture texture1;
			texture1.loadFromFile("C:/Users/Pancy/Pictures/red.png");
			ps->m_Texture = texture1;
			currentCD = keyCD;
		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			sf::Vector2i mouse = sf::Mouse::getPosition(*MainWindow);
			Vector2f pos = MainWindow->mapPixelToCoords(mouse);
			ParticleSystem* ps = new Explode(100, Quads, explodeLife, pos);
			PSManager::Instance()->AddPS(ps);
			//particles4.setEmitter(Vector2f(100, 200));
			Texture texture1;
			texture1.loadFromFile("C:/Users/Pancy/Pictures/yellow.png");
			ps->m_Texture = texture1;
			currentCD = keyCD;
		}
		if (Keyboard::isKeyPressed(Keyboard::E))
		{
			sf::Vector2i mouse = sf::Mouse::getPosition(*MainWindow);
			Vector2f pos = MainWindow->mapPixelToCoords(mouse);
			ParticleSystem* ps = new Explode(100, Quads, explodeLife, pos);
			PSManager::Instance()->AddPS(ps);
			//particles4.setEmitter(Vector2f(100, 200));
			Texture texture1;
			texture1.loadFromFile("C:/Users/Pancy/Pictures/green.png");
			ps->m_Texture = texture1;
			currentCD = keyCD;
		}
		if (Keyboard::isKeyPressed(Keyboard::R))
		{
			sf::Vector2i mouse = sf::Mouse::getPosition(*MainWindow);
			Vector2f pos = MainWindow->mapPixelToCoords(mouse);
			ParticleSystem* ps = new Explode(100, Quads, explodeLife, pos);
			PSManager::Instance()->AddPS(ps);
			//particles4.setEmitter(Vector2f(100, 200));
			Texture texture1;
			texture1.loadFromFile("C:/Users/Pancy/Pictures/orange.png");
			ps->m_Texture = texture1;
			currentCD = keyCD;
		}
		if (Keyboard::isKeyPressed(Keyboard::T))
		{
			sf::Vector2i mouse = sf::Mouse::getPosition(*MainWindow);
			Vector2f pos = MainWindow->mapPixelToCoords(mouse);
			ParticleSystem* ps = new Explode(100, Quads, explodeLife, pos);
			PSManager::Instance()->AddPS(ps);
			//particles4.setEmitter(Vector2f(100, 200));
			Texture texture1;
			texture1.loadFromFile("C:/Users/Pancy/Pictures/blue.png");
			ps->m_Texture = texture1;
			currentCD = keyCD;
		}
		if (Keyboard::isKeyPressed(Keyboard::Z))
		{
			sf::Vector2i mouse = sf::Mouse::getPosition(*MainWindow);
			Vector2f pos = MainWindow->mapPixelToCoords(mouse);
			ParticleSystem* ps = new ParticleSystem(100, Quads, explodeLife, pos);
			PSManager::Instance()->AddPS(ps);
			//particles4.setEmitter(Vector2f(100, 200));
			Texture texture1;
			texture1.loadFromFile("C:/Users/Pancy/Pictures/red.png");
			ps->m_Texture = texture1;
			currentCD = keyCD;
		}
		if (Keyboard::isKeyPressed(Keyboard::X))
		{
			sf::Vector2i mouse = sf::Mouse::getPosition(*MainWindow);
			Vector2f pos = MainWindow->mapPixelToCoords(mouse);
			ParticleSystem* ps = new ParticleSystem(100, Quads, explodeLife, pos);
			PSManager::Instance()->AddPS(ps);
			//particles4.setEmitter(Vector2f(100, 200));
			Texture texture1;
			texture1.loadFromFile("C:/Users/Pancy/Pictures/yellow.png");
			ps->m_Texture = texture1;
			currentCD = keyCD;
		}
		if (Keyboard::isKeyPressed(Keyboard::C))
		{
			sf::Vector2i mouse = sf::Mouse::getPosition(*MainWindow);
			Vector2f pos = MainWindow->mapPixelToCoords(mouse);
			ParticleSystem* ps = new ParticleSystem(100, Quads, explodeLife, pos);
			PSManager::Instance()->AddPS(ps);
			//particles4.setEmitter(Vector2f(100, 200));
			Texture texture1;
			texture1.loadFromFile("C:/Users/Pancy/Pictures/green.png");
			ps->m_Texture = texture1;
			currentCD = keyCD;
		}
		if (Keyboard::isKeyPressed(Keyboard::V))
		{
			sf::Vector2i mouse = sf::Mouse::getPosition(*MainWindow);
			Vector2f pos = MainWindow->mapPixelToCoords(mouse);
			ParticleSystem* ps = new ParticleSystem(100, Quads, explodeLife, pos);
			PSManager::Instance()->AddPS(ps);
			//particles4.setEmitter(Vector2f(100, 200));
			Texture texture1;
			texture1.loadFromFile("C:/Users/Pancy/Pictures/orange.png");
			ps->m_Texture = texture1;
			currentCD = keyCD;
		}
		if (Keyboard::isKeyPressed(Keyboard::B))
		{
			sf::Vector2i mouse = sf::Mouse::getPosition(*MainWindow);
			Vector2f pos = MainWindow->mapPixelToCoords(mouse);
			ParticleSystem* ps = new ParticleSystem(100, Quads, explodeLife, pos);
			PSManager::Instance()->AddPS(ps);
			//particles4.setEmitter(Vector2f(100, 200));
			Texture texture1;
			texture1.loadFromFile("C:/Users/Pancy/Pictures/blue.png");
			ps->m_Texture = texture1;
			currentCD = keyCD;
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			sf::Vector2i mouse = sf::Mouse::getPosition(*MainWindow);
			Vector2f pos = MainWindow->mapPixelToCoords(mouse);
			ParticleSystem* ps = new Shoot(100, Quads, shootLife, pos);
			PSManager::Instance()->AddPS(ps);
			//particles4.setEmitter(Vector2f(100, 200));
			Texture texture1;
			texture1.loadFromFile("C:/Users/Pancy/Pictures/red.png");
			ps->m_Texture = texture1;
			currentCD = keyCD;
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			sf::Vector2i mouse = sf::Mouse::getPosition(*MainWindow);
			Vector2f pos = MainWindow->mapPixelToCoords(mouse);
			ParticleSystem* ps = new Shoot(100, Quads, shootLife, pos);
			PSManager::Instance()->AddPS(ps);
			//particles4.setEmitter(Vector2f(100, 200));
			Texture texture1;
			texture1.loadFromFile("C:/Users/Pancy/Pictures/yellow.png");
			ps->m_Texture = texture1;
			currentCD = keyCD;
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			sf::Vector2i mouse = sf::Mouse::getPosition(*MainWindow);
			Vector2f pos = MainWindow->mapPixelToCoords(mouse);
			ParticleSystem* ps = new Shoot(100, Quads, shootLife, pos);
			PSManager::Instance()->AddPS(ps);
			//particles4.setEmitter(Vector2f(100, 200));
			Texture texture1;
			texture1.loadFromFile("C:/Users/Pancy/Pictures/green.png");
			ps->m_Texture = texture1;
			currentCD = keyCD;
		}
		if (Keyboard::isKeyPressed(Keyboard::F))
		{
			sf::Vector2i mouse = sf::Mouse::getPosition(*MainWindow);
			Vector2f pos = MainWindow->mapPixelToCoords(mouse);
			ParticleSystem* ps = new Shoot(100, Quads, shootLife, pos);
			PSManager::Instance()->AddPS(ps);
			//particles4.setEmitter(Vector2f(100, 200));
			Texture texture1;
			texture1.loadFromFile("C:/Users/Pancy/Pictures/orange.png");
			ps->m_Texture = texture1;
			currentCD = keyCD;
		}
		if (Keyboard::isKeyPressed(Keyboard::G))
		{
			sf::Vector2i mouse = sf::Mouse::getPosition(*MainWindow);
			Vector2f pos = MainWindow->mapPixelToCoords(mouse);
			ParticleSystem* ps = new Shoot(100, Quads, shootLife, pos);
			PSManager::Instance()->AddPS(ps);
			//particles4.setEmitter(Vector2f(100, 200));
			Texture texture1;
			texture1.loadFromFile("C:/Users/Pancy/Pictures/blue.png");
			ps->m_Texture = texture1;
			currentCD = keyCD;
		}

	}
}

void UpdateDisplay()
{
	// draw it
	MainWindow->clear();

	//if(!flag)
	PSManager::Instance()->Draw(MainWindow);

	MainWindow->display();
}

void UpdateRepeller()
{
	// make the particle system emitter follow the mouse
	sf::Vector2i mouse = sf::Mouse::getPosition(*MainWindow);
	//particles.setEmitter(window.mapPixelToCoords(mouse));
	PSManager::Instance()->m_Repellers[0].location = MainWindow->mapPixelToCoords(mouse);
}

void Update(Time elapsed)
{
	ProcessInput(elapsed);

	//UpdateRepeller();

	PSManager::Instance()->Update(elapsed);

	UpdateDisplay();
}



int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(1024, 512), "Particles");
	MainWindow = &window;
	// create the particle system
	set_some_PS();



	PSManager::Instance()->AddRepeller();

	// create a clock to track the elapsed time
	sf::Clock clock;

	// run the main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// update it

		sf::Time elapsed = clock.restart();
		float newFps = (float)1000 / (float)elapsed.asMilliseconds();
		float dif = newFps - fps;
		if (dif > 30 || dif < -30)
		{
			fps = newFps;
			system("cls");
			//cout << "fps: " << fps << endl;
			//cout << currentNum << endl;
		}
		Update(elapsed);


	}

	return 0;
}
