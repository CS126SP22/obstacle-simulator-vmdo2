#pragma once
#include <string>
#include <vector>
#include <array>
#include "cinder/gl/gl.h"
#include "game_details.h"

namespace game {

class GameContainer {
 public:

    /**
    * Displays the container walls and the current positions of the particles.
    */
    void Display();

    /**
     * Updates the positions and velocities of all particles (based on the rules
     * described in the assignment documentation).
     */
    void AdvanceOneFrame();
 private:
    std::vector<std::vector<cinder::vec2>> obstacles_;
    GameDetails game_details_;
};

}  // namespace game

