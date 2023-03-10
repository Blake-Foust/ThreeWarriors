#ifndef RESOURCE_HOLDER_HPP
#define RESOURCE_HOLDER_HPP

#include <string>
#include <memory>
#include <cassert>
#include <unordered_map>


template <typename Resource, typename Identifier>
class ResourceHolder
{
    public:
        void            load(Identifier id, const std::string& filename);
        
        template<typename Parameter>
        void            load(Identifier id, const std::string& filename, const Parameter& secondParam);

        Resource&       get(Identifier id);
        const Resource& get(Identifier id) const; 

    private:
        std::unordered_map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

#include "ResourceHolder.inl"
#endif //RESOURCE_HOLDER_HPP