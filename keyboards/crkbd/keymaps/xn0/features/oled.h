#pragma once

#ifdef OLED_ENABLE
    void oled_render_logo(void);
    void render_space(void);
    void render_mod_status_gui_alt(uint8_t modifiers);
    void render_mod_status_ctrl_shift(uint8_t modifiers);
    void render_logo(void);
    void render_layer_state(void);
    void render_status_main(void);
    oled_rotation_t oled_init_user(oled_rotation_t rotation);
    bool oled_task_user(void);
#endif