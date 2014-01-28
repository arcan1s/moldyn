/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 */

#ifndef GRAPH_H
#define GRAPH_H


/**
 * @fn check_cycle
 */
int check_cycle (const int N, const int *pn);
/**
 * @brief function that calculates number of cycles in graph
 * @code
 * cycle = check_cycle (N, pn);
 * @endcode
 * 
 * @param N               number of vertexes
 * @param pn              massive of number of vertexes with weight equals to i
 * 
 * @return number of cycles
 */


/**
 * @fn check_cycle_size
 */
int check_cycle_size (const int N, const int *matrix, const int depth, int *n_cycle);
/**
 * @brief function that returns number of cycles different size
 * @code
 * check_cycle_size (N, matrix, depth, n_cycle);
 * @endcode
 * 
 * @param N               number of vertexes
 * @param matrix          connectivity matrix
 * @param depth           depth of search (maximum number of vertexes in cycle)
 * @param n_cycle         massive of number of cycle with number of vertexes 
 *                        equals to i
 * 
 * @return 1              - memory error
 * @return 0              - exit without errors
 */


/**
 * @fn check_tail
 */
int check_tail (const int *pn);
/**
 * @brief function that calculates number of tails
 * @code
 * tails = check_tail (pn);
 * @endcode
 * 
 * @param pn              massive of number of vertexes with weight equals to i
 * 
 * @return number of tails
 */


/**
 * @fn graph_analyze
 */
int graph_analyze (const int N, const int *matrix, const int max_depth, int *iso);
/**
 * @brief function that analyzes graph isomorhic class
 * @code
 * graph_analyze (N, matrix, max_depth, iso);
 * @endcode
 * 
 * @param N               number of vertexes
 * @param matrix          connectivity matrix
 * @param max_depth       maximum depth of search for check_cycle_size
 * @param iso             isomorphism class
 * 
 * @return 1              - memory error
 * @return 0              - exit without errors
 */


#endif /* GRAPH_H */
