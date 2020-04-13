#pragma once

template <class Key, class Value>
class RBTree
{
public:
    RBTree();

private:
    enum Color { Red, Black };
    struct Node
    {
        Node() {}
        Node(Key k, Value v)
            : k(k)
            , v(v)
        {
        }
        Key k;
        Value v;
    };
    struct RBNode
    {
        Node node;
        Color color;
        RBNode *left;
        RBNode *right;
    };

    void leftSpin(RBNode *fatherNode, RBNode *node);
    void rightSpin(RBNode *fatherNode, RBNode *node);
};
template <class Key, class Value>
RBTree<Key, Value>::RBTree()
{
}
/*
 * right spin
 *         |    A                         A
 *         B                          D
 *      D     C           ----->    E   B
 *    E   F G   H                     F   C
 *                                      G   H
 **/
template <class Key, class Value>
void RBTree<Key, Value>::rightSpin(RBTree::RBNode *fatherNode, RBTree::RBNode *node)
{
    auto rightCNode = node->right;
    auto rLCCNode = rightCNode->left;
    node->right = rLCCNode;
    node == fatherNode->left ? fatherNode->left = rightCNode : fatherNode->right = rightCNode;
    rightCNode->right = node;
}

/*
 *left spin
 *      |       A                         A
 *      B                           C
 *   D     C         ----->    B       H
 * E   F  G  H              D    G
 *                       E    F
 **/
template <class Key, class Value>
void RBTree<Key, Value>::leftSpin(RBTree::RBNode *fatherNode, RBTree::RBNode *node)
{
    auto leftCNode = node->left;
    auto lRCCNode = leftCNode->right;
    node->left = lRCCNode;
    node == fatherNode->left ? fatherNode->left = leftCNode : fatherNode->right = leftCNode;
    leftCNode->left = node;
}
