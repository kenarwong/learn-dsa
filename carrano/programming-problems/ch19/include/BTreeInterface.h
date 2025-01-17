/** Interface for the ADT Btree.
 @file BTreeInterface.h */
#ifndef B_TREE_INTERFACE_
#define B_TREE_INTERFACE_
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
   
   /** Gets the data that is in the root of this Btree.
    @pre  The Btree is not empty.
    @post  The root's data has been returned, and the Btree is unchanged.
    @return  The data in the root of the Btree. */
   virtual ItemType getRootData() const = 0;
   
   /** Replaces the data in the root of this Btree with the given data,
    if the tree is not empty. However, if the tree is empty, inserts a new
    root node containing the given data into the tree.
    @pre  None.
    @post  The data in the root of the Btree is as given.
    @param newData  The data for the root. */
   virtual void setRootData(const ItemType& newData) = 0;
   
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
   
   /** Retrieves the specified data from this Btree.
    @post  The desired data has been returned, and the Btree
       is unchanged. If no such data was found, an exception is thrown.
    @param target  The data to locate.
    @return  The data in the Btree that matches the given data.*/
   virtual ItemType getEntry(const ItemType& target) const = 0;
   
   /** Tests whether the specified data occurs in this Btree.
    @post  The Btree is unchanged.
    @param target  The data to find.
    @return  True if data matching the target occurs in the tree, or false if not. */
   virtual bool contains(const ItemType& target) const = 0;
   
   /** Traverses this Btree in preorder (inorder, postorder) and
       calls the function visit once for each node.
    @param visit  A client-defined function that performs an operation on
       either each visited node or its data. */
   virtual void preorderTraverse(void visit(ItemType&)) const = 0;
   virtual void inorderTraverse(void visit(ItemType&)) const = 0;
   virtual void postorderTraverse(void visit(ItemType&)) const = 0;
   
   /** Destroys this tree and frees its assigned memory. */
   virtual ~BTreeInterface() { }
}; // end BTreeInterface
#endif