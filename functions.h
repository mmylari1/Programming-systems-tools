#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

/**
* @brief      { Print a message. Does not return a value. }
* @param[in]  msg   The message to be printed using printf()
*/
void hello(const char* msg);

/**
 * @brief      { Return the next multiple of a number after another number }
 *
 * @param[in]  start     { a starting number }
 * @param[in]  factor    { the factor of which to find a multiple }
 *
 * @return     { If start is a multiple of factor, return start + factor.
 * 				 Otherwise, return the smallest integer larger than start which
 * 				 is a multiple of factor. }
 */
int next_multiple(int start, int factor);

/**
 * @brief      { Convert a temperature in Fahrenheit scale to Celsius scale }
 *
 * @param[in]  fahrenheit  { The temperature in degrees fahrenheit }
 *
 * @return     { Returns the same temperature in degrees celsius }
 */
float ftoc (float fahrenheit);

/**
 * @brief      { Find the n-th member of the Fibonacci sequence }
 *
 * @param[in]  term     { Desired term to return }
 *
 * @return     { Returns the n-th sequence member. }
 */
int fibonacci(unsigned int term);

#endif //FUNCTIONS_H