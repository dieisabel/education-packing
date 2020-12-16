#include "../headers/packing.h"


Packing::Packing(int width, int height)
{
    _window.create(VideoMode(width, height), "Packing");
    _window.setFramerateLimit(60);

    _packingField.set(width, height);
}

void Packing::run()
{
    while (_window.isOpen())
    {
        _window.clear();

        Event event;
        while (_window.pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed:
                    _window.close();
                    break;

                case Event::KeyPressed:
                    switch (event.key.code)
                    {
                        case Keyboard::Delete:
                            _mousePos = Mouse::getPosition(_window);
                            _packingField.del(_mousePos.x, _mousePos.y);
                            break;

                        case Keyboard::Up:
                            _packingField.changeLimit(1000);
                            break;

                        case Keyboard::Down:
                            _packingField.changeLimit(-1000);
                            break;

                        case Keyboard::Num1:
                            _packingField.changeRadius(5);
                            break;

                        case Keyboard::Num2:
                            _packingField.changeRadius(-5);
                            break;
                    }
                    break;

                case Event::MouseButtonPressed:
                    switch (event.key.code)
                    {
                        case Mouse::Left:
                            _mousePos = Mouse::getPosition(_window);
                            _packingField.create(_mousePos.x, _mousePos.y);
                            break;
                    }
                    break;
            }
        }

        _packingField.update(_window);
        _window.display();
    }
}
