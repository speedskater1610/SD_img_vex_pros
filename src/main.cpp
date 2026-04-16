#include <utility>

#include "main.h"
#include "liblvgl/display/lv_display.h"
#include "liblvgl/widgets/image/lv_image.h"

namespace ui {
    inline auto screen = []() -> lv_obj_t* {
        return lv_screen_active();
    };

    inline auto set_bg = [](uint32_t hex) -> void {
        lv_obj_set_style_bg_color(screen(), lv_color_hex(hex), 0);
    };

    inline auto centered_img = []<typename T>(T&& src) -> lv_obj_t* {
        auto* img = lv_image_create(screen());

        // forward whatever was passed (eg: const void*, char*, LVGL img desc)
        lv_image_set_src(img, std::forward<T>(src));

        lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);
        return img;
    };
}

inline auto black_background() -> void { ui::set_bg(0x000000); }
inline auto blue_background() -> void { ui::set_bg(0x00008B); }
inline auto red_background() -> void { ui::set_bg(0xFF0000); }

auto display_img_from_c_array() -> void {
    LV_IMAGE_DECLARE(logo);
    ui::centered_img(&logo);
}

auto display_img_from_file(auto&& src) -> void {
    ui::centered_img(std::forward<decltype(src)>(src));
}

auto initialize() -> void {
    red_background();
    display_img_from_c_array();
}

auto competition_initialize() -> void {}
auto autonomous() -> void {}

auto opcontrol() -> void {
    for (;;) {
        pros::delay(20);
    }
}
