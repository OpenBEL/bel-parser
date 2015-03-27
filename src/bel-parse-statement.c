#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libbel.h"
#include "bel-ast.h"
#include "bel-node-stack.h"

static const int  set_start  = 1;
static const int  set_first_final  = 41;
static const int  set_error  = 0;
static const int  set_en_arguments  = 9;
static const int  set_en_term  = 38;
static const int  set_en_statement  = 1;
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
    /* subject           = bel_new_ast_node_token(BEL_TOKEN_SUBJECT); */
    /* object            = bel_new_ast_node_token(BEL_TOKEN_OBJECT); */
    term              = NULL;
    ast               = bel_new_ast();
    ast->root         = statement;

    stack_push(statement_stack, statement);

    memset(function, '\0', BEL_VALUE_CHAR_LEN);
    memset(relationship, '\0', BEL_VALUE_CHAR_LEN);
    memset(value, '\0', BEL_VALUE_CHAR_LEN);

    
	{
	cs = set_start;
top = 0;
}

	{
	if ( p == pe  )
	goto _test_eof;
	
goto _resume;

_again:
	switch ( cs  ) {
	case 1:
goto st1;
		case 0:
goto st0;
		case 2:
goto st2;
		case 3:
goto st3;
		case 4:
goto st4;
		case 5:
goto st5;
		case 6:
goto st6;
		case 41:
goto st41;
		case 7:
goto st7;
		case 42:
goto st42;
		case 8:
goto st8;
		case 9:
goto st9;
		case 10:
goto st10;
		case 11:
goto st11;
		case 12:
goto st12;
		case 13:
goto st13;
		case 14:
goto st14;
		case 15:
goto st15;
		case 16:
goto st16;
		case 17:
goto st17;
		case 18:
goto st18;
		case 19:
goto st19;
		case 20:
goto st20;
		case 43:
goto st43;
		case 21:
goto st21;
		case 22:
goto st22;
		case 23:
goto st23;
		case 24:
goto st24;
		case 44:
goto st44;
		case 25:
goto st25;
		case 26:
goto st26;
		case 27:
goto st27;
		case 28:
goto st28;
		case 29:
goto st29;
		case 30:
goto st30;
		case 31:
goto st31;
		case 32:
goto st32;
		case 33:
goto st33;
		case 45:
goto st45;
		case 34:
goto st34;
		case 35:
goto st35;
		case 36:
goto st36;
		case 37:
goto st37;
		case 38:
goto st38;
		case 39:
goto st39;
		case 40:
goto st40;
		case 46:
goto st46;
	
}
p+= 1;
if ( p == pe  )
	goto _test_eof;

_resume:
	switch ( cs  ) {
	case 1:
goto st_case_1;
	case 0:
goto st_case_0;
	case 2:
goto st_case_2;
	case 3:
goto st_case_3;
	case 4:
goto st_case_4;
	case 5:
goto st_case_5;
	case 6:
goto st_case_6;
	case 41:
goto st_case_41;
	case 7:
goto st_case_7;
	case 42:
goto st_case_42;
	case 8:
goto st_case_8;
	case 9:
goto st_case_9;
	case 10:
goto st_case_10;
	case 11:
goto st_case_11;
	case 12:
goto st_case_12;
	case 13:
goto st_case_13;
	case 14:
goto st_case_14;
	case 15:
goto st_case_15;
	case 16:
goto st_case_16;
	case 17:
goto st_case_17;
	case 18:
goto st_case_18;
	case 19:
goto st_case_19;
	case 20:
goto st_case_20;
	case 43:
goto st_case_43;
	case 21:
goto st_case_21;
	case 22:
goto st_case_22;
	case 23:
goto st_case_23;
	case 24:
goto st_case_24;
	case 44:
goto st_case_44;
	case 25:
goto st_case_25;
	case 26:
goto st_case_26;
	case 27:
goto st_case_27;
	case 28:
goto st_case_28;
	case 29:
goto st_case_29;
	case 30:
goto st_case_30;
	case 31:
goto st_case_31;
	case 32:
goto st_case_32;
	case 33:
goto st_case_33;
	case 45:
goto st_case_45;
	case 34:
goto st_case_34;
	case 35:
goto st_case_35;
	case 36:
goto st_case_36;
	case 37:
goto st_case_37;
	case 38:
goto st_case_38;
	case 39:
goto st_case_39;
	case 40:
goto st_case_40;
	case 46:
goto st_case_46;
	
}
goto st_out;
st1:
	p+= 1;
if ( p == pe  )
	goto _test_eof1;

st_case_1:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto st1;
	}
		 case 32:
{
goto st1;
	}
		 case 95:
{
goto ctr2;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr2;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr2;
		}
	
} 
else
	{
		goto ctr2;
	}

{
	goto st0;
}
st_case_0:
st0:
cs = 0;
goto _out;
ctr2:
	{{ p = p - 1;
}
            term = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term_stack->top = -1;
            stack_push(term_stack, term);
            {stack[top] = 2;
top+= 1;
goto st38;}}


	goto st2;
st2:
	p+= 1;
if ( p == pe  )
	goto _test_eof2;

st_case_2:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto st3;
	}
		 case 32:
{
goto st3;
	}
	
}
{
	goto st0;
}
st3:
	p+= 1;
if ( p == pe  )
	goto _test_eof3;

st_case_3:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto st3;
	}
		 case 10:
{
goto st0;
	}
		 case 32:
{
goto st3;
	}
	
}
if ( ( (*( p  ))
) > 31  )
	{
		if ( 33 <= ( (*( p  ))
)  )
	{
			goto ctr4;
		}
	
} 
else if ( ( (*( p  ))
) >= 11  )
	{
		goto ctr4;
	}

{
	goto ctr4;
}
ctr4:
	{ri = 0;
            memset(relationship, '\0', BEL_VALUE_CHAR_LEN);
        }
{relationship[ri++] = (( (*( p  ))
));
        }
{rel = bel_new_ast_node_token(BEL_TOKEN_REL);
            rel->token->left  = bel_new_ast_node_value(BEL_VALUE_REL, relationship);
            rel->token->right = NULL;

            object = bel_new_ast_node_token(BEL_TOKEN_OBJECT);
            object->token->left = rel;

            statement = stack_peek(statement_stack);
            statement->token->right = object;
        }


	goto st4;
ctr5:
	{relationship[ri++] = (( (*( p  ))
));
        }
{rel = bel_new_ast_node_token(BEL_TOKEN_REL);
            rel->token->left  = bel_new_ast_node_value(BEL_VALUE_REL, relationship);
            rel->token->right = NULL;

            object = bel_new_ast_node_token(BEL_TOKEN_OBJECT);
            object->token->left = rel;

            statement = stack_peek(statement_stack);
            statement->token->right = object;
        }


	goto st4;
st4:
	p+= 1;
if ( p == pe  )
	goto _test_eof4;

st_case_4:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto st5;
	}
		 case 10:
{
goto st0;
	}
		 case 32:
{
goto st5;
	}
	
}
if ( ( (*( p  ))
) > 31  )
	{
		if ( 33 <= ( (*( p  ))
)  )
	{
			goto ctr5;
		}
	
} 
else if ( ( (*( p  ))
) >= 11  )
	{
		goto ctr5;
	}

{
	goto ctr5;
}
st5:
	p+= 1;
if ( p == pe  )
	goto _test_eof5;

st_case_5:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto st5;
	}
		 case 32:
{
goto st5;
	}
		 case 40:
{
goto ctr7;
	}
		 case 95:
{
goto ctr8;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr8;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr8;
		}
	
} 
else
	{
		goto ctr8;
	}

{
	goto st0;
}
ctr7:
	{statement = bel_new_ast_node_token(BEL_TOKEN_STATEMENT);
            stack_push(statement_stack, statement);
            {stack[top] = 6;
top+= 1;
goto st1;}}


	goto st6;
st6:
	p+= 1;
if ( p == pe  )
	goto _test_eof6;

st_case_6:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto st6;
	}
		 case 32:
{
goto st6;
	}
		 case 41:
{
goto ctr10;
	}
	
}
{
	goto st0;
}
ctr10:
	{statement        = stack_pop(statement_stack);
            parent_statement = stack_peek(statement_stack);

            object = parent_statement->token->right;
            object->token->right = bel_copy_ast_node(statement);

            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st41;
st41:
	p+= 1;
if ( p == pe  )
	goto _test_eof41;

st_case_41:
{
	goto st0;
}
ctr8:
	{{ p = p - 1;
}
            term = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term_stack->top = -1;
            stack_push(term_stack, term);
            {stack[top] = 7;
top+= 1;
goto st38;}}


	goto st7;
st7:
	p+= 1;
if ( p == pe  )
	goto _test_eof7;

st_case_7:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto st7;
	}
		 case 10:
{
goto st41;
	}
		 case 13:
{
goto st42;
	}
		 case 32:
{
goto st7;
	}
		 case 41:
{
goto ctr14;
	}
	
}
{
	goto st0;
}
st42:
	p+= 1;
if ( p == pe  )
	goto _test_eof42;

st_case_42:
	if ( ( (*( p  ))
) == 10  )
	{
		goto st41;
	}

{
	goto st0;
}
ctr14:
	{statement        = stack_pop(statement_stack);
            parent_statement = stack_peek(statement_stack);

            object = parent_statement->token->right;
            object->token->right = bel_copy_ast_node(statement);

            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st8;
st8:
	p+= 1;
if ( p == pe  )
	goto _test_eof8;

st_case_8:
	switch ( ( (*( p  ))
)  ) {
	case 10:
{
goto st41;
	}
		 case 13:
{
goto st42;
	}
	
}
{
	goto st0;
}
st9:
	p+= 1;
if ( p == pe  )
	goto _test_eof9;

st_case_9:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr15;
	}
		 case 95:
{
goto ctr16;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr16;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr16;
		}
	
} 
else
	{
		goto ctr16;
	}

{
	goto st0;
}
ctr15:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }


	goto st10;
ctr17:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st10;
st10:
	p+= 1;
if ( p == pe  )
	goto _test_eof10;

st_case_10:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr18;
	}
		 case 92:
{
goto ctr19;
	}
	
}
if ( ( (*( p  ))
) > 91  )
	{
		if ( 93 <= ( (*( p  ))
)  )
	{
			goto ctr17;
		}
	
} 
else if ( ( (*( p  ))
) >= 35  )
	{
		goto ctr17;
	}

{
	goto ctr17;
}
ctr18:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st11;
st11:
	p+= 1;
if ( p == pe  )
	goto _test_eof11;

st_case_11:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr20;
	}
		 case 32:
{
goto ctr20;
	}
		 case 41:
{
goto ctr21;
	}
		 case 44:
{
goto ctr22;
	}
	
}
{
	goto st0;
}
ctr20:
	{if (!current_nv) {
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


	goto st12;
st12:
	p+= 1;
if ( p == pe  )
	goto _test_eof12;

st_case_12:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto st12;
	}
		 case 32:
{
goto st12;
	}
		 case 44:
{
goto st13;
	}
	
}
{
	goto st0;
}
ctr22:
	{if (!current_nv) {
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


	goto st13;
st13:
	p+= 1;
if ( p == pe  )
	goto _test_eof13;

st_case_13:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto st13;
	}
		 case 32:
{
goto st13;
	}
		 case 34:
{
goto ctr25;
	}
		 case 95:
{
goto ctr26;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr26;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr26;
		}
	
} 
else
	{
		goto ctr26;
	}

{
	goto st0;
}
ctr25:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }


	goto st14;
ctr27:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st14;
st14:
	p+= 1;
if ( p == pe  )
	goto _test_eof14;

st_case_14:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr18;
	}
		 case 92:
{
goto ctr28;
	}
	
}
if ( ( (*( p  ))
) > 91  )
	{
		if ( 93 <= ( (*( p  ))
)  )
	{
			goto ctr27;
		}
	
} 
else if ( ( (*( p  ))
) >= 35  )
	{
		goto ctr27;
	}

{
	goto ctr27;
}
ctr28:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st15;
st15:
	p+= 1;
if ( p == pe  )
	goto _test_eof15;

st_case_15:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr29;
	}
		 case 92:
{
goto ctr28;
	}
	
}
if ( ( (*( p  ))
) > 91  )
	{
		if ( 93 <= ( (*( p  ))
)  )
	{
			goto ctr27;
		}
	
} 
else if ( ( (*( p  ))
) >= 35  )
	{
		goto ctr27;
	}

{
	goto ctr27;
}
ctr35:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }


	goto st16;
ctr29:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st16;
st16:
	p+= 1;
if ( p == pe  )
	goto _test_eof16;

st_case_16:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr30;
	}
		 case 32:
{
goto ctr30;
	}
		 case 33:
{
goto ctr27;
	}
		 case 34:
{
goto ctr18;
	}
		 case 41:
{
goto ctr31;
	}
		 case 44:
{
goto ctr32;
	}
		 case 92:
{
goto ctr28;
	}
	
}
if ( ( (*( p  ))
) < 42  )
	{
		if ( ( (*( p  ))
) > 31  )
	{
			if ( 35 <= ( (*( p  ))
) && ( (*( p  ))
) <= 40  )
	{
				goto ctr27;
			}
		
} 
else if ( ( (*( p  ))
) >= 10  )
	{
			goto ctr27;
		}
	
} 
else if ( ( (*( p  ))
) > 43  )
	{
		if ( ( (*( p  ))
) > 91  )
	{
			if ( 93 <= ( (*( p  ))
)  )
	{
				goto ctr27;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr27;
		}
	
} 
else
	{
		goto ctr27;
	}

{
	goto ctr27;
}
ctr33:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st17;
ctr30:
	{value[vi++] = (( (*( p  ))
));
        }
{if (!current_nv) {
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
ctr57:
	{if (!current_nv) {
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
{value[vi++] = (( (*( p  ))
));
        }


	goto st17;
st17:
	p+= 1;
if ( p == pe  )
	goto _test_eof17;

st_case_17:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr33;
	}
		 case 32:
{
goto ctr33;
	}
		 case 33:
{
goto ctr27;
	}
		 case 34:
{
goto ctr18;
	}
		 case 44:
{
goto ctr34;
	}
		 case 92:
{
goto ctr28;
	}
	
}
if ( ( (*( p  ))
) < 35  )
	{
		if ( 10 <= ( (*( p  ))
) && ( (*( p  ))
) <= 31  )
	{
			goto ctr27;
		}
	
} 
else if ( ( (*( p  ))
) > 43  )
	{
		if ( ( (*( p  ))
) > 91  )
	{
			if ( 93 <= ( (*( p  ))
)  )
	{
				goto ctr27;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr27;
		}
	
} 
else
	{
		goto ctr27;
	}

{
	goto ctr27;
}
ctr34:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st18;
ctr32:
	{value[vi++] = (( (*( p  ))
));
        }
{if (!current_nv) {
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


	goto st18;
ctr59:
	{if (!current_nv) {
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
{value[vi++] = (( (*( p  ))
));
        }


	goto st18;
st18:
	p+= 1;
if ( p == pe  )
	goto _test_eof18;

st_case_18:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr34;
	}
		 case 32:
{
goto ctr34;
	}
		 case 33:
{
goto ctr27;
	}
		 case 34:
{
goto ctr35;
	}
		 case 91:
{
goto ctr27;
	}
		 case 92:
{
goto ctr28;
	}
		 case 95:
{
goto ctr36;
	}
		 case 96:
{
goto ctr27;
	}
	
}
if ( ( (*( p  ))
) < 58  )
	{
		if ( ( (*( p  ))
) < 35  )
	{
			if ( 10 <= ( (*( p  ))
) && ( (*( p  ))
) <= 31  )
	{
				goto ctr27;
			}
		
} 
else if ( ( (*( p  ))
) > 47  )
	{
			{
				goto ctr36;
			}
		} 
else
	{
			goto ctr27;
		}
	
} 
else if ( ( (*( p  ))
) > 64  )
	{
		if ( ( (*( p  ))
) < 93  )
	{
			if ( ( (*( p  ))
) <= 90  )
	{
				goto ctr36;
			}
		
} 
else if ( ( (*( p  ))
) > 94  )
	{
			if ( ( (*( p  ))
) > 122  )
	{
				{
					goto ctr27;
				}
			} 
else if ( ( (*( p  ))
) >= 97  )
	{
				goto ctr36;
			}
		
} 
else
	{
			goto ctr27;
		}
	
} 
else
	{
		goto ctr27;
	}

{
	goto ctr27;
}
ctr36:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }
{fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
{function[fi++] = (( (*( p  ))
));
        }


	goto st19;
ctr38:
	{value[vi++] = (( (*( p  ))
));
        }
{function[fi++] = (( (*( p  ))
));
        }


	goto st19;
st19:
	p+= 1;
if ( p == pe  )
	goto _test_eof19;

st_case_19:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr30;
	}
		 case 32:
{
goto ctr30;
	}
		 case 33:
{
goto ctr27;
	}
		 case 34:
{
goto ctr18;
	}
		 case 40:
{
goto ctr37;
	}
		 case 41:
{
goto ctr31;
	}
		 case 44:
{
goto ctr32;
	}
		 case 58:
{
goto ctr39;
	}
		 case 91:
{
goto ctr27;
	}
		 case 92:
{
goto ctr28;
	}
		 case 95:
{
goto ctr38;
	}
		 case 96:
{
goto ctr27;
	}
	
}
if ( ( (*( p  ))
) < 48  )
	{
		if ( ( (*( p  ))
) < 35  )
	{
			if ( 10 <= ( (*( p  ))
) && ( (*( p  ))
) <= 31  )
	{
				goto ctr27;
			}
		
} 
else if ( ( (*( p  ))
) > 39  )
	{
			if ( ( (*( p  ))
) > 43  )
	{
				if ( 45 <= ( (*( p  ))
)  )
	{
					goto ctr27;
				}
			
} 
else if ( ( (*( p  ))
) >= 42  )
	{
				goto ctr27;
			}
		
} 
else
	{
			goto ctr27;
		}
	
} 
else if ( ( (*( p  ))
) > 57  )
	{
		if ( ( (*( p  ))
) < 93  )
	{
			if ( ( (*( p  ))
) > 64  )
	{
				if ( ( (*( p  ))
) <= 90  )
	{
					goto ctr38;
				}
			
} 
else if ( ( (*( p  ))
) >= 59  )
	{
				goto ctr27;
			}
		
} 
else if ( ( (*( p  ))
) > 94  )
	{
			if ( ( (*( p  ))
) > 122  )
	{
				{
					goto ctr27;
				}
			} 
else if ( ( (*( p  ))
) >= 97  )
	{
				goto ctr38;
			}
		
} 
else
	{
			goto ctr27;
		}
	
} 
else
	{
		goto ctr38;
	}

{
	goto ctr27;
}
ctr37:
	{value[vi++] = (( (*( p  ))
));
        }
{bel_ast_node* term_top = stack_peek(term_stack);

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
{{stack[top] = 20;
top+= 1;
goto st9;}}


	goto st20;
st20:
	p+= 1;
if ( p == pe  )
	goto _test_eof20;

st_case_20:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr33;
	}
		 case 32:
{
goto ctr33;
	}
		 case 33:
{
goto ctr27;
	}
		 case 34:
{
goto ctr18;
	}
		 case 41:
{
goto ctr40;
	}
		 case 44:
{
goto ctr34;
	}
		 case 92:
{
goto ctr28;
	}
	
}
if ( ( (*( p  ))
) < 42  )
	{
		if ( ( (*( p  ))
) > 31  )
	{
			if ( 35 <= ( (*( p  ))
) && ( (*( p  ))
) <= 40  )
	{
				goto ctr27;
			}
		
} 
else if ( ( (*( p  ))
) >= 10  )
	{
			goto ctr27;
		}
	
} 
else if ( ( (*( p  ))
) > 43  )
	{
		if ( ( (*( p  ))
) > 91  )
	{
			if ( 93 <= ( (*( p  ))
)  )
	{
				goto ctr27;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr27;
		}
	
} 
else
	{
		goto ctr27;
	}

{
	goto ctr27;
}
ctr31:
	{value[vi++] = (( (*( p  ))
));
        }
{if (!current_nv) {
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
{term = stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st43;
ctr40:
	{value[vi++] = (( (*( p  ))
));
        }
{term = stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st43;
ctr58:
	{if (!current_nv) {
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
{value[vi++] = (( (*( p  ))
));
        }
{term = stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st43;
st43:
	p+= 1;
if ( p == pe  )
	goto _test_eof43;

st_case_43:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr18;
	}
		 case 92:
{
goto ctr28;
	}
	
}
if ( ( (*( p  ))
) > 91  )
	{
		if ( 93 <= ( (*( p  ))
)  )
	{
			goto ctr27;
		}
	
} 
else if ( ( (*( p  ))
) >= 35  )
	{
		goto ctr27;
	}

{
	goto ctr27;
}
ctr39:
	{term = stack_peek(term_stack);

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
{value[vi++] = (( (*( p  ))
));
        }


	goto st21;
st21:
	p+= 1;
if ( p == pe  )
	goto _test_eof21;

st_case_21:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr35;
	}
		 case 91:
{
goto ctr27;
	}
		 case 92:
{
goto ctr28;
	}
		 case 95:
{
goto ctr41;
	}
		 case 96:
{
goto ctr27;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( ( (*( p  ))
) < 48  )
	{
			if ( 35 <= ( (*( p  ))
)  )
	{
				goto ctr27;
			}
		
} 
else if ( ( (*( p  ))
) > 57  )
	{
			{
				goto ctr27;
			}
		} 
else
	{
			goto ctr41;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( ( (*( p  ))
) < 97  )
	{
			if ( 93 <= ( (*( p  ))
) && ( (*( p  ))
) <= 94  )
	{
				goto ctr27;
			}
		
} 
else if ( ( (*( p  ))
) > 122  )
	{
			{
				goto ctr27;
			}
		} 
else
	{
			goto ctr41;
		}
	
} 
else
	{
		goto ctr41;
	}

{
	goto ctr27;
}
ctr41:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }


	goto st22;
ctr42:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st22;
st22:
	p+= 1;
if ( p == pe  )
	goto _test_eof22;

st_case_22:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr30;
	}
		 case 32:
{
goto ctr30;
	}
		 case 33:
{
goto ctr27;
	}
		 case 34:
{
goto ctr18;
	}
		 case 41:
{
goto ctr31;
	}
		 case 44:
{
goto ctr32;
	}
		 case 91:
{
goto ctr27;
	}
		 case 92:
{
goto ctr28;
	}
		 case 95:
{
goto ctr42;
	}
		 case 96:
{
goto ctr27;
	}
	
}
if ( ( (*( p  ))
) < 48  )
	{
		if ( ( (*( p  ))
) < 35  )
	{
			if ( 10 <= ( (*( p  ))
) && ( (*( p  ))
) <= 31  )
	{
				goto ctr27;
			}
		
} 
else if ( ( (*( p  ))
) > 40  )
	{
			if ( ( (*( p  ))
) > 43  )
	{
				if ( 45 <= ( (*( p  ))
)  )
	{
					goto ctr27;
				}
			
} 
else if ( ( (*( p  ))
) >= 42  )
	{
				goto ctr27;
			}
		
} 
else
	{
			goto ctr27;
		}
	
} 
else if ( ( (*( p  ))
) > 57  )
	{
		if ( ( (*( p  ))
) < 93  )
	{
			if ( ( (*( p  ))
) > 64  )
	{
				if ( ( (*( p  ))
) <= 90  )
	{
					goto ctr42;
				}
			
} 
else
	{
				goto ctr27;
			}
		
} 
else if ( ( (*( p  ))
) > 94  )
	{
			if ( ( (*( p  ))
) > 122  )
	{
				{
					goto ctr27;
				}
			} 
else if ( ( (*( p  ))
) >= 97  )
	{
				goto ctr42;
			}
		
} 
else
	{
			goto ctr27;
		}
	
} 
else
	{
		goto ctr42;
	}

{
	goto ctr27;
}
ctr26:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }
{fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
{function[fi++] = (( (*( p  ))
));
        }


	goto st23;
ctr44:
	{value[vi++] = (( (*( p  ))
));
        }
{function[fi++] = (( (*( p  ))
));
        }


	goto st23;
st23:
	p+= 1;
if ( p == pe  )
	goto _test_eof23;

st_case_23:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr20;
	}
		 case 32:
{
goto ctr20;
	}
		 case 40:
{
goto ctr43;
	}
		 case 41:
{
goto ctr21;
	}
		 case 44:
{
goto ctr22;
	}
		 case 58:
{
goto ctr45;
	}
		 case 95:
{
goto ctr44;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr44;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr44;
		}
	
} 
else
	{
		goto ctr44;
	}

{
	goto st0;
}
ctr43:
	{bel_ast_node* term_top = stack_peek(term_stack);

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
{{stack[top] = 24;
top+= 1;
goto st9;}}


	goto st24;
st24:
	p+= 1;
if ( p == pe  )
	goto _test_eof24;

st_case_24:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto st12;
	}
		 case 32:
{
goto st12;
	}
		 case 41:
{
goto ctr46;
	}
		 case 44:
{
goto st13;
	}
	
}
{
	goto st0;
}
ctr21:
	{if (!current_nv) {
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
{term = stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st44;
ctr46:
	{term = stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st44;
st44:
	p+= 1;
if ( p == pe  )
	goto _test_eof44;

st_case_44:
{
	goto st0;
}
ctr45:
	{term = stack_peek(term_stack);

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


	goto st25;
st25:
	p+= 1;
if ( p == pe  )
	goto _test_eof25;

st_case_25:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr25;
	}
		 case 95:
{
goto ctr47;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr47;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr47;
		}
	
} 
else
	{
		goto ctr47;
	}

{
	goto st0;
}
ctr47:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }


	goto st26;
ctr48:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st26;
st26:
	p+= 1;
if ( p == pe  )
	goto _test_eof26;

st_case_26:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr20;
	}
		 case 32:
{
goto ctr20;
	}
		 case 41:
{
goto ctr21;
	}
		 case 44:
{
goto ctr22;
	}
		 case 95:
{
goto ctr48;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr48;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr48;
		}
	
} 
else
	{
		goto ctr48;
	}

{
	goto st0;
}
ctr19:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st27;
st27:
	p+= 1;
if ( p == pe  )
	goto _test_eof27;

st_case_27:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr49;
	}
		 case 92:
{
goto ctr19;
	}
	
}
if ( ( (*( p  ))
) > 91  )
	{
		if ( 93 <= ( (*( p  ))
)  )
	{
			goto ctr17;
		}
	
} 
else if ( ( (*( p  ))
) >= 35  )
	{
		goto ctr17;
	}

{
	goto ctr17;
}
ctr49:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st28;
st28:
	p+= 1;
if ( p == pe  )
	goto _test_eof28;

st_case_28:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr50;
	}
		 case 32:
{
goto ctr50;
	}
		 case 33:
{
goto ctr17;
	}
		 case 34:
{
goto ctr18;
	}
		 case 41:
{
goto ctr51;
	}
		 case 44:
{
goto ctr52;
	}
		 case 92:
{
goto ctr19;
	}
	
}
if ( ( (*( p  ))
) < 42  )
	{
		if ( ( (*( p  ))
) > 31  )
	{
			if ( 35 <= ( (*( p  ))
) && ( (*( p  ))
) <= 40  )
	{
				goto ctr17;
			}
		
} 
else if ( ( (*( p  ))
) >= 10  )
	{
			goto ctr17;
		}
	
} 
else if ( ( (*( p  ))
) > 43  )
	{
		if ( ( (*( p  ))
) > 91  )
	{
			if ( 93 <= ( (*( p  ))
)  )
	{
				goto ctr17;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr17;
		}
	
} 
else
	{
		goto ctr17;
	}

{
	goto ctr17;
}
ctr53:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st29;
ctr50:
	{value[vi++] = (( (*( p  ))
));
        }
{if (!current_nv) {
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


	goto st29;
st29:
	p+= 1;
if ( p == pe  )
	goto _test_eof29;

st_case_29:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr53;
	}
		 case 32:
{
goto ctr53;
	}
		 case 33:
{
goto ctr17;
	}
		 case 34:
{
goto ctr18;
	}
		 case 44:
{
goto ctr54;
	}
		 case 92:
{
goto ctr19;
	}
	
}
if ( ( (*( p  ))
) < 35  )
	{
		if ( 10 <= ( (*( p  ))
) && ( (*( p  ))
) <= 31  )
	{
			goto ctr17;
		}
	
} 
else if ( ( (*( p  ))
) > 43  )
	{
		if ( ( (*( p  ))
) > 91  )
	{
			if ( 93 <= ( (*( p  ))
)  )
	{
				goto ctr17;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr17;
		}
	
} 
else
	{
		goto ctr17;
	}

{
	goto ctr17;
}
ctr54:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st30;
ctr52:
	{value[vi++] = (( (*( p  ))
));
        }
{if (!current_nv) {
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


	goto st30;
st30:
	p+= 1;
if ( p == pe  )
	goto _test_eof30;

st_case_30:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr54;
	}
		 case 32:
{
goto ctr54;
	}
		 case 33:
{
goto ctr17;
	}
		 case 34:
{
goto ctr55;
	}
		 case 91:
{
goto ctr17;
	}
		 case 92:
{
goto ctr19;
	}
		 case 95:
{
goto ctr56;
	}
		 case 96:
{
goto ctr17;
	}
	
}
if ( ( (*( p  ))
) < 58  )
	{
		if ( ( (*( p  ))
) < 35  )
	{
			if ( 10 <= ( (*( p  ))
) && ( (*( p  ))
) <= 31  )
	{
				goto ctr17;
			}
		
} 
else if ( ( (*( p  ))
) > 47  )
	{
			{
				goto ctr56;
			}
		} 
else
	{
			goto ctr17;
		}
	
} 
else if ( ( (*( p  ))
) > 64  )
	{
		if ( ( (*( p  ))
) < 93  )
	{
			if ( ( (*( p  ))
) <= 90  )
	{
				goto ctr56;
			}
		
} 
else if ( ( (*( p  ))
) > 94  )
	{
			if ( ( (*( p  ))
) > 122  )
	{
				{
					goto ctr17;
				}
			} 
else if ( ( (*( p  ))
) >= 97  )
	{
				goto ctr56;
			}
		
} 
else
	{
			goto ctr17;
		}
	
} 
else
	{
		goto ctr17;
	}

{
	goto ctr17;
}
ctr55:
	{value[vi++] = (( (*( p  ))
));
        }
{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }


	goto st31;
st31:
	p+= 1;
if ( p == pe  )
	goto _test_eof31;

st_case_31:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr57;
	}
		 case 32:
{
goto ctr57;
	}
		 case 33:
{
goto ctr27;
	}
		 case 34:
{
goto ctr18;
	}
		 case 41:
{
goto ctr58;
	}
		 case 44:
{
goto ctr59;
	}
		 case 92:
{
goto ctr28;
	}
	
}
if ( ( (*( p  ))
) < 42  )
	{
		if ( ( (*( p  ))
) > 31  )
	{
			if ( 35 <= ( (*( p  ))
) && ( (*( p  ))
) <= 40  )
	{
				goto ctr27;
			}
		
} 
else if ( ( (*( p  ))
) >= 10  )
	{
			goto ctr27;
		}
	
} 
else if ( ( (*( p  ))
) > 43  )
	{
		if ( ( (*( p  ))
) > 91  )
	{
			if ( 93 <= ( (*( p  ))
)  )
	{
				goto ctr27;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr27;
		}
	
} 
else
	{
		goto ctr27;
	}

{
	goto ctr27;
}
ctr61:
	{value[vi++] = (( (*( p  ))
));
        }
{function[fi++] = (( (*( p  ))
));
        }


	goto st32;
ctr56:
	{value[vi++] = (( (*( p  ))
));
        }
{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
{function[fi++] = (( (*( p  ))
));
        }


	goto st32;
st32:
	p+= 1;
if ( p == pe  )
	goto _test_eof32;

st_case_32:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr50;
	}
		 case 32:
{
goto ctr50;
	}
		 case 33:
{
goto ctr17;
	}
		 case 34:
{
goto ctr18;
	}
		 case 40:
{
goto ctr60;
	}
		 case 41:
{
goto ctr51;
	}
		 case 44:
{
goto ctr52;
	}
		 case 58:
{
goto ctr62;
	}
		 case 91:
{
goto ctr17;
	}
		 case 92:
{
goto ctr19;
	}
		 case 95:
{
goto ctr61;
	}
		 case 96:
{
goto ctr17;
	}
	
}
if ( ( (*( p  ))
) < 48  )
	{
		if ( ( (*( p  ))
) < 35  )
	{
			if ( 10 <= ( (*( p  ))
) && ( (*( p  ))
) <= 31  )
	{
				goto ctr17;
			}
		
} 
else if ( ( (*( p  ))
) > 39  )
	{
			if ( ( (*( p  ))
) > 43  )
	{
				if ( 45 <= ( (*( p  ))
)  )
	{
					goto ctr17;
				}
			
} 
else if ( ( (*( p  ))
) >= 42  )
	{
				goto ctr17;
			}
		
} 
else
	{
			goto ctr17;
		}
	
} 
else if ( ( (*( p  ))
) > 57  )
	{
		if ( ( (*( p  ))
) < 93  )
	{
			if ( ( (*( p  ))
) > 64  )
	{
				if ( ( (*( p  ))
) <= 90  )
	{
					goto ctr61;
				}
			
} 
else if ( ( (*( p  ))
) >= 59  )
	{
				goto ctr17;
			}
		
} 
else if ( ( (*( p  ))
) > 94  )
	{
			if ( ( (*( p  ))
) > 122  )
	{
				{
					goto ctr17;
				}
			} 
else if ( ( (*( p  ))
) >= 97  )
	{
				goto ctr61;
			}
		
} 
else
	{
			goto ctr17;
		}
	
} 
else
	{
		goto ctr61;
	}

{
	goto ctr17;
}
ctr60:
	{value[vi++] = (( (*( p  ))
));
        }
{bel_ast_node* term_top = stack_peek(term_stack);

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
{{stack[top] = 33;
top+= 1;
goto st9;}}


	goto st33;
st33:
	p+= 1;
if ( p == pe  )
	goto _test_eof33;

st_case_33:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr53;
	}
		 case 32:
{
goto ctr53;
	}
		 case 33:
{
goto ctr17;
	}
		 case 34:
{
goto ctr18;
	}
		 case 41:
{
goto ctr63;
	}
		 case 44:
{
goto ctr54;
	}
		 case 92:
{
goto ctr19;
	}
	
}
if ( ( (*( p  ))
) < 42  )
	{
		if ( ( (*( p  ))
) > 31  )
	{
			if ( 35 <= ( (*( p  ))
) && ( (*( p  ))
) <= 40  )
	{
				goto ctr17;
			}
		
} 
else if ( ( (*( p  ))
) >= 10  )
	{
			goto ctr17;
		}
	
} 
else if ( ( (*( p  ))
) > 43  )
	{
		if ( ( (*( p  ))
) > 91  )
	{
			if ( 93 <= ( (*( p  ))
)  )
	{
				goto ctr17;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr17;
		}
	
} 
else
	{
		goto ctr17;
	}

{
	goto ctr17;
}
ctr51:
	{value[vi++] = (( (*( p  ))
));
        }
{if (!current_nv) {
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
{term = stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st45;
ctr63:
	{value[vi++] = (( (*( p  ))
));
        }
{term = stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st45;
st45:
	p+= 1;
if ( p == pe  )
	goto _test_eof45;

st_case_45:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr18;
	}
		 case 92:
{
goto ctr19;
	}
	
}
if ( ( (*( p  ))
) > 91  )
	{
		if ( 93 <= ( (*( p  ))
)  )
	{
			goto ctr17;
		}
	
} 
else if ( ( (*( p  ))
) >= 35  )
	{
		goto ctr17;
	}

{
	goto ctr17;
}
ctr62:
	{value[vi++] = (( (*( p  ))
));
        }
{term = stack_peek(term_stack);

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


	goto st34;
st34:
	p+= 1;
if ( p == pe  )
	goto _test_eof34;

st_case_34:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr55;
	}
		 case 91:
{
goto ctr17;
	}
		 case 92:
{
goto ctr19;
	}
		 case 95:
{
goto ctr64;
	}
		 case 96:
{
goto ctr17;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( ( (*( p  ))
) < 48  )
	{
			if ( 35 <= ( (*( p  ))
)  )
	{
				goto ctr17;
			}
		
} 
else if ( ( (*( p  ))
) > 57  )
	{
			{
				goto ctr17;
			}
		} 
else
	{
			goto ctr64;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( ( (*( p  ))
) < 97  )
	{
			if ( 93 <= ( (*( p  ))
) && ( (*( p  ))
) <= 94  )
	{
				goto ctr17;
			}
		
} 
else if ( ( (*( p  ))
) > 122  )
	{
			{
				goto ctr17;
			}
		} 
else
	{
			goto ctr64;
		}
	
} 
else
	{
		goto ctr64;
	}

{
	goto ctr17;
}
ctr65:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st35;
ctr64:
	{value[vi++] = (( (*( p  ))
));
        }
{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }


	goto st35;
st35:
	p+= 1;
if ( p == pe  )
	goto _test_eof35;

st_case_35:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr50;
	}
		 case 32:
{
goto ctr50;
	}
		 case 33:
{
goto ctr17;
	}
		 case 34:
{
goto ctr18;
	}
		 case 41:
{
goto ctr51;
	}
		 case 44:
{
goto ctr52;
	}
		 case 91:
{
goto ctr17;
	}
		 case 92:
{
goto ctr19;
	}
		 case 95:
{
goto ctr65;
	}
		 case 96:
{
goto ctr17;
	}
	
}
if ( ( (*( p  ))
) < 48  )
	{
		if ( ( (*( p  ))
) < 35  )
	{
			if ( 10 <= ( (*( p  ))
) && ( (*( p  ))
) <= 31  )
	{
				goto ctr17;
			}
		
} 
else if ( ( (*( p  ))
) > 40  )
	{
			if ( ( (*( p  ))
) > 43  )
	{
				if ( 45 <= ( (*( p  ))
)  )
	{
					goto ctr17;
				}
			
} 
else if ( ( (*( p  ))
) >= 42  )
	{
				goto ctr17;
			}
		
} 
else
	{
			goto ctr17;
		}
	
} 
else if ( ( (*( p  ))
) > 57  )
	{
		if ( ( (*( p  ))
) < 93  )
	{
			if ( ( (*( p  ))
) > 64  )
	{
				if ( ( (*( p  ))
) <= 90  )
	{
					goto ctr65;
				}
			
} 
else
	{
				goto ctr17;
			}
		
} 
else if ( ( (*( p  ))
) > 94  )
	{
			if ( ( (*( p  ))
) > 122  )
	{
				{
					goto ctr17;
				}
			} 
else if ( ( (*( p  ))
) >= 97  )
	{
				goto ctr65;
			}
		
} 
else
	{
			goto ctr17;
		}
	
} 
else
	{
		goto ctr65;
	}

{
	goto ctr17;
}
ctr16:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }
{fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
{function[fi++] = (( (*( p  ))
));
        }


	goto st36;
ctr66:
	{value[vi++] = (( (*( p  ))
));
        }
{function[fi++] = (( (*( p  ))
));
        }


	goto st36;
st36:
	p+= 1;
if ( p == pe  )
	goto _test_eof36;

st_case_36:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr20;
	}
		 case 32:
{
goto ctr20;
	}
		 case 40:
{
goto ctr43;
	}
		 case 41:
{
goto ctr21;
	}
		 case 44:
{
goto ctr22;
	}
		 case 58:
{
goto ctr67;
	}
		 case 95:
{
goto ctr66;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr66;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr66;
		}
	
} 
else
	{
		goto ctr66;
	}

{
	goto st0;
}
ctr67:
	{term = stack_peek(term_stack);

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


	goto st37;
st37:
	p+= 1;
if ( p == pe  )
	goto _test_eof37;

st_case_37:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr15;
	}
		 case 95:
{
goto ctr47;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr47;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr47;
		}
	
} 
else
	{
		goto ctr47;
	}

{
	goto st0;
}
st38:
	p+= 1;
if ( p == pe  )
	goto _test_eof38;

st_case_38:
	if ( ( (*( p  ))
) == 95  )
	{
		goto ctr68;
	}
	
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr68;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr68;
		}
	
} 
else
	{
		goto ctr68;
	}

{
	goto st0;
}
ctr68:
	{fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
{function[fi++] = (( (*( p  ))
));
        }


	goto st39;
ctr70:
	{function[fi++] = (( (*( p  ))
));
        }


	goto st39;
st39:
	p+= 1;
if ( p == pe  )
	goto _test_eof39;

st_case_39:
	switch ( ( (*( p  ))
)  ) {
	case 40:
{
goto ctr69;
	}
		 case 95:
{
goto ctr70;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr70;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr70;
		}
	
} 
else
	{
		goto ctr70;
	}

{
	goto st0;
}
ctr69:
	{term               = stack_peek(term_stack);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
{{stack[top] = 40;
top+= 1;
goto st9;}}


	goto st40;
st40:
	p+= 1;
if ( p == pe  )
	goto _test_eof40;

st_case_40:
{
	goto ctr71;
}
ctr71:
	{{ p = p - 1;
} }
{statement = stack_peek(statement_stack);
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

            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st46;
st46:
	p+= 1;
if ( p == pe  )
	goto _test_eof46;

st_case_46:
{
	goto st0;
}
	st_out:
	_test_eof1: cs = 1;
goto _test_eof; 
	_test_eof2: cs = 2;
goto _test_eof; 
	_test_eof3: cs = 3;
goto _test_eof; 
	_test_eof4: cs = 4;
goto _test_eof; 
	_test_eof5: cs = 5;
goto _test_eof; 
	_test_eof6: cs = 6;
goto _test_eof; 
	_test_eof41: cs = 41;
goto _test_eof; 
	_test_eof7: cs = 7;
goto _test_eof; 
	_test_eof42: cs = 42;
goto _test_eof; 
	_test_eof8: cs = 8;
goto _test_eof; 
	_test_eof9: cs = 9;
goto _test_eof; 
	_test_eof10: cs = 10;
goto _test_eof; 
	_test_eof11: cs = 11;
goto _test_eof; 
	_test_eof12: cs = 12;
goto _test_eof; 
	_test_eof13: cs = 13;
goto _test_eof; 
	_test_eof14: cs = 14;
goto _test_eof; 
	_test_eof15: cs = 15;
goto _test_eof; 
	_test_eof16: cs = 16;
goto _test_eof; 
	_test_eof17: cs = 17;
goto _test_eof; 
	_test_eof18: cs = 18;
goto _test_eof; 
	_test_eof19: cs = 19;
goto _test_eof; 
	_test_eof20: cs = 20;
goto _test_eof; 
	_test_eof43: cs = 43;
goto _test_eof; 
	_test_eof21: cs = 21;
goto _test_eof; 
	_test_eof22: cs = 22;
goto _test_eof; 
	_test_eof23: cs = 23;
goto _test_eof; 
	_test_eof24: cs = 24;
goto _test_eof; 
	_test_eof44: cs = 44;
goto _test_eof; 
	_test_eof25: cs = 25;
goto _test_eof; 
	_test_eof26: cs = 26;
goto _test_eof; 
	_test_eof27: cs = 27;
goto _test_eof; 
	_test_eof28: cs = 28;
goto _test_eof; 
	_test_eof29: cs = 29;
goto _test_eof; 
	_test_eof30: cs = 30;
goto _test_eof; 
	_test_eof31: cs = 31;
goto _test_eof; 
	_test_eof32: cs = 32;
goto _test_eof; 
	_test_eof33: cs = 33;
goto _test_eof; 
	_test_eof45: cs = 45;
goto _test_eof; 
	_test_eof34: cs = 34;
goto _test_eof; 
	_test_eof35: cs = 35;
goto _test_eof; 
	_test_eof36: cs = 36;
goto _test_eof; 
	_test_eof37: cs = 37;
goto _test_eof; 
	_test_eof38: cs = 38;
goto _test_eof; 
	_test_eof39: cs = 39;
goto _test_eof; 
	_test_eof40: cs = 40;
goto _test_eof; 
	_test_eof46: cs = 46;
goto _test_eof; 

	_test_eof: {}
	_out: {}
	}
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

