#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// ---------- Parse Tree Node ----------
typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// ---------- Parser (Recursive Descent) ----------
char expr[100]; // input expression
int pos = 0;

Node* expression(); // forward declarations
Node* term();
Node* factor();

// Get current character
char peek() {
    return expr[pos];
}

// Consume current character
char get() {
    return expr[pos++];
}

// Factor -> number | '(' Expr ')'
Node* factor() {
    if (isdigit(peek())) {
        return createNode(get());
    }
    else if (peek() == '(') {
        get(); // consume '('
        Node* node = expression();
        get(); // consume ')'
        return node;
    }
    return NULL;
}

// Term -> Factor { (*|/) Factor }
Node* term() {
    Node* node = factor();
    while (peek() == '*' || peek() == '/') {
        char op = get();
        Node* newNode = createNode(op);
        newNode->left = node;
        newNode->right = factor();
        node = newNode;
    }
    return node;
}

// Expr -> Term { (+|-) Term }
Node* expression() {
    Node* node = term();
    while (peek() == '+' || peek() == '-') {
        char op = get();
        Node* newNode = createNode(op);
        newNode->left = node;
        newNode->right = term();
        node = newNode;
    }
    return node;
}

// ---------- Tree Traversals ----------
void inorder(Node* root) {
    if (!root) return;
    if (root->left) printf("(");
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
    if (root->right) printf(")");
}

void preorder(Node* root) {
    if (!root) return;
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
}

// ---------- Main ----------
int main() {
    printf("Enter an arithmetic expression: ");
    scanf("%s", expr);

    Node* root = expression();

    printf("\nInorder   (infix): ");
    inorder(root);
    printf("\nPreorder  (prefix): ");
    preorder(root);
    printf("\nPostorder (postfix): ");
    postorder(root);
    printf("\n");

    return 0;
}

