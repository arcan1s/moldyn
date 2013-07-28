/**
 * @file
 */

#include <stdio.h>
#include <time.h>


/**
 * @fn message
 */
int message (const int log, const int mode, const char *text, FILE *output)
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
 * @return 0              - exit without errors
 */
{
  char out[4096];
  
  if (log == 1)
  {
    char time_str[256];
    
    time_t t = time (NULL);
    struct tm* aTm = localtime (&t);
    sprintf (time_str, "[%04d-%02d-%02d %02d:%02d:%02d] [%2i]: ", aTm->tm_year+1900, 
            aTm->tm_mon+1, aTm->tm_mday, aTm->tm_hour, aTm->tm_min, aTm->tm_sec, mode);
    fputs (time_str, output);
  }
  
  switch (mode)
  {
    case 0:
      sprintf (out, "Starting program: '%s'\n", text);
      break;
    case 1:
      sprintf (out, "Checking errors\n");
      break;
    case 2:
      sprintf (out, "Errors are not detected\n");
      break;
    case 3:
      sprintf (out, "Initialization of variables from file '%s'\n", text);
      break;
    case 4:
      break;
    case 5:
      sprintf (out, "Initial parametrs: \n%s", text);
      break;
    case 6:
      sprintf (out, "Processing\n");
      break;
    case 7:
      sprintf (out, "Open file: '%s'\n", text);
      break;
    case 8:
      sprintf (out, "%s", text);
      break;
    case 9:
      sprintf (out, "%6cSize of variables was changed successfully\n", ' ');
      break;
    case 10:
      sprintf (out, "%6cConnectivity matrix was created successfully\n", ' ');
      break;
    case 11:
      sprintf (out, "%6cConnectivity matrix was processed successfully\n", ' ');
      break;
    case 12:
      sprintf (out, "%6cResult was printed to file '%s' successfully\n", ' ', text);
      break;
    case 13:
      sprintf (out, "End of processing\n");
      break;
    case 14:
      sprintf (out, "Printing summary statistic to file '%s'\n", text);
      break;
    case 15:
      sprintf (out, "Free memory\n");
      break;
    case 16:
      sprintf (out, "Exiting without errors\n");
      break;
    case 17:
      sprintf (out, "Something wrong!\nSee '%s -h' for more details\n", text);
      break;
    case 18:
      sprintf (out, "File '%s' not found\nError\n", text);
      break;
    case 19:
      sprintf (out, "Memory error\n");
      break;
    case 20:
      sprintf (out, "%6cCenter of molecules was set successfully\n", ' ');
      break;
    case 21:
      sprintf (out, "%6cEnvironment was selected successfully\n", ' ');
      break;
  }
  
  fputs (out, output);
  return 0;
}