/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file messages.h
 * Header of mathmech library
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#ifndef MESSAGES_H
#define MESSAGES_H


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
int message (const int log, const int mode, const char *text, FILE *output);


#endif /* MESSAGES_H */
