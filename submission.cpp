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

int Circuit::get_first_switch_state() {
    return first_switch;
}

int Circuit::get_second_switch_state() {
    return second_switch;
}

int Circuit::get_lamp_state() {
    return lamp_state;
}

void Circuit::toggle_first_switch() {
    first_switch = 1 - first_switch;
    lamp_state = 1 - lamp_state;
}

void Circuit::toggle_second_switch() {
    second_switch = 1 - second_switch;
    lamp_state = 1 - lamp_state;
}