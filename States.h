//
// Created by astraeven on 2021/5/17.
//

#ifndef SFML_GAME_PROJECT_STATES_H
#define SFML_GAME_PROJECT_STATES_H
#include <vector>

class States {
private:
    std::vector<bool> objectStates;
public:
    States();
    enum states {HOVERED, NORMAL, EXIT, HIT1, HIT2, HIT3, STAND, HIDDEN, START, LAST};
    bool checkState(states state);
    void enableState(states state);
    void disableState(states state);
};


#endif //SFML_GAME_PROJECT_STATES_H
