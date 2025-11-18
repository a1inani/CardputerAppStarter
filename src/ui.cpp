#include <include/ui.h>
#include <lvgl.h>

void initUI() {
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label,
        "Hello Cardputer!\n"
        "LVGL 8.3.11 starter firmware\n"
        "Ready for Launcher."
    );
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}
