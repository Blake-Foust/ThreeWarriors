#ifndef CHARACTER_H
#define CHARACTER_H
#include "Entity.hpp"

class Character : public Entity
{
    public:
        enum Type{
            PinkMonster,
            OwlMonster,
            DudeMonster
        };
    public:
        explicit Character(Type type);
    
    private:
        Type    mType;


};

#endif //CHARACTER_H