#include <visualizer/game_simulation_app.h>

namespace game {

namespace visualizer {

GameSimulationApp::GameSimulationApp() {
    ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void GameSimulationApp::draw() {
    ci::Color background_color("black");
    ci::gl::clear(background_color);

    game_container_.Display();
}

void GameSimulationApp::update() {
    game_container_.AdvanceOneFrame();
}

void GameSimulationApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_RETURN:
      // ask your classifier to classify the image that's currently drawn on the
      // sketchpad and update current_prediction_
      break;

    case ci::app::KeyEvent::KEY_DELETE:
      //game_container_.Clear();
      break;
  }
}

}  // namespace GameSimulation

}  // namespace naivebayes
