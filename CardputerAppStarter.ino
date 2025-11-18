#include <M5Cardputer.h>
#include <lvgl.h>

#include <include/display.h>
#include <include/keyboard.h>
#include <include/ui.h>

void setup() {
    auto cfg = M5.config();
    cfg.output_power = true;   // optional, powers internal components

    M5Cardputer.begin(cfg);

    initDisplay();
    initKeyboard();
    initUI();
}

void loop() {
    M5Cardputer.update();     // required for keyboard, button, RTC

    lv_timer_handler();       // LVGL refresh
    handleKeyboard();         // our key → LVGL routing
    delay(5);
}