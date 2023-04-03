#include <iostream>
#include <vector>
#include <map>

typedef std::vector<std::shared_ptr<Entity>> EntityVector;
typedef std::map<std::string, EntityVector> EntityMap;

class EntityManager
{   
    EntityVector m_entities;
    EntityMap m_entityMap;
    size_t m_entitryCount = 0;

public:

    EntityManager() = default;
    std::shared_ptr<Entity> addEntity(cont std::string& nameTag);
    EntityVector& getEntities();
    EntityVector& getEntities(const std::string& nameTag);
};