#ifndef ESE_STRING_H
#define ESE_STRING_H

  void print_string(const char *str);
  int string_length(const char *str);
  void reverse_string(char *str);
  char *copy_string(const char *str);
  char *concat_string(const char *s1, const char *s2);
  const char *find_token(const char *s1, const char *st);
  char *overwrite_token(char *s1, const char *token, const char *filler);

#endif
