#include "ResourceHolder.hpp"

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename){
    std::unique_ptr<Resource> resource(new Resource());
    if(!resource->loadFromFile(filename)){
        throw std::runtime_error("ResourceHolder::load - Failed to Load" + filename);
    }
    auto inserted = this->mResourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
}

template<typename Resource, typename Identifier>
template<typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename, 
                                                const Parameter& secondParam){
                                                    std::unique_ptr<Resource> resource(new Resource());
                                                    if(!resource->loadFromFile(filename, secondParam))
                                                        throw std::runtime_error("ResourceHolder::load - failed to load" + filename);
                                                    
                                                    auto inserted = this->mResourceHolderMap.insert(std::make_pair(id, std::move(resource)));
                                                    assert(inserted.second);

                                                }

template<typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id){
    auto found = this->mResourceMap.find(id);
    assert(found != this->mResourceMap.end());

    return *found->second;
}

template<typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const{
    auto found = mResourceMap.find(id);
    assert(found != this->mResourceMap.end());

    return *found->second;
}

