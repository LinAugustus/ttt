/*
Author: Augustus Lin
Instructor: Tong Yi
Course: CSCI 135
Assignment e.9.3

*/
#include "Circuit.hpp"

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
