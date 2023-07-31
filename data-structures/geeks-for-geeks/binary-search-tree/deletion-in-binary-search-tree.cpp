// https://www.geeksforgeeks.org/deletion-in-binary-search-tree/

class Node {
public:
  int data;
  Node *left;
  Node *right;
};

Node *find_min(Node *root, Node *&par) {
  if (root->left) {
    par = root;
    return find_min(root->left, par);
  }
  return root;
}

Node *deleteNodeRec(Node *root, Node *par, int X) {
  if (!root) {
    return 0;
  }
  if (root->data > X) {
    return deleteNodeRec(root->left, root, X);
  } else if (root->data < X) {
    return deleteNodeRec(root->right, root, X);
  }

  if (root->left == 0 && root->right == 0) {
    if (par->left == root) {
      par->left = 0;
    }
    if (par->right == root) {
      par->right = 0;
    }
    return root;
  }
  if (root->left && root->right == 0) {
    if (par->left == root) {
      par->left = root->left;
    }
    if (par->right == root) {
      par->right = root->left;
    }
    return root;
  }
  if (root->left == 0 && root->right) {
    if (par->left == root) {
      par->left = root->right;
    }
    if (par->right == root) {
      par->right = root->right;
    }
    return root;
  }
  Node *p_min = root;
  Node *min = find_min(root->right, p_min);
  if (p_min != root) {
    p_min->left = min->right;
  } else {
    p_min->right = min->right;
  }
  int temp = min->data;
  min->data = root->data;
  root->data = temp;
  return root;
}

// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
  if (root->data > X) {
    deleteNodeRec(root->left, root, X);
    return root;
  }
  if (root->data < X) {
    deleteNodeRec(root->right, root, X);
    return root;
  }
  if (root->right) {
    Node *p_min = root;
    Node *min = find_min(root->right, p_min);
    if (p_min != root) {
      p_min->left = min->right;
    } else {
      p_min->right = min->right;
    }
    int temp = min->data;
    min->data = root->data;
    root->data = temp;
    return root;
  } else {
    return root->left;
  }
}

int main() { return 0; }
