// src\AllModule\ButtonFunctions.hpp
#ifndef BUTTONFUNCTIONS_HPP
#define BUTTONFUNCTIONS_HPP

enum ButtonColorState
{
    NoColor,
    White,
    Magenta,
    Yellow,
    Cyan
};

ButtonColorState lastColorState = NoColor;

void initializeButton()
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void printColorState(ButtonColorState colorState)
{
    switch (colorState)
    {
    case White:
        Serial.println("WHITE");
        break;
    case Magenta:
        Serial.println("MAGENTA");
        break;
    case Yellow:
        Serial.println("YELLOW");
        break;
    case Cyan:
        Serial.println("CYAN");
        break;
    default:
        break;
    }
}

void checkButtonPress()
{
    static unsigned long pressStartTime = 0;
    static unsigned long lastDebounceTime = 0;
    static bool lastButtonState = HIGH;
    static bool buttonPressed = false;
    ButtonColorState currentColorState = NoColor;

    bool currentButtonState = digitalRead(BUTTON_PIN);

    if (currentButtonState != lastButtonState)
    {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > ONE_TIME_PUSH)
    {
        if (currentButtonState == LOW && !buttonPressed)
        {
            pressStartTime = millis();
            buttonPressed = true;
            lastColorState = NoColor;
        }

        if (buttonPressed)
        {
            unsigned long pressDuration = millis() - pressStartTime;

            if (pressDuration >= FOURTH_TIME_PUSH)
            {
                currentColorState = Cyan;
                setColor(CYAN);
            }
            else if (pressDuration >= THIRD_TIME_PUSH)
            {
                currentColorState = Yellow;
                setColor(YELLOW);
            }
            else if (pressDuration >= SECOND_TIME_PUSH)
            {
                currentColorState = Magenta;
                setColor(MAGENTA);
            }
            else
            {
                currentColorState = White;
                setColor(WHITE);
            }

            if (currentColorState != lastColorState)
            {
                printColorState(currentColorState);
                lastColorState = currentColorState;
            }
        }

        if (currentButtonState == HIGH && buttonPressed)
        {
            switch (lastColorState)
            {
            case White:
                Serial.println("Case 1");
                break;
            case Magenta:
                Serial.println("Case 2");
                break;
            case Yellow:
                Serial.println("Case 3");
                break;
            case Cyan:
                Serial.println("Change Interface");
                handleChangeInterface();
                break;
            default:
                break;
            }

            setColor(BLACK);
            Serial.println("BLACK");
            buttonPressed = false;
            currentColorState = NoColor;
            lastColorState = NoColor;
        }
    }

    lastButtonState = currentButtonState;
}

#endif // src\AllModule\ButtonFunctions.hpp
