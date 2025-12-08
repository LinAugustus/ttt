#ifndef CIRCUIT_HPP
#define CIRCUIT_HPP

class Circuit {
public:
    int get_first_switch_state();
    int get_second_switch_state();
    int get_lamp_state();
    void toggle_first_switch();
    void toggle_second_switch();

private:
    int first_switch = 0;
    int second_switch = 0;
    int lamp_state = 0;
};

#endif