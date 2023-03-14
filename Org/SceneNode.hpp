#ifndef SCENENODE_H
#define SCENENODE_H
#include <memory>
#include <vector>

class SceneNode{
    public:
        typedef std::unique_ptr<SceneNode> Sptr;
    
    public:
        //Default Constructor
        SceneNode();
        void attachChild(Sptr child);
        Sptr detachChild(const SceneNode& node);
    
    private:
        std::vector<Sptr> mChildren;
        SceneNode*        mParent;

};



#endif //SCENENODE_H