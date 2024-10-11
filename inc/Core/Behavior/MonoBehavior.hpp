#pragma once

#include <unordered_map>
#include <map>
#include <typeindex>
#include <list>
#include <memory>
#include "Core/Behavior/Behavior.hpp"
#include "Core/Components/Component.hpp"


namespace MoonEngine
{

    class MonoBehavior : public Behavior
    {

    public:
        virtual ~MonoBehavior();

        void start() override;
        void handleInputs(const sf::Event &event) override;
        void update(float dt) override;
        void draw(sf::RenderWindow *window) override;
        void setRequestDestoy(bool request);
        bool isDestroyed() const;
        void setTag(int tag);

        template <typename T, class = std::enable_if_t<std::is_base_of_v<Component,T>>>
        void addComponent(T* component) 
        {
            mComponents[component->GetType()].reset(component);
        }

        template <typename T, class = std::enable_if_t<std::is_base_of_v<Component,T>>>
        T* getComponent() 
        {

            auto it = mComponents.find(T::typeInfo());
            if (it != mComponents.end())
            {
                return static_cast<T *>(it->second.get());
            }

            for (auto &pair : mComponents)
            {
                if (pair.first->IsDerivedFrom(T::typeInfo()))
                {
                    return static_cast<T *>(pair.second.get());
                }
            }
            return nullptr;
        }


        template <typename T, class = std::enable_if_t<std::is_base_of_v<Component,T>>>
        void RemoveComponent()
        {
            auto it = mComponents.find(T::typeInfo());
            if (it != mComponents.end())
            {
                mComponents.erase(it);
                return;
            }

            for (auto &pair : mComponents)
            {
                if (pair.first->IsDerivedFrom(T::typeInfo()))
                {
                    mComponents.erase(pair.first);
                    return;
                }
            }
        }

        int tag() const;

    protected:
        MonoBehavior(int tag = -1);        
        bool mRequestDestroy;
        int mTag;

        private:
            std::unordered_map<const TypeInfo*, std::unique_ptr<Component>> mComponents;
            std::map<int, std::list<Component *>> getOrder() const;
    };
}
