#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>

namespace MoonEngine
{
    struct TypeInfo 
    {
        static inline std::unordered_map<std::string, TypeInfo>& GetTypesMap() 
        {
            static std::unordered_map<std::string, TypeInfo> typesMap;
            return typesMap;
        }

        std::string name;
        TypeInfo* parent;
        std::unordered_set<TypeInfo*> children;

        TypeInfo(const std::string &n, TypeInfo* p = nullptr) : name(n), parent(p) 
        {
            if (p) p->children.insert(this);
        }

        bool IsDerivedFrom(const TypeInfo* other) const
        {
            
            for (const TypeInfo* current = this; current; current = current->parent) 
            {
                if (current == other) return true;
            }
            return false;
        }
    };

    #define TO_STRING( x ) #x

    #define DECLARE_COMPONENT_TYPE(name, parent) \
        static MoonEngine::TypeInfo &_type_info_##name(){static MoonEngine::TypeInfo _(#name, &_type_info_##parent()); return _;}; \
        static const MoonEngine::TypeInfo* typeInfo() { return &_type_info_##name(); } \
        virtual const MoonEngine::TypeInfo* GetType() const override { return &_type_info_##name(); }  


    #define DECLARE_COMPONENT_BASE_TYPE(name) \
        static MoonEngine::TypeInfo &_type_info_##name(){static MoonEngine::TypeInfo _(#name, nullptr); return _;} \
        static const MoonEngine::TypeInfo* typeInfo() { return &_type_info_##name(); } \
        virtual const MoonEngine::TypeInfo* GetType() const override { return &_type_info_##name(); }

}

