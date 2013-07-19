/* Library for printing messages at stdout
 *
 * Usage:
 *                                             message (log, mode, text, stdout)
 */

#include <stdio.h>
#include <string.h>
#include <time.h>


int message (int log, int mode, const char *text, FILE *stdout)
/* mode             - number of message
 * text             - additional text
 */
{
  char out[4096];
  
  if (log == 1)
  {
    char time_str[256];
    time_t t = time(NULL);
    struct tm* aTm = localtime(&t);
    sprintf(time_str, "[%04d-%02d-%02d %02d:%02d:%02d] [%2i]: ", aTm->tm_year+1900, 
            aTm->tm_mon+1, aTm->tm_mday, aTm->tm_hour, aTm->tm_min, aTm->tm_sec, mode);
    fputs (time_str, stdout);
  }
  
  switch (mode)
  {
    case 0:
      sprintf (out, "Starting program: '%s' (Ver.1.0.0)\n", text);
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
  }
  
  fputs (out, stdout);
  return 0;
}