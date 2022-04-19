#include <core/game_container.h>
#include <fstream>
#include <iostream>
#include <cassert>

namespace game {

    GameContainer::GameContainer() :box_left_dimension_(glm::vec2(100, 100)), box_right_dimension_(glm::vec2(400, 600)) {
        this->obstacles_ = GenerateRandomObstacles();
    }

    void GameContainer::Display() {
        ci::gl::color(ci::Color("blue"));
        ci::gl::drawSolidCircle(game_details_.player_position_, game_details_.player_radius_);
        ci::gl::color(ci::Color("white"));
        ci::gl::drawStrokedRect(ci::Rectf(box_left_dimension_, box_right_dimension_));
        for (unsigned int i = 0; i < obstacles_.size(); i++) {
            ci::gl::color(ci::Color(obstacles_[i].color_));
            ci::gl::drawSolidRect(ci::Rectf(obstacles_[i].bottom_left_corner_, obstacles_[i].upper_right_corner_));
        }
    }

    void GameContainer::AdvanceOneFrame() {
        for (unsigned int i = 0; i < obstacles_.size(); i++) {
            obstacles_[i].position_ += obstacles_[i].velocity_;
        }
    }

    std::vector<GameContainer::Obstacle> GameContainer::GenerateRandomObstacles() {
        std::vector<GameContainer::Obstacle> obstacles;
        for (int i = 0; i < 10; i++) {
            GameContainer::Obstacle obstacle;
            obstacle.width_ = 10 + (rand() % 20);
            obstacle.height_ = 20 + (rand() % 50);
            int position_x =
                    int(box_left_dimension_.x + (obstacle.width_ / 2)) + (rand() % int(box_right_dimension_.x - (obstacle.width_ / 2)));
            obstacle.position_ = glm::vec2(position_x, 100 - obstacle.height_ / 2);
            obstacle.bottom_left_corner_ = glm::vec2(obstacle.position_.x - obstacle.width_ / 2, obstacle.position_.y + obstacle.height_ / 2);
            obstacle.upper_right_corner_ = glm::vec2(obstacle.position_.x + obstacle.width_ / 2, obstacle.position_.y - obstacle.height_ / 2);
            obstacle.velocity_ = glm::vec2(0, 1 + (rand() % 5));
            obstacles.push_back(obstacle);
        }
        return obstacles;
    }

    void GameContainer::setGameDetails(GameDetails game_details) {
        game_details_ = game_details;
    }

    GameContainer::Obstacle::Obstacle() {
        color_ = "red";
        position_ = glm::vec2(50, 50);
        glm::vec2 velocity_ = glm::vec2(0, 1);
        height_ = 10;
        width_ = 5;
    }
}  // namespace game