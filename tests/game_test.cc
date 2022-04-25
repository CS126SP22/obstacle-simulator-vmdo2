#include <catch2/catch.hpp>
#include <fstream>
#include <core/game_container.h>

using game::GameContainer;

TEST_CASE("empty") {
    REQUIRE(1 > 0);
}

TEST_CASE("GameContainer sanity check") {
    GameContainer container;
    for (int i = 0; i < 20; i++) {
        container.AdvanceOneFrame();
    }
    REQUIRE(1 > 0);
}

TEST_CASE("Obstacles advance by one frame") {
    GameContainer game_container = GameContainer();
    GameContainer::Obstacle obstacle_1 = game_container.getObstacles()[0];
    game::GameDetails game_details = game_container.getGameDetails();
    game_container.AdvanceOneFrame();
    REQUIRE(game_container.getGameDetails().player_position_ == game_details.player_position_ + game_details.player_velocity_);
    REQUIRE(game_container.getObstacles()[0].position_ == obstacle_1.position_ + obstacle_1.velocity_);
}

TEST_CASE("Player advance by one frame") {
    GameContainer game_container = GameContainer();
    game::GameDetails game_details = game_container.getGameDetails();
    glm::vec2 initial_pos = game_details.player_position_;
    game_details.player_velocity_ = glm::vec2(-2, 0);
    game_container.setGameDetails(game_details);
    game_container.AdvanceOneFrame();
    REQUIRE(game_container.getGameDetails().player_velocity_ == glm::vec2(-2, 0));
    REQUIRE(game_container.getGameDetails().player_position_ == glm::vec2(-2, 0) + initial_pos);
}

TEST_CASE("Game detects when obstacle collides with player") {
    GameContainer game_container = GameContainer();
    GameContainer::Obstacle obstacle_1 = game_container.getObstacles()[0];
    game::GameDetails game_details = game_container.getGameDetails();
    game_details.player_position_ = obstacle_1.position_;
    game_container.setGameDetails(game_details);
    for (int i = 0; i < 20; i++) {
        game_container.AdvanceOneFrame();
    }
    REQUIRE(game_container.getGameDetails().game_over_ == true);
}

/*

TEST_CASE("Left and right movement for player is functional") {
    GameContainer game_container = GameContainer();
}
*/
