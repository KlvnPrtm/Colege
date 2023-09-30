#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A tree node. Holds pointers to left and right sub-trees, and some data (a string).
 */
typedef struct node {
    struct node *left;
    struct node *right;
    char *string;
} node;

node *root; /* pointers automatically initialized to NULL */

int insert(const char *string, node *root) {

    /* Add a string to the tree. Keeps in order, ignores dupes.
     */
    int num = strcmp(root->string, string);
    node *temp;

    for(;;) {
        if ( 0 == num)
            /* duplicate string - ignore it. */
            return 1;
        else if (-1 == num) {
            /* create new node, insert as right sub-tree.
             */
            if ( NULL == root -> right ) {
                temp = malloc(sizeof(node));
                temp -> left = NULL;
                temp -> right = NULL;
                temp -> string = strdup(string);
                return 2;
            }
            else
                root = root -> right;
        }
        else if ( NULL == root ->left ) {
            /* create new node, insert as left sub-tree.
             */
            temp = malloc(sizeof(node));
            temp -> left = NULL;
            temp -> right = NULL;
            temp -> string = strdup(string);
            return 2;
        }
        else
            root = root -> left;
    }
}


void print(node *root) {   
    /* in-order traversal -- first process left sub-tree.
     */
    if ( root -> left != NULL )
        print(root->left);
    /* then process current node.
     */
    fputs(root->string, stdout);

    /* then process right sub-tree
     */
    if ( root->right != NULL )
        print(root->right);
}

int main() {

    char line[100];

    /* Let user enter some data. Enter an EOF (e.g., ctrl-D or F6) when done.
     */
    while ( fgets(line, 100, stdin))
        insert(line, root);

    /* print out the data, in order
     */
    print(root);
    return 0;
}