#include <core/game_container.h>
#include <fstream>
#include <ctime>
#include <cstdlib>

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
            obstacles_[i].bottom_left_corner_ = glm::vec2(obstacles_[i].position_.x - (obstacles_[i].width_ / 2), obstacles_[i].position_.y + (obstacles_[i].height_ / 2));
            obstacles_[i].upper_right_corner_ = glm::vec2(obstacles_[i].position_.x + (obstacles_[i].width_ / 2), obstacles_[i].position_.y - (obstacles_[i].height_ / 2));
            ci::gl::drawSolidRect(ci::Rectf(obstacles_[i].bottom_left_corner_, obstacles_[i].upper_right_corner_));
        }
    }

    void GameContainer::AdvanceOneFrame() {
        for (unsigned int i = 0; i < obstacles_.size(); i++) {
            obstacles_[i].position_ += obstacles_[i].velocity_;
        }
        game_details_.player_position_ += game_details_.player_velocity_;
        if (PlayerCollision()) {
            game_details_.game_over_ = true;
        }
    }

    std::vector<GameContainer::Obstacle> GameContainer::GenerateRandomObstacles() {
        srand (static_cast <unsigned> (time(0)));
        std::vector<GameContainer::Obstacle> obstacles;
        for (int i = 0; i < 10; i++) {
            GameContainer::Obstacle obstacle;
            obstacle.width_ = 10 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(10)));
            obstacle.height_ = 20 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(30)));
            float position_x = box_left_dimension_.x + (obstacle.width_ / 2) + static_cast <float> (rand()) /
                    ( static_cast <float> (RAND_MAX/(box_right_dimension_.x - (obstacle.width_ / 2)
                    - (box_left_dimension_.x + (obstacle.width_ / 2)))));

            obstacle.position_ = glm::vec2(position_x, 100 - obstacle.height_ / 2);
            obstacle.velocity_ = glm::vec2(0, 1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(4))));
            obstacles.push_back(obstacle);
        }
        return obstacles;
    }

    void GameContainer::setGameDetails(GameDetails game_details) {
        game_details_ = game_details;
    }

    bool GameContainer::PlayerCollision() {
        for (unsigned int i = 0; i < obstacles_.size(); i++) {
            if (obstacles_[i].position_ == game_details_.player_position_) {
                return true;
            }
            if (obstacles_[i].bottom_left_corner_.x <= game_details_.player_position_.x - game_details_.player_radius_
            && obstacles_[i].upper_right_corner_.x >= game_details_.player_position_.x - game_details_.player_radius_
            && obstacles_[i].bottom_left_corner_.y >= game_details_.player_position_.y - game_details_.player_radius_
            && obstacles_[i].upper_right_corner_.y <= game_details_.player_position_.y - game_details_.player_radius_) {
                return true;
            } else if (obstacles_[i].bottom_left_corner_.x <= game_details_.player_position_.x - game_details_.player_radius_
                       && obstacles_[i].upper_right_corner_.x >= game_details_.player_position_.x - game_details_.player_radius_
                       && obstacles_[i].bottom_left_corner_.y >= game_details_.player_position_.y + game_details_.player_radius_
                       && obstacles_[i].upper_right_corner_.y <= game_details_.player_position_.y + game_details_.player_radius_) {
                return true;
            } else if (obstacles_[i].bottom_left_corner_.x <= game_details_.player_position_.x + game_details_.player_radius_
                       && obstacles_[i].upper_right_corner_.x >= game_details_.player_position_.x + game_details_.player_radius_
                       && obstacles_[i].bottom_left_corner_.y >= game_details_.player_position_.y - game_details_.player_radius_
                       && obstacles_[i].upper_right_corner_.y <= game_details_.player_position_.y - game_details_.player_radius_) {
                return true;
            } else if (obstacles_[i].bottom_left_corner_.x <= game_details_.player_position_.x + game_details_.player_radius_
                       && obstacles_[i].upper_right_corner_.x >= game_details_.player_position_.x + game_details_.player_radius_
                       && obstacles_[i].bottom_left_corner_.y >= game_details_.player_position_.y + game_details_.player_radius_
                       && obstacles_[i].upper_right_corner_.y <= game_details_.player_position_.y + game_details_.player_radius_) {
                return true;
            } else if (obstacles_[i].bottom_left_corner_.x <= game_details_.player_position_.x
                       && obstacles_[i].upper_right_corner_.x >= game_details_.player_position_.x
                       && obstacles_[i].bottom_left_corner_.y >= game_details_.player_position_.y
                       && obstacles_[i].upper_right_corner_.y <= game_details_.player_position_.y) {
                return true;
            }
        }
        return false;
    }

    GameContainer::Obstacle::Obstacle() {
        color_ = "red";
        position_ = glm::vec2(50, 50);
        glm::vec2 velocity_ = glm::vec2(0, 1);
        height_ = 10;
        width_ = 5;
    }
}  // namespace game