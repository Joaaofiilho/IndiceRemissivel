#include "BinaryTree.h"



BinaryTree::BinaryTree()
{
    root = NULL;
}
void BinaryTree::inserir(string dado)
{
    if(root == NULL)
        root = new Node_B(dado);
    else
        insert(root, dado);
}

void BinaryTree::mostraremordem()
{
    inorder(root);
    cout << endl;
}

void BinaryTree::criarArquivoIndice(fstream& arqIndice)
{
    arqIndice.open("arquivos/indice.txt", ios::out);
    if(arqIndice.is_open())
        criarArquivoIndice(root, arqIndice);
    else cout << "Nao foi possivel criar/abrir o arquivo \"indice\"" << endl;
    arqIndice.close();
}

void BinaryTree::criarArquivoIndice(Node_B *tree, fstream& arqIndice)
{
    if (tree == NULL)
        return;
    criarArquivoIndice(tree->left, arqIndice);

    if(arqIndice.is_open())
    {
        arqIndice << tree->data << ": ";
        for(int i = 0; i < tree->linhas.getTam(); i++)
        {
            arqIndice << tree->linhas.get(i) << " ";
        }
        arqIndice << "\n";
    }

    criarArquivoIndice(tree->right, arqIndice);
}

Node_B* BinaryTree::buscar(Node_B *tree, string data)
{
    if(tree == NULL)
        return NULL;
    else
    {
        if(data > tree->data)
            return buscar(tree->right, data);
        else if(data < tree->data)
            return buscar(tree->left, data);
        else
            return tree;
    }
}

Node_B* BinaryTree::buscar(string palavra)
{
    return buscar(root, palavra);
}

/*
 * Height of AVL Tree
 */
int BinaryTree::height(Node_B *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

/*
 * Height Difference
 */
int BinaryTree::diff(Node_B *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}

/*
 * Right- Right Rotation
 */
Node_B *BinaryTree::rr_rotation(Node_B *parent)
{
    Node_B *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
/*
 * Left- Left Rotation
 */
Node_B *BinaryTree::ll_rotation(Node_B *parent)
{
    Node_B *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

/*
 * Left - Right Rotation
 */
Node_B *BinaryTree::lr_rotation(Node_B *parent)
{
    Node_B *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}

/*
 * Right- Left Rotation
 */
Node_B *BinaryTree::rl_rotation(Node_B *parent)
{
    Node_B *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}

/*
 * Balancing AVL Tree
 */
Node_B *BinaryTree::balance(Node_B *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}

/*
 * Insert Element into the tree
 */
Node_B *BinaryTree::insert(Node_B *root, string value)
{
    if (root == NULL)
    {
        root = new Node_B(value);
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        //root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        //root = balance (root);
    }
    return root;
}

/*
 * Inorder Traversal of AVL Tree
 */
void BinaryTree::inorder(Node_B *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<tree->data<<"  ";
    inorder (tree->right);
}
/*
 * Preorder Traversal of AVL Tree
 */
void BinaryTree::preorder(Node_B *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->data<<"  ";
    preorder (tree->left);
    preorder (tree->right);

}

/*
 * Postorder Traversal of AVL Tree
 */
void BinaryTree::postorder(Node_B *tree)
{
    if (tree == NULL)
        return;
    postorder ( tree ->left );
    postorder ( tree ->right );
    cout<<tree->data<<"  ";
}

