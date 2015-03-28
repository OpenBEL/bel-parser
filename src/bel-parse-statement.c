
/* #line 1 "bel-parse-statement.rl" */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libbel.h"
#include "bel-ast.h"
#include "bel-node-stack.h"


/* #line 12 "bel-parse-statement.c" */
static const int set_start = 1;
static const int set_first_final = 169;
static const int set_error = 0;

static const int set_en_arguments = 9;
static const int set_en_term = 165;
static const int set_en_statement = 1;


/* #line 11 "bel-parse-statement.rl" */


bel_ast* bel_parse_statement(char* line) {
    int             cs;
    char            *p;
    char            *pe;
    int             top;
    int             *stack;
    bel_ast_node*   statement;
    bel_ast_node*   parent_statement;
    bel_ast_node*   subject;
    bel_ast_node*   rel;
    bel_ast_node*   object;
    bel_ast_node*   term;
    bel_ast_node*   current_nv;
    bel_ast_node*   arg;
    bel_ast*        ast;
    bel_node_stack* term_stack;
    bel_node_stack* statement_stack;
    char            *function;
    char            *relationship;
    char            *value;
    int             fi;
    int             ri;
    int             vi;

    // Copy line to stack; Append new line if needed.
    int             line_length = strlen(line);
    int             i;
    char            input[line_length + 2];
    strcpy(input, line);
    for (i = line_length - 1; (input[i] == '\n' || input[i] == '\r'); i--)
        input[i] = '\0';
    input[i + 1] = '\n';
    input[i + 2] = '\0';

    p                 = input;
    pe                = input + strlen(input);
    top               = 0;
    stack             = malloc(sizeof(int) * TERM_STACK_SIZE);
    current_nv        = NULL;
    function          = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    relationship      = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    value             = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    fi                = 0;
    ri                = 0;
    vi                = 0;

    term_stack        = stack_init(TERM_STACK_SIZE);
    statement_stack   = stack_init(STATEMENT_STACK_SIZE);
    statement         = bel_new_ast_node_token(BEL_TOKEN_STATEMENT);
    parent_statement  = NULL;
    term              = NULL;
    ast               = bel_new_ast();
    ast->root         = statement;

    stack_push(statement_stack, statement);

    memset(function, '\0', BEL_VALUE_CHAR_LEN);
    memset(relationship, '\0', BEL_VALUE_CHAR_LEN);
    memset(value, '\0', BEL_VALUE_CHAR_LEN);

    
/* #line 86 "bel-parse-statement.c" */
	{
	cs = set_start;
	top = 0;
	}

/* #line 92 "bel-parse-statement.c" */
	{
	if ( p == pe )
		goto _test_eof;
	goto _resume;

_again:
	switch ( cs ) {
		case 1: goto st1;
		case 0: goto st0;
		case 2: goto st2;
		case 3: goto st3;
		case 4: goto st4;
		case 5: goto st5;
		case 6: goto st6;
		case 169: goto st169;
		case 7: goto st7;
		case 170: goto st170;
		case 8: goto st8;
		case 9: goto st9;
		case 10: goto st10;
		case 11: goto st11;
		case 12: goto st12;
		case 13: goto st13;
		case 14: goto st14;
		case 15: goto st15;
		case 16: goto st16;
		case 171: goto st171;
		case 17: goto st17;
		case 18: goto st18;
		case 19: goto st19;
		case 20: goto st20;
		case 21: goto st21;
		case 22: goto st22;
		case 23: goto st23;
		case 24: goto st24;
		case 25: goto st25;
		case 172: goto st172;
		case 26: goto st26;
		case 27: goto st27;
		case 28: goto st28;
		case 173: goto st173;
		case 29: goto st29;
		case 30: goto st30;
		case 31: goto st31;
		case 32: goto st32;
		case 174: goto st174;
		case 33: goto st33;
		case 34: goto st34;
		case 35: goto st35;
		case 36: goto st36;
		case 175: goto st175;
		case 37: goto st37;
		case 38: goto st38;
		case 39: goto st39;
		case 40: goto st40;
		case 41: goto st41;
		case 176: goto st176;
		case 42: goto st42;
		case 43: goto st43;
		case 44: goto st44;
		case 45: goto st45;
		case 177: goto st177;
		case 178: goto st178;
		case 46: goto st46;
		case 47: goto st47;
		case 48: goto st48;
		case 49: goto st49;
		case 50: goto st50;
		case 51: goto st51;
		case 52: goto st52;
		case 53: goto st53;
		case 54: goto st54;
		case 179: goto st179;
		case 55: goto st55;
		case 56: goto st56;
		case 57: goto st57;
		case 58: goto st58;
		case 59: goto st59;
		case 60: goto st60;
		case 61: goto st61;
		case 62: goto st62;
		case 63: goto st63;
		case 64: goto st64;
		case 65: goto st65;
		case 180: goto st180;
		case 66: goto st66;
		case 67: goto st67;
		case 68: goto st68;
		case 181: goto st181;
		case 69: goto st69;
		case 70: goto st70;
		case 71: goto st71;
		case 182: goto st182;
		case 72: goto st72;
		case 73: goto st73;
		case 74: goto st74;
		case 75: goto st75;
		case 76: goto st76;
		case 183: goto st183;
		case 77: goto st77;
		case 78: goto st78;
		case 79: goto st79;
		case 80: goto st80;
		case 81: goto st81;
		case 184: goto st184;
		case 82: goto st82;
		case 83: goto st83;
		case 84: goto st84;
		case 85: goto st85;
		case 86: goto st86;
		case 87: goto st87;
		case 88: goto st88;
		case 89: goto st89;
		case 90: goto st90;
		case 185: goto st185;
		case 91: goto st91;
		case 92: goto st92;
		case 186: goto st186;
		case 93: goto st93;
		case 94: goto st94;
		case 95: goto st95;
		case 96: goto st96;
		case 97: goto st97;
		case 98: goto st98;
		case 99: goto st99;
		case 100: goto st100;
		case 101: goto st101;
		case 102: goto st102;
		case 103: goto st103;
		case 104: goto st104;
		case 105: goto st105;
		case 106: goto st106;
		case 107: goto st107;
		case 187: goto st187;
		case 108: goto st108;
		case 109: goto st109;
		case 110: goto st110;
		case 188: goto st188;
		case 111: goto st111;
		case 112: goto st112;
		case 113: goto st113;
		case 114: goto st114;
		case 189: goto st189;
		case 115: goto st115;
		case 116: goto st116;
		case 117: goto st117;
		case 118: goto st118;
		case 119: goto st119;
		case 190: goto st190;
		case 120: goto st120;
		case 121: goto st121;
		case 122: goto st122;
		case 123: goto st123;
		case 124: goto st124;
		case 125: goto st125;
		case 126: goto st126;
		case 127: goto st127;
		case 191: goto st191;
		case 128: goto st128;
		case 129: goto st129;
		case 130: goto st130;
		case 131: goto st131;
		case 132: goto st132;
		case 192: goto st192;
		case 133: goto st133;
		case 134: goto st134;
		case 135: goto st135;
		case 136: goto st136;
		case 137: goto st137;
		case 138: goto st138;
		case 139: goto st139;
		case 140: goto st140;
		case 193: goto st193;
		case 141: goto st141;
		case 142: goto st142;
		case 143: goto st143;
		case 144: goto st144;
		case 145: goto st145;
		case 146: goto st146;
		case 147: goto st147;
		case 148: goto st148;
		case 194: goto st194;
		case 149: goto st149;
		case 150: goto st150;
		case 151: goto st151;
		case 152: goto st152;
		case 153: goto st153;
		case 195: goto st195;
		case 154: goto st154;
		case 155: goto st155;
		case 156: goto st156;
		case 157: goto st157;
		case 158: goto st158;
		case 159: goto st159;
		case 160: goto st160;
		case 196: goto st196;
		case 161: goto st161;
		case 162: goto st162;
		case 163: goto st163;
		case 164: goto st164;
		case 165: goto st165;
		case 166: goto st166;
		case 167: goto st167;
		case 168: goto st168;
		case 197: goto st197;
	default: break;
	}

	if ( ++p == pe )
		goto _test_eof;
_resume:
	switch ( cs )
	{
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	switch( (*p) ) {
		case 9: goto st1;
		case 32: goto st1;
		case 95: goto tr2;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2;
	} else
		goto tr2;
	goto st0;
st0:
cs = 0;
	goto _out;
tr2:
/* #line 187 "bel-parse-statement.rl" */
	{
            p--;
            term = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term_stack->top = -1;
            stack_push(term_stack, term);
            {stack[top++] = 2; goto st165;}
        }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
/* #line 341 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st3;
		case 32: goto st3;
	}
	goto st0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	switch( (*p) ) {
		case 9: goto st3;
		case 10: goto st0;
		case 32: goto st3;
	}
	goto tr4;
tr4:
/* #line 79 "bel-parse-statement.rl" */
	{
            ri = 0;
            memset(relationship, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 93 "bel-parse-statement.rl" */
	{
            relationship[ri++] = (*p);
        }
/* #line 107 "bel-parse-statement.rl" */
	{
            rel = bel_new_ast_node_token(BEL_TOKEN_REL);
            rel->token->left  = bel_new_ast_node_value(BEL_VALUE_REL, relationship);
            rel->token->right = NULL;

            object = bel_new_ast_node_token(BEL_TOKEN_OBJECT);
            object->token->left = rel;

            statement = stack_peek(statement_stack);
            statement->token->right = object;
        }
	goto st4;
tr5:
/* #line 93 "bel-parse-statement.rl" */
	{
            relationship[ri++] = (*p);
        }
/* #line 107 "bel-parse-statement.rl" */
	{
            rel = bel_new_ast_node_token(BEL_TOKEN_REL);
            rel->token->left  = bel_new_ast_node_value(BEL_VALUE_REL, relationship);
            rel->token->right = NULL;

            object = bel_new_ast_node_token(BEL_TOKEN_OBJECT);
            object->token->left = rel;

            statement = stack_peek(statement_stack);
            statement->token->right = object;
        }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
/* #line 402 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st5;
		case 10: goto st0;
		case 32: goto st5;
	}
	goto tr5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	switch( (*p) ) {
		case 9: goto st5;
		case 32: goto st5;
		case 40: goto tr7;
		case 95: goto tr8;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr8;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr8;
	} else
		goto tr8;
	goto st0;
tr7:
/* #line 214 "bel-parse-statement.rl" */
	{
            statement = bel_new_ast_node_token(BEL_TOKEN_STATEMENT);
            stack_push(statement_stack, statement);
            {stack[top++] = 6; goto st1;}
        }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
/* #line 440 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st6;
		case 32: goto st6;
		case 41: goto tr10;
	}
	goto st0;
tr10:
/* #line 220 "bel-parse-statement.rl" */
	{
            statement        = stack_pop(statement_stack);
            parent_statement = stack_peek(statement_stack);

            object = parent_statement->token->right;
            object->token->right = bel_copy_ast_node(statement);

            {cs = stack[--top];goto _again;}
        }
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
/* #line 463 "bel-parse-statement.c" */
	goto st0;
tr8:
/* #line 187 "bel-parse-statement.rl" */
	{
            p--;
            term = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term_stack->top = -1;
            stack_push(term_stack, term);
            {stack[top++] = 7; goto st165;}
        }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
/* #line 479 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st7;
		case 10: goto st169;
		case 13: goto st170;
		case 32: goto st7;
		case 41: goto tr14;
	}
	goto st0;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	if ( (*p) == 10 )
		goto st169;
	goto st0;
tr14:
/* #line 220 "bel-parse-statement.rl" */
	{
            statement        = stack_pop(statement_stack);
            parent_statement = stack_peek(statement_stack);

            object = parent_statement->token->right;
            object->token->right = bel_copy_ast_node(statement);

            {cs = stack[--top];goto _again;}
        }
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
/* #line 511 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 10: goto st169;
		case 13: goto st170;
	}
	goto st0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	switch( (*p) ) {
		case 9: goto st9;
		case 32: goto st9;
		case 34: goto tr17;
		case 40: goto tr18;
		case 58: goto tr20;
		case 95: goto tr19;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr19;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr19;
	} else
		goto tr19;
	goto tr15;
tr15:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st10;
tr21:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st10;
tr283:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st10;
tr286:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
/* #line 607 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st0;
		case 32: goto st0;
		case 40: goto tr22;
		case 58: goto tr23;
	}
	goto tr21;
tr22:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 11; goto st9;}
        }
	goto st11;
tr174:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 11; goto st9;}
        }
	goto st11;
tr285:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 11; goto st9;}
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
/* #line 722 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st16;
		case 32: goto st16;
		case 41: goto tr26;
		case 44: goto tr27;
		case 58: goto tr28;
	}
	goto tr24;
tr18:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st12;
tr24:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st12;
tr160:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
/* #line 763 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st0;
		case 32: goto st0;
		case 58: goto tr28;
	}
	goto tr24;
tr28:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
/* #line 792 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st13;
		case 32: goto st13;
		case 34: goto tr30;
		case 95: goto tr31;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr31;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr31;
	} else
		goto tr31;
	goto st0;
tr30:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st14;
tr32:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
/* #line 829 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 34: goto tr33;
		case 92: goto tr34;
	}
	goto tr32;
tr33:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
/* #line 845 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 41: goto tr36;
		case 44: goto tr37;
	}
	goto st0;
tr35:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
	goto st16;
tr75:
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 16; goto st9;}
        }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
/* #line 908 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st16;
		case 32: goto st16;
		case 41: goto tr38;
		case 44: goto st17;
	}
	goto st0;
tr36:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st171;
tr38:
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
/* #line 956 "bel-parse-statement.c" */
	goto st0;
tr37:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
/* #line 986 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st17;
		case 32: goto st17;
		case 34: goto tr41;
		case 40: goto tr42;
		case 44: goto tr20;
		case 58: goto tr20;
		case 95: goto tr43;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr43;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr43;
	} else
		goto tr43;
	goto tr40;
tr40:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st18;
tr44:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
/* #line 1039 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st0;
		case 32: goto st0;
		case 40: goto tr45;
		case 44: goto tr46;
		case 58: goto tr47;
	}
	goto tr44;
tr45:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 19; goto st9;}
        }
	goto st19;
tr82:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 19; goto st9;}
        }
	goto st19;
tr213:
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 19; goto st9;}
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st19;
tr217:
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 19; goto st9;}
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
/* #line 1186 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st16;
		case 32: goto st16;
		case 41: goto tr49;
		case 44: goto st17;
		case 58: goto tr50;
	}
	goto tr48;
tr42:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st20;
tr48:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
/* #line 1216 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st0;
		case 32: goto st0;
		case 44: goto st0;
		case 58: goto tr50;
	}
	goto tr48;
tr50:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
/* #line 1246 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st21;
		case 32: goto st21;
		case 34: goto tr52;
		case 95: goto tr31;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr31;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr31;
	} else
		goto tr31;
	goto st0;
tr52:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st22;
tr53:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
/* #line 1283 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 34: goto tr33;
		case 92: goto tr54;
	}
	goto tr53;
tr54:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
/* #line 1299 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 34: goto tr55;
		case 92: goto tr54;
	}
	goto tr53;
tr96:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st24;
tr55:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
/* #line 1326 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr56;
		case 32: goto tr56;
		case 34: goto tr33;
		case 41: goto tr57;
		case 44: goto tr58;
		case 92: goto tr54;
	}
	goto tr53;
tr79:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 25; goto st9;}
        }
	goto st25;
tr59:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st25;
tr56:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
	goto st25;
tr137:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st25;
tr223:
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 25; goto st9;}
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
/* #line 1464 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr59;
		case 32: goto tr59;
		case 34: goto tr33;
		case 41: goto tr60;
		case 44: goto tr61;
		case 92: goto tr54;
	}
	goto tr53;
tr60:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st172;
tr57:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st172;
tr138:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st172;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
/* #line 1555 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 34: goto tr33;
		case 92: goto tr54;
	}
	goto tr53;
tr61:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st26;
tr58:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
	goto st26;
tr139:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
/* #line 1627 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr61;
		case 32: goto tr61;
		case 34: goto tr62;
		case 40: goto tr63;
		case 44: goto tr64;
		case 58: goto tr64;
		case 92: goto tr66;
		case 95: goto tr65;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr65;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr65;
	} else
		goto tr65;
	goto tr41;
tr41:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st27;
tr67:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
/* #line 1681 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr68;
		case 40: goto tr69;
		case 44: goto tr70;
		case 58: goto tr71;
		case 92: goto tr72;
	}
	goto tr67;
tr68:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
/* #line 1706 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr45;
		case 41: goto tr73;
		case 44: goto tr74;
		case 58: goto tr47;
	}
	goto tr44;
tr73:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st173;
tr127:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st173;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
/* #line 1794 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st0;
		case 32: goto st0;
		case 40: goto tr45;
		case 44: goto tr46;
		case 58: goto tr47;
	}
	goto tr44;
tr20:
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st29;
tr46:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st29;
tr214:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
/* #line 1835 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st0;
		case 32: goto st0;
		case 40: goto tr75;
	}
	goto tr46;
tr47:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
/* #line 1868 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st21;
		case 32: goto st21;
		case 34: goto tr76;
		case 40: goto tr75;
		case 95: goto tr77;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr77;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr77;
	} else
		goto tr77;
	goto tr46;
tr70:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st31;
tr64:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st31;
tr76:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
/* #line 1929 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr78;
		case 40: goto tr79;
		case 92: goto tr80;
	}
	goto tr70;
tr78:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
/* #line 1952 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr75;
		case 41: goto tr81;
		case 44: goto tr74;
	}
	goto tr46;
tr81:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st174;
tr225:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st174;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
/* #line 2031 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st0;
		case 32: goto st0;
		case 40: goto tr75;
	}
	goto tr46;
tr74:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
/* #line 2070 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st17;
		case 32: goto st17;
		case 34: goto tr41;
		case 40: goto tr82;
		case 44: goto tr20;
		case 58: goto tr20;
		case 95: goto tr43;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr43;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr43;
	} else
		goto tr43;
	goto tr40;
tr43:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st34;
tr83:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
/* #line 2123 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr45;
		case 41: goto tr73;
		case 44: goto tr74;
		case 58: goto tr47;
		case 95: goto tr83;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr83;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr83;
	} else
		goto tr83;
	goto tr44;
tr80:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
/* #line 2156 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr84;
		case 40: goto tr79;
		case 92: goto tr80;
	}
	goto tr70;
tr84:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st36;
tr101:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
/* #line 2194 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr56;
		case 32: goto tr56;
		case 34: goto tr78;
		case 40: goto tr79;
		case 41: goto tr85;
		case 44: goto tr86;
		case 92: goto tr80;
	}
	goto tr70;
tr85:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st175;
tr155:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st175;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
/* #line 2283 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr78;
		case 40: goto tr79;
		case 92: goto tr80;
	}
	goto tr70;
tr86:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st37;
tr150:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
/* #line 2360 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr61;
		case 32: goto tr61;
		case 34: goto tr62;
		case 40: goto tr87;
		case 44: goto tr64;
		case 58: goto tr64;
		case 92: goto tr66;
		case 95: goto tr65;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr65;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr65;
	} else
		goto tr65;
	goto tr41;
tr62:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st38;
tr104:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
/* #line 2414 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr56;
		case 32: goto tr56;
		case 34: goto tr68;
		case 40: goto tr69;
		case 41: goto tr88;
		case 44: goto tr86;
		case 58: goto tr71;
		case 92: goto tr72;
	}
	goto tr67;
tr69:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 39; goto st9;}
        }
	goto st39;
tr87:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 39; goto st9;}
        }
	goto st39;
tr231:
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 39; goto st9;}
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st39;
tr237:
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 39; goto st9;}
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
/* #line 2564 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr59;
		case 32: goto tr59;
		case 34: goto tr90;
		case 41: goto tr91;
		case 44: goto tr61;
		case 58: goto tr92;
		case 92: goto tr93;
	}
	goto tr89;
tr63:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st40;
tr89:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
/* #line 2596 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr90;
		case 44: goto tr53;
		case 58: goto tr92;
		case 92: goto tr93;
	}
	goto tr89;
tr90:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
/* #line 2616 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 41: goto tr94;
		case 44: goto tr37;
		case 58: goto tr50;
	}
	goto tr48;
tr49:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st176;
tr94:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st176;
tr133:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
/* #line 2706 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st0;
		case 32: goto st0;
		case 44: goto st0;
		case 58: goto tr50;
	}
	goto tr48;
tr95:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st42;
tr92:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
/* #line 2746 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr95;
		case 32: goto tr95;
		case 34: goto tr96;
		case 92: goto tr54;
		case 95: goto tr97;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr53;
tr97:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st43;
tr98:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
/* #line 2784 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr56;
		case 32: goto tr56;
		case 34: goto tr33;
		case 41: goto tr57;
		case 44: goto tr58;
		case 92: goto tr54;
		case 95: goto tr98;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr98;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr98;
	} else
		goto tr98;
	goto tr53;
tr93:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
/* #line 2813 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr99;
		case 44: goto tr53;
		case 58: goto tr92;
		case 92: goto tr93;
	}
	goto tr89;
tr99:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
/* #line 2833 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr56;
		case 32: goto tr56;
		case 34: goto tr90;
		case 41: goto tr100;
		case 44: goto tr58;
		case 58: goto tr92;
		case 92: goto tr93;
	}
	goto tr89;
tr91:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st177;
tr100:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
/* #line 2892 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr90;
		case 44: goto tr53;
		case 58: goto tr92;
		case 92: goto tr93;
	}
	goto tr89;
tr88:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st178;
tr149:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
/* #line 2980 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr68;
		case 40: goto tr69;
		case 44: goto tr70;
		case 58: goto tr71;
		case 92: goto tr72;
	}
	goto tr67;
tr71:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
/* #line 3021 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr95;
		case 32: goto tr95;
		case 34: goto tr101;
		case 40: goto tr79;
		case 92: goto tr80;
		case 95: goto tr102;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr102;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr102;
	} else
		goto tr102;
	goto tr70;
tr103:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st47;
tr102:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
/* #line 3068 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr56;
		case 32: goto tr56;
		case 34: goto tr78;
		case 40: goto tr79;
		case 41: goto tr85;
		case 44: goto tr86;
		case 92: goto tr80;
		case 95: goto tr103;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr103;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr103;
	} else
		goto tr103;
	goto tr70;
tr66:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st48;
tr72:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
/* #line 3122 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr104;
		case 40: goto tr69;
		case 44: goto tr70;
		case 58: goto tr71;
		case 92: goto tr72;
	}
	goto tr67;
tr65:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st49;
tr105:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
/* #line 3167 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr56;
		case 32: goto tr56;
		case 34: goto tr68;
		case 40: goto tr69;
		case 41: goto tr88;
		case 44: goto tr86;
		case 58: goto tr71;
		case 92: goto tr72;
		case 95: goto tr105;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr105;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr105;
	} else
		goto tr105;
	goto tr67;
tr106:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st50;
tr77:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
/* #line 3217 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr75;
		case 41: goto tr81;
		case 44: goto tr74;
		case 95: goto tr106;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr106;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr106;
	} else
		goto tr106;
	goto tr46;
tr31:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st51;
tr107:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
/* #line 3256 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 41: goto tr36;
		case 44: goto tr37;
		case 95: goto tr107;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr107;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr107;
	} else
		goto tr107;
	goto st0;
tr34:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
/* #line 3283 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 34: goto tr108;
		case 92: goto tr34;
	}
	goto tr32;
tr185:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st53;
tr108:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
/* #line 3310 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr33;
		case 41: goto tr110;
		case 44: goto tr111;
		case 92: goto tr34;
	}
	goto tr32;
tr143:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 54; goto st9;}
        }
	goto st54;
tr112:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st54;
tr109:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
/* #line 3389 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr112;
		case 32: goto tr112;
		case 34: goto tr33;
		case 41: goto tr113;
		case 44: goto tr114;
		case 92: goto tr34;
	}
	goto tr32;
tr113:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st179;
tr110:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st179;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
/* #line 3447 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 34: goto tr33;
		case 92: goto tr34;
	}
	goto tr32;
tr114:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st55;
tr111:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
/* #line 3491 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr114;
		case 32: goto tr114;
		case 34: goto tr116;
		case 40: goto tr117;
		case 44: goto tr118;
		case 58: goto tr118;
		case 92: goto tr120;
		case 95: goto tr119;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr119;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr119;
	} else
		goto tr119;
	goto tr115;
tr121:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st56;
tr115:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
/* #line 3545 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr122;
		case 40: goto tr123;
		case 44: goto tr124;
		case 58: goto tr125;
		case 92: goto tr126;
	}
	goto tr121;
tr122:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
/* #line 3570 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr45;
		case 41: goto tr127;
		case 44: goto tr74;
		case 58: goto tr47;
	}
	goto tr44;
tr123:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 58; goto st9;}
        }
	goto st58;
tr148:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 58; goto st9;}
        }
	goto st58;
tr254:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 58; goto st9;}
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
/* #line 3687 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr112;
		case 32: goto tr112;
		case 34: goto tr129;
		case 41: goto tr130;
		case 44: goto tr114;
		case 58: goto tr131;
		case 92: goto tr132;
	}
	goto tr128;
tr128:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st59;
tr117:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
/* #line 3719 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr129;
		case 44: goto tr32;
		case 58: goto tr131;
		case 92: goto tr132;
	}
	goto tr128;
tr129:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
/* #line 3739 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 41: goto tr133;
		case 44: goto tr37;
		case 58: goto tr50;
	}
	goto tr48;
tr134:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st61;
tr131:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
/* #line 3780 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr134;
		case 32: goto tr134;
		case 34: goto tr135;
		case 92: goto tr34;
		case 95: goto tr136;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr136;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr136;
	} else
		goto tr136;
	goto tr32;
tr135:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
/* #line 3812 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr137;
		case 32: goto tr137;
		case 34: goto tr33;
		case 41: goto tr138;
		case 44: goto tr139;
		case 92: goto tr54;
	}
	goto tr53;
tr315:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st63;
tr140:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st63;
tr136:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
/* #line 3854 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr33;
		case 41: goto tr110;
		case 44: goto tr111;
		case 92: goto tr34;
		case 95: goto tr140;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr140;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr140;
	} else
		goto tr140;
	goto tr32;
tr132:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
/* #line 3883 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr141;
		case 44: goto tr32;
		case 58: goto tr131;
		case 92: goto tr132;
	}
	goto tr128;
tr141:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
/* #line 3903 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr129;
		case 41: goto tr142;
		case 44: goto tr111;
		case 58: goto tr131;
		case 92: goto tr132;
	}
	goto tr128;
tr130:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st180;
tr142:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st180;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
/* #line 3962 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr129;
		case 44: goto tr32;
		case 58: goto tr131;
		case 92: goto tr132;
	}
	goto tr128;
tr124:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st66;
tr118:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st66;
tr166:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
/* #line 4016 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr78;
		case 40: goto tr143;
		case 92: goto tr144;
	}
	goto tr124;
tr144:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
/* #line 4039 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr145;
		case 40: goto tr143;
		case 92: goto tr144;
	}
	goto tr124;
tr145:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st68;
tr199:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
/* #line 4077 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr78;
		case 40: goto tr143;
		case 41: goto tr146;
		case 44: goto tr147;
		case 92: goto tr144;
	}
	goto tr124;
tr146:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
/* #line 4129 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr78;
		case 40: goto tr143;
		case 92: goto tr144;
	}
	goto tr124;
tr147:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
/* #line 4174 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr114;
		case 32: goto tr114;
		case 34: goto tr116;
		case 40: goto tr148;
		case 44: goto tr118;
		case 58: goto tr118;
		case 92: goto tr120;
		case 95: goto tr119;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr119;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr119;
	} else
		goto tr119;
	goto tr115;
tr116:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
/* #line 4218 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr137;
		case 32: goto tr137;
		case 34: goto tr68;
		case 40: goto tr69;
		case 41: goto tr149;
		case 44: goto tr150;
		case 58: goto tr71;
		case 92: goto tr72;
	}
	goto tr67;
tr152:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st71;
tr119:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
/* #line 4264 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr122;
		case 40: goto tr123;
		case 41: goto tr151;
		case 44: goto tr147;
		case 58: goto tr125;
		case 92: goto tr126;
		case 95: goto tr152;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr152;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr152;
	} else
		goto tr152;
	goto tr121;
tr151:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
/* #line 4326 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr122;
		case 40: goto tr123;
		case 44: goto tr124;
		case 58: goto tr125;
		case 92: goto tr126;
	}
	goto tr121;
tr125:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
/* #line 4367 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr134;
		case 32: goto tr134;
		case 34: goto tr153;
		case 40: goto tr143;
		case 92: goto tr144;
		case 95: goto tr154;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr154;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr154;
	} else
		goto tr154;
	goto tr124;
tr153:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
/* #line 4404 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr137;
		case 32: goto tr137;
		case 34: goto tr78;
		case 40: goto tr79;
		case 41: goto tr155;
		case 44: goto tr150;
		case 92: goto tr80;
	}
	goto tr70;
tr156:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st74;
tr329:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st74;
tr154:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
/* #line 4459 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr78;
		case 40: goto tr143;
		case 41: goto tr146;
		case 44: goto tr147;
		case 92: goto tr144;
		case 95: goto tr156;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr156;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr156;
	} else
		goto tr156;
	goto tr124;
tr126:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st75;
tr120:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
/* #line 4513 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr157;
		case 40: goto tr123;
		case 44: goto tr124;
		case 58: goto tr125;
		case 92: goto tr126;
	}
	goto tr121;
tr157:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
/* #line 4538 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr122;
		case 40: goto tr123;
		case 41: goto tr151;
		case 44: goto tr147;
		case 58: goto tr125;
		case 92: goto tr126;
	}
	goto tr121;
tr26:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st183;
tr182:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
/* #line 4598 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st0;
		case 32: goto st0;
		case 58: goto tr28;
	}
	goto tr24;
tr27:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st77;
tr183:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
/* #line 4643 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st17;
		case 32: goto st17;
		case 34: goto tr159;
		case 40: goto tr160;
		case 44: goto tr161;
		case 58: goto tr163;
		case 95: goto tr162;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr162;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr162;
	} else
		goto tr162;
	goto tr158;
tr164:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st78;
tr161:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st78;
tr158:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st78;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
/* #line 4711 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st0;
		case 32: goto st0;
		case 40: goto tr22;
		case 58: goto tr165;
	}
	goto tr164;
tr165:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st79;
tr163:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st79;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
/* #line 4772 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st13;
		case 32: goto st13;
		case 34: goto tr166;
		case 40: goto tr75;
		case 95: goto tr77;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr77;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr77;
	} else
		goto tr77;
	goto tr46;
tr167:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st80;
tr193:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st80;
tr159:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st80;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
/* #line 4838 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr168;
		case 40: goto tr169;
		case 58: goto tr170;
		case 92: goto tr171;
	}
	goto tr167;
tr168:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
/* #line 4862 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr22;
		case 41: goto tr172;
		case 44: goto tr173;
		case 58: goto tr165;
	}
	goto tr164;
tr172:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
/* #line 4913 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st0;
		case 32: goto st0;
		case 40: goto tr22;
		case 58: goto tr165;
	}
	goto tr164;
tr173:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
/* #line 4957 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st17;
		case 32: goto st17;
		case 34: goto tr159;
		case 40: goto tr174;
		case 44: goto tr161;
		case 58: goto tr163;
		case 95: goto tr162;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr162;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr162;
	} else
		goto tr162;
	goto tr158;
tr175:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st83;
tr162:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
/* #line 5010 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr22;
		case 41: goto tr172;
		case 44: goto tr173;
		case 58: goto tr165;
		case 95: goto tr175;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr175;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr175;
	} else
		goto tr175;
	goto tr164;
tr169:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 84; goto st9;}
        }
	goto st84;
tr203:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 84; goto st9;}
        }
	goto st84;
tr302:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 84; goto st9;}
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
/* #line 5136 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr59;
		case 32: goto tr59;
		case 34: goto tr177;
		case 41: goto tr178;
		case 44: goto tr179;
		case 58: goto tr180;
		case 92: goto tr181;
	}
	goto tr176;
tr176:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st85;
tr192:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
/* #line 5168 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr177;
		case 58: goto tr180;
		case 92: goto tr181;
	}
	goto tr176;
tr177:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
/* #line 5187 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 41: goto tr182;
		case 44: goto tr183;
		case 58: goto tr28;
	}
	goto tr24;
tr184:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st87;
tr180:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st87;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
/* #line 5228 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr184;
		case 32: goto tr184;
		case 34: goto tr185;
		case 92: goto tr54;
		case 95: goto tr186;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr186;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr186;
	} else
		goto tr186;
	goto tr53;
tr186:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st88;
tr187:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st88;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
/* #line 5266 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr137;
		case 32: goto tr137;
		case 34: goto tr33;
		case 41: goto tr138;
		case 44: goto tr139;
		case 92: goto tr54;
		case 95: goto tr187;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr187;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr187;
	} else
		goto tr187;
	goto tr53;
tr181:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st89;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
/* #line 5295 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr188;
		case 58: goto tr180;
		case 92: goto tr181;
	}
	goto tr176;
tr188:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st90;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
/* #line 5314 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr56;
		case 32: goto tr56;
		case 34: goto tr177;
		case 41: goto tr189;
		case 44: goto tr190;
		case 58: goto tr180;
		case 92: goto tr181;
	}
	goto tr176;
tr178:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st185;
tr189:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
/* #line 5373 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr177;
		case 58: goto tr180;
		case 92: goto tr181;
	}
	goto tr176;
tr179:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st91;
tr190:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
	goto st91;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
/* #line 5420 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr61;
		case 32: goto tr61;
		case 34: goto tr191;
		case 40: goto tr192;
		case 44: goto tr193;
		case 58: goto tr195;
		case 92: goto tr196;
		case 95: goto tr194;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr194;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr194;
	} else
		goto tr194;
	goto tr159;
tr202:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st92;
tr191:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st92;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
/* #line 5474 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr56;
		case 32: goto tr56;
		case 34: goto tr168;
		case 40: goto tr169;
		case 41: goto tr197;
		case 44: goto tr198;
		case 58: goto tr170;
		case 92: goto tr171;
	}
	goto tr167;
tr197:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
/* #line 5527 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr168;
		case 40: goto tr169;
		case 58: goto tr170;
		case 92: goto tr171;
	}
	goto tr167;
tr170:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st93;
tr195:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st93;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
/* #line 5598 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr184;
		case 32: goto tr184;
		case 34: goto tr199;
		case 40: goto tr79;
		case 92: goto tr80;
		case 95: goto tr200;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr200;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr200;
	} else
		goto tr200;
	goto tr70;
tr201:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st94;
tr200:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st94;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
/* #line 5645 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr137;
		case 32: goto tr137;
		case 34: goto tr78;
		case 40: goto tr79;
		case 41: goto tr155;
		case 44: goto tr150;
		case 92: goto tr80;
		case 95: goto tr201;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr201;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr201;
	} else
		goto tr201;
	goto tr70;
tr171:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st95;
tr196:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st95;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
/* #line 5699 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr202;
		case 40: goto tr169;
		case 58: goto tr170;
		case 92: goto tr171;
	}
	goto tr167;
tr198:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
/* #line 5745 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr61;
		case 32: goto tr61;
		case 34: goto tr191;
		case 40: goto tr203;
		case 44: goto tr193;
		case 58: goto tr195;
		case 92: goto tr196;
		case 95: goto tr194;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr194;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr194;
	} else
		goto tr194;
	goto tr159;
tr204:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st97;
tr194:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
/* #line 5799 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr56;
		case 32: goto tr56;
		case 34: goto tr168;
		case 40: goto tr169;
		case 41: goto tr197;
		case 44: goto tr198;
		case 58: goto tr170;
		case 92: goto tr171;
		case 95: goto tr204;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr204;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr204;
	} else
		goto tr204;
	goto tr167;
tr23:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st98;
tr288:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
/* #line 5873 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st13;
		case 32: goto st13;
		case 34: goto tr205;
		case 40: goto tr75;
		case 95: goto tr206;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr206;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr206;
	} else
		goto tr206;
	goto tr46;
tr207:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st99;
tr205:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st99;
tr255:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
/* #line 5934 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr208;
		case 40: goto tr143;
		case 92: goto tr209;
	}
	goto tr207;
tr208:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
/* #line 5957 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr75;
		case 41: goto tr81;
		case 44: goto tr210;
	}
	goto tr46;
tr210:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st101;
tr226:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
/* #line 6026 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st17;
		case 32: goto st17;
		case 34: goto tr212;
		case 40: goto tr213;
		case 44: goto tr214;
		case 58: goto tr214;
		case 95: goto tr215;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr215;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr215;
	} else
		goto tr215;
	goto tr211;
tr211:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st102;
tr216:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
/* #line 6079 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st0;
		case 32: goto st0;
		case 40: goto tr217;
		case 44: goto tr46;
		case 58: goto tr218;
	}
	goto tr216;
tr218:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
/* #line 6114 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st21;
		case 32: goto st21;
		case 34: goto tr219;
		case 40: goto tr75;
		case 95: goto tr220;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr220;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr220;
	} else
		goto tr220;
	goto tr46;
tr221:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st104;
tr219:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st104;
tr232:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st104;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
/* #line 6175 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr222;
		case 40: goto tr223;
		case 92: goto tr224;
	}
	goto tr221;
tr222:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
/* #line 6198 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr75;
		case 41: goto tr225;
		case 44: goto tr226;
	}
	goto tr46;
tr224:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
/* #line 6221 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr227;
		case 40: goto tr223;
		case 92: goto tr224;
	}
	goto tr221;
tr227:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st107;
tr241:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
/* #line 6259 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr56;
		case 32: goto tr56;
		case 34: goto tr222;
		case 40: goto tr223;
		case 41: goto tr228;
		case 44: goto tr229;
		case 92: goto tr224;
	}
	goto tr221;
tr228:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st187;
tr265:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st187;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
/* #line 6348 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr222;
		case 40: goto tr223;
		case 92: goto tr224;
	}
	goto tr221;
tr229:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
	goto st108;
tr266:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
/* #line 6425 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr61;
		case 32: goto tr61;
		case 34: goto tr230;
		case 40: goto tr231;
		case 44: goto tr232;
		case 58: goto tr232;
		case 92: goto tr234;
		case 95: goto tr233;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr233;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr233;
	} else
		goto tr233;
	goto tr212;
tr212:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st109;
tr235:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
/* #line 6479 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr236;
		case 40: goto tr237;
		case 44: goto tr221;
		case 58: goto tr238;
		case 92: goto tr239;
	}
	goto tr235;
tr236:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
/* #line 6504 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr217;
		case 41: goto tr240;
		case 44: goto tr226;
		case 58: goto tr218;
	}
	goto tr216;
tr240:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st188;
tr262:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st188;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
/* #line 6592 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st0;
		case 32: goto st0;
		case 40: goto tr217;
		case 44: goto tr46;
		case 58: goto tr218;
	}
	goto tr216;
tr238:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
/* #line 6631 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr95;
		case 32: goto tr95;
		case 34: goto tr241;
		case 40: goto tr223;
		case 92: goto tr224;
		case 95: goto tr242;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr242;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr242;
	} else
		goto tr242;
	goto tr221;
tr243:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st112;
tr242:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
/* #line 6678 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr56;
		case 32: goto tr56;
		case 34: goto tr222;
		case 40: goto tr223;
		case 41: goto tr228;
		case 44: goto tr229;
		case 92: goto tr224;
		case 95: goto tr243;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr243;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr243;
	} else
		goto tr243;
	goto tr221;
tr234:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st113;
tr239:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
/* #line 6732 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr244;
		case 40: goto tr237;
		case 44: goto tr221;
		case 58: goto tr238;
		case 92: goto tr239;
	}
	goto tr235;
tr230:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st114;
tr244:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
/* #line 6777 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr56;
		case 32: goto tr56;
		case 34: goto tr236;
		case 40: goto tr237;
		case 41: goto tr245;
		case 44: goto tr229;
		case 58: goto tr238;
		case 92: goto tr239;
	}
	goto tr235;
tr245:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st189;
tr272:
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st189;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
/* #line 6867 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr236;
		case 40: goto tr237;
		case 44: goto tr221;
		case 58: goto tr238;
		case 92: goto tr239;
	}
	goto tr235;
tr233:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st115;
tr246:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
/* #line 6912 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr56;
		case 32: goto tr56;
		case 34: goto tr236;
		case 40: goto tr237;
		case 41: goto tr245;
		case 44: goto tr229;
		case 58: goto tr238;
		case 92: goto tr239;
		case 95: goto tr246;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr246;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr246;
	} else
		goto tr246;
	goto tr235;
tr247:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st116;
tr220:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
/* #line 6962 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr75;
		case 41: goto tr225;
		case 44: goto tr226;
		case 95: goto tr247;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr247;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr247;
	} else
		goto tr247;
	goto tr46;
tr215:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st117;
tr248:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
/* #line 7014 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr217;
		case 41: goto tr240;
		case 44: goto tr226;
		case 58: goto tr218;
		case 95: goto tr248;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr248;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr248;
	} else
		goto tr248;
	goto tr216;
tr209:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st118;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
/* #line 7047 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr249;
		case 40: goto tr143;
		case 92: goto tr209;
	}
	goto tr207;
tr249:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st119;
tr335:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
/* #line 7085 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr208;
		case 40: goto tr143;
		case 41: goto tr250;
		case 44: goto tr251;
		case 92: goto tr209;
	}
	goto tr207;
tr250:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st190;
tr267:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st190;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
/* #line 7174 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr208;
		case 40: goto tr143;
		case 92: goto tr209;
	}
	goto tr207;
tr251:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st120;
tr268:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
	goto st120;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
/* #line 7251 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr114;
		case 32: goto tr114;
		case 34: goto tr253;
		case 40: goto tr254;
		case 44: goto tr255;
		case 58: goto tr255;
		case 92: goto tr257;
		case 95: goto tr256;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr256;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr256;
	} else
		goto tr256;
	goto tr252;
tr258:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st121;
tr252:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st121;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
/* #line 7305 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr259;
		case 40: goto tr123;
		case 44: goto tr207;
		case 58: goto tr260;
		case 92: goto tr261;
	}
	goto tr258;
tr259:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
/* #line 7330 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr217;
		case 41: goto tr262;
		case 44: goto tr210;
		case 58: goto tr218;
	}
	goto tr216;
tr260:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
/* #line 7370 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr134;
		case 32: goto tr134;
		case 34: goto tr263;
		case 40: goto tr143;
		case 92: goto tr209;
		case 95: goto tr264;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr264;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr264;
	} else
		goto tr264;
	goto tr207;
tr263:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st124;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
/* #line 7407 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr137;
		case 32: goto tr137;
		case 34: goto tr222;
		case 40: goto tr223;
		case 41: goto tr265;
		case 44: goto tr266;
		case 92: goto tr224;
	}
	goto tr221;
tr269:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st125;
tr264:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st125;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
/* #line 7447 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr208;
		case 40: goto tr143;
		case 41: goto tr267;
		case 44: goto tr268;
		case 92: goto tr209;
		case 95: goto tr269;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr269;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr269;
	} else
		goto tr269;
	goto tr207;
tr261:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st126;
tr257:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st126;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
/* #line 7501 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr270;
		case 40: goto tr123;
		case 44: goto tr207;
		case 58: goto tr260;
		case 92: goto tr261;
	}
	goto tr258;
tr270:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st127;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
/* #line 7526 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr259;
		case 40: goto tr123;
		case 41: goto tr271;
		case 44: goto tr251;
		case 58: goto tr260;
		case 92: goto tr261;
	}
	goto tr258;
tr271:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st191;
tr273:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st191;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
/* #line 7616 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr259;
		case 40: goto tr123;
		case 44: goto tr207;
		case 58: goto tr260;
		case 92: goto tr261;
	}
	goto tr258;
tr253:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st128;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
/* #line 7651 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr137;
		case 32: goto tr137;
		case 34: goto tr236;
		case 40: goto tr237;
		case 41: goto tr272;
		case 44: goto tr266;
		case 58: goto tr238;
		case 92: goto tr239;
	}
	goto tr235;
tr274:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st129;
tr256:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st129;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
/* #line 7697 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr259;
		case 40: goto tr123;
		case 41: goto tr273;
		case 44: goto tr268;
		case 58: goto tr260;
		case 92: goto tr261;
		case 95: goto tr274;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr274;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr274;
	} else
		goto tr274;
	goto tr258;
tr275:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st130;
tr206:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
/* #line 7747 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr75;
		case 41: goto tr81;
		case 44: goto tr210;
		case 95: goto tr275;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr275;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr275;
	} else
		goto tr275;
	goto tr46;
tr17:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st131;
tr276:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st131;
tr341:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st131;
tr344:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
/* #line 7834 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr277;
		case 40: goto tr278;
		case 58: goto tr279;
		case 92: goto tr280;
	}
	goto tr276;
tr277:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
/* #line 7858 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr22;
		case 41: goto tr281;
		case 44: goto tr282;
		case 58: goto tr23;
	}
	goto tr21;
tr281:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st192;
tr293:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st192;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
/* #line 7946 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st0;
		case 32: goto st0;
		case 40: goto tr22;
		case 58: goto tr23;
	}
	goto tr21;
tr282:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st133;
tr294:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
	goto st133;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
/* #line 8022 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st17;
		case 32: goto st17;
		case 34: goto tr284;
		case 40: goto tr285;
		case 44: goto tr286;
		case 58: goto tr288;
		case 95: goto tr287;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr287;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr287;
	} else
		goto tr287;
	goto tr283;
tr289:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st134;
tr284:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st134;
tr303:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
/* #line 8090 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr290;
		case 40: goto tr169;
		case 58: goto tr291;
		case 92: goto tr292;
	}
	goto tr289;
tr290:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
/* #line 8114 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr22;
		case 41: goto tr293;
		case 44: goto tr294;
		case 58: goto tr23;
	}
	goto tr21;
tr291:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st136;
tr305:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st136;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
/* #line 8185 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr184;
		case 32: goto tr184;
		case 34: goto tr295;
		case 40: goto tr223;
		case 92: goto tr224;
		case 95: goto tr296;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr296;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr296;
	} else
		goto tr296;
	goto tr221;
tr295:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st137;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
/* #line 8222 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr208;
		case 40: goto tr143;
		case 41: goto tr267;
		case 44: goto tr268;
		case 92: goto tr209;
	}
	goto tr207;
tr297:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st138;
tr296:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st138;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
/* #line 8262 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr137;
		case 32: goto tr137;
		case 34: goto tr222;
		case 40: goto tr223;
		case 41: goto tr265;
		case 44: goto tr266;
		case 92: goto tr224;
		case 95: goto tr297;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr297;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr297;
	} else
		goto tr297;
	goto tr221;
tr292:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st139;
tr306:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st139;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
/* #line 8316 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr298;
		case 40: goto tr169;
		case 58: goto tr291;
		case 92: goto tr292;
	}
	goto tr289;
tr298:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st140;
tr301:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
/* #line 8360 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr56;
		case 32: goto tr56;
		case 34: goto tr290;
		case 40: goto tr169;
		case 41: goto tr299;
		case 44: goto tr300;
		case 58: goto tr291;
		case 92: goto tr292;
	}
	goto tr289;
tr348:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st193;
tr299:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st193;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
/* #line 8450 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr53;
		case 32: goto tr53;
		case 34: goto tr290;
		case 40: goto tr169;
		case 58: goto tr291;
		case 92: goto tr292;
	}
	goto tr289;
tr349:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st141;
tr300:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
/* #line 8528 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr61;
		case 32: goto tr61;
		case 34: goto tr301;
		case 40: goto tr302;
		case 44: goto tr303;
		case 58: goto tr305;
		case 92: goto tr306;
		case 95: goto tr304;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr304;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr304;
	} else
		goto tr304;
	goto tr284;
tr307:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st142;
tr304:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
/* #line 8582 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr56;
		case 32: goto tr56;
		case 34: goto tr290;
		case 40: goto tr169;
		case 41: goto tr299;
		case 44: goto tr300;
		case 58: goto tr291;
		case 92: goto tr292;
		case 95: goto tr307;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr307;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr307;
	} else
		goto tr307;
	goto tr289;
tr308:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st143;
tr287:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
/* #line 8637 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr22;
		case 41: goto tr293;
		case 44: goto tr294;
		case 58: goto tr23;
		case 95: goto tr308;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr308;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr308;
	} else
		goto tr308;
	goto tr21;
tr278:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 144; goto st9;}
        }
	goto st144;
tr333:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 144; goto st9;}
        }
	goto st144;
tr343:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 119 "bel-parse-statement.rl" */
	{
            bel_ast_node* term_top = stack_peek(term_stack);

            // find ARG leaf
            arg = term_top->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            // create new nested term
            term               = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
            // set head term, left: new nested term, right: next arg
            arg->token->left   = term;
            arg->token->right  = bel_new_ast_node_token(BEL_TOKEN_ARG);

            // push new nested term onto stack
            stack_push(term_stack, term);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 144; goto st9;}
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st144;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
/* #line 8763 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr112;
		case 32: goto tr112;
		case 34: goto tr177;
		case 41: goto tr310;
		case 44: goto tr311;
		case 58: goto tr312;
		case 92: goto tr313;
	}
	goto tr309;
tr309:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st145;
tr321:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st145;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
/* #line 8795 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr177;
		case 58: goto tr312;
		case 92: goto tr313;
	}
	goto tr309;
tr314:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st146;
tr312:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st146;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
/* #line 8836 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr314;
		case 32: goto tr314;
		case 34: goto tr185;
		case 92: goto tr34;
		case 95: goto tr315;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr315;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr315;
	} else
		goto tr315;
	goto tr32;
tr313:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
/* #line 8863 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr316;
		case 58: goto tr312;
		case 92: goto tr313;
	}
	goto tr309;
tr316:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
/* #line 8882 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr177;
		case 41: goto tr317;
		case 44: goto tr318;
		case 58: goto tr312;
		case 92: goto tr313;
	}
	goto tr309;
tr310:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st194;
tr317:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st194;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
/* #line 8941 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr177;
		case 58: goto tr312;
		case 92: goto tr313;
	}
	goto tr309;
tr311:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
	goto st149;
tr318:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
/* #line 8988 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr114;
		case 32: goto tr114;
		case 34: goto tr320;
		case 40: goto tr321;
		case 44: goto tr322;
		case 58: goto tr324;
		case 92: goto tr325;
		case 95: goto tr323;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr323;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr323;
	} else
		goto tr323;
	goto tr319;
tr326:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st150;
tr322:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st150;
tr319:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
/* #line 9057 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr168;
		case 40: goto tr278;
		case 58: goto tr327;
		case 92: goto tr328;
	}
	goto tr326;
tr327:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st151;
tr324:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st151;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
/* #line 9128 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr314;
		case 32: goto tr314;
		case 34: goto tr199;
		case 40: goto tr143;
		case 92: goto tr144;
		case 95: goto tr329;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr329;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr329;
	} else
		goto tr329;
	goto tr124;
tr328:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st152;
tr325:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
/* #line 9180 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr330;
		case 40: goto tr278;
		case 58: goto tr327;
		case 92: goto tr328;
	}
	goto tr326;
tr330:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st153;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
/* #line 9204 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr168;
		case 40: goto tr278;
		case 41: goto tr331;
		case 44: goto tr332;
		case 58: goto tr327;
		case 92: goto tr328;
	}
	goto tr326;
tr331:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st195;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
/* #line 9257 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr168;
		case 40: goto tr278;
		case 58: goto tr327;
		case 92: goto tr328;
	}
	goto tr326;
tr332:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st154;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
/* #line 9303 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr114;
		case 32: goto tr114;
		case 34: goto tr320;
		case 40: goto tr333;
		case 44: goto tr322;
		case 58: goto tr324;
		case 92: goto tr325;
		case 95: goto tr323;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr323;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr323;
	} else
		goto tr323;
	goto tr319;
tr320:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st155;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
/* #line 9347 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr137;
		case 32: goto tr137;
		case 34: goto tr168;
		case 40: goto tr169;
		case 41: goto tr197;
		case 44: goto tr198;
		case 58: goto tr170;
		case 92: goto tr171;
	}
	goto tr167;
tr334:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st156;
tr323:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
/* #line 9393 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr168;
		case 40: goto tr278;
		case 41: goto tr331;
		case 44: goto tr332;
		case 58: goto tr327;
		case 92: goto tr328;
		case 95: goto tr334;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr334;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr334;
	} else
		goto tr334;
	goto tr326;
tr279:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st157;
tr346:
/* #line 140 "bel-parse-statement.rl" */
	{
            term = stack_peek(term_stack);

            // find ARG leaf
            arg = term->token->right;
            while(arg->token->right != NULL) {
                arg = arg->token->right;
            }

            current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
            current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, value);
            current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, NULL);
            arg->token->left         = current_nv;
            arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
/* #line 9475 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr314;
		case 32: goto tr314;
		case 34: goto tr335;
		case 40: goto tr143;
		case 92: goto tr209;
		case 95: goto tr336;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr336;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr336;
	} else
		goto tr336;
	goto tr207;
tr337:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st158;
tr336:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
/* #line 9522 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr208;
		case 40: goto tr143;
		case 41: goto tr250;
		case 44: goto tr251;
		case 92: goto tr209;
		case 95: goto tr337;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr337;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr337;
	} else
		goto tr337;
	goto tr207;
tr280:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st159;
tr347:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st159;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
/* #line 9576 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr338;
		case 40: goto tr278;
		case 58: goto tr279;
		case 92: goto tr280;
	}
	goto tr276;
tr338:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
/* #line 9600 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr277;
		case 40: goto tr278;
		case 41: goto tr339;
		case 44: goto tr340;
		case 58: goto tr279;
		case 92: goto tr280;
	}
	goto tr276;
tr339:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st196;
tr350:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 182 "bel-parse-statement.rl" */
	{
            term = stack_pop(term_stack);
            {cs = stack[--top];goto _again;}
        }
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
/* #line 9690 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr32;
		case 32: goto tr32;
		case 34: goto tr277;
		case 40: goto tr278;
		case 58: goto tr279;
		case 92: goto tr280;
	}
	goto tr276;
tr340:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st161;
tr351:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 156 "bel-parse-statement.rl" */
	{
            if (!current_nv) {
                term = stack_peek(term_stack);

                // find ARG leaf
                arg = term->token->right;
                while(arg->token->right != NULL) {
                    arg = arg->token->right;
                }

                current_nv               = bel_new_ast_node_token(BEL_TOKEN_NV);
                current_nv->token->left  = bel_new_ast_node_value(BEL_VALUE_PFX, NULL);
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
                arg->token->left         = current_nv;
                arg->token->right        = bel_new_ast_node_token(BEL_TOKEN_ARG);
            } else {
                current_nv->token->right = bel_new_ast_node_value(BEL_VALUE_VAL, value);
            }

            current_nv = 0;
        }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
/* #line 9768 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr114;
		case 32: goto tr114;
		case 34: goto tr342;
		case 40: goto tr343;
		case 44: goto tr344;
		case 58: goto tr346;
		case 92: goto tr347;
		case 95: goto tr345;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr345;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr345;
	} else
		goto tr345;
	goto tr341;
tr342:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st162;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
/* #line 9812 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr137;
		case 32: goto tr137;
		case 34: goto tr290;
		case 40: goto tr169;
		case 41: goto tr348;
		case 44: goto tr349;
		case 58: goto tr291;
		case 92: goto tr292;
	}
	goto tr289;
tr352:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st163;
tr345:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
	goto st163;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
/* #line 9858 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr109;
		case 32: goto tr109;
		case 34: goto tr277;
		case 40: goto tr278;
		case 41: goto tr350;
		case 44: goto tr351;
		case 58: goto tr279;
		case 92: goto tr280;
		case 95: goto tr352;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr352;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr352;
	} else
		goto tr352;
	goto tr276;
tr19:
/* #line 84 "bel-parse-statement.rl" */
	{
            vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st164;
tr353:
/* #line 97 "bel-parse-statement.rl" */
	{
            value[vi++] = (*p);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
/* #line 9913 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr35;
		case 32: goto tr35;
		case 40: goto tr22;
		case 41: goto tr281;
		case 44: goto tr282;
		case 58: goto tr23;
		case 95: goto tr353;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr353;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr353;
	} else
		goto tr353;
	goto tr21;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	switch( (*p) ) {
		case 9: goto st0;
		case 32: goto st0;
		case 40: goto st0;
	}
	goto tr354;
tr354:
/* #line 74 "bel-parse-statement.rl" */
	{
            fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st166;
tr355:
/* #line 89 "bel-parse-statement.rl" */
	{
            function[fi++] = (*p);
        }
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
/* #line 9963 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto tr356;
		case 32: goto tr356;
		case 40: goto tr357;
	}
	goto tr355;
tr356:
/* #line 101 "bel-parse-statement.rl" */
	{
            term               = stack_peek(term_stack);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
/* #line 9982 "bel-parse-statement.c" */
	switch( (*p) ) {
		case 9: goto st167;
		case 32: goto st167;
		case 40: goto tr359;
	}
	goto st0;
tr357:
/* #line 101 "bel-parse-statement.rl" */
	{
            term               = stack_peek(term_stack);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 168; goto st9;}
        }
	goto st168;
tr359:
/* #line 178 "bel-parse-statement.rl" */
	{
            {stack[top++] = 168; goto st9;}
        }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
/* #line 10011 "bel-parse-statement.c" */
	goto tr360;
tr360:
/* #line 242 "bel-parse-statement.rl" */
	{ p--; }
/* #line 195 "bel-parse-statement.rl" */
	{
            statement = stack_peek(statement_stack);
            if (statement->token->left == NULL) {
                // assign term as subject
                subject = bel_new_ast_node_token(BEL_TOKEN_SUBJECT);
                subject->token->left  = bel_copy_ast_node(term);
                subject->token->right = NULL;
                statement->token->left = subject;
            } else {
                // assign term as object; object is already available
                // after REL action
                object = statement->token->right;
                object->token->right = bel_copy_ast_node(term);
                statement->token->right = object;
            }

            {cs = stack[--top];goto _again;}
        }
	goto st197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
/* #line 10040 "bel-parse-statement.c" */
	goto st0;
	}
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof172: cs = 172; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof173: cs = 173; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof174: cs = 174; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof177: cs = 177; goto _test_eof; 
	_test_eof178: cs = 178; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof179: cs = 179; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof180: cs = 180; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof181: cs = 181; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof182: cs = 182; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof183: cs = 183; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof184: cs = 184; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof185: cs = 185; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof186: cs = 186; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof187: cs = 187; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof188: cs = 188; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof189: cs = 189; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof190: cs = 190; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof151: cs = 151; goto _test_eof; 
	_test_eof152: cs = 152; goto _test_eof; 
	_test_eof153: cs = 153; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof154: cs = 154; goto _test_eof; 
	_test_eof155: cs = 155; goto _test_eof; 
	_test_eof156: cs = 156; goto _test_eof; 
	_test_eof157: cs = 157; goto _test_eof; 
	_test_eof158: cs = 158; goto _test_eof; 
	_test_eof159: cs = 159; goto _test_eof; 
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof166: cs = 166; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof197: cs = 197; goto _test_eof; 

	_test_eof: {}
	_out: {}
	}

/* #line 283 "bel-parse-statement.rl" */


    // free allocations
    bel_free_ast_node(term);
    if (term_stack) {
        stack_destroy(term_stack);
    }
    if (statement_stack) {
        stack_destroy(statement_stack);
    }
    free(stack);
    free(function);
    free(relationship);
    free(value);

    return ast;
};
// vim: ft=c sw=4 ts=4 sts=4 expandtab

