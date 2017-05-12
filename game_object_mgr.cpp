
#include <SFML/Graphics.hpp>
#include <string>
#include <map>


namespace Tetris {

	class Game
	{
	public:
		static void Start(void)
		{
			if (_state != Game::Uninitialized)
				return;

			_window.create(sf::VideoMode(1024, 768, 32), "ASDF");
			_state = Game::Splash;

			if (Game::IsExiting())
			{
				Game::Loop();
			}
			_window.close();
		}

	private:
		static bool IsExiting();
		static void Loop(void)
		{
			switch (_state)
			{
				case Game::Splash:
				{
					ShowSplashScreen();
					break;
				}
				case Game::Menu:
				{
					ShowMenu();
					break;
				}
				case Game::Play:
				{


					break;
				}
			}
		}
		static void ShowSplashScreen(bool show = true);
		static void ShowMenu(bool show = true);

		enum State {
			Uninitialized,
			Splash,
			Pause,
			Menu,
			Play,
			Exiting
		};

		//static GameState _state;
		static sf::RenderWindow _window;
		static State _state;
	};

    class GameObject 
    {

    };

    class GameObjectManager
    {
    public:
        GameObjectManager();
        ~GameObjectManager();

        bool Insert(const std::string &name, Tetris::GameObject* obj);
        bool Remove(const std::string &name);
        int Count() const;
        GameObject* Get(const std::string name) const;

        void DrawAll(sf::RenderWindow& renderWindow);
        
    private:
        std::map<std::string, GameObject*> _objects;

        struct dealloc {
            void operator()(const std::pair<std::string, GameObject*> &p) const
            {
                delete p.second;
            }
        };

    };

}
