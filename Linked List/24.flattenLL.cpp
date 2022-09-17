#Approach 1: recursive 

//same logic as of merge two sorted linked list just replacing temp -> next to temp -> child/bottom
//coz print is initialized in that way only. so we'll attach nodes in child pointer.

Node* merge(Node* l1, Node* l2)
  {
      //if one list is empty return the other one
      if (!l1) return l2;
      if (!l2) return l1;
      
      //dummy node, we'll add sorted elements in it
      Node* ans = new Node(-1);
      Node* temp = ans;//use this to traverse
      
      while (l1 && l2)
      {
          if (l1 -> data < l2 -> data)
          {
              temp -> bottom = l1;
              temp = l1;
              l1 = l1 -> bottom;
          }
          else
          {
              temp -> bottom = l2;
              temp = l2;
              l2 = l2 -> bottom;
          }
      }
      while (l1)
      {
          temp -> bottom = l1;
          temp = l1;
          l1 = l1 -> bottom;
      }
      while (l2)
      {
          temp -> bottom = l2;
          temp = l2;
          l2 = l2 -> bottom;
      }
      return ans -> bottom;
      //to free dummy node we can simply store ans -> next and then delete the node.
  }
/*  Function which returns the  root of 
    the flattened linked list. */

Node *flatten(Node *root)
{
   if (root == NULL || root -> next == NULL)
        return root;
    //recursion will solve all the element on right, just solve the current case!
    Node* right = flatten(root -> next);

    return merge(root, right);
}

#Approach 2 : Iterative