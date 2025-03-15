typedef int elem_t;

typedef struct Node_t {
    elem_t value;
    struct Node_t* left;
    struct Node_t* right;
} Node_t;

enum Tree_errors
{
    SUCCESS = 0,
    MEMORY_ALLOC_ERR = 1,
};

const int SIZE_DOT_FILENAME = 60;
const int SIZE_PNG_FILENAME = 60;
const int SIZE_COMMAND      = 120;

Tree_errors create_node(Node_t** node, elem_t value);
Tree_errors insert_node(Node_t** root, elem_t value);
Node_t* search_node(Node_t* root, elem_t value);
Tree_errors free_tree(Node_t** node);
Tree_errors dump_tree(Node_t* root, FILE* file);
Tree_errors generate_dot(Node_t* root);
Node_t* delete_node(Node_t* root, elem_t value);