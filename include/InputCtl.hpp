#pragma once
#include "check_gl.hpp"
#include <memory>
#include <glm/glm.hpp>
#include "KeyBinding.hpp"

class InputCtl
{

public:
    InputCtl();
    ~InputCtl();
    InputCtl(InputCtl&&) = delete;


    void register_callbacks(GLFWwindow* window);


    glm::mat4x4 get_view_matrix();
    glm::mat4x4 get_projection_matrix();

private:
    void cursor_pos_callback(double xpos, double ypos);
    void mouse_button_callback(int button, int action, int mods);
    void scroll_callback(double xoffset, double yoffset);
    void key_callback(int key, int scancode, int action, int mods);
    void framebuffer_size_callback(int width, int height);


public:
	class CameraAttributes;
	std::unique_ptr<CameraAttributes> const Camera;


    struct InputPreference {
        float zoom_speed = 0.2f;
        float orbit_speed = 1.0f;
        float drift_speed = 1.0f;
        float pan_speed = 2.0f;
        MouseBinding orbit_binding = { Modifier::kNone, MouseButton::kLMB };
        MouseBinding drift_binding = { Modifier::kCtrl, MouseButton::kLMB };
        MouseBinding pan_binding = { Modifier::kShift, MouseButton::kLMB };
        MouseBinding zoom_binding = { Modifier::kNone, MouseButton::kWheel };
        MouseBinding hitchcock_binding = { Modifier::kShift, MouseButton::kWheel };
        int zoom_axis = 1;
        bool clamp_cursor = true;
    } m_inputPref;
};