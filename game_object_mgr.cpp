
#include <SFML/Graphics.hpp>
#include <string>
#include <map>


namespace Tetris {



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
