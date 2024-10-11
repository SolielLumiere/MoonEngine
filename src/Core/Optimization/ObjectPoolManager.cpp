#include "Core/Optimization/ObjectPoolManager.hpp"

using namespace MoonEngine;


std::unique_ptr<ObjectPoolManager> ObjectPoolManager::mInstance = nullptr;

ObjectPoolManager::ObjectPoolManager()
{
}

ObjectPoolManager::~ObjectPoolManager()
{
}

ObjectPoolManager* MoonEngine::ObjectPoolManager::instance()
{
    if(mInstance.get() == nullptr)
    {
        mInstance.reset(new ObjectPoolManager());
    }

    return mInstance.get();
}
