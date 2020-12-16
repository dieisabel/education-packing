#include "../headers/status_bar.h"


void StatusBar::set(string path)
{
    _font = loadFont(path);

    _text.setFont(_font);
    _text.setCharacterSize(24);
    _text.setFillColor(Color::White);
    _text.setPosition(Vector2f(125, 70));

    _figureVars = _text;
    _figureVars.setPosition(Vector2f(125, 10));
}

Font StatusBar::loadFont(string path)
{
    Font font;
    if (!font.loadFromFile(path))
    {
        cout << "Error while loading font" << endl;
        exit(EXIT_FAILURE);
    }
    return font;
}

void StatusBar::overflow(int value, int maxValue)
{
    _text.setString(to_string(value) + " / " + to_string(maxValue) +
                    " !! OVERFLOW !!");
    _text.setFillColor(Color::Red);
}

void StatusBar::normal(int value, int maxValue)
{
    _text.setString(to_string(value) + " / " + to_string(maxValue));
    _text.setFillColor(Color::White);
}

void StatusBar::update(RenderWindow &window, int radius)
{   
    _figureVars.setString("radius: " + to_string(radius));

    window.draw(_text);
    window.draw(_figureVars);

}
