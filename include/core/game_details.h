#pragma once
#include <string>
#include <vector>
#include <array>
#include "cinder/gl/gl.h"

namespace game {

class GameDetails {
public:
    float player_radius_ = 10;
    glm::vec2 player_position_;
    glm::vec2 player_velocity_;
    bool game_over_ = false;
    std::vector<std::string> power_ups_ = {"invincibility", "size decrease", "slow time"};

    GameDetails();

    GameDetails(float player_radius, glm::vec2 player_position, glm::vec2 player_velocity, glm::vec2 player_acceleration, bool game_over);


private:
    bool invincibility_ = false;
    bool slow_time_ = false;
    bool decrease_size = false;
    int static const kAbilityTime = 5;

};

}  // namespace game
