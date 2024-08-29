#ifndef NODE_
#define NODE_

template<class ItemType>
class Node
{
  public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType getItem() const;
    Node<ItemType>* getNext() const;

  private:
    ItemType item;
    Node<ItemType>* next;
};

#endif