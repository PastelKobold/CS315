//Java code of the red-black tree.
//Needs a node class. Maybe nodes should be stored in their own header file to be used by both?

/*private Node insert(Node h, Key key, Value val){ 
 if (h == null) 
    return new Node(key, val, RED);
 int cmp = key.compareTo(h.key);
 if (cmp == 0) 
    h.val = val;
 else if (cmp < 0) 
    h.left = insert(h.left, key, val); 
 else 
    h.right = insert(h.right, key, val); 
 if (isRed(h.right))
    h = rotateLeft(h); 
 if (isRed(h.left) && isRed(h.left.left))
    h = rotateRight(h);
 if (isRed(h.left) && isRed(h.right))
    colorFlip(h);
 return h;
}*/