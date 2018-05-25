#ifndef NODE_H
#define NODE_H


class Node
{
private:
    Point coord_;

public:
    Node();
    Point getCoord(){return coord_;}
};

#endif // NODE_H
