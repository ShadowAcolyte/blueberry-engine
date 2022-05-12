#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

#include <blueberry/graphics/3d/perspective_camera.hh>

const glm::vec3 blueberry::PerspectiveCamera::up = glm::vec3(0.0f, 1.0f, 0.0f);

blueberry::PerspectiveCamera::PerspectiveCamera(float fov, float aspect_ratio, float znear, float zfar)
{
    m_yaw = 0;
    m_pitch = 0;
    m_fov = fov;

    m_position = glm::vec3(0.0f, 0.0f, 0.0f);
    m_direction = glm::vec3(0.0f, 0.0f, 1.0f);

    m_projection = glm::perspective(fov, aspect_ratio, znear, zfar);
    m_view = glm::lookAt(m_position, m_position + m_direction, PerspectiveCamera::up);
    m_projView = m_projection * m_view;
}

void blueberry::PerspectiveCamera::update_projection(float fov, float aspect_ratio, float znear, float zfar)
{
    m_projection = glm::perspective(fov, aspect_ratio, znear, zfar);
    m_projView = m_projection * m_view;
}

void blueberry::PerspectiveCamera::update()
{
    m_direction.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_direction.y = sin(glm::radians(m_pitch));
    m_direction.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_direction = glm::normalize(m_direction);

    m_view = glm::lookAt(m_position, m_position + m_direction, PerspectiveCamera::up);
    m_projView = m_projection * m_view;
}
