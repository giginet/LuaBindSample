//
//  GameObject.h
//  HelloLua
//
//  Created by giginet on 2013/12/16.
//
//

#ifndef __HelloLua__GameObject__
#define __HelloLua__GameObject__

#include "cocos2d.h"

using namespace cocos2d;
class GameObject :public Node {
  public:
    GameObject(float x, float y);
    void method();
};

#endif /* defined(__HelloLua__GameObject__) */
