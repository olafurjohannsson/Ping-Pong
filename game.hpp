#ifndef game_hpp
#define game_hpp

#include <SFML/Graphics.hpp>

class game : private sf::NonCopyable
{
    public:
        game();
        void run();

    private:
        void process_events();
        void update(sf::Time elapsed_time);
        void render();

        void update_statistics(sf::Time elapsed_time);
        void handle_player_input(sf::Keyboard::Key key, bool is_pressed);

        static const float player_speed;
        static const sf::Time time_per_frame;

        sf::RenderWindow window;
        sf::Texture texture;
        sf::Sprite player;
        sf::Font font;
        sf::Text statistics_text;
        sf::Time statistics_update_time;

        std::size_t statistics_num_frames;
        bool is_moving_up;
        bool is_moving_down;
        bool is_moving_right;
        bool is_moving_left;        
};

#endif