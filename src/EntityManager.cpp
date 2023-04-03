#include "EntityManager.h"

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& nameTag)
{
    auto e = std::shared_ptr<Entity>(new Entity(nameTag, m_entitryCount++));
    m_toAdd.push_back(e);
    return e;
}

void EntityManager::update()
{
    for(auto& e : m_toAdd)
    {
        m_entities.push_back(e);
        m_entityMap[e->nameTag()].push_back(e);
    }
    m_toAdd.clear();

    for(auto& e : m_entities)
    {
        std::remove_if(m_entities.begin(), m_entities.end(), [](std::shared_ptr<Entity> e) { return !e->alive(); });
    }
}
