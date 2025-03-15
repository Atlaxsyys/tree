#include <stdlib.h>
#include <stdio.h>

#include "tree.h"


Tree_errors create_node(Node_t** node, elem_t value)
{
    *node = (Node_t*) calloc(1, sizeof(Node_t));

    if (*node == nullptr)
    {
        return MEMORY_ALLOC_ERR;
    }

    (*node)->value = value;
    (*node)->left = nullptr;
    (*node)->right = nullptr;

    return SUCCESS;
}

Tree_errors insert_node(Node_t** root, elem_t value)
{
    if (*root == nullptr)
    {
        return create_node(root, value);
    }

    if (value < (*root)->value)
    {
        return insert_node(&((*root)->left), value);
    }
    else
    {
        return insert_node(&((*root)->right), value);
    }

    return SUCCESS;
}

Node_t* search_node(Node_t* root, elem_t value)
{
    if (root == nullptr)  { return nullptr; }
    
    if (root->value == value) { return root; }

    if (value < root->value)  { return search_node(root->left, value);  }
    else                      { return search_node(root->right, value); }

    return nullptr;
}

Tree_errors free_tree(Node_t** node)
{
    if (*node == nullptr) return SUCCESS;

    free_tree(&((*node)->left));
    free_tree(&((*node)->right));

    free(*node);
    *node = nullptr;

    return SUCCESS;
}

Tree_errors dump_tree(Node_t* root, FILE* file)
{
    fprintf(file, "    \"%p\" [shape=Mrecord, style=filled; fillcolor=\"purple\"; label=\"{value: %d | current: %p | { Left: %p | Right: %p } }\"];\n", root, root->value, root, root->left, root->right);
    
    if (root->left)
    {
        fprintf(file, "    \"%p\" -> \"%p\";\n", root, root->left);
        dump_tree(root->left, file);
    }

    if (root->right)
    {
        fprintf(file, "    \"%p\" -> \"%p\";\n", root, root->right);
        dump_tree(root->right, file);
    }

    return SUCCESS;
}

Tree_errors generate_dot(Node_t* root)
{
    static int file_counter = 0;

    char* dot_filename = (char*) calloc(SIZE_DOT_FILENAME, sizeof(char));
    char* png_filename = (char*) calloc(SIZE_PNG_FILENAME, sizeof(char));
    char* command      = (char*) calloc(SIZE_COMMAND,      sizeof(char));

    sprintf(dot_filename, "../tests/graph_%d.dot", file_counter);
    sprintf(png_filename, "../tests/graph_%d.png", file_counter);

    FILE* file = fopen(dot_filename, "w");
    
    fprintf(file, "digraph BinaryTree {\n");
    fprintf(file, "    bgcolor=\"#C0C0C0\";\n\n");
    fprintf(file, "    node [shape=record];\n");
    
    dump_tree(root, file);
    
    fprintf(file, "}\n");
    fclose(file);

    sprintf(command, "dot -Tpng %s -o %s", dot_filename, png_filename);
    system(command);    

    file_counter++;
    
    free(dot_filename);
    free(png_filename);
    free(command);

    return SUCCESS;
}

Node_t* delete_node(Node_t* root, elem_t value)
{
    if (!root) return nullptr;
    
    if (value < root->value)
    {
        root->left = delete_node(root->left, value);
    }

    else if (value > root->value)
    {
        root->right = delete_node(root->right, value);
    }

    else 
    {
        free_tree(&root);

        return nullptr;
    }
    
    return root;
}


