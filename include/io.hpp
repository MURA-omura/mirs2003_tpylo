#ifndef __IO__
#define __IO__

class Io(){
public:
    Io(int pin);
    int getSw();

private:
    int pin;
};

#endif
