#pragma once 


namespace MoonEngine
{
    struct TypeInfo;

    class ITypeable
    {

    public:
        virtual const TypeInfo* GetType() const = 0;
        virtual ~ITypeable(){};

    private:
        
    protected:
        ITypeable(){};
    };

}

