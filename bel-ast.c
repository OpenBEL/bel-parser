#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bel-ast.h"

bel_ast_node* bel_new_ast_node_token(bel_ast_token_type type) {
    bel_ast_node* node;
    node = malloc(sizeof(bel_ast_node));
    node->token = malloc(sizeof(bel_ast_node_token));
    node->token->type  = TOKEN;
    node->token->ttype = type;
    node->token->left  = NULL;
    node->token->right = NULL;
    return node;
};

bel_ast_node* bel_new_ast_node_value(bel_ast_value_type type, char* value) {
    bel_ast_node* node;
    char*         copy_value;

    if (value) {
        copy_value = malloc(strlen(value) + 1);
        strcpy(copy_value, value);
    } else {
        copy_value = NULL;
    }

    node = malloc(sizeof(bel_ast_node));
    node->value = malloc(sizeof(bel_ast_node_value));
    node->value->type  = VALUE;
    node->value->vtype = type;
    node->value->value = copy_value;
    return node;
};

bel_ast* bel_new_ast() {
    bel_ast* ast;
    ast = malloc(sizeof(bel_ast));
    ast->root = NULL;
    return ast;
};

void bel_free_ast(bel_ast* ast) {
    if (!ast) {
        return;
    }
    bel_free_ast_node(ast->root);
    free(ast);
};

void bel_free_ast_node(bel_ast_node* node) {
    if (node->type_info->type == TOKEN) {
        if (node->token->left != NULL) {
            bel_free_ast_node(node->token->left);
        }
        if (node->token->right != NULL) {
            bel_free_ast_node(node->token->right);
        }
	free(node->token);
    } else {
	free(node->value->value);
	free(node->value);
    }

    free(node);
};

void bel_print_ast_node(bel_ast_node* node, char* tree_flat_string) {
    char val[1024 * 32];
    if (node == NULL) {
        strcat(tree_flat_string, "(null) ");
        return;
    }

    switch(node->type_info->type) {
        case TOKEN:
            switch(node->type_info->ttype) {
                case TOKEN_ARG:
                    strcat(tree_flat_string, "ARG ");
                    break;
                case TOKEN_NV:
                    strcat(tree_flat_string, "NV ");
                    break;
                case TOKEN_TERM:
                    strcat(tree_flat_string, "TERM ");
                    break;
            };
            bel_print_ast_node(node->token->left, tree_flat_string);
            bel_print_ast_node(node->token->right, tree_flat_string);
            break;
        case VALUE:
            switch(node->type_info->vtype) {
                case VALUE_FX:
		    if (node->value->value == NULL) {
		        strcat(tree_flat_string, "fx((null)) ");
		    } else {
			sprintf(val, "fx(%s) ", node->value->value);
			strcat(tree_flat_string, val);
		    }
                    break;
                case VALUE_PFX:
		    if (node->value->value == NULL) {
		        strcat(tree_flat_string, "pfx((null)) ");
		    } else {
			sprintf(val, "pfx(%s) ", node->value->value);
			strcat(tree_flat_string, val);
		    }
                    break;
                case VALUE_VAL:
		    if (node->value->value == NULL) {
		        strcat(tree_flat_string, "val((null)) ");
		    } else {
			sprintf(val, "val(%s) ", node->value->value);
			strcat(tree_flat_string, val);
		    }
                    break;
            };
            break;
    };
};

void bel_print_ast(bel_ast* ast) {
    if (!ast) {
        return;
    }

    char tree_flat_string[1024 * 32];
    memset(tree_flat_string, '\0', 1024 * 32);
    bel_print_ast_node(ast->root, tree_flat_string);
    fprintf(stdout, "%s\n", tree_flat_string);
};

char* bel_ast_as_string(bel_ast* ast) {
    if (!ast) {
        return NULL;
    }

    char *tree_flat_string;
    tree_flat_string = calloc(1024 * 32, 1);
    bel_print_ast_node(ast->root, tree_flat_string);
    return tree_flat_string;
};
