#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <vector>
#include <memory>
#include <Core/Components/Component.hpp>

namespace MoonEngine
{
    class ICollider : public Component
    {
        
    public:
        ICollider(GameObject *parent, const sf::Vector2f &relativePos = sf::Vector2f(0, 0), float relativeAngle = 0, int order = -1);
        virtual ~ICollider();

        virtual bool intersects(const ICollider *other);
        virtual bool intersects(const sf::FloatRect &other);
        virtual void update(float dt) override;
        virtual void draw(sf::RenderWindow *window) override;
        virtual void setPosition(const sf::Vector2f &pos);
        virtual sf::Vector2f getCenter() const;


        void setColor(const sf::Color &color);
        void setFillColor(const sf::Color &color);
        void setOrigin(const sf::Vector2f &origin);
        void setIsTrigger(bool isTrigger);
        bool isTrigger();

        
        
        const std::vector<sf::Shape*> &colliders() const;

        template <typename T>
        const T* getCollider(int index) {
            return static_cast<const T*>(mColliders.at(index));
        }

        bool operator == (const sf::FloatRect &rect);
        bool operator == (const ICollider &other);

        DECLARE_COMPONENT_BASE_TYPE(ICollider)

    protected:
        std::vector<sf::Shape*> mColliders;
        bool mIsTrigger;
        sf::Vector2f mRelative;
        float mRelativeAngle;
    };
}


