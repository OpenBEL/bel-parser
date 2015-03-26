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
static const int  set_first_final  = 33;
static const int  set_error  = 0;
static const int  set_en_arguments  = 4;
static const int  set_en_term  = 1;
bel_ast* bel_parse_term(char* line) {
    int             cs;
    char            *p;
    char            *pe;
    int             top;
    int             *stack;
    bel_ast_node*   term;
    bel_ast_node*   current_nv;
    bel_ast_node*   arg;
    bel_ast*        ast;
    bel_node_stack* term_stack;
    char            *function;
    char            *value;
    int             fi;
    int             vi;

    p            = line;
    pe           = line + strlen(line);
    top          = 0;
    stack        = malloc(sizeof(int) * TERM_STACK_SIZE);
    current_nv   = NULL;
    function     = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    value        = malloc(sizeof(char) * BEL_VALUE_CHAR_LEN);
    fi           = 0;
    vi           = 0;

    term_stack   = stack_init(TERM_STACK_SIZE);
    term         = bel_new_ast_node_token(BEL_TOKEN_TERM);
    ast          = bel_new_ast();
    ast->root    = term;

    stack_push(term_stack, term);
    memset(function, '\0', BEL_VALUE_CHAR_LEN);
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
		case 33:
goto st33;
		case 4:
goto st4;
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
		case 34:
goto st34;
		case 16:
goto st16;
		case 17:
goto st17;
		case 18:
goto st18;
		case 19:
goto st19;
		case 35:
goto st35;
		case 20:
goto st20;
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
		case 36:
goto st36;
		case 29:
goto st29;
		case 30:
goto st30;
		case 31:
goto st31;
		case 32:
goto st32;
	
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
	case 33:
goto st_case_33;
	case 4:
goto st_case_4;
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
	case 34:
goto st_case_34;
	case 16:
goto st_case_16;
	case 17:
goto st_case_17;
	case 18:
goto st_case_18;
	case 19:
goto st_case_19;
	case 35:
goto st_case_35;
	case 20:
goto st_case_20;
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
	case 36:
goto st_case_36;
	case 29:
goto st_case_29;
	case 30:
goto st_case_30;
	case 31:
goto st_case_31;
	case 32:
goto st_case_32;
	
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
	{fi = 0;
            memset(function, '\0', BEL_VALUE_CHAR_LEN);
        }
{function[fi++] = (( (*( p  ))
));
        }


	goto st2;
ctr3:
	{function[fi++] = (( (*( p  ))
));
        }


	goto st2;
st2:
	p+= 1;
if ( p == pe  )
	goto _test_eof2;

st_case_2:
	switch ( ( (*( p  ))
)  ) {
	case 40:
{
goto ctr2;
	}
		 case 95:
{
goto ctr3;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr3;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr3;
		}
	
} 
else
	{
		goto ctr3;
	}

{
	goto st0;
}
ctr2:
	{term               = stack_peek(term_stack);
            term->token->left  = bel_new_ast_node_value(BEL_VALUE_FX, function);
            term->token->right = bel_new_ast_node_token(BEL_TOKEN_ARG);
        }
{{stack[top] = 3;
top+= 1;
goto st4;}}


	goto st3;
st3:
	p+= 1;
if ( p == pe  )
	goto _test_eof3;

st_case_3:
	if ( ( (*( p  ))
) == 41  )
	{
		goto st33;
	}

{
	goto st0;
}
st33:
	p+= 1;
if ( p == pe  )
	goto _test_eof33;

st_case_33:
{
	goto st0;
}
st4:
	p+= 1;
if ( p == pe  )
	goto _test_eof4;

st_case_4:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr5;
	}
		 case 95:
{
goto ctr6;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr6;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr6;
		}
	
} 
else
	{
		goto ctr6;
	}

{
	goto st0;
}
ctr5:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }


	goto st5;
ctr7:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st5;
st5:
	p+= 1;
if ( p == pe  )
	goto _test_eof5;

st_case_5:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr8;
	}
		 case 92:
{
goto ctr9;
	}
	
}
if ( ( (*( p  ))
) > 91  )
	{
		if ( 93 <= ( (*( p  ))
)  )
	{
			goto ctr7;
		}
	
} 
else if ( ( (*( p  ))
) >= 35  )
	{
		goto ctr7;
	}

{
	goto ctr7;
}
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
	case 9:
{
goto ctr10;
	}
		 case 32:
{
goto ctr10;
	}
		 case 41:
{
goto ctr11;
	}
		 case 44:
{
goto ctr12;
	}
	
}
{
	goto st0;
}
ctr10:
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
		 case 32:
{
goto st7;
	}
		 case 44:
{
goto st8;
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


	goto st9;
ctr17:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st9;
st9:
	p+= 1;
if ( p == pe  )
	goto _test_eof9;

st_case_9:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr8;
	}
		 case 92:
{
goto ctr18;
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
goto ctr19;
	}
		 case 92:
{
goto ctr18;
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
ctr25:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }


	goto st11;
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
	case 9:
{
goto ctr20;
	}
		 case 32:
{
goto ctr20;
	}
		 case 33:
{
goto ctr17;
	}
		 case 34:
{
goto ctr8;
	}
		 case 41:
{
goto ctr21;
	}
		 case 44:
{
goto ctr22;
	}
		 case 92:
{
goto ctr18;
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
ctr23:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st12;
ctr20:
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


	goto st12;
ctr47:
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
goto ctr23;
	}
		 case 32:
{
goto ctr23;
	}
		 case 33:
{
goto ctr17;
	}
		 case 34:
{
goto ctr8;
	}
		 case 44:
{
goto ctr24;
	}
		 case 92:
{
goto ctr18;
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
ctr24:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st13;
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


	goto st13;
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
goto ctr17;
	}
		 case 34:
{
goto ctr25;
	}
		 case 91:
{
goto ctr17;
	}
		 case 92:
{
goto ctr18;
	}
		 case 95:
{
goto ctr26;
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
				goto ctr26;
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
				goto ctr26;
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
				goto ctr26;
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


	goto st14;
ctr28:
	{value[vi++] = (( (*( p  ))
));
        }
{function[fi++] = (( (*( p  ))
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
goto ctr20;
	}
		 case 32:
{
goto ctr20;
	}
		 case 33:
{
goto ctr17;
	}
		 case 34:
{
goto ctr8;
	}
		 case 40:
{
goto ctr27;
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
goto ctr29;
	}
		 case 91:
{
goto ctr17;
	}
		 case 92:
{
goto ctr18;
	}
		 case 95:
{
goto ctr28;
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
					goto ctr28;
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
				goto ctr28;
			}
		
} 
else
	{
			goto ctr17;
		}
	
} 
else
	{
		goto ctr28;
	}

{
	goto ctr17;
}
ctr27:
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
{{stack[top] = 15;
top+= 1;
goto st4;}}


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
goto ctr23;
	}
		 case 32:
{
goto ctr23;
	}
		 case 33:
{
goto ctr17;
	}
		 case 34:
{
goto ctr8;
	}
		 case 41:
{
goto ctr30;
	}
		 case 44:
{
goto ctr24;
	}
		 case 92:
{
goto ctr18;
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
{stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st34;
ctr30:
	{value[vi++] = (( (*( p  ))
));
        }
{stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st34;
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
{stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
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
goto ctr8;
	}
		 case 92:
{
goto ctr18;
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
ctr29:
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


	goto st16;
st16:
	p+= 1;
if ( p == pe  )
	goto _test_eof16;

st_case_16:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr25;
	}
		 case 91:
{
goto ctr17;
	}
		 case 92:
{
goto ctr18;
	}
		 case 95:
{
goto ctr31;
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
			goto ctr31;
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
			goto ctr31;
		}
	
} 
else
	{
		goto ctr31;
	}

{
	goto ctr17;
}
ctr31:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }


	goto st17;
ctr32:
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
goto ctr20;
	}
		 case 32:
{
goto ctr20;
	}
		 case 33:
{
goto ctr17;
	}
		 case 34:
{
goto ctr8;
	}
		 case 41:
{
goto ctr21;
	}
		 case 44:
{
goto ctr22;
	}
		 case 91:
{
goto ctr17;
	}
		 case 92:
{
goto ctr18;
	}
		 case 95:
{
goto ctr32;
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
					goto ctr32;
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
				goto ctr32;
			}
		
} 
else
	{
			goto ctr17;
		}
	
} 
else
	{
		goto ctr32;
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


	goto st18;
ctr34:
	{value[vi++] = (( (*( p  ))
));
        }
{function[fi++] = (( (*( p  ))
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
goto ctr10;
	}
		 case 32:
{
goto ctr10;
	}
		 case 40:
{
goto ctr33;
	}
		 case 41:
{
goto ctr11;
	}
		 case 44:
{
goto ctr12;
	}
		 case 58:
{
goto ctr35;
	}
		 case 95:
{
goto ctr34;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr34;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr34;
		}
	
} 
else
	{
		goto ctr34;
	}

{
	goto st0;
}
ctr33:
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
{{stack[top] = 19;
top+= 1;
goto st4;}}


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
goto st7;
	}
		 case 32:
{
goto st7;
	}
		 case 41:
{
goto ctr36;
	}
		 case 44:
{
goto st8;
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
{stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st35;
ctr36:
	{stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st35;
st35:
	p+= 1;
if ( p == pe  )
	goto _test_eof35;

st_case_35:
{
	goto st0;
}
ctr35:
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


	goto st20;
st20:
	p+= 1;
if ( p == pe  )
	goto _test_eof20;

st_case_20:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr15;
	}
		 case 95:
{
goto ctr37;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr37;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr37;
		}
	
} 
else
	{
		goto ctr37;
	}

{
	goto st0;
}
ctr37:
	{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
        }
{value[vi++] = (( (*( p  ))
));
        }


	goto st21;
ctr38:
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
	case 9:
{
goto ctr10;
	}
		 case 32:
{
goto ctr10;
	}
		 case 41:
{
goto ctr11;
	}
		 case 44:
{
goto ctr12;
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
ctr9:
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
	case 34:
{
goto ctr39;
	}
		 case 92:
{
goto ctr9;
	}
	
}
if ( ( (*( p  ))
) > 91  )
	{
		if ( 93 <= ( (*( p  ))
)  )
	{
			goto ctr7;
		}
	
} 
else if ( ( (*( p  ))
) >= 35  )
	{
		goto ctr7;
	}

{
	goto ctr7;
}
ctr39:
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
	case 9:
{
goto ctr40;
	}
		 case 32:
{
goto ctr40;
	}
		 case 33:
{
goto ctr7;
	}
		 case 34:
{
goto ctr8;
	}
		 case 41:
{
goto ctr41;
	}
		 case 44:
{
goto ctr42;
	}
		 case 92:
{
goto ctr9;
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
				goto ctr7;
			}
		
} 
else if ( ( (*( p  ))
) >= 10  )
	{
			goto ctr7;
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
				goto ctr7;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr7;
		}
	
} 
else
	{
		goto ctr7;
	}

{
	goto ctr7;
}
ctr43:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st24;
ctr40:
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
goto ctr43;
	}
		 case 32:
{
goto ctr43;
	}
		 case 33:
{
goto ctr7;
	}
		 case 34:
{
goto ctr8;
	}
		 case 44:
{
goto ctr44;
	}
		 case 92:
{
goto ctr9;
	}
	
}
if ( ( (*( p  ))
) < 35  )
	{
		if ( 10 <= ( (*( p  ))
) && ( (*( p  ))
) <= 31  )
	{
			goto ctr7;
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
				goto ctr7;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr7;
		}
	
} 
else
	{
		goto ctr7;
	}

{
	goto ctr7;
}
ctr44:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st25;
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
goto ctr7;
	}
		 case 34:
{
goto ctr45;
	}
		 case 91:
{
goto ctr7;
	}
		 case 92:
{
goto ctr9;
	}
		 case 95:
{
goto ctr46;
	}
		 case 96:
{
goto ctr7;
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
				goto ctr7;
			}
		
} 
else if ( ( (*( p  ))
) > 47  )
	{
			{
				goto ctr46;
			}
		} 
else
	{
			goto ctr7;
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
				goto ctr46;
			}
		
} 
else if ( ( (*( p  ))
) > 94  )
	{
			if ( ( (*( p  ))
) > 122  )
	{
				{
					goto ctr7;
				}
			} 
else if ( ( (*( p  ))
) >= 97  )
	{
				goto ctr46;
			}
		
} 
else
	{
			goto ctr7;
		}
	
} 
else
	{
		goto ctr7;
	}

{
	goto ctr7;
}
ctr45:
	{value[vi++] = (( (*( p  ))
));
        }
{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
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
goto ctr47;
	}
		 case 32:
{
goto ctr47;
	}
		 case 33:
{
goto ctr17;
	}
		 case 34:
{
goto ctr8;
	}
		 case 41:
{
goto ctr48;
	}
		 case 44:
{
goto ctr49;
	}
		 case 92:
{
goto ctr18;
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
{function[fi++] = (( (*( p  ))
));
        }


	goto st27;
ctr46:
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
goto ctr40;
	}
		 case 32:
{
goto ctr40;
	}
		 case 33:
{
goto ctr7;
	}
		 case 34:
{
goto ctr8;
	}
		 case 40:
{
goto ctr50;
	}
		 case 41:
{
goto ctr41;
	}
		 case 44:
{
goto ctr42;
	}
		 case 58:
{
goto ctr52;
	}
		 case 91:
{
goto ctr7;
	}
		 case 92:
{
goto ctr9;
	}
		 case 95:
{
goto ctr51;
	}
		 case 96:
{
goto ctr7;
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
				goto ctr7;
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
					goto ctr7;
				}
			
} 
else if ( ( (*( p  ))
) >= 42  )
	{
				goto ctr7;
			}
		
} 
else
	{
			goto ctr7;
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
					goto ctr51;
				}
			
} 
else if ( ( (*( p  ))
) >= 59  )
	{
				goto ctr7;
			}
		
} 
else if ( ( (*( p  ))
) > 94  )
	{
			if ( ( (*( p  ))
) > 122  )
	{
				{
					goto ctr7;
				}
			} 
else if ( ( (*( p  ))
) >= 97  )
	{
				goto ctr51;
			}
		
} 
else
	{
			goto ctr7;
		}
	
} 
else
	{
		goto ctr51;
	}

{
	goto ctr7;
}
ctr50:
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
{{stack[top] = 28;
top+= 1;
goto st4;}}


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
goto ctr43;
	}
		 case 32:
{
goto ctr43;
	}
		 case 33:
{
goto ctr7;
	}
		 case 34:
{
goto ctr8;
	}
		 case 41:
{
goto ctr53;
	}
		 case 44:
{
goto ctr44;
	}
		 case 92:
{
goto ctr9;
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
				goto ctr7;
			}
		
} 
else if ( ( (*( p  ))
) >= 10  )
	{
			goto ctr7;
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
				goto ctr7;
			}
		
} 
else if ( ( (*( p  ))
) >= 45  )
	{
			goto ctr7;
		}
	
} 
else
	{
		goto ctr7;
	}

{
	goto ctr7;
}
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
{stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st36;
ctr53:
	{value[vi++] = (( (*( p  ))
));
        }
{stack_pop(term_stack);
            {top -= 1;
cs = stack[top];
goto _again;}
        }


	goto st36;
st36:
	p+= 1;
if ( p == pe  )
	goto _test_eof36;

st_case_36:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr8;
	}
		 case 92:
{
goto ctr9;
	}
	
}
if ( ( (*( p  ))
) > 91  )
	{
		if ( 93 <= ( (*( p  ))
)  )
	{
			goto ctr7;
		}
	
} 
else if ( ( (*( p  ))
) >= 35  )
	{
		goto ctr7;
	}

{
	goto ctr7;
}
ctr52:
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


	goto st29;
st29:
	p+= 1;
if ( p == pe  )
	goto _test_eof29;

st_case_29:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr45;
	}
		 case 91:
{
goto ctr7;
	}
		 case 92:
{
goto ctr9;
	}
		 case 95:
{
goto ctr54;
	}
		 case 96:
{
goto ctr7;
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
				goto ctr7;
			}
		
} 
else if ( ( (*( p  ))
) > 57  )
	{
			{
				goto ctr7;
			}
		} 
else
	{
			goto ctr54;
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
				goto ctr7;
			}
		
} 
else if ( ( (*( p  ))
) > 122  )
	{
			{
				goto ctr7;
			}
		} 
else
	{
			goto ctr54;
		}
	
} 
else
	{
		goto ctr54;
	}

{
	goto ctr7;
}
ctr55:
	{value[vi++] = (( (*( p  ))
));
        }


	goto st30;
ctr54:
	{value[vi++] = (( (*( p  ))
));
        }
{vi = 0;
            memset(value, '\0', BEL_VALUE_CHAR_LEN);
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
goto ctr40;
	}
		 case 32:
{
goto ctr40;
	}
		 case 33:
{
goto ctr7;
	}
		 case 34:
{
goto ctr8;
	}
		 case 41:
{
goto ctr41;
	}
		 case 44:
{
goto ctr42;
	}
		 case 91:
{
goto ctr7;
	}
		 case 92:
{
goto ctr9;
	}
		 case 95:
{
goto ctr55;
	}
		 case 96:
{
goto ctr7;
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
				goto ctr7;
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
					goto ctr7;
				}
			
} 
else if ( ( (*( p  ))
) >= 42  )
	{
				goto ctr7;
			}
		
} 
else
	{
			goto ctr7;
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
					goto ctr55;
				}
			
} 
else
	{
				goto ctr7;
			}
		
} 
else if ( ( (*( p  ))
) > 94  )
	{
			if ( ( (*( p  ))
) > 122  )
	{
				{
					goto ctr7;
				}
			} 
else if ( ( (*( p  ))
) >= 97  )
	{
				goto ctr55;
			}
		
} 
else
	{
			goto ctr7;
		}
	
} 
else
	{
		goto ctr55;
	}

{
	goto ctr7;
}
ctr6:
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


	goto st31;
ctr56:
	{value[vi++] = (( (*( p  ))
));
        }
{function[fi++] = (( (*( p  ))
));
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
goto ctr10;
	}
		 case 32:
{
goto ctr10;
	}
		 case 40:
{
goto ctr33;
	}
		 case 41:
{
goto ctr11;
	}
		 case 44:
{
goto ctr12;
	}
		 case 58:
{
goto ctr57;
	}
		 case 95:
{
goto ctr56;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr56;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr56;
		}
	
} 
else
	{
		goto ctr56;
	}

{
	goto st0;
}
ctr57:
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


	goto st32;
st32:
	p+= 1;
if ( p == pe  )
	goto _test_eof32;

st_case_32:
	switch ( ( (*( p  ))
)  ) {
	case 34:
{
goto ctr5;
	}
		 case 95:
{
goto ctr37;
	}
	
}
if ( ( (*( p  ))
) < 65  )
	{
		if ( 48 <= ( (*( p  ))
) && ( (*( p  ))
) <= 57  )
	{
			goto ctr37;
		}
	
} 
else if ( ( (*( p  ))
) > 90  )
	{
		if ( 97 <= ( (*( p  ))
) && ( (*( p  ))
) <= 122  )
	{
			goto ctr37;
		}
	
} 
else
	{
		goto ctr37;
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
	_test_eof33: cs = 33;
goto _test_eof; 
	_test_eof4: cs = 4;
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
	_test_eof34: cs = 34;
goto _test_eof; 
	_test_eof16: cs = 16;
goto _test_eof; 
	_test_eof17: cs = 17;
goto _test_eof; 
	_test_eof18: cs = 18;
goto _test_eof; 
	_test_eof19: cs = 19;
goto _test_eof; 
	_test_eof35: cs = 35;
goto _test_eof; 
	_test_eof20: cs = 20;
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
	_test_eof36: cs = 36;
goto _test_eof; 
	_test_eof29: cs = 29;
goto _test_eof; 
	_test_eof30: cs = 30;
goto _test_eof; 
	_test_eof31: cs = 31;
goto _test_eof; 
	_test_eof32: cs = 32;
goto _test_eof; 

	_test_eof: {}
	_out: {}
	}
if (term_stack) {
        stack_destroy(term_stack);
    }
    free(stack);
    free(function);
    free(value);

    return ast;
};
// vim: ft=c sw=4 ts=4 sts=4 expandtab

