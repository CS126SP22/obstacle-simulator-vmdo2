#pragma once
#include <string>
#include <vector>
#include <array>
#include "cinder/gl/gl.h"
#include "game_details.h"

namespace game {

class GameContainer {
 public:
    glm::vec2 box_left_dimension_;
    glm::vec2 box_right_dimension_;

    struct Obstacle {
        public:
            char* color_;
            glm::vec2 position_;
            glm::vec2 bottom_left_corner_;
            glm::vec2 upper_right_corner_;
            glm::vec2 velocity_;
            int height_;
            int width_;

            Obstacle();

            Obstacle(std::string color, glm::vec2 position, glm::vec2 velocity, int height, int width);

        };
    GameContainer();

    /**
    * Displays the container walls and the current positions of the obtsacles and the player.
    */
    void Display();

    /**
     * Updates the positions and velocities of all obstacles and the player
     */
    void AdvanceOneFrame();

    /**
     * This function randomly creates an Obstacle
     * @return std::vector<Obstacle>
     */
    std::vector<Obstacle> GenerateRandomObstacles();

    GameDetails getGameDetails() {
        return GameDetails();
    }

    void setGameDetails(GameDetails game_details);

    std::vector<Obstacle> getObstacles() {
        return obstacles_;
    }

private:
    GameDetails game_details_;
    std::vector<Obstacle> obstacles_;
};

}  // namespace game

