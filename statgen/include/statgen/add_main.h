#ifndef ADD_MAIN_H
#define ADD_MAIN_H

int error_checking (const float *, const int, const char *, const int, const int, 
                    const char *, const int, const int);
int printing_head (const char *, const int, const int, const char *, const int, 
                   const int, const float *, const int, const int *, const int, 
                   const float *, const int);
int print_message (const int, FILE *, const int, FILE *, const int, const char *);
int set_defaults (float *, int *, char *, int *, int *, int *, char *, int *, 
                  int *, int *);

#endif /* ADD_MAIN_H */