#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <core/game_container.h>
#include <core/game_details.h>

namespace game {

namespace visualizer {

/**
 * Allows a user to draw a digit on a sketchpad and uses Naive Bayes to
 * classify it.
 */
class GameSimulationApp : public ci::app::App {
 public:
  GameSimulationApp();

  void keyDown(ci::app::KeyEvent event) override;

  void draw();

  void update();
  const int kWindowSize = 875;

 private:
  GameContainer game_container_;
  bool start_game_ = false;

};

}  // namespace visualizer

}  // namespace game
