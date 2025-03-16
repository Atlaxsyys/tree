#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main()
{
    Node_t* root = nullptr;
    
    insert_node(&root, "spokoinoi");
    generate_dot(root);

    insert_node(&root, "nochi");
    generate_dot(root);

    insert_node(&root, "I");
    generate_dot(root);

    insert_node(&root, "want");
    generate_dot(root);

    insert_node(&root, "sleep");
    generate_dot(root);

    insert_node(&root, "goodbye");
    generate_dot(root);

    insert_node(&root, "goodluck");
    generate_dot(root);
    
    free_tree(&root);
    
    return 0;
}
