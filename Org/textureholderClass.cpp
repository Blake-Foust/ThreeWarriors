#include "textureholderClass.h"
#include <unordered_map>
#include <memory>

//Loading from files
void TextureHolder::load(Textures::ID id, const std::string& filename){
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    if(!texture->loadFromFile(filename)){
        throw std::runtime_error("TextureHolder::load - Failed to load + " + filename);
    }

    auto inserted = this->mTextureMap.insert(std::make_pair(id,std::move(texture)));
    assert(inserted.second);
}; 

//Accessing the Texture
sf::Texture& TextureHolder::get(Textures::ID id){
    auto found = this->mTextureMap.find(id);
    assert(found != mTextureMap.end());
    
    return *found->second;
}; 

const sf::Texture& TextureHolder::get(Textures::ID id) const{
    auto found = this->mTextureMap.find(id);
    return *found->second;
}; 