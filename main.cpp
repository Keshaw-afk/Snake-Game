
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define WIDTH 800.0f
#define HEIGHT 600.0f
#define SNAKE_CELL_SIZE 20.0f
class Snake
{
    public:

    int length;
    sf::Color head_color;
    sf::Color body_color;
    sf::Vector2f speed;
    sf::Vector2f coordinates;
    

    Snake(int _length, sf::Color _head_color, sf::Color _body_color,
            const sf::Vector2f _speed = {0.0f, 0.0f}, const sf::Vector2f _coordinates = {0.0f, 0.0f})
    {
        length = _length;
        head_color = _head_color;
        body_color = _body_color;
        speed = _speed;
    }

    void grow()
    {
        length+=1;
    }

    void render(sf::RenderWindow& window)
    {   
        for (int i = 0 ; i<length-1; i++)
        {
            sf::RectangleShape square;
            square.setSize(sf::Vector2f(SNAKE_CELL_SIZE, SNAKE_CELL_SIZE));
            square.setFillColor(body_color);
            square.setPosition({WIDTH/2+i*SNAKE_CELL_SIZE, HEIGHT/2});
            window.draw(square);
        }
        sf::RectangleShape head;
        head.setSize(sf::Vector2f(SNAKE_CELL_SIZE, SNAKE_CELL_SIZE));
        head.setFillColor(head_color);
        head.setPosition({WIDTH/2 + (length-1)*SNAKE_CELL_SIZE, HEIGHT/2});
        window.draw(head);

    }


};


int main()
{
    sf::RenderWindow window(sf::VideoMode({(unsigned int)WIDTH, (unsigned int) HEIGHT}), "Snake Game");   
    Snake snake(5, sf::Color::Black, sf::Color::White);
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        window.clear(sf::Color::Red);
        snake.render(window);
        window.display();


    }
}
