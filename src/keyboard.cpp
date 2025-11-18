#include <include/keyboard.h>
#include <M5Cardputer.h>
#include <lvgl.h>

void initKeyboard() {
    // no setup needed
}

static void send_lv_key(uint32_t k) {
    lv_group_t *g = lv_group_get_default();
    if (!g) return;

    lv_obj_t *focused = lv_group_get_focused(g);
    if (!focused) return;

    uint32_t key = k;  // LVGL expects pointer to u32
    lv_event_send(focused, LV_EVENT_KEY, &key);
}

void handleKeyboard() {
    // Only process on change
    if (!M5Cardputer.Keyboard.isChange()) return;

    // Only handle press events
    if (M5Cardputer.Keyboard.isPressed()) {
        Keyboard_Class::KeysState st = M5Cardputer.Keyboard.keysState();

        // Backspace
        if (st.del) {
            send_lv_key(LV_KEY_BACKSPACE);
        }

        // Enter
        if (st.enter) {
            send_lv_key(LV_KEY_ENTER);
        }

        // Regular characters (word buffer)
        for (size_t i = 0; i < sizeof(st.word) / sizeof(st.word[0]); i++) {
            char c = st.word[i];
            if (c == 0) break;  // end of word
            send_lv_key((uint32_t)c);
        }
    }
}
