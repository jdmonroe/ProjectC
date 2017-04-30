#ifndef ADMINISTRATOR_H_INCLUDED
#define ADMINISTRATOR_H_INCLUDED

void CreateAccount( file);
void ChangePassword(char password);
char ViewInfo(FILE* file);
void DeleteInfo(FILE* file);
char ShowTop(FILE* file);
char ShowAll(FILE* file);

#endif // ADMINISTRATOR_H_INCLUDED
