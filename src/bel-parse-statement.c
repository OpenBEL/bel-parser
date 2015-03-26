#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bel-ast.h"
#include "bel-node-stack.h"

/*
 * Value size: The maximum number of characters to hold in an
 * accumulated value.
 */
#define BEL_VALUE_CHAR_LEN 512

/*
 * Term stack size: Allows for a nesting of at most 32 terms.
 */
#define TERM_STACK_SIZE 32

static const int  set_start  = 1;
static const int  set_first_final  = 37;
static const int  set_error  = 0;
static const int  set_en_arguments  = 5;
static const int  set_en_term  = 34;
static const int  set_en_statement  = 1;
bel_ast* bel_parse_statement(char* line) {
    int             cs;
    char            *p;
    char            *pe;
    int             top;
    int             *stack;
    bel_ast_node*   statement;
    bel_ast_node*   subject;
    bel_ast_node*   rel;
    bel_ast_node*   object;
    bel_ast_node*   term;
    bel_ast_node*   current_nv;
    bel_ast_node*   arg;
    bel_ast*        ast;
    bel_node_stack* term_stack;
    char            *function;
    char            *relationship;
    char            *value;
    int             fi;
    int             ri;
    int             vi;

    p            = line;
    pe           = line + strlen(line);
    top          = 0;
    stack        = malloc(sizeof(int) * TERM_STACK_SIZE);
    current_nv   = NULL;
    function     = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    relationship = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    value        = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    fi           = 0;
    ri           = 0;
    vi           = 0;

    term_stack   = stack_init(TERM_STACK_SIZE);
    statement    = bel_new_ast_node_token(BEL_TOKEN_STATEMENT);
    subject      = bel_new_ast_node_token(BEL_TOKEN_SUBJECT);
    rel          = bel_new_ast_node_token(BEL_TOKEN_REL);
    object       = bel_new_ast_node_token(BEL_TOKEN_OBJECT);
    term         = NULL;
    ast          = bel_new_ast();
    ast->root    = statement;

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
		case 37:
goto st37;
		case 5:
goto st5;
		case 6:
goto st6;
		case 7:
goto st7;
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
		case 38:
goto st38;
		case 17:
goto st17;
		case 18:
goto st18;
		case 19:
goto st19;
		case 20:
goto st20;
		case 39:
goto st39;
		case 21:
goto st21;
		case 22:
goto st22;
		case 23:
goto st23;
		case 24:
goto st24;
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
		case 40:
goto st40;
		case 30:
goto st30;
		case 31:
goto st31;
		case 32:
goto st32;
		case 33:
goto st33;
		case 34:
goto st34;
		case 35:
goto st35;
		case 36:
goto st36;
		case 41:
goto st41;
		case 42:
goto st42;
		case 43:
goto st43;
	
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
	case 37:
goto st_case_37;
	case 5:
goto st_case_5;
	case 6:
goto st_case_6;
	case 7:
goto st_case_7;
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
	case 38:
goto st_case_38;
	case 17:
goto st_case_17;
	case 18:
goto st_case_18;
	case 19:
goto st_case_19;
	case 20:
goto st_case_20;
	case 39:
goto st_case_39;
	case 21:
goto st_case_21;
	case 22:
goto st_case_22;
	case 23:
goto st_case_23;
	case 24:
goto st_case_24;
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
	case 40:
goto st_case_40;
	case 30:
goto st_case_30;
	case 31:
goto st_case_31;
	case 32:
goto st_case_32;
	case 33:
goto st_case_33;
	case 34:
goto st_case_34;
	case 35:
goto st_case_35;
	case 36:
goto st_case_36;
	case 41:
goto st_case_41;
	case 42:
goto st_case_42;
	case 43:
goto st_case_43;
	
}
goto st_out;
st1:
	p+= 1;
if ( p == pe  )
	goto _test_eof1;

st_case_1:
	if ( ( (*( p  ))
) == 95  )
	{
		goto ctr0;
	}
	
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr0;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr0;
		}
	
} 
else
	{
		goto ctr0;
	}

{
	goto st0;
}
st_case_0:
st0:
cs = 0;
goto _out;
ctr0:
	{{ p = p - 1;
}
            term = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term_stack->top = -1;
            stack_push(term_stack, term);
            {stack[top] = 2;
top+= 1;
goto st34;}}


	goto st2;
st2:
	p+= 1;
if ( p == pe  )
	goto _test_eof2;

st_case_2:
	if ( ( (*( p  ))
) == 32  )
	{
		goto st0;
	}
	
if ( ( (*( p  ))
) < 11  )
	{
		if ( 9 <= ( (*( p  ))
)  )
	{
			goto st0;
		}
	
} 
else if ( ( (*( p  ))
) > 31  )
	{
		if ( 33 <= ( (*( p  ))
)  )
	{
			goto ctr2;
		}
	
} 
else
	{
		goto ctr2;
	}

{
	goto ctr2;
}
ctr2:
	{ri = 0;
            memset(relationship, '\0', BEL_VALUE_CHAR_LEN);
        }
{relationship[ri++] = (( (*( p  ))
));
        }
{rel->token->left = bel_new_ast_node_value(BEL_VALUE_REL, relationship);
            object->token->left = rel;
        }


	goto st3;
ctr3:
	{relationship[ri++] = (( (*( p  ))
));
        }
{rel->token->left = bel_new_ast_node_value(BEL_VALUE_REL, relationship);
            object->token->left = rel;
        }


	goto st3;
st3:
	p+= 1;
if ( p == pe  )
	goto _test_eof3;

st_case_3:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto st4;
	}
		 case 10:
{
goto st0;
	}
		 case 32:
{
goto st4;
	}
	
}
if ( ( (*( p  ))
) > 31  )
	{
		if ( 33 <= ( (*( p  ))
)  )
	{
			goto ctr3;
		}
	
} 
else if ( ( (*( p  ))
) >= 11  )
	{
		goto ctr3;
	}

{
	goto ctr3;
}
st4:
	p+= 1;
if ( p == pe  )
	goto _test_eof4;

st_case_4:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto st4;
	}
		 case 32:
{
goto st4;
	}
		 case 95:
{
goto ctr5;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr5;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr5;
		}
	
} 
else
	{
		goto ctr5;
	}

{
	goto st0;
}
ctr5:
	{{ p = p - 1;
}
            term = bel_new_ast_node_token(BEL_TOKEN_TERM);
            term_stack->top = -1;
            stack_push(term_stack, term);
            {stack[top] = 37;
top+= 1;
goto st34;}}


	goto st37;
st37:
	p+= 1;
if ( p == pe  )
	goto _test_eof37;

st_case_37:
{
	goto st0;
}
st5:
	p+= 1;
if ( p == pe  )
	goto _test_eof5;

st_case_5:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr6;
	}
		 case 95:
{
goto ctr7;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr7;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr7;
		}
	
} 
else
	{
		goto ctr7;
	}

{
	goto st0;
}
ctr6:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }


	goto st6;
ctr8:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st6;
st6:
	p+= 1;
if ( p == pe  )
	goto _test_eof6;

st_case_6:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr9;
	}
		 case 92:
{
goto ctr10;
	}
	
}
if ( ( (*( p  ))
) > 91  )
	{
		if ( 93 <= ( (*( p  ))
)  )
	{
			goto ctr8;
		}
	
} 
else if ( ( (*( p  ))
) >= 35  )
	{
		goto ctr8;
	}

{
	goto ctr8;
}
ctr9:
	{value[vi++] = (( (*( p  ))
));
        }


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
goto ctr11;
	}
		 case 32:
{
goto ctr11;
	}
		 case 41:
{
goto ctr12;
	}
		 case 44:
{
goto ctr13;
	}
	
}
{
	goto st0;
}
ctr11:
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


	goto st8;
st8:
	p+= 1;
if ( p == pe  )
	goto _test_eof8;

st_case_8:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto st8;
	}
		 case 32:
{
goto st8;
	}
		 case 44:
{
goto st9;
	}
	
}
{
	goto st0;
}
ctr13:
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


	goto st9;
st9:
	p+= 1;
if ( p == pe  )
	goto _test_eof9;

st_case_9:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto st9;
	}
		 case 32:
{
goto st9;
	}
		 case 34:
{
goto ctr16;
	}
		 case 95:
{
goto ctr17;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr17;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr17;
		}
	
} 
else
	{
		goto ctr17;
	}

{
	goto st0;
}
ctr16:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }


	goto st10;
ctr18:
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
goto ctr9;
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
			goto ctr18;
		}
	
} 
else if ( ( (*( p  ))
) >= 35  )
	{
		goto ctr18;
	}

{
	goto ctr18;
}
ctr19:
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
	case 34:
{
goto ctr20;
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
			goto ctr18;
		}
	
} 
else if ( ( (*( p  ))
) >= 35  )
	{
		goto ctr18;
	}

{
	goto ctr18;
}
ctr26:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }


	goto st12;
ctr20:
	{value[vi++] = (( (*( p  ))
));
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
goto ctr21;
	}
		 case 32:
{
goto ctr21;
	}
		 case 33:
{
goto ctr18;
	}
		 case 34:
{
goto ctr9;
	}
		 case 41:
{
goto ctr22;
	}
		 case 44:
{
goto ctr23;
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
				goto ctr18;
			}
		
} 
else if ( ( (*( p  ))
) >= 10  )
	{
			goto ctr18;
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
				goto ctr18;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr18;
		}
	
} 
else
	{
		goto ctr18;
	}

{
	goto ctr18;
}
ctr24:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st13;
ctr21:
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


	goto st13;
ctr48:
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
goto ctr24;
	}
		 case 32:
{
goto ctr24;
	}
		 case 33:
{
goto ctr18;
	}
		 case 34:
{
goto ctr9;
	}
		 case 44:
{
goto ctr25;
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
			goto ctr18;
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
				goto ctr18;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr18;
		}
	
} 
else
	{
		goto ctr18;
	}

{
	goto ctr18;
}
ctr25:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st14;
ctr23:
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


	goto st14;
ctr50:
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


	goto st14;
st14:
	p+= 1;
if ( p == pe  )
	goto _test_eof14;

st_case_14:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr25;
	}
		 case 32:
{
goto ctr25;
	}
		 case 33:
{
goto ctr18;
	}
		 case 34:
{
goto ctr26;
	}
		 case 91:
{
goto ctr18;
	}
		 case 92:
{
goto ctr19;
	}
		 case 95:
{
goto ctr27;
	}
		 case 96:
{
goto ctr18;
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
				goto ctr18;
			}
		
} 
else if ( ( (*( p  ))
) > 47  )
	{
			{
				goto ctr27;
			}
		} 
else
	{
			goto ctr18;
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
					goto ctr18;
				}
			} 
else if ( ( (*( p  ))
) >= 97  )
	{
				goto ctr27;
			}
		
} 
else
	{
			goto ctr18;
		}
	
} 
else
	{
		goto ctr18;
	}

{
	goto ctr18;
}
ctr27:
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


	goto st15;
ctr29:
	{value[vi++] = (( (*( p  ))
));
        }
{function[fi++] = (( (*( p  ))
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
	case 9:
{
goto ctr21;
	}
		 case 32:
{
goto ctr21;
	}
		 case 33:
{
goto ctr18;
	}
		 case 34:
{
goto ctr9;
	}
		 case 40:
{
goto ctr28;
	}
		 case 41:
{
goto ctr22;
	}
		 case 44:
{
goto ctr23;
	}
		 case 58:
{
goto ctr30;
	}
		 case 91:
{
goto ctr18;
	}
		 case 92:
{
goto ctr19;
	}
		 case 95:
{
goto ctr29;
	}
		 case 96:
{
goto ctr18;
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
				goto ctr18;
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
					goto ctr18;
				}
			
} 
else if ( ( (*( p  ))
) >= 42  )
	{
				goto ctr18;
			}
		
} 
else
	{
			goto ctr18;
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
					goto ctr29;
				}
			
} 
else if ( ( (*( p  ))
) >= 59  )
	{
				goto ctr18;
			}
		
} 
else if ( ( (*( p  ))
) > 94  )
	{
			if ( ( (*( p  ))
) > 122  )
	{
				{
					goto ctr18;
				}
			} 
else if ( ( (*( p  ))
) >= 97  )
	{
				goto ctr29;
			}
		
} 
else
	{
			goto ctr18;
		}
	
} 
else
	{
		goto ctr29;
	}

{
	goto ctr18;
}
ctr28:
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
{{stack[top] = 16;
top+= 1;
goto st5;}}


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
goto ctr24;
	}
		 case 32:
{
goto ctr24;
	}
		 case 33:
{
goto ctr18;
	}
		 case 34:
{
goto ctr9;
	}
		 case 41:
{
goto ctr31;
	}
		 case 44:
{
goto ctr25;
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
				goto ctr18;
			}
		
} 
else if ( ( (*( p  ))
) >= 10  )
	{
			goto ctr18;
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
				goto ctr18;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr18;
		}
	
} 
else
	{
		goto ctr18;
	}

{
	goto ctr18;
}
ctr22:
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


	goto st38;
ctr31:
	{value[vi++] = (( (*( p  ))
));
        }
{term = stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st38;
ctr49:
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


	goto st38;
st38:
	p+= 1;
if ( p == pe  )
	goto _test_eof38;

st_case_38:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr9;
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
			goto ctr18;
		}
	
} 
else if ( ( (*( p  ))
) >= 35  )
	{
		goto ctr18;
	}

{
	goto ctr18;
}
ctr30:
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


	goto st17;
st17:
	p+= 1;
if ( p == pe  )
	goto _test_eof17;

st_case_17:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr26;
	}
		 case 91:
{
goto ctr18;
	}
		 case 92:
{
goto ctr19;
	}
		 case 95:
{
goto ctr32;
	}
		 case 96:
{
goto ctr18;
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
				goto ctr18;
			}
		
} 
else if ( ( (*( p  ))
) > 57  )
	{
			{
				goto ctr18;
			}
		} 
else
	{
			goto ctr32;
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
				goto ctr18;
			}
		
} 
else if ( ( (*( p  ))
) > 122  )
	{
			{
				goto ctr18;
			}
		} 
else
	{
			goto ctr32;
		}
	
} 
else
	{
		goto ctr32;
	}

{
	goto ctr18;
}
ctr32:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }


	goto st18;
ctr33:
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
goto ctr21;
	}
		 case 32:
{
goto ctr21;
	}
		 case 33:
{
goto ctr18;
	}
		 case 34:
{
goto ctr9;
	}
		 case 41:
{
goto ctr22;
	}
		 case 44:
{
goto ctr23;
	}
		 case 91:
{
goto ctr18;
	}
		 case 92:
{
goto ctr19;
	}
		 case 95:
{
goto ctr33;
	}
		 case 96:
{
goto ctr18;
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
				goto ctr18;
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
					goto ctr18;
				}
			
} 
else if ( ( (*( p  ))
) >= 42  )
	{
				goto ctr18;
			}
		
} 
else
	{
			goto ctr18;
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
					goto ctr33;
				}
			
} 
else
	{
				goto ctr18;
			}
		
} 
else if ( ( (*( p  ))
) > 94  )
	{
			if ( ( (*( p  ))
) > 122  )
	{
				{
					goto ctr18;
				}
			} 
else if ( ( (*( p  ))
) >= 97  )
	{
				goto ctr33;
			}
		
} 
else
	{
			goto ctr18;
		}
	
} 
else
	{
		goto ctr33;
	}

{
	goto ctr18;
}
ctr17:
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
ctr35:
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
goto ctr11;
	}
		 case 32:
{
goto ctr11;
	}
		 case 40:
{
goto ctr34;
	}
		 case 41:
{
goto ctr12;
	}
		 case 44:
{
goto ctr13;
	}
		 case 58:
{
goto ctr36;
	}
		 case 95:
{
goto ctr35;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr35;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr35;
		}
	
} 
else
	{
		goto ctr35;
	}

{
	goto st0;
}
ctr34:
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
goto st5;}}


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
goto st8;
	}
		 case 32:
{
goto st8;
	}
		 case 41:
{
goto ctr37;
	}
		 case 44:
{
goto st9;
	}
	
}
{
	goto st0;
}
ctr12:
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


	goto st39;
ctr37:
	{term = stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st39;
st39:
	p+= 1;
if ( p == pe  )
	goto _test_eof39;

st_case_39:
{
	goto st0;
}
ctr36:
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
goto ctr16;
	}
		 case 95:
{
goto ctr38;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr38;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr38;
		}
	
} 
else
	{
		goto ctr38;
	}

{
	goto st0;
}
ctr38:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }


	goto st22;
ctr39:
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
goto ctr11;
	}
		 case 32:
{
goto ctr11;
	}
		 case 41:
{
goto ctr12;
	}
		 case 44:
{
goto ctr13;
	}
		 case 95:
{
goto ctr39;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr39;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr39;
		}
	
} 
else
	{
		goto ctr39;
	}

{
	goto st0;
}
ctr10:
	{value[vi++] = (( (*( p  ))
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
	case 34:
{
goto ctr40;
	}
		 case 92:
{
goto ctr10;
	}
	
}
if ( ( (*( p  ))
) > 91  )
	{
		if ( 93 <= ( (*( p  ))
)  )
	{
			goto ctr8;
		}
	
} 
else if ( ( (*( p  ))
) >= 35  )
	{
		goto ctr8;
	}

{
	goto ctr8;
}
ctr40:
	{value[vi++] = (( (*( p  ))
));
        }


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
goto ctr41;
	}
		 case 32:
{
goto ctr41;
	}
		 case 33:
{
goto ctr8;
	}
		 case 34:
{
goto ctr9;
	}
		 case 41:
{
goto ctr42;
	}
		 case 44:
{
goto ctr43;
	}
		 case 92:
{
goto ctr10;
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
				goto ctr8;
			}
		
} 
else if ( ( (*( p  ))
) >= 10  )
	{
			goto ctr8;
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
				goto ctr8;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr8;
		}
	
} 
else
	{
		goto ctr8;
	}

{
	goto ctr8;
}
ctr44:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st25;
ctr41:
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


	goto st25;
st25:
	p+= 1;
if ( p == pe  )
	goto _test_eof25;

st_case_25:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr44;
	}
		 case 32:
{
goto ctr44;
	}
		 case 33:
{
goto ctr8;
	}
		 case 34:
{
goto ctr9;
	}
		 case 44:
{
goto ctr45;
	}
		 case 92:
{
goto ctr10;
	}
	
}
if ( ( (*( p  ))
) < 35  )
	{
		if ( 10 <= ( (*( p  ))
) && ( (*( p  ))
) <= 31  )
	{
			goto ctr8;
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
				goto ctr8;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr8;
		}
	
} 
else
	{
		goto ctr8;
	}

{
	goto ctr8;
}
ctr45:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st26;
ctr43:
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
goto ctr45;
	}
		 case 32:
{
goto ctr45;
	}
		 case 33:
{
goto ctr8;
	}
		 case 34:
{
goto ctr46;
	}
		 case 91:
{
goto ctr8;
	}
		 case 92:
{
goto ctr10;
	}
		 case 95:
{
goto ctr47;
	}
		 case 96:
{
goto ctr8;
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
				goto ctr8;
			}
		
} 
else if ( ( (*( p  ))
) > 47  )
	{
			{
				goto ctr47;
			}
		} 
else
	{
			goto ctr8;
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
				goto ctr47;
			}
		
} 
else if ( ( (*( p  ))
) > 94  )
	{
			if ( ( (*( p  ))
) > 122  )
	{
				{
					goto ctr8;
				}
			} 
else if ( ( (*( p  ))
) >= 97  )
	{
				goto ctr47;
			}
		
} 
else
	{
			goto ctr8;
		}
	
} 
else
	{
		goto ctr8;
	}

{
	goto ctr8;
}
ctr46:
	{value[vi++] = (( (*( p  ))
));
        }
{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }


	goto st27;
st27:
	p+= 1;
if ( p == pe  )
	goto _test_eof27;

st_case_27:
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr48;
	}
		 case 32:
{
goto ctr48;
	}
		 case 33:
{
goto ctr18;
	}
		 case 34:
{
goto ctr9;
	}
		 case 41:
{
goto ctr49;
	}
		 case 44:
{
goto ctr50;
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
				goto ctr18;
			}
		
} 
else if ( ( (*( p  ))
) >= 10  )
	{
			goto ctr18;
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
				goto ctr18;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr18;
		}
	
} 
else
	{
		goto ctr18;
	}

{
	goto ctr18;
}
ctr52:
	{value[vi++] = (( (*( p  ))
));
        }
{function[fi++] = (( (*( p  ))
));
        }


	goto st28;
ctr47:
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
goto ctr41;
	}
		 case 32:
{
goto ctr41;
	}
		 case 33:
{
goto ctr8;
	}
		 case 34:
{
goto ctr9;
	}
		 case 40:
{
goto ctr51;
	}
		 case 41:
{
goto ctr42;
	}
		 case 44:
{
goto ctr43;
	}
		 case 58:
{
goto ctr53;
	}
		 case 91:
{
goto ctr8;
	}
		 case 92:
{
goto ctr10;
	}
		 case 95:
{
goto ctr52;
	}
		 case 96:
{
goto ctr8;
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
				goto ctr8;
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
					goto ctr8;
				}
			
} 
else if ( ( (*( p  ))
) >= 42  )
	{
				goto ctr8;
			}
		
} 
else
	{
			goto ctr8;
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
					goto ctr52;
				}
			
} 
else if ( ( (*( p  ))
) >= 59  )
	{
				goto ctr8;
			}
		
} 
else if ( ( (*( p  ))
) > 94  )
	{
			if ( ( (*( p  ))
) > 122  )
	{
				{
					goto ctr8;
				}
			} 
else if ( ( (*( p  ))
) >= 97  )
	{
				goto ctr52;
			}
		
} 
else
	{
			goto ctr8;
		}
	
} 
else
	{
		goto ctr52;
	}

{
	goto ctr8;
}
ctr51:
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
{{stack[top] = 29;
top+= 1;
goto st5;}}


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
goto ctr44;
	}
		 case 32:
{
goto ctr44;
	}
		 case 33:
{
goto ctr8;
	}
		 case 34:
{
goto ctr9;
	}
		 case 41:
{
goto ctr54;
	}
		 case 44:
{
goto ctr45;
	}
		 case 92:
{
goto ctr10;
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
				goto ctr8;
			}
		
} 
else if ( ( (*( p  ))
) >= 10  )
	{
			goto ctr8;
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
				goto ctr8;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr8;
		}
	
} 
else
	{
		goto ctr8;
	}

{
	goto ctr8;
}
ctr42:
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


	goto st40;
ctr54:
	{value[vi++] = (( (*( p  ))
));
        }
{term = stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st40;
st40:
	p+= 1;
if ( p == pe  )
	goto _test_eof40;

st_case_40:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr9;
	}
		 case 92:
{
goto ctr10;
	}
	
}
if ( ( (*( p  ))
) > 91  )
	{
		if ( 93 <= ( (*( p  ))
)  )
	{
			goto ctr8;
		}
	
} 
else if ( ( (*( p  ))
) >= 35  )
	{
		goto ctr8;
	}

{
	goto ctr8;
}
ctr53:
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


	goto st30;
st30:
	p+= 1;
if ( p == pe  )
	goto _test_eof30;

st_case_30:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr46;
	}
		 case 91:
{
goto ctr8;
	}
		 case 92:
{
goto ctr10;
	}
		 case 95:
{
goto ctr55;
	}
		 case 96:
{
goto ctr8;
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
				goto ctr8;
			}
		
} 
else if ( ( (*( p  ))
) > 57  )
	{
			{
				goto ctr8;
			}
		} 
else
	{
			goto ctr55;
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
				goto ctr8;
			}
		
} 
else if ( ( (*( p  ))
) > 122  )
	{
			{
				goto ctr8;
			}
		} 
else
	{
			goto ctr55;
		}
	
} 
else
	{
		goto ctr55;
	}

{
	goto ctr8;
}
ctr56:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st31;
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
goto ctr41;
	}
		 case 32:
{
goto ctr41;
	}
		 case 33:
{
goto ctr8;
	}
		 case 34:
{
goto ctr9;
	}
		 case 41:
{
goto ctr42;
	}
		 case 44:
{
goto ctr43;
	}
		 case 91:
{
goto ctr8;
	}
		 case 92:
{
goto ctr10;
	}
		 case 95:
{
goto ctr56;
	}
		 case 96:
{
goto ctr8;
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
				goto ctr8;
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
					goto ctr8;
				}
			
} 
else if ( ( (*( p  ))
) >= 42  )
	{
				goto ctr8;
			}
		
} 
else
	{
			goto ctr8;
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
					goto ctr56;
				}
			
} 
else
	{
				goto ctr8;
			}
		
} 
else if ( ( (*( p  ))
) > 94  )
	{
			if ( ( (*( p  ))
) > 122  )
	{
				{
					goto ctr8;
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
			goto ctr8;
		}
	
} 
else
	{
		goto ctr56;
	}

{
	goto ctr8;
}
ctr7:
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


	goto st32;
ctr57:
	{value[vi++] = (( (*( p  ))
));
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
goto ctr11;
	}
		 case 32:
{
goto ctr11;
	}
		 case 40:
{
goto ctr34;
	}
		 case 41:
{
goto ctr12;
	}
		 case 44:
{
goto ctr13;
	}
		 case 58:
{
goto ctr58;
	}
		 case 95:
{
goto ctr57;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr57;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr57;
		}
	
} 
else
	{
		goto ctr57;
	}

{
	goto st0;
}
ctr58:
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


	goto st33;
st33:
	p+= 1;
if ( p == pe  )
	goto _test_eof33;

st_case_33:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr6;
	}
		 case 95:
{
goto ctr38;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr38;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr38;
		}
	
} 
else
	{
		goto ctr38;
	}

{
	goto st0;
}
st34:
	p+= 1;
if ( p == pe  )
	goto _test_eof34;

st_case_34:
	if ( ( (*( p  ))
) == 95  )
	{
		goto ctr59;
	}
	
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr59;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr59;
		}
	
} 
else
	{
		goto ctr59;
	}

{
	goto st0;
}
ctr59:
	{fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
{function[fi++] = (( (*( p  ))
));
        }


	goto st35;
ctr61:
	{function[fi++] = (( (*( p  ))
));
        }


	goto st35;
st35:
	p+= 1;
if ( p == pe  )
	goto _test_eof35;

st_case_35:
	switch ( ( (*( p  ))
)  ) {
	case 40:
{
goto ctr60;
	}
		 case 95:
{
goto ctr61;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr61;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr61;
		}
	
} 
else
	{
		goto ctr61;
	}

{
	goto st0;
}
ctr60:
	{term               = stack_peek(term_stack);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
{{stack[top] = 36;
top+= 1;
goto st5;}}


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
goto ctr62;
	}
		 case 10:
{
goto ctr63;
	}
		 case 13:
{
goto ctr64;
	}
		 case 32:
{
goto ctr62;
	}
	
}
{
	goto st0;
}
ctr62:
	{if (statement->token->left == NULL) {
                // statement left token (e.g. subject) is available
                subject->token->left = bel_copy_ast_node(term);
                statement->token->left = subject;
            } else {
                // assume right token (e.g. object) is available
                object->token->right = bel_copy_ast_node(term);
                statement->token->right = object;
            }

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
	switch ( ( (*( p  ))
)  ) {
	case 9:
{
goto ctr62;
	}
		 case 32:
{
goto ctr62;
	}
	
}
{
	goto st0;
}
ctr63:
	{if (statement->token->left == NULL) {
                // statement left token (e.g. subject) is available
                subject->token->left = bel_copy_ast_node(term);
                statement->token->left = subject;
            } else {
                // assume right token (e.g. object) is available
                object->token->right = bel_copy_ast_node(term);
                statement->token->right = object;
            }

            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st42;
st42:
	p+= 1;
if ( p == pe  )
	goto _test_eof42;

st_case_42:
{
	goto st0;
}
ctr64:
	{if (statement->token->left == NULL) {
                // statement left token (e.g. subject) is available
                subject->token->left = bel_copy_ast_node(term);
                statement->token->left = subject;
            } else {
                // assume right token (e.g. object) is available
                object->token->right = bel_copy_ast_node(term);
                statement->token->right = object;
            }

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
	if ( ( (*( p  ))
) == 10  )
	{
		goto ctr63;
	}

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
	_test_eof37: cs = 37;
goto _test_eof; 
	_test_eof5: cs = 5;
goto _test_eof; 
	_test_eof6: cs = 6;
goto _test_eof; 
	_test_eof7: cs = 7;
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
	_test_eof38: cs = 38;
goto _test_eof; 
	_test_eof17: cs = 17;
goto _test_eof; 
	_test_eof18: cs = 18;
goto _test_eof; 
	_test_eof19: cs = 19;
goto _test_eof; 
	_test_eof20: cs = 20;
goto _test_eof; 
	_test_eof39: cs = 39;
goto _test_eof; 
	_test_eof21: cs = 21;
goto _test_eof; 
	_test_eof22: cs = 22;
goto _test_eof; 
	_test_eof23: cs = 23;
goto _test_eof; 
	_test_eof24: cs = 24;
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
	_test_eof40: cs = 40;
goto _test_eof; 
	_test_eof30: cs = 30;
goto _test_eof; 
	_test_eof31: cs = 31;
goto _test_eof; 
	_test_eof32: cs = 32;
goto _test_eof; 
	_test_eof33: cs = 33;
goto _test_eof; 
	_test_eof34: cs = 34;
goto _test_eof; 
	_test_eof35: cs = 35;
goto _test_eof; 
	_test_eof36: cs = 36;
goto _test_eof; 
	_test_eof41: cs = 41;
goto _test_eof; 
	_test_eof42: cs = 42;
goto _test_eof; 
	_test_eof43: cs = 43;
goto _test_eof; 

	_test_eof: {}
	_out: {}
	}
bel_free_ast_node(term);
    if (term_stack) {
        stack_destroy(term_stack);
    }
    free(stack);
    free(function);
    free(relationship);
    free(value);

    return ast;
};
// vim: ft=c sw=4 ts=4 sts=4 expandtab

