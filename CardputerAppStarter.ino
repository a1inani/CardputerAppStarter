#include <M5Cardputer.h>
#include <lvgl.h>

#include <include/display.h>
#include <include/keyboard.h>
#include <include/ui.h>

void setup() {
  auto cfg = M5.config();
  M5Cardputer.begin(cfg);

  initDisplay();
  initKeyboard();
  initUI();
}

void loop() {
  lv_timer_handler();
  handleKeyboard();
  delay(5);
}
