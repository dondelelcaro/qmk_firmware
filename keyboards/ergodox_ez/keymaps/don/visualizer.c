/*
Copyright 2017 Fred Sundvik

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Currently we are assuming that both the backlight and LCD are enabled
// But it's entirely possible to write a custom visualizer that use only
// one of them
#ifndef LCD_BACKLIGHT_ENABLE
#error This visualizer needs that LCD backlight is enabled
#endif

#ifndef LCD_ENABLE
#error This visualizer needs that LCD is enabled
#endif

#include "visualizer.h"
#include "visualizer_keyframes.h"
#include "lcd_keyframes.h"
#include "lcd_backlight_keyframes.h"
#include "led_backlight_keyframes.h"
#include "system/serial_link.h"
// #include "default_animations.h"
// #include "led_test.h"

static bool keyframe_enable(keyframe_animation_t* animation, visualizer_state_t* state);
static bool keyframe_fade_in(keyframe_animation_t* animation, visualizer_state_t* state);

static const char* welcome_text[] = {"QMK: Don Keymap", "Infinity Ergodox"};

// Just an example how to write custom keyframe functions, we could have moved
// all this into the init function
bool display_welcome(keyframe_animation_t* animation, visualizer_state_t* state) {
    (void)animation;
    // Read the uGFX documentation for information how to use the displays
    // http://wiki.ugfx.org/index.php/Main_Page
    gdispClear(White);
    // You can use static variables for things that can't be found in the animation
    // or state structs
    gdispDrawString(0, 3, welcome_text[0], state->font_dejavusansbold12, Black);
    gdispDrawString(0, 15, welcome_text[1], state->font_dejavusansbold12, Black);
    // Always remember to flush the display
    gdispFlush();
    // you could set the backlight color as well, but we won't do it here, since
    // it's part of the following animation
    // lcd_backlight_color(hue, 0xFF, intensity);
    // We don't need constant updates, just drawing the screen once is enough
    return false;
}

// Feel free to modify the animations below, or even add new ones if needed

static bool keyframe_enable(keyframe_animation_t* animation, visualizer_state_t* state) {
#ifdef LCD_ENABLE
    lcd_keyframe_enable(animation, state);
#endif
#ifdef LCD_BACKLIGHT_ENABLE
    lcd_backlight_keyframe_enable(animation, state);
#endif
#ifdef BACKLIGHT_ENABLE
    led_backlight_keyframe_enable(animation, state);
#endif
    return false;
}

static bool keyframe_disable(keyframe_animation_t* animation, visualizer_state_t* state) {
#ifdef LCD_ENABLE
    lcd_keyframe_disable(animation, state);
#endif
#ifdef LCD_BACKLIGHT_ENABLE
    lcd_backlight_keyframe_disable(animation, state);
#endif
#ifdef BACKLIGHT_ENABLE
    led_backlight_keyframe_disable(animation, state);
#endif
    return false;
}

static bool keyframe_fade_in(keyframe_animation_t* animation, visualizer_state_t* state) {
    bool ret = false;
#ifdef LCD_BACKLIGHT_ENABLE
    ret |= lcd_backlight_keyframe_animate_color(animation, state);
#endif
#ifdef BACKLIGHT_ENABLE
    ret |= led_backlight_keyframe_fade_in_all(animation, state);
#endif
    return ret;
}

static bool keyframe_fade_out(keyframe_animation_t* animation, visualizer_state_t* state) {
    bool ret = false;
#ifdef LCD_BACKLIGHT_ENABLE
    ret |= lcd_backlight_keyframe_animate_color(animation, state);
#endif
#ifdef BACKLIGHT_ENABLE
    ret |= led_backlight_keyframe_fade_out_all(animation, state);
#endif
    return ret;
}

// Don't worry, if the startup animation is long, you can use the keyboard like normal
// during that time
static keyframe_animation_t startup_animation = {
#if LCD_ENABLE
    .num_frames = 3,
#else
    .num_frames = 2,
#endif
    .loop = false,
    .frame_lengths = {
        0, 
#if LCD_ENABLE
        0, 
#endif
        gfxMillisecondsToTicks(5000)},
    .frame_functions = {
            keyframe_enable,
#if LCD_ENABLE
            display_welcome,
#endif
            keyframe_fade_in,
    },
};

keyframe_animation_t suspend_animation = {
#if LCD_ENABLE
    .num_frames = 3,
#else
    .num_frames = 2,
#endif
    .loop = false,
    .frame_lengths = {
#if LCD_ENABLE
        0, 
#endif
        gfxMillisecondsToTicks(1000), 
        0},
    .frame_functions = {
#if LCD_ENABLE
            lcd_keyframe_display_layer_text,
#endif
            keyframe_fade_out,
            keyframe_disable,
    },
};

void user_visualizer_suspend(visualizer_state_t* state) {
    state->layer_text = "Suspending...";
    uint8_t hue = LCD_HUE(state->current_lcd_color);
    uint8_t sat = LCD_SAT(state->current_lcd_color);
    state->target_lcd_color = LCD_COLOR(hue, sat, 0);
    start_keyframe_animation(&suspend_animation);
}

void user_visualizer_resume(visualizer_state_t* state) {
  state->current_lcd_color = LCD_COLOR(0,0,0);
  state->target_lcd_color = LCD_COLOR(0,0,0xFF);
  // initial_update = true;
  start_keyframe_animation(&startup_animation);
}

void initialize_user_visualizer(visualizer_state_t* state) {
    // The brightness will be dynamically adjustable in the future
    // But for now, change it here.
    lcd_backlight_brightness(0x50);
    state->current_lcd_color = LCD_COLOR(0x00, 0x00, 0xFF);
    state->target_lcd_color = LCD_COLOR(0x10, 0xFF, 0xFF);
    start_keyframe_animation(&startup_animation);
    //    start_keyframe_animation(&led_test_animation);
}

void update_user_visualizer_state(visualizer_state_t* state, visualizer_keyboard_status_t* prev_status) {
    // Add more tests, change the colors and layer texts here
    // Usually you want to check the high bits (higher layers first)
    // because that's the order layers are processed for keypresses
    // You can for check for example:
    // state->status.layer
    // state->status.default_layer
    // state->status.leds (see led.h for available statuses)
    if (state->status.layer & 0x20) {
      state->target_lcd_color = LCD_COLOR(0xB0, 0xFF, 0xFF);
      state->layer_text = "Plover";
    }
    else if (state->status.layer & 0x10) {
      state->target_lcd_color = LCD_COLOR(0x90, 0xFF, 0xFF);
      state->layer_text = "Numpad";
    }
    else if (state->status.layer & 0x8) {
      state->target_lcd_color = LCD_COLOR(0x60, 0xFF, 0xFF);
      state->layer_text = "KBD FXNs";
    }
    else if (state->status.layer & 0x4) {
        state->target_lcd_color = LCD_COLOR(0x30, 0xFF, 0xFF);
        state->layer_text = "Mouse";
    }
    else if (state->status.layer & 0x2) {
      state->target_lcd_color = LCD_COLOR(0x00, 0xFF, 0xFF);
        state->layer_text = "FXN/Symbols";
    }
    else {
      state->target_lcd_color = LCD_COLOR(0x00, 0xFF, 0x80);
      state->layer_text = "Default";
    }
}
