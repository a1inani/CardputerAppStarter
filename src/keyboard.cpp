#include <include/keyboard.h>
#include <M5Cardputer.h>
#include <lvgl.h>

void initKeyboard() {
    // No initialization required.
}

void handleKeyboard() {
    // Only react when a new key state is detected
    if (M5Cardputer.Keyboard.isChange()) {

        // Key pressed?
        if (M5Cardputer.Keyboard.isPressed()) {
            uint8_t key = M5Cardputer.Keyboard.key;

            // Send LVGL key event to the focused object
            lv_event_send(lv_obj_get_focused(NULL), LV_EVENT_KEY, &key);
        }
    }
}

