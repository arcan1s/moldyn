/**
 * @file
 */

#ifndef MESSAGES_H
#define MESSAGES_H


/**
 * @fn message
 */
int message (const int log, const int mode, const char *text, FILE *output);
/**
 * @brief function that prints messages to output
 * @code
 * message (log, mode, text, output);
 * @endcode
 * 
 * @param log             equal to 1 if print to logfile
 * @param mode            number of message
 * @param text            additional text
 * @param output          output file (may be stdout)
 * 
 * @return 1              - unknown mode
 * @return 0              - exit without errors
 */


#endif /* MESSAGES_H */
