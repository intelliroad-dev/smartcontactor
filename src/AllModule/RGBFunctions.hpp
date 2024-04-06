// src\AllModule\RGBFunctions.hpp
#ifndef RGBFUNCTIONS_HPP
#define RGBFUNCTIONS_HPP

enum Color
{
    BLACK,
    RED,
    GREEN,
    BLUE,
    MAGENTA,
    YELLOW,
    CYAN,
    WHITE
};

void initializeRGB()
{
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
}

void setColor(Color color)
{
    switch (color)
    {
    case BLACK:
        digitalWrite(RED_PIN, LOW);
        digitalWrite(GREEN_PIN, LOW);
        digitalWrite(BLUE_PIN, LOW);
        break;
    case RED:
        digitalWrite(RED_PIN, HIGH);
        digitalWrite(GREEN_PIN, LOW);
        digitalWrite(BLUE_PIN, LOW);
        break;
    case GREEN:
        digitalWrite(RED_PIN, LOW);
        digitalWrite(GREEN_PIN, HIGH);
        digitalWrite(BLUE_PIN, LOW);
        break;
    case BLUE:
        digitalWrite(RED_PIN, LOW);
        digitalWrite(GREEN_PIN, LOW);
        digitalWrite(BLUE_PIN, HIGH);
        break;
    case MAGENTA:
        digitalWrite(RED_PIN, HIGH);
        digitalWrite(GREEN_PIN, LOW);
        digitalWrite(BLUE_PIN, HIGH);
        break;
    case YELLOW:
        digitalWrite(RED_PIN, HIGH);
        digitalWrite(GREEN_PIN, HIGH);
        digitalWrite(BLUE_PIN, LOW);
        break;
    case CYAN:
        digitalWrite(RED_PIN, LOW);
        digitalWrite(GREEN_PIN, HIGH);
        digitalWrite(BLUE_PIN, HIGH);
        break;
    case WHITE:
        digitalWrite(RED_PIN, HIGH);
        digitalWrite(GREEN_PIN, HIGH);
        digitalWrite(BLUE_PIN, HIGH);
        break;
    }
}

#endif // src\AllModule\RGBFunctions.hpp
