#pragma once

#include "Core/Behavior/Behavior.hpp"
#include "Core/Components/TypeInfo/TypeInfo.hpp"
#include "Core/Components/TypeInfo/ITypeable.hpp"

namespace MoonEngine
{
    class GameObject;
    struct TypeInfo;

    class Component : public Behavior, public ITypeable
    {

    public:
        virtual ~Component();
        int order() const;
        

      
        DECLARE_COMPONENT_BASE_TYPE(Component)

    protected:
        Component(GameObject *parent, int order = -1);
        void instanciate(GameObject *e);

        template <typename T>
        T* parent()
        {
            return static_cast<T*>(mParent);
        }

        GameObject *parent()
        {
            return mParent;
        }


    private:
        GameObject *mParent;
        int mOrder;
        sf::Vector2f mRelativePos;
    };
}

