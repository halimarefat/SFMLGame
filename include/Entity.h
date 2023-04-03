#include <iostream>
#include <vector>
#include <map>

class Entity
{
    const size_t m_id = 0;
    const std::string m_nameTag = "Default";
    bool m_alive = true;

    Entity(const std::string& nameTag, size_t id);

public:

    std::shared_ptr<CTransform> cTransform;
    std::shared_ptr<CSprite> cSprite;
    std::shared_ptr<CName> cName;
    std::shared_ptr<CShape> cShape;
    std::shared_ptr<CBBox> cBBox;
    
    void kill();
    const std::string nameTag() const;
    const bool alive() const;
};