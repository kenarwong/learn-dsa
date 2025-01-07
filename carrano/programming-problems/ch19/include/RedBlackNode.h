#ifndef RED_BLACK_NODE_
#define RED_BLACK_NODE_

#include "BinaryNode.h"

enum Color {RED, BLACK};

template<class ItemType>
class RedBlackNode : public BinaryNode<ItemType>
{
private:
  Color leftColor, rightColor;
public:
  // Get and set methods for leftColor and rightColor
  // . . .
}; // end RedBlackNode

#endif