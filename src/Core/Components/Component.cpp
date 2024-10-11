#include "Core/Components/Component.hpp"
#include "Core/Components/StateHandler.hpp"


using namespace MoonEngine;

Component::Component(GameObject *parent, int order)
    :   mOrder(order),
        mParent(parent)
{
    
}

Component::~Component()
{
    
}

void Component::instanciate(GameObject *e)
{
    StateHandler::instance()->instanciate(e);
}


int Component::order() const
{
    return mOrder;
}


