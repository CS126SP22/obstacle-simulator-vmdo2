#include <core/game_details.h>
#include <fstream>
#include <iostream>
#include <cassert>

namespace game {

    GameDetails::GameDetails() {
        player_position_ = glm::vec2(250, 600 - player_radius_);
        player_velocity_ = glm::vec2(0, 0);
        player_acceleration_ = glm::vec2(1, 0);
    }
}  // namespace naivebayes