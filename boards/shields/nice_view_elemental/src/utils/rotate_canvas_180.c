#include "../../include/utils/rotate_canvas_180.h"

#include <lvgl.h>
#include <string.h>
#include "../../include/main.h"
#include "../../include/colors.h"

void rotate_main_canvas_180() {
    static lv_color_t cbuf_tmp[LV_CANVAS_BUF_SIZE_TRUE_COLOR(MAIN_CANVAS_WIDTH, MAIN_CANVAS_HEIGHT)];
    memcpy(cbuf_tmp, main_canvas_buffer, sizeof(cbuf_tmp));

    lv_img_dsc_t img;
    img.data = (void*)cbuf_tmp;
    img.header.cf = LV_IMG_CF_TRUE_COLOR;
    img.header.w = MAIN_CANVAS_WIDTH;
    img.header.h = MAIN_CANVAS_HEIGHT;

    lv_canvas_fill_bg(main_canvas, BACKGROUND_COLOR, LV_OPA_COVER);
    lv_canvas_transform(
        main_canvas,
        &img,
        1800,  // 180 degrees in tenths of a degree
        LV_IMG_ZOOM_NONE,
        0, 0,
        MAIN_CANVAS_WIDTH / 2, MAIN_CANVAS_HEIGHT / 2,
        false
    );
}

void rotate_battery_canvas_180() {
    static lv_color_t cbuf_tmp[LV_CANVAS_BUF_SIZE_TRUE_COLOR(BATTERY_CANVAS_WIDTH, BATTERY_CANVAS_HEIGHT)];
    memcpy(cbuf_tmp, battery_canvas_buffer, sizeof(cbuf_tmp));

    lv_img_dsc_t img;
    img.data = (void*)cbuf_tmp;
    img.header.cf = LV_IMG_CF_TRUE_COLOR;
    img.header.w = BATTERY_CANVAS_WIDTH;
    img.header.h = BATTERY_CANVAS_HEIGHT;

    lv_canvas_fill_bg(battery_canvas, BACKGROUND_COLOR, LV_OPA_COVER);
    lv_canvas_transform(
        battery_canvas,
        &img,
        1800,
        LV_IMG_ZOOM_NONE,
        0, 0,
        BATTERY_CANVAS_WIDTH / 2, BATTERY_CANVAS_HEIGHT / 2,
        false
    );
}

void rotate_connectivity_canvas_flipped() {
    static lv_color_t cbuf_tmp[LV_CANVAS_BUF_SIZE_TRUE_COLOR(CONNECTIVITY_CANVAS_WIDTH, CONNECTIVITY_CANVAS_HEIGHT)];
    memcpy(cbuf_tmp, connectivity_canvas_buffer, sizeof(cbuf_tmp));

    lv_img_dsc_t img;
    img.data = (void*)cbuf_tmp;
    img.header.cf = LV_IMG_CF_TRUE_COLOR;
    img.header.w = CONNECTIVITY_CANVAS_WIDTH;
    img.header.h = CONNECTIVITY_CANVAS_HEIGHT;

    lv_canvas_fill_bg(connectivity_canvas, BACKGROUND_COLOR, LV_OPA_COVER);
    lv_canvas_transform(
        connectivity_canvas,
        &img,
        2700,  // 270 degrees (90 original + 180 flip)
        LV_IMG_ZOOM_NONE,
        -1, 0,
        CONNECTIVITY_CANVAS_WIDTH / 2, CONNECTIVITY_CANVAS_HEIGHT / 2,
        false
    );
}
