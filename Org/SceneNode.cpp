#include "SceneNode.hpp"

void SceneNode::attachChild(Sptr child){
    child->mParent = this;
    mChildren.push_back(std::move(child));
};

SceneNode::Sptr SceneNode::detachChild(const SceneNode& node){
    auto found = std::find_if(mChildren.begin(), mChildren.end(),
    [&] (Sptr& p) -> bool {return p.get() == &node;});
    
    assert(found != mChildren.end());

    Sptr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
};

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform(); 

    drawCurrent(target, states);
    for(auto itr = mChildren.begin(); itr != mChildren.end(); ++itr){
        (*itr)->draw(target, states);
    }
}

