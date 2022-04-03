#pragma once

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

namespace blueberry
{
    class PerspectiveCamera
    {
    public:
        float m_fov;
        float m_pitch;
        float m_yaw;

        glm::vec3 m_position;
        glm::vec3 m_direction;
        static const glm::vec3 up; // World's "up" direction

        glm::mat4 m_view;
        glm::mat4 m_projection;
        glm::mat4 m_projView;

        PerspectiveCamera() = default;
        PerspectiveCamera(float fov, float aspectRatio, float znear, float zfar);

        // Update view and proj-view matrices, should ideally be called once per frame
        void update();
        // Update projection matrix
        void updateProjection(float fov, float aspectRatio, float znear, float zfar);
    };
}
