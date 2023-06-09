#include "Entity.h"

typedef std::vector<std::shared_ptr<Entity>> EntityVector;
typedef std::map<std::string, EntityVector> EntityMap;

class EntityManager
{   
    EntityVector m_entities;
    EntityVector m_toAdd;
    EntityMap m_entityMap;
    size_t m_entitryCount = 0;

public:

    EntityManager() = default;
    void update();
    std::shared_ptr<Entity> addEntity(const std::string& nameTag);
    EntityVector& getEntities();
    EntityVector& getEntities(const std::string& nameTag);
};