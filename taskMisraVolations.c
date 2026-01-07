/*
 * FILE: non_misra_chaos.c
 * PURPOSE: To demonstrate code that actively violates MISRA C guidelines.
 * WARNING: DO NOT USE THIS CODE STYLE IN REAL PROJECTS.
 * It is full of undefined behavior and dangerous constructs.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* VIOLATION: Macro argument 'a' evaluated twice. Dangerous if 'a' has side effects (e.g., i++). */
#define SQUARE_(a) ((a) * (a))

/* VIOLATION: Missing parentheses around arguments and result. */
#define ADD_(a, b) ((a) + (b))

/* VIOLATION: Using a macro to uncertain pointer arithmetic */
// MISRA C 2012 Rule 18.1: A pointer resulting from arithmetic on a pointer 
// operand shall address an element of the same array as that pointer operand.
#define SKIP_AHEAD(ptr, n) ((void*)((char*)ptr + n))

/* VIOLATION: Global variables. Should be avoided or heavily restricted. */
// MISRA C 2023 Rule 8.7
// Functions and objects should not be defined with external linkage 
// if they are referenced in only one translation unit
int g_counter = 0;
unsigned int g_flags = 0xFFFF;
char *g_buffer_ptr;
float g_global_float;

/* VIOLATION: Function prototypes not defined in a header file. */
// MISRA C:2012 / MISRA C:2023 Rule 8.5:
// Declaring an external function in a non-header file, or defining a function in
// a header file, are common ways to violate this rule.
void new_function(int a, unsigned short b, long *c);
int *_local_addr(void);
void pointer_math(void *data, int offset);



/* VIOLATION: Basic types used instead of fixed-width (e.g., int32_t) */
/* Structure with potential padding issues used dangerously later */
// Order members by size: Declaring structure members from largest to smallest
// can minimize the amount of padding introduced by the compiler,
// reducing memory waste. 
// struct TestStruct {
//     int i;
//     short s;
// 	char c;
// };
struct TestStruct {
    char c;
    int i;
    short s;
};

int main(void) {
	/* VIOLATION: Basic types used instead of fixed-width (e.g., int32_t) */
	// MISRA C:2012 / MISRA C:2023 Directive 4.6 
	// Rule Name: typedefs that indicate size and signedness should be used in 
	// place of the basic numerical types.
    int i, j, k;
	/* VIOLATION: Magic numbers used instead of constants */
    unsigned short us_val = 50;
    long l_val = -1000;

	/* VIOLATION: Uninitialized variable used */
	// MISRA C Rule 9.1 (Mandatory): The value of an object with automatic storage duration 
    // shall not be read before it has been set
    int uninit_var;
    g_counter += uninit_var;

    /* VIOLATION: Magic numbers used instead of constants */
	g_buffer_ptr = (char *)malloc(1024);
	/* VIOLATION: No check if malloc failed (returned NULL) */
	// Directive 4.7 (in MISRA C:2012 and 2023): "If a function returns error 
	// information, then that error information shall be tested". 

	/* VIOLATION: Using strcpy is often banned due to buffer overflow risk. */
    // MISRA C:2012 Rule 21.17: Use of the string handling functions from 
	// <string.h> shall not result in accesses beyond the bounds of the 
	// objects referenced by their pointer parameters
	strcpy(g_buffer_ptr, "Start chaos");

	/* VIOLATION: Magic numbers used instead of constants */
    i = 5;
	/* VIOLATION: Side effect in macro argument. 'i' will be incremented twice. */
    j = SQUARE_(i++);
    printf("SQUARE_ result (expected 25 or 30, got %d), i is now %d\n", j, i);

	/* VIOLATION: Implicit conversion between signed and unsigned. */
	// MISRA-C:2012 Rule 10.3: The value of an expression shall not be cast 
	// implicitly to a type with a wider range or different signedness.
    if (l_val > us_val) {
        g_flags = 0;
    }


	new_function(i, us_val, &l_val);

    int *dangerous_ptr = _local_addr();
    

    struct TestStruct bs;
    bs.c = 'A';
    bs.i = 0x12345678;
    bs.s = 0x9999;

    /* VIOLATION: Casting pointer to unrelated type*/
	pointer_math((void*)&bs, sizeof(char));

    /* VIOLATION: Comma operator used to perform multiple actions*/
	i = 0, j = 10, k = (i++, j++, i + j);

    /* VIOLATION: goto Statement used. Destroys structured control flow. */
	//5.4 in MISRA C:2012, strictly prohibit the use of the goto statement
	if (k > 20) goto end_of_main;

    i = 0;
start_loop:
 /* VIOLATION: Missing braces {} for the if and the nested loop statement */
    if (i < 10)
        for (j = 0; j < 5; j++)
            g_counter++;
    else
        goto break_loop;

    i++;
	/* VIOLATION: goto Statement used. Destroys structured control flow. */
    goto start_loop;

break_loop:

	/* VIOLATION: Deep nesting */
	// MISRA-C:2012 Rule 15.2 (Advisory): Functions shall not contain deep 
	// nesting of control structures.
    if (g_counter > 50) {
        if (g_flags & 0x01) {
            while (l_val < 0) {
                if (us_val > 0) {
                    l_val++;
                    us_val--;
                } else {
                    break;
                }
            }
        }
    }

end_of_main:
    free(g_buffer_ptr);
	 /* VIOLATION: Depending on C standard version, not returning a value from main might be invalid. */
}

/* VIOLATION: Function parameter names different from declaration (if one existed in header) */
// Rule 8.3 (All declarations of an object or function shall use the same names 
// and type qualifiers): This rule specifically mandates that all declarations and 
// the definition of a function must use the identical names and type qualifiers for the parameters. 
void new_function(int p1, unsigned short p2, long *p3) {
	/* VIOLATION: Basic char type used*/
    char c_idx;

	/* VIOLATION: Missing braces */
    if (p1 > 100) return;

    for (c_idx = 0; c_idx < (char)p1; c_idx++) {
		/* VIOLATION: Implicit promotion*/
        *p3 = *p3 + (p2 * c_idx);

		/* VIOLATION: Assignment in condition expression. */
        if ((g_global_float = (float)c_idx / 2.0f) > 5.0f) {
             char temp_buf[20];
			 /* VIOLATION: sprintf often banned*/
             sprintf(temp_buf, "Float: %f", g_global_float);
        }
    }

	/* VIOLATION: Multiple return points in a function. */
    if (*p3 > 10000) {
        g_flags = 0;
        return;
    }

    g_flags = 1;
	/* Implicit return at end of function */
	// MISRA C:2012 Rule 17.4 	The implicit return at the end of a function 
	// (when the function is non-void and reaches its terminating brace without 
	// a return statement)
}

int *_local_addr(void) {
    int local_var = 100;
    /* VIOLATION: Returning pointer to local variable (undefined behavior when accessed) */
    return &local_var;
}

void pointer_math(void *data, int offset) {
	/* VIOLATION: Pointer arithmetic on void pointer (compiler extension, not standard C). */
    int *hacked_int_ptr = (int *)((char*)data + offset);

    printf("Value at offset %d is potentially: 0x%X\n", offset, *hacked_int_ptr);

	/* VIOLATION: Basic types used instead of fixed-width (e.g., int32_t) */
    short *s_ptr;

	/* VIOLATION: More confusing macro usage */
    s_ptr = (short*)SKIP_AHEAD(data, offset + sizeof(int));
    *s_ptr = 0xDEAD;
}

void filler_function(void) {
    int x = 10, y = 20, z;
	/* VIOLATION: Assignment within expression used as boolean */
    if (z = x + y) {
        g_counter = z;
    }

    /* VIOLATION: Empty loop body with semicolon on same line, easy to miss. */
	while(x-- > 0);

    switch(y) {
        case 20:
            z = 1;
		 /* VIOLATION: Missing break statement*/
        case 30:
            z = 2;
            break;
	/* VIOLATION: Switch statement without default case */
    }

    /* VIOLATION: Using confusing ternary operator nesting */
	z = (x > y) ? (y > z ? 1 : 0) : (x < z ? 2 : 3);

    /* VIOLATION: Shadowing global variable declaration */
	float g_global_float = 3.14f;
    printf("Local float: %f\n", g_global_float);

    {
        /* VIOLATION: Shadowing global variable declaration */
		int g_counter = 999;
        printf("Shadowed counter: %d\n", g_counter);
    }
    printf("Global counter: %d\n", g_counter);
}