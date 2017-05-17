

#include "game.hpp"

const float game::player_speed = 100.f;
const sf::Time game::time_per_frame = sf::seconds(1.f/60.f);

game::game() : window(sf::VideoMode(640, 480), "SFML", sf::Style::Close),
			   texture(),
			   player(),
			   font(),
			   statistics_text(),
			   statistics_update_time(),
			   statistics_num_frames(0),
			   is_moving_down(false),
			   is_moving_up(false),
			   is_moving_left(false),
			   is_moving_right(false)
{
	if (!texture.loadFromFile("Media/Textures/Eagle.png"))
	{
		// Handle loading error
	}

	player.setTexture(mTexture);
	player.setPosition(100.f, 100.f);
	
	font.loadFromFile("Media/Sansation.ttf");
	statistics_text.setFont(mFont);
	statistics_text.setPosition(5.f, 5.f);
	statistics_text.setCharacterSize(10);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			process_events();
			update(TimePerFrame);
		}

		update_statistics(elapsedTime);
		render();
	}
}

void Game::process_events()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handle_player_input(event.key.code, true);
				break;

			case sf::Event::KeyReleased:
				handle_player_input(event.key.code, false);
				break;

			case sf::Event::Closed:
				window.close();
				break;
		}
	}
}

void game::update(sf::Time elapsedTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (is_moving_up)
		movement.y -= PlayerSpeed;
	if (is_moving_down)
		movement.y += PlayerSpeed;
	if (is_moving_left)
		movement.x -= PlayerSpeed;
	if (is_moving_right)
		movement.x += PlayerSpeed;
		
	player.move(movement * elapsedTime.asSeconds());
}

void game::render()
{
	window.clear();	
	window.draw(player);
	window.draw(statistics_text);
	window.display();
}

void game::update_statistics(sf::Time elapsedTime)
{
	statistics_update_time += elapsedTime;
	statistics_num_frames += 1;

	if (statistics_update_time >= sf::seconds(1.0f))
	{
		statistics_text.setString(
			"Frames / Second = " + toString(statistics_num_frames) + "\n" +
			"Time / Update = " + toString(statistics_update_time.asMicroseconds() / statistics_num_frames) + "us");
							 
		statistics_update_time -= sf::seconds(1.0f);
		statistics_num_frames = 0;
	}
}

void game::handle_player_input(sf::Keyboard::Key key, bool isPressed)
{	
	if (key == sf::Keyboard::W)
		is_moving_up = isPressed;
	else if (key == sf::Keyboard::S)
		is_moving_down = isPressed;
	else if (key == sf::Keyboard::A)
		is_moving_left = isPressed;
	else if (key == sf::Keyboard::D)
		is_moving_right = isPressed;
}