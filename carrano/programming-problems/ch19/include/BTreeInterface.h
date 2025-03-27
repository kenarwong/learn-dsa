#ifndef B_TREE_INTERFACE_H
#define B_TREE_INTERFACE_H
#include "NotFoundException.h"

template<class ItemType>
class BTreeInterface
{
public:
   /** Tests whether this Btree is empty.
    @return  True if the Btree is empty, or false if not. */
   virtual bool isEmpty() const = 0;
   
   /** Gets the height of this Btree.
    @return  The height of the Btree. */
   virtual int getHeight() const = 0;
   
   /** Gets the number of nodes in this Btree.
    @return  The number of nodes in the Btree. */
   virtual int getNumberOfNodes() const = 0;
   
   /** Adds the given data to this Btree.
    @param newData  The data to add to the Btree.
    @post  The Btree contains the new data.
    @return  True if the addition is successful, or false if not. */
   virtual bool add(const ItemType& newData) = 0;
   
   /** Removes the specified data from this Btree.
    @param target  The data to remove from the Btree.
    @return  True if the removal is successful, or false if not. */
   virtual bool remove(const ItemType& target) = 0;
   
   /** Removes all data from this Btree. */
   virtual void clear() = 0;
   
   /** Tests whether the specified data occurs in this Btree.
    @post  The Btree is unchanged.
    @param target  The data to find.
    @return  True if data matching the target occurs in the tree, or false if not. */
   virtual bool contains(const ItemType& target) const = 0;
   
  //  /** Traverses this Btree in preorder (inorder, postorder) and
  //      calls the function visit once for each node.
  //   @param visit  A client-defined function that performs an operation on
  //      either each visited node or its data. */
  //  virtual void preorderTraverse(void visit(ItemType&)) const = 0;
  //  virtual void inorderTraverse(void visit(ItemType&)) const = 0;
  //  virtual void postorderTraverse(void visit(ItemType&)) const = 0;
   
   /** Destroys this tree and frees its assigned memory. */
   virtual ~BTreeInterface() { }
}; // end BTreeInterface
#endif