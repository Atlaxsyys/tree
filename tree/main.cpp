#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main()
{
    Node_t* root = nullptr;
    
    insert_node(&root, 50);
    generate_dot(root);

    insert_node(&root, 30);
    generate_dot(root);

    insert_node(&root, 70);
    generate_dot(root);

    insert_node(&root, 20);
    generate_dot(root);

    insert_node(&root, 40);
    generate_dot(root);

    insert_node(&root, 60);
    generate_dot(root);

    insert_node(&root, 80);
    generate_dot(root);
    
    
    free_tree(&root);
    
    return 0;
}
