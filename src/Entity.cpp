#include "Entity.h"

void Entity::kill()
{
    m_alive = false;
}

const std::string Entity::nameTag() const
{
    return m_nameTag;
}

const bool Entity::alive() const
{
    return m_alive;
}