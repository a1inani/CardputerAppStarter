#include <include/ui.h>
#include <lvgl.h>

void initUI() {
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label,
        "Cardputer Starter Firmware\n"
        "LVGL 8.3.11 + Keyboard OK"
    );

    // Center in the middle of the screen
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    // Optional: center text lines inside the label
    lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
}
