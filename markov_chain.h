#ifndef MARKOV_CHAIN_H
#define MARKOV_CHAIN_H

#include "list.h"

struct node;
typedef struct node node_t;

struct pointer;
typedef struct pointer pointer_t;

struct discrete_chain;
typedef struct discrete_chain discrete_chain_t;

/*
 * The chain is created based on a file sent in, which is
 * opened and parsed. A suitable format may be the JSON-format.
 */
discrete_chain_t *chain_create(float *matrix, int num_dim, int start);

/*
 * The chain is destroyed, freeing all allocations from memory.
 */
void chain_destroy(discrete_chain_t *chain);

/*
 * The data from the chain is written to a file given
 * as argument to this function.
 */
void write_to_file(discrete_chain_t *chain, char *filename);

/*
 * When a chain has been created, it has to be verified.
 * This is done by checking if the sum of probabilities on each pointer is equal to one. 
 * Other verifications may be added in the future.
 */
int verify_chain(discrete_chain_t *chain);

/*
 * A transition is performed. The current node we're on is sent in,
 * and the chain where the transition is to be written to is also sent in.
 * The node transitioned to is returned. 
 */
node_t *transition(discrete_chain_t *chain);

/*
 * Returns the id of the current node in the chain
 */
int get_current_node(discrete_chain_t *chain);

/*
 * Is to print out the list of transitions of 
 * the given markov chain on the screen
 */
void print_transition_list(discrete_chain_t *chain);

#endif