class Morse{
public:
    Morse(int pin);
    void begin();
    void dot();
    void dash();
private:
    int _pin;
}