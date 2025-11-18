#include <include/display.h>
#include <M5Cardputer.h>
#include <lvgl.h>

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[320 * 10];

static void flush_cb(lv_disp_drv_t *disp,
                     const lv_area_t *area,
                     lv_color_t *color_p) {

    // Push image chunk to Cardputer display
    M5Cardputer.Display.pushImage(
        area->x1,
        area->y1,
        area->x2 - area->x1 + 1,
        area->y2 - area->y1 + 1,
        (uint16_t*)color_p
    );

    lv_disp_flush_ready(disp);
}

void initDisplay() {
    lv_init();

    // Setup keyboard input group
    lv_group_t *g = lv_group_create();
    lv_group_set_default(g);

    lv_disp_draw_buf_init(&draw_buf, buf, NULL, 320 * 10);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);

    disp_drv.hor_res = 320;
    disp_drv.ver_res = 240;
    disp_drv.draw_buf = &draw_buf;
    disp_drv.flush_cb = flush_cb;

    lv_disp_drv_register(&disp_drv);
}
