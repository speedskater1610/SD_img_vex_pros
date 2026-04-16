#define DEF_IF_NOT_DEFINED(x) \
    #ifndef x                 \
    #define x                 \
    #endif

DEF_IF_NOT_DEFINED(LV_ATTRIBUTE_MEM_ALIGN)
DEF_IF_NOT_DEFINED(LV_ATTRIBUTE_IMAGE_LOGO)

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "pros/apix.h"
#endif

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

/* Put the raw hex in here -- https://lvgl.io/tools/imageconverter */
const uint8_t logo_map[] = {

};

const lv_image_dsc_t logo = {
  .header.cf = LV_COLOR_FORMAT_RGB565A8,
  .header.magic = LV_IMAGE_HEADER_MAGIC,
  .header.w = 251,
  .header.h = 240,
  .data_size = 60240 * 3,
  .data = logo_map,
};
