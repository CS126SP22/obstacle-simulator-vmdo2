#pragma once
#include <string>
#include <vector>
#include <array>

namespace game {

class GameDetails {
public:
    float player_radius_ = 10;
private:
    bool invincibility_ = false;
    bool slow_time_ = false;
    bool decrease_size = false;
    int static const kAbilityTime = 5;

};

}  // namespace game
