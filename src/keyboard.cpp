#include <include/keyboard.h>
#include <M5Cardputer.h>
#include <lvgl.h>

void initKeyboard() {
    // No initialization required
}

void handleKeyboard() {
    // Only act when there is a key state change
    if (M5Cardputer.Keyboard.isChange()) {

        if (M5Cardputer.Keyboard.isPressed()) {

            uint8_t key = M5Cardputer.Keyboard.keyCode();

            // Get default group
            lv_group_t *g = lv_group_get_default();
            if (!g) return;

            lv_obj_t *focused = lv_group_get_focused(g);
            if (!focused) return;

            // Send keyboard event to LVGL
            lv_event_send(focused, LV_EVENT_KEY, &key);
        }
    }
}
