#pragma once

namespace MoonEngine
{
    template <typename T>
    class Singleton
    {
    public:
        static T* instance()
        {
            static T* instance = new T();
            return instance;
        }


        Singleton(const Singleton &) = delete;
        Singleton &operator=(const Singleton &) = delete;

    protected:
        Singleton() {}
    };

}
