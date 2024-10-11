#pragma once 
#include <unordered_map>
#include <typeindex>
#include <memory>
#include "ObjectPool.hpp"

namespace MoonEngine 
{
    class ObjectPoolManager
    {
        
    public:
        ObjectPoolManager();
        ~ObjectPoolManager();

        template <typename T>
        void createPool(int initialSize)
        {
            if(mPools.count(typeid(T)))
            {
                return;
            }
            
            mPools[typeid(T)] = new ObjectPool<T>(initialSize);
        }

        template <typename T>
        T* acquire()
        {
            return static_cast<ObjectPool<T>*>(mPools.at(typeid(T)))->acquire();
        }

        template <typename T>
        void release(T* object)
        {
            static_cast<ObjectPool<T>*>(mPools.at(typeid(T)))->release(object);
        }

        static ObjectPoolManager *instance();
    private:
        static std::unique_ptr<ObjectPoolManager> mInstance;
        std::unordered_map<std::type_index, void*> mPools;
    };

}