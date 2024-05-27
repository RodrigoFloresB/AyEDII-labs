#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem elem;
    stack next;
};
 
// El primer elem en el primer nodo va a ser el largo de la pila.

static bool invrep(stack s) {
    return (s->next == NULL && s->elem == 0);
}

stack stack_empty() {
    stack nodo= malloc(sizeof(struct _s_stack));
    nodo->elem = 0; // stack vacio
    nodo->next = NULL;

    return nodo;
}

stack stack_push(stack s, stack_elem e) {
    stack res = malloc(sizeof(struct _s_stack));
    
    if (res == NULL)
    {
        printf("Error al resevar memoria \n");
        exit(EXIT_FAILURE);
    }

    res->elem = e;
    res->next = s->next; // seria el primer elemento del stack
    s->elem++; // incrementa el tamano del stack
    s->next = res; // apunta al nuevo nodo

    return s;
}

stack stack_pop(stack s) {
    assert(!invrep(s));

	stack res = s->next;
	s = (s->next)->next;
    s->elem--;
	free(res);
	res = NULL;	

	return s;
}

unsigned int stack_size(stack s) {
    
    return s->elem;
}

stack_elem stack_top(stack s) {
    assert(!invrep(s));

    return (s->next)->elem;
}

bool stack_is_empty(stack s) {
    
    return (s == NULL);
}

stack_elem *stack_to_array(stack s) {
    stack aux = s->next;
    stack_elem *res = NULL;
    unsigned int length = stack_size(s);

    if (!stack_is_empty(s))
    {
        res = calloc(length, sizeof(stack_elem));
        for (unsigned int i = 0; i < length; i++)
        {
            res[length-i-1] = aux->elem;
            aux = aux->next;
        }
    }
    
    return res;
}

stack stack_destroy(stack s) {

    while (s != NULL) {
        stack aux = s->next;
        free(s);
        s = aux;
    }

  return NULL;
}